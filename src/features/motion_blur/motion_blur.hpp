#pragma once
#include <d3d11.h>
#include <memory>

class c_motion_blur {
    ID3D11Device* m_device = nullptr;
    ID3D11DeviceContext* m_context = nullptr;
    int m_width = 0;
    int m_height = 0;
    bool m_initialized = false;
    bool m_first_frame = true;

    ID3D11VertexShader* m_vs = nullptr;
    ID3D11PixelShader* m_ps = nullptr;
    ID3D11SamplerState* m_sampler = nullptr;
    ID3D11BlendState* m_blend_state = nullptr;
    ID3D11Buffer* m_cb = nullptr;

    ID3D11Texture2D* m_frame_copy = nullptr;
    ID3D11ShaderResourceView* m_frame_copy_srv = nullptr;
    ID3D11Texture2D* m_accum = nullptr;
    ID3D11ShaderResourceView* m_accum_srv = nullptr;
    ID3D11Texture2D* m_output = nullptr;
    ID3D11RenderTargetView* m_output_rtv = nullptr;
    ID3D11ShaderResourceView* m_output_srv = nullptr;

    DXGI_FORMAT m_format = DXGI_FORMAT_R8G8B8A8_UNORM;
    bool create_shaders();
    bool create_resources();

public:
    bool initialize(ID3D11Device* device, ID3D11DeviceContext* context, IDXGISwapChain* swap_chain);
    void render(IDXGISwapChain* swap_chain, float strength);
    void cleanup();
    bool is_initialized() const { return m_initialized; }
};

inline const auto g_motion_blur = std::make_unique<c_motion_blur>();
