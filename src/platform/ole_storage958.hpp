#pragma once
#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <ole2.h>
#include <array>
#include "platform/observed_cp958.hpp"
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>
namespace ra2::platform::ole_storage958 {
inline void need(bool b,const char* s){if(!b)throw std::runtime_error(s);}
struct Item { std::uint32_t selector; const wchar_t* name; };
inline constexpr std::array<Item,13> items{{
 {2,L"Scenario Description"},{3,L"Player House"},{9,L"Version"},{0x10,L"Internal Version"},{0xc,L"Start Time"},{0xd,L"Last Save Time"},{0xa,L"Play Time"},{0x12,L"Executable Name"},{4,L"Player Name"},{8,L"Player Name2"},{0x64,L"Scenario Number"},{0x65,L"Campaign"},{0x66,L"GameType"}}};
class Storage {
 ILockBytes* lock_=nullptr; IStorage* storage_=nullptr; static inline Storage* active_=nullptr;
 void create_doc(){need(CreateILockBytesOnHGlobal(nullptr,TRUE,&lock_)==S_OK&&lock_,"958 CreateILockBytesOnHGlobal");need(StgCreateDocfileOnILockBytes(lock_,STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE,0,&storage_)==S_OK&&storage_,"958 StgCreateDocfileOnILockBytes");}
 public:
 Storage(){need(!active_,"958 exclusive active fixture");create_doc();active_=this;}
 ~Storage(){active_=nullptr;if(storage_)storage_->Release();if(lock_)lock_->Release();}
 Storage(const Storage&)=delete;Storage&operator=(const Storage&)=delete;
 static Storage& current(){need(active_,"958 active provider");return *active_;}
 std::uint32_t address()const{static_assert(sizeof(void*)==4,"native x86 only");return std::uint32_t(reinterpret_cast<std::uintptr_t>(storage_));}
 void reset(const std::array<std::string,13>& values){if(storage_){storage_->Release();storage_=nullptr;}if(lock_){lock_->Release();lock_=nullptr;}create_doc();for(std::size_t i=0;i<items.size();++i){IStream*s=nullptr;HRESULT h=storage_->CreateStream(items[i].name,STGM_CREATE|STGM_WRITE|STGM_SHARE_EXCLUSIVE,0,0,&s);need(h==S_OK&&s,"958 genuine IStorage::CreateStream");std::vector<wchar_t>w;w.reserve(values[i].size()+1);for(unsigned char c:values[i]){need(c<0x80,"958 ASCII-only fixture contract");w.push_back(static_cast<wchar_t>(c));}w.push_back(0);ULONG wrote=0;h=s->Write(w.data(),ULONG(w.size()*sizeof(wchar_t)),&wrote);bool ok=(h==S_OK&&wrote==w.size()*sizeof(wchar_t));need(s->Commit(STGC_DEFAULT)==S_OK,"958 stream commit");s->Release();need(ok,"958 genuine IStream::Write");}need(storage_->Commit(STGC_DEFAULT)==S_OK,"958 commit compound storage");}
 IStorage* get()const{return storage_;}
 std::vector<std::uint8_t> read_selector(std::uint32_t selector)const{const Item*it=nullptr;for(const auto&x:items)if(x.selector==selector){it=&x;break;}need(it,"958 known selector");IStream*s=nullptr;HRESULT h=storage_->OpenStream(it->name,nullptr,STGM_READ|STGM_SHARE_EXCLUSIVE,0,&s);need(h==S_OK&&s,"958 genuine IStorage::OpenStream snapshot");std::vector<std::uint8_t>b;for(;;){std::uint8_t chunk[256];ULONG got=0;h=s->Read(chunk,sizeof chunk,&got);b.insert(b.end(),chunk,chunk+got);if(h==S_FALSE||got==0)break;need(h==S_OK,"958 genuine snapshot read");}s->Release();return b;}
 std::vector<std::uint8_t> snapshot()const{std::vector<std::uint8_t> all;for(const auto&x:items){auto b=read_selector(x.selector);const auto n=std::uint32_t(b.size());for(unsigned k=0;k<4;++k)all.push_back(std::uint8_t(n>>(8*k)));all.insert(all.end(),b.begin(),b.end());}return all;}
};
inline std::uint32_t convert_selector(std::uint32_t selector,char* output){auto&owner=Storage::current();const Item*it=nullptr;for(const auto&x:items)if(x.selector==selector){it=&x;break;}need(it,"958 selected table selector");IStream*s=nullptr;HRESULT hr=owner.get()->OpenStream(it->name,nullptr,0x10,0,&s);need(hr==S_OK&&s,"958 target OpenStream positive branch");std::array<wchar_t,130> wide{};std::size_t n=0;for(;;){wchar_t ch=0;ULONG got=0;hr=s->Read(&ch,2,&got);need(hr==S_OK&&got==2,"958 target Read successful UTF16 unit");need(n<wide.size(),"958 bounded NUL terminator");wide[n++]=ch;if(ch==0)break;}int converted=ra2::platform::cp958::convert(CP_ACP,0,wide.data(),-1,output,127,nullptr,nullptr);need(converted>0&&converted<=127,"958 actual WideCharToMultiByte success");s->Release();return static_cast<std::uint32_t>(hr);}
}
