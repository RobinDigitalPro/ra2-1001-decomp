#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "recovered/recovery_b1496.hpp"
#include <array>
#include <cstring>
#include <stdexcept>
namespace ra2::platform::exception1496 {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
inline U fs_head(){U v;asm volatile("movl %%fs:0,%0":"=r"(v));return v;}
inline U fs_selector(){unsigned short v;asm volatile("movw %%fs,%0":"=r"(v));return v;}
inline U fs_thread(){U v;asm volatile("movl %%fs:0x24,%0":"=r"(v));return v;}
inline void require(bool v,const char*s){if(!v)throw std::runtime_error(s);}
struct Event {U code{},flags{},count{},carrier{},record{},thread{},matched{},context_address{},exception_address{};std::array<std::uint8_t,84>record_before{},record_after{};CONTEXT context_before{},context_after{};EXCEPTION_RECORD exception{};fp::Image api_before{},api_after{};U fs_before{},fs_after{},selector_before{},selector_after{};};
struct Provider final:recovered::b1496::ExceptionAPI {
 static Provider*active;PVOID registration{};U expected_carrier{},expected_record{},thread{},calls{},unexpected{};std::array<std::uint8_t,84>expected{};Event event{};
 U registered_handle{},removal_result{};
 Provider();~Provider();void close();void expect(U carrier,U record,const std::array<std::uint8_t,84>&bytes);void raise(U,U,U,const U*)override;void verify()const;static LONG CALLBACK handler(EXCEPTION_POINTERS*);
};
}
