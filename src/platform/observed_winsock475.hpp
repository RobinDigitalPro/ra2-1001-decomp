#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <winsock2.h>
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>
namespace ra2::platform::winsock475 {
using Memory=ra2::recovered::global_b26::Memory;
struct Event {std::array<std::uint32_t,6> words;bool operator==(const Event&b)const{return words==b.words;}};
class Socket {
 using Set=int(WSAAPI*)(SOCKET,int,int,const char*,int);
 using Get=int(WSAAPI*)(SOCKET,int,int,char*,int*);
 using Last=int(WSAAPI*)();
 using Clear=void(WSAAPI*)(int);
 HMODULE module_{};Set set_{};Get get_{};Last last_{};Clear clear_{};
 SOCKET socket_=INVALID_SOCKET;bool started_=false,native_=false,bad_=false;unsigned step_=0;
 std::array<int,2> requested_{};std::vector<Event> events_;
 inline static Socket* active_=nullptr;
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 template<class T>T proc(const char*n){auto p=GetProcAddress(module_,n);need(p!=nullptr,"475 original Winsock export");return reinterpret_cast<T>(p);}
 static int WSAAPI observe(SOCKET s,int level,int option,const char*value,int length){
  auto& a=*active_;const unsigned index=a.step_++;
  if(index>=2||s!=a.socket_||level!=SOL_SOCKET||option!=(index==0?SO_RCVBUF:SO_SNDBUF)||length!=4)a.bad_=true;
  if(a.native_&&reinterpret_cast<std::uintptr_t>(value)!=(index==0?0x7e906cu:0x7e9068u))a.bad_=true;
  const auto v=*reinterpret_cast<const int*>(value);
  if(index<2&&v!=a.requested_[index])a.bad_=true;
  const int result=a.set_(s,level,option,value,length); // Always the genuine original DLL export.
  a.events_.push_back({{std::uint32_t(s),std::uint32_t(level),std::uint32_t(option),std::uint32_t(v),std::uint32_t(length),std::uint32_t(result)}});
  return result;
 }
public:
 Socket(){
  need(active_==nullptr,"475 nested socket context");module_=LoadLibraryA("wsock32.dll");need(module_!=nullptr,"475 original Winsock DLL");
  set_=proc<Set>("setsockopt");get_=proc<Get>("getsockopt");last_=proc<Last>("WSAGetLastError");clear_=proc<Clear>("WSASetLastError");
  need(set_==proc<Set>(MAKEINTRESOURCEA(21))&&last_==proc<Last>(MAKEINTRESOURCEA(111)),"475 original ordinal/name export identity");
  WSADATA data{};const auto start=proc<int(WSAAPI*)(WORD,LPWSADATA)>("WSAStartup");need(start(MAKEWORD(1,1),&data)==0,"475 WSAStartup");started_=true;
  socket_=proc<SOCKET(WSAAPI*)(int,int,int)>("socket")(AF_INET,SOCK_DGRAM,IPPROTO_UDP);need(socket_!=INVALID_SOCKET,"475 owned local UDP socket");active_=this;
 }
 ~Socket(){
  if(socket_!=INVALID_SOCKET)proc<int(WSAAPI*)(SOCKET)>("closesocket")(socket_);
  if(started_)proc<int(WSAAPI*)()>("WSACleanup")();active_=nullptr;if(module_)FreeLibrary(module_);
 }
 static std::uint32_t handle(){need(active_!=nullptr,"475 no socket context");return std::uint32_t(active_->socket_);}
 void bind(Memory&m){
  m.w32(0x785570,std::uint32_t(reinterpret_cast<std::uintptr_t>(&observe)));
  m.w32(0x78557c,std::uint32_t(reinterpret_cast<std::uintptr_t>(last_)));
 }
 void begin(bool native,int receive,int send){
  native_=native;requested_={receive,send};step_=0;bad_=false;events_.clear();
  const int initial=65536;
  need(set_(socket_,SOL_SOCKET,SO_RCVBUF,reinterpret_cast<const char*>(&initial),4)==0,"475 receive prestate");
  need(set_(socket_,SOL_SOCKET,SO_SNDBUF,reinterpret_cast<const char*>(&initial),4)==0,"475 send prestate");
  clear_(0);
 }
 std::vector<Event> finish(){
  need(step_==2&&!bad_&&events_.size()==2,"475 actual API argument/identity/order");
  need(events_[0].words[5]==0&&events_[1].words[5]==0,"475 actual socket configuration must succeed");
  need(last_()==0,"475 preserved zero Winsock error state");
  for(unsigned k=0;k<2;++k){int size=4,value=0;need(get_(socket_,SOL_SOCKET,k==0?SO_RCVBUF:SO_SNDBUF,reinterpret_cast<char*>(&value),&size)==0&&size==4,"475 real socket option readback");need(value==requested_[k],"475 socket buffer did not acquire requested capacity");}
  return events_;
 }
 static int configure(std::uint32_t s,int option,int value){
  need(active_!=nullptr,"475 missing original DLL adapter");
  return observe(SOCKET(s),SOL_SOCKET,option,reinterpret_cast<const char*>(&value),4);
 }
};
}
