#include "SDK.hpp"

#include <DllLauncher.hpp>
#include <Common/MemoryEngine.hpp>

#include <DeadLock/SDK/Interface/Interface.hpp>
#include <DeadLock/SDK/Interface/CShemaSystemSDK.hpp>
#include <DeadLock/SDK/Interface/IEngineToClient.hpp>

#define INCLUDE_DEADLOCK_SEARCH_FUNCTION(Interface,FuncName)\
if ( !##Interface##_Search::##FuncName##Fn.Search() )\
	bIsReady = false;

namespace SDK
{
	CSchemaSystem* Interfaces::g_pSchemaSystem = nullptr;
	IVEngineToClient* Interfaces::g_pEngineToClient = nullptr;
	
	CSchemaSystem* Interfaces::SchemaSystem()
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

	IVEngineToClient* Interfaces::EngineToClient()
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
}
