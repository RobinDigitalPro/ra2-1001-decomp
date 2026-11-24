#include "recovered/records_b85.hpp"
#include "recovered/leaf_containers.hpp"
#include "recovered/leaf_state.hpp"
#include "recovered/leaf_b15_b.hpp"
#include "recovered/leaf_b21_b.hpp"
#include "recovered/leaf_text_rng.hpp"
#include "recovered/global_accessors_b20.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::records_b85 {
using namespace global_b26;
namespace {
std::uint32_t decrement_record(Memory& m, std::uint32_t record) {
    std::array<std::uint8_t, 16> bytes{};
    constexpr std::uint32_t base=0x1000;
    leaf::Memory lm(bytes.data(),base,static_cast<std::uint32_t>(bytes.size()));
    lm.w32(base+0x0c,m.r32(record+0x0c));
    leaf::Inputs in{}; in.cx=base;
    const auto result=leaf::fun_00401f90(lm,in);
    m.w32(record+0x0c,lm.r32(base+0x0c));
    return result;
}

std::uint32_t indexed_record(Memory& m, std::uint32_t container, std::uint32_t index) {
    // Invoke the accepted helper on a guest-address-equivalent temporary view.
    std::array<std::uint8_t, 0x400> bytes{};
    constexpr std::uint32_t base=0x2000;
    const auto count=m.r32(container+0x38), data=m.r32(container+0x2c);
    if (index>=count || count>4) throw std::domain_error("Block85 indexed-container contract exceeded");
    leaf::Memory lm(bytes.data(),base,static_cast<std::uint32_t>(bytes.size()));
    lm.w32(base+0x38,count); lm.w32(base+0x2c,base+0x100);
    leaf::Inputs in{}; in.cx=base; in.arg[0]=index;
    const auto p=leaf::fun_00719920(lm,in);
    if (!p) throw std::domain_error("Block85 indexed-container helper returned null inside positive contract");
    return data+(p-(base+0x100));
}

std::uint32_t alliance(Memory& m, std::uint32_t receiver, std::uint32_t candidate) {
    std::array<std::uint8_t,0x6000> bytes{};
    constexpr std::uint32_t base=0x10000, cx=base+0x100, other=base+0x200;
    leaf::Memory lm(bytes.data(),base,static_cast<std::uint32_t>(bytes.size()));
    lm.w32(cx+0x30,m.r32(receiver+0x30));
    lm.w32(cx+0x5674,m.r32(receiver+0x5674));
    lm.w32(other+0x30,m.r32(candidate+0x30));
    leaf::Inputs in{}; in.cx=cx; in.arg[0]=other;
    return leaf::fun_004e4be0(lm,in);
}
}

std::uint32_t fun_00405c10(Memory& m,const Inputs& i) {
    const auto w=i.cx, o=m.r32(w);
    if (m.r32(0x8192f8)!=0 && m.r32(w+0x0c)==0x8192ec && o && m.r32(w+8)==m.r32(o+0x24) &&
        m.r32(w+4)==m.r32(o+0x138) && !(m.r8(o+0x18)&1u) && m.r32(o+0xb0)==0) {
        const auto n=m.r32(o+0xa8);
        if(n<1 || n>4) throw std::domain_error("Block85 0x5c10 slot-count contract exceeded");
        for(std::uint32_t k=0;k<n;++k){const auto p=m.r32(o+0x28+4*k);if(!p)throw std::domain_error("Block85 0x5c10 null slot");(void)decrement_record(m,p);m.w32(o+0x28+4*k,0);}
        m.w32(o+0xa8,0);m.w32(o+0x1c,4);m.w32(o+0x138,0);m.w32(o+0x278,0);m.w32(o+0x18,m.r32(o+0x18)|1u);
        m.w32(w,0);
    }
    m.w32(w+8,0);m.w32(w+0x0c,0);return w;
}

std::uint32_t fun_00405d50(Memory& m,const Inputs& i) {
    const auto w=i.cx, o=m.r32(w);
    if (m.r32(0x8192f8)!=0 && m.r32(w+0x0c)==0x8192ec && o && m.r32(w+8)==m.r32(o+0x24) &&
        m.r32(w+4)==m.r32(o+0x138) && !(m.r8(o+0x18)&1u) && m.r32(o+0xb0)==0) {
        const auto n=m.r32(o+0xa8);
        if(n<1 || n>4) throw std::domain_error("Block85 0x5d50 slot-count contract exceeded");
        for(std::uint32_t k=0;k<n;++k){const auto p=m.r32(o+0x28+4*k);if(!p)throw std::domain_error("Block85 0x5d50 null slot");(void)decrement_record(m,p);m.w32(o+0x28+4*k,0);}
        m.w32(o+0xa8,0);m.w32(o+0x1c,4);m.w32(o+0x138,0);m.w32(o+0x278,0);m.w32(o+0x18,m.r32(o+0x18)|1u);
        m.w32(w,0);m.w32(w+8,0);
    }
    return w;
}

std::uint32_t fun_0044b610(Memory& m,const Inputs& i) {
    const auto o=i.cx, arr=m.r32(o+0x540); auto count=m.r32(o+0x54c);
    if(count<4||count>8)throw std::domain_error("Block85 0x4b610 count outside finite contract");
    for(std::uint32_t cursor=count;cursor>0;){--cursor;const auto p=m.r32(arr+4*cursor);if(m.r32(p+0x228)==o)continue;
        auto n=m.r32(o+0x54c);if(cursor>=n)continue;const auto new_count=n-1;m.w32(o+0x54c,new_count);
        for(std::uint32_t k=cursor;k<new_count;++k)m.w32(arr+4*k,m.r32(arr+4*(k+1)));
    }
    if(m.r32(o+0x54c)<3)throw std::domain_error("Block85 0x4b610 survivor-count contract exceeded");
    m.w8(o+0x531,1);return arr;
}

std::uint32_t fun_004ec700(Memory& m,const Inputs& i) {
    const auto o=i.cx, xy=i.arg[0]; std::uint32_t outer=0;
    const auto want_x=m.r16(xy),want_y=m.r16(xy+2);
    for(;outer<12;++outer){const auto c=m.r32(o+0x158+4*outer);if(!c)throw std::domain_error("Block85 0xec700 requires preinitialized containers");
        const auto count=m.r32(c+0x38);if(count>4)throw std::domain_error("Block85 0xec700 count exceeds four");
        for(std::uint32_t k=0;k<count;++k){const auto p=indexed_record(m,c,k);const auto x=m.r32(p),y=m.r32(p+4);
            const auto qx=leaf::sar(x+((x>>31)?0xffu:0u),8),qy=leaf::sar(y+((y>>31)?0xffu:0u),8);
            if(static_cast<std::uint16_t>(qx)==want_x && static_cast<std::uint16_t>(qy)==want_y)return p;
        }
    }
    return 0;
}

std::uint32_t fun_004ec7b0(Memory& m,const Inputs& i) {
    const auto o=i.cx,wanted=i.arg[0],out_index=i.arg[1],out_inner=i.arg[2];
    for(std::uint32_t outer=0;outer<12;++outer){const auto c=m.r32(o+0x158+4*outer);if(!c)throw std::domain_error("Block85 0xec7b0 requires preinitialized containers");
        const auto count=m.r32(c+0x38);if(count>4)throw std::domain_error("Block85 0xec7b0 count exceeds four");
        for(std::uint32_t k=0;k<count;++k)if(indexed_record(m,c,k)==wanted){m.w32(out_index,outer);m.w8(out_inner,k);return (out_index&0xffffff00u)|1u;}
    }
    m.w32(out_index,0xffffffffu);m.w8(out_inner,0);return out_inner&0xffffff00u;
}

std::uint32_t fun_005303c0(Memory& m,const Inputs& i) {
    const auto o=i.cx;auto head=m.r32(o+0x314),tail=m.r32(o+0x318);
    if(head>255||tail>255)throw std::domain_error("Block85 0x1303c0 ring cursor outside byte range");
    std::array<std::uint8_t,0x400> helper_bytes{};constexpr std::uint32_t helper_base=0x1000;
    leaf::Memory helper_memory(helper_bytes.data(),helper_base,static_cast<std::uint32_t>(helper_bytes.size()));
    helper_memory.w32(helper_base+0x314,head);helper_memory.w32(helper_base+0x318,tail);
    leaf::Inputs helper_inputs{};helper_inputs.cx=helper_base;
    if((leaf::fun_00530be0(helper_memory,helper_inputs)&0xffu)==0||
       (leaf::fun_00530c00(helper_memory,helper_inputs)&0xffu)!=0)
        throw std::domain_error("Block85 0x1303c0 full nonempty ring route not selected");
    auto read=[&](){const auto v=m.r16(o+0x114+2*head);head=(head+1u)&255u;m.w32(o+0x314,head);return v;};
    if(read()!=2)throw std::domain_error("Block85 0x1303c0 opcode contract exceeded");
    const auto a=read(),b=read();m.w32(o,a);m.w32(o+0x0c,a);m.w32(o+4,b);m.w32(o+0x10,b);return 2;
}

std::uint32_t fun_005382d0(Memory& m,const Inputs& i) {
    const auto o=i.cx, idx=i.arg[0];auto count=m.r32(o+0x44), arr=m.r32(o+0x38);
    if(count<4||count>32||idx>=count)throw std::domain_error("Block85 0x1382d0 index/count contract exceeded");
    const auto new_count=count-1;m.w32(o+0x44,new_count);
    for(std::uint32_t k=idx+1;k<=new_count;++k)m.w32(arr+4*(k-1),m.r32(arr+4*k));
    if(m.r32(o+0x50)>=new_count||m.r8(o+0x54)!=0)throw std::domain_error("Block85 0x1382d0 callback gate contract exceeded");
    auto x=m.r32(o+0x16c);if(s32(x)>=s32(new_count)){--x;if(s32(x)<0)x=0;m.w32(o+0x16c,x);}
    auto y=m.r32(o+0x170);std::uint32_t eax;
    if(s32(y)<s32(new_count))eax=y;else{--y;if(s32(y)<0)y=0;m.w32(o+0x170,y);eax=y&0xffffff00u;}
    return eax;
}

std::uint32_t fun_00592a60(Memory& m,const Inputs& i) {
    const auto o=i.cx,prev=m.r32(o+4),next=m.r32(o+8);
    if(m.r32(o+0x0c)||m.r32(o+0x20)||!m.r32(o+0x24)||m.r8(o+0x12)||!prev||!next||(i.arg[0]&1u))throw std::domain_error("Block85 0x192a60 finite reset contract exceeded");
    m.w32(o,0x791458);m.w32(o+0x24,0);m.w32(next+4,prev);m.w32(prev+8,next);m.w32(o+8,0);m.w32(o+4,0);m.w32(o,0x785afc);return o;
}

std::uint32_t fun_005b3af0(Memory& m,const Inputs& i) {
    const auto key=i.cx,count=m.r32(0xa59630),table=m.r32(0xa59624);
    if(!(m.r8(0xa59638)&1u)||count>32)throw std::domain_error("Block85 0x1b3af0 initialized lookup contract exceeded");
    for(std::uint32_t n=0;n<count;++n){const auto p=m.r32(table+4*n);if(!p)throw std::domain_error("Block85 0x1b3af0 null table record");if(m.r32(p+0x28)==key)return p;}
    return 0;
}

std::uint32_t fun_005bdc90(Memory& m,const Inputs& i) {
    const auto count=m.r32(0xa1a5d8),table=m.r32(0xa1a5cc),excluded=i.cx;
    if(count>32)throw std::domain_error("Block85 0x1bdc90 count exceeds finite contract");
    std::uint32_t result=0;
    for(std::uint32_t a=0;a<count;++a){const auto outer=m.r32(table+4*a);if(!outer||m.r8(outer+0x13d)||!m.r8(outer+0x134)||outer==excluded)continue;
        bool sticky=false,first_reciprocal_greater=false;
        for(std::uint32_t b=0;b<count;++b){if(b==a)continue;const auto inner=m.r32(table+4*b);if(!inner||m.r8(inner+0x13d)||!m.r8(inner+0x134)||inner==excluded)continue;
            if((alliance(m,outer,inner)&0xffu)==0)continue;
            if((alliance(m,inner,outer)&0xffu)==0)continue;
            if(b>a&&!sticky)first_reciprocal_greater=true;
            sticky=true;
        }
        if(first_reciprocal_greater||!sticky)++result;
    }
    return result;
}

std::uint32_t fun_005c3020(Memory& m,const Inputs&) {
    const auto count=m.r32(0xa27db8),table=m.r32(0xa27dac);if(count>64)throw std::domain_error("Block85 0x1c3020 count exceeds finite contract");
    std::array<std::uint8_t,0x1000> global_bytes{};constexpr std::uint32_t global_base=0x00b0d000;
    leaf::Memory global_memory(global_bytes.data(),global_base,static_cast<std::uint32_t>(global_bytes.size()));
    global_memory.w32(0x00b0d850,m.r32(0x00b0d850));leaf::Inputs global_inputs{};
    if(ra2::recovered::fun_0072a6e0(global_memory,global_inputs)!=0xbcu)
        throw std::domain_error("Block85 0x1c3020 first accessor did not return 0xbc");
    std::uint32_t last=0;
    for(std::uint32_t n=0;n<count;++n){const auto p=m.r32(table+4*n);if(!p)throw std::domain_error("Block85 0x1c3020 null table entry");
        std::array<std::uint8_t,0x400> bytes{};constexpr std::uint32_t base=0x3000;
        // Both strings are copied as bounded UTF-16 units; the original helper is executed unchanged.
        auto copy=[&](std::uint32_t src,std::uint32_t dst){std::uint32_t k=0;do{if(k+2>=bytes.size())throw std::domain_error("Block85 0x1c3020 string exceeds bounded helper view");const auto ch=m.r16(src+2*k);bytes[dst-base+2*k]=static_cast<std::uint8_t>(ch);bytes[dst-base+2*k+1]=static_cast<std::uint8_t>(ch>>8);++k;if(!ch)break;}while(true);};
        copy(p,base+0x20);copy(0xa2793e,base+0x200);
        leaf::Memory lm(bytes.data(),base,static_cast<std::uint32_t>(bytes.size()));leaf::Inputs in{};in.arg[0]=base+0x20;in.arg[1]=base+0x200;
        if(leaf::fun_0076f113(lm,in)==0||m.r32(p+0x65)==0)throw std::domain_error("Block85 0x1c3020 positive-clear contract exceeded");
        m.w32(p+0x65,0);last=p;
    }
    return last;
}

std::uint32_t fun_005d4730(Memory& m,const Inputs& i) {
    if(i.cx!=0)throw std::domain_error("Block85 0x1d4730 requires ECX zero");
    const auto object=m.r32(m.r32(0xa1e11c));if(!m.r8(object+0x279))throw std::domain_error("Block85 0x1d4730 object gate not selected");
    if(m.r32(0xaa8648)!=1)throw std::domain_error("Block85 0x1d4730 one-entry interval required");
    const auto p=m.r32(m.r32(0xaa863c));if(m.r32(m.r32(p+0xe0)+0x264)!=0||m.r32(p+0xe8)!=1)throw std::domain_error("Block85 0x1d4730 first interval contract exceeded");
    return m.r32(p+0x98);
}

std::uint32_t fun_005f8380(Memory& m,const Inputs& i) {
    const auto d=i.cx,s=i.arg[0];if(m.r32(s+0x28)||m.r32(s+0x34)||m.r32(d+0x28)||m.r32(d+0x34))throw std::domain_error("Block85 0x1f8380 ownership-field contract exceeded");
    const auto old3c=m.r32(d+0x3c),old28=m.r32(d+0x28),old34=m.r32(d+0x34);
    for(std::uint32_t n=0;n<0x80;++n)m.w32(d+4*n,m.r32(s+4*n));
    m.w32(d+0x3c,old3c);m.w32(d+0x28,old28);m.w32(d+0x34,old34);return d;
}

std::uint32_t fun_00665c40(Memory& m,const Inputs& i) {
    auto target=i.arg[0];if(target==0)target=m.r32(0xa1e0e4);
    if(m.r32(0xa255c8)==4)throw std::domain_error("Block85 0x265c40 string-comparison branch excluded");
    const auto count=m.r32(0xa1a5d8),table=m.r32(0xa1a5cc);if(count>32)throw std::domain_error("Block85 0x265c40 count exceeds finite contract");
    std::uint32_t last=0;
    for(std::uint32_t n=0;n<count;++n){last=m.r32(table+4*n);if(!last)throw std::domain_error("Block85 0x265c40 null record");if(m.r8(last+0x134)&&!m.r8(last+0x13d))return (last&0xffffff00u)|(last==target?1u:0u);}
    return last&0xffffff00u;
}

std::uint32_t fun_006e0e60(Memory& m,const Inputs& i) {
    const auto o=i.cx,key=i.arg[0],out=i.arg[1];if(m.r32(o+0x250)!=1||m.r8(o+0x258)==0)throw std::domain_error("Block85 0x2e0e60 prepared one-row route required");
    const auto row=m.r32(o+0x24c);if(m.r32(row)!=key)return 0;
    const auto payload=m.r32(row+4);for(std::uint32_t n=0;n<7;++n)m.w32(out+4*n,m.r32(payload+4*n));m.w32(o+0x25c,row);return 1;
}

std::uint32_t fun_007574c0(Memory& m,const Inputs& i) {
    if((i.arg[0]&0xffu)!=0)throw std::domain_error("Block85 0x3574c0 bank-one route excluded");
    const auto o=i.cx,count=m.r32(o+0x43860),cursor=m.r32(o+0x43854);if(count>=128||cursor>127)throw std::domain_error("Block85 0x3574c0 capacity/cursor contract exceeded");
    for(std::uint32_t k=0;k<128;++k){const auto idx=(cursor+k)&127u;m.w32(o+0x43854,(idx+1)&127u);const auto slot=o+0x16850+idx*0x2d0;
        if(m.r8(slot+0x45)==0){m.w8(slot+0x45,1);m.w32(o+0x43860,count+1);m.w8(slot+0x47,0);m.w8(slot+0x48,0);return slot;}}
    return 0;
}

std::uint32_t fun_00763ce0(Memory& m,const Inputs& i) {
    const auto o=i.cx,d=m.r32(o+0x6dc);if((m.r32(d+0x14)&4u)||!(m.r8(o+0x1a4)&1u)||m.r32(o+0x48)||m.r32(o+0x4c))throw std::domain_error("Block85 0x363ce0 call-free flag route not selected");
    m.w32(o+0x1a4,m.r32(o+0x1a4)&~1u);return 0xffffffffu;
}

std::uint32_t fun_00768000(Memory& m,const Inputs& i) {
    const auto o=i.cx,start=i.dx,end=i.arg[0],value=i.arg[1],action=i.arg[2],extent=m.r32(o+0x10);
    if(s32(start)<0||s32(end)<0||s32(start)>=s32(extent)||s32(end)>=s32(extent)||s32(start)>=s32(end)||action!=1||m.r32(o+0x124)==0)throw std::domain_error("Block85 0x368000 local action-one contract exceeded");
    const auto norm=s32(value)<0?0xffffffffu:value, flags=m.r32(o+0x150);
    if(flags&0x80u){m.w32(o+0x13c,start);m.w32(o+0x138,m.r32(o+0x12c));}
    else {m.w32(o+0x144,start);m.w32(o+0x140,end);}
    // The flag route preserves the old first endpoint in +0x128. The
    // adjacent route initializes that field from the requested start.
    if(!(flags&0x80u))m.w32(o+0x128,start);
    m.w32(o+0x130,end);m.w32(o+0x134,norm);return 0xffffffffu;
}

std::uint32_t fun_0076f800(Memory& m,const Inputs& i) {
    const auto index=i.arg[0],descriptor=i.arg[1],inner=i.arg[2],expected=i.arg[3],outer_key=i.arg[4];
    const auto header=m.r32(descriptor+0x10);if(m.r32(header+8)!=1)throw std::domain_error("Block85 0x36f800 one-outer route required");
    const auto table=m.r32(header+0xc),record=m.r32(table);if(m.r32(record+4)!=1)throw std::domain_error("Block85 0x36f800 one-child route required");
    if(m.r32(record)!=outer_key||m.r32(m.r32(table+4))!=inner)throw std::domain_error("Block85 0x36f800 pointer-identity keys not selected");
    const auto child=m.r32(table+4);
    std::array<std::uint8_t,0x1000> bytes{};constexpr std::uint32_t base=0x1000,obj=base+0x100,tab=base+0x300,p=base+0x500;
    const auto b=m.r32(child+0xc),off=m.r32(child+0x10);if(s32(b)<0||index>0x100||off>0x400)throw std::domain_error("Block85 0x36f800 helper-address contract exceeded");
    const auto map_base=base+0x600, map_p=base+0x900;
    leaf::Memory lm(bytes.data(),base,static_cast<std::uint32_t>(bytes.size()));lm.w32(obj,child+8);lm.w32(obj+4,map_base);lm.w32(obj+8,off);lm.w32(map_base+index,map_p);lm.w32(map_p+off,m.r32(m.r32(b+index)+off));
    leaf::Inputs hi{};hi.arg[0]=index;hi.arg[1]=obj;const auto actual=leaf::fun_0076fa31(lm,hi)+(b-map_base);
    if(actual!=expected) throw std::domain_error("Block85 0x36f800 expected derived-value route not selected");
    return record;
}
}
