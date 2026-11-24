#include "recovered/recovery_b1505.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1505 {namespace {
void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
void fp_domain(const platform::x87::Image&f){
 constexpr unsigned short CW[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool valid=false;for(auto c:CW)valid|=f.word(0)==c;need(valid,"1505 twelve validmasked CW");const U sw=f.word(4),top=(sw>>11)&7,tag=f.word(8);need((sw&~0x7f3fu)==0,"1505 TOP/conditions andmaskedsticky0..5 only");bool empty=false;
 for(U k=0;k<8;++k){U t=(tag>>(2*((top+k)&7)))&3;need(t==0||t==3,"1505 finite normal valid or empty");if(t==3)empty=true;else{need(!empty,"1505 contiguous live stack");const U e=(f.bytes[36+10*k]|(U(f.bytes[37+10*k])<<8))&0x7fff;need((f.bytes[35+10*k]&0x80)&&e>0&&e<0x7fff,"1505 normal raw80 livevalue");}if(k==7)need(t==3,"1505 depth8 excluded before FLD");}
}
U lookup_4d56d0(Memory&m,U vector,U key){
 need(m.r32(vector)==0x78da24&&m.r32(0x78da34)==0x4d56d0,"1505 actualHousevector lookupslot");const U count=m.r32(vector+0x10),array=m.r32(vector+4);need(count>=1&&count<=4&&m.r32(vector+8)>=count,"1505 genuine nonempty boundedvector");for(U k=0;k<count;++k)if(m.r32(array+4*k)==key)return k;throw std::domain_error("1505 positiveactualobjectlookup required");
}
void case0_692ef0(Memory&m,U object,U house){
 const U count=m.r32(0xa1e018),records=m.r32(0xa1e00c);need(count>=1&&count<=4,"1505 actual nonempty registry");for(U k=0;k<count;++k)need(m.r8(m.r32(records+4*k)+0x1354)==0,"1505 actualcase0 ineligible-record loop");
 need(m.r32(object+0x28)==house&&m.r8(house+0x144)==1,"1505 constructorHouse144 already1");m.w8(house+0x144,1); // actualstore, notclaimedtransition
}
U active_692730(Memory&m,U object,U house){
 const U d=m.r32(object+0x24);need(m.r8(d+0xdd)==0&&m.r8(d+0xe1)==0&&m.r32(d+0xb4)==0,"1505 actualType0/DD0/PostClickfalse");need(m.r32(object+0x2c)!=0xffffffff&&m.r8(object+0x55)==1&&m.r8(object+0x57)==1,"1505 genuinelyactive/granted/ready object");need(m.r8(object+0x56)==0&&m.r8(d+0xe9)==0&&m.r8(d+0xe0)==1,"1505 producerbackedPreClick activeleg beforetimerreads");
 case0_692ef0(m,object,house);m.w8(object+0x57,0);
 // 692973 PreClicktrue exits692A21. Opaque30/34/38 neverconsumed here.
 return d;
}
U tail_4e5f70(Memory&m,U house,U index,U coordinate){
 const U object=m.r32(m.r32(house+0x1a0)+4*index),d=m.r32(object+0x24);need(m.r8(d+0xe1)==0&&m.r32(object+0x28)==house&&m.r32(0xa1e0e4)!=house,"1505 actualsameHouseowner andgenuineothercurrentHouse UIlowbyte0");(void)coordinate; // Type0 selectedleg doesnotdereferencecoordinate
 (void)active_692730(m,object,house);need(m.r32(object+0x24)==d,"1505 descriptoridentityretained");return(d&0xffffff00u)|1;
}
}
U fun_004f3150(Memory&public_memory,const Inputs&i){
 fp_domain(i.fp.image);const U house=i.cx;need(public_memory.r32(house+0x54f0)==0xffffffff&&public_memory.r32(house+0x541c)==1,"1505 genuineHouseconstructor modevalues");
 std::array<std::uint8_t,64> scratch;constexpr U base=0x7db00000,origin=base+8,reference=base+12,out=base+16;ra2::recovered::leaf::Memory local(scratch.data(),base,scratch.size());Memory m=public_memory;m.add(local);
 const auto x=static_cast<U>(static_cast<std::int32_t>(m.r32(house+0x53bc))/256),y=static_cast<U>(static_cast<std::int32_t>(m.r32(house+0x53c0))/256);need(x>=64&&x<=67&&y>=64&&y<=67,"1505 B1421cellcenter64..67 projection");m.w16(origin,x);m.w16(origin+2,y);m.w32(reference,0);
 Inputs child{};child.ax=i.ax;child.cx=0x81a820;child.dx=i.dx;child.arithmetic_flags=i.arithmetic_flags;child.fp=i.fp;child.arg.fill(0);child.arg[0]=out;child.arg[1]=origin;child.arg[3]=0xffffffff;child.arg[6]=5;child.arg[7]=5;child.arg[11]=1;child.arg[12]=reference;
 // UnchangedB517 reserves/initializesits own7D100000span. Itslegacyminus8word
 // isunreadonthisselectedroute; no nativeprivateword isseeded bythisadapter.
 const U result=recovery_b517::fun_0054d770(m,child);i.fp=child.fp;need(result==out&&m.r16(out)==x&&m.r16(out+2)==y,"1505 actualradius0 selectedorigin returned");m.w16(origin,m.r16(out)+2);m.w16(origin+2,m.r16(out+2)+2);
 need(m.r32(0xa28b5c)==0&&m.r32(origin)!=0,"1505 adjustedcoordinate differsoriginalzerosentinel");const U index=lookup_4d56d0(m,house+0x19c,i.arg[0]);return tail_4e5f70(m,house,index,origin);
}
}
