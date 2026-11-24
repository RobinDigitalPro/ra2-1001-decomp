#pragma once
#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <ole2.h>
#include <array>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <cstring>
namespace ra2::platform::stream1144 {
inline void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
inline unsigned pointer(const void*p){static_assert(sizeof(void*)==4);return unsigned(reinterpret_cast<std::uintptr_t>(p));}
struct Identity{unsigned stream{},vptr{},write{},handle{},buffer{},capacity{},flags{};bool operator==(const Identity&)const=default;};
struct State{Identity id;std::vector<BYTE>bytes;std::uint64_t cursor{};bool operator==(const State&)const=default;};
// Same real Ole32 provider as951. Explicit fixed backing extent adds complete
// raw identity/payload/lifetime checks. No proxy or patched COM virtual table.
class Stream{
 IStream*p_=nullptr;HGLOBAL h_=nullptr;Identity identity_{};
 public:
 Stream(){h_=GlobalAlloc(GMEM_MOVEABLE|GMEM_ZEROINIT,4096u);need(h_!=nullptr,"1144 genuine movable HGLOBAL4096");const auto result=CreateStreamOnHGlobal(h_,TRUE,&p_);if(result!=S_OK||!p_){GlobalFree(h_);h_=nullptr;throw std::runtime_error("1144 genuine OLE IStream construction");}identity_=identity();need(identity_.capacity==4096u,"1144 complete fixed HGLOBAL extent");balanced_reference();}
 ~Stream(){if(p_)p_->Release();}
 Stream(const Stream&)=delete;Stream&operator=(const Stream&)=delete;
 unsigned address()const{return pointer(p_);}
 Identity identity()const{need(p_!=nullptr,"1144 live stream");HGLOBAL h=nullptr;need(GetHGlobalFromStream(p_,&h)==S_OK&&h==h_,"1144 actual backing raw HGLOBAL");const auto flags=GlobalFlags(h);need(flags!=GMEM_INVALID_HANDLE,"1144 live actual lock flags");auto*data=GlobalLock(h);need(data!=nullptr,"1144 actual backing GlobalLock");Identity id{pointer(p_),*reinterpret_cast<const unsigned*>(p_),(*reinterpret_cast<const unsigned*const*>(p_))[4],pointer(h),pointer(data),unsigned(GlobalSize(h)),flags};SetLastError(NO_ERROR);const auto unlocked=GlobalUnlock(h);need(bool(unlocked)==bool(flags&GMEM_LOCKCOUNT)&&GetLastError()==NO_ERROR&&GlobalFlags(h)==flags,"1144 exact balanced GlobalUnlock BOOL/last-error/rawflags");return id;}
 void balanced_reference()const{need(p_->AddRef()==2u&&p_->Release()==1u,"1144 actual exclusive COM ownership AddRef2 Release1");}
 void restore(const std::vector<BYTE>&bytes,unsigned position){need(bytes.size()==4096u&&position<16u&&identity()==identity_,"1144 complete same raw live backing before restore");LARGE_INTEGER zero{};need(p_->Seek(zero,STREAM_SEEK_SET,nullptr)==S_OK,"1144 initial seek");ULONG written=0;need(p_->Write(bytes.data(),4096u,&written)==S_OK&&written==4096u,"1144 restore complete actual backing payload");LARGE_INTEGER q{};q.QuadPart=position;need(p_->Seek(q,STREAM_SEEK_SET,nullptr)==S_OK&&identity()==identity_,"1144 exact restore cursor and LIVE raw identities");}
 State state()const{STATSTG st{};need(p_->Stat(&st,STATFLAG_NONAME)==S_OK&&st.cbSize.QuadPart==4096u,"1144 full logical stream extent");LARGE_INTEGER zero{};ULARGE_INTEGER q{};need(p_->Seek(zero,STREAM_SEEK_CUR,&q)==S_OK,"1144 actual stream cursor");const auto id=identity();need(id==identity_,"1144 unchanged raw stream/vptr/slot/handle/buffer/capacity");auto*data=static_cast<const BYTE*>(GlobalLock(h_));need(data!=nullptr,"1144 full backing payload lock");State s{id,std::vector<BYTE>(data,data+4096u),q.QuadPart};SetLastError(NO_ERROR);const auto unlocked=GlobalUnlock(h_);need(bool(unlocked)==bool(identity_.flags&GMEM_LOCKCOUNT)&&GetLastError()==NO_ERROR&&GlobalFlags(h_)==identity_.flags,"1144 full backing balanced unlock result/flags");return s;}
 unsigned write(unsigned raw,const void*buffer,unsigned count,ULONG*written){need(raw==address()&&buffer!=nullptr&&(count==4u||count==16u)&&written==nullptr,"1144 complete actual Write parameters");return unsigned(p_->Write(buffer,count,written));}
 void close(){need(p_!=nullptr&&identity()==identity_,"1144 final LIVE identities before cleanup");balanced_reference();const auto result=p_->Release();p_=nullptr;need(result==0u,"1144 actual final Release0");SetLastError(NO_ERROR);need(GlobalFlags(h_)==GMEM_INVALID_HANDLE&&GetLastError()==ERROR_INVALID_HANDLE,"1144 real delete-on-release HGLOBAL lifetime");h_=nullptr;}
};
}
