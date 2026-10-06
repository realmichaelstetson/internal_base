#include "menu.h"

#include <imgui.h>
#include <Windows.h>
#include <cstdio>

#include "../core/config.h"
#include "../core/hooks.h"
#include "../features/chams.h"
#include "../sdk/globals.h"

// shadcn/ui (zinc, dark) look. Widgets themselves (switch, slider, select) are restyled in ext/imgui/imgui_widgets.cpp.
namespace
{
	namespace col
	{
		constexpr ImVec4 rgb( int hex, float a = 1.f )
		{
			return { ( ( hex >> 16 ) & 0xFF ) / 255.f, ( ( hex >> 8 ) & 0xFF ) / 255.f, ( hex & 0xFF ) / 255.f, a };
		}

		constexpr ImVec4 background = rgb( 0x09090B );
		constexpr ImVec4 sidebar = rgb( 0x0F0F12 );
		constexpr ImVec4 card = rgb( 0x0C0C0E );
		constexpr ImVec4 muted = rgb( 0x27272A );
		constexpr ImVec4 mutedHover = rgb( 0x3F3F46 );
		constexpr ImVec4 border = rgb( 0x27272A );
		constexpr ImVec4 foreground = rgb( 0xFAFAFA );
		constexpr ImVec4 mutedText = rgb( 0xA1A1AA );
		constexpr ImVec4 ring = rgb( 0x52525B );
		constexpr ImVec4 destructive = rgb( 0x7F1D1D );
		constexpr ImVec4 destructiveHover = rgb( 0x991B1B );
		constexpr ImVec4 success = rgb( 0x22C55E );
		constexpr ImVec4 danger = rgb( 0xEF4444 );
	}

	ImFont* fontRegular = nullptr;
	ImFont* fontSemibold = nullptr;
	ImFont* fontTitle = nullptr;
	ImFont* fontSmall = nullptr;

	enum class Page
	{
		Chams,
		Bunnyhop,
		Settings,
	};

	Page page = Page::Chams;
	int chamsTarget = config::chams::Enemies;

	ImFont* loadFont( const char* file, float size )
	{
		char path[ MAX_PATH ];
		GetWindowsDirectoryA( path, MAX_PATH );
		strcat_s( path, "\\Fonts\\" );
		strcat_s( path, file );

		if ( GetFileAttributesA( path ) == INVALID_FILE_ATTRIBUTES )
			return nullptr;

		ImFontConfig cfg;
		cfg.OversampleH = 2;
		cfg.PixelSnapH = true;
		return ImGui::GetIO( ).Fonts->AddFontFromFileTTF( path, size, &cfg );
	}

	void applyTheme( )
	{
		ImGuiStyle& style = ImGui::GetStyle( );
		style.WindowPadding = { 0.f, 0.f };
		style.FramePadding = { 10.f, 6.f };
		style.ItemSpacing = { 8.f, 12.f };
		style.ItemInnerSpacing = { 8.f, 8.f };
		style.ScrollbarSize = 8.f;
		style.GrabMinSize = 17.f;

		style.WindowRounding = 10.f;
		style.ChildRounding = 8.f;
		style.FrameRounding = 6.f;
		style.PopupRounding = 8.f;
		style.GrabRounding = 99.f;
		style.ScrollbarRounding = 99.f;

		style.WindowBorderSize = 1.f;
		style.ChildBorderSize = 1.f;
		style.PopupBorderSize = 1.f;
		style.FrameBorderSize = 0.f;
		style.SelectableTextAlign = { 0.f, 0.5f };

		ImVec4* c = style.Colors;
		c[ ImGuiCol_Text ] = col::foreground;
		c[ ImGuiCol_TextDisabled ] = col::mutedText;
		c[ ImGuiCol_WindowBg ] = col::background;
		c[ ImGuiCol_ChildBg ] = { 0.f, 0.f, 0.f, 0.f };
		c[ ImGuiCol_PopupBg ] = col::background;
		c[ ImGuiCol_Border ] = col::border;
		c[ ImGuiCol_BorderShadow ] = { 0.f, 0.f, 0.f, 0.f };
		c[ ImGuiCol_FrameBg ] = col::muted;
		c[ ImGuiCol_FrameBgHovered ] = col::mutedHover;
		c[ ImGuiCol_FrameBgActive ] = col::mutedHover;
		c[ ImGuiCol_CheckMark ] = col::foreground;
		c[ ImGuiCol_SliderGrab ] = col::foreground;
		c[ ImGuiCol_SliderGrabActive ] = col::rgb( 0xFFFFFF );
		c[ ImGuiCol_Button ] = col::muted;
		c[ ImGuiCol_ButtonHovered ] = col::mutedHover;
		c[ ImGuiCol_ButtonActive ] = col::ring;
		c[ ImGuiCol_Header ] = col::muted;
		c[ ImGuiCol_HeaderHovered ] = col::muted;
		c[ ImGuiCol_HeaderActive ] = col::mutedHover;
		c[ ImGuiCol_Separator ] = col::border;
		c[ ImGuiCol_ScrollbarBg ] = { 0.f, 0.f, 0.f, 0.f };
		c[ ImGuiCol_ScrollbarGrab ] = col::muted;
		c[ ImGuiCol_ScrollbarGrabHovered ] = col::mutedHover;
		c[ ImGuiCol_ScrollbarGrabActive ] = col::ring;
		c[ ImGuiCol_NavCursor ] = col::ring;
		c[ ImGuiCol_TitleBg ] = col::background;
		c[ ImGuiCol_TitleBgActive ] = col::background;
	}

	// smooth 0..1 animation keyed by an ImGui id
	float animate( ImGuiID id, float target, float speed = 14.f )
	{
		ImGuiStorage* storage = ImGui::GetStateStorage( );
		float* value = storage->GetFloatRef( id, target );
		*value += ( target - *value ) * ( ImGui::GetIO( ).DeltaTime * speed > 1.f ? 1.f : ImGui::GetIO( ).DeltaTime * speed );
		return *value;
	}

	void textMuted( const char* text )
	{
		ImGui::PushStyleColor( ImGuiCol_Text, col::mutedText );
		ImGui::TextWrapped( "%s", text );
		ImGui::PopStyleColor( );
	}

	// shadcn <Badge variant="outline">
	void badge( const char* text, ImVec4 dot = { 0.f, 0.f, 0.f, 0.f } )
	{
		ImGui::PushFont( fontSmall );
		ImDrawList* draw = ImGui::GetWindowDrawList( );
		const ImVec2 textSize = ImGui::CalcTextSize( text );
		const float dotSpace = dot.w > 0.f ? 12.f : 0.f;
		const ImVec2 pos = ImGui::GetCursorScreenPos( );
		const ImVec2 size( textSize.x + 16.f + dotSpace, textSize.y + 6.f );

		draw->AddRect( pos, { pos.x + size.x, pos.y + size.y }, ImGui::GetColorU32( col::border ), 99.f );
		if ( dot.w > 0.f )
			draw->AddCircleFilled( { pos.x + 11.f, pos.y + size.y * 0.5f }, 3.f, ImGui::GetColorU32( dot ) );
		draw->AddText( { pos.x + 8.f + dotSpace, pos.y + 3.f }, ImGui::GetColorU32( col::foreground ), text );

		ImGui::Dummy( size );
		ImGui::PopFont( );
	}

	// shadcn <Kbd>
	void kbd( const char* key )
	{
		ImGui::PushFont( fontSmall );
		ImDrawList* draw = ImGui::GetWindowDrawList( );
		const ImVec2 textSize = ImGui::CalcTextSize( key );
		const ImVec2 pos = ImGui::GetCursorScreenPos( );
		const ImVec2 size( textSize.x + 12.f, textSize.y + 6.f );
		draw->AddRectFilled( pos, { pos.x + size.x, pos.y + size.y }, ImGui::GetColorU32( col::muted ), 4.f );
		draw->AddText( { pos.x + 6.f, pos.y + 3.f }, ImGui::GetColorU32( col::mutedText ), key );
		ImGui::Dummy( size );
		ImGui::PopFont( );
	}

	// shadcn <Card> with a title + description header. Auto-sizes to its content.
	bool beginCard( const char* id, const char* title, const char* description, float width = 0.f )
	{
		ImGui::PushStyleColor( ImGuiCol_ChildBg, col::card );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { 18.f, 16.f } );
		const bool open = ImGui::BeginChild( id, { width, 0.f }, ImGuiChildFlags_Borders | ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_AlwaysUseWindowPadding );
		ImGui::PopStyleVar( );
		ImGui::PopStyleColor( );

		ImGui::PushFont( fontSemibold );
		ImGui::TextUnformatted( title );
		ImGui::PopFont( );
		if ( description )
		{
			ImGui::SetCursorPosY( ImGui::GetCursorPosY( ) - 8.f );
			textMuted( description );
		}
		ImGui::Spacing( );
		return open;
	}

	void endCard( )
	{
		ImGui::EndChild( );
	}

	// label on the left, colour swatch on the right, popover with the picker
	void colorRow( const char* label, float* color )
	{
		ImGui::PushID( label );
		const float rowHeight = ImGui::GetFrameHeight( );
		const ImVec2 start = ImGui::GetCursorPos( );
		const float width = ImGui::GetContentRegionAvail( ).x;

		ImGui::AlignTextToFramePadding( );
		ImGui::TextUnformatted( label );

		ImGui::SetCursorPos( { start.x + width - 44.f, start.y } );
		const ImVec4 value( color[ 0 ], color[ 1 ], color[ 2 ], color[ 3 ] );
		ImGui::PushStyleVar( ImGuiStyleVar_FrameBorderSize, 1.f );
		if ( ImGui::ColorButton( "##swatch", value, ImGuiColorEditFlags_AlphaPreviewHalf, { 44.f, rowHeight } ) )
			ImGui::OpenPopup( "##picker" );
		ImGui::PopStyleVar( );

		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { 12.f, 12.f } );
		if ( ImGui::BeginPopup( "##picker" ) )
		{
			ImGui::SetNextItemWidth( 200.f );
			ImGui::ColorPicker4( "##picker4", color, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_DisplayHex );
			ImGui::EndPopup( );
		}
		ImGui::PopStyleVar( );
		ImGui::PopID( );
	}

	bool combo( const char* label, int* current, const char* const items[ ], int count )
	{
		bool changed = false;
		ImGui::SetNextItemWidth( 170.f );
		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { 4.f, 4.f } );
		const bool open = ImGui::BeginCombo( label, items[ *current ] );
		ImGui::PopStyleVar( );
		if ( open )
		{
			ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing, { 0.f, 2.f } );
			for ( int i = 0; i < count; ++i )
			{
				const bool selected = i == *current;
				if ( ImGui::Selectable( items[ i ], selected, 0, { 0.f, ImGui::GetFrameHeight( ) - 4.f } ) )
				{
					*current = i;
					changed = true;
				}
				if ( selected )
					ImGui::SetItemDefaultFocus( );
			}
			ImGui::PopStyleVar( );
			ImGui::EndCombo( );
		}
		return changed;
	}

	// shadcn <Tabs> - segmented control with a sliding active indicator
	void tabs( const char* id, int* current, const char* const items[ ], int count )
	{
		ImGui::PushID( id );
		ImDrawList* draw = ImGui::GetWindowDrawList( );
		const ImVec2 pos = ImGui::GetCursorScreenPos( );
		const float width = ImGui::GetContentRegionAvail( ).x;
		const float height = ImGui::GetFrameHeight( ) + 6.f;
		const float segment = ( width - 6.f ) / count;

		draw->AddRectFilled( pos, { pos.x + width, pos.y + height }, ImGui::GetColorU32( col::muted ), 8.f );

		const float x = animate( ImGui::GetID( "##indicator" ), static_cast< float >( *current ), 16.f );
		const ImVec2 indicatorMin( pos.x + 3.f + segment * x, pos.y + 3.f );
		draw->AddRectFilled( indicatorMin, { indicatorMin.x + segment, pos.y + height - 3.f }, ImGui::GetColorU32( col::background ), 6.f );

		for ( int i = 0; i < count; ++i )
		{
			const ImVec2 segMin( pos.x + 3.f + segment * i, pos.y + 3.f );
			ImGui::SetCursorScreenPos( segMin );
			ImGui::PushID( i );
			if ( ImGui::InvisibleButton( "##tab", { segment, height - 6.f } ) )
				*current = i;
			const bool hovered = ImGui::IsItemHovered( );
			ImGui::PopID( );

			const ImVec2 textSize = ImGui::CalcTextSize( items[ i ] );
			const ImVec4 textCol = ( i == *current || hovered ) ? col::foreground : col::mutedText;
			draw->AddText( { segMin.x + ( segment - textSize.x ) * 0.5f, segMin.y + ( height - 6.f - textSize.y ) * 0.5f }, ImGui::GetColorU32( textCol ), items[ i ] );
		}

		ImGui::SetCursorScreenPos( { pos.x, pos.y + height } );
		ImGui::Dummy( { width, 0.f } );
		ImGui::PopID( );
	}

	bool button( const char* label, ImVec2 size, bool destructive = false )
	{
		if ( destructive )
		{
			ImGui::PushStyleColor( ImGuiCol_Button, col::destructive );
			ImGui::PushStyleColor( ImGuiCol_ButtonHovered, col::destructiveHover );
			ImGui::PushStyleColor( ImGuiCol_ButtonActive, col::destructiveHover );
		}
		const bool pressed = ImGui::Button( label, size );
		if ( destructive )
			ImGui::PopStyleColor( 3 );
		return pressed;
	}

	// ---------------------------------------------------------------- sidebar

	void sidebarSection( const char* title )
	{
		ImGui::PushFont( fontSmall );
		ImGui::SetCursorPosX( 20.f );
		ImGui::PushStyleColor( ImGuiCol_Text, col::mutedText );
		ImGui::TextUnformatted( title );
		ImGui::PopStyleColor( );
		ImGui::PopFont( );
		ImGui::SetCursorPosY( ImGui::GetCursorPosY( ) - 6.f );
	}

	void sidebarItem( const char* label, Page target )
	{
		const bool active = page == target;
		const ImVec2 pos = ImGui::GetCursorScreenPos( );
		const float width = ImGui::GetContentRegionAvail( ).x - 24.f;
		const float height = 32.f;
		const ImVec2 min( pos.x + 12.f, pos.y );
		const ImVec2 max( min.x + width, min.y + height );

		ImGui::SetCursorScreenPos( min );
		if ( ImGui::InvisibleButton( label, { width, height } ) )
			page = target;
		const bool hovered = ImGui::IsItemHovered( );

		const float t = animate( ImGui::GetID( label ), active ? 1.f : ( hovered ? 0.5f : 0.f ) );
		ImDrawList* draw = ImGui::GetWindowDrawList( );
		if ( t > 0.01f )
			draw->AddRectFilled( min, max, ImGui::GetColorU32( ImVec4( col::muted.x, col::muted.y, col::muted.z, t ) ), 6.f );
		if ( active )
			draw->AddRectFilled( { min.x, min.y + 8.f }, { min.x + 3.f, max.y - 8.f }, ImGui::GetColorU32( col::foreground ), 2.f );

		const ImVec2 textSize = ImGui::CalcTextSize( label );
		draw->AddText( { min.x + 14.f, min.y + ( height - textSize.y ) * 0.5f }, ImGui::GetColorU32( active || hovered ? col::foreground : col::mutedText ), label );

		ImGui::SetCursorPosY( ImGui::GetCursorPosY( ) - 8.f );
	}

	void sidebar( )
	{
		ImGui::PushStyleColor( ImGuiCol_ChildBg, col::sidebar );
		ImGui::BeginChild( "##sidebar", { 200.f, 0.f } );
		ImGui::PopStyleColor( );

		// brand
		ImGui::SetCursorPos( { 20.f, 20.f } );
		ImDrawList* draw = ImGui::GetWindowDrawList( );
		const ImVec2 logo = ImGui::GetCursorScreenPos( );
		draw->AddRectFilled( logo, { logo.x + 32.f, logo.y + 32.f }, ImGui::GetColorU32( col::foreground ), 8.f );
		ImGui::PushFont( fontSemibold );
		const ImVec2 glyph = ImGui::CalcTextSize( "C2" );
		draw->AddText( { logo.x + ( 32.f - glyph.x ) * 0.5f, logo.y + ( 32.f - glyph.y ) * 0.5f }, ImGui::GetColorU32( col::background ), "C2" );
		ImGui::SetCursorPos( { 62.f, 18.f } );
		ImGui::TextUnformatted( "cs2 internal" );
		ImGui::PopFont( );
		ImGui::PushFont( fontSmall );
		ImGui::SetCursorPos( { 62.f, 38.f } );
		ImGui::TextColored( col::mutedText, "build 14189" );
		ImGui::PopFont( );

		ImGui::SetCursorPosY( 76.f );
		sidebarSection( "VISUALS" );
		sidebarItem( "Chams", Page::Chams );
		ImGui::Dummy( { 0.f, 4.f } );
		sidebarSection( "MOVEMENT" );
		sidebarItem( "Bunnyhop", Page::Bunnyhop );
		ImGui::Dummy( { 0.f, 4.f } );
		sidebarSection( "OTHER" );
		sidebarItem( "Settings", Page::Settings );

		// footer
		const float footerY = ImGui::GetWindowHeight( ) - 44.f;
		draw->AddLine( { ImGui::GetWindowPos( ).x, ImGui::GetWindowPos( ).y + footerY - 12.f }, { ImGui::GetWindowPos( ).x + 200.f, ImGui::GetWindowPos( ).y + footerY - 12.f }, ImGui::GetColorU32( col::border ) );
		ImGui::SetCursorPos( { 20.f, footerY } );
		kbd( "INSERT" );
		ImGui::SameLine( 0.f, 6.f );
		ImGui::PushFont( fontSmall );
		ImGui::SetCursorPosY( footerY + 3.f );
		ImGui::TextColored( col::mutedText, "toggle menu" );
		ImGui::PopFont( );

		ImGui::EndChild( );

		// sidebar right border
		const ImVec2 min = ImGui::GetItemRectMin( );
		const ImVec2 max = ImGui::GetItemRectMax( );
		ImGui::GetWindowDrawList( )->AddLine( { max.x, min.y }, { max.x, max.y }, ImGui::GetColorU32( col::border ) );
	}

	// ---------------------------------------------------------------- pages

	void pageHeader( const char* title, const char* description )
	{
		ImGui::PushFont( fontTitle );
		ImGui::TextUnformatted( title );
		ImGui::PopFont( );
		ImGui::SetCursorPosY( ImGui::GetCursorPosY( ) - 8.f );
		textMuted( description );
		ImGui::Spacing( );
	}

	void layerCard( const char* id, const char* title, const char* description, config::chams::Layer& layer, float width, bool* throughWalls = nullptr )
	{
		ImGui::PushID( id );
		beginCard( id, title, description, width );

		ImGui::Checkbox( "Enabled", &layer.enabled );
		ImGui::BeginDisabled( !layer.enabled );
		combo( "Material", &layer.material, config::chams::materialNames, config::chams::MaterialCount );
		colorRow( "Color", layer.color );
		ImGui::Checkbox( "Rainbow", &layer.rainbow );
		ImGui::Checkbox( "Pulse", &layer.pulse );
		if ( throughWalls )
			ImGui::Checkbox( "Through walls", throughWalls );
		ImGui::EndDisabled( );

		endCard( );
		ImGui::PopID( );
	}

	void chamsPage( )
	{
		using namespace config::chams;
		pageHeader( "Chams", "Override player and weapon materials. Every target has its own visible, through-walls and overlay layer." );

		beginCard( "##chams_general", "General", nullptr );
		{
			const bool ready = features::chams::ready( );
			badge( ready ? "Materials ready" : features::chams::status( ), ready ? col::success : col::danger );
			if ( !hooks::chamsHooked( ) )
			{
				ImGui::SameLine( );
				badge( "Draw hook not found", col::danger );
			}
			ImGui::Checkbox( "Enable chams", &enabled );
		}
		endCard( );

		tabs( "##targets", &chamsTarget, targetNames, TargetCount );

		Group& group = groups[ chamsTarget ];
		ImGui::BeginDisabled( !enabled );

		const float spacing = ImGui::GetStyle( ).ItemSpacing.x;
		const float half = ( ImGui::GetContentRegionAvail( ).x - spacing ) * 0.5f;
		layerCard( "##visible", "Visible", "Drawn where the model can be seen.", group.visible, half );
		ImGui::SameLine( );
		layerCard( "##hidden", "Through walls", "Drawn behind walls (ignore-z).", group.hidden, half );
		layerCard( "##overlay", "Overlay", "Extra pass on top of the model, e.g. a glow rim.", group.overlay, 0.f, &group.overlayThroughWalls );

		ImGui::EndDisabled( );
	}

	void bhopPage( )
	{
		pageHeader( "Bunnyhop", "Automatically jumps the moment you touch the ground while the key is held." );

		struct KeyOption
		{
			const char* name;
			int vk;
		};
		static constexpr KeyOption keys[ ] = {
			{ "Space", VK_SPACE }, { "Mouse 4", VK_XBUTTON1 }, { "Mouse 5", VK_XBUTTON2 }, { "Left Alt", VK_LMENU }, { "C", 'C' },
		};
		static const char* keyNames[ ] = { keys[ 0 ].name, keys[ 1 ].name, keys[ 2 ].name, keys[ 3 ].name, keys[ 4 ].name };

		beginCard( "##bhop", "Settings", "Paused while the menu is open." );

		bool enabled = config::bhop::enabled;
		if ( ImGui::Checkbox( "Enabled", &enabled ) )
			config::bhop::enabled = enabled;

		ImGui::BeginDisabled( !enabled );
		int current = 0;
		for ( int i = 0; i < IM_ARRAYSIZE( keys ); ++i )
			if ( keys[ i ].vk == config::bhop::key )
				current = i;
		if ( combo( "Key", &current, keyNames, IM_ARRAYSIZE( keyNames ) ) )
			config::bhop::key = keys[ current ].vk;

		int delay = config::bhop::releaseDelay;
		if ( ImGui::SliderInt( "Release delay", &delay, 1, 20, "%d ms" ) )
			config::bhop::releaseDelay = delay;
		ImGui::EndDisabled( );

		endCard( );
	}

	void settingsPage( )
	{
		pageHeader( "Settings", "Keybinds and session." );

		beginCard( "##keys", "Keybinds", nullptr );
		auto row = [ ]( const char* action, const char* key )
		{
			const float y = ImGui::GetCursorPosY( );
			ImGui::TextUnformatted( action );
			ImGui::PushFont( fontSmall );
			const float w = ImGui::CalcTextSize( key ).x + 12.f;
			ImGui::PopFont( );
			ImGui::SetCursorPos( { ImGui::GetWindowWidth( ) - 18.f - w, y } );
			kbd( key );
		};
		row( "Toggle menu", "INSERT" );
		row( "Unload", "END" );
		endCard( );

		beginCard( "##danger", "Danger zone", "Removes all hooks and unloads the DLL from the game." );
		if ( button( "Unload", { 140.f, 0.f }, true ) )
			globals::running = false;
		endCard( );
	}
}

void menu::setup( )
{
	ImGuiIO& io = ImGui::GetIO( );
	io.Fonts->Clear( );

	// Segoe UI ships with every Windows install and is close enough to Inter/Geist
	fontRegular = loadFont( "segoeui.ttf", 16.f );
	fontSemibold = loadFont( "seguisb.ttf", 16.f );
	fontTitle = loadFont( "seguisb.ttf", 24.f );
	fontSmall = loadFont( "segoeui.ttf", 13.f );

	if ( !fontRegular )
		fontRegular = io.Fonts->AddFontDefault( );
	if ( !fontSemibold )
		fontSemibold = fontRegular;
	if ( !fontTitle )
		fontTitle = fontSemibold;
	if ( !fontSmall )
		fontSmall = fontRegular;

	io.FontDefault = fontRegular;
	applyTheme( );
}

void menu::render( )
{
	if ( !globals::menuOpen )
		return;

	const ImVec2 display = ImGui::GetIO( ).DisplaySize;
	ImGui::SetNextWindowSize( { 820.f, 560.f }, ImGuiCond_Always );
	ImGui::SetNextWindowPos( { display.x * 0.5f, display.y * 0.5f }, ImGuiCond_Once, { 0.5f, 0.5f } );

	if ( ImGui::Begin( "##cs2internal", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse ) )
	{
		sidebar( );
		ImGui::SameLine( 0.f, 0.f );

		ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, { 24.f, 22.f } );
		ImGui::BeginChild( "##content", { 0.f, 0.f }, ImGuiChildFlags_AlwaysUseWindowPadding );
		ImGui::PopStyleVar( );

		switch ( page )
		{
		case Page::Chams: chamsPage( ); break;
		case Page::Bunnyhop: bhopPage( ); break;
		case Page::Settings: settingsPage( ); break;
		}

		ImGui::EndChild( );
	}
	ImGui::End( );
}
