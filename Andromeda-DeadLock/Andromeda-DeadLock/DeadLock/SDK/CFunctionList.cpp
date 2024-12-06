#include "CFunctionList.hpp"

static CFunctionList g_CFunctionList{};

auto CFunctionList::OnInit() -> bool
{
	std::vector<CBasePattern*> vPatterns =
	{
	};

	auto Searched = true;

	for ( auto& Pattern : vPatterns )
	{
		if ( !Pattern->Search() )
			Searched = false;
#if LOG_SDK_FUNCTION_LIST == 1
		else
		{
			DEV_LOG( "%s -> %p\n" , Pattern->GetPatternName() , Pattern->GetFunction() );
		}
#endif
	}

	return Searched;
}

auto GetFunctionList() -> CFunctionList*
{
	return &g_CFunctionList;
}
