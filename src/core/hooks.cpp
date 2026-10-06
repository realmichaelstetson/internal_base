#include "hooks.h"

#include <d3d11.h>
#include <dxgi.h>
#include <MinHook.h>
#include <imgui.h>
#include <backends/imgui_impl_dx11.h>
#include <backends/imgui_impl_win32.h>

#include "../sdk/globals.h"
#include "../core/config.h"
#include "../features/chams.h"
#include "../sdk/offsets.h"
#include "../sdk/pattern.h"
#include "../ui/menu.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

namespace
{
	using PresentFn = HRESULT( __stdcall* )( IDXGISwapChain*, UINT, UINT );
	using ResizeBuffersFn = HRESULT( __stdcall* )( IDXGISwapChain*, UINT, UINT, UINT, DXGI_FORMAT, UINT );

	PresentFn oPresent = nullptr;
	ResizeBuffersFn oResizeBuffers = nullptr;
	features::chams::DrawObjectFn oDrawObject = nullptr;
	void* presentTarget = nullptr;
	void* resizeBuffersTarget = nullptr;

	HWND window = nullptr;
	WNDPROC oWndProc = nullptr;
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* context = nullptr;
	ID3D11RenderTargetView* renderTarget = nullptr;
	bool imguiReady = false;

	// CS2 uses SDL3 relative mouse mode, which locks the cursor in the middle of the screen.
	// Turn it off while the menu is open so the cursor can move freely.
	void setRelativeMouse( bool enabled )
	{
		const HMODULE sdl = GetModuleHandleA( "SDL3.dll" );
		if ( !sdl )
			return;

		using GetKeyboardFocusFn = void* ( * )( );
		using SetRelativeMouseModeFn = bool ( * )( void*, bool );

		const auto getFocus = reinterpret_cast< GetKeyboardFocusFn >( GetProcAddress( sdl, "SDL_GetKeyboardFocus" ) );
		const auto setRelative = reinterpret_cast< SetRelativeMouseModeFn >( GetProcAddress( sdl, "SDL_SetWindowRelativeMouseMode" ) );
		if ( !getFocus || !setRelative )
			return;

		if ( void* sdlWindow = getFocus( ) )
			setRelative( sdlWindow, enabled );
	}

	void toggleMenu( )
	{
		globals::menuOpen = !globals::menuOpen;
		setRelativeMouse( !globals::menuOpen );
	}

	bool isInputMessage( UINT msg )
	{
		return ( msg >= WM_MOUSEFIRST && msg <= WM_MOUSELAST ) ||
			( msg >= WM_KEYFIRST && msg <= WM_KEYLAST ) ||
			msg == WM_INPUT;
	}

	LRESULT CALLBACK hkWndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
	{
		if ( msg == WM_KEYDOWN && wParam == config::menuKey && !( lParam & ( 1 << 30 ) ) )
			toggleMenu( );

		if ( globals::menuOpen )
		{
			ImGui_ImplWin32_WndProcHandler( hWnd, msg, wParam, lParam );

			// block game input while the menu is open
			if ( isInputMessage( msg ) )
				return TRUE;
		}

		return CallWindowProcW( oWndProc, hWnd, msg, wParam, lParam );
	}

	void createRenderTarget( IDXGISwapChain* swapChain )
	{
		ID3D11Texture2D* backBuffer = nullptr;
		if ( SUCCEEDED( swapChain->GetBuffer( 0, IID_PPV_ARGS( &backBuffer ) ) ) )
		{
			device->CreateRenderTargetView( backBuffer, nullptr, &renderTarget );
			backBuffer->Release( );
		}
	}

	void releaseRenderTarget( )
	{
		if ( renderTarget )
		{
			renderTarget->Release( );
			renderTarget = nullptr;
		}
	}

	bool initImGui( IDXGISwapChain* swapChain )
	{
		if ( FAILED( swapChain->GetDevice( IID_PPV_ARGS( &device ) ) ) )
			return false;

		device->GetImmediateContext( &context );

		DXGI_SWAP_CHAIN_DESC desc{ };
		swapChain->GetDesc( &desc );
		window = desc.OutputWindow;

		createRenderTarget( swapChain );

		ImGui::CreateContext( );
		ImGuiIO& io = ImGui::GetIO( );
		io.IniFilename = nullptr;
		io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

		menu::setup( );

		ImGui_ImplWin32_Init( window );
		ImGui_ImplDX11_Init( device, context );

		oWndProc = reinterpret_cast< WNDPROC >( SetWindowLongPtrW( window, GWLP_WNDPROC, reinterpret_cast< LONG_PTR >( hkWndProc ) ) );

		if ( globals::menuOpen )
			setRelativeMouse( false );

		return true;
	}

	HRESULT __stdcall hkPresent( IDXGISwapChain* swapChain, UINT syncInterval, UINT flags )
	{
		if ( !imguiReady )
			imguiReady = initImGui( swapChain );

		if ( imguiReady && globals::running )
		{
			if ( !renderTarget )
				createRenderTarget( swapChain );

			ImGui_ImplDX11_NewFrame( );
			ImGui_ImplWin32_NewFrame( );
			ImGui::NewFrame( );

			ImGui::GetIO( ).MouseDrawCursor = globals::menuOpen;
			menu::render( );

			ImGui::Render( );
			context->OMSetRenderTargets( 1, &renderTarget, nullptr );
			ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData( ) );
		}

		return oPresent( swapChain, syncInterval, flags );
	}

	HRESULT __stdcall hkResizeBuffers( IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT format, UINT flags )
	{
		releaseRenderTarget( );
		return oResizeBuffers( swapChain, bufferCount, width, height, format, flags );
	}

	void* __fastcall hkDrawObject( void* desc, void* renderContext, void* sceneData, int count, void* sceneView, void* sceneLayer, void* unk )
	{
		return features::chams::onDrawObject( oDrawObject, desc, renderContext, sceneData, count, sceneView, sceneLayer, unk );
	}

	// Creates a throwaway device + swap chain just to read the IDXGISwapChain vtable.
	bool getSwapChainVTable( void** out )
	{
		WNDCLASSEXW wc{ sizeof( wc ), CS_HREDRAW | CS_VREDRAW, DefWindowProcW, 0, 0, GetModuleHandleW( nullptr ), nullptr, nullptr, nullptr, nullptr, L"dummy_dx11", nullptr };
		RegisterClassExW( &wc );
		HWND dummy = CreateWindowW( wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 0, 0, 100, 100, nullptr, nullptr, wc.hInstance, nullptr );

		DXGI_SWAP_CHAIN_DESC sd{ };
		sd.BufferCount = 1;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = dummy;
		sd.SampleDesc.Count = 1;
		sd.Windowed = TRUE;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		IDXGISwapChain* swapChain = nullptr;
		ID3D11Device* dummyDevice = nullptr;
		ID3D11DeviceContext* dummyContext = nullptr;
		const D3D_FEATURE_LEVEL levels[ ] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0 };

		const HRESULT hr = D3D11CreateDeviceAndSwapChain( nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, levels, 2,
			D3D11_SDK_VERSION, &sd, &swapChain, &dummyDevice, nullptr, &dummyContext );

		if ( SUCCEEDED( hr ) )
		{
			void** vtable = *reinterpret_cast< void*** >( swapChain );
			out[ 0 ] = vtable[ 8 ];  // Present
			out[ 1 ] = vtable[ 13 ]; // ResizeBuffers

			swapChain->Release( );
			dummyContext->Release( );
			dummyDevice->Release( );
		}

		DestroyWindow( dummy );
		UnregisterClassW( wc.lpszClassName, wc.hInstance );
		return SUCCEEDED( hr );
	}
}

bool hooks::init( )
{
	void* functions[ 2 ]{ };
	if ( !getSwapChainVTable( functions ) )
		return false;

	presentTarget = functions[ 0 ];
	resizeBuffersTarget = functions[ 1 ];

	if ( MH_Initialize( ) != MH_OK )
		return false;

	if ( MH_CreateHook( presentTarget, reinterpret_cast< void* >( &hkPresent ), reinterpret_cast< void** >( &oPresent ) ) != MH_OK )
		return false;

	if ( MH_CreateHook( resizeBuffersTarget, reinterpret_cast< void* >( &hkResizeBuffers ), reinterpret_cast< void** >( &oResizeBuffers ) ) != MH_OK )
		return false;

	// chams hook is optional - the menu still works if the signature is outdated
	if ( void* drawObject = reinterpret_cast< void* >( pattern::find( "scenesystem.dll", patterns::drawObject ) ) )
		MH_CreateHook( drawObject, reinterpret_cast< void* >( &hkDrawObject ), reinterpret_cast< void** >( &oDrawObject ) );

	return MH_EnableHook( MH_ALL_HOOKS ) == MH_OK;
}

bool hooks::chamsHooked( )
{
	return oDrawObject != nullptr;
}

void hooks::shutdown( )
{
	MH_DisableHook( MH_ALL_HOOKS );
	MH_Uninitialize( );

	// give any in-flight Present call time to finish
	Sleep( 100 );

	if ( oWndProc )
		SetWindowLongPtrW( window, GWLP_WNDPROC, reinterpret_cast< LONG_PTR >( oWndProc ) );

	if ( imguiReady )
	{
		ImGui_ImplDX11_Shutdown( );
		ImGui_ImplWin32_Shutdown( );
		ImGui::DestroyContext( );
	}

	setRelativeMouse( true );
	releaseRenderTarget( );
	if ( context )
		context->Release( );
	if ( device )
		device->Release( );
}
