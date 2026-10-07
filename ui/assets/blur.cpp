#include "blur.hpp"
#include "../../src/core/main.hpp"
#include <d3dcompiler.h>
#include <cstring>

#pragma comment(lib, "d3dcompiler.lib")

static const char* vertex_shader_code = R"(
struct VS_INPUT {
    float2 pos : POSITION;
    float2 uv : TEXCOORD0;
};

struct PS_INPUT {
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
};

PS_INPUT main(VS_INPUT input) {
    PS_INPUT output;
    output.pos = float4(input.pos, 0.0f, 1.0f);
    output.uv = input.uv;
    return output;
}
)";

static const char* horizontal_blur_shader_code = R"(
Texture2D shaderTexture : register(t0);
SamplerState samplerState : register(s0);

cbuffer BlurBuffer : register(b0) {
    float blurSize;
    float blurStrength;
    float screenWidth;
    float screenHeight;
    float menuX;
    float menuY;
    float menuWidth;
    float menuHeight;
    float cornerRadius;
    float edgeSoftness;
    float padding[2];
};

struct PS_INPUT {
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
};

float4 main(PS_INPUT input) : SV_TARGET {
    // 13-tap separable gaussian for smoother blur (less blocky artifacts).
    float texelSize = 1.0f / screenWidth;
    float2 stepUv = float2(texelSize * blurSize, 0.0f);

    static const float weights[13] = {
        0.0561f, 0.0690f, 0.0782f, 0.0847f, 0.0876f, 0.0890f, 0.0894f,
        0.0890f, 0.0876f, 0.0847f, 0.0782f, 0.0690f, 0.0561f
    };

    float4 color = 0;
    [unroll]
    for (int i = 0; i < 13; i++) {
        float2 uv = input.uv + stepUv * (float)(i - 6);
        color += shaderTexture.Sample(samplerState, uv) * weights[i];
    }
    return color;
}
)";

static const char* vertical_blur_shader_code = R"(
Texture2D shaderTexture : register(t0);
SamplerState samplerState : register(s0);

cbuffer BlurBuffer : register(b0) {
    float blurSize;
    float blurStrength;
    float screenWidth;
    float screenHeight;
    float menuX;
    float menuY;
    float menuWidth;
    float menuHeight;
    float cornerRadius;
    float edgeSoftness;
    float padding[2];
};

struct PS_INPUT {
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
};

float4 main(PS_INPUT input) : SV_TARGET {
    // 13-tap separable gaussian for smoother blur (less blocky artifacts).
    float texelSize = 1.0f / screenHeight;
    float2 stepUv = float2(0.0f, texelSize * blurSize);

    static const float weights[13] = {
        0.0561f, 0.0690f, 0.0782f, 0.0847f, 0.0876f, 0.0890f, 0.0894f,
        0.0890f, 0.0876f, 0.0847f, 0.0782f, 0.0690f, 0.0561f
    };

    float4 color = 0;
    [unroll]
    for (int i = 0; i < 13; i++) {
        float2 uv = input.uv + stepUv * (float)(i - 6);
        color += shaderTexture.Sample(samplerState, uv) * weights[i];
    }
    return color;
}
)";

static const char* composite_shader_code = R"(
Texture2D shaderTexture : register(t0);
SamplerState samplerState : register(s0);

cbuffer BlurBuffer : register(b0) {
    float blurSize;
    float blurStrength;
    float screenWidth;
    float screenHeight;
    float menuX;
    float menuY;
    float menuWidth;
    float menuHeight;
    float cornerRadius;
    float edgeSoftness;
    float padding[2];
};

struct PS_INPUT {
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
};

float roundedBoxSdf(float2 samplePos, float2 halfSize, float radius) {
    float2 q = abs(samplePos) - (halfSize - radius);
    return length(max(q, 0.0f)) + min(max(q.x, q.y), 0.0f) - radius;
}

float4 main(PS_INPUT input) : SV_TARGET {
    float2 pixelPos = input.uv * float2(screenWidth, screenHeight);
    // Inset by 1px to avoid any bleed along the rounded edge.
    float inset = 1.0f;
    float2 menuCenter = float2(menuX + menuWidth * 0.5f, menuY + menuHeight * 0.5f);
    float2 halfSize = float2(menuWidth * 0.5f - inset, menuHeight * 0.5f - inset);
    float dist = roundedBoxSdf(pixelPos - menuCenter, halfSize, max(cornerRadius - inset, 0.0f));
    // Don't touch pixels outside the rounded shape at all.
    if (dist > 0.0f)
        discard;

    return shaderTexture.Sample(samplerState, input.uv);
}
)";

static bool log_shader_error(const char* stage, HRESULT hr, ID3DBlob* error_blob) {
    if (error_blob && error_blob->GetBufferPointer()) {
        LOG_ERROR(xorstr_("[blur] %s compile failed: 0x%08X: %s"),
            stage, hr, static_cast<const char*>(error_blob->GetBufferPointer()));
    } else {
        LOG_ERROR(xorstr_("[blur] %s compile failed: 0x%08X"), stage, hr);
    }
    return false;
}

bool c_blur::initialize(ID3D11Device* device, ID3D11DeviceContext* context) {
    if (!device || !context)
        return false;

    m_device = device;
    m_context = context;

    if (!create_shaders())
        return false;

    if (!create_buffers())
        return false;

    D3D11_SAMPLER_DESC sampler_desc = {};
    sampler_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sampler_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
    sampler_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
    sampler_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    sampler_desc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    sampler_desc.MinLOD = 0;
    sampler_desc.MaxLOD = D3D11_FLOAT32_MAX;

    if (FAILED(m_device->CreateSamplerState(&sampler_desc, &m_sampler_state))) {
        LOG_ERROR(xorstr_("[blur] CreateSamplerState failed"));
        return false;
    }

    D3D11_BLEND_DESC blend_desc = {};
    blend_desc.RenderTarget[0].BlendEnable = TRUE;
    blend_desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    blend_desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    blend_desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    blend_desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    blend_desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
    blend_desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    blend_desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

    if (FAILED(m_device->CreateBlendState(&blend_desc, &m_blend_state))) {
        LOG_ERROR(xorstr_("[blur] CreateBlendState failed"));
        return false;
    }

    D3D11_RASTERIZER_DESC raster_desc = {};
    raster_desc.FillMode = D3D11_FILL_SOLID;
    raster_desc.CullMode = D3D11_CULL_NONE;
    raster_desc.ScissorEnable = FALSE;
    raster_desc.DepthClipEnable = FALSE;

    if (FAILED(m_device->CreateRasterizerState(&raster_desc, &m_rasterizer_state))) {
        LOG_ERROR(xorstr_("[blur] CreateRasterizerState failed"));
        return false;
    }

    m_initialized = true;
    return true;
}

void c_blur::shutdown() {
    release_textures();

    m_vertex_shader.Reset();
    m_horizontal_blur_shader.Reset();
    m_vertical_blur_shader.Reset();
    m_composite_shader.Reset();
    m_vertex_buffer.Reset();
    m_constant_buffer.Reset();
    m_input_layout.Reset();
    m_sampler_state.Reset();
    m_blend_state.Reset();
    m_rasterizer_state.Reset();

    m_device.Reset();
    m_context.Reset();

    m_initialized = false;
}

bool c_blur::create_shaders() {
    HRESULT hr;
    ComPtr<ID3DBlob> vs_blob;
    ComPtr<ID3DBlob> error_blob;

    hr = D3DCompile(vertex_shader_code, strlen(vertex_shader_code), nullptr, nullptr, nullptr,
        "main", "vs_5_0", 0, 0, &vs_blob, &error_blob);
    if (FAILED(hr))
        return log_shader_error("vertex shader", hr, error_blob.Get());

    hr = m_device->CreateVertexShader(vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), nullptr, &m_vertex_shader);
    if (FAILED(hr)) {
        LOG_ERROR(xorstr_("[blur] CreateVertexShader failed: 0x%08X"), hr);
        return false;
    }

    D3D11_INPUT_ELEMENT_DESC layout[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 8, D3D11_INPUT_PER_VERTEX_DATA, 0 }
    };

    hr = m_device->CreateInputLayout(layout, 2, vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), &m_input_layout);
    if (FAILED(hr)) {
        LOG_ERROR(xorstr_("[blur] CreateInputLayout failed: 0x%08X"), hr);
        return false;
    }

    ComPtr<ID3DBlob> h_blur_blob;
    hr = D3DCompile(horizontal_blur_shader_code, strlen(horizontal_blur_shader_code), nullptr,
        nullptr, nullptr, "main", "ps_5_0", 0, 0, &h_blur_blob, &error_blob);
    if (FAILED(hr))
        return log_shader_error("horizontal blur shader", hr, error_blob.Get());

    hr = m_device->CreatePixelShader(h_blur_blob->GetBufferPointer(), h_blur_blob->GetBufferSize(), nullptr, &m_horizontal_blur_shader);
    if (FAILED(hr)) {
        LOG_ERROR(xorstr_("[blur] CreatePixelShader horizontal failed: 0x%08X"), hr);
        return false;
    }

    ComPtr<ID3DBlob> v_blur_blob;
    hr = D3DCompile(vertical_blur_shader_code, strlen(vertical_blur_shader_code), nullptr,
        nullptr, nullptr, "main", "ps_5_0", 0, 0, &v_blur_blob, &error_blob);
    if (FAILED(hr))
        return log_shader_error("vertical blur shader", hr, error_blob.Get());

    hr = m_device->CreatePixelShader(v_blur_blob->GetBufferPointer(), v_blur_blob->GetBufferSize(), nullptr, &m_vertical_blur_shader);
    if (FAILED(hr)) {
        LOG_ERROR(xorstr_("[blur] CreatePixelShader vertical failed: 0x%08X"), hr);
        return false;
    }

    ComPtr<ID3DBlob> composite_blob;
    hr = D3DCompile(composite_shader_code, strlen(composite_shader_code), nullptr,
        nullptr, nullptr, "main", "ps_5_0", 0, 0, &composite_blob, &error_blob);
    if (FAILED(hr))
        return log_shader_error("composite shader", hr, error_blob.Get());

    hr = m_device->CreatePixelShader(composite_blob->GetBufferPointer(), composite_blob->GetBufferSize(), nullptr, &m_composite_shader);
    if (FAILED(hr)) {
        LOG_ERROR(xorstr_("[blur] CreatePixelShader composite failed: 0x%08X"), hr);
        return false;
    }

    return true;
}

bool c_blur::create_buffers() {
    struct Vertex {
        float pos[2];
        float uv[2];
    };

    Vertex vertices[] = {
        { { -1.0f,  1.0f }, { 0.0f, 0.0f } },
        { {  1.0f,  1.0f }, { 1.0f, 0.0f } },
        { { -1.0f, -1.0f }, { 0.0f, 1.0f } },
        { {  1.0f, -1.0f }, { 1.0f, 1.0f } }
    };

    D3D11_BUFFER_DESC vb_desc = {};
    vb_desc.Usage = D3D11_USAGE_DEFAULT;
    vb_desc.ByteWidth = sizeof(vertices);
    vb_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA vb_data = {};
    vb_data.pSysMem = vertices;

    if (FAILED(m_device->CreateBuffer(&vb_desc, &vb_data, &m_vertex_buffer))) {
        LOG_ERROR(xorstr_("[blur] CreateBuffer vertex failed"));
        return false;
    }

    D3D11_BUFFER_DESC cb_desc = {};
    cb_desc.Usage = D3D11_USAGE_DYNAMIC;
    cb_desc.ByteWidth = sizeof(BlurConstants);
    cb_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cb_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    if (FAILED(m_device->CreateBuffer(&cb_desc, nullptr, &m_constant_buffer))) {
        LOG_ERROR(xorstr_("[blur] CreateBuffer constant failed"));
        return false;
    }

    return true;
}

bool c_blur::create_textures(int width, int height) {
    if (width == m_screen_width && height == m_screen_height && m_temp_texture)
        return true;

    release_textures();

    m_screen_width = width;
    m_screen_height = height;

    D3D11_TEXTURE2D_DESC tex_desc = {};
    tex_desc.Width = width;
    tex_desc.Height = height;
    tex_desc.MipLevels = 1;
    tex_desc.ArraySize = 1;
    tex_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    tex_desc.SampleDesc.Count = 1;
    tex_desc.Usage = D3D11_USAGE_DEFAULT;
    tex_desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;

    if (FAILED(m_device->CreateTexture2D(&tex_desc, nullptr, &m_temp_texture))) {
        LOG_ERROR(xorstr_("[blur] CreateTexture2D temp failed"));
        return false;
    }
    if (FAILED(m_device->CreateRenderTargetView(m_temp_texture.Get(), nullptr, &m_temp_rtv))) {
        LOG_ERROR(xorstr_("[blur] CreateRenderTargetView temp failed"));
        return false;
    }
    if (FAILED(m_device->CreateShaderResourceView(m_temp_texture.Get(), nullptr, &m_temp_srv))) {
        LOG_ERROR(xorstr_("[blur] CreateShaderResourceView temp failed"));
        return false;
    }

    if (FAILED(m_device->CreateTexture2D(&tex_desc, nullptr, &m_blur_texture))) {
        LOG_ERROR(xorstr_("[blur] CreateTexture2D blur failed"));
        return false;
    }
    if (FAILED(m_device->CreateRenderTargetView(m_blur_texture.Get(), nullptr, &m_blur_rtv))) {
        LOG_ERROR(xorstr_("[blur] CreateRenderTargetView blur failed"));
        return false;
    }
    if (FAILED(m_device->CreateShaderResourceView(m_blur_texture.Get(), nullptr, &m_blur_srv))) {
        LOG_ERROR(xorstr_("[blur] CreateShaderResourceView blur failed"));
        return false;
    }

    return true;
}

void c_blur::release_textures() {
    m_temp_texture.Reset();
    m_temp_rtv.Reset();
    m_temp_srv.Reset();
    m_blur_texture.Reset();
    m_blur_rtv.Reset();
    m_blur_srv.Reset();
}

void c_blur::resize(int width, int height) {
    if (width != m_screen_width || height != m_screen_height)
        create_textures(width, height);
}

void c_blur::apply_blur(float x, float y, float width, float height, float blur_strength, float corner_radius) {
    if (!m_initialized || !m_context || width <= 0.0f || height <= 0.0f)
        return;

    ComPtr<ID3D11RenderTargetView> original_rtv;
    ComPtr<ID3D11DepthStencilView> original_dsv;
    m_context->OMGetRenderTargets(1, &original_rtv, &original_dsv);
    if (!original_rtv)
        return;

    ComPtr<ID3D11Resource> resource;
    original_rtv->GetResource(&resource);
    ComPtr<ID3D11Texture2D> backbuffer;
    resource.As(&backbuffer);
    if (!backbuffer)
        return;

    D3D11_TEXTURE2D_DESC bb_desc = {};
    backbuffer->GetDesc(&bb_desc);
    if (!create_textures((int)bb_desc.Width, (int)bb_desc.Height))
        return;

    D3D11_MAPPED_SUBRESOURCE mapped = {};
    if (SUCCEEDED(m_context->Map(m_constant_buffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped))) {
        BlurConstants* constants = static_cast<BlurConstants*>(mapped.pData);
        constants->blur_size = blur_strength * 0.65f;
        constants->blur_strength = blur_strength;
        constants->screen_width = static_cast<float>(bb_desc.Width);
        constants->screen_height = static_cast<float>(bb_desc.Height);
        constants->menu_x = x;
        constants->menu_y = y;
        constants->menu_width = width;
        constants->menu_height = height;
        constants->corner_radius = corner_radius;
        constants->edge_softness = 1.5f;
        constants->padding[0] = 0.0f;
        constants->padding[1] = 0.0f;
        m_context->Unmap(m_constant_buffer.Get(), 0);
    }

    ComPtr<ID3D11BlendState> old_blend_state;
    float old_blend_factor[4] = {};
    UINT old_sample_mask = 0xffffffff;
    m_context->OMGetBlendState(&old_blend_state, old_blend_factor, &old_sample_mask);

    ComPtr<ID3D11RasterizerState> old_rasterizer_state;
    m_context->RSGetState(&old_rasterizer_state);

    D3D11_VIEWPORT old_viewport = {};
    UINT num_viewports = 1;
    m_context->RSGetViewports(&num_viewports, &old_viewport);

    m_context->CopyResource(m_temp_texture.Get(), backbuffer.Get());

    m_context->IASetInputLayout(m_input_layout.Get());
    m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

    UINT stride = sizeof(float) * 4;
    UINT offset = 0;
    m_context->IASetVertexBuffers(0, 1, m_vertex_buffer.GetAddressOf(), &stride, &offset);

    m_context->VSSetShader(m_vertex_shader.Get(), nullptr, 0);
    m_context->PSSetConstantBuffers(0, 1, m_constant_buffer.GetAddressOf());
    m_context->PSSetSamplers(0, 1, m_sampler_state.GetAddressOf());
    m_context->OMSetBlendState(m_blend_state.Get(), nullptr, 0xffffffff);
    m_context->RSSetState(m_rasterizer_state.Get());

    D3D11_VIEWPORT viewport = {};
    viewport.Width = static_cast<float>(bb_desc.Width);
    viewport.Height = static_cast<float>(bb_desc.Height);
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;
    m_context->RSSetViewports(1, &viewport);

    m_context->OMSetRenderTargets(1, m_blur_rtv.GetAddressOf(), nullptr);
    m_context->PSSetShader(m_horizontal_blur_shader.Get(), nullptr, 0);
    m_context->PSSetShaderResources(0, 1, m_temp_srv.GetAddressOf());
    m_context->Draw(4, 0);

    ID3D11ShaderResourceView* null_srv = nullptr;
    m_context->PSSetShaderResources(0, 1, &null_srv);

    m_context->OMSetRenderTargets(1, m_temp_rtv.GetAddressOf(), nullptr);
    m_context->PSSetShader(m_vertical_blur_shader.Get(), nullptr, 0);
    m_context->PSSetShaderResources(0, 1, m_blur_srv.GetAddressOf());
    m_context->Draw(4, 0);

    m_context->PSSetShaderResources(0, 1, &null_srv);

    m_context->OMSetRenderTargets(1, original_rtv.GetAddressOf(), original_dsv.Get());
    m_context->RSSetViewports(1, &old_viewport);
    // Composite pass should overwrite inside the mask; blending can cause faint rectangular artifacts.
    m_context->OMSetBlendState(nullptr, nullptr, 0xffffffff);
    m_context->PSSetShader(m_composite_shader.Get(), nullptr, 0);
    m_context->PSSetShaderResources(0, 1, m_temp_srv.GetAddressOf());
    m_context->Draw(4, 0);

    m_context->PSSetShaderResources(0, 1, &null_srv);
    m_context->OMSetBlendState(old_blend_state.Get(), old_blend_factor, old_sample_mask);
    m_context->RSSetState(old_rasterizer_state.Get());
}
