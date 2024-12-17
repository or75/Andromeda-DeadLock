#include "CEntityData.hpp"

#include <DeadLock/SDK/FunctionListSDK.hpp>
#include <DeadLock/SDK/Math/Math.hpp>

auto CGameSceneNode::GetBonePosition( int32 BoneIndex , Vector3& BonePos ) -> bool
{
	if ( auto* pSkeletonInstance = GetSkeletonInstance(); pSkeletonInstance && BoneIndex != -1 )
	{
		CModelState ModelState = pSkeletonInstance->m_modelState();

		if ( const CBoneData* pBones = ModelState.m_pBones; pBones )
		{
			const CBoneData& Data = pBones[BoneIndex];

			BonePos = Data.position;

			return true;
		}
	}

	return false;
}

auto CSkeletonInstance::CalcWorldSpaceBones( unsigned int Mask ) -> void
{
	return CSkeletonInstance_CalcWorldSpaceBones( this , Mask );
}

auto C_BaseEntity::IsCitadelPlayerController() -> bool
{
	const auto* pszDesingerName = pEntityIdentity()->DesingerName().String();

	if ( pszDesingerName && strcmp( pszDesingerName , XorStr( "citadel_player_controller" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::IsCitadelPlayerPawn() -> bool
{
	const auto* pszDesingerName = pEntityIdentity()->DesingerName().String();

	if ( pszDesingerName && strcmp( pszDesingerName , XorStr( "player" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::IsNpcTrooper() -> bool
{
	const auto* pszDesingerName = pEntityIdentity()->DesingerName().String();

	if ( pszDesingerName && strcmp( pszDesingerName , XorStr( "npc_trooper" ) ) == 0 )
		return true;

	return false;
}

auto C_BaseEntity::GetBoneIdByName( const char* szName ) -> int
{
	return C_BaseEntity_GetBoneIdByName( this , szName );
}
