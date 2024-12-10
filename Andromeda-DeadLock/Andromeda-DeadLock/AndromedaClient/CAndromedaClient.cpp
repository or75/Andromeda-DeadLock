#include "CAndromedaClient.hpp"
#include "CAndromedaGUI.hpp"

#include <ImGui/imgui.h>

#include <DeadLock/SDK/SDK.hpp>
#include <DeadLock/SDK/Math/Math.hpp>

#include <DeadLock/SDK/Interface/IEngineToClient.hpp>
#include <DeadLock/SDK/Interface/CGameEntitySystem.hpp>

#include <DeadLock/SDK/Update/CUserCmd.hpp>

#include <GameClient/CEntityCache/CEntityCache.hpp>
#include <GameClient/CL_CitadelPlayerController.hpp>

#include "Fonts/CFontManager.hpp"
#include "Render/CRenderStackSystem.hpp"

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
	if ( strstr( szSoundName , XorStr( "Footstep" ) ) )
	{
		if ( auto* pBaseEntity = SDK::Interfaces::GameEntitySystem()->GetBaseEntity( SourceEntityIndex ); pBaseEntity )
		{
			if ( auto* pLocalCitadelPlayerController = GetCL_CitadelPlayerController()->GetLocal(); pLocalCitadelPlayerController )
			{
				if ( pLocalCitadelPlayerController->m_iTeamNum() != pBaseEntity->m_iTeamNum() )
				{
					if ( pBaseEntity->IsCitadelPlayerPawn() )
					{
						std::scoped_lock m_Lock( m_SoundLock );

						m_SoundList.emplace_back( GetTickCount64() , Pos );
					}
				}
			}
		}
	}
}

auto CAndromedaClient::OnCreateMove( CCitadelInput* pCitadelInput , CUserCmd* pUserCmd ) -> void
{
	//DEV_LOG( "%s\n" , pUserCmd->cmd.DebugString().c_str() );
}

auto CAndromedaClient::OnClientOutput() -> void
{
	if ( SDK::Interfaces::EngineToClient()->IsInGame() )
	{
		// TODO: Visual Render

		std::scoped_lock m_Lock( m_SoundLock );

		auto NewEnd = std::remove_if( m_SoundList.begin() , m_SoundList.end() , []( const SoundData_t& Sound )
		{
			return GetTickCount64() - Sound.dwTime >= g_SoundShowTime;
		} );

		m_SoundList.erase( NewEnd , m_SoundList.end() );

		for ( const auto& Sound : m_SoundList )
		{
			auto Ratio = static_cast<float>( GetTickCount64() - Sound.dwTime ) / static_cast<float>( g_SoundShowTime );
			auto Alpha = std::lerp( 1.f , 0.f , Ratio );

			ImVec2 Screen;

			if ( Math::WorldToScreen( Sound.Pos , Screen ) )
			{
				constexpr static auto SoundSize = 20.f;
				auto Radius = std::lerp( SoundSize , 0.f , Ratio );

				GetRenderStackSystem()->DrawCircle3D( Sound.Pos , Radius , ImColor( 255 , 255 , 0 ) );
			}
		}
	}
}

auto CAndromedaClient::OnRender() -> void
{
	if ( GetAndromedaGUI()->IsVisible() )
	{
		ImGui::SetNextWindowSize( ImVec2( 460.f , 490.f ) , ImGuiCond_FirstUseEver );

		if ( ImGui::Begin( XorStr( CHEAT_NAME ) , 0 , ImGuiWindowFlags_NoResize ) )
		{

		}

		ImGui::End();
	}

	GetFontManager()->FirstInitFonts();
	GetFontManager()->m_VerdanaFont.DrawString( 1 , 1 , ImColor( 1.f , 1.f , 1.f ) , FW1_LEFT , XorStr( CHEAT_NAME ) );

	GetRenderStackSystem()->OnRenderStack();
}

auto GetAndromedaClient() -> CAndromedaClient*
{
	return &g_CAndromedaClient;
}
