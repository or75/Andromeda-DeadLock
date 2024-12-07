#include "CHook_Loader.hpp"

#include <Common/MemoryEngine.hpp>
#include <MinHook/MinHook.h>

#include <DeadLock/SDK/SDK.hpp>

#include <DeadLock/Hook/Hook_Present.hpp>
#include <DeadLock/Hook/Hook_ResizeBuffers.hpp>
#include <DeadLock/Hook/Hook_CreateSwapChain.hpp>
#include <DeadLock/Hook/Hook_FireEventClientSide.hpp>
#include <DeadLock/Hook/Hook_MouseInputEnabled.hpp>
#include <DeadLock/Hook/Hook_IsRelativeMouseMode.hpp>
#include <DeadLock/Hook/Hook_OnAddEntity.hpp>
#include <DeadLock/Hook/Hook_OnRemoveEntity.hpp>
#include <DeadLock/Hook/Hook_GetMatricesForView.hpp>
#include <DeadLock/Hook/Hook_CreateMove.hpp>
#include <DeadLock/Hook/Hook_ParseMessage.hpp>

static CHook_Loader g_CHook_Loader{};

auto CHook_Loader::InitalizeMH() -> bool
{
	return MH_Initialize() == MH_OK;
}

auto CHook_Loader::InstallSecondHook() -> bool
{
	m_Hooks =
	{
		{ { XorStr( "Hook::PresentOverlay" ) , XorStr( "? ? ? ? ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 41 8B E8" ) , GAMEOVERLAYRENDER64_DLL } , &Hook_Present , reinterpret_cast<LPVOID*>( &Present_o ) },
		{ { XorStr( "Hook::ResizeBuffers" ) , XorStr( "? ? ? ? ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 44 8B FA" ) , GAMEOVERLAYRENDER64_DLL } , &Hook_ResizeBuffers , reinterpret_cast<LPVOID*>( &ResizeBuffers_o ) },
		{ { XorStr( "Hook::CreateSwapChainOld" ) , XorStr( "48 8D 15 ? ? ? ? E8 ? ? ? ? EB 20 48 8B 4E ? 48 8D 15 ? ? ? ? E8 ? ? ? ? 84 C0 75 0C 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8B 6C 24 ? 48 8B 0F E8 ? ? ? ? 48 8B 74 24 ? 8B C3 48 8B 5C 24 ? 48 83 C4 ? 5F C3 CC 48 89 5C 24 ? 48 89 74 24 ?" ) , GAMEOVERLAYRENDER64_DLL , 0 , eBasePatternSearchType::SEARCH_TYPE_PTR2 } , &Hook_CreateSwapChain , reinterpret_cast<LPVOID*>( &CreateSwapChain_o ) , true , true } ,
		{ { XorStr( "Hook::CreateSwapChainNew" ) , XorStr( "48 8D 15 ? ? ? ? E8 ? ? ? ? EB ? 48 8B 4E ? 48 8D 15 ? ? ? ? E8 ? ? ? ? 84 C0 75 ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8B 6C 24 ? 48 8B 0F E8 ? ? ? ? 48 8B 74 24 ? 8B C3 48 8B 5C 24 ? 48 83 C4 ? 5F C3 ? ? ? ? ? ? ? ? ? ? ? ? ? ? 48 89 5C 24 ? 48 89 74 24 ?" ) , GAMEOVERLAYRENDER64_DLL , 0 , eBasePatternSearchType::SEARCH_TYPE_PTR2 } , &Hook_CreateSwapChain , reinterpret_cast<LPVOID*>( &CreateSwapChain_o ) } ,
		{ { XorStr( "Hook::FireEventClientSide" ) , XorStr( "48 89 5C 24 ? 56 57 41 54 48 83 EC 30 48 8B F2" ) , CLIENT_DLL } , &Hook_FireEventClientSide , reinterpret_cast<LPVOID*>( &FireEventClientSide_o ) },
		{ { XorStr( "Hook::MouseInputEnabled" ) , XorStr( "48 83 EC 28 E8 ? ? ? ? 84 C0 0F 85" ) , CLIENT_DLL } , &Hook_MouseInputEnabled , reinterpret_cast<LPVOID*>( &MouseInputEnabled_o ) },
		{ { XorStr( "Hook::IsRelativeMouseMode" ) , XorStr( "48 89 6C 24 10 48 89 74 24 18 48 89 7C 24 20 41 56 48 83 EC ? 0F B6 EA" ) , INPUTSYSTEM_DLL } , &Hook_IsRelativeMouseMode , reinterpret_cast<LPVOID*>( &IsRelativeMouseMode_o ) },
		{ { XorStr( "Hook::OnAddEntity" ) , XorStr( "48 89 74 24 10 57 48 83 EC 20 48 8B F9 41 8B C0 B9 FF 7F 00 00 48 8B F2 23 C1 41 83 F8 FF 0F 45 C8 81 F9 00 40 00 00" ) , CLIENT_DLL } , &Hook_OnAddEntity , reinterpret_cast<LPVOID*>( &OnAddEntity_o ) },
		{ { XorStr( "Hook::OnRemoveEntity" ) , XorStr( "48 89 74 24 10 57 48 83 EC 20 48 8B F9 41 8B C0 25 FF 7F 00 00 B9 FF 7F 00 00 41 83 F8 FF 48 8B F2 0F 45 C8 81 F9 00 40 00 00" ) , CLIENT_DLL } , &Hook_OnRemoveEntity , reinterpret_cast<LPVOID*>( &OnRemoveEntity_o ) },
		{ { XorStr( "Hook::GetMatricesForView" ) , XorStr( "40 53 48 81 EC ? ? ? ? 49 8B C1" ) , CLIENT_DLL } , &Hook_GetMatricesForView , reinterpret_cast<LPVOID*>( &GetMatricesForView_o ) },
		{ { XorStr( "Hook::CreateMove" ) , XorStr( "85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40 18" ) , CLIENT_DLL } , &Hook_CreateMove , reinterpret_cast<LPVOID*>( &CreateMove_o ) },
		{ { XorStr( "Hook::ParseMessage" ) , XorStr( "40 56 57 41 57 48 83 EC ? 4C 8B F9" ) , ENGINE2_DLL } , &Hook_ParseMessage , reinterpret_cast<LPVOID*>( &ParseMessage_o ) },
	};

	return InstallHooks();
}

auto CHook_Loader::InstallHooks() -> bool
{
	for ( auto& Hook : m_Hooks )
	{
		while ( !GetModuleHandleA( Hook.m_Pattern.GetDllName() ) )
			   Sleep( 1 );

		if ( !Hook.m_Pattern.Search( Hook.m_bSkipError ) )
		{
			if ( !Hook.m_bSkipError )
				DEV_LOG( "[error] Hook #1 -> '%s'\n" , Hook.m_Pattern.GetPatternName() );

			if ( !Hook.m_bSkipIfNotFound )
				return false;
			else
				continue;
		}

		auto Status = MH_CreateHook( Hook.m_Pattern.GetFunction() , Hook.m_pDetour , Hook.m_pOriginal );

		if ( Status != MH_OK )
		{
			DEV_LOG( "[error] Hook #2 [%i] -> '%s'\n" , Status , Hook.m_Pattern.GetPatternName() );
			return false;
		}
	}

	MH_EnableHook( MH_ALL_HOOKS );

	m_Hooks.clear();

	return true;
}

auto CHook_Loader::DestroyHooks() -> void
{
	MH_DisableHook( MH_ALL_HOOKS );
	MH_Uninitialize();
}

auto GetHook_Loader() -> CHook_Loader*
{
	return &g_CHook_Loader;
}
