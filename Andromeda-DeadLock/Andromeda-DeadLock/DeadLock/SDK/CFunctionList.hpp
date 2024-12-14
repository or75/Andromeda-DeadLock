#pragma once

#include <vector>
#include <Common/Common.hpp>

#include <DeadLock/SDK/SDK.hpp>
#include <DeadLock/CBasePattern.hpp>

#define DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL(Ret,Function,Param,UsingParam,CallParam)\
inline Ret Function Param\
{\
	using Fn = Ret ( __fastcall* ) UsingParam;\
	Fn Original = static_cast<Fn>( GetFunctionList()->##Function##.GetFunction() );\
	return Original##CallParam##;\
}

class CFunctionList final
{
public:
	auto OnInit() -> bool;

public:
	CBasePattern CSkeletonInstance_CalcWorldSpaceBones = { VmpStr( "CSkeletonInstance::CalcWorldSpaceBones" ) , VmpStr( "40 55 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8D 6C 24 ? 48 8B F1" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern ScreenTransform = { VmpStr( "ScreenTransform" ) , VmpStr( "48 89 5C 24 ? 56 48 83 EC 20 48 8B F1 48 8B DA 48 8B 0D" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern CCitadelInput_GetViewAngles = { VmpStr( "CCitadelInput::GetViewAngles" ) , VmpStr( "E8 ? ? ? ? EB ? 48 8B 01 48 8D 54 24 ?" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern CCitadelInput_SetViewAngles = { VmpStr( "CCitadelInput::SetViewAngles" ) , VmpStr( "85 D2 75 3F 48 63 81 ? ? ? ? F2 41 0F 10 00 85 C0 74 1D 48 8B 89 ? ? ? ? 48 69 D0" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern CGameEntitySystem_GetBaseEntity = { VmpStr( "CGameEntitySystem::GetBaseEntity" ) , VmpStr( "81 FA FE 7F 00 00 77 36 8B C2 C1 F8 09 83 F8 3F" ) , CLIENT_DLL };
	CBasePattern CGameEntitySystem_GetHighestEntityIndex = { VmpStr( "CGameEntitySystem::GetHighestEntityIndex" ) , VmpStr( "E8 ? ? ? ? 8B 08 FF C1 85 C9 0F 8E" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern CGameEntitySystem_GetLocalCitadelPlayerController = { VmpStr( "CGameEntitySystem::GetLocalCitadelPlayerController" ) , VmpStr( "E8 ? ? ? ? 45 8B 4F ? 4C 8D 05" ) , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern IGameEvent_GetName = { VmpStr( "IGameEvent::GetName" ) , VmpStr( "8B 41 14 0F BA E0 1E 73 05 48 8D 41 18 C3" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern GetCUserCmdTick = { VmpStr( "GetCUserCmdTick" ) , VmpStr( "40 53 48 83 EC 20 4C 8B 41 ? 48 8B DA 48 8B 0D" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern GetCUserCmdArray = { VmpStr( "GetCUserCmdArray" ) , VmpStr( "48 89 4C 24 ? 41 54 41 57" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern GetCUserCmdBySequenceNumber = { VmpStr( "GetÑUserCmdBySequenceNumber" ) , VmpStr( "40 53 48 83 EC 20 8B DA 85 D2 78" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_EnvSky_Update = { VmpStr( "C_EnvSky::Update" ) , VmpStr( "40 53 48 83 EC 30 48 8B D9 E8 ? ? ? ? 48 8B 43" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern C_CitadelPlayerPawn_GetBoneIdByName = { VmpStr( "C_CitadelPlayerPawn::GetBoneIdByName" ) , VmpStr( "40 53 48 83 EC 20 48 8B 89 ? ? ? ? 48 8B DA 48 8B 01 FF 50 ? 48 8B C8" ) , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };

};

auto GetFunctionList() -> CFunctionList*;
