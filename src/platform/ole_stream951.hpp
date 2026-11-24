#pragma once
#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include <ole2.h>
#include <cstdint>
#include <vector>
#include <stdexcept>
namespace ra2::platform::ole_stream951 {
inline void need(bool ok,const char*s){if(!ok)throw std::runtime_error(s);}
struct State{std::vector<std::uint8_t> bytes;std::uint64_t position;bool operator==(const State&)const=default;};
class Stream {
 IStream* p_=nullptr;static inline Stream* active_=nullptr;
 public:
 Stream(){need(active_==nullptr,"951 exclusive fixture");need(CreateStreamOnHGlobal(nullptr,TRUE,&p_)==S_OK&&p_,"951 real OLE stream creation");active_=this;}
 ~Stream(){active_=nullptr;if(p_)p_->Release();}
 Stream(const Stream&)=delete;Stream&operator=(const Stream&)=delete;
 static Stream& current(){need(active_!=nullptr,"951 fixture active");return *active_;}
 std::uint32_t address()const{static_assert(sizeof(void*)==4);return std::uint32_t(reinterpret_cast<std::uintptr_t>(p_));}
 void reset(const std::vector<std::uint8_t>&prefix){ULARGE_INTEGER size{};LARGE_INTEGER pos{};need(p_->SetSize(size)==S_OK&&p_->Seek(pos,STREAM_SEEK_SET,nullptr)==S_OK,"951 reset genuine stream");if(!prefix.empty()){ULONG written=0;need(p_->Write(prefix.data(),ULONG(prefix.size()),&written)==S_OK&&written==prefix.size(),"951 prefix write");}}
 State state()const{STATSTG st{};need(p_->Stat(&st,STATFLAG_NONAME)==S_OK&&st.cbSize.HighPart==0,"951 bounded real stream size");LARGE_INTEGER zero{};ULARGE_INTEGER position{};need(p_->Seek(zero,STREAM_SEEK_CUR,&position)==S_OK,"951 real stream position");HGLOBAL h=nullptr;need(GetHGlobalFromStream(p_,&h)==S_OK,"951 backing HGLOBAL");State s{{},position.QuadPart};s.bytes.resize(st.cbSize.LowPart);if(!s.bytes.empty()){auto data=GlobalLock(h);need(data!=nullptr,"951 stream backing lock");const auto*bytes=static_cast<const std::uint8_t*>(data);s.bytes.assign(bytes,bytes+s.bytes.size());GlobalUnlock(h);}return s;}
 std::uint32_t write_word(std::uint32_t pointer,std::uint32_t value){need(pointer==address(),"951 caller genuine IStream");return std::uint32_t(p_->Write(&value,4,nullptr));}
};
}
