#include "CSDK_Loader.hpp"

#include <DeadLock/SDK/SDK.hpp>
#include <DeadLock/SDK/CSchemaOffset.hpp>
#include <DeadLock/SDK/SDL3/SDL3_Functions.hpp>

#include <Common/Helpers/ModuleLoaderHelper.hpp>

#define RETURN_FALSE_IF_INTERFACE_ERROR(Interface)\
if ( !Interface )\
{\
	DEV_LOG( "[error] Interface::%s\n" , #Interface );\
	return false;\
}

#define RETURN_FALSE_IF_POINTER_ERROR(Pointer)\
if ( !Pointer )\
{\
	DEV_LOG( "[error] Pointer::%s\n" , #Pointer );\
	return false;\
}

static CSDK_Loader g_SDK_Loader{};

auto CSDK_Loader::LoadSDK() -> bool
{
	// Wait for module load:
	if ( !IsModuleLoad( NAVSYSTEM_DLL ) )
		return false;

	// Log SDK:
#if LOG_SDK_INTERFACE == 1
	DEV_LOG( "[+] CSDK_Loader::LoadSDK:\n\n" );
#endif

	// Interfaces:
	auto pSchemaSystem = SDK::Interfaces::SchemaSystem();
	auto pEngineToClient = SDK::Interfaces::EngineToClient();
	
	// Return if error #1
	RETURN_FALSE_IF_INTERFACE_ERROR( pSchemaSystem );
	RETURN_FALSE_IF_INTERFACE_ERROR( pEngineToClient );
	
	// Log:
#if LOG_SDK_INTERFACE == 1
	DEV_LOG( "\n" );
#endif

	// Log:
#if LOG_SDK_INTERFACE == 1
	DEV_LOG( "[+] pSchemaSystem: %p\n" , pSchemaSystem );
	DEV_LOG( "[+] pEngineToClient: %p\n" , pEngineToClient );
#endif

	DEV_LOG( "\n" );

	// TEST SDK END

	if ( !GetSDL3Functions()->OnInit() )
		return false;

	GetSchemaOffset()->Init();

	return true;
}

auto GetSDK_Loader() -> CSDK_Loader*
{
	return &g_SDK_Loader;
}
