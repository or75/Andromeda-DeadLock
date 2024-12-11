#include "CAndromedaGUI.hpp"
#include "DllLauncher.hpp"

#include <Common/Helpers/StringHelper.hpp>

#include <ShlObj_core.h>

#include <ImGui/imgui_impl_win32.h>
#include <ImGui/imgui_impl_dx11.h>

#include <DeadLock/SDK/SDK.hpp>
#include <DeadLock/SDK/Interface/IEngineToClient.hpp>
#include <DeadLock/SDK/SDL3/SDL3_Functions.hpp>

#include <DeadLock/Hook/Hook_IsRelativeMouseMode.hpp>

#include <AndromedaClient/CAndromedaClient.hpp>
#include <AndromedaClient/Fonts/FontAwesomeIcon.hpp>
#include <AndromedaClient/Settings/Settings.hpp>

static CAndromedaGUI g_CAndromedaGUI{};

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler( HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam );

auto CAndromedaGUI::OnInit( IDXGISwapChain* pSwapChain ) -> void
{
	DXGI_SWAP_CHAIN_DESC SwapChainDesc;

	if ( FAILED( pSwapChain->GetDevice( IID_PPV_ARGS( &m_pDevice ) ) ) )
	{
		DEV_LOG( "[error] CAndromedaGUI::OnInit: #1\n" );
		return;
	}

	m_pDevice->GetImmediateContext( &m_pDeviceContext );

	if ( FAILED( pSwapChain->GetDesc( &SwapChainDesc ) ) )
	{
		DEV_LOG( "[error] CAndromedaGUI::OnInit: #2\n" );
		return;
	}

	m_hDeadLockWindow = SwapChainDesc.OutputWindow;

	m_pImGuiContext = ImGui::CreateContext();

	m_GuiFile = GetDllDir() + XorStr( GUI_FILE );

	if ( !m_pFreeType_Font )
		m_pFreeType_Font = new FreeTypeBuild();

	ImGui::SetCurrentContext( m_pImGuiContext );

	ImGui::GetIO().IniFilename = m_GuiFile.c_str();
	ImGui::GetIO().LogFilename = "";

	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	ImGui::GetIO().BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	ImGui_ImplWin32_Init( m_hDeadLockWindow );
	ImGui_ImplDX11_Init( m_pDevice , m_pDeviceContext );

	InitFont();
	InitIndigoStyle();

	m_WndProc_o = (WNDPROC)SetWindowLongPtrA( m_hDeadLockWindow , GWLP_WNDPROC , (LONG_PTR)GUI_WndProc );

	m_bInit = true;
}

auto CAndromedaGUI::OnDestroy() -> void
{
	SetWindowLongPtrA( m_hDeadLockWindow , GWLP_WNDPROC , (LONG_PTR)GetAndromedaGUI()->m_WndProc_o );

	m_bVisible = false;

	if ( m_pFreeType_Font )
	{
		delete m_pFreeType_Font;
		m_pFreeType_Font = nullptr;
	}

	ClearRenderTargetView();

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImGui::DestroyContext();

	m_bInit = false;
}

auto CAndromedaGUI::InitFont() -> void
{
	ImGuiIO& io = ImGui::GetIO();

	ImFontConfig TahomaFontConfig;
	ImFontConfig FontAwesomeIconConfig;

	static const ImWchar TahomaRanges[] =
	{
		0x0020, 0xFFFC,
		0,
	};

	static const ImWchar AwesomeIconRanges[] =
	{
		0x002D, 0x007A,
		ICON_MIN_FA, ICON_MAX_FA,
		0
	};

	wchar_t* szWindowsFontPath = nullptr;

	if ( SHGetKnownFolderPath( FOLDERID_Fonts , 0 , 0 , &szWindowsFontPath ) == S_OK )
	{
		std::wstring TahomaFont = std::wstring( szWindowsFontPath ) + L"\\tahoma.ttf";
		io.Fonts->AddFontFromFileTTF( unicode_to_utf8( TahomaFont ).c_str() , 15.f , &TahomaFontConfig , TahomaRanges );
	}

	m_pFontAwesomeIcons = io.Fonts->AddFontFromMemoryCompressedTTF( FontAwesomeIcon_compressed_data , FontAwesomeIcon_compressed_size , 25.f , &FontAwesomeIconConfig , AwesomeIconRanges );

	CoTaskMemFree( szWindowsFontPath );
}

auto CAndromedaGUI::InitIndigoStyle() -> void
{
	auto& style = ImGui::GetStyle();
	auto& colors = style.Colors;

	float roundness = 2.0f;

	style.WindowBorderSize = 1.0f;
	style.FrameBorderSize = 1.0f;
	style.WindowMinSize = ImVec2( 75.f , 50.f );
	style.FramePadding = ImVec2( 5 , 5 );
	style.ItemSpacing = ImVec2( 6 , 5 );
	style.ItemInnerSpacing = ImVec2( 2 , 4 );
	style.Alpha = 1.0f;
	style.WindowRounding = 0.f;
	style.FrameRounding = roundness;
	style.PopupRounding = 0;
	style.PopupBorderSize = 1.f;
	style.IndentSpacing = 6.0f;
	style.ColumnsMinSpacing = 50.0f;
	style.GrabMinSize = 14.0f;
	style.GrabRounding = roundness;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = roundness;

	style.AntiAliasedFill = true;
	style.AntiAliasedLines = true;
	style.AntiAliasedLinesUseTex = true;

	colors[ImGuiCol_Text] = ImVec4( 1.00f , 1.00f , 1.00f , 1.00f );
	colors[ImGuiCol_TextDisabled] = ImVec4( 0.50f , 0.50f , 0.50f , 1.00f );

	colors[ImGuiCol_WindowBg] = ImVec4( 0.20f , 0.23f , 0.31f , 1.00f );
	colors[ImGuiCol_ChildBg] = ImVec4( 0.20f , 0.23f , 0.31f , 1.00f );
	colors[ImGuiCol_PopupBg] = ImVec4( 0.20f , 0.23f , 0.31f , 1.00f );

	colors[ImGuiCol_Border] = ImVec4( 0.f , 0.f , 0.f , 1.00f );
	colors[ImGuiCol_BorderShadow] = ImVec4( 0.00f , 0.00f , 0.00f , 0.00f );

	colors[ImGuiCol_FrameBg] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );
	colors[ImGuiCol_FrameBgHovered] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );
	colors[ImGuiCol_FrameBgActive] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );

	colors[ImGuiCol_TitleBg] = ImVec4( 0.00f , 0.43f , 1.00f , 1.00f );
	colors[ImGuiCol_TitleBgActive] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4( 0.10f , 0.69f , 1.00f , 1.00f );

	colors[ImGuiCol_MenuBarBg] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );

	colors[ImGuiCol_ScrollbarBg] = ImVec4( 0.00f , 0.00f , 0.00f , 0.00f );
	colors[ImGuiCol_ScrollbarGrab] = ImVec4( 0.39f , 0.44f , 0.56f , 1.00f );
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.12f , 0.43f , 1.00f , 1.00f );
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );

	colors[ImGuiCol_CheckMark] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );

	colors[ImGuiCol_SliderGrab] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );
	colors[ImGuiCol_SliderGrabActive] = ImVec4( 0.10f , 0.69f , 1.00f , 1.00f );

	colors[ImGuiCol_Button] = ImVec4( 0.25f , 0.28f , 0.38f , 1.00f );
	colors[ImGuiCol_ButtonHovered] = ImVec4( 0.12f , 0.43f , 1.00f , 1.00f );
	colors[ImGuiCol_ButtonActive] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );

	colors[ImGuiCol_Header] = ImVec4( 0.00f , 0.43f , 1.00f , 1.00f );
	colors[ImGuiCol_HeaderHovered] = ImVec4( 0.00f , 0.55f , 1.00f , 1.00f );
	colors[ImGuiCol_HeaderActive] = ImVec4( 0.00f , 0.43f , 1.00f , 1.00f );

	colors[ImGuiCol_Separator] = ImVec4( 0.43f , 0.43f , 0.50f , 0.50f );
	colors[ImGuiCol_SeparatorHovered] = ImVec4( 0.10f , 0.40f , 0.75f , 0.78f );
	colors[ImGuiCol_SeparatorActive] = ImVec4( 0.10f , 0.40f , 0.75f , 1.00f );

	colors[ImGuiCol_ResizeGrip] = ImVec4( 0.26f , 0.59f , 0.98f , 0.25f );
	colors[ImGuiCol_ResizeGripHovered] = ImVec4( 0.26f , 0.59f , 0.98f , 0.67f );
	colors[ImGuiCol_ResizeGripActive] = ImVec4( 0.26f , 0.59f , 0.98f , 0.95f );

	colors[ImGuiCol_Tab] = ImVec4( 0.00f , 0.50f , 1.00f , 1.00f );
	colors[ImGuiCol_TabHovered] = ImVec4( 0.12f , 0.69f , 1.00f , 1.00f );

	colors[ImGuiCol_TabActive] = ImVec4( 0.12f , 0.69f , 1.00f , 1.00f );
	colors[ImGuiCol_TabUnfocused] = ImVec4( 0.07f , 0.10f , 0.15f , 0.97f );
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4( 0.14f , 0.26f , 0.42f , 1.00f );

	colors[ImGuiCol_PlotLines] = ImVec4( 0.61f , 0.61f , 0.61f , 1.00f );
	colors[ImGuiCol_PlotLinesHovered] = ImVec4( 1.00f , 0.43f , 0.35f , 1.00f );
	colors[ImGuiCol_PlotHistogram] = ImVec4( 0.10f , 0.69f , 1.00f , 1.00f );
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4( 1.00f , 0.60f , 0.00f , 1.00f );

	colors[ImGuiCol_TextSelectedBg] = ImVec4( 0.26f , 0.59f , 0.98f , 0.35f );
	colors[ImGuiCol_DragDropTarget] = ImVec4( 1.00f , 1.00f , 0.00f , 0.90f );

	colors[ImGuiCol_NavHighlight] = ImVec4( 0.26f , 0.59f , 0.98f , 1.00f );
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4( 1.00f , 1.00f , 1.00f , 0.70f );
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4( 0.80f , 0.80f , 0.80f , 0.20f );

	colors[ImGuiCol_ModalWindowDimBg] = ImVec4( 0.80f , 0.80f , 0.80f , 0.35f );
	colors[ImGuiCol_WindowShadow] = ImVec4( 0.f , 0.f , 1.f , 1.f );
}

auto CAndromedaGUI::InitVermillionStyle() -> void
{
	auto& style = ImGui::GetStyle();
	auto& colors = style.Colors;

	float roundness = 2.0f;

	style.WindowBorderSize = 1.0f;
	style.FrameBorderSize = 1.0f;
	style.WindowMinSize = ImVec2( 75.f , 50.f );
	style.FramePadding = ImVec2( 5 , 5 );
	style.ItemSpacing = ImVec2( 6 , 5 );
	style.ItemInnerSpacing = ImVec2( 2 , 4 );
	style.Alpha = 1.0f;
	style.WindowRounding = 0.f;
	style.FrameRounding = roundness;
	style.PopupRounding = 0;
	style.PopupBorderSize = 1.f;
	style.IndentSpacing = 6.0f;
	style.ColumnsMinSpacing = 50.0f;
	style.GrabMinSize = 14.0f;
	style.GrabRounding = roundness;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = roundness;

	style.AntiAliasedFill = true;
	style.AntiAliasedLines = true;
	style.AntiAliasedLinesUseTex = true;

	colors[ImGuiCol_Text] = ImVec4( 1.00f , 1.00f , 1.00f , 0.75f );
	colors[ImGuiCol_TextDisabled] = ImVec4( 1.00f , 0.18f , 0.29f , 0.78f );

	colors[ImGuiCol_WindowBg] = ImVec4( 0.17f , 0.20f , 0.25f , 1.00f );
	colors[ImGuiCol_ChildBg] = ImVec4( 0.20f , 0.22f , 0.27f , 0.57f );
	colors[ImGuiCol_PopupBg] = ImVec4( 0.17f , 0.20f , 0.25f , 1.00f );

	colors[ImGuiCol_Border] = ImVec4( 0.00f , 0.00f , 0.00f , 1.00f );
	colors[ImGuiCol_BorderShadow] = ImVec4( 0.00f , 0.00f , 0.00f , 0.00f );

	colors[ImGuiCol_FrameBg] = ImVec4( 0.37f , 0.36f , 0.46f , 0.24f );
	colors[ImGuiCol_FrameBgHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.78f );
	colors[ImGuiCol_FrameBgActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_TitleBg] = ImVec4( 0.20f , 0.22f , 0.27f , 1.00f );
	colors[ImGuiCol_TitleBgActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4( 0.20f , 0.22f , 0.27f , 0.75f );

	colors[ImGuiCol_MenuBarBg] = ImVec4( 0.20f , 0.22f , 0.27f , 0.47f );

	colors[ImGuiCol_ScrollbarBg] = ImVec4( 0.20f , 0.22f , 0.27f , 1.00f );
	colors[ImGuiCol_ScrollbarGrab] = ImVec4( 0.09f , 0.15f , 0.16f , 1.00f );
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.78f );
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_CheckMark] = ImVec4( 0.71f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_SliderGrab] = ImVec4( 0.78f , 0.18f , 0.29f , 0.37f );
	colors[ImGuiCol_SliderGrabActive] = ImVec4( 0.92f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_Button] = ImVec4( 0.65f , 0.18f , 0.29f , 1.00f );
	colors[ImGuiCol_ButtonHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.86f );
	colors[ImGuiCol_ButtonActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_Header] = ImVec4( 0.78f , 0.18f , 0.29f , 0.76f );
	colors[ImGuiCol_HeaderHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.86f );
	colors[ImGuiCol_HeaderActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_Separator] = ImVec4( 0.15f , 0.00f , 0.00f , 0.35f );
	colors[ImGuiCol_SeparatorHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.59f );
	colors[ImGuiCol_SeparatorActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_ResizeGrip] = ImVec4( 0.78f , 0.18f , 0.29f , 0.63f );
	colors[ImGuiCol_ResizeGripHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.78f );
	colors[ImGuiCol_ResizeGripActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_Tab] = ImVec4( 0.78f , 0.18f , 0.29f , 0.76f );
	colors[ImGuiCol_TabHovered] = ImVec4( 0.78f , 0.18f , 0.29f , 0.86f );
	colors[ImGuiCol_TabActive] = ImVec4( 0.78f , 0.18f , 0.29f , 1.00f );
	colors[ImGuiCol_TabUnfocused] = ImVec4( 0.07f , 0.10f , 0.15f , 0.97f );
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4( 0.14f , 0.26f , 0.42f , 1.00f );

	colors[ImGuiCol_PlotLines] = ImVec4( 0.78f , 0.93f , 0.89f , 0.63f );
	colors[ImGuiCol_PlotLinesHovered] = ImVec4( 0.92f , 0.18f , 0.29f , 1.00f );
	colors[ImGuiCol_PlotHistogram] = ImVec4( 0.86f , 0.93f , 0.89f , 0.63f );
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4( 0.92f , 0.18f , 0.29f , 1.00f );

	colors[ImGuiCol_TextSelectedBg] = ImVec4( 0.92f , 0.18f , 0.29f , 0.43f );
	colors[ImGuiCol_DragDropTarget] = ImVec4( 1.00f , 1.00f , 0.00f , 0.90f );

	colors[ImGuiCol_NavHighlight] = ImVec4( 0.45f , 0.45f , 0.90f , 0.80f );
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4( 1.00f , 1.00f , 1.00f , 0.70f );
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4( 0.80f , 0.80f , 0.80f , 0.20f );

	colors[ImGuiCol_ModalWindowDimBg] = ImVec4( 0.80f , 0.80f , 0.80f , 0.35f );
	colors[ImGuiCol_WindowShadow] = ImVec4( 1.f , 0.f , 0.f , 1.f );
}

auto CAndromedaGUI::UpdateStyle() -> void
{
	if ( Settings::Misc::MenuStyle == EAndromedaGuiStyle::INDIGO )
		InitIndigoStyle();
	else if ( Settings::Misc::MenuStyle == EAndromedaGuiStyle::VERMILLION )
		InitVermillionStyle();
}

void CAndromedaGUI::OnPresent( IDXGISwapChain* pSwapChain )
{
	if ( !m_bInit )
		OnInit( pSwapChain );
	else
		OnRender( pSwapChain );
}

void CAndromedaGUI::OnResizeBuffers( IDXGISwapChain* pSwapChain )
{
	OnDestroy();
}

void CAndromedaGUI::OnRender( IDXGISwapChain* pSwapChain )
{
	if ( m_pFreeType_Font && m_pFreeType_Font->PreNewFrame() )
	{
		ImGui_ImplDX11_InvalidateDeviceObjects();
		ImGui_ImplDX11_CreateDeviceObjects();
	}
	else
	{
		if ( !m_pRenderTargetView )
		{
			ID3D11Texture2D* pBackBuffer = nullptr;

			if ( FAILED( pSwapChain->GetBuffer( 0 , IID_PPV_ARGS( &pBackBuffer ) ) ) )
			{
				DEV_LOG( "[error] CAndromedaGUI::OnRender: #1\n" );
				return;
			}

			D3D11_RENDER_TARGET_VIEW_DESC RenderTargetDesc;

			memset( &RenderTargetDesc , 0 , sizeof( RenderTargetDesc ) );

			RenderTargetDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			RenderTargetDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2DMS;

			if ( pBackBuffer )
			{
				m_pDevice->CreateRenderTargetView( pBackBuffer , &RenderTargetDesc , &m_pRenderTargetView );
				pBackBuffer->Release();
			}
		}

		ImGui::SetCurrentContext( m_pImGuiContext );

		m_pDeviceContext->OMGetRenderTargets( 1 , &m_pMainRenderTarget , 0 );
		m_pDeviceContext->OMSetRenderTargets( 1 , &m_pRenderTargetView , 0 );

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();

		GetAndromedaClient()->OnRender();

		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData() );

		m_pDeviceContext->OMSetRenderTargets( 1 , &m_pMainRenderTarget , 0 );
	}
}

auto CAndromedaGUI::OnReopenGUI() -> void
{
	m_bVisible = !m_bVisible;

	ImGui::GetIO().MouseDrawCursor = m_bVisible;
	ShowCursor( !m_bVisible );

	IsRelativeMouseMode_o( SDK::Interfaces::InputSystem() , m_bVisible ? false : m_bMainActive );

	if ( m_bVisible )
	{
		if ( m_vecMousePosSave.x == 0.f && m_vecMousePosSave.y == 0.f )
			m_vecMousePosSave = ImGui::GetIO().DisplaySize / 2.f;

		ImGui::GetIO().MousePos = m_vecMousePosSave;

		if ( SDK::Interfaces::EngineToClient()->IsInGame() )
			GetSDL3Functions()->SDL_WarpMouseInWindow_o( nullptr , ImGui::GetIO().MousePos.x , ImGui::GetIO().MousePos.y );
	}
	else
	{
		m_vecMousePosSave = ImGui::GetIO().MousePos;
	}
}

LRESULT WINAPI CAndromedaGUI::GUI_WndProc( HWND hwnd , UINT uMsg , WPARAM wParam , LPARAM lParam )
{
	if ( uMsg == WM_QUIT || uMsg == WM_CLOSE || uMsg == WM_DESTROY )
	{
		GetDllLauncher()->OnDestroy();
		return true;
	}

	if ( GetAndromedaGUI()->m_bInit )
	{
		if ( uMsg == WM_KEYUP && wParam == VK_INSERT )
			GetAndromedaGUI()->OnReopenGUI();

		if ( GetAndromedaGUI()->IsVisible() && ImGui_ImplWin32_WndProcHandler( hwnd , uMsg , wParam , lParam ) == 0 )
			return true;
	}

	return CallWindowProcA( GetAndromedaGUI()->m_WndProc_o , hwnd , uMsg , wParam , lParam );
}

auto CAndromedaGUI::FreeTypeBuild::PreNewFrame() -> bool
{
	if ( !WantRebuild )
		return false;

	ImFontAtlas* atlas = ImGui::GetIO().Fonts;

	for ( int n = 0; n < atlas->ConfigData.Size; n++ )
		( (ImFontConfig*)&atlas->ConfigData[n] )->RasterizerMultiply = RasterizerMultiply;

#ifdef IMGUI_ENABLE_FREETYPE
	if ( BuildMode == FontBuildMode::FreeType )
	{
		atlas->FontBuilderIO = ImGuiFreeType::GetBuilderForFreeType();
		atlas->FontBuilderFlags = FreeTypeBuilderFlags;
	}
#endif

	atlas->Build();
	WantRebuild = false;

	return true;
}

auto CAndromedaGUI::ClearRenderTargetView() -> void
{
	if ( m_pRenderTargetView )
	{
		m_pRenderTargetView->Release();
		m_pRenderTargetView = nullptr;
	}
}

auto GetAndromedaGUI() -> CAndromedaGUI*
{
	return &g_CAndromedaGUI;
}
