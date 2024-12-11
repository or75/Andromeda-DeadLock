#include "CFunctionList.hpp"

static CFunctionList g_CFunctionList{};

auto CFunctionList::OnInit() -> bool
{
	std::vector<CBasePattern*> vPatterns =
	{
		&CSkeletonInstance_CalcWorldSpaceBones,
		&ScreenTransform,
		&CCitadelInput_GetViewAngles,
		&CCitadelInput_SetViewAngles,
		&C_BaseEntity_ComputeHitboxSurroundingBox,
		&CGameEntitySystem_GetBaseEntity,
		&CGameEntitySystem_GetHighestEntityIndex,
		&CGameEntitySystem_GetLocalCitadelPlayerController,
		&IGameEvent_GetName,
		&GetCUserCmdTick,
		&GetCUserCmdArray,
		&GetCUserCmdBySequenceNumber,
		&C_EnvSky_Update,
	};

	auto Searched = true;

	for ( auto& Pattern : vPatterns )
	{
		if ( !Pattern->Search() )
			Searched = false;
#if LOG_SDK_FUNCTION_LIST == 1
		else
		{
			DEV_LOG( "%s -> %p\n" , Pattern->GetPatternName() , Pattern->GetFunction() );
		}
#endif
	}

	return Searched;
}

auto GetFunctionList() -> CFunctionList*
{
	return &g_CFunctionList;
}
