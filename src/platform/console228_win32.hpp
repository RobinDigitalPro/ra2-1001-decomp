#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
namespace ra2::platform::console228 {
inline void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
class Console {
 inline static Console* active_{};
 HANDLE handle_=INVALID_HANDLE_VALUE;
 std::array<INPUT_RECORD,8> records_{};
 unsigned size_{},count_calls_{},peek_calls_{};
public:
 Console(unsigned n){
  static_assert(sizeof(void*)==4&&sizeof(INPUT_RECORD)==20,"original x86 console layout");
  const auto window=GetConsoleWindow();need(window&&!IsWindowVisible(window),"228 requires its private hidden console process");
  handle_=CreateFileW(L"CONIN$",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,0,nullptr);
  need(handle_!=INVALID_HANDLE_VALUE,"228 open private input");need(FlushConsoleInputBuffer(handle_)!=0,"228 clear private input");
  size_=1+(n/2)%8;const auto yes=(n&1)!=0;const auto selected=(n/16)%size_;
  for(unsigned k=0;k<size_;++k){auto&r=records_[k];
   if(k==selected&&yes){r.EventType=KEY_EVENT;r.Event.KeyEvent.bKeyDown=TRUE;r.Event.KeyEvent.wRepeatCount=1;r.Event.KeyEvent.wVirtualKeyCode='A'+n%26;r.Event.KeyEvent.wVirtualScanCode=30;r.Event.KeyEvent.uChar.AsciiChar=char('A'+n%26);}
   else if((k+n)%2){r.EventType=KEY_EVENT;r.Event.KeyEvent.bKeyDown=FALSE;r.Event.KeyEvent.wRepeatCount=1;r.Event.KeyEvent.uChar.AsciiChar=char('a'+k);}
   else {r.EventType=MOUSE_EVENT;r.Event.MouseEvent.dwMousePosition={SHORT(k+1),SHORT(n%40)};r.Event.MouseEvent.dwEventFlags=MOUSE_MOVED;}
  }
  DWORD written=0;need(WriteConsoleInputA(handle_,records_.data(),size_,&written)&&written==size_,"228 actual queue insertion");check();
 }
 ~Console(){if(active_==this)active_=nullptr;if(handle_!=INVALID_HANDLE_VALUE)CloseHandle(handle_);}
 void check()const{DWORD count=0,read=0;std::array<INPUT_RECORD,8> out{};
  need(GetNumberOfConsoleInputEvents(handle_,&count)&&count==size_,"228 exact pending count");
  need(PeekConsoleInputA(handle_,out.data(),size_,&read)&&read==size_&&std::memcmp(out.data(),records_.data(),size_*20)==0,"228 unchanged real input queue");}
 template<class Memory>void bind(Memory&m){m.w32(0x818dd8,0xffffffff);m.w32(0x818de0,unsigned(reinterpret_cast<std::uintptr_t>(handle_)));m.w32(0x785344,unsigned(reinterpret_cast<std::uintptr_t>(&count)));m.w32(0x785260,unsigned(reinterpret_cast<std::uintptr_t>(&peek)));}
 void begin(){need(!active_,"228 observer active");count_calls_=peek_calls_=0;active_=this;}
 void finish(){need(active_==this&&count_calls_==1&&peek_calls_==1,"228 exactly two real APIs");active_=nullptr;check();}
 static BOOL WINAPI count(HANDLE h,LPDWORD out){need(active_&&h==active_->handle_&&active_->count_calls_++==0&&active_->peek_calls_==0,"228 count arguments/order");return GetNumberOfConsoleInputEvents(h,out);}
 static BOOL WINAPI peek(HANDLE h,PINPUT_RECORD out,DWORD size,LPDWORD read){need(active_&&h==active_->handle_&&size==active_->size_&&active_->count_calls_==1&&active_->peek_calls_++==0,"228 peek arguments/order");return PeekConsoleInputA(h,out,size,read);}
};
}
