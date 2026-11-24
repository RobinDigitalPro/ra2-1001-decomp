#include "recovered/numeric_b71.hpp"

#include "recovered/global_b58_c.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/global_b28_memory.hpp"
#include "recovered/leaf_memory.hpp"
#include "recovered/ini_integer.hpp"
#include "platform/x87_extended_b40.hpp"
#include "platform/x87_b61.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::global_b26 { std::uint32_t fun_00545490(Memory&,const Inputs&); }

namespace ra2::recovered::numeric_b71 {
namespace {
namespace fp = ra2::platform::x87;
namespace fp_extra = ra2::platform::x87_b61;

struct MutableFrame {
    const Inputs& original;
    Inputs value;
    explicit MutableFrame(const Inputs& input) : original(input), value(input) {}
    ~MutableFrame() { original.arg = value.arg; original.fp = value.fp; }
};

constexpr std::uint32_t synthetic_local_base = 0x30000000u;
struct LocalScratch {
    std::array<std::uint8_t, 0x1000> bytes{};
    ra2::recovered::leaf::Memory span{bytes.data(), synthetic_local_base,
                                      static_cast<std::uint32_t>(bytes.size())};
    Memory view;
    explicit LocalScratch(Memory& original) : view(original) { view.add(span); }
};

inline std::uint32_t byte_result(const Inputs& i, std::uint32_t value) {
    return (i.ax & 0xffffff00u) | (value & 0xffu);
}
inline std::uint64_t dword_pair(Memory& m,std::uint32_t p) {
    return std::uint64_t(m.r32(p)) | (std::uint64_t(m.r32(p+4u))<<32);
}
inline void raw_register(fp::State& state, unsigned first, unsigned second) {
    state.require_masked(); fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte %c[first],%c[second]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [first]"i"(first),[second]"i"(second)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
inline void fidivr32(fp::State& state,std::uint32_t value) {
    state.require_masked(); fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfidivrl %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [operand]"m"(value)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
inline void fdivr64(fp::State& state,std::uint64_t value) {
    state.require_masked(); fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfdivrl %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [operand]"m"(value)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
inline void fimul32(fp::State& state,std::uint32_t value) {
    state.require_masked(); fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [operand]"m"(value)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
inline void fcom64(fp::State& state,std::uint64_t value) {
    state.require_masked(); fp::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfcoml %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [operand]"m"(value)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
inline void sqrt_helper(Memory& m,Inputs& i,std::uint64_t value) {
    i.fp.load64(value);
    i.fp.compare32(m.r32(0x00785738u));
    i.ax=floating_b61::with_ax(i.ax,i.fp.status());
    // The first JZ is taken only when C3 is clear. Equality takes the
    // short floor path: pop the input, load the floor, and return directly.
    if ((i.ax & 0x4000u)!=0u) { i.fp.pop_st0(); i.fp.load32(m.r32(0x00785738u)); return; }
    i.fp.compare32(m.r32(0x00785738u));
    i.ax=floating_b61::with_ax(i.ax,i.fp.status());
    if (((i.ax>>8u)&0x41u)!=0u) i.fp.multiply64(dword_pair(m,0x00788578u));
    const auto float_bits=i.fp.pop32();
    i.cx=float_bits;
    i.ax=i.cx;
    i.cx &= 0x007fffffu;
    i.ax >>= 23u;
    i.ax -= 0x7fu;
    if (i.ax&1u) i.cx|=0x00800000u;
    i.ax=static_cast<std::uint32_t>(static_cast<std::int16_t>(static_cast<std::uint16_t>(i.ax))>>1);
    i.cx >>= 10u;
    i.ax += 0x7fu;
    i.cx=m.r32(0x0080013cu+i.cx*4u);
    i.ax <<=23u;
    i.cx += i.ax;
    i.fp.load32(i.cx);
}
inline std::uint32_t convert_helper(Memory& m,Inputs& i) {
    const auto current=i.fp.control();
    if (current != static_cast<std::uint16_t>(m.r32(0x007c3a04u)))
        i.fp.load_control(static_cast<std::uint16_t>(m.r32(0x007c3a04u)));
    const auto result=i.fp.pop_integer64();
    i.dx=static_cast<std::uint32_t>(std::uint64_t(result)>>32u);
    i.ax=static_cast<std::uint32_t>(result);
    return i.ax;
}
inline std::uint32_t rounded_sqrt(Memory& m,Inputs& i,std::uint64_t square) {
    sqrt_helper(m,i,square);
    return convert_helper(m,i);
}
inline std::int32_t signed_word(Memory& m,std::uint32_t p) { return static_cast<std::int16_t>(m.r16(p)); }
inline std::int32_t signed_dword(std::uint32_t x) { return static_cast<std::int32_t>(x); }
inline std::uint32_t helper_157450(Memory& m,const Inputs& i,std::uint32_t p,std::uint32_t flag) {
    Inputs call=i;call.arg[0]=p;call.arg[1]=flag;
    return ra2::recovered::global_b26::fun_00557450(m,call);
}
inline std::uint32_t helper_4b8850(Memory& m,const Inputs& i,std::uint32_t desc,std::uint32_t out) {
    Inputs call=i;call.cx=desc;call.arg[0]=out;
    return fun_004b8850(m,call);
}
inline std::uint32_t helper_5676f0(Memory& m,const Inputs& i,std::uint32_t left,std::uint32_t right) {
    Inputs call=i;call.cx=left;call.dx=right;
    return ra2::recovered::global_b26::fun_005676f0(m,call);
}
inline std::uint32_t helper_455490(Memory& m,std::uint32_t vector) {
    Inputs call{};call.arg[0]=vector;
    return ra2::recovered::global_b26::fun_00545490(m,call);
}
}

// RVA 0x0b8850: bounded signed-word interpolation. The original two IDIVs
// are reached only after positive count and positive low-word quotient guards.
std::uint32_t fun_004b8850(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto object=i.cx;const auto count=static_cast<std::int16_t>(m.r16(object+0x14u));
    auto result=m.r32(object);
    if(count<=0) {m.w32(i.arg[0],result);return i.arg[0];}
    const auto start=m.r32(object+8u),duration=m.r32(object+0x10u),now=m.r32(0x00a2896cu);
    std::uint32_t remaining=duration;
    if(start!=0xffffffffu){const auto elapsed=now-start;if(static_cast<std::int32_t>(elapsed)>=static_cast<std::int32_t>(duration)){m.w32(i.arg[0],result);return i.arg[0];}remaining-=elapsed;}
    if(remaining==0u){m.w32(i.arg[0],result);return i.arg[0];}
    const auto delta=static_cast<std::int16_t>(m.r16(object)-m.r16(object+4u));
    const auto magnitude=delta<0?std::uint32_t(0u-static_cast<std::uint32_t>(delta)):static_cast<std::uint32_t>(delta);
    const auto quotient=static_cast<std::int16_t>(magnitude/static_cast<std::uint32_t>(count));
    if(quotient>0){std::uint32_t phase=duration;
        if(start!=0xffffffffu){const auto elapsed=now-start;if(static_cast<std::int32_t>(elapsed)>=static_cast<std::int32_t>(duration))phase=0u;else phase-=elapsed;}
        const auto step=static_cast<std::int32_t>(delta)/static_cast<std::int16_t>(quotient);
        result=(result&0xffff0000u)|std::uint16_t(std::uint16_t(result)-std::uint16_t(std::uint32_t(step)*phase));}
    m.w32(i.arg[0],result);return i.arg[0];
}

// RVA 0x157380: test four signed-short corners through accepted grid helper.
std::uint32_t fun_00557380(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto rect=i.arg[0],flag=i.arg[1];
    LocalScratch local(m);
    auto test=[&](std::uint16_t x,std::uint16_t y){
        const auto p=synthetic_local_base; local.view.w16(p,x);local.view.w16(p+2u,y);
        return helper_157450(local.view,i,p,flag)&0xffu;
    };
    const auto x=static_cast<std::uint16_t>(m.r16(rect)),y=static_cast<std::uint16_t>(m.r16(rect+4u));
    i.arg[0]=std::uint32_t(x)|(std::uint32_t(y)<<16u);
    if(!test(x,y))return 0u;
    const auto right=static_cast<std::uint16_t>(m.r32(rect+8u)+m.r32(rect)-1u);
    i.arg[1]=std::uint32_t(right)|(std::uint32_t(y)<<16u);
    if(!test(right,y))return 0u;
    const auto bottom=static_cast<std::uint16_t>(m.r32(rect+4u)+m.r32(rect+0xcu)-1u);
    if(!test(x,bottom))return 0u;
    if(!test(right,bottom))return 0u;
    return 1u;
}

// RVA 0x157630: grid fallback, level adjustment, then four signed bounds.
std::uint32_t fun_00557630(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    auto al=i.arg[2]&0xffu;auto rect=i.arg[1],owner=i.arg[0];
    const auto y=signed_word(m,rect+2u),x=signed_word(m,rect);
    std::uint32_t esi=0u;
    if(al){const auto idx=(std::uint32_t(y)<<9u)+std::uint32_t(x);
        if(static_cast<std::int32_t>(idx)>=0&&idx<0x40000u){const auto table=m.r32(0x0081a958u);auto item=m.r32(table+idx*4u);if(!item){m.w32(0x00a57634u,m.r32(rect));item=0x00a57610u;}esi=static_cast<std::uint32_t>(static_cast<std::int8_t>(m.r8(item+0x11bu)));if(m.r8(item+0x11cu)){const auto limit=m.r32(i.cx+0xf0u)+m.r32(owner+4u)*2u+4u+std::uint32_t(esi);if(y+x<static_cast<std::int32_t>(limit))++esi;}}
        else{m.w32(0x00a57634u,m.r32(rect));const auto item=0x00a57610u;esi=static_cast<std::uint32_t>(static_cast<std::int8_t>(m.r8(item+0x11bu)));if(m.r8(item+0x11cu)){const auto limit=m.r32(i.cx+0xf0u)+m.r32(owner+4u)*2u+4u+std::uint32_t(esi);if(y+x<static_cast<std::int32_t>(limit))++esi;}}
    }
    const auto sum=signed_dword(std::uint32_t(y)+std::uint32_t(x));
    const auto global=m.r32(i.cx+0xf0u),aux_y=m.r32(owner+4u);
    const auto low=signed_dword(global+aux_y*2u+esi);
    if(sum<=low)return byte_result(i,0);
    const auto height=m.r32(owner+0xcu);
    const auto upper=signed_dword(global+(aux_y+height)*2u+2u+esi);
    if(sum>upper)return byte_result(i,0);
    const auto base_x=m.r32(owner);
    const auto edge_x=signed_dword((base_x+m.r32(owner+8u))*2u-global);
    const auto delta_x=signed_dword(std::uint32_t(x)-std::uint32_t(y));
    if(delta_x>=edge_x)return byte_result(i,0);
    const auto edge_y=signed_dword(global-base_x*2u);
    const auto delta_y=signed_dword(std::uint32_t(y)-std::uint32_t(x));
    if(delta_y>=edge_y)return byte_result(i,0);
    return byte_result(i,1);
}

// RVA 0x29fce0: signed inclusive extent and relative-coordinate membership.
std::uint32_t fun_0069fce0(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto object=i.cx;auto x0=signed_dword(m.r32(object+0xd98u)),x1=signed_dword(m.r32(object+0xd90u));
    auto y0=signed_dword(m.r32(object+0xd9cu)),y1=signed_dword(m.r32(object+0xd94u));
    if(x1>x0)std::swap(x0,x1);if(y1>y0)std::swap(y0,y1);
    const auto width=std::uint32_t(x0)-std::uint32_t(x1)+1u,height=std::uint32_t(y0)-std::uint32_t(y1)+1u;
    if(static_cast<std::int32_t>(width)<=0||static_cast<std::int32_t>(height)<=0)return 0;
    const auto count=signed_dword(m.r32(object+0xdb0u));if(count<=0)return 0;if(count>512)throw std::out_of_range("B71 29fce0 fixture count exceeds mapped record window");
    for(std::int32_t n=0;n<count;++n){const auto p=0x00aa6100u+std::uint32_t(n)*12u;const auto target=m.r32(p);if(!target||m.r8(target+0x7du)==0u)continue;
        const auto rx=signed_dword(m.r32(p+4u))-signed_dword(m.r32(object+0xb0u));const auto ry=signed_dword(m.r32(p+8u))-signed_dword(m.r32(object+0xb4u));
        const auto xend=signed_dword(std::uint32_t(x1)+width),yend=signed_dword(std::uint32_t(y1)+height);
        if(rx>=x1&&rx<xend&&ry>=y1&&ry<yend)return 1u;
    }return 0u;
}

// RVA 0x2b57d0: aggregate object flags and best accepted fixed-table score.
std::uint32_t fun_006b57d0(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto object=i.cx,owner=m.r32(i.cx+0xdcu);m.w8(object+0xe8u,1u);m.w8(object+0xe9u,0u);m.w32(object+0xe4u,9u);
    const auto count=m.r32(owner+0x9cu);if(count>512u)throw std::out_of_range("B71 2b57d0 fixture list exceeds mapped window");for(std::uint32_t k=0;k<count;++k){const auto child=m.r32(owner+0xa8u+k*8u);if(m.r8(child+0xadau)){if(m.r32(child+0x52cu)==0)m.w8(object+0xe8u,0u);else m.w8(object+0xe9u,1u);}
        const auto score=helper_5676f0(m,i,m.r32(child+0x500u),m.r32(object+0xe4u));m.w32(object+0xe4u,score);}
    if(m.r8(object+0xeeu))m.w8(object+0xe8u,0u);return owner;
}

// RVA 0x1fe290 uses the literal entryESP-8 value exposed by Inputs.
std::uint32_t fun_005fe290(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto object=i.cx;const auto desc=m.r32(object+0x28u)+0x2e0u;
    LocalScratch local(m);const auto output=synthetic_local_base+0x800u;
    Inputs call=i;call.cx=desc;call.arg[0]=output;fun_004b8850(local.view,call);const auto sample=local.view.r32(output);
    const auto bucket=(((sample>>12u)+1u)>>1u)&7u;const auto state=signed_dword(m.r32(object+0x48u));
    std::uint32_t offset=0xa0u,limit=4u;
    if(state>=0&&state<=1){offset=0;limit=3u;}else if(state==2){offset=0x50u;}
    auto inner=m.r32(object+0x50u)+1u;m.w32(object+0x50u,inner);if(static_cast<std::int32_t>(inner)<static_cast<std::int32_t>(limit))return byte_result(i,0);
    const auto outer=m.r32(object+0x4cu)+1u;m.w32(object+0x50u,0u);m.w32(object+0x4cu,outer);if(outer>=10u)return byte_result(i,1);
    const auto record=m.r32(object+0x44u);if(!record)return byte_result(i,0);
    const auto timer=m.r32(0x00a2896cu);m.w32(record+0x9cu,timer);m.w32(record+0xa0u,i.stack_minus8);m.w32(record+0xa4u,0x80u);m.w32(record+0xa8u,0x80u);
    m.w32(record+0x98u,outer+bucket*10u+offset);return byte_result(i,0);
}

// Remaining entries are defined below in x87/register-order translation.
// Frozen accepted 0x76aa50 conversion semantics, translated over explicit state.
std::uint32_t fun_00475fd0(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto object=i.cx;const auto first=m.r32(object)&0xffu,second=m.r32(object+4u)&0xffu;
    const auto x=std::int32_t(first)-128,y=std::int32_t(second)-128;
    i.fp.load_integer32(static_cast<std::uint32_t>(y));i.fp.load_integer32(static_cast<std::uint32_t>(x));
    i.fp.load_st0();fp_extra::reg<0xd8c9>(i.fp);i.fp.load_st2();fp_extra::reg<0xd8cb>(i.fp);i.fp.add_pop();
    const auto sq=i.fp.pop64();i.fp.pop_st0();i.fp.pop_st0();
    const auto distance=rounded_sqrt(m,i,sq);
    if(static_cast<std::int32_t>(distance)<60)return 0;
    std::uint32_t value=0;if(first>128u)value=1u;if(second>128u)value|=2u;
    return value?value+1u:0u;
}

// RVA 0x0f4a70: exact ordered x87 byte-channel normalization and conversion.
std::uint32_t fun_004f4a70(Memory& m,const Inputs& input) {
    MutableFrame f(input);auto& i=f.value;const auto object=i.cx;
    const std::array<std::uint32_t,3> v{m.r8(object+0x55e9u),m.r8(object+0x55eau),m.r8(object+0x55ebu)};
    const auto scale=dword_pair(m,0x0078df58u),limit=dword_pair(m,0x0078df50u),lower=dword_pair(m,0x0078df48u),zero=dword_pair(m,0x00786610u);
    i.fp.load_integer32(v[0]);auto red=i.fp.store64();
    i.fp.load_integer32(v[1]);auto green=i.fp.store64();
    i.fp.load_integer32(v[2]);auto blue=i.fp.store64();
    // FLD ST0; FMUL ST1; FLD ST2; FMUL ST3; FADDP; FLD ST3;
    // FMUL ST4; FADDP; then the caller's FSTP local and three FSTP ST0s.
    raw_register(i.fp,0xd9,0xc0);raw_register(i.fp,0xd8,0xc9);raw_register(i.fp,0xd9,0xc2);raw_register(i.fp,0xd8,0xcb);raw_register(i.fp,0xde,0xc1);
    raw_register(i.fp,0xd9,0xc3);raw_register(i.fp,0xd8,0xcc);raw_register(i.fp,0xde,0xc1);
    const auto squares=i.fp.pop64();i.fp.pop_st0();i.fp.pop_st0();i.fp.pop_st0();
    sqrt_helper(m,i,squares);fcom64(i.fp,zero);i.ax=floating_b61::with_ax(i.ax,i.fp.status());
    const bool zero_length=(i.ax&0x4000u)!=0u;
    if(zero_length){i.fp.pop_st0();i.fp.load64(limit);red=green=blue=limit;}
    else{
        for(auto* channel:{&red,&green}){
            i.fp.load64(*channel);i.fp.multiply64(scale);raw_register(i.fp,0xd8,0xf1);*channel=i.fp.store64();
            i.fp.compare_pop64(limit);i.ax=floating_b61::with_ax(i.ax,i.fp.status());if((i.ax&0x4100u)==0u)*channel=0x406fe00000000000ull;
        }
        i.fp.load64(blue);i.fp.multiply64(scale);raw_register(i.fp,0xde,0xf1);fcom64(i.fp,limit);i.ax=floating_b61::with_ax(i.ax,i.fp.status());blue=i.fp.store64();
        if((i.ax&0x4100u)==0u){i.fp.pop_st0();i.fp.load64(limit);blue=i.fp.store64();}
        for(auto* channel:{&red,&green}){i.fp.load64(*channel);i.fp.compare_pop64(lower);i.ax=floating_b61::with_ax(i.ax,i.fp.status());if((i.ax&0x0100u)!=0u)*channel=zero;}
        fcom64(i.fp,lower);i.ax=floating_b61::with_ax(i.ax,i.fp.status());if((i.ax&0x0100u)!=0u){i.fp.pop_st0();i.fp.load64(zero);blue=i.fp.store64();}
    }
    // The blue candidate remains in ST0. The original squares blue, green,
    // then red, and pops both the sum and blue.
    raw_register(i.fp,0xd9,0xc0);raw_register(i.fp,0xd8,0xc9);
    i.fp.load64(green);i.fp.multiply64(green);i.fp.add_pop();
    i.fp.load64(red);i.fp.multiply64(red);i.fp.add_pop();
    const auto norm_square=i.fp.pop64();i.fp.pop_st0();sqrt_helper(m,i,norm_square);
    fcom64(i.fp,zero);i.ax=floating_b61::with_ax(i.ax,i.fp.status());
    if((i.ax&0x4000u)!=0u){i.fp.pop_st0();i.fp.load64(limit);red=green=blue=limit;}
    else {
        for(auto* channel:{&red,&green}){
            i.fp.load64(*channel);i.fp.multiply64(scale);raw_register(i.fp,0xd8,0xf1);*channel=i.fp.store64();
            i.fp.compare_pop64(limit);i.ax=floating_b61::with_ax(i.ax,i.fp.status());if((i.ax&0x4100u)==0u)*channel=0x406fe00000000000ull;
        }
        i.fp.load64(blue);i.fp.multiply64(scale);raw_register(i.fp,0xde,0xf1);fcom64(i.fp,limit);i.ax=floating_b61::with_ax(i.ax,i.fp.status());
        if((i.ax&0x4100u)==0u){i.fp.pop_st0();i.fp.load64(limit);}
    }
    i.fp.load64(red);auto r=convert_helper(m,i);m.w8(object+0x55ecu,r&0xffu);
    i.fp.load64(green);auto g=convert_helper(m,i);m.w8(object+0x55edu,g&0xffu);
    auto b=convert_helper(m,i);m.w8(object+0x55eeu,b&0xffu);return b;
}

std::uint32_t fun_004ceac0(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto object=i.cx;const auto start=m.r32(object+0xcu),duration=m.r32(object+0x14u),now=m.r32(0x00a2896cu);
    auto remaining=duration;if(start!=0xffffffffu){const auto elapsed=now-start;if(static_cast<std::int32_t>(now-start)>=static_cast<std::int32_t>(duration))remaining=0;else remaining-=elapsed;}
    if(remaining!=0u)return 0u;
    const auto point=i.arg[0];const auto x=signed_dword(m.r32(point))-signed_dword(m.r32(object+0x18u));
    const auto y=signed_dword(m.r32(point+4u))-signed_dword(m.r32(object+0x1cu));
    const auto z=signed_dword(m.r32(point+8u))-signed_dword(m.r32(object+0x20u));
    i.fp.load_integer32(static_cast<std::uint32_t>(z));i.fp.load_integer32(static_cast<std::uint32_t>(y));i.fp.load_integer32(static_cast<std::uint32_t>(x));
    i.fp.load_st0();fp_extra::reg<0xd8c9>(i.fp);i.fp.load_st2();fp_extra::reg<0xd8cb>(i.fp);i.fp.add_pop();
    fp_extra::reg<0xd9c3>(i.fp);fp_extra::reg<0xd8cc>(i.fp);i.fp.add_pop();const auto sq=i.fp.pop64();i.fp.pop_st0();i.fp.pop_st0();i.fp.pop_st0();
    auto dist=rounded_sqrt(m,i,sq);dist=ra2::recovered::global_b26::sar(dist-std::uint32_t(static_cast<std::int32_t>(dist)<0),1u);
    if(static_cast<std::int32_t>(dist)<0x20)return 1u;
    if(dist>=0x100u||static_cast<std::int32_t>(dist)<=signed_dword(m.r32(object+0x24u)))return 0u;
    m.w32(object+0x24u,dist);return 2u;
}

// Exact two-bound x87 clamp used by both byte color adapters.
namespace {
void clamp_byte_float(Memory& m,Inputs& i) {
    const auto hi=m.r32(0x007860a8u),lo=m.r32(0x00785738u);
    i.fp.load32(hi);i.fp.compare_pop_st1();auto status=i.fp.status();i.ax=floating_b61::with_ax(i.ax,status);
    if(((status>>8u)&1u)==0u){
        i.fp.load32(lo);i.fp.compare_pop_st1();status=i.fp.status();i.ax=floating_b61::with_ax(i.ax,status);
        if(((status>>8u)&0x41u)==0u){i.fp.pop_st0();i.fp.load32(lo);return;}
    }
    i.fp.load32(hi);i.fp.compare_pop_st1();status=i.fp.status();i.ax=floating_b61::with_ax(i.ax,status);
    if(((status>>8u)&1u)!=0u){i.fp.pop_st0();i.fp.load32(hi);}
}
}
std::uint32_t fun_00634070(Memory& m, const Inputs& input) {
    MutableFrame frame(input);
    auto& i = frame.value;
    const auto dst = i.cx;
    const auto src_a = i.arg[0];
    const auto src_b = i.arg[1];
    i.fp.load32(m.r32(0x007867f8u));
    i.fp.subtract32(i.arg[2]);
    // Channel 0: B*weight + A*(one-weight), in the original FILD/FILD/FMUL ST2 order.
    i.fp.load_integer32(m.r8(src_b));
    i.fp.multiply32(i.arg[2]);
    i.fp.load_integer32(m.r8(src_a));
    raw_register(i.fp, 0xd8, 0xca);
    i.fp.add_pop();
    clamp_byte_float(m, i);
    m.w8(dst, convert_helper(m, i) & 0xffu);

    // Channel 1: A*(one-weight) + B*weight, preserving the original FMUL ST1,
    // then memory FMUL and FADDP sequence.
    i.fp.load_integer32(m.r8(src_a + 1u));
    raw_register(i.fp, 0xd8, 0xc9);
    i.fp.load_integer32(m.r8(src_b + 1u));
    i.fp.multiply32(i.arg[2]);
    i.fp.add_pop();
    clamp_byte_float(m, i);
    m.w8(dst + 1u, convert_helper(m, i) & 0xffu);

    // Channel 2: integer multiply of the surviving stack value by A, then B*weight.
    fimul32(i.fp, m.r8(src_a + 2u));
    i.fp.load_integer32(m.r8(src_b + 2u));
    i.fp.multiply32(i.arg[2]);
    i.fp.add_pop();
    clamp_byte_float(m, i);
    m.w8(dst + 2u, convert_helper(m, i) & 0xffu);

    i.arg[1] = m.r8(src_b + 2u);
    return dst;
}
std::uint32_t fun_006341e0(Memory& m, const Inputs& input) {
    MutableFrame frame(input);
    auto& i = frame.value;
    const auto dst = i.cx;
    const auto src = i.arg[0];
    const auto scale = i.arg[1];
    for (unsigned k = 0; k != 3; ++k) {
        const auto value = m.r8(src + k);
        i.fp.load_integer32(value);
        i.fp.multiply32(scale);
        clamp_byte_float(m, i);
        m.w8(dst + k, convert_helper(m, i) & 0xffu);
        i.arg[0] = value;
    }
    return dst;
}

std::uint32_t fun_006141d0(Memory& m,const Inputs& input) {
    MutableFrame f(input);auto& i=f.value;
    const auto count=m.r32(0x00aa4878u)+3u;
    const auto adjusted=static_cast<std::uint32_t>((std::int64_t(static_cast<std::int32_t>(count))*0x55555556ll)>>32);
    const auto n=std::uint32_t(std::int32_t(adjusted)+(count>>31));
    const auto owner=m.r32(0x00a1e0e4u),list=m.r32(owner+0x6cu),count_objects=m.r32(owner+0x78u);
    std::uint32_t sum=0;
    for(std::uint32_t k=0;k<count_objects;++k){const auto entity=m.r32(list+k*4u),target=m.r32(entity+0x418u);sum+=m.r32(target+0xc6cu);sum+=m.r32(target+0xc68u);}
    const auto divisor=dword_pair(m,0x00790de8u);i.fp.load_integer32(sum);i.fp.add64(divisor);fdivr64(i.fp,divisor);
    fimul32(i.fp,n);
    const auto scaled=convert_helper(m,i);
    const auto value=static_cast<std::int32_t>(scaled);
    const auto cap=std::int32_t(n-1u);
    const auto lower=value<=0?0u:static_cast<std::uint32_t>(value);
    const auto clamped=std::min(lower,static_cast<std::uint32_t>(cap));
    return n-clamped;
}

std::uint32_t fun_00628af0(Memory& m, const Inputs& input) {
    MutableFrame frame(input);
    auto& i = frame.value;
    const auto context = i.cx;
    const auto out = i.arg[0];
    const auto point = i.arg[1];
    const auto x = static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(point)));
    const auto y = static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(point + 2u)));

    const auto xsum = m.r32(context + 0x148cu) - static_cast<std::uint32_t>(y) + static_cast<std::uint32_t>(x);
    i.fp.load_integer32(xsum);
    i.fp.multiply32(m.r32(context + 0x1484u));
    ra2::platform::x87_extended::add_integer32(i.fp,m.r32(context + 0x1498u));
    const auto xout = convert_helper(m, i);

    const auto ysum = static_cast<std::uint32_t>(y) - m.r32(context + 0x1494u) + static_cast<std::uint32_t>(x);
    i.fp.load_integer32(ysum);
    i.fp.multiply32(m.r32(context + 0x1484u));
    ra2::platform::x87_extended::add_integer32(i.fp,m.r32(context + 0x149cu));
    const auto yout = convert_helper(m, i);

    const auto comparison = m.r32(context + 0x1498u) - 1u;
    const auto adjusted_x = xout + (xout == comparison ? 1u : 0u);
    m.w32(out, adjusted_x);
    m.w32(out + 4u, yout);
    m.w32(out + 8u, 1u);
    m.w32(out + 12u, 1u);
    i.arg[1] = m.r32(context + 0x1498u);
    return out;
}
std::uint32_t fun_00629220(Memory& m, const Inputs& input) {
    MutableFrame frame(input);
    auto& i = frame.value;
    const auto object = i.cx;
    const auto out = i.arg[0];
    const auto point = i.arg[1];
    const auto px = m.r32(point);
    const auto py = m.r32(point + 4u);

    const auto xnumerator = (m.r32(object + 0x148cu) << 8u) - py + px;
    i.fp.load_integer32(xnumerator);
    i.fp.multiply32(m.r32(object + 0x1484u));
    i.fp.multiply32(m.r32(0x007937bcu));
    auto xout = convert_helper(m, i);

    const auto ynumerator = py - (m.r32(object + 0x1494u) << 8u) + px;
    i.fp.load_integer32(ynumerator);
    i.fp.multiply32(m.r32(object + 0x1484u));
    i.fp.multiply32(m.r32(0x007937bcu));
    auto yout = convert_helper(m, i);

    if ((i.arg[2] & 0xffu) != 0u) {
        if (static_cast<std::int32_t>(xout) < 0) xout = 0u;
        else if (static_cast<std::int32_t>(xout) >= static_cast<std::int32_t>(m.r32(object + 0x14a0u)))
            xout = m.r32(object + 0x14a0u) - 1u;
        if (static_cast<std::int32_t>(yout) < 0) yout = 0u;
        else if (static_cast<std::int32_t>(yout) >= static_cast<std::int32_t>(m.r32(object + 0x14a4u)))
            yout = m.r32(object + 0x14a4u) - 1u;
    }
    m.w32(out, xout);
    m.w32(out + 4u, yout);
    i.arg[1] = ynumerator;
    return out;
}

// RVA 0x50050 uses the exact integer-ratio helper at 0x4e7870. Its x87
// result is consumed by FCOMP and FNSTSW in the original caller.
namespace {
void helper_0e7870(Memory& m,const Inputs& i,std::uint32_t object) {
    const auto a=m.r32(object+0x52d0u),b=m.r32(object+0x52d4u);
    if(static_cast<std::int32_t>(a)>=static_cast<std::int32_t>(b) || b==0u) { i.fp.load64(dword_pair(m,0x00785708u)); return; }
    if(a==0u) { i.fp.load64(dword_pair(m,0x00786610u)); return; }
    i.fp.load_integer32(a);i.fp.divide_integer32(b);
}
}
std::uint32_t fun_00450050(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto object=i.cx;
    if(m.r8(object+0x530u)==0u && static_cast<std::int32_t>(m.r32(object+0x54cu))<2)
        return byte_result(i,0);
    if(static_cast<std::int32_t>(m.r32(object+0x3fcu))>0 || m.r32(object+0x6cu)==0u)
        return byte_result(i,0);
    const auto target=m.r32(object+0x418u);
    if(m.r8(target+0x1217u)!=0u && static_cast<std::int32_t>(m.r32(target+0xc6cu))>0 && m.r8(target+0x11feu)!=0u) {
        helper_0e7870(m,i,m.r32(object+0x1b4u));
        i.fp.compare_pop64(dword_pair(m,0x00785708u));
        i.ax=floating_b61::with_ax(i.ax,i.fp.status());
        if((i.ax&0x0100u)!=0u && static_cast<std::int32_t>(m.r32(object+0x54cu))<2)
            return byte_result(i,0);
    }
    if(m.r8(target+0x1206u)!=0u && m.r8(object+0x59cu)==0u) return byte_result(i,0);
    return byte_result(i,1);
}

// RVA 0x2334b0 searches a finite typed global list by squared short-coordinate
// distance. The threshold table remains at its original immutable address.
std::uint32_t fun_006334b0(Memory& m, const Inputs& input) {
    MutableFrame frame(input);
    auto& i = frame.value;
    const auto type = i.cx;
    i.ax = type; // Original MOV EAX,ECX precedes all branches.
    if (type != 0u &&
        (static_cast<std::int32_t>(type) <= 3 || static_cast<std::int32_t>(type) > 5))
        return byte_result(i, 0);

    const auto count = static_cast<std::int32_t>(m.r32(0x00a9e318u));
    if (count <= 0) return byte_result(i, 0);
    if (count > 512) throw std::out_of_range("B71 2334b0 fixture list exceeds mapped window");
    const auto list = m.r32(0x00a9e30cu);
    const auto packed_point = i.arg[0]; // The sole stack argument; EBP+8 is x/y.
    const auto query_x = static_cast<std::int16_t>(packed_point);
    const auto query_y = static_cast<std::int16_t>(packed_point >> 16u);

    for (std::int32_t k = 0; k < count; ++k) {
        const auto node = m.r32(list + static_cast<std::uint32_t>(k) * 4u);
        const auto node_type = m.r32(node);
        if (node_type != type) continue;

        // Original SUBs are 16-bit before MOVSX; preserve their wraparound.
        const auto dx = static_cast<std::int16_t>(
            static_cast<std::uint16_t>(query_x) - static_cast<std::uint16_t>(m.r16(node + 0x20u)));
        const auto dy = static_cast<std::int16_t>(
            static_cast<std::uint16_t>(query_y) - static_cast<std::uint16_t>(m.r16(node + 0x22u)));

        // FILD dy; FILD dx; FLD ST0; FMUL ST1; FLD ST2; FMUL ST3;
        // FADDP; FSTP double [ESP]; FSTP ST0; FSTP ST0.
        i.fp.load_integer32(static_cast<std::uint32_t>(dy));
        i.fp.load_integer32(static_cast<std::uint32_t>(dx));
        raw_register(i.fp, 0xd9, 0xc0);
        raw_register(i.fp, 0xd8, 0xc9);
        raw_register(i.fp, 0xd9, 0xc2);
        raw_register(i.fp, 0xd8, 0xcb);
        i.fp.add_pop();
        const auto square_as_binary64 = i.fp.pop64();
        i.fp.pop_st0();
        i.fp.pop_st0();

        // The helper receives the FSTP'd binary64 value, not integer bits.
        const auto converted = rounded_sqrt(m, i, square_as_binary64);
        const auto distance = static_cast<std::int16_t>(converted); // MOVSX EAX,AX.
        i.ax = static_cast<std::uint32_t>(static_cast<std::int32_t>(distance));

        // [0x821b88] -> object -> +0x398 table -> node type * 4.
        const auto threshold_root = m.r32(0x00821b88u);
        const auto thresholds = m.r32(threshold_root + 0x398u);
        const auto threshold = static_cast<std::int32_t>(
            m.r32(thresholds + node_type * 4u));
        if (static_cast<std::int32_t>(distance) < threshold)
            return byte_result(i, 1); // MOV AL,1, preserving distance's upper 24 bits.

        i.ax = type; // Original reloads its saved initial EAX before continuing.
    }
    i.ax = type;
    return byte_result(i, 0); // XOR AL,AL.
}

std::uint32_t fun_0069f940(Memory& m,const Inputs& input) {
    MutableFrame frame(input); auto& i=frame.value;
    const auto object=i.cx;
    const auto argx=i.arg[0],argy=i.arg[1],argw=i.arg[2],argh=i.arg[3];
    const auto ox=m.r32(object+0xb0u),oy=m.r32(object+0xb4u);
    const auto minx=ox+argx,miny=oy+argy,maxx=minx+argw,maxy=miny+argh;
    const auto count=signed_dword(m.r32(0x00a28748u));if(count<=0)return 0;
    if(count>512)throw std::out_of_range("B71 29f940 fixture source list exceeds mapped window");
    const auto list=m.r32(0x00a2873cu);
    std::uint32_t index=0;
    for(;index<static_cast<std::uint32_t>(count);++index) {
        const auto entity=m.r32(list+index*4u);
        if(m.r8(entity+0x7du)==0u || m.r8(entity+0x74u)==0u) continue;
        const auto side=m.r32(entity+0x418u);if(m.r8(side+0x1385u)!=0u)continue;
        const auto p=entity+0x88u;const auto x=m.r32(p),y=m.r32(p+4u),z=m.r32(p+8u);
        // The original's LEA/CDQ/SUB/SAR sequences implement truncating
        // integer divisions at each signed-coordinate stage.
        auto sx=signed_dword(30u*x-30u*y);
        auto sy=signed_dword(15u*x+15u*y);
        sx=static_cast<std::int32_t>(static_cast<std::int64_t>(sx)/256);
        sy=static_cast<std::int32_t>(static_cast<std::int64_t>(sy)/256);
        const auto correction=(static_cast<std::int32_t>(z)>=0x2d8)?1u:0u;
        i.arg[0]=correction;i.fp.load_integer32(z);i.fp.multiply64(dword_pair(m,0x00aa5f90u));ra2::platform::x87_extended::add_integer32(i.fp,correction);
        i.fp.add64(dword_pair(m,0x00785728u));const auto height=static_cast<std::int32_t>(convert_helper(m,i));
        sy=signed_dword(std::uint32_t(sy)-std::uint32_t(height));
        if(sx<static_cast<std::int32_t>(minx)||sx>static_cast<std::int32_t>(maxx)||sy<static_cast<std::int32_t>(miny)||sy>static_cast<std::int32_t>(maxy))continue;
        const auto rx=signed_dword(std::uint32_t(sx)-ox),ry=signed_dword(std::uint32_t(sy)-oy);
        auto written=m.r32(object+0xdb0u);if(written==500u||rx< -32||ry< -32)continue;
        if(rx>static_cast<std::int32_t>(m.r32(0x00821978u)+32u)||ry>static_cast<std::int32_t>(m.r32(0x0082197cu)+32u))continue;
        const auto slot=0x00aa6100u+written*12u;m.w32(slot,entity);m.w32(slot+4u,ox+std::uint32_t(rx));m.w32(slot+8u,oy+std::uint32_t(ry));
        m.w32(object+0xdb0u,written+1u);
    }
    return index;
}

std::uint32_t fun_00778eb7(Memory& m,const Inputs& input) {
    MutableFrame frame(input);auto& i=frame.value;
    auto raw=std::uint64_t(i.arg[0])|(std::uint64_t(i.arg[1])<<32u);
    i.fp.load64(raw);i.fp.compare_pop64(dword_pair(m,0x00786610u));
    std::int32_t exponent=0;std::uint64_t local=0;
    if((i.fp.status()&0x4000u)!=0){i.fp.load_zero();local=i.fp.pop64();}
    else{
        if((raw&0x7ff0000000000000ull)==0&&(raw&0xfffffffffffffull)!=0){
            i.fp.load64(raw);i.fp.compare_pop64(dword_pair(m,0x00786610u));const bool negative=(i.fp.status()&0x100u)!=0;
            exponent=-1021;
            while((raw&0x0010000000000000ull)==0){raw<<=1;--exponent;}
            raw&=~0x0010000000000000ull;if(negative)raw|=0x8000000000000000ull;
            i.arg[0]=std::uint32_t(raw);i.arg[1]=std::uint32_t(raw>>32);
        }else exponent=std::int32_t((raw>>52)&0x7ffu)-1022;
        // Caller spill, exact accepted 0x778dd0 load/spill/repack/load, caller spill.
        i.fp.load64(raw);raw=i.fp.pop64();i.fp.load64(raw);auto inner=i.fp.pop64();
        inner=(inner&0x800fffffffffffffull)|0x3fe0000000000000ull;
        i.fp.load64(inner);local=i.fp.pop64();
    }
    i.fp.load64(local);m.w32(i.arg[2],std::uint32_t(exponent));return i.arg[2];
}

namespace {
std::uint64_t read_pair(const Inputs& i,unsigned low_word) {
    return std::uint64_t(i.arg[low_word]) | (std::uint64_t(i.arg[low_word+1u])<<32u);
}
inline bool status_bit(const Inputs& i,std::uint16_t bit) { return (i.fp.status()&bit)!=0u; }
}

// RVA 0x7f7c0. This is an ordered x87 predicate; the local binary64 values
// correspond to the original ESP+8/+10/+18/+20/+28 slots. The only helper
// call is the frozen lookup-root operation translated by sqrt_helper().
std::uint32_t fun_0047f7c0(Memory& m,const Inputs& input) {
    MutableFrame f(input); auto& i=f.value;
    const auto zero=dword_pair(m,0x00786610u),fallback=dword_pair(m,0x00787528u);
    const auto t=std::uint64_t(i.arg[1])|(std::uint64_t(i.arg[2])<<32u);
    i.fp.load_integer32(i.cx); i.fp.load_integer32(i.dx); fcom64(i.fp,zero);
    i.ax=floating_b61::with_ax(i.ax,i.fp.status());
    // The observed equality branch substitutes the fallback operand.
    if((i.ax&0x4000u)!=0u){i.fp.pop_st0();i.fp.load64(fallback);}
    i.fp.load_integer32(i.arg[0]); const auto local10=i.fp.pop64();
    i.fp.load_st1();raw_register(i.fp,0xd8,0xca);const auto local8=i.fp.pop64();
    i.fp.load_st0();raw_register(i.fp,0xd8,0xc9);const auto local18=i.fp.pop64();i.fp.pop_st0();
    i.fp.load64(local8);raw_register(i.fp,0xd8,0xc9);raw_register(i.fp,0xde,0xc9);
    i.fp.load64(local8);i.fp.multiply64(local10);i.fp.multiply64(t);raw_register(i.fp,0xd8,0xc0);i.fp.subtract_pop();
    i.fp.load64(t);i.fp.multiply64(t);i.fp.multiply64(local18);i.fp.subtract_pop();
    const auto local20=i.fp.store64();i.fp.compare_pop64(zero);i.ax=floating_b61::with_ax(i.ax,i.fp.status());
    if((i.ax&0x0100u)!=0u)return (i.ax&0xffffff00u);
    i.fp.load64(local10);i.fp.multiply64(local10);i.fp.divide64(local18);i.fp.add64(dword_pair(m,0x00785708u));raw_register(i.fp,0xd8,0xc0);
    const auto local28=i.fp.store64();i.fp.compare_pop64(zero);i.ax=floating_b61::with_ax(i.ax,i.fp.status());
    if((i.ax&0x4000u)!=0u)return (i.ax&0xffffff00u);
    i.fp.load64(local10);i.fp.multiply64(t);i.fp.reverse_subtract64(local8);
    const auto numerator=i.fp.pop64();
    sqrt_helper(m,i,local20);i.fp.add64(numerator);i.fp.divide64(local28);i.fp.compare_pop64(zero);i.ax=floating_b61::with_ax(i.ax,i.fp.status());
    if((i.ax&0x0100u)!=0u){
        sqrt_helper(m,i,local20);i.fp.reverse_subtract64(numerator);i.fp.divide64(local28);i.fp.compare_pop64(zero);i.ax=floating_b61::with_ax(i.ax,i.fp.status());
        if((i.ax&0x0100u)!=0u)return i.ax&0xffffff00u;
    }
    return (i.ax&0xffffff00u)|1u;
}

// RVA 0x179f20. The first branch is the four-word global-key fast path. The
// other path preserves the original signed-short midpoint rounding and the
// x87 square-root/interpolation operation order for finite, nonzero divisors.
std::uint32_t fun_00579f20(Memory& m,const Inputs& input) {
    MutableFrame frame(input);auto& i=frame.value;
    const auto key=i.arg[2];
    const bool equal=m.r32(key)==m.r32(0x00a57c98u)&&m.r32(key+4)==m.r32(0x00a57c9cu)&&m.r32(key+8)==m.r32(0x00a57ca0u)&&m.r32(key+12)==m.r32(0x00a57ca4u);
    if(equal){
        const auto a=i.arg[0],b=i.arg[1];
        const auto dx=std::uint32_t(signed_word(m,a)-signed_word(m,b)),dy=std::uint32_t(signed_word(m,a+2)-signed_word(m,b+2));
        i.arg[0]=dx*dx+dy*dy;i.fp.load_integer32(i.arg[0]);sqrt_helper(m,i,i.fp.pop64());return i.ax;
    }
    const auto p0=i.arg[0],p1=i.arg[1],p3=i.arg[3];
    const auto x1=signed_word(m,p1),y1=signed_word(m,p1+2),x3=signed_word(m,p3),y3=signed_word(m,p3+2);
    const auto half=[](std::int32_t v){return global_b26::s32(global_b26::sar(std::uint32_t(v),1));};
    const auto mag=[](std::int32_t v){return v<0?0u-std::uint32_t(v):std::uint32_t(v);};
    const auto d0=mag(half(x1-y1)-half(x3-y3)),d1=mag(half(x1+y1)-half(x3+y3));
    i.arg[1]=std::uint32_t(x3);i.arg[2]=d0;i.arg[3]=d1;
    if(d0==0&&d1==0){i.fp.load32(m.r32(0x00785738u));return 0;}
    i.arg[1]=d0*d0+d1*d1;
    i.fp.load_integer32(i.arg[1]);sqrt_helper(m,i,i.fp.pop64());
    i.fp.load_integer32(i.arg[2]);raw_register(i.fp,0xd8,0xf1);
    const auto dx=mag(signed_word(m,p0)-x1),dy=mag(signed_word(m,p0+2)-y1);
    i.arg[0]=dx;const auto ratio=i.fp.pop64();
    fidivr32(i.fp,i.arg[3]);
    if(dx<=dy)i.arg[0]=dy;
    i.fp.multiply32(i.arg[5]);i.fp.load32(i.arg[4]);i.fp.multiply64(ratio);i.fp.add_pop();
    i.fp.load_integer32(i.arg[0]);raw_register(i.fp,0xde,0xc9);return dx;
}
} // namespace ra2::recovered::numeric_b71
