#pragma once

#include <stdint.h>

#if defined(__x86_64__) || defined(_WIN64)
#define X64BITS
#endif

typedef unsigned char uint8;
typedef signed char int8;
typedef float float32;

#if defined( _WIN32 )

typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int32 int32;
typedef unsigned __int32 uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;

typedef uint32 uint;
typedef int64 lint64;
typedef uint64 ulint64;

#ifdef X64BITS
typedef __int64 intp;
typedef unsigned __int64 uintp;
#else
typedef __int32 intp;
typedef unsigned __int32 uintp;
#endif

#else // _WIN32

#ifdef X64BITS
typedef long long intp;
typedef unsigned long long uintp;
#else
typedef int intp;
typedef unsigned int uintp;
#endif

#endif

struct bf_read;
struct bf_write;

using CEntityIndex = int;
using CGlobalSymbol = const char*;

#define C_NetworkUtlVectorBase CUtlVector
#define C_UtlVectorEmbeddedNetworkVar CUtlVector
#define CNetworkViewOffsetVector Vector3

struct ResourceBindingBase_t
{
	void* data;
};

enum MoveType_t : uint8_t
{
    MOVETYPE_NONE = 0x00 ,
    MOVETYPE_OBSOLETE = 0x01 ,
    MOVETYPE_WALK = 0x02 ,
    MOVETYPE_FLY = 0x03 ,
    MOVETYPE_FLYGRAVITY = 0x04 ,
    MOVETYPE_VPHYSICS = 0x05 ,
    MOVETYPE_PUSH = 0x06 ,
    MOVETYPE_NOCLIP = 0x07 ,
    MOVETYPE_OBSERVER = 0x08 ,
    MOVETYPE_STEP = 0x09 ,
    MOVETYPE_SYNC = 0x0A ,
    MOVETYPE_CUSTOM = 0x0B ,
    MOVETYPE_LAST = 0x0C ,
    MOVETYPE_INVALID = 0x0C ,
    MOVETYPE_MAX_BITS = 0x05 ,
};

enum EBoneFlags : uint32_t
{
    FLAG_NO_BONE_FLAGS = 0x0 ,
    FLAG_BONEFLEXDRIVER = 0x4 ,
    FLAG_CLOTH = 0x8 ,
    FLAG_PHYSICS = 0x10 ,
    FLAG_ATTACHMENT = 0x20 ,
    FLAG_ANIMATION = 0x40 ,
    FLAG_MESH = 0x80 ,
    FLAG_HITBOX = 0x100 ,
    FLAG_BONE_USED_BY_VERTEX_LOD0 = 0x400 ,
    FLAG_BONE_USED_BY_VERTEX_LOD1 = 0x800 ,
    FLAG_BONE_USED_BY_VERTEX_LOD2 = 0x1000 ,
    FLAG_BONE_USED_BY_VERTEX_LOD3 = 0x2000 ,
    FLAG_BONE_USED_BY_VERTEX_LOD4 = 0x4000 ,
    FLAG_BONE_USED_BY_VERTEX_LOD5 = 0x8000 ,
    FLAG_BONE_USED_BY_VERTEX_LOD6 = 0x10000 ,
    FLAG_BONE_USED_BY_VERTEX_LOD7 = 0x20000 ,
    FLAG_BONE_MERGE_READ = 0x40000 ,
    FLAG_BONE_MERGE_WRITE = 0x80000 ,
    FLAG_ALL_BONE_FLAGS = 0xfffff ,
    BLEND_PREALIGNED = 0x100000 ,
    FLAG_RIGIDLENGTH = 0x200000 ,
    FLAG_PROCEDURAL = 0x400000 ,
};
