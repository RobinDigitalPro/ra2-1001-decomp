#pragma once
#define NOMINMAX
#include <windows.h>
#include <oleauto.h>
#include <httprequest.h>
#include "recovered/recovery_b1499.hpp"
#include <string>
#include <vector>
namespace ra2::platform::dispatch1499 {
using U=std::uint32_t;namespace model=recovered::b1499;namespace fp=ra2::platform::x87;
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
U fs_head();U fs_selector();void require(bool,const char*);void stack_span(U,U);
struct Boundary{U kind=0,pointer=0,result=0,fs_before=0,fs_after=0,selector_before=0,selector_after=0;fp::Image before,after;std::array<unsigned char,16>produced{};};
struct Trace{std::vector<Boundary>api;std::array<unsigned char,16>argument{},variant{};std::array<unsigned char,32>exception{};std::array<U,4>params{};U arg_error=0,hr=0;};
struct Provider final:model::DispatchAPI {
 IWinHttpRequest*object=nullptr;U dispatch_id=0,invoke_target=0;std::string module;Trace trace;U expected_types=0,expected_variant=0;bool initialized=false;
 using Init=void(WINAPI*)(VARIANTARG*);Init real_init=nullptr;decltype(&lstrlenW)real_length=nullptr;
 Provider();~Provider();Provider(const Provider&)=delete;Provider&operator=(const Provider&)=delete;
 void verify_identity()const;void begin(U,U=0);void verify(bool)const;std::int16_t independent_bool();
 U length(const std::uint16_t*)override;void initialize(model::Variant&)override;U invoke(U,U,U,model::Params&,model::Variant&,model::Exception&,U&)override;
};
}
