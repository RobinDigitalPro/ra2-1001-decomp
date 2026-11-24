#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>
namespace ra2::platform::ui244 {
struct Event { unsigned kind;int id;unsigned message,wp,lp,result;std::u16string text;
 bool operator==(const Event&o)const{return kind==o.kind&&id==o.id&&message==o.message&&wp==o.wp&&lp==o.lp&&result==o.result&&text==o.text;}
};
class Scope {
 using Get=HWND(WINAPI*)(HWND,int);using Send=LRESULT(WINAPI*)(HWND,UINT,WPARAM,LPARAM);using Show=BOOL(WINAPI*)(HWND,int);using Atomic=LONG(WINAPI*)(volatile LONG*);
 HWND parent_{};std::array<HWND,9>children_{};volatile LONG*counter_;Get get_;Send send_;Show show_;Atomic add_,sub_;unsigned pairs_{};
 inline static Scope*active_{};
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 int id(HWND h)const{for(unsigned k=0;k<9;++k)if(h==children_[k])return ids[k];throw std::runtime_error("244 non-owned child handle");}
public:
 inline static constexpr int ids[9]={0x411,0x412,0x419,0x41a,0x6da,0x6db,0x6cf,0x6d6,-1};
 std::vector<Event>events;std::vector<std::pair<unsigned,LONG>>atomics;
 explicit Scope(volatile LONG*p):counter_(p){
  static_assert(sizeof(void*)==4,"244 original x86 IAT width");
  const auto user=LoadLibraryW(L"user32.dll"),kernel=GetModuleHandleW(L"kernel32.dll");
  get_=reinterpret_cast<Get>(GetProcAddress(user,"GetDlgItem"));send_=reinterpret_cast<Send>(GetProcAddress(user,"SendMessageA"));show_=reinterpret_cast<Show>(GetProcAddress(user,"ShowWindow"));
  add_=reinterpret_cast<Atomic>(GetProcAddress(kernel,"InterlockedIncrement"));sub_=reinterpret_cast<Atomic>(GetProcAddress(kernel,"InterlockedDecrement"));need(get_&&send_&&show_&&add_&&sub_&&counter_,"244 real exports");
  parent_=CreateWindowExW(0,L"STATIC",L"244 private",WS_OVERLAPPED,0,0,64,64,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);need(parent_,"244 private hidden parent");
  for(unsigned k=0;k<9;++k){children_[k]=CreateWindowExW(0,L"STATIC",L"",WS_CHILD|WS_VISIBLE|SS_LEFT,0,0,8,8,parent_,reinterpret_cast<HMENU>(INT_PTR(ids[k])),GetModuleHandleW(nullptr),nullptr);need(children_[k]&&get_(parent_,ids[k])==children_[k],"244 real child lookup");}
 }
 ~Scope(){if(active_==this)active_=nullptr;if(parent_)DestroyWindow(parent_);}
 HWND parent()const{return parent_;}volatile LONG*counter()const{return counter_;}
 static Scope&current(){need(active_,"244 observer absent");return *active_;}
 void begin(unsigned pairs){need(!active_&&*counter_==0&&(pairs==2||pairs==4),"244 fresh state");for(auto h:children_)show_(h,SW_SHOW);events.clear();atomics.clear();pairs_=pairs;active_=this;}
 void finish(){need(active_==this&&events.size()==28&&atomics.size()==2*pairs_&&*counter_==0,"244 complete real API lifecycle");
  for(unsigned k=0;k<atomics.size();++k)need(atomics[k].first==(k<pairs_?9u:21u)&&atomics[k].second==LONG(k%2?0:1),"244 exact formatter/USER32 interleaving");
  for(unsigned k=0;k<9;++k)need(DWORD(GetWindowLongA(children_[k],GWL_STYLE))==DWORD(ids[k]==0x6d6||ids[k]==-1?0x40000000u:0x50000000u),"244 independent final visibility");active_=nullptr;
 }
 static HWND WINAPI get(HWND p,int i){auto&s=current();need(p==s.parent_,"244 parent identity");const auto h=s.get_(p,i);need(h&&s.id(h)==i,"244 actual GetDlgItem result");s.events.push_back({1,-1,unsigned(i),0,0,1,{}});return h;}
 static LRESULT WINAPI send(HWND h,UINT msg,WPARAM wp,LPARAM lp){auto&s=current();Event e{2,s.id(h),msg,unsigned(wp),unsigned(lp),0,{}};
  if(msg==0x4b2){need(lp!=0,"244 real UTF16 pointer");const auto*p=reinterpret_cast<const wchar_t*>(lp);unsigned k=0;for(;k<64&&p[k];++k)e.text.push_back(char16_t(p[k]));need(k<64,"244 UTF16 bound");e.lp=0;}
  const auto result=s.send_(h,msg,wp,lp);e.result=unsigned(result);s.events.push_back(e);return result;
 }
 static BOOL WINAPI show(HWND h,int command){auto&s=current();need(command==SW_HIDE,"244 bounded ShowWindow command");const auto result=s.show_(h,command);s.events.push_back({3,s.id(h),unsigned(command),0,0,unsigned(result),{}});return result;}
 static LONG WINAPI increment(volatile LONG*p){auto&s=current();need(p==s.counter_&&s.atomics.size()%2==0,"244 increment pointer/order");const auto r=s.add_(p);need(r==1,"244 actual increment result");s.atomics.push_back({unsigned(s.events.size()),r});return r;}
 static LONG WINAPI decrement(volatile LONG*p){auto&s=current();need(p==s.counter_&&s.atomics.size()%2==1,"244 decrement pointer/order");const auto r=s.sub_(p);need(r==0,"244 actual decrement result");s.atomics.push_back({unsigned(s.events.size()),r});return r;}
 template<class Memory>void bind(Memory&m){need(m.r32(0xb10e24)==unsigned(*counter_),"244 counter backing");m.w32(0x78549c,unsigned(reinterpret_cast<std::uintptr_t>(&get)));m.w32(0x7854a0,unsigned(reinterpret_cast<std::uintptr_t>(&send)));m.w32(0x785498,unsigned(reinterpret_cast<std::uintptr_t>(&show)));m.w32(0x7851bc,unsigned(reinterpret_cast<std::uintptr_t>(&increment)));m.w32(0x7851c0,unsigned(reinterpret_cast<std::uintptr_t>(&decrement)));}
};
}
