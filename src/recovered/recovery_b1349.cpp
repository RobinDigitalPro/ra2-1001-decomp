#include "recovery_b1349.hpp"
#include <stdexcept>
namespace ra2::recovered::b1349 {
namespace {
using U=std::uint32_t;using X=ra2::platform::x87::State;
void need(bool ok,const char*s){if(!ok)throw std::domain_error(s);}
void fiadd(X& fp,U operand){fp.require_masked();ra2::platform::x87::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfiaddl %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
 :[host]"=m"(host.bytes),[guest]"+m"(fp.image.bytes):[operand]"m"(operand):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
U convert(Memory&m,X&fp){const U cw=m.r16(0x7c3a04);if(fp.control()!=cw)fp.load_control_masked(cw);return U(fp.pop_integer64());}
void trig(Memory&m,X&fp,std::uint64_t angle,bool cosine){
 fp.load64(angle);fp.multiply32(m.r32(cosine?0x7c313c:0x7c3138));
 const U scaled=convert(m,fp);need(scaled==0,"B1349 zero-angle original LUT index");
 fp.load32(m.r32(cosine?0x7ec104:0x7ea104));
}
void point(Memory&m,X&fp,U target,U distance,U out){
 // Exact 4B8850 nonpositive-rate branch: copy the current direction DWORD.
 const U direction=m.r32(target+0x2e0);need(m.r16(target+0x2f4)==0&&(direction&0xffff)==0x3fff,"B1349 fixed zero-radian direction");
 const U x=m.r32(target+0x88),y=m.r32(target+0x8c),z=m.r32(target+0x90);
 fp.load_integer32(0);fp.multiply64(floating_b61::read64(m,0x786620));const auto angle=fp.pop64();
 fp.load_integer32(distance);const auto amount=fp.pop64();
 fp.load_integer32(y);const auto fy=fp.pop64();
 trig(m,fp,angle,false);fp.multiply64(amount);fp.reverse_subtract64(fy);const U oy=convert(m,fp);
 trig(m,fp,angle,true);fp.multiply64(amount);fiadd(fp,x);const U ox=convert(m,fp);
 m.w32(out,ox);m.w32(out+4,oy);m.w32(out+8,z);
}
}
U fun_00434090(Memory&m,const Inputs&i){
 const U self=i.cx,target=i.arg[0],rules=m.r32(0x821b88);
 need(m.r32(self)==0x78612c&&m.r32(0x7862c8)==0x4c9d60&&m.r8(self+0x74)==0,"B1349 genuine nonplaced actor setter route");
 need(i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&0x3800)==0,"B1349 empty incoming x87 stack");
 const U forward=m.r32(rules+0x6b4),back=m.r32(rules+0x6b0);
 need(forward>=1&&forward<=32&&back>=1&&back<=64,"B1349 positive finite offset rules");
 const U x=m.r32(target+0x88),y=m.r32(target+0x8c),z=m.r32(target+0x90);
 need(x>=128&&x<=2175&&y>=64&&y<=1087&&z<=255,"B1349 bounded integer coordinate inputs");
 need(m.r16(0x7c3a04)==0x0e7f&&m.r32(0x7ea104)==0&&m.r32(0x7ec104)==0x3f800000,"B1349 exact original numeric constants");
 point(m,i.fp,target,forward,self+0xac);point(m,i.fp,target,0u-back,self+0xa0);
 // Genuine78612C+19C=4C9D60, self74=0 calls 5CD850: three stores.
 m.w32(self+0x88,m.r32(self+0xac));m.w32(self+0x8c,m.r32(self+0xb0));m.w32(self+0x90,m.r32(self+0xb4));
 return m.r32(self+0xb4);
}
}
