#include "numeric_b80.hpp"
#include "platform/x87_integer_subtract_b42.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::numeric_b80 {
namespace extra_detail {
using namespace floating_b61;
using global_b26::imul_high;
namespace fp=ra2::platform::x87;
namespace ext=ra2::platform::x87_extended;
namespace sub=ra2::platform::x87_integer_subtract;
// Each operation restores host state; temporaries are host locals. No invented
// guest stack or writes outside the original input/output fields are introduced.
template<unsigned Code> void reg(fp::State&f){
 f.require_masked();fp::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte %c[a],%c[b]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[a]"i"(Code>>8),[b]"i"(Code&255):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
void reverse_divide64(fp::State&f,std::uint64_t v){f.require_masked();fp::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfdivrl %[v]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
std::uint32_t integer(Memory&m,fp::State&f){const auto c=m.r32(0x7c3a04u);if(f.control()!=c)f.load_control(std::uint16_t(c));return std::uint32_t(f.pop_integer64());}
// Original ba080 table approximation, including its two compares and single
// precision intermediate. This deliberately does not substitute std::sqrt.
void root(Memory&m,fp::State&f,std::uint64_t v){f.load64(v);f.compare32(m.r32(0x785738u));if(f.status()&0x4000u){f.pop_st0();f.load32(m.r32(0x785738u));return;}f.compare32(m.r32(0x785738u));if(f.status()&0x4100u)f.multiply64(read64(m,0x788578u));const auto bits=f.pop32();auto e=(bits>>23)-127u,man=bits&0x7fffffu;if(e&1u)man|=0x800000u;e=sx16(sar(sx16(e),1));f.load32(m.r32(0x80013cu+(man>>10)*4u)+((e+127u)<<23));}
std::uint32_t trig(Memory&m,fp::State&f,std::uint64_t v,bool cosine){f.load64(v);f.multiply32(m.r32(cosine?0x7c313cu:0x7c3138u));const auto integral=integer(m,f),odd=integral&1u;auto index=sar(integral-(s32(integral)<0?0xffffffffu:0u),1)&0x80001fffu;if(s32(index)<0){--index;index|=0xffffe000u;++index;if(s32(index)<0)index+=cosine?0x2800u:0x2000u;}else if(cosine)index+=0x800u;if(odd&&s32(index)<(cosine?0x27ff:0x1fff))++index;f.load32(m.r32(0x7ea104u+index*4u));return index;}
void acos_table(Memory&m,fp::State&f,std::uint64_t v){f.load64(v);f.add32(m.r32(0x7867f8u));f.multiply32(m.r32(0x78bf88u));const auto offset=integer(m,f)*4u;f.load32(m.r32(0x7f4114u-offset));f.reverse_subtract64(read64(m,0x786630u));}
// Exact ba270 numeric stack contract: two doubles rounded to float; ratio is
// converted through 76aa50, then its original table/quadrant adjustments.
void angle(Memory&m,fp::State&f,std::uint64_t a,std::uint64_t b){f.load64(b);const auto bf=f.pop32();f.load64(a);const auto af=f.pop32();f.load32(bf);f.compare_pop32(m.r32(0x785738u));f.load32(af);if(f.status()&0x4000u){f.compare_pop32(m.r32(0x785738u));if(f.status()&0x4000u){f.load32(m.r32(0x785738u));return;}f.load32(af);f.compare_pop32(m.r32(0x785738u));f.load32(m.r32((f.status()&0x4100u)?0x78bf90u:0x78bf8cu));return;}
 ext::divide32(f,bf);ext::divide32(f,m.r32(0x800138u));auto n=integer(m,f);if(s32(n)<0)n=0u-n;f.load32(m.r32(s32(n)>=4097?0x78bf8cu:0x7fc134u+n*4u));f.load32(bf);f.compare_pop32(m.r32(0x785738u));if(f.status()&0x100u)f.reverse_subtract64(read64(m,0x788158u));f.load32(af);f.compare_pop32(m.r32(0x785738u));if(f.status()&0x100u)f.change_sign();}
std::uint32_t half_toward_zero(std::uint32_t n){return sar(n-(s32(n)<0?0xffffffffu:0u),1);}
std::uint32_t div256(std::uint32_t n){return sar(n+(s32(n)<0?255u:0u),8);}
}
std::uint32_t fun_00697de0(Memory&m,const Inputs&i){using namespace extra_detail;const auto src=i.arg[1],x=m.r32(src),y=m.r32(src+4),z=m.r32(src+8);i.arg[1]=s32(z)>=728?1u:0u;const auto a=half_toward_zero(x*60u)+half_toward_zero(0u-y*60u),b=half_toward_zero(x*30u)+half_toward_zero(y*30u);i.fp.load_integer32(z);i.fp.multiply64(read64(m,0xaa5f90u));ext::add_integer32(i.fp,i.arg[1]);i.fp.add64(read64(m,0x785728u));const auto height=integer(m,i.fp);m.w32(i.arg[0],div256(a));m.w32(i.arg[0]+4,div256(b)-height);return i.arg[0];}
std::uint32_t fun_004ea260(Memory&m,const Inputs&i){using namespace extra_detail;const auto p=i.arg[0],r=i.cx;if(m.r32(p)==m.r32(0xa28b90u)&&m.r32(p+4)==m.r32(0xa28b94u)&&m.r32(p+8)==m.r32(0xa28b98u))return 0xffffffffu;const auto dx=m.r32(r+0x53bcu)-m.r32(p),dy=m.r32(r+0x53c0u)-m.r32(p+4),dz=m.r32(r+0x53c4u)-m.r32(p+8);auto&f=i.fp;f.load_integer32(dy);f.load_integer32(dz);f.load_integer32(dx);f.load_st0();ext::multiply_st1(f);f.load_st2();ext::multiply_st3(f);f.add_pop();ext::load_st3(f);ext::multiply_st4(f);f.add_pop();const auto squared=f.pop64();f.pop_st0();f.pop_st0();f.pop_st0();root(m,f,squared);const auto distance=integer(m,f),radius=m.r32(r+0x53c8u);if(s32(distance)<=s32(radius))return 0;if(s32(distance)>s32(radius<<2))return 0xffffffffu;
 // The original overwrites only the low word of its raw argument pointer,
 // after first replacing that caller word with the queried X coordinate.
 i.arg[0]=m.r32(p);f.load_integer32(i.arg[0]);sub::subtract_integer32(f,m.r32(r+0x53bcu));const auto b=f.pop64();f.load_integer32(m.r32(r+0x53c0u));sub::subtract_integer32(f,m.r32(p+4));const auto a=f.pop64();angle(m,f,a,b);f.subtract64(read64(m,0x786630u));f.multiply64(read64(m,0x786628u));const auto quantized=integer(m,f);i.arg[0]=(i.arg[0]&0xffff0000u)|(quantized&65535u);const auto sector=(((i.arg[0]>>7)+1u)>>1)&255u;if(sector>32u&&sector<224u)return 1;if(sector>160u&&sector<96u)return 3;return sector<=32u?2u:4u;}
std::uint32_t fun_0061a7f0(Memory&m,const Inputs&i){using namespace extra_detail;auto&f=i.fp;const auto in=i.dx,out=i.cx;std::array<std::uint32_t,4> q{0,0,0,0x3f800000u};f.load32(m.r32(in+40));f.add32(m.r32(in+20));f.add32(m.r32(in));ext::compare64(f,read64(m,0x786610u));if(f.status()&0x4000u){f.pop_st0();for(unsigned k=0;k<4;++k)m.w32(out+k*4,q[k]);return out;}ext::compare64(f,read64(m,0x786610u));if(!(f.status()&0x4100u)){f.add64(read64(m,0x785708u));const auto value=f.pop64();root(m,f,value);f.load_st0();f.multiply64(read64(m,0x785728u));q[3]=f.pop32();reverse_divide64(f,read64(m,0x785728u));f.load32(m.r32(in+36));f.subtract32(m.r32(in+24));ext::multiply_st1(f);q[0]=f.pop32();f.load32(m.r32(in+8));f.subtract32(m.r32(in+32));ext::multiply_st1(f);q[1]=f.pop32();f.load32(m.r32(in+16));f.subtract32(m.r32(in+4));ext::multiply_st1(f);q[2]=f.pop32();f.pop_st0();}else{f.pop_st0();unsigned k=0;f.load32(m.r32(in+20));f.load32(m.r32(in));f.compare_pop_twice();if(f.status()&0x100u)k=1;const unsigned diagonal[]{0,5,10};f.load32(m.r32(in+40));f.load32(m.r32(in+diagonal[k]*4));f.compare_pop_twice();if(f.status()&0x100u)k=2;unsigned j=k==0?1:k==1?2:0,l=k==0?2:k==1?0:1;f.load32(m.r32(in+diagonal[k]*4));f.load32(m.r32(in+diagonal[j]*4));f.load32(m.r32(in+diagonal[l]*4));reg<0xd8c1>(f);reg<0xd8ea>(f);f.add64(read64(m,0x785708u));const auto value=f.pop64();f.pop_st0();f.pop_st0();root(m,f,value);f.load_st0();f.multiply64(read64(m,0x785728u));q[k]=f.pop32();reverse_divide64(f,read64(m,0x785728u));f.load32(m.r32(in+(j+l*4)*4));f.subtract32(m.r32(in+(l+j*4)*4));ext::multiply_st1(f);q[3]=f.pop32();f.load32(m.r32(in+(k+j*4)*4));f.add32(m.r32(in+(j+k*4)*4));ext::multiply_st1(f);q[j]=f.pop32();f.load32(m.r32(in+(k+l*4)*4));f.add32(m.r32(in+(l+k*4)*4));ext::multiply_st1(f);q[l]=f.pop32();f.pop_st0();}for(unsigned k=0;k<4;++k)m.w32(out+k*4,q[k]);return out;}
std::uint32_t fun_0061a650(Memory&m,const Inputs&i){using namespace extra_detail;auto&f=i.fp;const auto a=i.dx,b=i.arg[0],out=i.cx,t=i.arg[1];f.load32(m.r32(a+12));f.multiply32(m.r32(b+12));f.load32(m.r32(a+8));f.multiply32(m.r32(b+8));f.add_pop();f.load32(m.r32(a+4));f.multiply32(m.r32(b+4));f.add_pop();f.load32(m.r32(a));f.multiply32(m.r32(b));f.add_pop();const auto dot=f.store64();f.add64(read64(m,0x785708u));f.compare_pop64(read64(m,0x787520u));std::uint64_t first;
 if(!(f.status()&0x4100u)){f.load64(read64(m,0x785708u));f.subtract64(dot);f.compare_pop64(read64(m,0x787520u));if(!(f.status()&0x4100u)){acos_table(m,f,dot);const auto theta=f.pop64();trig(m,f,theta,false);const auto denominator=f.pop64();f.load32(m.r32(0x7867f8u));f.subtract32(t);f.multiply64(theta);const auto arg=f.pop64();trig(m,f,arg,false);f.divide64(denominator);first=f.pop64();f.load32(t);f.multiply64(theta);const auto arg2=f.pop64();trig(m,f,arg2,false);f.divide64(denominator);}else{f.load32(m.r32(0x7867f8u));f.subtract32(t);first=f.pop64();f.load32(t);}}else{f.load32(m.r32(0x7867f8u));f.subtract32(t);f.multiply64(read64(m,0x793620u));const auto arg=f.pop64();trig(m,f,arg,false);first=f.pop64();f.load32(t);f.multiply64(read64(m,0x793620u));const auto arg2=f.pop64();trig(m,f,arg2,false);}
 std::array<std::uint32_t,4> q{};for(unsigned k=0;k<4;++k){f.load32(m.r32(b+k*4));ext::multiply_st1(f);f.load32(m.r32(a+k*4));f.multiply64(first);f.add_pop();q[k]=f.pop32();}for(unsigned k=0;k<4;++k)m.w32(out+k*4,q[k]);f.pop_st0();return out;}
std::uint32_t fun_00590fb0(Memory&m,const Inputs&i){using namespace extra_detail;auto&f=i.fp;const auto p=i.cx;f.load64(read64(m,p+8));f.load64(read64(m,p));f.load_st0();ext::multiply_st1(f);f.load_st2();ext::multiply_st3(f);f.add_pop();const auto square=f.pop64();f.pop_st0();f.pop_st0();root(m,f,square);const auto planar=f.pop64();angle(m,f,read64(m,p+16),planar);f.subtract64(read64(m,0x786630u));f.multiply64(read64(m,0x786628u));const auto word=integer(m,f);f.load_integer32(sx16(word)-0x3fffu);f.multiply64(read64(m,0x786620u));const auto original_angle=f.pop64();
 f.load64(read64(m,p+16));f.load64(read64(m,p+8));f.load64(read64(m,p));f.load_st2();ext::multiply_st3(f);f.load_st1();ext::multiply_st2(f);f.add_pop();f.load_st2();ext::multiply_st3(f);f.add_pop();const auto all_square=f.pop64();f.pop_st0();f.pop_st0();f.pop_st0();root(m,f,all_square);const auto magnitude=f.pop64();f.load64(original_angle);f.compare_pop64(read64(m,0x786610u));if(!(f.status()&0x4000u)){trig(m,f,original_angle,true);reverse_divide64(f,read64(m,p));write64(m,p,f.pop64());trig(m,f,original_angle,true);reverse_divide64(f,read64(m,p+8));write64(m,p+8,f.pop64());}
 auto load_angle=[&](){f.load_integer32(sx16(m.r16(i.arg[0]))-0x3fffu);f.multiply64(read64(m,0x786620u));return f.pop64();};trig(m,f,load_angle(),true);f.multiply64(read64(m,p));write64(m,p,f.pop64());trig(m,f,load_angle(),true);f.multiply64(read64(m,p+8));write64(m,p+8,f.pop64());const auto result=trig(m,f,load_angle(),false);f.multiply64(magnitude);write64(m,p+16,f.pop64());return result;}
// Original custom 12-byte representation: five 16-bit significand words plus
// sign/exponent word. Six-word product scratch and carry/shift helpers are local.
std::uint32_t fun_00780a28(Memory&m,const Inputs&i){using namespace extra_detail;const auto a=i.arg[0],b=i.arg[1];const auto ea=m.r16(a+10)&0x7fffu,eb=m.r16(b+10)&0x7fffu,sign=(m.r16(a+10)^m.r16(b+10))&0x8000u;auto exp=ea+eb;i.arg[0]=exp;
 auto special=[&](){m.w32(a,0);m.w32(a+4,0);m.w32(a+8,0x7fff8000u+(sign?0x80000000u:0u));return ea;};
 if(ea>=0x7fff||eb>=0x7fff||exp>0xbffdu)return special();
 if(exp<=0x3fbfu){m.w32(a,0);m.w32(a+4,0);m.w32(a+8,0);return 0;}
 if(!ea){++exp;i.arg[0]=exp;if(!(m.r32(a+8)&0x7fffffffu)&&!m.r32(a+4)&&!m.r32(a)){m.w16(a+10,0);return 0;}}
 if(!eb){++exp;i.arg[0]=exp;if(!(m.r32(b+8)&0x7fffffffu)&&!m.r32(b+4)&&!m.r32(b)){m.w32(a,0);m.w32(a+4,0);m.w32(a+8,0);return 0;}}
 std::array<std::uint16_t,6> q{};i.arg[1]=5;
 for(unsigned k=0;k<5;++k){for(unsigned j=0;j<5-k;++j){const auto product=m.r16(a+(k+j)*2)*m.r16(b+(4-j)*2);const auto value=std::uint64_t(q[k])+(std::uint64_t(q[k+1])<<16)+product;q[k]=std::uint16_t(value);q[k+1]=std::uint16_t(value>>16);if(value>>32)++q[k+2];}--i.arg[1];}
 exp+=0xc002u;i.arg[0]=exp;
 auto left=[&](){unsigned carry=0;for(auto&v:q){const auto next=v>>15;v=std::uint16_t((v<<1)|carry);carry=next;}};
 auto right=[&](){unsigned carry=0;for(unsigned n=6;n-->0;){const auto next=q[n]&1u;q[n]=std::uint16_t((q[n]>>1)|(carry<<15));carry=next;}};
 while(s32(sx16(exp))>0&&!(q[5]&0x8000u)){left();exp+=0xffffu;i.arg[0]=exp;}
 if(s32(sx16(exp))<=0){exp+=0xffffu;i.arg[0]=exp;if(s32(sx16(exp))<0){const auto count=0u-sx16(exp);exp+=count;i.arg[0]=exp;bool sticky=false;for(auto n=0u;n<count;++n){sticky|=(q[0]&1u)!=0;right();}if(sticky)q[0]|=1u;}}
 if(q[0]>0x8000u||(q[0]==0x8000u&&(q[1]&1u))){unsigned n=1;while(n<6&&q[n]==65535u){q[n]=0;++n;}if(n==6){++exp;i.arg[0]=exp;q[5]=0x8000u;}else ++q[n];}
 if((exp&65535u)>=0x7fffu){special();return exp;}for(unsigned n=0;n<5;++n)m.w16(a+n*2,q[n+1]);m.w16(a+10,exp|sign);return exp|sign;
}
}

