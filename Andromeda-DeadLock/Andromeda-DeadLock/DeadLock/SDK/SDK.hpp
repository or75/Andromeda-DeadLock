#pragma once

#include <Common/Common.hpp>

class CSchemaSystem;
class IVEngineToClient;
class CGameEntitySystem;

#define CLIENT_DLL				"client.dll"
#define ENGINE2_DLL				"engine2.dll"
#define NAVSYSTEM_DLL			"navsystem.dll"
#define GAMEOVERLAYRENDER64_DLL "gameoverlayrenderer64.dll"
#define SCHEMASYSTEM_DLL		"schemasystem.dll"

namespace SDK
{
	class Interfaces
	{
	public:
		static CSchemaSystem* SchemaSystem();
		static IVEngineToClient* EngineToClient();
		static CGameEntitySystem* GameEntitySystem();

	private:
		static CSchemaSystem* g_pSchemaSystem;
		static IVEngineToClient* g_pEngineToClient;
		static CGameEntitySystem* g_pGameEntitySystem;
	};
}
