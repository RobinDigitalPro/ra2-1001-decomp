#pragma once
#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <ole2.h>
#include <array>
#include <cstdint>
#include <string>
#include <vector>
#include <stdexcept>
namespace ra2::platform::ole_storage973 {
inline void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
struct Item{std::uint32_t selector;const wchar_t*name;};
inline constexpr std::array<Item,13>items{{{2,L"Scenario Description"},{3,L"Player House"},{9,L"Version"},{0x10,L"Internal Version"},{0xc,L"Start Time"},{0xd,L"Last Save Time"},{0xa,L"Play Time"},{0x12,L"Executable Name"},{4,L"Player Name"},{8,L"Player Name2"},{0x64,L"Scenario Number"},{0x65,L"Campaign"},{0x66,L"GameType"}}};
inline const Item&item(unsigned selector){for(const auto&x:items)if(x.selector==selector)return x;throw std::runtime_error("973 known selector");}
struct Lifetime{std::uint32_t object,identity,refs;bool operator==(const Lifetime&o)const{return object==o.object&&identity==o.identity&&refs==o.refs;}bool operator!=(const Lifetime&o)const{return !(*this==o);}};
class Storage{
 ILockBytes*lock_=nullptr;IStorage*storage_=nullptr;static inline Storage*active_=nullptr;
 public:
 Storage(){need(!active_,"973 exclusive fixture");need(CreateILockBytesOnHGlobal(nullptr,TRUE,&lock_)==S_OK&&lock_,"973 genuine lockbytes");need(StgCreateDocfileOnILockBytes(lock_,STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,&storage_)==S_OK&&storage_,"973 genuine compound storage");active_=this;}
 ~Storage(){active_=nullptr;if(storage_)storage_->Release();if(lock_)lock_->Release();}
 Storage(const Storage&)=delete;Storage&operator=(const Storage&)=delete;
 static Storage&current(){need(active_,"973 active storage");return *active_;}
 IStorage*get()const{return storage_;}
 std::uint32_t address()const{static_assert(sizeof(void*)==4);return std::uint32_t(reinterpret_cast<std::uintptr_t>(storage_));}
 Lifetime lifetime()const{const GUID iid_unknown{0u,0u,0u,{0xc0u,0u,0u,0u,0u,0u,0u,0x46u}};IUnknown*q=nullptr;need(storage_->QueryInterface(iid_unknown,reinterpret_cast<void**>(&q))==S_OK&&q,"973 actual COM identity");const auto identity=std::uint32_t(reinterpret_cast<std::uintptr_t>(q));q->Release();const auto count=storage_->AddRef();const auto after=storage_->Release();need(count==after+1u,"973 genuine observed AddRef/Release balance");return {address(),identity,after};}
 void seed_except(const std::array<std::string,13>&values,unsigned absent){for(unsigned j=0;j<items.size();++j){if(items[j].selector==absent)continue;IStream*s=nullptr;need(storage_->CreateStream(items[j].name,STGM_CREATE|STGM_WRITE|STGM_SHARE_EXCLUSIVE,0,0,&s)==S_OK&&s,"973 fixture CreateStream");std::vector<wchar_t>w;for(unsigned char c:values[j]){need(c<128u,"973 ASCII fixture");w.push_back(wchar_t(c));}w.push_back(0);ULONG wrote=0;const auto hr=s->Write(w.data(),ULONG(w.size()*2u),&wrote);const bool ok=hr==S_OK&&wrote==w.size()*2u&&s->Commit(STGC_DEFAULT)==S_OK;s->Release();need(ok,"973 fixture stream seed/commit");}need(storage_->Commit(STGC_DEFAULT)==S_OK,"973 fixture storage commit");}
 void erase(unsigned selector){need(storage_->DestroyElement(item(selector).name)==S_OK,"973 outside-observation selected stream reset");need(storage_->Commit(STGC_DEFAULT)==S_OK,"973 reset commit");}
 std::vector<std::uint8_t>read(unsigned selector,bool&present)const{IStream*s=nullptr;const auto hr=storage_->OpenStream(item(selector).name,nullptr,STGM_READ|STGM_SHARE_EXCLUSIVE,0,&s);if(hr==STG_E_FILENOTFOUND){present=false;return {};}need(hr==S_OK&&s,"973 snapshot OpenStream");present=true;std::vector<std::uint8_t>v;for(;;){std::uint8_t b[256];ULONG got=0;const auto h=s->Read(b,sizeof b,&got);v.insert(v.end(),b,b+got);if(h==S_FALSE||!got)break;need(h==S_OK,"973 snapshot actual Read");}s->Release();return v;}
 std::vector<std::uint8_t>snapshot()const{std::vector<std::uint8_t>v;for(const auto&it:items){bool present=false;const auto b=read(it.selector,present);v.push_back(present?1u:0u);const auto size=std::uint32_t(b.size());for(unsigned k=0;k<4u;++k)v.push_back(std::uint8_t(size>>(8u*k)));v.insert(v.end(),b.begin(),b.end());}return v;}
};
}
