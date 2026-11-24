#include "recovered/recovery_b901.hpp"
#include "recovered/allocation_wrappers.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::recovery_b901 {
namespace {
using U=std::uint32_t;
U allocate(U n,U flag,void* p){if(flag!=1u)throw std::domain_error("901 allocation flag");return static_cast<Heap*>(p)->allocate(n);}
U release(U p,void* h){return static_cast<Heap*>(h)->release(p);}
std::string read_guest_string(const Memory& m,U p){if(!p)throw std::domain_error("901 positive contract requires nonnull string");std::string s;for(U k=0;k<64;++k){U c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("901 bounded input exceeds 63 bytes");}
std::string read_heap_string(const Heap& h,U p){if(!p)throw std::domain_error("901 positive contract requires owned receiver text");std::string s;for(U k=0;k<64;++k){U c=h.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("901 bounded receiver exceeds 63 bytes");}
U alloc(Heap& h,U bytes){ra2::recovered::AllocationWrapperOperations op{allocate,release,&h};U p=ra2::recovered::fun_0076d957(bytes,op);if(!p)throw std::domain_error("901 excludes allocation failure");return p;}
void free(Heap& h,U p){ra2::recovered::AllocationWrapperOperations op{allocate,release,&h};(void)ra2::recovered::fun_0076d67b(p,op);}
void copy(Heap& h,U dst,const std::string& s){for(U k=0;k<s.size();++k)h.w8(dst+k,U(std::uint8_t(s[k])));h.w8(dst+U(s.size()),0);}
}
U fun_0075a3d0(Memory& m,const Inputs& in,Heap& h){
 const U receiver=in.cx;
 const U original=m.r32(receiver);
 const U search=in.arg[0], replacement=in.arg[1];
 if(!receiver||!original||!search||!replacement)throw std::domain_error("901 requires nonnull receiver and strings");
 const auto source=read_heap_string(h,original), needle=read_guest_string(m,search), repl=read_guest_string(m,replacement);
 if(source.empty()||needle.empty()||repl.empty())throw std::domain_error("901 bounded positive grammar requires nonempty strings");
 const auto at=source.find(needle);
 if(at==std::string::npos||source.find(needle,at+1)!=std::string::npos||at==0||at+needle.size()>=source.size())throw std::domain_error("901 requires exactly one interior match with prefix and suffix");
 const std::string prefix=source.substr(0,at), suffix=source.substr(at+needle.size());
 // This portable model preserves the four observed allocation requests and
 // release order. The unmodified substring/append helpers are exercised by
 // the native original closure, not called with host pointers here.
 const U prefix_block=alloc(h,U(prefix.size()+1));
 copy(h,prefix_block,prefix);
 const U middle_block=alloc(h,U(prefix.size()+repl.size()+1));
 copy(h,middle_block,prefix+repl);
 free(h,prefix_block);
 // 0x75a55b writes ESI into [ESP+0x28]. With ESP=S-32 this is
 // the caller's [S+8] word, which is the replacement argument at entry.
 // The value survives after this temporary is freed below.
 in.arg[1]=middle_block;
 const U full_block=alloc(h,U(prefix.size()+repl.size()+suffix.size()+1));
 copy(h,full_block,prefix+repl+suffix);
 free(h,middle_block);
 free(h,original);
 const U output=alloc(h,U(prefix.size()+repl.size()+suffix.size()+1));
 m.w32(receiver,output);
 copy(h,output,prefix+repl+suffix);
 free(h,full_block);
 // HeapFree succeeds with EAX=1; the later MOV AL,1 preserves full EAX=1.
 return 1u;
}
}
