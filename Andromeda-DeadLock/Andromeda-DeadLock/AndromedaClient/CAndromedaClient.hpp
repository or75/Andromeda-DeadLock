#pragma once

#include <Common/Common.hpp>

#include <DeadLock/SDK/Types/CEntityData.hpp>

class IGameEvent;

class IAndromedaClient
{
public:
	virtual void OnFireEventClientSide( IGameEvent* pGameEvent ) = 0;
	virtual void OnAddEntity( CEntityInstance* pInst , CHandle handle ) = 0;
	virtual void OnRemoveEntity( CEntityInstance* pInst , CHandle handle ) = 0;

public:
	virtual void OnRenderMenu() = 0;
};

class CAndromedaClient final : public IAndromedaClient
{
public:
	auto OnInit() -> void;

public:
	virtual void OnFireEventClientSide( IGameEvent* pGameEvent ) override;
	virtual void OnAddEntity( CEntityInstance* pInst , CHandle handle ) override;
	virtual void OnRemoveEntity( CEntityInstance* pInst , CHandle handle ) override;

public:
	virtual void OnRenderMenu() override;
};

auto GetAndromedaClient() -> CAndromedaClient*;
