#pragma once

#include <Common/Common.hpp>

#include <DeadLock/SDK/Types/CEntityData.hpp>

class IGameEvent;
class CCitadelInput;
class CUserCmd;

struct SoundData_t
{
	ULONGLONG dwTime = 0;
	Vector3 Pos;
};

class IAndromedaClient
{
public:
	virtual void OnFireEventClientSide( IGameEvent* pGameEvent ) = 0;
	virtual void OnAddEntity( CEntityInstance* pInst , CHandle handle ) = 0;
	virtual void OnRemoveEntity( CEntityInstance* pInst , CHandle handle ) = 0;
	virtual void OnStartSound( const Vector3& Pos , const int SourceEntityIndex , const char* szSoundName ) = 0;
	virtual void OnCreateMove( CCitadelInput* pCitadelInput , CUserCmd* pUserCmd ) = 0;
	virtual void OnClientOutput() = 0;

public:
	virtual void OnRender() = 0;
};

class CAndromedaClient final : public IAndromedaClient
{
	using SoundListVecType_t = std::vector<SoundData_t>;
	using Lock_t = std::mutex;

public:
	auto OnInit() -> void;

public:
	virtual void OnFireEventClientSide( IGameEvent* pGameEvent ) override;
	virtual void OnAddEntity( CEntityInstance* pInst , CHandle handle ) override;
	virtual void OnRemoveEntity( CEntityInstance* pInst , CHandle handle ) override;
	virtual void OnStartSound( const Vector3& Pos , const int SourceEntityIndex , const char* szSoundName ) override;
	virtual void OnCreateMove( CCitadelInput* pCitadelInput , CUserCmd* pUserCmd ) override;
	virtual void OnClientOutput() override;

public:
	virtual void OnRender() override;

private:
	SoundListVecType_t m_SoundList;
	Lock_t m_SoundLock;

private:
	constexpr static auto g_SoundShowTime = 1000;
};

auto GetAndromedaClient() -> CAndromedaClient*;
