// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: .proto

#ifndef GOOGLE_PROTOBUF_INCLUDED__2eproto
#define GOOGLE_PROTOBUF_INCLUDED__2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT__2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct__2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table__2eproto;
namespace MyNameSpace {
class FullName;
struct FullNameDefaultTypeInternal;
extern FullNameDefaultTypeInternal _FullName_default_instance_;
class Student;
struct StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
class StudentsGroup;
struct StudentsGroupDefaultTypeInternal;
extern StudentsGroupDefaultTypeInternal _StudentsGroup_default_instance_;
}  // namespace MyNameSpace
PROTOBUF_NAMESPACE_OPEN
template<> ::MyNameSpace::FullName* Arena::CreateMaybeMessage<::MyNameSpace::FullName>(Arena*);
template<> ::MyNameSpace::Student* Arena::CreateMaybeMessage<::MyNameSpace::Student>(Arena*);
template<> ::MyNameSpace::StudentsGroup* Arena::CreateMaybeMessage<::MyNameSpace::StudentsGroup>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace MyNameSpace {

// ===================================================================

class FullName final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:MyNameSpace.FullName) */ {
 public:
  inline FullName() : FullName(nullptr) {}
  ~FullName() override;
  explicit constexpr FullName(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FullName(const FullName& from);
  FullName(FullName&& from) noexcept
    : FullName() {
    *this = ::std::move(from);
  }

  inline FullName& operator=(const FullName& from) {
    CopyFrom(from);
    return *this;
  }
  inline FullName& operator=(FullName&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
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
  static const FullName& default_instance() {
    return *internal_default_instance();
  }
  static inline const FullName* internal_default_instance() {
    return reinterpret_cast<const FullName*>(
               &_FullName_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FullName& a, FullName& b) {
    a.Swap(&b);
  }
  inline void Swap(FullName* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FullName* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FullName* New() const final {
    return new FullName();
  }

  FullName* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FullName>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FullName& from);
  void MergeFrom(const FullName& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FullName* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "MyNameSpace.FullName";
  }
  protected:
  explicit FullName(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kMiddleNameFieldNumber = 2,
    kLastNameFieldNumber = 3,
  };
  // string Name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // optional string MiddleName = 2;
  bool has_middlename() const;
  private:
  bool _internal_has_middlename() const;
  public:
  void clear_middlename();
  const std::string& middlename() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_middlename(ArgT0&& arg0, ArgT... args);
  std::string* mutable_middlename();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_middlename();
  void set_allocated_middlename(std::string* middlename);
  private:
  const std::string& _internal_middlename() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_middlename(const std::string& value);
  std::string* _internal_mutable_middlename();
  public:

  // string LastName = 3;
  void clear_lastname();
  const std::string& lastname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_lastname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_lastname();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_lastname();
  void set_allocated_lastname(std::string* lastname);
  private:
  const std::string& _internal_lastname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_lastname(const std::string& value);
  std::string* _internal_mutable_lastname();
  public:

  // @@protoc_insertion_point(class_scope:MyNameSpace.FullName)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr middlename_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr lastname_;
  friend struct ::TableStruct__2eproto;
};
// -------------------------------------------------------------------

class Student final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:MyNameSpace.Student) */ {
 public:
  inline Student() : Student(nullptr) {}
  ~Student() override;
  explicit constexpr Student(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Student(const Student& from);
  Student(Student&& from) noexcept
    : Student() {
    *this = ::std::move(from);
  }

  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student& operator=(Student&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
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
  static const Student& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
               &_Student_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Student& a, Student& b) {
    a.Swap(&b);
  }
  inline void Swap(Student* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Student* New() const final {
    return new Student();
  }

  Student* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Student>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Student& from);
  void MergeFrom(const Student& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "MyNameSpace.Student";
  }
  protected:
  explicit Student(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRatingsMapFieldNumber = 2,
    kNameStudentFieldNumber = 1,
    kGpaFieldNumber = 3,
  };
  // repeated int32 ratingsMap = 2 [packed = true];
  int ratingsmap_size() const;
  private:
  int _internal_ratingsmap_size() const;
  public:
  void clear_ratingsmap();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_ratingsmap(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_ratingsmap() const;
  void _internal_add_ratingsmap(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_ratingsmap();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 ratingsmap(int index) const;
  void set_ratingsmap(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_ratingsmap(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      ratingsmap() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_ratingsmap();

  // .MyNameSpace.FullName nameStudent = 1;
  bool has_namestudent() const;
  private:
  bool _internal_has_namestudent() const;
  public:
  void clear_namestudent();
  const ::MyNameSpace::FullName& namestudent() const;
  PROTOBUF_FUTURE_MUST_USE_RESULT ::MyNameSpace::FullName* release_namestudent();
  ::MyNameSpace::FullName* mutable_namestudent();
  void set_allocated_namestudent(::MyNameSpace::FullName* namestudent);
  private:
  const ::MyNameSpace::FullName& _internal_namestudent() const;
  ::MyNameSpace::FullName* _internal_mutable_namestudent();
  public:
  void unsafe_arena_set_allocated_namestudent(
      ::MyNameSpace::FullName* namestudent);
  ::MyNameSpace::FullName* unsafe_arena_release_namestudent();

  // int32 gpa = 3;
  void clear_gpa();
  ::PROTOBUF_NAMESPACE_ID::int32 gpa() const;
  void set_gpa(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_gpa() const;
  void _internal_set_gpa(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:MyNameSpace.Student)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > ratingsmap_;
  mutable std::atomic<int> _ratingsmap_cached_byte_size_;
  ::MyNameSpace::FullName* namestudent_;
  ::PROTOBUF_NAMESPACE_ID::int32 gpa_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct__2eproto;
};
// -------------------------------------------------------------------

class StudentsGroup final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:MyNameSpace.StudentsGroup) */ {
 public:
  inline StudentsGroup() : StudentsGroup(nullptr) {}
  ~StudentsGroup() override;
  explicit constexpr StudentsGroup(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StudentsGroup(const StudentsGroup& from);
  StudentsGroup(StudentsGroup&& from) noexcept
    : StudentsGroup() {
    *this = ::std::move(from);
  }

  inline StudentsGroup& operator=(const StudentsGroup& from) {
    CopyFrom(from);
    return *this;
  }
  inline StudentsGroup& operator=(StudentsGroup&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
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
  static const StudentsGroup& default_instance() {
    return *internal_default_instance();
  }
  static inline const StudentsGroup* internal_default_instance() {
    return reinterpret_cast<const StudentsGroup*>(
               &_StudentsGroup_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(StudentsGroup& a, StudentsGroup& b) {
    a.Swap(&b);
  }
  inline void Swap(StudentsGroup* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StudentsGroup* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline StudentsGroup* New() const final {
    return new StudentsGroup();
  }

  StudentsGroup* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<StudentsGroup>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const StudentsGroup& from);
  void MergeFrom(const StudentsGroup& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StudentsGroup* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "MyNameSpace.StudentsGroup";
  }
  protected:
  explicit StudentsGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStudentMapFieldNumber = 1,
  };
  // repeated .MyNameSpace.Student studentMap = 1;
  int studentmap_size() const;
  private:
  int _internal_studentmap_size() const;
  public:
  void clear_studentmap();
  ::MyNameSpace::Student* mutable_studentmap(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::MyNameSpace::Student >*
      mutable_studentmap();
  private:
  const ::MyNameSpace::Student& _internal_studentmap(int index) const;
  ::MyNameSpace::Student* _internal_add_studentmap();
  public:
  const ::MyNameSpace::Student& studentmap(int index) const;
  ::MyNameSpace::Student* add_studentmap();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::MyNameSpace::Student >&
      studentmap() const;

  // @@protoc_insertion_point(class_scope:MyNameSpace.StudentsGroup)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::MyNameSpace::Student > studentmap_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct__2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FullName

// string Name = 1;
inline void FullName::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& FullName::name() const {
  // @@protoc_insertion_point(field_get:MyNameSpace.FullName.Name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:MyNameSpace.FullName.Name)
}
inline std::string* FullName::mutable_name() {
  // @@protoc_insertion_point(field_mutable:MyNameSpace.FullName.Name)
  return _internal_mutable_name();
}
inline const std::string& FullName::_internal_name() const {
  return name_.Get();
}
inline void FullName::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_name() {
  // @@protoc_insertion_point(field_release:MyNameSpace.FullName.Name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FullName::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:MyNameSpace.FullName.Name)
}

// optional string MiddleName = 2;
inline bool FullName::_internal_has_middlename() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool FullName::has_middlename() const {
  return _internal_has_middlename();
}
inline void FullName::clear_middlename() {
  middlename_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& FullName::middlename() const {
  // @@protoc_insertion_point(field_get:MyNameSpace.FullName.MiddleName)
  return _internal_middlename();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_middlename(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 middlename_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:MyNameSpace.FullName.MiddleName)
}
inline std::string* FullName::mutable_middlename() {
  // @@protoc_insertion_point(field_mutable:MyNameSpace.FullName.MiddleName)
  return _internal_mutable_middlename();
}
inline const std::string& FullName::_internal_middlename() const {
  return middlename_.Get();
}
inline void FullName::_internal_set_middlename(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  middlename_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_middlename() {
  _has_bits_[0] |= 0x00000001u;
  return middlename_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_middlename() {
  // @@protoc_insertion_point(field_release:MyNameSpace.FullName.MiddleName)
  if (!_internal_has_middlename()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return middlename_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FullName::set_allocated_middlename(std::string* middlename) {
  if (middlename != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  middlename_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), middlename,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:MyNameSpace.FullName.MiddleName)
}

// string LastName = 3;
inline void FullName::clear_lastname() {
  lastname_.ClearToEmpty();
}
inline const std::string& FullName::lastname() const {
  // @@protoc_insertion_point(field_get:MyNameSpace.FullName.LastName)
  return _internal_lastname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_lastname(ArgT0&& arg0, ArgT... args) {
 
 lastname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:MyNameSpace.FullName.LastName)
}
inline std::string* FullName::mutable_lastname() {
  // @@protoc_insertion_point(field_mutable:MyNameSpace.FullName.LastName)
  return _internal_mutable_lastname();
}
inline const std::string& FullName::_internal_lastname() const {
  return lastname_.Get();
}
inline void FullName::_internal_set_lastname(const std::string& value) {
  
  lastname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_lastname() {
  
  return lastname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_lastname() {
  // @@protoc_insertion_point(field_release:MyNameSpace.FullName.LastName)
  return lastname_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FullName::set_allocated_lastname(std::string* lastname) {
  if (lastname != nullptr) {
    
  } else {
    
  }
  lastname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), lastname,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:MyNameSpace.FullName.LastName)
}

// -------------------------------------------------------------------

// Student

// .MyNameSpace.FullName nameStudent = 1;
inline bool Student::_internal_has_namestudent() const {
  return this != internal_default_instance() && namestudent_ != nullptr;
}
inline bool Student::has_namestudent() const {
  return _internal_has_namestudent();
}
inline void Student::clear_namestudent() {
  if (GetArenaForAllocation() == nullptr && namestudent_ != nullptr) {
    delete namestudent_;
  }
  namestudent_ = nullptr;
}
inline const ::MyNameSpace::FullName& Student::_internal_namestudent() const {
  const ::MyNameSpace::FullName* p = namestudent_;
  return p != nullptr ? *p : reinterpret_cast<const ::MyNameSpace::FullName&>(
      ::MyNameSpace::_FullName_default_instance_);
}
inline const ::MyNameSpace::FullName& Student::namestudent() const {
  // @@protoc_insertion_point(field_get:MyNameSpace.Student.nameStudent)
  return _internal_namestudent();
}
inline void Student::unsafe_arena_set_allocated_namestudent(
    ::MyNameSpace::FullName* namestudent) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(namestudent_);
  }
  namestudent_ = namestudent;
  if (namestudent) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:MyNameSpace.Student.nameStudent)
}
inline ::MyNameSpace::FullName* Student::release_namestudent() {
  
  ::MyNameSpace::FullName* temp = namestudent_;
  namestudent_ = nullptr;
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::MyNameSpace::FullName* Student::unsafe_arena_release_namestudent() {
  // @@protoc_insertion_point(field_release:MyNameSpace.Student.nameStudent)
  
  ::MyNameSpace::FullName* temp = namestudent_;
  namestudent_ = nullptr;
  return temp;
}
inline ::MyNameSpace::FullName* Student::_internal_mutable_namestudent() {
  
  if (namestudent_ == nullptr) {
    auto* p = CreateMaybeMessage<::MyNameSpace::FullName>(GetArenaForAllocation());
    namestudent_ = p;
  }
  return namestudent_;
}
inline ::MyNameSpace::FullName* Student::mutable_namestudent() {
  // @@protoc_insertion_point(field_mutable:MyNameSpace.Student.nameStudent)
  return _internal_mutable_namestudent();
}
inline void Student::set_allocated_namestudent(::MyNameSpace::FullName* namestudent) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete namestudent_;
  }
  if (namestudent) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::MyNameSpace::FullName>::GetOwningArena(namestudent);
    if (message_arena != submessage_arena) {
      namestudent = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, namestudent, submessage_arena);
    }
    
  } else {
    
  }
  namestudent_ = namestudent;
  // @@protoc_insertion_point(field_set_allocated:MyNameSpace.Student.nameStudent)
}

// repeated int32 ratingsMap = 2 [packed = true];
inline int Student::_internal_ratingsmap_size() const {
  return ratingsmap_.size();
}
inline int Student::ratingsmap_size() const {
  return _internal_ratingsmap_size();
}
inline void Student::clear_ratingsmap() {
  ratingsmap_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Student::_internal_ratingsmap(int index) const {
  return ratingsmap_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Student::ratingsmap(int index) const {
  // @@protoc_insertion_point(field_get:MyNameSpace.Student.ratingsMap)
  return _internal_ratingsmap(index);
}
inline void Student::set_ratingsmap(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  ratingsmap_.Set(index, value);
  // @@protoc_insertion_point(field_set:MyNameSpace.Student.ratingsMap)
}
inline void Student::_internal_add_ratingsmap(::PROTOBUF_NAMESPACE_ID::int32 value) {
  ratingsmap_.Add(value);
}
inline void Student::add_ratingsmap(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_ratingsmap(value);
  // @@protoc_insertion_point(field_add:MyNameSpace.Student.ratingsMap)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
Student::_internal_ratingsmap() const {
  return ratingsmap_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
Student::ratingsmap() const {
  // @@protoc_insertion_point(field_list:MyNameSpace.Student.ratingsMap)
  return _internal_ratingsmap();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
Student::_internal_mutable_ratingsmap() {
  return &ratingsmap_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
Student::mutable_ratingsmap() {
  // @@protoc_insertion_point(field_mutable_list:MyNameSpace.Student.ratingsMap)
  return _internal_mutable_ratingsmap();
}

// int32 gpa = 3;
inline void Student::clear_gpa() {
  gpa_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Student::_internal_gpa() const {
  return gpa_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Student::gpa() const {
  // @@protoc_insertion_point(field_get:MyNameSpace.Student.gpa)
  return _internal_gpa();
}
inline void Student::_internal_set_gpa(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  gpa_ = value;
}
inline void Student::set_gpa(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_gpa(value);
  // @@protoc_insertion_point(field_set:MyNameSpace.Student.gpa)
}

// -------------------------------------------------------------------

// StudentsGroup

// repeated .MyNameSpace.Student studentMap = 1;
inline int StudentsGroup::_internal_studentmap_size() const {
  return studentmap_.size();
}
inline int StudentsGroup::studentmap_size() const {
  return _internal_studentmap_size();
}
inline void StudentsGroup::clear_studentmap() {
  studentmap_.Clear();
}
inline ::MyNameSpace::Student* StudentsGroup::mutable_studentmap(int index) {
  // @@protoc_insertion_point(field_mutable:MyNameSpace.StudentsGroup.studentMap)
  return studentmap_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::MyNameSpace::Student >*
StudentsGroup::mutable_studentmap() {
  // @@protoc_insertion_point(field_mutable_list:MyNameSpace.StudentsGroup.studentMap)
  return &studentmap_;
}
inline const ::MyNameSpace::Student& StudentsGroup::_internal_studentmap(int index) const {
  return studentmap_.Get(index);
}
inline const ::MyNameSpace::Student& StudentsGroup::studentmap(int index) const {
  // @@protoc_insertion_point(field_get:MyNameSpace.StudentsGroup.studentMap)
  return _internal_studentmap(index);
}
inline ::MyNameSpace::Student* StudentsGroup::_internal_add_studentmap() {
  return studentmap_.Add();
}
inline ::MyNameSpace::Student* StudentsGroup::add_studentmap() {
  // @@protoc_insertion_point(field_add:MyNameSpace.StudentsGroup.studentMap)
  return _internal_add_studentmap();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::MyNameSpace::Student >&
StudentsGroup::studentmap() const {
  // @@protoc_insertion_point(field_list:MyNameSpace.StudentsGroup.studentMap)
  return studentmap_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace MyNameSpace

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED__2eproto
