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
};

auto GetFunctionList() -> CFunctionList*;
