#pragma once

#include <Common/Common.hpp>

#include <DeadLock/SDK/CFunctionList.hpp>
#include <DeadLock/SDK/Math/Vector3.hpp>
#include <DeadLock/SDK/Math/QAngle.hpp>

class CSkeletonInstance;
class CCitadelInput;
class C_BaseEntity;
class CGameEntitySystem;
class CCitadelPlayerController;

DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL( void , CSkeletonInstance_CalcWorldSpaceBones , ( CSkeletonInstance* pCSkeletonInstance , unsigned int mask ) , ( CSkeletonInstance* , unsigned int ) , ( pCSkeletonInstance , mask ) );
DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL( bool , ScreenTransform , ( const Vector3& vOrigin , Vector3& vOut ) , ( const Vector3& , Vector3& ) , ( vOrigin , vOut ) );
DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL( QAngle* , CCitadelInput_GetViewAngles , ( CCitadelInput* pCCitadelInput , int32_t slot ) , ( CCitadelInput* , int32_t ) , ( pCCitadelInput , slot ) );
DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL( void , CCitadelInput_SetViewAngles , ( CCitadelInput* pCCitadelInput , int32_t slot , QAngle& Angles ) , ( CCitadelInput* , int32_t , QAngle& ) , ( pCCitadelInput , slot , Angles ) );
DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL( bool , C_BaseEntity_ComputeHitboxSurroundingBox , ( C_BaseEntity* pBaseEntity , Vector3& mins , Vector3& maxs ) , ( C_BaseEntity* , Vector3& , Vector3& ) , ( pBaseEntity , mins , maxs ) );
DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL( void* , CGameEntitySystem_GetBaseEntity , ( CGameEntitySystem* pGameEntitySystem , int iIndex ) , ( CGameEntitySystem* , int ) , ( pGameEntitySystem , iIndex ) );
DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL( void , CGameEntitySystem_GetHighestEntityIndex , ( CGameEntitySystem* pGameEntitySystem , int& HighestIdx ) , ( CGameEntitySystem* , int& ) , ( pGameEntitySystem , HighestIdx ) );
DECLARATE_DEADLOCK_FUNCTION_SDK_FASTCALL( CCitadelPlayerController* , CGameEntitySystem_GetLocalCitadelPlayerController , ( int iSlot ) , ( int ) , ( iSlot ) );