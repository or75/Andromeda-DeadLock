#pragma once

#include <Common/Common.hpp>

class CSchemaSystem;
class IVEngineToClient;

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

	private:
		static CSchemaSystem* g_pSchemaSystem;
		static IVEngineToClient* g_pEngineToClient;
	};
}
