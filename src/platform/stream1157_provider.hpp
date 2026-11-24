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
namespace ra2::platform::stream1157 {
inline void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
inline unsigned pointer(const void*p){static_assert(sizeof(void*)==4);return unsigned(reinterpret_cast<std::uintptr_t>(p));}
struct Identity{unsigned stream{},vptr{},query{},addref{},release{},write{},commit{},handle{},buffer{},capacity{},flags{};bool operator==(const Identity&other)const{return stream==other.stream&&vptr==other.vptr&&query==other.query&&addref==other.addref&&release==other.release&&write==other.write&&commit==other.commit&&handle==other.handle&&buffer==other.buffer&&capacity==other.capacity&&flags==other.flags;}bool operator!=(const Identity&other)const{return !(*this==other);}};
struct State{Identity id;std::vector<BYTE>bytes;std::uint64_t cursor{};bool operator==(const State&other)const{return id==other.id&&bytes==other.bytes&&cursor==other.cursor;}bool operator!=(const State&other)const{return !(*this==other);}};
// Same real Ole32 provider as951. Explicit fixed backing extent adds complete
// raw identity/payload/lifetime checks. No proxy or patched COM virtual table.
struct Event{unsigned method,receiver,slot,arg0,arg1,result,output;bool operator==(const Event&other)const{return method==other.method&&receiver==other.receiver&&slot==other.slot&&arg0==other.arg0&&arg1==other.arg1&&result==other.result&&output==other.output;}bool operator!=(const Event&other)const{return !(*this==other);}};
class Stream{
 IStream*p_=nullptr;IStream*queried_=nullptr;HGLOBAL h_=nullptr;Identity identity_{};static inline Stream*active_=nullptr;std::vector<Event>events_;
 public:
 Stream(){need(active_==nullptr,"1157 exclusive real stream fixture");h_=GlobalAlloc(GMEM_MOVEABLE|GMEM_ZEROINIT,4096u);need(h_!=nullptr,"1157 genuine movable HGLOBAL4096");const auto result=CreateStreamOnHGlobal(h_,TRUE,&p_);if(result!=S_OK||!p_){GlobalFree(h_);h_=nullptr;throw std::runtime_error("1157 genuine OLE IStream construction");}active_=this;identity_=identity();need(identity_.capacity==4096u,"1157 complete fixed HGLOBAL extent");balanced_reference();}
 ~Stream(){active_=nullptr;if(p_){if(queried_)p_->Release();p_->Release();}}
 Stream(const Stream&)=delete;Stream&operator=(const Stream&)=delete;
 static Stream&current(){need(active_!=nullptr,"1157 actual active stream");return *active_;}
 unsigned address()const{return pointer(p_);}
 const std::vector<Event>&events()const{return events_;}
 Identity identity()const{need(p_!=nullptr,"1157 live stream");HGLOBAL h=nullptr;need(GetHGlobalFromStream(p_,&h)==S_OK&&h==h_,"1157 actual backing raw HGLOBAL");const auto flags=GlobalFlags(h);need(flags!=GMEM_INVALID_HANDLE,"1157 live actual lock flags");auto*data=GlobalLock(h);need(data!=nullptr,"1157 actual backing GlobalLock");const auto*vt=*reinterpret_cast<const unsigned*const*>(p_);Identity id{pointer(p_),*reinterpret_cast<const unsigned*>(p_),vt[0],vt[1],vt[2],vt[4],vt[8],pointer(h),pointer(data),unsigned(GlobalSize(h)),flags};SetLastError(NO_ERROR);const auto unlocked=GlobalUnlock(h);need(bool(unlocked)==bool(flags&GMEM_LOCKCOUNT)&&GetLastError()==NO_ERROR&&GlobalFlags(h)==flags,"1157 exact balanced GlobalUnlock BOOL/last-error/rawflags");return id;}
 void balanced_reference()const{const unsigned count=queried_?2u:1u;const auto raised=p_->AddRef(),restored=p_->Release();need(raised==count+1u&&restored==count,"1157 complete actual balanced COM reference results");}
 unsigned query_owned(){need(!queried_,"1157 exactly one real QI-owned reference");const auto*guid=reinterpret_cast<const IID*>(0x7c0ab8u);const auto result=p_->QueryInterface(*guid,reinterpret_cast<void**>(&queried_));events_.push_back({0u,address(),identity_.query,0x7c0ab8u,pointer(&queried_),unsigned(result),pointer(queried_)});need(result==S_OK&&queried_==p_,"1157 genuine complete IStream QI result/rawidentity");balanced_reference();return pointer(queried_);}
 unsigned add_ref(unsigned raw){need(raw==address(),"1157 completeAddRef receiver");const auto result=p_->AddRef();events_.push_back({1u,raw,identity_.addref,0u,0u,result,0u});return result;}
 unsigned commit(unsigned raw,unsigned flags){need(raw==address(),"1157 completeCommit receiver");const auto result=p_->Commit(flags);events_.push_back({2u,raw,identity_.commit,flags,0u,unsigned(result),0u});return unsigned(result);}
 unsigned release(unsigned raw){need(raw==address(),"1157 completeRelease receiver");const auto result=p_->Release();events_.push_back({3u,raw,identity_.release,0u,0u,result,0u});return result;}
 void transfer_output_to_owner(unsigned raw)const{need(queried_==p_&&raw==address(),"1157 retained output ownership transfer with no API or refcount change");}
 void restore(const std::vector<BYTE>&bytes,unsigned position){need(bytes.size()==4096u&&position<16u&&identity()==identity_,"1157 complete same raw live backing before restore");LARGE_INTEGER zero{};need(p_->Seek(zero,STREAM_SEEK_SET,nullptr)==S_OK,"1157 initial seek");ULONG written=0;need(p_->Write(bytes.data(),4096u,&written)==S_OK&&written==4096u,"1157 restore complete actual backing payload");LARGE_INTEGER q{};q.QuadPart=position;need(p_->Seek(q,STREAM_SEEK_SET,nullptr)==S_OK&&identity()==identity_,"1157 exact restore cursor and LIVE raw identities");}
 State state()const{STATSTG st{};need(p_->Stat(&st,STATFLAG_NONAME)==S_OK&&st.cbSize.QuadPart==4096u,"1157 full logical stream extent");LARGE_INTEGER zero{};ULARGE_INTEGER q{};need(p_->Seek(zero,STREAM_SEEK_CUR,&q)==S_OK,"1157 actual stream cursor");const auto id=identity();need(id==identity_,"1157 unchanged raw stream/vptr/slot/handle/buffer/capacity");auto*data=static_cast<const BYTE*>(GlobalLock(h_));need(data!=nullptr,"1157 full backing payload lock");State s{id,std::vector<BYTE>(data,data+4096u),q.QuadPart};SetLastError(NO_ERROR);const auto unlocked=GlobalUnlock(h_);need(bool(unlocked)==bool(identity_.flags&GMEM_LOCKCOUNT)&&GetLastError()==NO_ERROR&&GlobalFlags(h_)==identity_.flags,"1157 full backing balanced unlock result/flags");return s;}
 unsigned write(unsigned raw,const void*buffer,unsigned count,ULONG*written){need(raw==address()&&buffer!=nullptr&&(count==4u||count==16u)&&written==nullptr,"1157 complete actual Write parameters");return unsigned(p_->Write(buffer,count,written));}
 void close(){need(p_!=nullptr&&queried_==p_&&identity()==identity_,"1157 finalLIVE identities and retainedoutputownership");balanced_reference();const auto output=p_->Release();queried_=nullptr;need(output==1u,"1157 actual retainedoutputRelease1");const auto result=p_->Release();p_=nullptr;need(result==0u,"1157 actual fixturefinalRelease0");SetLastError(NO_ERROR);need(GlobalFlags(h_)==GMEM_INVALID_HANDLE&&GetLastError()==ERROR_INVALID_HANDLE,"1157 real deleteonrelease HGLOBAL lifetime");h_=nullptr;}
};
}
