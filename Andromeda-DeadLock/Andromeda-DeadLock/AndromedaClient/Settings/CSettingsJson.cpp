#include "CSettingsJson.hpp"
#include "DllLauncher.hpp"

#include <filesystem>

static CSettingsJson g_CSettingsJson{};

auto CSettingsJson::LoadConfig( const std::string& JsonFile ) -> void
{

}

auto CSettingsJson::SaveConfig( const std::string& JsonFile ) -> void
{

}

auto CSettingsJson::DeleteConfig( const std::string& JsonFile ) -> void
{
	const auto ConfigFilePath = GetDllDir() + JsonFile;

	DeleteFileA( ConfigFilePath.c_str() );
}

auto CSettingsJson::UpdateConfigList() -> void
{
	m_vecConfigList.clear();

	for ( const auto& Entry : std::filesystem::directory_iterator( GetDllDir().c_str() ) )
	{
		if ( Entry.is_regular_file() )
		{
			if ( Entry.path().extension().string() == XorStr( ".json" ) )
				m_vecConfigList.emplace_back( Entry.path().filename().string() );
		}
	}
}

auto CSettingsJson::GetIntJson( const rapidjson::Value& JsonValue , const char* Name , int& Output , const int Min , const int Max ) -> void
{
	if ( !JsonValue.IsNull() && JsonValue.HasMember( Name ) )
	{
		auto& Value = JsonValue[Name];

		if ( !Value.IsNull() && Value.IsInt() )
		{
			const auto IntValue = Value.GetInt();

			if ( IntValue < Min )
				Output = Min;
			else if ( IntValue > Max )
				Output = Max;
			else
				Output = IntValue;
		}
	}
}

auto CSettingsJson::GetBoolJson( const rapidjson::Value& JsonValue , const char* Name , bool& Output ) -> void
{
	if ( !JsonValue.IsNull() && JsonValue.HasMember( Name ) )
	{
		auto& Value = JsonValue[Name];

		if ( !Value.IsNull() && Value.IsBool() )
			Output = Value.GetBool();
	}
}

auto CSettingsJson::GetFloatJson( const rapidjson::Value& JsonValue , const char* Name , float& Output , const float Min , const float Max ) -> void
{
	if ( !JsonValue.IsNull() && JsonValue.HasMember( Name ) )
	{
		auto& Value = JsonValue[Name];

		if ( !Value.IsNull() && Value.IsFloat() )
		{
			Output = std::clamp( Value.GetFloat() , Min , Max );
		}
	}
}

auto CSettingsJson::GetColorJson( const rapidjson::Value& JsonValue , const char* Name , float* Output ) -> void
{
	if ( !JsonValue.IsNull() && JsonValue.HasMember( Name ) )
	{
		auto& Value = JsonValue[Name];

		if ( !Value.IsNull() && Value.IsArray() && Value.GetArray().Size() == 3 )
		{
			Output[0] = Value.GetArray()[0].GetFloat();
			Output[1] = Value.GetArray()[1].GetFloat();
			Output[2] = Value.GetArray()[2].GetFloat();

			Output[0] = std::clamp( Output[0] , 0.f , 1.f );
			Output[1] = std::clamp( Output[1] , 0.f , 1.f );
			Output[2] = std::clamp( Output[2] , 0.f , 1.f );
		}
	}
}

auto CSettingsJson::AddIntJson( rapidjson::PrettyWriter<rapidjson::OStreamWrapper>& Writer , const char* Name , int& Output ) -> void
{
	Writer.String( Name );
	Writer.Int( Output );
}

auto CSettingsJson::AddUInt64Json( rapidjson::PrettyWriter<rapidjson::OStreamWrapper>& Writer , const char* Name , uint64_t& Output ) -> void
{
	Writer.String( Name );
	Writer.Uint64( Output );
}

auto CSettingsJson::AddBoolJson( rapidjson::PrettyWriter<rapidjson::OStreamWrapper>& Writer , const char* Name , bool& Output ) -> void
{
	Writer.String( Name );
	Writer.Bool( Output );
}

auto CSettingsJson::AddStringJson( rapidjson::PrettyWriter<rapidjson::OStreamWrapper>& Writer , const char* Name , std::string& Output ) -> void
{
	Writer.String( Name );
	Writer.String( Output.c_str() );
}

auto CSettingsJson::AddFloatJson( rapidjson::PrettyWriter<rapidjson::OStreamWrapper>& Writer , const char* Name , float& Output ) -> void
{
	Writer.String( Name );
	Writer.Double( static_cast<double>( Output ) );
}

auto CSettingsJson::AddColorJson( rapidjson::PrettyWriter<rapidjson::OStreamWrapper>& Writer , const char* Name , float* Output ) -> void
{
	Writer.String( Name );
	Writer.StartArray();

	Writer.Double( static_cast<double>( Output[0] ) );
	Writer.Double( static_cast<double>( Output[1] ) );
	Writer.Double( static_cast<double>( Output[2] ) );

	Writer.EndArray();
}

auto GetSettingsJson() -> CSettingsJson*
{
	return &g_CSettingsJson;
}
