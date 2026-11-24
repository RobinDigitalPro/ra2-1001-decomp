#include "numeric_b80.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::numeric_b80 {
namespace extra_detail {
void root(Memory&,ra2::platform::x87::State&,std::uint64_t);
std::uint32_t integer(Memory&,ra2::platform::x87::State&);
}

namespace {
namespace fp = ra2::platform::x87;
namespace fp_ext = ra2::platform::x87_extended;
[[noreturn]] void outside(const char* why) { throw std::domain_error(why); }
void need(bool ok, const char* why) { if (!ok) outside(why); }

std::uint32_t timer_match(Memory& m, const Inputs& i, std::uint32_t tag) {
    const auto receiver=i.arg[0];
    if(!receiver) return floating_b61::with_al(i.ax,0u);
    const auto count=m.r32(receiver+0x1acu);
    if(static_cast<std::int32_t>(count)<=0) return 0u;
    need(count==1u,"numeric timer predicate fixture exceeds one-element bounded route");
    const auto list=m.r32(receiver+0x1a0u);
    need(list!=0u,"numeric timer predicate requires a nonnull list");
    const auto object=m.r32(list);
    need(object!=0u,"numeric timer predicate requires its selected nonnull list element");
    const auto nested=m.r32(object+0x24u);
    need(nested!=0u,"numeric timer predicate nested tag pointer is null");
    if(m.r32(nested+0xb4u)!=tag) return 0u;
    if(!m.r8(object+0x55u)) return floating_b61::with_al(object,0u);
    const auto start=m.r32(object+0x2cu),duration=m.r32(object+0x34u);
    std::uint32_t remaining=duration;
    if(start!=0xffffffffu){
        const auto elapsed=m.r32(0x00a2896cu)-start;
        if(static_cast<std::int32_t>(elapsed)>=static_cast<std::int32_t>(duration)) remaining=0u;
        else remaining-=elapsed;
    }
    if(start==0xffffffffu) remaining=duration;
    i.arg[0]=remaining;
    const auto divisor=m.r32(nested+0xb0u);
    need(divisor!=0u,"numeric timer x87 ratio denominator is zero");
    const auto clock_object=m.r32(0x00821b88u);
    need(clock_object!=0u,"numeric timer threshold object is null");
    i.fp.load_integer32(remaining);
    i.fp.load_integer32(divisor);
    i.fp.divide_pop(); // ratio = remaining / divisor
    i.fp.load32(m.r32(0x007867f8u));
    i.fp.subtract32(m.r32(clock_object+0xb80u));
    i.fp.compare_pop_twice();
    const auto status=i.fp.status();
    const auto success=(status&0x0100u)==0u;
    const auto ax=floating_b61::with_ax(nested,status);
    return floating_b61::with_al(ax,success?1u:0u);
}

fp::Raw80 read80_stack(const Inputs& i,unsigned first_word) {
    fp::Raw80 x;
    for(unsigned n=0;n<10u;++n)x.bytes[n]=static_cast<std::uint8_t>(i.arg[first_word+n/4u]>>((n%4u)*8u));
    return x;
}
std::uint64_t read64_stack(const Inputs& i,unsigned first_word){
    return std::uint64_t(i.arg[first_word])|(std::uint64_t(i.arg[first_word+1u])<<32u);
}
void sqrt_estimate(Memory& m,const Inputs& i,std::uint64_t value) {
    extra_detail::root(m,i.fp,value);
}
std::uint32_t convert_fp(Memory& m,const Inputs& i) {
    const auto control=i.fp.control(),expected=std::uint16_t(m.r32(0x007c3a04u));
    if(control!=expected)i.fp.load_control(expected);
    return static_cast<std::uint32_t>(i.fp.pop_integer64());
}
std::uint32_t rounded_sqrt(Memory& m,const Inputs& i,std::uint64_t square) {
    sqrt_estimate(m,i,square);return convert_fp(m,i);
}
}

std::uint32_t fun_0041d330(Memory& m,const Inputs& i){return timer_match(m,i,1u);}
std::uint32_t fun_0041d3e0(Memory& m,const Inputs& i){return timer_match(m,i,3u);}

std::uint32_t fun_0042e810(Memory& m,const Inputs& i){
    const auto base=i.cx;
    if(!m.r32(base+0x60u))return 0u;
    for(std::uint32_t candidate=0;candidate<8u;++candidate)for(std::uint32_t subpoint=0;subpoint<3u;++subpoint){
        const auto chosen=candidate*3u+subpoint,point=m.r32(base+chosen*4u);
        if(!point)continue;
        const auto dx=i.arg[0]-m.r32(point),dy=i.arg[1]-m.r32(point+4u),dz=i.arg[2]-m.r32(point+8u);
        // 42e85c..42e88a: retain the original three live coordinates and
        // duplicate/product ordering, including discarded numeric x87 slots.
        i.fp.load_integer32(dy);i.fp.load_integer32(dz);i.fp.load_integer32(dx);
        i.fp.load_st0();fp_ext::multiply_st1(i.fp);
        i.fp.load_st2();fp_ext::multiply_st3(i.fp);i.fp.add_pop();
        fp_ext::load_st3(i.fp);fp_ext::multiply_st4(i.fp);i.fp.add_pop();
        const auto square=i.fp.pop64();i.fp.pop_st0();i.fp.pop_st0();i.fp.pop_st0();
        const auto distance=rounded_sqrt(m,i,square);
        if(global_b26::s32(distance)<128)return m.r32(base+chosen*4u);
    }
    return 0u;
}
std::uint32_t fun_0062d520(Memory& m,const Inputs& i){
    const auto p=i.cx;
    const auto dx=m.r32(p+0x28u)-m.r32(p+0x1cu);
    const auto dy=m.r32(p+0x2cu)-m.r32(p+0x20u);
    const auto dz=m.r32(p+0x30u)-m.r32(p+0x24u);
    m.w32(p+0x4cu,dx);m.w32(p+0x50u,dy);m.w32(p+0x54u,dz);
    const auto x=m.r32(p+0x4cu),y=m.r32(p+0x50u),z=m.r32(p+0x54u);
    const auto square=x*x+y*y+z*z;
    i.fp.load_integer32(square);
    const auto sqbits=i.fp.pop64();
    sqrt_estimate(m,i,sqbits);
    floating_b61::write64(m,p+0x58u,i.fp.store64());
    i.fp.divide64(floating_b61::read64(m,p+0x10u));
    const auto scale=convert_fp(m,i);m.w32(p+0x7cu,scale);
    auto last=scale;
    if(scale!=0u){
        last=static_cast<std::uint32_t>(static_cast<std::int32_t>(dx)/static_cast<std::int32_t>(scale));m.w32(p+0x60u,last);
        last=static_cast<std::uint32_t>(static_cast<std::int32_t>(dy)/static_cast<std::int32_t>(scale));m.w32(p+0x64u,last);
        last=static_cast<std::uint32_t>(static_cast<std::int32_t>(dz)/static_cast<std::int32_t>(scale));m.w32(p+0x68u,last);
    }else {m.w32(p+0x60u,dx);m.w32(p+0x64u,dy);m.w32(p+0x68u,dz);}
    return last;
}

std::uint32_t fun_00760ad0(Memory& m,const Inputs& i){
    const auto a=i.cx,b=i.arg[0],first_limit=i.dx,second_limit=i.arg[1];
    need(m.r32(a+8u)==m.r32(b+8u)&&m.r32(a+0xcu)==m.r32(b+0xcu),
         "rectangle fallback-copy route excluded from finite clipping contract");
    auto ax=m.r32(a),ay=m.r32(a+4u),aw=m.r32(a+8u),ah=m.r32(a+0xcu);
    auto bx=m.r32(b),by=m.r32(b+4u),bw=m.r32(b+8u),bh=m.r32(b+0xcu);
    if(global_b26::s32(ax)<0){bx-=ax;aw+=ax;bw+=ax;ax=0;}
    if(global_b26::s32(ay)<0){by-=ay;ah+=ay;bh+=ay;ay=0;}
    auto overlap=ax-m.r32(first_limit+8u)+aw;
    if(global_b26::s32(overlap)>0){aw-=overlap;bw-=overlap;}
    overlap=ah-m.r32(first_limit+0xcu)+ay;
    if(global_b26::s32(overlap)>0){ah-=overlap;bh-=overlap;}
    if(global_b26::s32(bx)<0){ax-=bx;aw+=bx;bw+=bx;bx=0;}
    if(global_b26::s32(by)<0){ay-=by;ah+=by;bh+=by;by=0;}
    overlap=bw-m.r32(second_limit+8u)+bx;
    if(global_b26::s32(overlap)>0){bw-=overlap;aw-=overlap;}
    overlap=by-m.r32(second_limit+0xcu)+bh;
    if(global_b26::s32(overlap)>0){bh-=overlap;ah-=overlap;}
    m.w32(a,ax);m.w32(a+4u,ay);m.w32(a+8u,aw);m.w32(a+0xcu,ah);
    m.w32(b,bx);m.w32(b+4u,by);m.w32(b+8u,bw);m.w32(b+0xcu,bh);
    return global_b26::s32(aw)>0&&global_b26::s32(ah)>0&&
           global_b26::s32(bw)>0&&global_b26::s32(bh)>0?1u:0u;
}
std::uint32_t fun_005365a0(Memory& m,const Inputs& i){
    const auto scale_out=i.cx,factor_out=i.dx;
    const auto xptr=i.arg[0],yptr=i.arg[1],zptr=i.arg[2];
    auto clamp=[&](std::uint32_t p){auto v=m.r32(p);if(global_b26::s32(v)<=0)v=0;if(global_b26::s32(v)>=2000)v=2000;m.w32(p,v);};
    clamp(xptr);clamp(yptr);clamp(zptr);
    m.w32(scale_out,65536u);
    const auto x=m.r32(xptr);i.arg[0]=x;
    if(!(x==1000u&&m.r32(yptr)==x&&m.r32(zptr)==x)){
        const auto y=m.r32(yptr);i.arg[1]=y;
        const auto z=m.r32(zptr);
        unsigned primary;
        if(global_b26::s32(y)>global_b26::s32(x))primary=global_b26::s32(y)<global_b26::s32(z)?2u:1u;
        else if(global_b26::s32(x)>=global_b26::s32(z))primary=0u;
        else primary=global_b26::s32(y)>=global_b26::s32(x)&&global_b26::s32(y)>=global_b26::s32(z)?1u:2u;
        const auto peak=primary==0?x:primary==1?y:z;
        i.fp.load_integer32(peak);i.fp.multiply64(floating_b61::read64(m,0x7905a0u));i.fp.multiply64(floating_b61::read64(m,0x787528u));
        if(primary==0)i.fp.load_st0();
        const auto scale=convert_fp(m,i);m.w32(scale_out,scale);
        if(global_b26::s32(scale)<66){
            if(primary==0)i.fp.pop_st0();
            m.w32(scale_out,65536u);m.w32(xptr,1000u);m.w32(yptr,1000u);m.w32(zptr,1000u);m.w32(factor_out,0);
        }else{
            const std::uint32_t ptrs[]{xptr,yptr,zptr};m.w32(ptrs[primary],1000u);
            auto normalize=[&](std::uint32_t p){i.fp.load_integer32(m.r32(p));i.fp.multiply64(floating_b61::read64(m,0x7905a0u));
                if(primary==0)floating_b61::fp_extra::reg<0xd8f1>(i.fp);else i.fp.divide_integer32(m.r32(scale_out));
                const auto v=convert_fp(m,i);m.w32(p,v);};
            if(primary==0){normalize(yptr);normalize(zptr);i.fp.pop_st0();}
            else if(primary==1){normalize(xptr);normalize(zptr);}
            else{normalize(xptr);normalize(yptr);}
            // 536756 is the low 32-bit IMUL result, followed by signed SAR16.
            m.w32(factor_out,global_b26::sar(m.r32(scale_out)*m.r32(factor_out),16));
        }
    }
    auto factor=m.r32(factor_out);if(global_b26::s32(factor)>=2000)factor=2000;
    m.w32(factor_out,factor);return factor;
}
std::uint32_t fun_0057a090(Memory& m,const Inputs& i){
    const auto record=i.arg[1],point=i.arg[0];
    const auto r0=m.r32(record),r1=m.r32(record+4u),r2=m.r32(record+8u),r3=m.r32(record+0xcu);
    if(r0==m.r32(0x00a57c98u)&&r1==m.r32(0x00a57c9cu)&&r2==m.r32(0x00a57ca0u)&&r3==m.r32(0x00a57ca4u))
        return floating_b61::with_al(r3,1u);
    const auto x=static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(point)));
    const auto y=static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(point+2u)));
    const auto left=static_cast<std::int32_t>(r0),top=static_cast<std::int32_t>(r1);
    const auto right=left+static_cast<std::int32_t>(r2),bottom=top+static_cast<std::int32_t>(r3);
    if((i.arg[2]&0xffu)==0u)return x>=left&&x<right&&y>=top&&y<bottom?1u:0u;
    const auto origin=m.r32(0x0081a910u);
    const auto q0=std::uint32_t(x)-2u*r0-std::uint32_t(y)+origin-1u;
    const auto q2=std::uint32_t(x)-2u*r1-origin+std::uint32_t(y)-1u;
    i.arg[2]=q0;
    i.fp.load_integer32(static_cast<std::uint32_t>(q0));i.fp.multiply64(floating_b61::read64(m,0x00785728u));
    i.fp.load_integer32(r2);i.fp.multiply64(floating_b61::read64(m,0x00785728u));
    i.arg[2]=q2;i.fp.subtract_pop();
    i.fp.load_integer32(static_cast<std::uint32_t>(q2));i.fp.multiply64(floating_b61::read64(m,0x00785728u));
    i.fp.load_integer32(r3);i.fp.multiply64(floating_b61::read64(m,0x00785728u));i.fp.subtract_pop();
    i.fp.load_st0();fp_ext::multiply_st1(i.fp);i.fp.multiply64(read64_stack(i,5u));
    i.fp.load_st2();fp_ext::multiply_st3(i.fp);i.fp.multiply64(read64_stack(i,3u));i.fp.add_pop();
    i.fp.compare_pop64(floating_b61::read64(m,0x00785708u));
    const auto status=i.fp.status();
    i.fp.pop_st0();i.fp.pop_st0();
    return (status&0x0100u)!=0u?1u:0u;
}

std::uint32_t fun_0077be5c(Memory& m,const Inputs& i){
    const auto destination=i.arg[0],source=i.arg[1];
    const auto bits=floating_b61::read64(m,source);
    const auto exponent=std::uint16_t((bits>>52u)&0x7ffu);
    need(exponent>=1u&&exponent<=2046u,"binary64-to-extended route requires a finite normal operand");
    const auto sign=std::uint16_t((bits>>63u)?0x8000u:0u);
    const auto significand=((bits&0x000fffffffffffffull)|0x0010000000000000ull)<<11u;
    floating_b61::write64(m,destination,significand);
    m.w16(destination+8u,std::uint16_t(exponent+0x3c00u)|sign);
    i.arg[1]=sign;
    return destination;
}

std::uint32_t fun_0077bf20(Memory& m,const Inputs& i){
    // Each ten-byte operand is copied from its original inline caller-stack slot.
    const auto first=read80_stack(i,0u),second=read80_stack(i,3u);
    const auto exponent0=std::uint16_t(first.bytes[8]|(std::uint16_t(first.bytes[9])<<8u))&0x7fffu;
    const auto exponent1=std::uint16_t(second.bytes[8]|(std::uint16_t(second.bytes[9])<<8u))&0x7fffu;
    const auto high=std::uint32_t(first.bytes[4])|(std::uint32_t(first.bytes[5])<<8u)|
                    (std::uint32_t(first.bytes[6])<<16u)|(std::uint32_t(first.bytes[7])<<24u);
    const auto transformed=(high<<1u)^0x0e000000u;
    need(exponent0>=0x3ffeu&&exponent0<=0x4001u&&exponent1>=0x3ffeu&&exponent1<=0x4001u,
         "extended division exponents outside bounded normal route");
    need((high&0x80000000u)!=0u&&((transformed&0x0e000000u)!=0u),
         "extended division operand outside direct FDIVP branch");
    i.fp.load80(second);
    i.fp.load80(first);
    i.fp.divide_pop();
    return transformed;
}
}
