#pragma once

#include <Common/Common.hpp>
#include <Common/MemoryEngine.hpp>

#include <DeadLock/CBasePattern.hpp>

#include <DeadLock/SDK/SDK.hpp>
#include <DeadLock/SDK/Types/CBaseTypes.hpp>

#define SCHEMA_SYSTEM_INTERFACE_VERSION "SchemaSystem_001"

#pragma region CSchemaSystemIndex

namespace index
{
	namespace CSchemaSystem
	{
		constexpr auto GlobalTypeScope = 11;
		constexpr auto SchemaClassInfo = 38;
	}
}

#pragma endregion

#pragma region GeneratorOffset

namespace GeneratorOffset
{
	constexpr auto GetNumSchema = 0x29;
	constexpr auto GetClassContainer = 0x580; // 49 8D 9E ? ? ? ? 0F 1F 40 00 66 66 66 0F 1F 84 00 00 00 00 00 41 B8 4E 02 00 00 48 8D ? ? ? ? ? 48 8B CB
	constexpr auto GetEnumContainer = 0x2E10;
}

#pragma endregion

#pragma region CSchemaSystemClasses

class CSchemaClassBinding;
class CSchemaEnumBinding;
class CSchemaType;
class CSchemaSystemTypeScope;

#pragma endregion

#pragma region CSchemaSystemImpl

struct SchemaClassFieldDataArray_t
{
	char* FieldName;
	CSchemaType* FieldType;
	int FieldOffset;
	int FieldUnk;
	void* unkn0;
};

struct SchemaEnumFieldDataArray_t
{
	char* FieldName;
	uint64_t FieldData;
	void* unkn0;
	void* unkn1;
};

class CSchemaClassBinding
{
public:
	class CBaseClass_t
	{
	public:
		void* unk;
		CSchemaClassBinding* m_classInfo;
	};
	void* pthis;
	const char* m_bindingName;
	char* m_dllName;
	int m_SizeOf;
	unsigned short int m_DataArraySize;
	unsigned short int unkn1;
	unsigned short int unkn2;
	BYTE m_Align;
	BYTE unkn3;
	unsigned short int unkn4;
	unsigned short int m_baseClass_num;
	SchemaClassFieldDataArray_t* m_DataArray;
	void* unkn6;
	CBaseClass_t* m_baseClass;
	void* unkn7;
	void* unkn8;
	CSchemaSystemTypeScope* m_TypeScope;
	CSchemaType* m_Type;
	unsigned short int m_Flags;
};

class CSchemaEnumBinding
{
public:
	void* pthis;
	const char* m_bindingName;
	char* m_dllName;
	int8 m_TypeSize;
	int8 m_TypeAlign;
	int16 unkn0;
	int16 size;
	int16 unkn1;
	SchemaEnumFieldDataArray_t* m_DataArray;
	void* unkn2;
	CSchemaSystemTypeScope* m_TypeScope;

	const char* GenerateTypeStorage()
	{
		const char* TypeStorage = nullptr;

		switch ( m_TypeSize )
		{
			case 1:
				TypeStorage = "uint8_t";
				break;
			case 2:
				TypeStorage = "uint16_t";
				break;
			case 4:
				TypeStorage = "uint32_t";
				break;
			case 8:
				TypeStorage = "uint64_t";
				break;
			default:
				TypeStorage = "INVALID_TYPE";;
				break;
		}

		return TypeStorage;
	}
};

class CSchemaType
{
public:
	void* ptable;
	char* szTypeName;
};

template <class T = CSchemaClassBinding>
class CSchemaList
{
public:
	class SchemaBlock
	{
	public:
		SchemaBlock* Next() const
		{
			return m_nextBlock;
		}
		T* GetBinding() const
		{
			return m_classBinding;
		}
	private:
		void* unkn0;
		SchemaBlock* m_nextBlock;
		T* m_classBinding;
	};

	class BlockContainer
	{
	public:
		SchemaBlock* GetFirstBlock() const
		{
			return m_firstBlock;
		}
	private:
		void* unkn[4];
		SchemaBlock* m_firstBlock;
	};

	typedef std::array<BlockContainer , 256> BlockContainers;

	int GetNumSchema()
	{
		return CUSTOM_OFFSET( int , -GeneratorOffset::GetNumSchema );
	}

	const BlockContainers& GetBlockContainers()
	{
		return CUSTOM_OFFSET( const BlockContainers , 0x0 );
	}
};

#pragma endregion

class CSchemaSystemTypeScope
{
public:
	CSchemaList<CSchemaClassBinding>* GetClassContainer()
	{
		return CUSTOM_OFFSET_RAW( CSchemaList<CSchemaClassBinding> , GeneratorOffset::GetClassContainer );
	}

public:
	CSchemaList<CSchemaEnumBinding>* GetEnumContainer()
	{
		return CUSTOM_OFFSET_RAW( CSchemaList<CSchemaEnumBinding> , GeneratorOffset::GetEnumContainer );
	}
};

namespace CSchemaSystem_Search
{
	inline CBasePattern GetAllTypeScopeFn = { VmpStr( "CSchemaSystem::GetAllTypeScope" ) , VmpStr( "48 8B 05 ? ? ? ? 48 8B D6 0F B7 CB 48 8B 3C C8" ) , SCHEMASYSTEM_DLL , 0 , SEARCH_TYPE_PTR2 };
}

class CSchemaSystem
{
public:
	auto GlobalTypeScope() -> CSchemaSystemTypeScope*
	{
		VirtualFn( CSchemaSystemTypeScope* )( CSchemaSystem* );
		return vget< Fn >( this , index::CSchemaSystem::GlobalTypeScope )( this );
	}

	auto GetAllTypeScope() -> CSchemaSystemTypeScope**
	{
		return *reinterpret_cast<CSchemaSystemTypeScope***>( CSchemaSystem_Search::GetAllTypeScopeFn.GetFunction() );
	}
};
