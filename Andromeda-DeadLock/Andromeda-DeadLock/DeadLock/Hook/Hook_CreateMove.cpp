#include "Hook_CreateMove.hpp"

#include <DeadLock/SDK/Update/CCitadelInput.hpp>
#include <GameClient/CL_CitadelPlayerController.hpp>

auto Hook_CreateMove( CCitadelInput* pCitadelInput , uint32_t split_screen_index , char a3 ) -> void
{
	CreateMove_o( pCitadelInput , split_screen_index , a3 );

	if ( auto* pLocalCitadelPlayerController = GetCL_CitadelPlayerController()->GetLocal(); pLocalCitadelPlayerController )
	{
		if ( auto* pCUserCmd = pCitadelInput->GetUserCmd( pLocalCitadelPlayerController ); pCUserCmd )
		{
			DEV_LOG( "%s\n" , pCUserCmd->cmd.DebugString().c_str() );
		}
	}
}
