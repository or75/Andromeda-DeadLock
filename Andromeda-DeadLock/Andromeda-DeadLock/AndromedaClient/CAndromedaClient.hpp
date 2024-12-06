#pragma once

#include <Common/Common.hpp>

class IGameEvent;

class IAndromedaClient
{
public:
	virtual void OnFireEventClientSide( IGameEvent* pGameEvent ) = 0;

public:
	virtual void OnRenderMenu() = 0;
};

class CAndromedaClient final : public IAndromedaClient
{
public:
	auto OnInit() -> void;

public:
	virtual void OnFireEventClientSide( IGameEvent* pGameEvent ) override;

public:
	virtual void OnRenderMenu() override;
};

auto GetAndromedaClient() -> CAndromedaClient*;
