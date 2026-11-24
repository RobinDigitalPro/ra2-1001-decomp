#pragma once
#define NOMINMAX
#include <windows.h>
#include <mmsystem.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::receiver245 {
// The original and reconstruction use the same owned event and actual OS APIs.
// Clock values are observed, never supplied or replayed.
class Scope {
 inline static Scope* active_{};
 HANDLE event_{};unsigned base_{},size_{};unsigned char* data_{};
 unsigned phase_{},first_{},last_{},roots_{},polls_{},ticks_{},base_tick_{};
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 static Scope& current(){need(active_,"245 missing observer");return *active_;}
 DWORD sample(unsigned site){
  const DWORD value=::timeGetTime();++ticks_;
  if(site==0x5c718c){need(phase_==0&&roots_==0,"245 initial clock order");first_=value;phase_=1;++roots_;}
  else if(site==0x5c71ae){need(phase_==1,"245 repeated clock order");last_=value;phase_=2;++roots_;}
  else {need(site==0x4816b1&&(phase_==6||phase_==7),"245 maintenance clock order");phase_=phase_==6?7:1;}
  return value;
 }
 static DWORD WINAPI tick_import(){
  // 68FAD0 has no prologue: the next stack word after its return address
  // identifies the original caller. __builtin_frame_address forces this frame.
  auto*f=static_cast<const unsigned*>(__builtin_frame_address(0));
  need(f[1]==0x68fad6,"245 authentic shifted-clock caller");return current().sample(f[2]);
 }
 static BOOL WINAPI reset_import(HANDLE h){auto&s=current();need(s.phase_==2&&h==s.event_,"245 reset order/owned event");const auto r=::ResetEvent(h);need(r!=FALSE,"245 real reset failed");s.phase_=3;return r;}
 static BOOL WINAPI clear_import(HANDLE h,LPDWORD error,LPCOMSTAT status){auto&s=current();need(s.phase_==3&&h==INVALID_HANDLE_VALUE,"245 clear order/invalid handle");const auto r=::ClearCommError(h,error,status);need(r==FALSE,"245 unsupported valid receiver");s.phase_=4;return r;}
 static BOOL WINAPI read_import(HANDLE h,LPVOID p,DWORD count,LPDWORD got,LPOVERLAPPED ov){auto&s=current();need(s.phase_==4&&h==INVALID_HANDLE_VALUE&&count==1&&ov&&ov->hEvent==s.event_,"245 read arguments/order");const auto r=::ReadFile(h,p,count,got,ov);need(r==FALSE&&*got==0,"245 invalid receiver read changed");s.phase_=5;return r;}
 static DWORD WINAPI error_import(){const DWORD r=::GetLastError();auto&s=current();need(s.phase_==5&&r==ERROR_INVALID_HANDLE,"245 actual read error");s.phase_=6;++s.polls_;return r;}
public:
 Scope(unsigned base,unsigned char*data,unsigned size):base_(base),size_(size),data_(data){static_assert(sizeof(void*)==4);event_=::CreateEventA(nullptr,TRUE,FALSE,nullptr);need(event_!=nullptr,"245 create owned event");}
 ~Scope(){if(active_==this)active_=nullptr;if(event_)::CloseHandle(event_);}
 unsigned event()const{return unsigned(reinterpret_cast<std::uintptr_t>(event_));}
 void begin(unsigned base){need(!active_,"245 observer already active");phase_=first_=last_=roots_=polls_=ticks_=0;base_tick_=base;active_=this;}
 void finish(unsigned eax){need(active_==this&&phase_==2&&polls_>0&&roots_==polls_+2&&ticks_==roots_+2*polls_,"245 loop/API counts");need((last_>>4)-(first_>>4)>=30,"245 real elapsed interval");need(eax==(last_>>4)-base_tick_,"245 EAX differs from actual final shifted clock minus base");active_=nullptr;}
 template<class Memory>void bind(Memory&m){m.w32(0x785524,unsigned(reinterpret_cast<std::uintptr_t>(&tick_import)));m.w32(0x785170,unsigned(reinterpret_cast<std::uintptr_t>(&reset_import)));m.w32(0x785150,unsigned(reinterpret_cast<std::uintptr_t>(&clear_import)));m.w32(0x785110,unsigned(reinterpret_cast<std::uintptr_t>(&read_import)));m.w32(0x7851f4,unsigned(reinterpret_cast<std::uintptr_t>(&error_import)));}
 static unsigned clock(unsigned site){return current().sample(site);}
 void* pointer(unsigned p,unsigned n){need(p>=base_&&n<=size_&&p-base_<=size_-n,"245 API buffer outside owned arena");return data_+(p-base_);}
 static void poll(unsigned receiver,unsigned event){
  auto&s=current();need(event==s.event(),"245 receiver event mismatch");
  reset_import(s.event_);DWORD errors;COMSTAT status;
  clear_import(INVALID_HANDLE_VALUE,&errors,&status);DWORD got=0;
  read_import(INVALID_HANDLE_VALUE,s.pointer(receiver+0x6c,1),1,&got,static_cast<OVERLAPPED*>(s.pointer(receiver+0x28,sizeof(OVERLAPPED))));
  (void)error_import(); // 4068F0 following this error is a literal RET.
 }
};
}
