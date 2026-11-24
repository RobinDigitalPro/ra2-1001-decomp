#include "recovered/recovery_b1083.hpp"
#include "recovered/recovery_b1063.hpp"
#include "recovered/global_b60_c.hpp"
#include "recovered/leaf_b56_b.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1083 {namespace {
void need(bool v){if(!v)throw std::domain_error("1083 outside positive one-row base palette constructors");}
std::uint64_t read64(Memory&m,unsigned p){return std::uint64_t(m.r32(p))|(std::uint64_t(m.r32(p+4u))<<32u);}
unsigned truncate(Memory&m,State&fp){const auto control=std::uint16_t(m.r32(0x7c3a04u));if(fp.control()!=control)fp.load_control(control);return unsigned(fp.pop_integer64());}
// Exact accepted4BA0F0/140 table-index semantics, no sin/cos provider.
void table_trig(Memory&m,State&fp,std::uint64_t argument,bool quarter_turn){fp.load64(argument);fp.multiply32(m.r32(quarter_turn?0x7c313cu:0x7c3138u));const auto v=std::int32_t(truncate(m,fp));const unsigned odd=unsigned(v)&1u;const auto absolute=unsigned(v<0?-std::int64_t(v):v);unsigned index=(absolute/2u)&0x1fffu;if(quarter_turn)index+=v<0?0x2800u:0x800u;if(odd&&index<(quarter_turn?0x27ffu:0x1fffu))++index;need(v>=0&&index<10240u);fp.load32(m.r32(0x7ea104u+4u*index));}
}
unsigned fun_0065a790(Memory&m,const Inputs&i,Heap&h,State&fp){
 need(i.arg[0]==0x820150u&&i.arg[2]!=0u);const auto surface=i.arg[1];
 need(m.r32(surface)==0x78bbe4u&&m.r32(0x78bc54u)==0x4aa970u&&m.r32(surface+0x10u)==2u);
 std::array<unsigned char,768>pal{};leaf::Memory local(pal.data(),0x11000u,768u);Memory v=m;v.add(local);Inputs j=i;j.arg[1]=0x11000u;
const unsigned hue=m.r8(i.cx),saturation=m.r8(i.cx+1u),value=m.r8(i.cx+2u);need(hue>=1u&&hue<=254u&&saturation>=16u&&saturation<=207u&&value>=32u&&value<=223u);for(unsigned k=0;k<768u;++k)v.w8(j.arg[1]+k,m.r8(i.dx+k));
 fp.load_integer32(saturation);const auto saturation64=fp.pop64();fp.load_integer32(value);const auto value64=fp.pop64();std::array<unsigned char,6>hsv{};leaf::Memory hsv_span(hsv.data(),0x10000u,6u);
 for(unsigned j=0;j<16u;++j){fp.load_integer32(j);fp.load_st0();fp.multiply64(read64(m,0x7940f0u));fp.add64(read64(m,0x7940e8u));auto a=fp.pop64();fp.multiply64(read64(m,0x7940e0u));fp.add64(read64(m,0x7940d8u));const auto b=fp.pop64();if(j==0u)a=0x3fc921fb54442d18ull;table_trig(m,fp,b,false);fp.multiply64(saturation64);const auto x=truncate(m,fp);table_trig(m,fp,a,true);fp.multiply64(value64);const auto y=truncate(m,fp);hsv[0]=static_cast<unsigned char>(hue);hsv[1]=static_cast<unsigned char>(x);hsv[2]=static_cast<unsigned char>(y);leaf::Inputs convert{};convert.cx=0x10000u;convert.arg[0]=0x10003u;leaf::fun_004fe550(hsv_span,convert);for(unsigned k=0;k<3u;++k)v.w8(0x11000u+3u*(j+16u)+k,hsv[3u+k]);}

 for(unsigned k=0;k<768u;++k)m.w8(i.arg[2]+k,pal[k]);
 const auto p=h.allocate(0x188u);need(p!=0u);leaf::Memory owner_span(reinterpret_cast<unsigned char*>(std::uintptr_t(p)),p,400u);v.add(owner_span);
 v.w32(p+4u,2u);for(unsigned off=8u;off<=0x168u;off+=4u)v.w32(p+off,0u);v.w32(p+0x16cu,1u);for(unsigned off=0x170u;off<=0x17cu;off+=4u)v.w32(p+off,0u);v.w32(p,0x788f70u);
 const auto out=h.allocate(512u);need(out!=0u);v.w32(p+0x170u,out);v.w32(p+0x174u,out);leaf::Memory output_span(reinterpret_cast<unsigned char*>(std::uintptr_t(out)),out,512u);v.add(output_span);
 global_b26::Inputs fill{};fill.cx=out;fill.dx=1u;fill.arg[0]=0x11000u;global_b26::fun_004ab710(v,fill);
 v.w32(p+0x180u,m.r16(0x83b300u));v.w32(p+0x184u,m.r16(0x83b302u));Inputs factory{};factory.cx=p;b1063::fun_004838e0(v,factory,h);
 const auto count=m.r32(0x839490u),data=m.r32(0x839484u);need(count==1u&&m.r32(0x839488u)==10u&&data);m.w32(0x839490u,2u);h.w32(data+4u,p);
 return p;
}
}
