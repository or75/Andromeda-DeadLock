#pragma once

#include <Common/Common.hpp>

#include "Color.hpp"

#include "CBaseTypes.hpp"
#include "CHandle.hpp"

#include "CUtlMemory.hpp"
#include "CUtlString.hpp"
#include "CUtlSymbol.hpp"
#include "CUtlSymbolLarge.hpp"
#include "CUtlVector.hpp"
#include "CStrongHandle.hpp"
#include "CUtlStringToken.hpp"

#include <DeadLock/SDK/CSchemaOffset.hpp>
#include <DeadLock/SDK/Interface/CShemaSystemSDK.hpp>
#include <DeadLock/SDK/Math/Rect_t.hpp>

namespace index
{
	namespace CGameSceneNode
	{
		constexpr auto GetSkeletonInstance = 8;
	}
}

class CSkeletonInstance;
class InfoForResourceTypeCModel {};

struct alignas( 16 ) CBoneData
{
	Vector3 position;
	float scale;
	Vector3 rotation;
};

class CPlayerPawnComponent
{
public:
};

class IHandleEntity
{
public:
	virtual ~IHandleEntity() {}
};

class CEntityIdentity 
{
public:
	SCHEMA_OFFSET_CUSTOM( pBaseEntity , 0x0 , C_BaseEntity* );
	SCHEMA_OFFSET_CUSTOM( Handle , 0x10 , CHandle );

public:
	SCHEMA_OFFSET( "CEntityIdentity" , "m_name" , Name , CUtlSymbolLarge );
	SCHEMA_OFFSET( "CEntityIdentity" , "m_designerName" , DesingerName , CUtlSymbolLarge );
};

class CEntityInstance : public IHandleEntity
{
public:
	auto GetSchemaClassBinding() -> CSchemaClassBinding*
	{
		CSchemaClassBinding* pBinding = nullptr;

		VirtualFn( void )( CEntityInstance* , CSchemaClassBinding** );
		vget< Fn >( this , index::CSchemaSystem::SchemaClassInfo )( this , &pBinding );

		return pBinding;
	}

public:
	SCHEMA_OFFSET( "CEntityInstance" , "m_pEntity" , pEntityIdentity , CEntityIdentity* );
	SCHEMA_OFFSET( "CEntityInstance" , "m_bVisibleinPVS" , m_bVisibleinPVS , bool );
};

class CGameSceneNode
{
public:
	SCHEMA_OFFSET( "CGameSceneNode" , "m_vecAbsOrigin" , m_vecAbsOrigin , Vector3 );

public:
	auto GetBonePosition( int32 BoneIndex , Vector3& BonePos ) -> bool;

public:
	auto GetSkeletonInstance() -> CSkeletonInstance*
	{
		VirtualFn( CSkeletonInstance* )( CGameSceneNode* );
		return vget< Fn >( this , index::CGameSceneNode::GetSkeletonInstance )( this );
	}
};

class CModelState
{
private:
	PAD( 0x80 );

public:
	CBoneData* m_pBones;

public:
	SCHEMA_OFFSET( "CModelState" , "m_hModel" , m_hModel , CStrongHandle<InfoForResourceTypeCModel> );
	SCHEMA_OFFSET( "CModelState" , "m_ModelName" , m_ModelName , CUtlSymbolLarge );
};

class CSkeletonInstance : public CGameSceneNode
{
public:
	SCHEMA_OFFSET( "CSkeletonInstance" , "m_modelState" , m_modelState , CModelState );

public:
	auto CalcWorldSpaceBones( unsigned int Mask ) -> void;
};

class CCollisionProperty
{
public:
	SCHEMA_OFFSET( "CCollisionProperty" , "m_vecMins" , m_vecMins , Vector3 );
	SCHEMA_OFFSET( "CCollisionProperty" , "m_vecMaxs" , m_vecMaxs , Vector3 );
};

class C_BaseEntity : public CEntityInstance
{
public:
	auto IsCitadelPlayerController() -> bool;
	auto IsCitadelPlayerPawn() -> bool;

public:
	auto GetOrigin() -> const Vector3&;

public:
	auto GetBoundingBox( Rect_t& out , bool computeSurroundingBox = false ) -> bool;
	auto ComputeHitboxSurroundingBox( Vector3& mins , Vector3& maxs ) -> bool;

public:
	SCHEMA_OFFSET( "C_BaseEntity" , "m_pGameSceneNode" , m_pGameSceneNode , CGameSceneNode* );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_pCollision" , m_pCollision , CCollisionProperty* );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_iTeamNum" , m_iTeamNum , uint8 );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_fFlags" , m_fFlags , uint32 );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_MoveType" , m_MoveType , MoveType_t );
	SCHEMA_OFFSET( "C_BaseEntity" , "m_nActualMoveType" , m_nActualMoveType , MoveType_t );
};

class C_BaseModelEntity : public C_BaseEntity
{
public:
};

class CBaseAnimGraph : public C_BaseModelEntity
{
public:
};

class C_BaseFlex : public CBaseAnimGraph
{
public:
};

class C_BaseCombatCharacter : public C_BaseFlex
{
public:
};

class C_BaseToggle : public C_BaseModelEntity
{
public:
};

class C_BaseTrigger : public C_BaseToggle
{
public:
};

class C_PostProcessingVolume : public C_BaseTrigger
{
public:
	SCHEMA_OFFSET( "C_PostProcessingVolume" , "m_flMinExposure" , m_flMinExposure , float32 );
	SCHEMA_OFFSET( "C_PostProcessingVolume" , "m_flMaxExposure" , m_flMaxExposure , float32 );
	SCHEMA_OFFSET( "C_PostProcessingVolume" , "m_bExposureControl" , m_bExposureControl , bool );
};

class CPlayer_CameraServices : public CPlayerPawnComponent
{
public:
	SCHEMA_OFFSET( "CPlayer_CameraServices" , "m_hActivePostProcessingVolume" , m_hActivePostProcessingVolume , CHandle ); // C_PostProcessingVolume
};

class C_BasePlayerPawn : public C_BaseCombatCharacter
{
public:
	SCHEMA_OFFSET( "C_BasePlayerPawn" , "m_pCameraServices" , m_pCameraServices , CPlayer_CameraServices* );
};

class CCitadelPlayerPawnBase : public C_BasePlayerPawn
{
public:
};

class C_CitadelPlayerPawn : public CCitadelPlayerPawnBase
{
public:
};

class CBasePlayerController : public C_BaseEntity
{
public:
	SCHEMA_OFFSET( "CBasePlayerController" , "m_hPawn" , m_hPawn , CHandle ); // C_BasePlayerPawn
};

class CCitadelPlayerController : public CBasePlayerController
{
public:
	SCHEMA_OFFSET( "CCitadelPlayerController" , "m_hHeroPawn" , m_hHeroPawn , CHandle ); // C_CitadelPlayerPawn
};

class C_EnvSky : public C_BaseModelEntity
{
public:
	SCHEMA_OFFSET( "C_EnvSky" , "m_vTintColor" , m_vTintColor , Color );
	SCHEMA_OFFSET( "C_EnvSky" , "m_vTintColorLightingOnly" , m_vTintColorLightingOnly , Color );
};
