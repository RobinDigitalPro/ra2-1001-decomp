#include "recovery_b1258.hpp"
#include <array>
#include <string>
#include <stdexcept>
#include <cstdint>
namespace ra2::recovered::b1258 {namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
unsigned pointer(HANDLE p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
HANDLE handle(unsigned p){return reinterpret_cast<HANDLE>(std::uintptr_t(p));}
const char* name(unsigned p){return reinterpret_cast<const char*>(std::uintptr_t(p));}
void zero(Heap&h,unsigned p,unsigned n){for(unsigned k=0;k<n;++k)h.w8(p+k,0u);}
void copy(Heap&h,unsigned p,const std::string&s){for(unsigned k=0;k<=s.size();++k)h.w8(p+k,k==s.size()?0u:unsigned(static_cast<unsigned char>(s[k])));}
unsigned word(const unsigned char*p){return unsigned(p[0])|(unsigned(p[1])<<8u)|(unsigned(p[2])<<16u)|(unsigned(p[3])<<24u);}
void upper(Heap&h,unsigned p){for(unsigned k=0;k<32u;++k){const auto c=h.r8(p+k);if(!c)return;if(c>='a'&&c<='z')h.w8(p+k,c-32u);}throw std::domain_error("1258 bounded ASCII clone");}
void probe(FileApi&a,unsigned p){const auto h=a.create_file_a(name(p),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(h!=INVALID_HANDLE_VALUE&&a.close_handle(h)!=FALSE,"1258 genuine positive physical availability");}
unsigned open(FileApi&a,unsigned p){probe(a,p);const auto h=a.create_file_a(name(p),GENERIC_READ,3u,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(h!=INVALID_HANDLE_VALUE,"1258 genuine physical Open1");return pointer(h);}
void init_file(Heap&h,unsigned p,unsigned filename){h.w32(p,0x7856a0u);h.w32(p+4u,1u);h.w32(p+8u,0u);h.w32(p+12u,0xffffffffu);h.w32(p+16u,0xffffffffu);h.w32(p+20u,filename);for(unsigned k=24u;k<28u;++k)h.w8(p+k,0u);h.w8(p+28u,1u);for(unsigned k=32u;k<=37u;++k)h.w8(p+k,0u);for(unsigned k=40u;k<=76u;k+=4u)h.w32(p+k,k==60u||k==64u?0xffffffffu:0u);h.w8(p+80u,0u);h.w32(p+84u,0u);h.w32(p+88u,0u);h.w8(p+92u,0u);h.w32(p+96u,0u);}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,FileApi&a,Observation&o){
 need(root==0x11c0u&&i.cx==0x7b7cccu&&i.dx==0u,"1258 original public audio basename and proved NULL directory");
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0xa588e0u)==0u&&m.r32(0x838be0u)==0u&&m.r8(0xa9e184u)==0u,"1258 cold ordinary physical/ASCII route");const char expected[]="audio";for(unsigned k=0;k<sizeof(expected);++k)need(m.r8(i.cx+k)==unsigned(expected[k]),"1258 actual original literal");
 o.owner=h.allocate(0x124u);zero(h,o.owner,0x124u);
 // Original779146/779010 clones the private produced name;5928A0 then
 //781B14 uppercases it before checking the original empty archive table.
 o.index_name=h.allocate(10u);copy(h,o.index_name,"audio.idx");upper(h,o.index_name);probe(a,o.index_name);
 o.file=h.allocate(100u);o.bag_name=h.allocate(10u);copy(h,o.bag_name,"audio.bag");init_file(h,o.file,o.bag_name);h.w32(o.owner+0x10cu,o.file);upper(h,o.bag_name);probe(a,o.bag_name);
 o.index_handle=open(a,o.index_name);o.bag_handle=open(a,o.bag_name);h.w32(o.file+16u,o.bag_handle);
 std::array<unsigned char,12>header;DWORD got=0u;need(a.read_file(handle(o.index_handle),header.data(),12u,&got,nullptr)!=FALSE&&got==12u,"1258 real complete header producer");o.header_version=word(header.data()+4u);o.count=word(header.data()+8u);need(o.header_version==2u&&o.count==1u,"1258 actual version2 one-record route");h.w32(o.owner+4u,o.count);
 o.index=h.allocate(36u*o.count);h.w32(o.owner,o.index);zero(h,o.index,36u*o.count);need(a.read_file(handle(o.index_handle),reinterpret_cast<void*>(std::uintptr_t(o.index)),36u*o.count,&got,nullptr)!=FALSE&&got==36u*o.count,"1258 actual complete index bytes drive retained owner");
 // Original76D686 count1 exits at76D698 before comparator/private data use.
 h.w32(o.owner+0x114u,0u);need(a.close_handle(handle(o.index_handle))!=FALSE,"1258 real local index close");need(h.release(o.index_name)!=0u,"1258 original local filename destructor");return o.owner;
}
unsigned cleanup(Heap&h,FileApi&a,const Observation&o){
 // Original401580 ->4019A0 ->42F250 ->630060, outside candidate credit.
 h.w32(o.file,0x793c84u);need(a.close_handle(handle(o.bag_handle))!=FALSE,"1258 outside retained genuine handle close");h.w32(o.file+16u,0xffffffffu);need(h.release(o.bag_name)!=0u,"1258 outside owned name free");h.w32(o.file+20u,0u);h.w8(o.file+28u,0u);h.w32(o.file,0x793c3cu);need(h.release(o.file)!=0u,"1258 outside owned CCFile free");need(h.release(o.index)!=0u,"1258 outside owned index free");return h.release(o.owner);
}
}
