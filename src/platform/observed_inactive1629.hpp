#pragma once
#define NOMINMAX
#include <windows.h>
#include "platform/x87_state.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::inactive1629 {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
struct Fs {U head;std::uint16_t selector;bool operator==(const Fs&v)const{return head==v.head&&selector==v.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Result {U calls{},window{},id{},returned{},error_before{},error_after{};bool fp_identity{},fs_identity{};};
class Trace {
 inline static Trace*active_{};Result result_{};
 static void need(bool x){if(!x)throw std::runtime_error("1629 exact inactive realGetDlgItem observation");}
public:
 void begin(){need(!active_);result_={};active_=this;}
 static HWND WINAPI get(HWND window,int id){need(active_&&active_->result_.calls==0u&&window==nullptr&&id==0x53e);auto&v=active_->result_;const auto before=fp::capture_host();const auto fs0=fs();const U error=::GetLastError();const HWND out=::GetDlgItem(window,id);const U error_after=::GetLastError();const auto after=fp::capture_host();const auto fs1=fs();v={1u,U(reinterpret_cast<std::uintptr_t>(window)),U(id),U(reinterpret_cast<std::uintptr_t>(out)),error,error_after,fp::same_numeric(before,after),fs0==fs1};need(v.fp_identity&&v.fs_identity);return out;}
 Result finish(){need(active_==this&&result_.calls==1u);active_=nullptr;return result_;}
 ~Trace(){if(active_==this)active_=nullptr;}
};
}
