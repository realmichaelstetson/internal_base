#include "../../src/core/main.hpp"
#include "directx.hpp"
#include "../../ui/menu/menu.hpp"
#include "../../src/hooks/hooks.hpp"
#include <windowsx.h>
using namespace hooks;
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static LRESULT CALLBACK wnd_proc_hook(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	LPARAM scaled_lparam = lparam;
	if (msg == WM_MOUSEMOVE || msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP ||
		msg == WM_RBUTTONDOWN || msg == WM_RBUTTONUP || msg == WM_MBUTTONDOWN ||
		msg == WM_MBUTTONUP || msg == WM_LBUTTONDBLCLK || msg == WM_RBUTTONDBLCLK ||
		msg == WM_MOUSEWHEEL || msg == WM_MOUSEHWHEEL) {
		int x = GET_X_LPARAM(lparam);
		int y = GET_Y_LPARAM(lparam);
		x = (int)(x * g_directx->get_mouse_scale_x());
		y = (int)(y * g_directx->get_mouse_scale_y());
		scaled_lparam = MAKELPARAM(x, y);
	}

	const bool imgui_consumed = ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, scaled_lparam) != 0;
	const bool menu_captures_input = g_menu && g_menu->m_opened && g_init_progress.done;
	if (menu_captures_input) {
		if (msg >= WM_MOUSEFIRST && msg <= WM_MOUSELAST)
			return true;

		const ImGuiIO& io = ImGui::GetIO();
		const bool wants_keyboard_input = io.WantTextInput || io.WantCaptureKeyboard;
		const bool is_keyboard_msg = (msg >= WM_KEYFIRST && msg <= WM_KEYLAST) ||
		                              msg == WM_CHAR || msg == WM_SYSCHAR ||
		                              msg == WM_UNICHAR || msg == WM_INPUT;
		if (wants_keyboard_input && is_keyboard_msg)
			return true;
		if (imgui_consumed && !is_keyboard_msg)
			return true;
	}

	return CallWindowProcA(g_directx->get_wnd_proc_original(), hwnd, msg, wparam, lparam);
}

bool c_directx::initialize() {

	WNDCLASSEXA wc{};
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = DefWindowProcA;
	wc.hInstance = GetModuleHandleA(nullptr);
	wc.lpszClassName = "celerity_dummy_window";
	if (!RegisterClassExA(&wc)) {
		LOG_ERROR(xorstr_("[directx] dummy window class registration failed: %lu"), GetLastError());
		return false;
	}

	HWND dummy_hwnd = CreateWindowExA(0, wc.lpszClassName, "", 0, 0, 0, 1, 1,
		nullptr, nullptr, wc.hInstance, nullptr);
	if (!dummy_hwnd) {
		LOG_ERROR(xorstr_("[directx] dummy window creation failed: %lu"), GetLastError());
		UnregisterClassA(wc.lpszClassName, wc.hInstance);
		return false;
	}

	DXGI_SWAP_CHAIN_DESC desc{};
	desc.BufferCount = 1;
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = dummy_hwnd;
	desc.SampleDesc.Count = 1;
	desc.Windowed = TRUE;
	desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	IDXGISwapChain* dummy_chain = nullptr;
	ID3D11Device* dummy_device = nullptr;
	ID3D11DeviceContext* dummy_ctx = nullptr;
	D3D_FEATURE_LEVEL feature_level;
	const D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0 };

	HRESULT hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE,
		nullptr, 0, levels, _countof(levels), D3D11_SDK_VERSION,
		&desc, &dummy_chain, &dummy_device, &feature_level, &dummy_ctx);

	if (FAILED(hr) || !dummy_chain) {
		LOG_ERROR(xorstr_("[directx] dummy swap chain creation failed: 0x%08X"), hr);
		if (dummy_hwnd) DestroyWindow(dummy_hwnd);
		UnregisterClassA(wc.lpszClassName, wc.hInstance);
		return false;
	}

	m_present_address       = vmt::get_v_method(dummy_chain, 8);
	m_resize_buffers_address = vmt::get_v_method(dummy_chain, 13);

	IDXGIDevice* dxgi_device = nullptr;
	if (SUCCEEDED(dummy_chain->GetDevice(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgi_device))) && dxgi_device) {
		IDXGIAdapter* adapter = nullptr;
		if (SUCCEEDED(dxgi_device->GetAdapter(&adapter)) && adapter) {
			IDXGIFactory* factory = nullptr;
			if (SUCCEEDED(adapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&factory))) && factory) {
				m_create_swap_chain_address = vmt::get_v_method(factory, 10);
				factory->Release();
			}
			adapter->Release();
		}
		dxgi_device->Release();
	}

	if (dummy_ctx)    dummy_ctx->Release();
	if (dummy_device) dummy_device->Release();
	if (dummy_chain)  dummy_chain->Release();
	if (dummy_hwnd)   DestroyWindow(dummy_hwnd);
	UnregisterClassA(wc.lpszClassName, wc.hInstance);

	if (!m_present_address || !m_resize_buffers_address) {
		LOG_ERROR(xorstr_("[directx] failed to resolve swap-chain methods"));
		diagnostics::g_diagnostics->mark_hook("Present", false, false);
		diagnostics::g_diagnostics->mark_hook("ResizeBuffers", false, false);
		return false;
	}

	diagnostics::g_diagnostics->mark_hook("Present", true, false);
	diagnostics::g_diagnostics->mark_hook("ResizeBuffers", true, false);
	diagnostics::g_diagnostics->mark_hook("CreateSwapChain", m_create_swap_chain_address != nullptr, false);

	return true;
}

void c_directx::uninitialize() {
	if (m_wnd_proc_original && m_window) {
		SetWindowLongPtrA(m_window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(m_wnd_proc_original));
		m_wnd_proc_original = nullptr;
	}

	destroy_render_target();

	if (m_imgui_initialized) {
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
		m_imgui_initialized = false;
	}

	if (m_device_context) { m_device_context->Release(); m_device_context = nullptr; }
	if (m_device)         { m_device->Release();         m_device         = nullptr; }
	m_swap_chain = nullptr;
	m_window = nullptr;
	m_started = false;
	m_initial_cursor_synced = false;
	m_last_dpi_scale = 0.0f;
}

void c_directx::cleanup_imgui() {
	if (m_imgui_initialized) {
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
		m_imgui_initialized = false;
	}
}

void c_directx::reinitialize_imgui() {
	if (!m_device || !m_device_context || !m_window)
		return;

	if (!m_imgui_initialized) {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplWin32_Init(m_window);
		ImGui_ImplDX11_Init(m_device, m_device_context);
		m_imgui_initialized = true;

		if (g_menu) {
			RECT rect;
			int screen_h = 0;
			if (GetClientRect(m_window, &rect))
				screen_h = rect.bottom - rect.top;

			float scale = 1.0f;
			if (screen_h > 0) {
				// Better scaling: use sqrt for more gradual scaling
				// 1080p = 1.0x, 1440p = 1.15x, 4K = 1.41x
				float ratio = screen_h / 1080.0f;
				scale = sqrtf(ratio);
				if (scale < 0.5f) scale = 0.5f;
				if (scale > 2.0f) scale = 2.0f;
			}
			g_menu->rebuild_fonts(scale);
			m_last_dpi_scale = scale;
		}
	}
}

void c_directx::create_render_target() {
	if (!m_swap_chain || !m_device)
		return;

	if (m_render_target) {
		m_render_target->Release();
		m_render_target = nullptr;
	}

	ID3D11Texture2D* back_buffer = nullptr;
	if (SUCCEEDED(m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&back_buffer))) && back_buffer) {
		m_device->CreateRenderTargetView(back_buffer, nullptr, &m_render_target);
		back_buffer->Release();
	}
}

void c_directx::destroy_render_target() {
	if (m_render_target) {
		m_render_target->Release();
		m_render_target = nullptr;
	}
}

void c_directx::update_dpi_scale() {
	if (!m_imgui_initialized || !m_window)
		return;

	RECT rect;
	if (!GetClientRect(m_window, &rect))
		return;

	int height = rect.bottom - rect.top;
	if (height <= 0)
		return;

	// Better scaling: use sqrt for more gradual scaling
	// 1080p = 1.0x, 1440p = 1.15x, 4K = 1.41x
	float ratio = height / 1080.0f;
	float scale = sqrtf(ratio);
	if (scale < 0.5f) scale = 0.5f;
	if (scale > 2.0f) scale = 2.0f;

	if (!g_menu)
		return;

	const bool fonts_missing = g_menu->get_menu_bold_font() == nullptr;
	if (fonts_missing || std::abs(scale - m_last_dpi_scale) > 0.01f) {
		g_menu->rebuild_fonts(scale);
		m_last_dpi_scale = scale;
	}
}

void c_directx::start_frame(IDXGISwapChain* swap_chain) {

	if (!m_started || m_swap_chain != swap_chain) {

		if (m_swap_chain != swap_chain) {
			if (m_device_context) { m_device_context->Release(); m_device_context = nullptr; }
			if (m_device) { m_device->Release(); m_device = nullptr; }
		}

		m_swap_chain = swap_chain;

		if (FAILED(swap_chain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&m_device))) || !m_device) {
			LOG_ERROR(xorstr_("[directx] failed to get D3D11 device"));
			return;
		}

		m_device->GetImmediateContext(&m_device_context);
		if (!m_device_context) {
			LOG_ERROR(xorstr_("[directx] failed to get D3D11 device context"));
			if (m_device) { m_device->Release(); m_device = nullptr; }
			m_swap_chain = nullptr;
			return;
		}

		if (!m_started) {
			DXGI_SWAP_CHAIN_DESC desc;
			if (FAILED(swap_chain->GetDesc(&desc)) || !desc.OutputWindow) {
				LOG_ERROR(xorstr_("[directx] failed to get swap-chain description"));
				if (m_device_context) { m_device_context->Release(); m_device_context = nullptr; }
				if (m_device) { m_device->Release(); m_device = nullptr; }
				m_swap_chain = nullptr;
				return;
			}
			m_window = desc.OutputWindow;

			m_wnd_proc_original = reinterpret_cast<WNDPROC>(
				SetWindowLongPtrA(m_window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(wnd_proc_hook)));

			create_render_target();

			ImGui::CreateContext();
			ImGui::StyleColorsDark();
			ImGui_ImplWin32_Init(m_window);
			ImGui_ImplDX11_Init(m_device, m_device_context);

			m_imgui_initialized = true;

			RECT rect;
			int screen_h = 0;
			if (GetClientRect(m_window, &rect))
				screen_h = rect.bottom - rect.top;

			float scale = 1.0f;
			if (screen_h > 0) {
				scale = screen_h / 1080.0f;
				if (scale < 0.5f) scale = 0.5f;
				if (scale > 4.0f) scale = 4.0f;
			}
			if (g_menu)
				g_menu->rebuild_fonts(scale);
			m_last_dpi_scale = scale;

			m_started = true;
		} else if (m_swap_chain != swap_chain && !m_imgui_initialized) {

			reinitialize_imgui();
		}
	}

	if (!m_render_target)
		create_render_target();

	update_dpi_scale();
}

void c_directx::new_frame() {
	if (!m_imgui_initialized)
		return;

	m_mouse_scale_x = 1.0f;
	m_mouse_scale_y = 1.0f;

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void c_directx::end_frame() {
	if (!m_imgui_initialized)
		return;

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}
