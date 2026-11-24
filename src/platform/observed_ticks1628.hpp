#pragma once
#include "platform/observed_ticks152.hpp"
#include "platform/x87_state.hpp"
#include <array>
namespace ra2::platform::ticks1628 {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
struct Fs {U head;std::uint16_t selector;bool operator==(const Fs&v)const{return head==v.head&&selector==v.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Event {U raw{},error_before{},error_after{};bool fp_identity{},fs_identity{};};
struct Result {std::array<Event,4>events{};U count{},wait_ms{},wait_error_before{},wait_error_after{},wait_raw_before{},wait_raw_after{};bool wait_fp_identity{},wait_fs_identity{};};
class Trace {
 inline static Trace* active_{};Result result_{};bool delay_{};
 static void need(bool x){if(!x)throw std::runtime_error("1628 bounded real timer observation");}
public:
 void begin_root(bool delay){need(!active_);result_={};delay_=delay;active_=this;}
 static DWORD WINAPI get(){need(active_&&active_->result_.count<4u);auto&self=*active_;const auto before=fp::capture_host();const auto fs0=fs();const U error=GetLastError();
  ticks152::Tick one;one.begin();const U raw=ticks152::Tick::get();const U raw_again=one.finish();const U after_error=GetLastError();const auto after=fp::capture_host();const auto fs1=fs();need(raw==raw_again);
  self.result_.events[self.result_.count++]={raw,error,after_error,fp::same_numeric(before,after),fs0==fs1};
  need(fp::same_numeric(before,after)&&fs0==fs1&&after_error==error);
  if(self.delay_&&self.result_.count==2u){self.result_.wait_ms=32u;self.result_.wait_raw_before=raw;const auto h=fp::capture_host();const auto f=fs();self.result_.wait_error_before=GetLastError();::Sleep(32u);self.result_.wait_error_after=GetLastError();self.result_.wait_fp_identity=fp::same_numeric(h,fp::capture_host());self.result_.wait_fs_identity=f==fs();need(self.result_.wait_fp_identity&&self.result_.wait_fs_identity&&self.result_.wait_error_before==self.result_.wait_error_after);}
  return raw;
 }
 Result finish_root(){need(active_==this&&(result_.count==3u||result_.count==4u));active_=nullptr;if(delay_){result_.wait_raw_after=result_.events[2].raw;need(result_.count==4u&&std::int32_t((result_.events[2].raw>>4u)-(result_.events[1].raw>>4u))>=1);}return result_;}
 ~Trace(){if(active_==this)active_=nullptr;}
};
}
