#pragma once

#include <Common/Common.hpp>

class CCitadelInput;
class CUserCmd;

class IMisc
{
public:
	virtual void OnCreateMove( CCitadelInput* pInput , CUserCmd* pUserCmd ) = 0;
};

class CMisc final : public IMisc
{
public:
	virtual void OnCreateMove( CCitadelInput* pInput , CUserCmd* pUserCmd ) override;
};

auto GetMisc() -> CMisc*;
