#include "recovered/recovery_b1094.hpp"
#include "recovered/name_hash.hpp"
#include <stdexcept>
#include <vector>
namespace ra2::recovered::b1094 {
namespace {
void need(bool v){if(!v)throw std::domain_error("1094 positive physical BUILDNGZ.SHP size and same complete cached bytes");}
void word(Observation&o,unsigned p,unsigned n){for(unsigned k=0;k<4u;++k)o.file.at(p+k)=static_cast<unsigned char>(n>>(8u*k));}
unsigned cached(Memory&m,unsigned name){
 need(m.r32(0xb10530u)==0u);std::vector<unsigned char>s;
 for(unsigned k=0;k<32u;++k){const auto c=m.r8(name+k);if(!c)break;need(c>=0x20u&&c<=0x7eu&&!(c>='a'&&c<='z'));s.push_back(static_cast<unsigned char>(c));}
 need(s.size()==12u);NameHashState state{};const auto key=fun_00493da0(state,s.data(),static_cast<int>(s.size()));auto owner=m.r32(0xa588e0u);
 for(unsigned chain=0;owner&&chain<2u;++chain){const auto next=m.r32(owner+4u);need(next&&m.r32(owner+8u));auto count=m.r32(owner+0x14u),table=m.r32(owner+0x20u);need(count==0u||count==4u);
  while(count){const auto middle=count/2u,entry=table+middle*12u,hash=m.r32(entry);if(global_b26::s32(hash)>global_b26::s32(key))count=middle;else if(hash==key){const auto backing=m.r32(owner+0x24u);need(backing);return backing+m.r32(entry+4u);}else{table=entry+12u;count-=middle+1u;}}owner=next;
 }throw std::domain_error("1094 genuine positive loaded BUILDNGZ.SHP cache hit required");
}
unsigned half(Heap&h,unsigned p){return h.r8(p)|(h.r8(p+1u)<<8u);}
}
unsigned run(Memory&m,const Inputs&,Heap&h,Api&a,State&,Observation&o){
 need(m.r32(0x8385e4u)==0u&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);
 constexpr unsigned source_name=0x7bad48u;for(unsigned k=0;k<13u;++k)need(m.r8(source_name+k)==static_cast<unsigned char>("BUILDNGZ.SHP"[k]));
 // Exact468B70/46F990/42F1F0/438140 construction and630110 owned clone.
 o.name=h.allocate(13u);need(o.name);for(unsigned k=0;k<13u;++k)h.w8(o.name+k,m.r8(source_name+k));
 word(o,0u,0x7856a0u);word(o,4u,1u);word(o,0xcu,0xffffffffu);word(o,0x10u,0xffffffffu);word(o,0x14u,o.name);o.file[0x1cu]=1u;word(o,0x3cu,0xffffffffu);word(o,0x40u,0xffffffffu);
 const auto path=reinterpret_cast<const char*>(std::uintptr_t(o.name));
 const auto close=[&](HANDLE p){need(a.close_handle(p)!=FALSE);word(o,0x10u,0xffffffffu);};
 const auto probe=[&](){auto p=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(p!=INVALID_HANDLE_VALUE);word(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(p)));close(p);};
 //68D70 physical availability, then68E40 Open(1)'s physical probe. No cache
 // lookup is reached by either success path. No ReadFile or seek occurs.
 probe();probe();auto file=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(file!=INVALID_HANDLE_VALUE);word(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(file)));o.size=a.size(file,nullptr);need(o.size>=33u&&o.size<32768u);word(o,0xcu,o.size);close(file);
 //438290/42F250/630060: free the filename BEFORE root's exact-size allocation.
 o.filename_free=h.release(o.name);need(o.filename_free!=0u);word(o,0u,0x793c3cu);word(o,0x14u,0u);o.file[0x1cu]=0u;
 o.payload=h.allocate(o.size);need(o.payload);m.w32(0x8385e4u,o.payload);const auto source=cached(m,source_name);for(unsigned k=0;k<o.size;++k)h.w8(o.payload+k,m.r8(source+k));
 const auto count=half(h,o.payload+6u),offset=h.r32(o.payload+0x1cu);const auto width=static_cast<std::int16_t>(half(h,o.payload+2u)),height=static_cast<std::int16_t>(half(h,o.payload+4u));need(count>0u&&offset>=32u&&width>0&&height>0&&offset+unsigned(width)*unsigned(height)<=o.size);
 auto eax=unsigned(int(height));auto pixels=o.payload+offset;
 for(int y=0;y<height;++y){for(int x=0;x<width;++x){auto low=h.r8(pixels+unsigned(x));eax=(eax&0xffffff00u)|low;if(low){low=(low-0x41u)&255u;h.w8(pixels+unsigned(x),low);eax=(eax&0xffffff00u)|low;}}pixels+=unsigned(width);}
 return eax;
}
}
