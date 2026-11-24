#include "recovery_b381.hpp"
#include "name_hash.hpp"
#include "ini_lookup.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b381 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::array<std::uint8_t,64> text(const Memory&m,std::uint32_t p){
 need(p!=0,"381 requires nonnull text");std::array<std::uint8_t,64> v{};
 for(unsigned n=0;n<v.size();++n){v[n]=std::uint8_t(m.r8(p+n));if(!v[n])return v;}
 throw std::domain_error("381 bounded text must terminate in 64 bytes");
}
std::uint32_t hash(const std::array<std::uint8_t,64>&s){unsigned n=0;while(s[n])++n;return ini_name_hash(s.data(),n,nullptr);}
void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){throw std::domain_error("381 only initialized sorted indexes");}
std::uint32_t lookup(Memory&m,std::uint32_t index,std::uint32_t query,bool sections){
 const auto count=m.r32(index+4),nodes=m.r32(index),cached=m.r32(index+16);
 need(count>=1&&count<=16&&nodes&&m.r8(index+12)!=0&&m.r32(index+8)>=count,"381 bounded initialized index");
 std::array<IniIndexEntry,16> entries{};
 for(unsigned k=0;k<count;++k){entries[k].key=global_b26::s32(m.r32(nodes+8*k));if(k)need(entries[k-1].key<entries[k].key,"381 unique signed sorted keys");}
 IniIndex logical{entries.data(),static_cast<std::int32_t>(count),1,nullptr,count};
 if(cached){need(cached>=nodes&&(cached-nodes)%8==0&&(cached-nodes)/8<count,"381 readable cache in index");logical.cached=&entries[(cached-nodes)/8];}
 const auto signed_query=global_b26::s32(query);const IniOperations ops{ini_name_hash,no_sort,nullptr,nullptr,nullptr,nullptr};
 if(!logical.cached||logical.cached->key!=signed_query){
  logical.cached=sections?fun_005106d0(logical,&signed_query,ops):fun_005105a0(logical,&signed_query,ops);
  need(logical.cached!=nullptr,"381 positive indexed hit required");
  m.w32(index+16,nodes+8u*static_cast<unsigned>(logical.cached-entries.data()));
 }
 if(!sections)need(fun_00510220(logical,&signed_query,ops)!=0,"381 membership must preserve positive cache");
 const auto row=nodes+8u*static_cast<unsigned>(logical.cached-entries.data());
 const auto value=m.r32(row+4);need(value!=0,"381 nonnull index value");return value;
}
// Exact integer construction of binary32 for quarter-valued decimals <=255.75.
// This covers a finite scanner subset; it is not a general sscanf replacement.
std::uint32_t parse_quarters(const std::array<std::uint8_t,64>&s,unsigned&percent){
 unsigned at=0,whole=0,digits=0;
 while(s[at]>='0'&&s[at]<='9'){whole=whole*10+s[at++]-'0';++digits;need(digits<=3&&whole<=255,"381 integer part in0..255");}
 need(digits!=0,"381 decimal digits required");unsigned fraction=0;
 if(s[at]=='.'){
  ++at;const auto a=s[at++],b=s[at++];
  need((a=='0'&&b=='0')||(a=='2'&&b=='5')||(a=='5'&&b=='0')||(a=='7'&&b=='5'),"381 only exact quarter decimal fractions");
  fraction=a=='0'?0:a=='2'?1:a=='5'?2:3;
 }
 percent=s[at]=='%'?at:0;if(percent)++at;
 need(s[at]==0,"381 optional trailing percent only");
 const unsigned q=whole*4+fraction;need(q!=0,"381 positive nonzero decimal route");
 unsigned top=0;for(unsigned v=q;v>1;v>>=1)++top;
 return ((top+125u)<<23)|((q<<(23-top))&0x7fffffu);
}
}
std::uint32_t fun_0050d7f0(Memory&m,const Inputs&i){
 const auto receiver=i.cx;need(receiver!=0,"381 nonnull INI receiver");
 const auto section_name=text(m,i.arg[0]),key_name=text(m,i.arg[1]);
 const auto sh=hash(section_name);i.arg[0]=sh;i.arg[1]=sh;
 const auto section=lookup(m,receiver+0x20,sh,true);
 const auto kh=hash(key_name);i.arg[0]=kh;
 const auto value=lookup(m,section+0x2c,kh,false);const auto address=m.r32(value+0x10);const auto input=text(m,address);
 need(m.r8(0x7c6548)=='%'&&m.r8(0x7c6549)=='f'&&m.r8(0x7c654a)==0,"381 pinned %f literal");
 need(m.r32(0x8174a8)==0x7727a8&&m.r32(0x81776c)==1&&m.r8(0x817770)=='.',"381 initialized float dispatch and C decimal locale");
 unsigned percent=0;const auto bits=parse_quarters(input,percent);i.arg[1]=bits;
 // FLD float [entryESP+8], FSTP double [entryESP+12], then FLD that double.
 i.fp.load32(bits);const auto wide=i.fp.pop64();i.arg[2]=std::uint32_t(wide);i.arg[3]=std::uint32_t(wide>>32);
 i.fp.load64(wide);
 if(percent){need(floating_b61::read64(m,0x787518)==0x3f847ae147ae147bull,"381 original percent factor");i.fp.multiply64(floating_b61::read64(m,0x787518));}
 // Full EAX is strchr(value,'%'), while the floating result remains in ST0.
 return percent?address+percent:0;
}
}
