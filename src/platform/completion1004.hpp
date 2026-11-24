#pragma once
#define NOMINMAX
#include <windows.h>
#include <mmsystem.h>
#include <array>
#include <vector>
#include <cstdint>
#include <stdexcept>
namespace io1004 {
class Scope {
 inline static Scope*active=nullptr;
 unsigned base,size,receiver=0,bytes=0,phase=0,sides=0,expected_sides=0;
 unsigned char*data;HANDLE file=INVALID_HANDLE_VALUE,event=nullptr;
 unsigned clocks=0,completions=0,resets=0;DWORD reset_result=0;
 std::array<DWORD,2> samples{};std::vector<unsigned char>payload;
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 static unsigned p(const void*v){return unsigned(reinterpret_cast<std::uintptr_t>(v));}
 static DWORD WINAPI tick_import(){return current().tick();}
 static BOOL WINAPI get_import(HANDLE h,LPOVERLAPPED ov,LPDWORD count,BOOL wait){return current().get(h,ov,count,wait);}
 static BOOL WINAPI reset_import(HANDLE h){return current().reset(h);}
 BOOL get(HANDLE h,LPOVERLAPPED ov,LPDWORD count,BOOL wait){
  need(phase==2u&&h==file&&ov==pointer(receiver+0x3cu,20u)&&count&&wait==FALSE,"1004 exact actual GetOverlappedResult arguments/order");
  const auto result=::GetOverlappedResult(h,ov,count,wait);const auto error=GetLastError();
  need(result!=FALSE&&*count==bytes,"1004 actual completed nonzero transfer");++completions;++phase;SetLastError(error);return result;
 }
 BOOL reset(HANDLE h){need(phase==3u&&h==event,"1004 exact owned event reset/order");const auto result=::ResetEvent(h);const auto error=GetLastError();need(result!=FALSE,"1004 actual ResetEvent success");reset_result=unsigned(result);++resets;++phase;SetLastError(error);return result;}
 void finish(unsigned eax){need(phase==4u&&eax==reset_result&&WaitForSingleObject(event,0u)==WAIT_TIMEOUT,"1004 actual un-signaled completed event/fullBOOL");++sides;need(sides<=expected_sides,"1004 unexpected extra side");}
 public:
 Scope(unsigned b,unsigned char*d,unsigned n):base(b),size(n),data(d){
  static_assert(sizeof(void*)==4&&sizeof(OVERLAPPED)==20);need(!active,"1004 exclusive real IO observer");
  CreateDirectoryA("build\\block1004",nullptr);CreateDirectoryA("build\\block1004\\private",nullptr);
  event=CreateEventA(nullptr,TRUE,FALSE,nullptr);need(event!=nullptr,"1004 owned completion event");
  file=CreateFileA("build\\block1004\\private\\completed.bin",GENERIC_READ|GENERIC_WRITE,0,nullptr,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED|FILE_FLAG_DELETE_ON_CLOSE,nullptr);need(file!=INVALID_HANDLE_VALUE,"1004 owned private overlapped file");active=this;
 }
 ~Scope(){active=nullptr;if(file!=INVALID_HANDLE_VALUE)CloseHandle(file);if(event)CloseHandle(event);}
 static Scope&current(){need(active!=nullptr,"1004 observer required");return *active;}
 void*pointer(unsigned a,unsigned n){need(a>=base&&n<=size&&a-base<=size-n,"1004 pointer belongs to exact arena");return data+(a-base);}
 template<class M>void bind(M&m){m.w32(0x785524u,p(reinterpret_cast<const void*>(&tick_import)));m.w32(0x785178u,p(reinterpret_cast<const void*>(&get_import)));m.w32(0x785170u,p(reinterpret_cast<const void*>(&reset_import)));}
 template<class M>void prepare(M&m,unsigned r,unsigned n,bool paired){
  need(sides==expected_sides,"1004 previous fixture sides incomplete");receiver=r;bytes=1u+n%256u;sides=0;expected_sides=paired?2u:1u;phase=0;
  auto*ov=static_cast<OVERLAPPED*>(pointer(r+0x3cu,20u));*ov={};ov->hEvent=event;payload.resize(bytes);for(unsigned j=0;j<bytes;++j)payload[j]=static_cast<unsigned char>(n*37u+j*131u);
  ResetEvent(event);DWORD written=0;const auto started=WriteFile(file,payload.data(),bytes,&written,ov);need(started!=FALSE||GetLastError()==ERROR_IO_PENDING,"1004 genuine overlapped write producer");need(GetOverlappedResult(file,ov,&written,TRUE)!=FALSE&&written==bytes,"1004 fixture waits for actual write completion");need(WaitForSingleObject(event,0)==WAIT_OBJECT_0,"1004 real completion event signaled");m.w32(r+0x5cu,p(file));m.w8(r+0x51u,1u);
 }
 DWORD tick(){need(phase<2u,"1004 two actual clock calls first");const auto value=::timeGetTime();samples[phase++]=value;++clocks;return value;}
 template<class M>BOOL complete(M&m){DWORD count=0;return get(reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(receiver+0x5cu))),static_cast<OVERLAPPED*>(pointer(receiver+0x3cu,20u)),&count,FALSE);}
 template<class M>unsigned reset_model(M&m){return unsigned(reset(reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(receiver+0x4cu)))));}
 void finish_model_side(unsigned eax){finish(eax);need(sides==1u&&expected_sides==2u,"1004 first side");}
 void before_original(){need(sides==1u&&phase==4u&&expected_sides==2u,"1004 restore before original");need(SetEvent(event)!=FALSE,"1004 fixture restores same completed event");phase=0;}
 void finish_original_side(unsigned eax){finish(eax);need(sides==2u,"1004 completed paired sides");}
 void finish_model_only(unsigned eax){finish(eax);need(sides==1u&&expected_sides==1u,"1004 independent model side");}
 void totals(unsigned cases)const{need(clocks==4u*cases&&completions==2u*cases&&resets==2u*cases,"1004 exact actual native/model API totals");}
};}
