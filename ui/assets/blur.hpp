#pragma once
#include <d3d11.h>
#include <wrl/client.h>
#include <memory>

using Microsoft::WRL::ComPtr;

class c_blur {
public:
    bool initialize(ID3D11Device* device, ID3D11DeviceContext* context);
    void shutdown();
    void apply_blur(float x, float y, float width, float height, float blur_strength = 10.0f, float corner_radius = 16.0f);
    void resize(int width, int height);

    bool is_initialized() const { return m_initialized; }

private:
    bool create_shaders();
    bool create_buffers();
    bool create_textures(int width, int height);
    void release_textures();

    ComPtr<ID3D11Device> m_device;
    ComPtr<ID3D11DeviceContext> m_context;

    ComPtr<ID3D11VertexShader> m_vertex_shader;
    ComPtr<ID3D11PixelShader> m_horizontal_blur_shader;
    ComPtr<ID3D11PixelShader> m_vertical_blur_shader;
    ComPtr<ID3D11PixelShader> m_composite_shader;

    ComPtr<ID3D11Buffer> m_vertex_buffer;
    ComPtr<ID3D11Buffer> m_constant_buffer;
    ComPtr<ID3D11InputLayout> m_input_layout;

    ComPtr<ID3D11Texture2D> m_temp_texture;
    ComPtr<ID3D11RenderTargetView> m_temp_rtv;
    ComPtr<ID3D11ShaderResourceView> m_temp_srv;

    ComPtr<ID3D11Texture2D> m_blur_texture;
    ComPtr<ID3D11RenderTargetView> m_blur_rtv;
    ComPtr<ID3D11ShaderResourceView> m_blur_srv;

    ComPtr<ID3D11SamplerState> m_sampler_state;
    ComPtr<ID3D11BlendState> m_blend_state;
    ComPtr<ID3D11RasterizerState> m_rasterizer_state;

    int m_screen_width = 0;
    int m_screen_height = 0;
    bool m_initialized = false;

    struct BlurConstants {
        float blur_size;
        float blur_strength;
        float screen_width;
        float screen_height;
        float menu_x;
        float menu_y;
        float menu_width;
        float menu_height;
        float corner_radius;
        float edge_softness;
        float padding[2];
    };
};

inline const auto g_blur = std::make_unique<c_blur>();
