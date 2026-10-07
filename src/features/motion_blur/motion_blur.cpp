#include "motion_blur.hpp"
#include <d3dcompiler.h>

#pragma comment(lib, "d3dcompiler.lib")

static const char* k_vs_src = R"(
struct VS_OUT {
    float4 pos : SV_POSITION;
    float2 uv  : TEXCOORD0;
};
VS_OUT vs_main(uint id : SV_VertexID) {
    VS_OUT o;
    o.uv  = float2(id & 1, (id >> 1) & 1);
    o.pos = float4(o.uv.x * 2.0f - 1.0f, 1.0f - o.uv.y * 2.0f, 0.0f, 1.0f);
    return o;
}
)";

static const char* k_ps_src = R"(
Texture2D<float4> tex_current : register(t0);
Texture2D<float4> tex_accum   : register(t1);
SamplerState samp : register(s0);

cbuffer cb : register(b0) {
    float2 texel_size;
    float  strength;
    float  _padding;
};

struct PS_IN {
    float4 pos : SV_POSITION;
    float2 uv  : TEXCOORD0;
};

float4 ps_main(PS_IN input) : SV_TARGET {
    float4 current = tex_current.Sample(samp, input.uv);
    float4 accum   = tex_accum.Sample(samp, input.uv);
    return lerp(current, accum, saturate(strength));
}
)";

bool c_motion_blur::create_shaders() {
    ID3DBlob* vs_blob = nullptr;
    ID3DBlob* ps_blob = nullptr;
    ID3DBlob* err = nullptr;

    HRESULT hr = D3DCompile(k_vs_src, strlen(k_vs_src), nullptr, nullptr, nullptr,
                            "vs_main", "vs_5_0", 0, 0, &vs_blob, &err);
    if (FAILED(hr)) {
        if (err) { err->Release(); }
        return false;
    }

    hr = m_device->CreateVertexShader(vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(),
                                       nullptr, &m_vs);
    if (FAILED(hr)) {
        vs_blob->Release();
        return false;
    }

    hr = D3DCompile(k_ps_src, strlen(k_ps_src), nullptr, nullptr, nullptr,
                    "ps_main", "ps_5_0", 0, 0, &ps_blob, &err);
    if (FAILED(hr)) {
        if (err) { err->Release(); }
        vs_blob->Release();
        return false;
    }

    hr = m_device->CreatePixelShader(ps_blob->GetBufferPointer(), ps_blob->GetBufferSize(),
                                      nullptr, &m_ps);
    ps_blob->Release();
    if (FAILED(hr)) {
        vs_blob->Release();
        return false;
    }

    vs_blob->Release();
    return true;
}

bool c_motion_blur::create_resources() {
    D3D11_TEXTURE2D_DESC desc{};
    desc.Width = m_width;
    desc.Height = m_height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = m_format;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

    HRESULT hr = m_device->CreateTexture2D(&desc, nullptr, &m_frame_copy);
    if (FAILED(hr)) return false;

    D3D11_SHADER_RESOURCE_VIEW_DESC srv_desc{};
    srv_desc.Format = desc.Format;
    srv_desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srv_desc.Texture2D.MipLevels = 1;

    hr = m_device->CreateShaderResourceView(m_frame_copy, &srv_desc, &m_frame_copy_srv);
    if (FAILED(hr)) return false;

    hr = m_device->CreateTexture2D(&desc, nullptr, &m_accum);
    if (FAILED(hr)) return false;

    hr = m_device->CreateShaderResourceView(m_accum, &srv_desc, &m_accum_srv);
    if (FAILED(hr)) return false;

    desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    hr = m_device->CreateTexture2D(&desc, nullptr, &m_output);
    if (FAILED(hr)) return false;

    D3D11_RENDER_TARGET_VIEW_DESC rtv_desc{};
    rtv_desc.Format = desc.Format;
    rtv_desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
    rtv_desc.Texture2D.MipSlice = 0;

    hr = m_device->CreateRenderTargetView(m_output, &rtv_desc, &m_output_rtv);
    if (FAILED(hr)) return false;

    hr = m_device->CreateShaderResourceView(m_output, &srv_desc, &m_output_srv);
    if (FAILED(hr)) return false;

    D3D11_SAMPLER_DESC samp_desc{};
    samp_desc.Filter = D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT;
    samp_desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
    samp_desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
    samp_desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    samp_desc.MaxLOD = D3D11_FLOAT32_MAX;

    hr = m_device->CreateSamplerState(&samp_desc, &m_sampler);
    if (FAILED(hr)) return false;

    D3D11_BLEND_DESC blend_desc{};
    blend_desc.RenderTarget[0].BlendEnable = FALSE;
    blend_desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    hr = m_device->CreateBlendState(&blend_desc, &m_blend_state);
    if (FAILED(hr)) return false;

    D3D11_BUFFER_DESC cb_desc{};
    cb_desc.ByteWidth = sizeof(float) * 4;
    cb_desc.Usage = D3D11_USAGE_DYNAMIC;
    cb_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cb_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    hr = m_device->CreateBuffer(&cb_desc, nullptr, &m_cb);
    if (FAILED(hr)) return false;

    return true;
}

bool c_motion_blur::initialize(ID3D11Device* device, ID3D11DeviceContext* context,
                                IDXGISwapChain* swap_chain) {
    cleanup();

    DXGI_SWAP_CHAIN_DESC sc_desc;
    if (FAILED(swap_chain->GetDesc(&sc_desc)))
        return false;

    m_device = device;
    m_context = context;
    m_width = (int)sc_desc.BufferDesc.Width;
    m_height = (int)sc_desc.BufferDesc.Height;
    m_format = sc_desc.BufferDesc.Format;

    if (!create_shaders()) {
        cleanup();
        return false;
    }

    if (!create_resources()) {
        cleanup();
        return false;
    }

    m_initialized = true;
    return true;
}

void c_motion_blur::render(IDXGISwapChain* swap_chain, float strength) {
    if (!m_initialized || !m_device || !m_context || !swap_chain || strength <= 0.0f)
        return;

    ID3D11Texture2D* backbuffer = nullptr;
    HRESULT hr = swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D),
                                        reinterpret_cast<void**>(&backbuffer));
    if (FAILED(hr) || !backbuffer)
        return;

    ID3D11RenderTargetView* old_rtv = nullptr;
    ID3D11ShaderResourceView* old_srvs[2] = {};
    ID3D11Buffer* old_cb = nullptr;
    ID3D11SamplerState* old_sampler = nullptr;
    ID3D11BlendState* old_blend = nullptr;
    UINT old_sample_mask = 0;
    ID3D11VertexShader* old_vs = nullptr;
    ID3D11PixelShader* old_ps = nullptr;
    ID3D11InputLayout* old_layout = nullptr;
    D3D11_PRIMITIVE_TOPOLOGY old_topology = D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED;
    float blend_factor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

    m_context->OMGetRenderTargets(1, &old_rtv, nullptr);
    m_context->VSGetShader(&old_vs, nullptr, nullptr);
    m_context->PSGetShader(&old_ps, nullptr, nullptr);
    m_context->PSGetShaderResources(0, 2, old_srvs);
    m_context->PSGetConstantBuffers(0, 1, &old_cb);
    m_context->PSGetSamplers(0, 1, &old_sampler);
    m_context->OMGetBlendState(&old_blend, nullptr, &old_sample_mask);
    m_context->IAGetInputLayout(&old_layout);
    m_context->IAGetPrimitiveTopology(&old_topology);

    m_context->CopyResource(m_frame_copy, backbuffer);

    if (m_first_frame) {
        m_context->CopyResource(m_accum, backbuffer);
        m_context->CopyResource(m_output, backbuffer);
        m_first_frame = false;

        if (old_srvs[0]) old_srvs[0]->Release();
        if (old_srvs[1]) old_srvs[1]->Release();
        if (old_rtv) old_rtv->Release();
        if (old_cb) old_cb->Release();
        if (old_sampler) old_sampler->Release();
        if (old_blend) old_blend->Release();
        if (old_vs) old_vs->Release();
        if (old_ps) old_ps->Release();
        if (old_layout) old_layout->Release();
        backbuffer->Release();
        return;
    }

    {
    D3D11_MAPPED_SUBRESOURCE mapped{};
    hr = m_context->Map(m_cb, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped);
    if (SUCCEEDED(hr)) {
        float* data = static_cast<float*>(mapped.pData);
        data[0] = 1.0f / static_cast<float>(m_width);
        data[1] = 1.0f / static_cast<float>(m_height);
        data[2] = strength;
        data[3] = 0.0f;
        m_context->Unmap(m_cb, 0);
    }

    ID3D11ShaderResourceView* srvs[2] = { m_frame_copy_srv, m_accum_srv };
    m_context->PSSetShaderResources(0, 2, srvs);
    m_context->PSSetConstantBuffers(0, 1, &m_cb);
    m_context->PSSetSamplers(0, 1, &m_sampler);

    m_context->VSSetShader(m_vs, nullptr, 0);
    m_context->PSSetShader(m_ps, nullptr, 0);
    m_context->IASetInputLayout(nullptr);
    m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

    m_context->OMSetBlendState(m_blend_state, blend_factor, 0xFFFFFFFF);
    m_context->OMSetRenderTargets(1, &m_output_rtv, nullptr);

    m_context->Draw(4, 0);

    m_context->CopyResource(backbuffer, m_output);
    m_context->CopyResource(m_accum, m_output);
    }

    m_context->OMSetRenderTargets(1, &old_rtv, nullptr);
    m_context->VSSetShader(old_vs, nullptr, 0);
    m_context->PSSetShader(old_ps, nullptr, 0);
    m_context->PSSetShaderResources(0, 2, old_srvs);
    m_context->PSSetConstantBuffers(0, 1, &old_cb);
    m_context->PSSetSamplers(0, 1, &old_sampler);
    m_context->OMSetBlendState(old_blend, blend_factor, old_sample_mask);
    m_context->IASetInputLayout(old_layout);
    m_context->IASetPrimitiveTopology(old_topology);

    if (old_srvs[0]) old_srvs[0]->Release();
    if (old_srvs[1]) old_srvs[1]->Release();
    if (old_rtv) old_rtv->Release();
    if (old_cb) old_cb->Release();
    if (old_sampler) old_sampler->Release();
    if (old_blend) old_blend->Release();
    if (old_vs) old_vs->Release();
    if (old_ps) old_ps->Release();
    if (old_layout) old_layout->Release();

    backbuffer->Release();
}

void c_motion_blur::cleanup() {
    m_initialized = false;
    m_first_frame = true;
    m_device = nullptr;
    m_context = nullptr;

    if (m_vs) { m_vs->Release(); m_vs = nullptr; }
    if (m_ps) { m_ps->Release(); m_ps = nullptr; }
    if (m_sampler) { m_sampler->Release(); m_sampler = nullptr; }
    if (m_blend_state) { m_blend_state->Release(); m_blend_state = nullptr; }
    if (m_cb) { m_cb->Release(); m_cb = nullptr; }
    if (m_frame_copy) { m_frame_copy->Release(); m_frame_copy = nullptr; }
    if (m_frame_copy_srv) { m_frame_copy_srv->Release(); m_frame_copy_srv = nullptr; }
    if (m_accum) { m_accum->Release(); m_accum = nullptr; }
    if (m_accum_srv) { m_accum_srv->Release(); m_accum_srv = nullptr; }
    if (m_output) { m_output->Release(); m_output = nullptr; }
    if (m_output_rtv) { m_output_rtv->Release(); m_output_rtv = nullptr; }
    if (m_output_srv) { m_output_srv->Release(); m_output_srv = nullptr; }
}
