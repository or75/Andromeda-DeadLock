#include "CAndromedaClient.hpp"
#include "CAndromedaGUI.hpp"

#include <ImGui/imgui.h>

#include <DeadLock/SDK/Interface/IGameEvent.hpp>

static CAndromedaClient g_CAndromedaClient{};

auto CAndromedaClient::OnInit() -> void
{

}

auto CAndromedaClient::OnFireEventClientSide( IGameEvent* pGameEvent ) -> void
{
	DEV_LOG( "OnFireEventClientSide: %s\n", pGameEvent->GetName() );
}

auto CAndromedaClient::OnRenderMenu() -> void
{
	if ( GetAndromedaGUI()->IsVisible() )
	{
		ImGui::SetNextWindowSize( ImVec2( 460.f , 490.f ) , ImGuiCond_FirstUseEver );

		if ( ImGui::Begin( XorStr( CHEAT_NAME ) , 0 , ImGuiWindowFlags_NoResize ) )
		{

		}

		ImGui::End();
	}
}

auto GetAndromedaClient() -> CAndromedaClient*
{
	return &g_CAndromedaClient;
}
