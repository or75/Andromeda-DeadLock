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

auto C_BaseEntity::GetOrigin() -> const Vector3&
{
	auto pGameSceneNode = m_pGameSceneNode();

	if ( !pGameSceneNode )
		return Vector3::Zero;

	return pGameSceneNode->m_vecAbsOrigin();
}

auto C_BaseEntity::GetBoundingBox( Rect_t& out , bool computeSurroundingBox ) -> bool
{
	auto pCollision = m_pCollision();

	if ( !pCollision )
		return false;

	Vector3 mins;
	Vector3 maxs;

	if ( computeSurroundingBox )
	{
		if ( !ComputeHitboxSurroundingBox( mins , maxs ) )
			return false;
	}
	else
	{
		const auto absOrigin = GetOrigin();

		mins = pCollision->m_vecMins() + absOrigin;
		maxs = pCollision->m_vecMaxs() + absOrigin;
	}

#undef max
#undef min

	out.x = out.y = std::numeric_limits<float>::max();
	out.w = out.h = -std::numeric_limits<float>::max();

	for ( int i = 0; i < 8; ++i )
	{
		const Vector3 point_list[8] =
		{
		  Vector3( mins.m_x, mins.m_y, mins.m_z ), Vector3( mins.m_x, maxs.m_y, mins.m_z ),
		  Vector3( maxs.m_x, maxs.m_y, mins.m_z ), Vector3( maxs.m_x, mins.m_y, mins.m_z ),
		  Vector3( maxs.m_x, maxs.m_y, maxs.m_z ), Vector3( mins.m_x, maxs.m_y, maxs.m_z ),
		  Vector3( mins.m_x, mins.m_y, maxs.m_z ), Vector3( maxs.m_x, mins.m_y, maxs.m_z )
		};

		const Vector3 Point = point_list[i];

		ImVec2 Screen;

		if ( !Math::WorldToScreen( Point , Screen ) )
			return false;

		out.x = std::min( out.x , Screen.x );
		out.y = std::min( out.y , Screen.y );
		out.w = std::max( out.w , Screen.x );
		out.h = std::max( out.h , Screen.y );
	}

	return true;
}

auto C_BaseEntity::ComputeHitboxSurroundingBox( Vector3& mins , Vector3& maxs ) -> bool
{
	return C_BaseEntity_ComputeHitboxSurroundingBox( this , mins , maxs );
}
