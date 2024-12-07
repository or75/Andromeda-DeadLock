#include "CAndromedaClient.hpp"
#include "CAndromedaGUI.hpp"

#include <ImGui/imgui.h>

#include <DeadLock/SDK/Update/CUserCmd.hpp>
#include <GameClient/CEntityCache/CEntityCache.hpp>

static CAndromedaClient g_CAndromedaClient{};

auto CAndromedaClient::OnInit() -> void
{

}

auto CAndromedaClient::OnFireEventClientSide( IGameEvent* pGameEvent ) -> void
{

}

auto CAndromedaClient::OnAddEntity( CEntityInstance* pInst , CHandle handle ) -> void
{
	GetEntityCache()->OnAddEntity( pInst , handle );
}

auto CAndromedaClient::OnRemoveEntity( CEntityInstance* pInst , CHandle handle ) -> void
{
	GetEntityCache()->OnRemoveEntity( pInst , handle );
}

auto CAndromedaClient::OnStartSound( const Vector3& Pos , const int SourceEntityIndex , const char* szSoundName ) -> void
{
	// Footstep
	DEV_LOG( "%s\n" , szSoundName );
}

auto CAndromedaClient::OnCreateMove( CCitadelInput* pCitadelInput , CUserCmd* pUserCmd ) -> void
{
	DEV_LOG( "%s\n" , pUserCmd->cmd.DebugString().c_str() );
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
