#include "CMisc.hpp"

#include <DeadLock/SDK/SDK.hpp>
#include <DeadLock/SDK/Types/CEntityData.hpp>
#include <DeadLock/SDK/Interface/CGameEntitySystem.hpp>

#include <GameClient/CL_CitadelPlayerPawn.hpp>

#include <AndromedaClient/Settings/Settings.hpp>

static CMisc g_CMisc{};

auto CMisc::OnCreateMove( CCitadelInput* pInput , CUserCmd* pUserCmd ) -> void
{
	auto SetSkyColor = [&]( const Color& Col )
	{
		FOR_EACH_ENTITY( i )
		{
			auto pEntity = SDK::Interfaces::GameEntitySystem()->GetBaseEntity( i );

			if ( pEntity && !strcmp( pEntity->GetSchemaClassBinding()->m_bindingName , XorStr( "C_EnvSky" ) ) )
			{
				auto pC_EnvSky = reinterpret_cast<C_EnvSky*>( pEntity );

				if ( pC_EnvSky->m_vTintColor() != Col && pC_EnvSky->m_vTintColorLightingOnly() != Col )
				{
					pC_EnvSky->m_vTintColor() = Col;
					pC_EnvSky->m_vTintColorLightingOnly() = Col;

					C_EnvSky_Update( pC_EnvSky );
				}
			}
		}
	};

	auto SetNightMode = [&]( const float Min , const float Max , const bool Control )
	{
		auto* pLocalCitadelPlayerPawn = GetCL_CitadelPlayerPawn()->GetLocal();

		if ( pLocalCitadelPlayerPawn )
		{
			auto pCameraService = pLocalCitadelPlayerPawn->m_pCameraServices();

			if ( pCameraService )
			{
				auto pC_PostProcessingVolume = pCameraService->m_hActivePostProcessingVolume().Get<C_PostProcessingVolume>();

				if ( pC_PostProcessingVolume )
				{
					pC_PostProcessingVolume->m_flMinExposure() = Min;
					pC_PostProcessingVolume->m_flMaxExposure() = Max;
					pC_PostProcessingVolume->m_bExposureControl() = Control;
				}
			}
		}
	};

	if ( Settings::Misc::SkyColorChanger )
		SetSkyColor( Color( static_cast<int>( Settings::Colors::Misc::SkyColor[0] * 255.f ) ,
							static_cast<int>( Settings::Colors::Misc::SkyColor[1] * 255.f ) ,
							static_cast<int>( Settings::Colors::Misc::SkyColor[2] * 255.f ) ) );

	if ( Settings::Misc::NightMode )
		SetNightMode( 0.2f , 0.2f , true );
	else
		SetNightMode( 1.0f , 1.0f , false );
}

auto GetMisc() -> CMisc*
{
	return &g_CMisc;
}
