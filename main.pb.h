// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: main.proto

#ifndef PROTOBUF_main_2eproto__INCLUDED
#define PROTOBUF_main_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_main_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsChatRoomImpl();
void InitDefaultsChatRoom();
void InitDefaultsRequestImpl();
void InitDefaultsRequest();
inline void InitDefaults() {
  InitDefaultsChatRoom();
  InitDefaultsRequest();
}
}  // namespace protobuf_main_2eproto
namespace hw {
class ChatRoom;
class ChatRoomDefaultTypeInternal;
extern ChatRoomDefaultTypeInternal _ChatRoom_default_instance_;
class Client;
class ClientDefaultTypeInternal;
extern ClientDefaultTypeInternal _Client_default_instance_;
class Request;
class RequestDefaultTypeInternal;
extern RequestDefaultTypeInternal _Request_default_instance_;
}  // namespace hw
namespace hw {

// ===================================================================

class Client : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:hw.Client) */ {
 public:
  Client();
  virtual ~Client();

  Client(const Client& from);

  inline Client& operator=(const Client& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Client(Client&& from) noexcept
    : Client() {
    *this = ::std::move(from);
  }

  inline Client& operator=(Client&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Client& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Client* internal_default_instance() {
    return reinterpret_cast<const Client*>(
               &_Client_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Client* other);
  friend void swap(Client& a, Client& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Client* New() const PROTOBUF_FINAL { return New(NULL); }

  Client* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Client& from);
  void MergeFrom(const Client& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Client* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .hw.ChatRoom chatRoom = 2;
  int chatroom_size() const;
  void clear_chatroom();
  static const int kChatRoomFieldNumber = 2;
  const ::hw::ChatRoom& chatroom(int index) const;
  ::hw::ChatRoom* mutable_chatroom(int index);
  ::hw::ChatRoom* add_chatroom();
  ::google::protobuf::RepeatedPtrField< ::hw::ChatRoom >*
      mutable_chatroom();
  const ::google::protobuf::RepeatedPtrField< ::hw::ChatRoom >&
      chatroom() const;

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:hw.Client)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::hw::ChatRoom > chatroom_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  mutable int _cached_size_;
  friend struct ::protobuf_main_2eproto::TableStruct;
  friend void ::protobuf_main_2eproto::InitDefaultsChatRoomImpl();
};
// -------------------------------------------------------------------

class ChatRoom : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:hw.ChatRoom) */ {
 public:
  ChatRoom();
  virtual ~ChatRoom();

  ChatRoom(const ChatRoom& from);

  inline ChatRoom& operator=(const ChatRoom& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ChatRoom(ChatRoom&& from) noexcept
    : ChatRoom() {
    *this = ::std::move(from);
  }

  inline ChatRoom& operator=(ChatRoom&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ChatRoom& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ChatRoom* internal_default_instance() {
    return reinterpret_cast<const ChatRoom*>(
               &_ChatRoom_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ChatRoom* other);
  friend void swap(ChatRoom& a, ChatRoom& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ChatRoom* New() const PROTOBUF_FINAL { return New(NULL); }

  ChatRoom* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ChatRoom& from);
  void MergeFrom(const ChatRoom& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ChatRoom* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .hw.Client clients = 4;
  int clients_size() const;
  void clear_clients();
  static const int kClientsFieldNumber = 4;
  const ::hw::Client& clients(int index) const;
  ::hw::Client* mutable_clients(int index);
  ::hw::Client* add_clients();
  ::google::protobuf::RepeatedPtrField< ::hw::Client >*
      mutable_clients();
  const ::google::protobuf::RepeatedPtrField< ::hw::Client >&
      clients() const;

  // string owner = 1;
  void clear_owner();
  static const int kOwnerFieldNumber = 1;
  const ::std::string& owner() const;
  void set_owner(const ::std::string& value);
  #if LANG_CXX11
  void set_owner(::std::string&& value);
  #endif
  void set_owner(const char* value);
  void set_owner(const char* value, size_t size);
  ::std::string* mutable_owner();
  ::std::string* release_owner();
  void set_allocated_owner(::std::string* owner);

  // int32 thread = 2;
  void clear_thread();
  static const int kThreadFieldNumber = 2;
  ::google::protobuf::int32 thread() const;
  void set_thread(::google::protobuf::int32 value);

  // int32 port = 3;
  void clear_port();
  static const int kPortFieldNumber = 3;
  ::google::protobuf::int32 port() const;
  void set_port(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:hw.ChatRoom)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::hw::Client > clients_;
  ::google::protobuf::internal::ArenaStringPtr owner_;
  ::google::protobuf::int32 thread_;
  ::google::protobuf::int32 port_;
  mutable int _cached_size_;
  friend struct ::protobuf_main_2eproto::TableStruct;
  friend void ::protobuf_main_2eproto::InitDefaultsChatRoomImpl();
};
// -------------------------------------------------------------------

class Request : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:hw.Request) */ {
 public:
  Request();
  virtual ~Request();

  Request(const Request& from);

  inline Request& operator=(const Request& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Request(Request&& from) noexcept
    : Request() {
    *this = ::std::move(from);
  }

  inline Request& operator=(Request&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Request& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Request* internal_default_instance() {
    return reinterpret_cast<const Request*>(
               &_Request_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(Request* other);
  friend void swap(Request& a, Request& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Request* New() const PROTOBUF_FINAL { return New(NULL); }

  Request* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Request& from);
  void MergeFrom(const Request& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Request* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string from = 1;
  void clear_from();
  static const int kFromFieldNumber = 1;
  const ::std::string& from() const;
  void set_from(const ::std::string& value);
  #if LANG_CXX11
  void set_from(::std::string&& value);
  #endif
  void set_from(const char* value);
  void set_from(const char* value, size_t size);
  ::std::string* mutable_from();
  ::std::string* release_from();
  void set_allocated_from(::std::string* from);

  // string request = 2;
  void clear_request();
  static const int kRequestFieldNumber = 2;
  const ::std::string& request() const;
  void set_request(const ::std::string& value);
  #if LANG_CXX11
  void set_request(::std::string&& value);
  #endif
  void set_request(const char* value);
  void set_request(const char* value, size_t size);
  ::std::string* mutable_request();
  ::std::string* release_request();
  void set_allocated_request(::std::string* request);

  // @@protoc_insertion_point(class_scope:hw.Request)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr from_;
  ::google::protobuf::internal::ArenaStringPtr request_;
  mutable int _cached_size_;
  friend struct ::protobuf_main_2eproto::TableStruct;
  friend void ::protobuf_main_2eproto::InitDefaultsRequestImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Client

// string name = 1;
inline void Client::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Client::name() const {
  // @@protoc_insertion_point(field_get:hw.Client.name)
  return name_.GetNoArena();
}
inline void Client::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:hw.Client.name)
}
#if LANG_CXX11
inline void Client::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:hw.Client.name)
}
#endif
inline void Client::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:hw.Client.name)
}
inline void Client::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:hw.Client.name)
}
inline ::std::string* Client::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:hw.Client.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Client::release_name() {
  // @@protoc_insertion_point(field_release:hw.Client.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Client::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:hw.Client.name)
}

// repeated .hw.ChatRoom chatRoom = 2;
inline int Client::chatroom_size() const {
  return chatroom_.size();
}
inline void Client::clear_chatroom() {
  chatroom_.Clear();
}
inline const ::hw::ChatRoom& Client::chatroom(int index) const {
  // @@protoc_insertion_point(field_get:hw.Client.chatRoom)
  return chatroom_.Get(index);
}
inline ::hw::ChatRoom* Client::mutable_chatroom(int index) {
  // @@protoc_insertion_point(field_mutable:hw.Client.chatRoom)
  return chatroom_.Mutable(index);
}
inline ::hw::ChatRoom* Client::add_chatroom() {
  // @@protoc_insertion_point(field_add:hw.Client.chatRoom)
  return chatroom_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::hw::ChatRoom >*
Client::mutable_chatroom() {
  // @@protoc_insertion_point(field_mutable_list:hw.Client.chatRoom)
  return &chatroom_;
}
inline const ::google::protobuf::RepeatedPtrField< ::hw::ChatRoom >&
Client::chatroom() const {
  // @@protoc_insertion_point(field_list:hw.Client.chatRoom)
  return chatroom_;
}

// -------------------------------------------------------------------

// ChatRoom

// string owner = 1;
inline void ChatRoom::clear_owner() {
  owner_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ChatRoom::owner() const {
  // @@protoc_insertion_point(field_get:hw.ChatRoom.owner)
  return owner_.GetNoArena();
}
inline void ChatRoom::set_owner(const ::std::string& value) {
  
  owner_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:hw.ChatRoom.owner)
}
#if LANG_CXX11
inline void ChatRoom::set_owner(::std::string&& value) {
  
  owner_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:hw.ChatRoom.owner)
}
#endif
inline void ChatRoom::set_owner(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  owner_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:hw.ChatRoom.owner)
}
inline void ChatRoom::set_owner(const char* value, size_t size) {
  
  owner_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:hw.ChatRoom.owner)
}
inline ::std::string* ChatRoom::mutable_owner() {
  
  // @@protoc_insertion_point(field_mutable:hw.ChatRoom.owner)
  return owner_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ChatRoom::release_owner() {
  // @@protoc_insertion_point(field_release:hw.ChatRoom.owner)
  
  return owner_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ChatRoom::set_allocated_owner(::std::string* owner) {
  if (owner != NULL) {
    
  } else {
    
  }
  owner_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), owner);
  // @@protoc_insertion_point(field_set_allocated:hw.ChatRoom.owner)
}

// int32 thread = 2;
inline void ChatRoom::clear_thread() {
  thread_ = 0;
}
inline ::google::protobuf::int32 ChatRoom::thread() const {
  // @@protoc_insertion_point(field_get:hw.ChatRoom.thread)
  return thread_;
}
inline void ChatRoom::set_thread(::google::protobuf::int32 value) {
  
  thread_ = value;
  // @@protoc_insertion_point(field_set:hw.ChatRoom.thread)
}

// int32 port = 3;
inline void ChatRoom::clear_port() {
  port_ = 0;
}
inline ::google::protobuf::int32 ChatRoom::port() const {
  // @@protoc_insertion_point(field_get:hw.ChatRoom.port)
  return port_;
}
inline void ChatRoom::set_port(::google::protobuf::int32 value) {
  
  port_ = value;
  // @@protoc_insertion_point(field_set:hw.ChatRoom.port)
}

// repeated .hw.Client clients = 4;
inline int ChatRoom::clients_size() const {
  return clients_.size();
}
inline void ChatRoom::clear_clients() {
  clients_.Clear();
}
inline const ::hw::Client& ChatRoom::clients(int index) const {
  // @@protoc_insertion_point(field_get:hw.ChatRoom.clients)
  return clients_.Get(index);
}
inline ::hw::Client* ChatRoom::mutable_clients(int index) {
  // @@protoc_insertion_point(field_mutable:hw.ChatRoom.clients)
  return clients_.Mutable(index);
}
inline ::hw::Client* ChatRoom::add_clients() {
  // @@protoc_insertion_point(field_add:hw.ChatRoom.clients)
  return clients_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::hw::Client >*
ChatRoom::mutable_clients() {
  // @@protoc_insertion_point(field_mutable_list:hw.ChatRoom.clients)
  return &clients_;
}
inline const ::google::protobuf::RepeatedPtrField< ::hw::Client >&
ChatRoom::clients() const {
  // @@protoc_insertion_point(field_list:hw.ChatRoom.clients)
  return clients_;
}

// -------------------------------------------------------------------

// Request

// string from = 1;
inline void Request::clear_from() {
  from_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Request::from() const {
  // @@protoc_insertion_point(field_get:hw.Request.from)
  return from_.GetNoArena();
}
inline void Request::set_from(const ::std::string& value) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:hw.Request.from)
}
#if LANG_CXX11
inline void Request::set_from(::std::string&& value) {
  
  from_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:hw.Request.from)
}
#endif
inline void Request::set_from(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:hw.Request.from)
}
inline void Request::set_from(const char* value, size_t size) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:hw.Request.from)
}
inline ::std::string* Request::mutable_from() {
  
  // @@protoc_insertion_point(field_mutable:hw.Request.from)
  return from_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Request::release_from() {
  // @@protoc_insertion_point(field_release:hw.Request.from)
  
  return from_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Request::set_allocated_from(::std::string* from) {
  if (from != NULL) {
    
  } else {
    
  }
  from_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from);
  // @@protoc_insertion_point(field_set_allocated:hw.Request.from)
}

// string request = 2;
inline void Request::clear_request() {
  request_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Request::request() const {
  // @@protoc_insertion_point(field_get:hw.Request.request)
  return request_.GetNoArena();
}
inline void Request::set_request(const ::std::string& value) {
  
  request_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:hw.Request.request)
}
#if LANG_CXX11
inline void Request::set_request(::std::string&& value) {
  
  request_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:hw.Request.request)
}
#endif
inline void Request::set_request(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  request_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:hw.Request.request)
}
inline void Request::set_request(const char* value, size_t size) {
  
  request_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:hw.Request.request)
}
inline ::std::string* Request::mutable_request() {
  
  // @@protoc_insertion_point(field_mutable:hw.Request.request)
  return request_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Request::release_request() {
  // @@protoc_insertion_point(field_release:hw.Request.request)
  
  return request_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Request::set_allocated_request(::std::string* request) {
  if (request != NULL) {
    
  } else {
    
  }
  request_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), request);
  // @@protoc_insertion_point(field_set_allocated:hw.Request.request)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace hw

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_main_2eproto__INCLUDED
