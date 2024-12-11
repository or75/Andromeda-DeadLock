#include "CVisual.hpp"

#include <algorithm>

#include <DeadLock/SDK/SDK.hpp>
#include <DeadLock/SDK/Math/Math.hpp>
#include <DeadLock/SDK/Types/CEntityData.hpp>

#include <DeadLock/SDK/Interface/CGameEntitySystem.hpp>
#include <DeadLock/SDK/Interface/IEngineToClient.hpp>

#include <GameClient/CEntityCache/CEntityCache.hpp>
#include <GameClient/CL_CitadelPlayerController.hpp>

#include <AndromedaClient/Settings/Settings.hpp>
#include <AndromedaClient/Render/CRenderStackSystem.hpp>

static CVisual g_CVisual{};

auto CVisual::OnRender() -> void
{
	if ( !Settings::Visual::Active )
		return;

	const auto Lock = GetEntityCache()->GetLock();
	const auto CachedVec = GetEntityCache()->GetCachedEntity();

	Lock->lock();

	for ( const auto& CachedEntity : *CachedVec )
	{
		auto pEntity = CachedEntity.m_Handle.Get();

		if ( !pEntity )
			continue;

		auto hEntity = pEntity->pEntityIdentity()->Handle();

		if ( hEntity != CachedEntity.m_Handle )
			continue;

		switch ( CachedEntity.m_Type )
		{
			case CachedEntity_t::CITADEL_PLAYER_CONTROLLER:
			{
				auto* pCCitadelPlayerController = reinterpret_cast<CCitadelPlayerController*>( pEntity );

				if ( pCCitadelPlayerController != GetCL_CitadelPlayerController()->GetLocal() )
				{
					DEV_LOG( "m_pGameSceneNode: %p\n" , pCCitadelPlayerController->m_hHeroPawn().Get()->m_pGameSceneNode() );

					//Rect_t Box;
					//OnRenderPlayerEsp( pCCitadelPlayerController , Box );
				}
			}
			break;
		}
	}

	Lock->unlock();

	if ( Settings::Visual::SoundStepEsp )
		OnRenderSound();
}

auto CVisual::OnStartSound( const Vector3& Pos , const int SourceEntityIndex , const char* szSoundName ) -> void
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

auto CVisual::OnClientOutput() -> void
{
	OnRender();
}

auto CVisual::OnRenderSound() -> void
{
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

			GetRenderStackSystem()->DrawCircle3D( Sound.Pos , Radius , ImColor( 1.f , 1.f , 0.f , Alpha ) );
		}
	}
}

auto CVisual::OnRenderPlayerEsp( CCitadelPlayerController* pCCitadelPlayerController , const Rect_t& Box ) -> void
{
	if ( !pCCitadelPlayerController->m_PlayerDataGlobal().m_bAlive() )
		return;

	const ImVec2 min = { Box.x, Box.y };
	const ImVec2 max = { Box.w, Box.h };

	auto PlayerColor = ImColor( 255 , 255 , 255 );

	if ( pCCitadelPlayerController->m_iTeamNum() == TEAM_DIER )
	{
		PlayerColor = ImColor( 255 , 0 , 0 );
	}
	else if ( pCCitadelPlayerController->m_iTeamNum() == TEAM_RADIANT )
	{
		PlayerColor = ImColor( 0 , 0 , 255 );
	}

	GetRenderStackSystem()->DrawOutlineCoalBox( min , max , PlayerColor );
}

auto GetVisual() -> CVisual*
{
	return &g_CVisual;
}
