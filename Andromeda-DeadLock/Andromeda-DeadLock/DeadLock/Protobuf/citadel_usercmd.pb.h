// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: citadel_usercmd.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_citadel_5fusercmd_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_citadel_5fusercmd_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021008 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "networkbasetypes.pb.h"
#include "usercmd.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_citadel_5fusercmd_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_citadel_5fusercmd_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_citadel_5fusercmd_2eproto;
class CCitadelUserCmdPB;
struct CCitadelUserCmdPBDefaultTypeInternal;
extern CCitadelUserCmdPBDefaultTypeInternal _CCitadelUserCmdPB_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::CCitadelUserCmdPB* Arena::CreateMaybeMessage<::CCitadelUserCmdPB>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class CCitadelUserCmdPB final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:CCitadelUserCmdPB) */ {
 public:
  inline CCitadelUserCmdPB() : CCitadelUserCmdPB(nullptr) {}
  ~CCitadelUserCmdPB() override;
  explicit PROTOBUF_CONSTEXPR CCitadelUserCmdPB(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  CCitadelUserCmdPB(const CCitadelUserCmdPB& from);
  CCitadelUserCmdPB(CCitadelUserCmdPB&& from) noexcept
    : CCitadelUserCmdPB() {
    *this = ::std::move(from);
  }

  inline CCitadelUserCmdPB& operator=(const CCitadelUserCmdPB& from) {
    CopyFrom(from);
    return *this;
  }
  inline CCitadelUserCmdPB& operator=(CCitadelUserCmdPB&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CCitadelUserCmdPB& default_instance() {
    return *internal_default_instance();
  }
  static inline const CCitadelUserCmdPB* internal_default_instance() {
    return reinterpret_cast<const CCitadelUserCmdPB*>(
               &_CCitadelUserCmdPB_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(CCitadelUserCmdPB& a, CCitadelUserCmdPB& b) {
    a.Swap(&b);
  }
  inline void Swap(CCitadelUserCmdPB* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CCitadelUserCmdPB* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CCitadelUserCmdPB* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<CCitadelUserCmdPB>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const CCitadelUserCmdPB& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const CCitadelUserCmdPB& from) {
    CCitadelUserCmdPB::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CCitadelUserCmdPB* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "CCitadelUserCmdPB";
  }
  protected:
  explicit CCitadelUserCmdPB(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kViewDeltaXFieldNumber = 11,
    kViewDeltaYFieldNumber = 12,
    kBaseFieldNumber = 1,
    kVecCameraPositionFieldNumber = 2,
    kAngCameraAnglesFieldNumber = 3,
    kExecuteAbilityIndicesFieldNumber = 4,
    kCameraRoamingSpeedFieldNumber = 6,
    kInShopFieldNumber = 5,
    kUsingFreeCursorFieldNumber = 8,
    kEnemyHeroAimedAtFieldNumber = 10,
  };
  // repeated int32 view_delta_x = 11;
  int view_delta_x_size() const;
  private:
  int _internal_view_delta_x_size() const;
  public:
  void clear_view_delta_x();
  private:
  int32_t _internal_view_delta_x(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      _internal_view_delta_x() const;
  void _internal_add_view_delta_x(int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      _internal_mutable_view_delta_x();
  public:
  int32_t view_delta_x(int index) const;
  void set_view_delta_x(int index, int32_t value);
  void add_view_delta_x(int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      view_delta_x() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      mutable_view_delta_x();

  // repeated int32 view_delta_y = 12;
  int view_delta_y_size() const;
  private:
  int _internal_view_delta_y_size() const;
  public:
  void clear_view_delta_y();
  private:
  int32_t _internal_view_delta_y(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      _internal_view_delta_y() const;
  void _internal_add_view_delta_y(int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      _internal_mutable_view_delta_y();
  public:
  int32_t view_delta_y(int index) const;
  void set_view_delta_y(int index, int32_t value);
  void add_view_delta_y(int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      view_delta_y() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      mutable_view_delta_y();

  // optional .CBaseUserCmdPB base = 1;
  bool has_base() const;
  private:
  bool _internal_has_base() const;
  public:
  void clear_base();
  const ::CBaseUserCmdPB& base() const;
  PROTOBUF_NODISCARD ::CBaseUserCmdPB* release_base();
  ::CBaseUserCmdPB* mutable_base();
  void set_allocated_base(::CBaseUserCmdPB* base);
  private:
  const ::CBaseUserCmdPB& _internal_base() const;
  ::CBaseUserCmdPB* _internal_mutable_base();
  public:
  void unsafe_arena_set_allocated_base(
      ::CBaseUserCmdPB* base);
  ::CBaseUserCmdPB* unsafe_arena_release_base();

  // optional .CMsgVector vec_camera_position = 2;
  bool has_vec_camera_position() const;
  private:
  bool _internal_has_vec_camera_position() const;
  public:
  void clear_vec_camera_position();
  const ::CMsgVector& vec_camera_position() const;
  PROTOBUF_NODISCARD ::CMsgVector* release_vec_camera_position();
  ::CMsgVector* mutable_vec_camera_position();
  void set_allocated_vec_camera_position(::CMsgVector* vec_camera_position);
  private:
  const ::CMsgVector& _internal_vec_camera_position() const;
  ::CMsgVector* _internal_mutable_vec_camera_position();
  public:
  void unsafe_arena_set_allocated_vec_camera_position(
      ::CMsgVector* vec_camera_position);
  ::CMsgVector* unsafe_arena_release_vec_camera_position();

  // optional .CMsgQAngle ang_camera_angles = 3;
  bool has_ang_camera_angles() const;
  private:
  bool _internal_has_ang_camera_angles() const;
  public:
  void clear_ang_camera_angles();
  const ::CMsgQAngle& ang_camera_angles() const;
  PROTOBUF_NODISCARD ::CMsgQAngle* release_ang_camera_angles();
  ::CMsgQAngle* mutable_ang_camera_angles();
  void set_allocated_ang_camera_angles(::CMsgQAngle* ang_camera_angles);
  private:
  const ::CMsgQAngle& _internal_ang_camera_angles() const;
  ::CMsgQAngle* _internal_mutable_ang_camera_angles();
  public:
  void unsafe_arena_set_allocated_ang_camera_angles(
      ::CMsgQAngle* ang_camera_angles);
  ::CMsgQAngle* unsafe_arena_release_ang_camera_angles();

  // optional int32 execute_ability_indices = 4;
  bool has_execute_ability_indices() const;
  private:
  bool _internal_has_execute_ability_indices() const;
  public:
  void clear_execute_ability_indices();
  int32_t execute_ability_indices() const;
  void set_execute_ability_indices(int32_t value);
  private:
  int32_t _internal_execute_ability_indices() const;
  void _internal_set_execute_ability_indices(int32_t value);
  public:

  // optional float camera_roaming_speed = 6;
  bool has_camera_roaming_speed() const;
  private:
  bool _internal_has_camera_roaming_speed() const;
  public:
  void clear_camera_roaming_speed();
  float camera_roaming_speed() const;
  void set_camera_roaming_speed(float value);
  private:
  float _internal_camera_roaming_speed() const;
  void _internal_set_camera_roaming_speed(float value);
  public:

  // optional bool in_shop = 5;
  bool has_in_shop() const;
  private:
  bool _internal_has_in_shop() const;
  public:
  void clear_in_shop();
  bool in_shop() const;
  void set_in_shop(bool value);
  private:
  bool _internal_in_shop() const;
  void _internal_set_in_shop(bool value);
  public:

  // optional bool using_free_cursor = 8;
  bool has_using_free_cursor() const;
  private:
  bool _internal_has_using_free_cursor() const;
  public:
  void clear_using_free_cursor();
  bool using_free_cursor() const;
  void set_using_free_cursor(bool value);
  private:
  bool _internal_using_free_cursor() const;
  void _internal_set_using_free_cursor(bool value);
  public:

  // optional int32 enemy_hero_aimed_at = 10 [default = -1];
  bool has_enemy_hero_aimed_at() const;
  private:
  bool _internal_has_enemy_hero_aimed_at() const;
  public:
  void clear_enemy_hero_aimed_at();
  int32_t enemy_hero_aimed_at() const;
  void set_enemy_hero_aimed_at(int32_t value);
  private:
  int32_t _internal_enemy_hero_aimed_at() const;
  void _internal_set_enemy_hero_aimed_at(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:CCitadelUserCmdPB)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t > view_delta_x_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t > view_delta_y_;
    ::CBaseUserCmdPB* base_;
    ::CMsgVector* vec_camera_position_;
    ::CMsgQAngle* ang_camera_angles_;
    int32_t execute_ability_indices_;
    float camera_roaming_speed_;
    bool in_shop_;
    bool using_free_cursor_;
    int32_t enemy_hero_aimed_at_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_citadel_5fusercmd_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CCitadelUserCmdPB

// optional .CBaseUserCmdPB base = 1;
inline bool CCitadelUserCmdPB::_internal_has_base() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.base_ != nullptr);
  return value;
}
inline bool CCitadelUserCmdPB::has_base() const {
  return _internal_has_base();
}
inline const ::CBaseUserCmdPB& CCitadelUserCmdPB::_internal_base() const {
  const ::CBaseUserCmdPB* p = _impl_.base_;
  return p != nullptr ? *p : reinterpret_cast<const ::CBaseUserCmdPB&>(
      ::_CBaseUserCmdPB_default_instance_);
}
inline const ::CBaseUserCmdPB& CCitadelUserCmdPB::base() const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.base)
  return _internal_base();
}
inline void CCitadelUserCmdPB::unsafe_arena_set_allocated_base(
    ::CBaseUserCmdPB* base) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.base_);
  }
  _impl_.base_ = base;
  if (base) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:CCitadelUserCmdPB.base)
}
inline ::CBaseUserCmdPB* CCitadelUserCmdPB::release_base() {
  _impl_._has_bits_[0] &= ~0x00000001u;
  ::CBaseUserCmdPB* temp = _impl_.base_;
  _impl_.base_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::CBaseUserCmdPB* CCitadelUserCmdPB::unsafe_arena_release_base() {
  // @@protoc_insertion_point(field_release:CCitadelUserCmdPB.base)
  _impl_._has_bits_[0] &= ~0x00000001u;
  ::CBaseUserCmdPB* temp = _impl_.base_;
  _impl_.base_ = nullptr;
  return temp;
}
inline ::CBaseUserCmdPB* CCitadelUserCmdPB::_internal_mutable_base() {
  _impl_._has_bits_[0] |= 0x00000001u;
  if (_impl_.base_ == nullptr) {
    auto* p = CreateMaybeMessage<::CBaseUserCmdPB>(GetArenaForAllocation());
    _impl_.base_ = p;
  }
  return _impl_.base_;
}
inline ::CBaseUserCmdPB* CCitadelUserCmdPB::mutable_base() {
  ::CBaseUserCmdPB* _msg = _internal_mutable_base();
  // @@protoc_insertion_point(field_mutable:CCitadelUserCmdPB.base)
  return _msg;
}
inline void CCitadelUserCmdPB::set_allocated_base(::CBaseUserCmdPB* base) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.base_);
  }
  if (base) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(base));
    if (message_arena != submessage_arena) {
      base = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, base, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.base_ = base;
  // @@protoc_insertion_point(field_set_allocated:CCitadelUserCmdPB.base)
}

// optional .CMsgVector vec_camera_position = 2;
inline bool CCitadelUserCmdPB::_internal_has_vec_camera_position() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.vec_camera_position_ != nullptr);
  return value;
}
inline bool CCitadelUserCmdPB::has_vec_camera_position() const {
  return _internal_has_vec_camera_position();
}
inline const ::CMsgVector& CCitadelUserCmdPB::_internal_vec_camera_position() const {
  const ::CMsgVector* p = _impl_.vec_camera_position_;
  return p != nullptr ? *p : reinterpret_cast<const ::CMsgVector&>(
      ::_CMsgVector_default_instance_);
}
inline const ::CMsgVector& CCitadelUserCmdPB::vec_camera_position() const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.vec_camera_position)
  return _internal_vec_camera_position();
}
inline void CCitadelUserCmdPB::unsafe_arena_set_allocated_vec_camera_position(
    ::CMsgVector* vec_camera_position) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.vec_camera_position_);
  }
  _impl_.vec_camera_position_ = vec_camera_position;
  if (vec_camera_position) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:CCitadelUserCmdPB.vec_camera_position)
}
inline ::CMsgVector* CCitadelUserCmdPB::release_vec_camera_position() {
  _impl_._has_bits_[0] &= ~0x00000002u;
  ::CMsgVector* temp = _impl_.vec_camera_position_;
  _impl_.vec_camera_position_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::CMsgVector* CCitadelUserCmdPB::unsafe_arena_release_vec_camera_position() {
  // @@protoc_insertion_point(field_release:CCitadelUserCmdPB.vec_camera_position)
  _impl_._has_bits_[0] &= ~0x00000002u;
  ::CMsgVector* temp = _impl_.vec_camera_position_;
  _impl_.vec_camera_position_ = nullptr;
  return temp;
}
inline ::CMsgVector* CCitadelUserCmdPB::_internal_mutable_vec_camera_position() {
  _impl_._has_bits_[0] |= 0x00000002u;
  if (_impl_.vec_camera_position_ == nullptr) {
    auto* p = CreateMaybeMessage<::CMsgVector>(GetArenaForAllocation());
    _impl_.vec_camera_position_ = p;
  }
  return _impl_.vec_camera_position_;
}
inline ::CMsgVector* CCitadelUserCmdPB::mutable_vec_camera_position() {
  ::CMsgVector* _msg = _internal_mutable_vec_camera_position();
  // @@protoc_insertion_point(field_mutable:CCitadelUserCmdPB.vec_camera_position)
  return _msg;
}
inline void CCitadelUserCmdPB::set_allocated_vec_camera_position(::CMsgVector* vec_camera_position) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.vec_camera_position_);
  }
  if (vec_camera_position) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(vec_camera_position));
    if (message_arena != submessage_arena) {
      vec_camera_position = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, vec_camera_position, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.vec_camera_position_ = vec_camera_position;
  // @@protoc_insertion_point(field_set_allocated:CCitadelUserCmdPB.vec_camera_position)
}

// optional .CMsgQAngle ang_camera_angles = 3;
inline bool CCitadelUserCmdPB::_internal_has_ang_camera_angles() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.ang_camera_angles_ != nullptr);
  return value;
}
inline bool CCitadelUserCmdPB::has_ang_camera_angles() const {
  return _internal_has_ang_camera_angles();
}
inline const ::CMsgQAngle& CCitadelUserCmdPB::_internal_ang_camera_angles() const {
  const ::CMsgQAngle* p = _impl_.ang_camera_angles_;
  return p != nullptr ? *p : reinterpret_cast<const ::CMsgQAngle&>(
      ::_CMsgQAngle_default_instance_);
}
inline const ::CMsgQAngle& CCitadelUserCmdPB::ang_camera_angles() const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.ang_camera_angles)
  return _internal_ang_camera_angles();
}
inline void CCitadelUserCmdPB::unsafe_arena_set_allocated_ang_camera_angles(
    ::CMsgQAngle* ang_camera_angles) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.ang_camera_angles_);
  }
  _impl_.ang_camera_angles_ = ang_camera_angles;
  if (ang_camera_angles) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:CCitadelUserCmdPB.ang_camera_angles)
}
inline ::CMsgQAngle* CCitadelUserCmdPB::release_ang_camera_angles() {
  _impl_._has_bits_[0] &= ~0x00000004u;
  ::CMsgQAngle* temp = _impl_.ang_camera_angles_;
  _impl_.ang_camera_angles_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::CMsgQAngle* CCitadelUserCmdPB::unsafe_arena_release_ang_camera_angles() {
  // @@protoc_insertion_point(field_release:CCitadelUserCmdPB.ang_camera_angles)
  _impl_._has_bits_[0] &= ~0x00000004u;
  ::CMsgQAngle* temp = _impl_.ang_camera_angles_;
  _impl_.ang_camera_angles_ = nullptr;
  return temp;
}
inline ::CMsgQAngle* CCitadelUserCmdPB::_internal_mutable_ang_camera_angles() {
  _impl_._has_bits_[0] |= 0x00000004u;
  if (_impl_.ang_camera_angles_ == nullptr) {
    auto* p = CreateMaybeMessage<::CMsgQAngle>(GetArenaForAllocation());
    _impl_.ang_camera_angles_ = p;
  }
  return _impl_.ang_camera_angles_;
}
inline ::CMsgQAngle* CCitadelUserCmdPB::mutable_ang_camera_angles() {
  ::CMsgQAngle* _msg = _internal_mutable_ang_camera_angles();
  // @@protoc_insertion_point(field_mutable:CCitadelUserCmdPB.ang_camera_angles)
  return _msg;
}
inline void CCitadelUserCmdPB::set_allocated_ang_camera_angles(::CMsgQAngle* ang_camera_angles) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.ang_camera_angles_);
  }
  if (ang_camera_angles) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(ang_camera_angles));
    if (message_arena != submessage_arena) {
      ang_camera_angles = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, ang_camera_angles, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.ang_camera_angles_ = ang_camera_angles;
  // @@protoc_insertion_point(field_set_allocated:CCitadelUserCmdPB.ang_camera_angles)
}

// optional int32 execute_ability_indices = 4;
inline bool CCitadelUserCmdPB::_internal_has_execute_ability_indices() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool CCitadelUserCmdPB::has_execute_ability_indices() const {
  return _internal_has_execute_ability_indices();
}
inline void CCitadelUserCmdPB::clear_execute_ability_indices() {
  _impl_.execute_ability_indices_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline int32_t CCitadelUserCmdPB::_internal_execute_ability_indices() const {
  return _impl_.execute_ability_indices_;
}
inline int32_t CCitadelUserCmdPB::execute_ability_indices() const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.execute_ability_indices)
  return _internal_execute_ability_indices();
}
inline void CCitadelUserCmdPB::_internal_set_execute_ability_indices(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.execute_ability_indices_ = value;
}
inline void CCitadelUserCmdPB::set_execute_ability_indices(int32_t value) {
  _internal_set_execute_ability_indices(value);
  // @@protoc_insertion_point(field_set:CCitadelUserCmdPB.execute_ability_indices)
}

// optional bool in_shop = 5;
inline bool CCitadelUserCmdPB::_internal_has_in_shop() const {
  bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool CCitadelUserCmdPB::has_in_shop() const {
  return _internal_has_in_shop();
}
inline void CCitadelUserCmdPB::clear_in_shop() {
  _impl_.in_shop_ = false;
  _impl_._has_bits_[0] &= ~0x00000020u;
}
inline bool CCitadelUserCmdPB::_internal_in_shop() const {
  return _impl_.in_shop_;
}
inline bool CCitadelUserCmdPB::in_shop() const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.in_shop)
  return _internal_in_shop();
}
inline void CCitadelUserCmdPB::_internal_set_in_shop(bool value) {
  _impl_._has_bits_[0] |= 0x00000020u;
  _impl_.in_shop_ = value;
}
inline void CCitadelUserCmdPB::set_in_shop(bool value) {
  _internal_set_in_shop(value);
  // @@protoc_insertion_point(field_set:CCitadelUserCmdPB.in_shop)
}

// optional float camera_roaming_speed = 6;
inline bool CCitadelUserCmdPB::_internal_has_camera_roaming_speed() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool CCitadelUserCmdPB::has_camera_roaming_speed() const {
  return _internal_has_camera_roaming_speed();
}
inline void CCitadelUserCmdPB::clear_camera_roaming_speed() {
  _impl_.camera_roaming_speed_ = 0;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline float CCitadelUserCmdPB::_internal_camera_roaming_speed() const {
  return _impl_.camera_roaming_speed_;
}
inline float CCitadelUserCmdPB::camera_roaming_speed() const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.camera_roaming_speed)
  return _internal_camera_roaming_speed();
}
inline void CCitadelUserCmdPB::_internal_set_camera_roaming_speed(float value) {
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.camera_roaming_speed_ = value;
}
inline void CCitadelUserCmdPB::set_camera_roaming_speed(float value) {
  _internal_set_camera_roaming_speed(value);
  // @@protoc_insertion_point(field_set:CCitadelUserCmdPB.camera_roaming_speed)
}

// optional bool using_free_cursor = 8;
inline bool CCitadelUserCmdPB::_internal_has_using_free_cursor() const {
  bool value = (_impl_._has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool CCitadelUserCmdPB::has_using_free_cursor() const {
  return _internal_has_using_free_cursor();
}
inline void CCitadelUserCmdPB::clear_using_free_cursor() {
  _impl_.using_free_cursor_ = false;
  _impl_._has_bits_[0] &= ~0x00000040u;
}
inline bool CCitadelUserCmdPB::_internal_using_free_cursor() const {
  return _impl_.using_free_cursor_;
}
inline bool CCitadelUserCmdPB::using_free_cursor() const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.using_free_cursor)
  return _internal_using_free_cursor();
}
inline void CCitadelUserCmdPB::_internal_set_using_free_cursor(bool value) {
  _impl_._has_bits_[0] |= 0x00000040u;
  _impl_.using_free_cursor_ = value;
}
inline void CCitadelUserCmdPB::set_using_free_cursor(bool value) {
  _internal_set_using_free_cursor(value);
  // @@protoc_insertion_point(field_set:CCitadelUserCmdPB.using_free_cursor)
}

// optional int32 enemy_hero_aimed_at = 10 [default = -1];
inline bool CCitadelUserCmdPB::_internal_has_enemy_hero_aimed_at() const {
  bool value = (_impl_._has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool CCitadelUserCmdPB::has_enemy_hero_aimed_at() const {
  return _internal_has_enemy_hero_aimed_at();
}
inline void CCitadelUserCmdPB::clear_enemy_hero_aimed_at() {
  _impl_.enemy_hero_aimed_at_ = -1;
  _impl_._has_bits_[0] &= ~0x00000080u;
}
inline int32_t CCitadelUserCmdPB::_internal_enemy_hero_aimed_at() const {
  return _impl_.enemy_hero_aimed_at_;
}
inline int32_t CCitadelUserCmdPB::enemy_hero_aimed_at() const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.enemy_hero_aimed_at)
  return _internal_enemy_hero_aimed_at();
}
inline void CCitadelUserCmdPB::_internal_set_enemy_hero_aimed_at(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000080u;
  _impl_.enemy_hero_aimed_at_ = value;
}
inline void CCitadelUserCmdPB::set_enemy_hero_aimed_at(int32_t value) {
  _internal_set_enemy_hero_aimed_at(value);
  // @@protoc_insertion_point(field_set:CCitadelUserCmdPB.enemy_hero_aimed_at)
}

// repeated int32 view_delta_x = 11;
inline int CCitadelUserCmdPB::_internal_view_delta_x_size() const {
  return _impl_.view_delta_x_.size();
}
inline int CCitadelUserCmdPB::view_delta_x_size() const {
  return _internal_view_delta_x_size();
}
inline void CCitadelUserCmdPB::clear_view_delta_x() {
  _impl_.view_delta_x_.Clear();
}
inline int32_t CCitadelUserCmdPB::_internal_view_delta_x(int index) const {
  return _impl_.view_delta_x_.Get(index);
}
inline int32_t CCitadelUserCmdPB::view_delta_x(int index) const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.view_delta_x)
  return _internal_view_delta_x(index);
}
inline void CCitadelUserCmdPB::set_view_delta_x(int index, int32_t value) {
  _impl_.view_delta_x_.Set(index, value);
  // @@protoc_insertion_point(field_set:CCitadelUserCmdPB.view_delta_x)
}
inline void CCitadelUserCmdPB::_internal_add_view_delta_x(int32_t value) {
  _impl_.view_delta_x_.Add(value);
}
inline void CCitadelUserCmdPB::add_view_delta_x(int32_t value) {
  _internal_add_view_delta_x(value);
  // @@protoc_insertion_point(field_add:CCitadelUserCmdPB.view_delta_x)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
CCitadelUserCmdPB::_internal_view_delta_x() const {
  return _impl_.view_delta_x_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
CCitadelUserCmdPB::view_delta_x() const {
  // @@protoc_insertion_point(field_list:CCitadelUserCmdPB.view_delta_x)
  return _internal_view_delta_x();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
CCitadelUserCmdPB::_internal_mutable_view_delta_x() {
  return &_impl_.view_delta_x_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
CCitadelUserCmdPB::mutable_view_delta_x() {
  // @@protoc_insertion_point(field_mutable_list:CCitadelUserCmdPB.view_delta_x)
  return _internal_mutable_view_delta_x();
}

// repeated int32 view_delta_y = 12;
inline int CCitadelUserCmdPB::_internal_view_delta_y_size() const {
  return _impl_.view_delta_y_.size();
}
inline int CCitadelUserCmdPB::view_delta_y_size() const {
  return _internal_view_delta_y_size();
}
inline void CCitadelUserCmdPB::clear_view_delta_y() {
  _impl_.view_delta_y_.Clear();
}
inline int32_t CCitadelUserCmdPB::_internal_view_delta_y(int index) const {
  return _impl_.view_delta_y_.Get(index);
}
inline int32_t CCitadelUserCmdPB::view_delta_y(int index) const {
  // @@protoc_insertion_point(field_get:CCitadelUserCmdPB.view_delta_y)
  return _internal_view_delta_y(index);
}
inline void CCitadelUserCmdPB::set_view_delta_y(int index, int32_t value) {
  _impl_.view_delta_y_.Set(index, value);
  // @@protoc_insertion_point(field_set:CCitadelUserCmdPB.view_delta_y)
}
inline void CCitadelUserCmdPB::_internal_add_view_delta_y(int32_t value) {
  _impl_.view_delta_y_.Add(value);
}
inline void CCitadelUserCmdPB::add_view_delta_y(int32_t value) {
  _internal_add_view_delta_y(value);
  // @@protoc_insertion_point(field_add:CCitadelUserCmdPB.view_delta_y)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
CCitadelUserCmdPB::_internal_view_delta_y() const {
  return _impl_.view_delta_y_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
CCitadelUserCmdPB::view_delta_y() const {
  // @@protoc_insertion_point(field_list:CCitadelUserCmdPB.view_delta_y)
  return _internal_view_delta_y();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
CCitadelUserCmdPB::_internal_mutable_view_delta_y() {
  return &_impl_.view_delta_y_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
CCitadelUserCmdPB::mutable_view_delta_y() {
  // @@protoc_insertion_point(field_mutable_list:CCitadelUserCmdPB.view_delta_y)
  return _internal_mutable_view_delta_y();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_citadel_5fusercmd_2eproto