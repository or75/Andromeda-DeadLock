// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: prediction_events.proto

#include "prediction_events.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR CPredictionEvent_Teleport::CPredictionEvent_Teleport(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.origin_)*/nullptr
  , /*decltype(_impl_.angles_)*/nullptr
  , /*decltype(_impl_.drop_to_ground_range_)*/0} {}
struct CPredictionEvent_TeleportDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CPredictionEvent_TeleportDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CPredictionEvent_TeleportDefaultTypeInternal() {}
  union {
    CPredictionEvent_Teleport _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CPredictionEvent_TeleportDefaultTypeInternal _CPredictionEvent_Teleport_default_instance_;
PROTOBUF_CONSTEXPR CPredictionEvent_StringCommand::CPredictionEvent_StringCommand(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.command_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}} {}
struct CPredictionEvent_StringCommandDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CPredictionEvent_StringCommandDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CPredictionEvent_StringCommandDefaultTypeInternal() {}
  union {
    CPredictionEvent_StringCommand _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CPredictionEvent_StringCommandDefaultTypeInternal _CPredictionEvent_StringCommand_default_instance_;
static ::_pb::Metadata file_level_metadata_prediction_5fevents_2eproto[2];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_prediction_5fevents_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_prediction_5fevents_2eproto = nullptr;

const uint32_t TableStruct_prediction_5fevents_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::CPredictionEvent_Teleport, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::CPredictionEvent_Teleport, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::CPredictionEvent_Teleport, _impl_.origin_),
  PROTOBUF_FIELD_OFFSET(::CPredictionEvent_Teleport, _impl_.angles_),
  PROTOBUF_FIELD_OFFSET(::CPredictionEvent_Teleport, _impl_.drop_to_ground_range_),
  0,
  1,
  2,
  PROTOBUF_FIELD_OFFSET(::CPredictionEvent_StringCommand, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::CPredictionEvent_StringCommand, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::CPredictionEvent_StringCommand, _impl_.command_),
  0,
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, -1, sizeof(::CPredictionEvent_Teleport)},
  { 12, 19, -1, sizeof(::CPredictionEvent_StringCommand)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_CPredictionEvent_Teleport_default_instance_._instance,
  &::_CPredictionEvent_StringCommand_default_instance_._instance,
};

const char descriptor_table_protodef_prediction_5fevents_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\027prediction_events.proto\032\026networkbasety"
  "pes.proto\"s\n\031CPredictionEvent_Teleport\022\033"
  "\n\006origin\030\001 \001(\0132\013.CMsgVector\022\033\n\006angles\030\002 "
  "\001(\0132\013.CMsgQAngle\022\034\n\024drop_to_ground_range"
  "\030\003 \001(\002\"1\n\036CPredictionEvent_StringCommand"
  "\022\017\n\007command\030\001 \001(\t*B\n\025EBasePredictionEven"
  "ts\022\026\n\021BPE_StringCommand\020\200\001\022\021\n\014BPE_Telepo"
  "rt\020\202\001"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_prediction_5fevents_2eproto_deps[1] = {
  &::descriptor_table_networkbasetypes_2eproto,
};
static ::_pbi::once_flag descriptor_table_prediction_5fevents_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_prediction_5fevents_2eproto = {
    false, false, 285, descriptor_table_protodef_prediction_5fevents_2eproto,
    "prediction_events.proto",
    &descriptor_table_prediction_5fevents_2eproto_once, descriptor_table_prediction_5fevents_2eproto_deps, 1, 2,
    schemas, file_default_instances, TableStruct_prediction_5fevents_2eproto::offsets,
    file_level_metadata_prediction_5fevents_2eproto, file_level_enum_descriptors_prediction_5fevents_2eproto,
    file_level_service_descriptors_prediction_5fevents_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_prediction_5fevents_2eproto_getter() {
  return &descriptor_table_prediction_5fevents_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_prediction_5fevents_2eproto(&descriptor_table_prediction_5fevents_2eproto);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* EBasePredictionEvents_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_prediction_5fevents_2eproto);
  return file_level_enum_descriptors_prediction_5fevents_2eproto[0];
}
bool EBasePredictionEvents_IsValid(int value) {
  switch (value) {
    case 128:
    case 130:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class CPredictionEvent_Teleport::_Internal {
 public:
  using HasBits = decltype(std::declval<CPredictionEvent_Teleport>()._impl_._has_bits_);
  static const ::CMsgVector& origin(const CPredictionEvent_Teleport* msg);
  static void set_has_origin(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static const ::CMsgQAngle& angles(const CPredictionEvent_Teleport* msg);
  static void set_has_angles(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_drop_to_ground_range(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

const ::CMsgVector&
CPredictionEvent_Teleport::_Internal::origin(const CPredictionEvent_Teleport* msg) {
  return *msg->_impl_.origin_;
}
const ::CMsgQAngle&
CPredictionEvent_Teleport::_Internal::angles(const CPredictionEvent_Teleport* msg) {
  return *msg->_impl_.angles_;
}
void CPredictionEvent_Teleport::clear_origin() {
  if (_impl_.origin_ != nullptr) _impl_.origin_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
void CPredictionEvent_Teleport::clear_angles() {
  if (_impl_.angles_ != nullptr) _impl_.angles_->Clear();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
CPredictionEvent_Teleport::CPredictionEvent_Teleport(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:CPredictionEvent_Teleport)
}
CPredictionEvent_Teleport::CPredictionEvent_Teleport(const CPredictionEvent_Teleport& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  CPredictionEvent_Teleport* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.origin_){nullptr}
    , decltype(_impl_.angles_){nullptr}
    , decltype(_impl_.drop_to_ground_range_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_origin()) {
    _this->_impl_.origin_ = new ::CMsgVector(*from._impl_.origin_);
  }
  if (from._internal_has_angles()) {
    _this->_impl_.angles_ = new ::CMsgQAngle(*from._impl_.angles_);
  }
  _this->_impl_.drop_to_ground_range_ = from._impl_.drop_to_ground_range_;
  // @@protoc_insertion_point(copy_constructor:CPredictionEvent_Teleport)
}

inline void CPredictionEvent_Teleport::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.origin_){nullptr}
    , decltype(_impl_.angles_){nullptr}
    , decltype(_impl_.drop_to_ground_range_){0}
  };
}

CPredictionEvent_Teleport::~CPredictionEvent_Teleport() {
  // @@protoc_insertion_point(destructor:CPredictionEvent_Teleport)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CPredictionEvent_Teleport::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.origin_;
  if (this != internal_default_instance()) delete _impl_.angles_;
}

void CPredictionEvent_Teleport::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CPredictionEvent_Teleport::Clear() {
// @@protoc_insertion_point(message_clear_start:CPredictionEvent_Teleport)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(_impl_.origin_ != nullptr);
      _impl_.origin_->Clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(_impl_.angles_ != nullptr);
      _impl_.angles_->Clear();
    }
  }
  _impl_.drop_to_ground_range_ = 0;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CPredictionEvent_Teleport::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional .CMsgVector origin = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_origin(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional .CMsgQAngle angles = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_angles(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional float drop_to_ground_range = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 29)) {
          _Internal::set_has_drop_to_ground_range(&has_bits);
          _impl_.drop_to_ground_range_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* CPredictionEvent_Teleport::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CPredictionEvent_Teleport)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional .CMsgVector origin = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::origin(this),
        _Internal::origin(this).GetCachedSize(), target, stream);
  }

  // optional .CMsgQAngle angles = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::angles(this),
        _Internal::angles(this).GetCachedSize(), target, stream);
  }

  // optional float drop_to_ground_range = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(3, this->_internal_drop_to_ground_range(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CPredictionEvent_Teleport)
  return target;
}

size_t CPredictionEvent_Teleport::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CPredictionEvent_Teleport)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional .CMsgVector origin = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *_impl_.origin_);
    }

    // optional .CMsgQAngle angles = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *_impl_.angles_);
    }

    // optional float drop_to_ground_range = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 + 4;
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CPredictionEvent_Teleport::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CPredictionEvent_Teleport::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CPredictionEvent_Teleport::GetClassData() const { return &_class_data_; }


void CPredictionEvent_Teleport::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CPredictionEvent_Teleport*>(&to_msg);
  auto& from = static_cast<const CPredictionEvent_Teleport&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:CPredictionEvent_Teleport)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_mutable_origin()->::CMsgVector::MergeFrom(
          from._internal_origin());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_mutable_angles()->::CMsgQAngle::MergeFrom(
          from._internal_angles());
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.drop_to_ground_range_ = from._impl_.drop_to_ground_range_;
    }
    _this->_impl_._has_bits_[0] |= cached_has_bits;
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CPredictionEvent_Teleport::CopyFrom(const CPredictionEvent_Teleport& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CPredictionEvent_Teleport)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CPredictionEvent_Teleport::IsInitialized() const {
  return true;
}

void CPredictionEvent_Teleport::InternalSwap(CPredictionEvent_Teleport* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(CPredictionEvent_Teleport, _impl_.drop_to_ground_range_)
      + sizeof(CPredictionEvent_Teleport::_impl_.drop_to_ground_range_)
      - PROTOBUF_FIELD_OFFSET(CPredictionEvent_Teleport, _impl_.origin_)>(
          reinterpret_cast<char*>(&_impl_.origin_),
          reinterpret_cast<char*>(&other->_impl_.origin_));
}

::PROTOBUF_NAMESPACE_ID::Metadata CPredictionEvent_Teleport::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_prediction_5fevents_2eproto_getter, &descriptor_table_prediction_5fevents_2eproto_once,
      file_level_metadata_prediction_5fevents_2eproto[0]);
}

// ===================================================================

class CPredictionEvent_StringCommand::_Internal {
 public:
  using HasBits = decltype(std::declval<CPredictionEvent_StringCommand>()._impl_._has_bits_);
  static void set_has_command(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

CPredictionEvent_StringCommand::CPredictionEvent_StringCommand(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:CPredictionEvent_StringCommand)
}
CPredictionEvent_StringCommand::CPredictionEvent_StringCommand(const CPredictionEvent_StringCommand& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  CPredictionEvent_StringCommand* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.command_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.command_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.command_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_command()) {
    _this->_impl_.command_.Set(from._internal_command(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:CPredictionEvent_StringCommand)
}

inline void CPredictionEvent_StringCommand::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.command_){}
  };
  _impl_.command_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.command_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

CPredictionEvent_StringCommand::~CPredictionEvent_StringCommand() {
  // @@protoc_insertion_point(destructor:CPredictionEvent_StringCommand)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void CPredictionEvent_StringCommand::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.command_.Destroy();
}

void CPredictionEvent_StringCommand::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void CPredictionEvent_StringCommand::Clear() {
// @@protoc_insertion_point(message_clear_start:CPredictionEvent_StringCommand)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.command_.ClearNonDefaultToEmpty();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CPredictionEvent_StringCommand::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional string command = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_command();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          #ifndef NDEBUG
          ::_pbi::VerifyUTF8(str, "CPredictionEvent_StringCommand.command");
          #endif  // !NDEBUG
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* CPredictionEvent_StringCommand::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CPredictionEvent_StringCommand)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional string command = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_command().data(), static_cast<int>(this->_internal_command().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "CPredictionEvent_StringCommand.command");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_command(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CPredictionEvent_StringCommand)
  return target;
}

size_t CPredictionEvent_StringCommand::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CPredictionEvent_StringCommand)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional string command = 1;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_command());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CPredictionEvent_StringCommand::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    CPredictionEvent_StringCommand::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CPredictionEvent_StringCommand::GetClassData() const { return &_class_data_; }


void CPredictionEvent_StringCommand::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<CPredictionEvent_StringCommand*>(&to_msg);
  auto& from = static_cast<const CPredictionEvent_StringCommand&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:CPredictionEvent_StringCommand)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_command()) {
    _this->_internal_set_command(from._internal_command());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CPredictionEvent_StringCommand::CopyFrom(const CPredictionEvent_StringCommand& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CPredictionEvent_StringCommand)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CPredictionEvent_StringCommand::IsInitialized() const {
  return true;
}

void CPredictionEvent_StringCommand::InternalSwap(CPredictionEvent_StringCommand* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.command_, lhs_arena,
      &other->_impl_.command_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata CPredictionEvent_StringCommand::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_prediction_5fevents_2eproto_getter, &descriptor_table_prediction_5fevents_2eproto_once,
      file_level_metadata_prediction_5fevents_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::CPredictionEvent_Teleport*
Arena::CreateMaybeMessage< ::CPredictionEvent_Teleport >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CPredictionEvent_Teleport >(arena);
}
template<> PROTOBUF_NOINLINE ::CPredictionEvent_StringCommand*
Arena::CreateMaybeMessage< ::CPredictionEvent_StringCommand >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CPredictionEvent_StringCommand >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
