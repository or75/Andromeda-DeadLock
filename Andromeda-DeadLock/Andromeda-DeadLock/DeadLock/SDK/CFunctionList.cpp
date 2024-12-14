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
		&CGameEntitySystem_GetBaseEntity,
		&CGameEntitySystem_GetHighestEntityIndex,
		&CGameEntitySystem_GetLocalCitadelPlayerController,
		&IGameEvent_GetName,
		&GetCUserCmdTick,
		&GetCUserCmdArray,
		&GetCUserCmdBySequenceNumber,
		&C_EnvSky_Update,
		&C_CitadelPlayerPawn_GetBoneIdByName,
	};

	auto Searched = true;

	for ( auto& Pattern : vPatterns )
	{
		if ( !Pattern->Search() )
			Searched = false;
	}

	return Searched;
}

auto GetFunctionList() -> CFunctionList*
{
	return &g_CFunctionList;
}
