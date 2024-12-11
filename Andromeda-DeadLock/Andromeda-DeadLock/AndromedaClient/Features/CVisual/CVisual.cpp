#include "CVisual.hpp"

#include <algorithm>

#include <DeadLock/SDK/SDK.hpp>
#include <DeadLock/SDK/Math/Math.hpp>
#include <DeadLock/SDK/Types/CEntityData.hpp>
#include <DeadLock/SDK/Interface/CGameEntitySystem.hpp>

#include <GameClient/CL_CitadelPlayerController.hpp>

#include <AndromedaClient/Settings/Settings.hpp>
#include <AndromedaClient/Render/CRenderStackSystem.hpp>

static CVisual g_CVisual{};

auto CVisual::OnRender() -> void
{
	if ( !Settings::Visual::Active )
		return;

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

auto GetVisual() -> CVisual*
{
	return &g_CVisual;
}
