#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <cstdint>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::recovery_b1110 {
struct ThreadEvent{
 unsigned kind,input,result,last_error;
 bool operator==(const ThreadEvent&b)const{return kind==b.kind&&input==b.input&&result==b.result&&last_error==b.last_error;}
};
// Actual nonvirtual System32 API backend, never configurable callback results.
// Recorder bookkeeping restores the real API's post-call LastError. Counts
// describe forwarded target operations, excluding observer restore/query calls.
struct ThreadAPI {
 unsigned slot,context,extent=0x74u;std::vector<ThreadEvent>events;
 ThreadAPI(unsigned s,unsigned p):slot(s),context(p){events.reserve(3u);}
 void event(unsigned k,unsigned a,unsigned r,unsigned error){events.push_back({k,a,r,error});::SetLastError(error);}
 unsigned get_error(){unsigned value=::GetLastError();event(1u,0u,value,value);return value;}
 unsigned get_value(unsigned s){auto p=::TlsGetValue(s);unsigned error=::GetLastError(),raw=unsigned(reinterpret_cast<std::uintptr_t>(p));event(2u,s,raw,error);if(s!=slot||raw!=context||extent!=0x74u)throw std::runtime_error("1110 raw realTLS identity/full116byte extent");return raw;}
 void set_error(unsigned value){::SetLastError(value);unsigned after=::GetLastError();event(3u,value,0u,after);}
 unsigned current_thread(unsigned s){auto saved=get_error();auto p=get_value(s);set_error(saved);return p;}
};
}
