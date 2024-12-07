#include "SDK.hpp"

#include <DllLauncher.hpp>
#include <Common/MemoryEngine.hpp>

#include <DeadLock/SDK/Interface/Interface.hpp>
#include <DeadLock/SDK/Interface/CShemaSystemSDK.hpp>
#include <DeadLock/SDK/Interface/IEngineToClient.hpp>
#include <DeadLock/SDK/Interface/CInputSystem.hpp>

#define INCLUDE_DEADLOCK_SEARCH_FUNCTION(Interface,FuncName)\
if ( !##Interface##_Search::##FuncName##Fn.Search() )\
	bIsReady = false;

namespace SDK
{
	CSchemaSystem* Interfaces::g_pSchemaSystem = nullptr;
	IVEngineToClient* Interfaces::g_pEngineToClient = nullptr;
	CGameEntitySystem* Interfaces::g_pGameEntitySystem = nullptr;
	CInputSystem* Interfaces::g_pInputSystem = nullptr;

	CUserCmd** Pointers::g_ppCUserCmd = nullptr;

	auto Interfaces::SchemaSystem() -> CSchemaSystem*
	{
		if ( !g_pSchemaSystem )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( SCHEMASYSTEM_DLL );
			g_pSchemaSystem = CaptureInterface<CSchemaSystem>( pfnFactory , XorStr( SCHEMA_SYSTEM_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_DEADLOCK_SEARCH_FUNCTION( CSchemaSystem , GetAllTypeScope );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pSchemaSystem;
	}

	auto Interfaces::EngineToClient() -> IVEngineToClient*
	{
		if ( !g_pEngineToClient )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( ENGINE2_DLL );
			g_pEngineToClient = CaptureInterface<IVEngineToClient>( pfnFactory , XorStr( IVENGINE_TO_CLIENT_INTERFACE_VERSION ) );

			bool bIsReady = true;

			INCLUDE_DEADLOCK_SEARCH_FUNCTION( IVEngineToClient , IsInGame );
			INCLUDE_DEADLOCK_SEARCH_FUNCTION( IVEngineToClient , ExecuteClientCmd );

			if ( !bIsReady )
				return nullptr;
		}

		return g_pEngineToClient;
	}

	auto Interfaces::GameEntitySystem() -> CGameEntitySystem*
	{
		if ( !g_pGameEntitySystem )
		{
			/*
			00007FFAAA94B06 | 48:8B0D 90C67A01               | mov rcx,qword ptr ds:[0x7FFAAC0F7700]            | ppGameEntitySystem
			00007FFAAA94B07 | 48:8D9424 50020000             | lea rdx,qword ptr ss:[rsp+0x250]                 |
			00007FFAAA94B07 | 33DB                           | xor ebx,ebx                                      |
			00007FFAAA94B07 | E8 81ABEBFF                    | call client.7FFAAA805C00                         | GetHighestEntityIndex
			00007FFAAA94B07 | 8B08                           | mov ecx,dword ptr ds:[rax]                       |
			00007FFAAA94B08 | FFC1                           | inc ecx                                          |
			00007FFAAA94B08 | 85C9                           | test ecx,ecx                                     |
			00007FFAAA94B08 | 0F8E FC000000                  | jle client.7FFAAA94B187                          |
			00007FFAAA94B08 | 48:89BC24 40020000             | mov qword ptr ss:[rsp+0x240],rdi                 |
			00007FFAAA94B09 | 0F1F40 00                      | nop dword ptr ds:[rax],eax                       |
			00007FFAAA94B09 | 66:0F1F8400 00000000           | nop word ptr ds:[rax+rax],ax                     |
			00007FFAAA94B0A | 48:8B0D 59C67A01               | mov rcx,qword ptr ds:[0x7FFAAC0F7700]            |
			00007FFAAA94B0A | 8BD3                           | mov edx,ebx                                      |
			00007FFAAA94B0A | E8 E2A2ECFF                    | call client.7FFAAA815390                         | GetBaseEntity
			00007FFAAA94B0A | 48:8BF8                        | mov rdi,rax                                      |
			00007FFAAA94B0B | 48:85C0                        | test rax,rax                                     |
			00007FFAAA94B0B | 74 76                          | je client.7FFAAA94B12C                           |
			00007FFAAA94B0B | C64424 30 00                   | mov byte ptr ss:[rsp+0x30],0x0                   |
			00007FFAAA94B0B | 48:8BC8                        | mov rcx,rax                                      |
			00007FFAAA94B0B | 48:8B10                        | mov rdx,qword ptr ds:[rax]                       |
			00007FFAAA94B0C | FF92 60010000                  | call qword ptr ds:[rdx+0x160]                    |
			00007FFAAA94B0C | 4C:8D05 6AC7A200               | lea r8,qword ptr ds:[0x7FFAAB377838]             | 00007FFAAB377838:"'%s'"
			00007FFAAA94B0C | BA 00010000                    | mov edx,0x100                                    |
			00007FFAAA94B0D | 48:8D8C24 30010000             | lea rcx,qword ptr ss:[rsp+0x130]                 |
			00007FFAAA94B0D | 4C:8B48 08                     | mov r9,qword ptr ds:[rax+0x8]                    |
			00007FFAAA94B0D | FF15 8B258900                  | call qword ptr ds:[<V_snprintf>]                 |
			00007FFAAA94B0E | 48:8B47 10                     | mov rax,qword ptr ds:[rdi+0x10]                  |
			00007FFAAA94B0E | 48:8D15 78A38A00               | lea rdx,qword ptr ds:[0x7FFAAB1F5468]            |
			00007FFAAA94B0F | 4C:8D8C24 30010000             | lea r9,qword ptr ss:[rsp+0x130]                  |
			00007FFAAA94B0F | 4C:8D4424 30                   | lea r8,qword ptr ss:[rsp+0x30]                   |
			00007FFAAA94B0F | 48:8B48 18                     | mov rcx,qword ptr ds:[rax+0x18]                  |
			00007FFAAA94B10 | 48:8D05 60A38A00               | lea rax,qword ptr ds:[0x7FFAAB1F5468]            |
			00007FFAAA94B10 | 48:85C9                        | test rcx,rcx                                     |
			00007FFAAA94B10 | 48:0F45D1                      | cmovne rdx,rcx                                   |
			00007FFAAA94B10 | 48:8D0D 726AC500               | lea rcx,qword ptr ds:[0x7FFAAB5A1B88]            | 00007FFAAB5A1B88:"Ent %3d: %s class %s name %s\n"
			*/

			auto ppGameEntitySystem = reinterpret_cast<uintptr_t>( FindPattern( CLIENT_DLL , XorStr( "48 8B ? ? ? ? ? 48 8D 94 24 50 02 00 00 33 DB E8 ? ? ? ? 8B 08 FF C1 85 C9" ) ) );

			if ( !ppGameEntitySystem )
				return nullptr;

GetGameEntitySystemPointer:;

			g_pGameEntitySystem = *GetPtrAddress<CGameEntitySystem**>( ppGameEntitySystem );

			if ( !g_pGameEntitySystem )
			{
				Sleep( 500 );
				goto GetGameEntitySystemPointer;
			}
		}

		return g_pGameEntitySystem;
	}

	auto Interfaces::InputSystem() -> CInputSystem*
	{
		if ( !g_pInputSystem )
		{
			CreateInterfaceFn pfnFactory = CaptureFactory( INPUTSYSTEM_DLL );
			g_pInputSystem = CaptureInterface<CInputSystem>( pfnFactory , XorStr( INPUT_SYSTEM_INTERFACE_VERSION ) );
		}

		return g_pInputSystem;
	}

	/*
	00007FFB8C03CA8 | 48:8B0D 1D102001               | mov rcx,qword ptr ds:[0x7FFB8D23DAB0]            | CUserCmd**
	00007FFB8C03CA9 | E8 080AE2FF                    | call client.7FFB8BE5D4A0                         | GetCUserCmdArray
	00007FFB8C03CA9 | 48:8BCF                        | mov rcx,rdi                                      |
	00007FFB8C03CA9 | 4C:8BE8                        | mov r13,rax                                      |
	00007FFB8C03CA9 | 44:8BB8 70650000               | mov r15d,dword ptr ds:[rax+0x6570]               | offset SequenceNumber
	00007FFB8C03CAA | 41:8BD7                        | mov edx,r15d                                     |
	00007FFB8C03CAA | E8 2307E2FF                    | call client.7FFB8BE5D1D0                         | GetUserCmdBySequenceNumber
	*/
	// 48 8B ? ? ? ? ? E8 ? ? ? ? 48 8B CF 4C 8B E8 44 8B B8 ? ? ? ? 41 8B D7 E8
	auto Pointers::GetFirstCUserCmdArray() -> CUserCmd**
	{
		if ( !g_ppCUserCmd )
		{
			auto ppCUserCmd = reinterpret_cast<uintptr_t>( FindPattern( CLIENT_DLL , XorStr( "48 8B ? ? ? ? ? E8 ? ? ? ? 48 8B CF 4C 8B E8 44 8B B8 ? ? ? ? 41 8B D7 E8 ? ? ? ? 48 8B ? ? ? ? ? 45 33 E4" ) ) );

			if ( !ppCUserCmd )
				return nullptr;

			g_ppCUserCmd = *GetPtrAddress<CUserCmd***>( ppCUserCmd );
		}

		return g_ppCUserCmd;
	}
}
