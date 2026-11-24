#include "recovered/heap_b29_memory.hpp"

#include <stdexcept>

namespace ra2::recovered::heap_b29 {
namespace {
inline std::uint32_t byte_with(std::uint32_t v, std::uint32_t b) { return (v & 0xffffff00u) | (b & 0xffu); }
inline void release_ptr(Memory& m, State& s, const Operations& op, std::uint32_t p) {
    release(m, s, op, p);
}
}

void fun_00407440(Memory& m, State& s, const Operations& op) {
    release_ptr(m,s,op,s.cx);
}
void fun_004083e0(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx, p=m.r32(s.cx);
    if(p) release_ptr(m,s,op,p);
    release_ptr(m,s,op,self);
}
void fun_00408d20(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx, p=m.r32(s.cx+0x10u);
    if(p) release_ptr(m,s,op,p);
    release_ptr(m,s,op,self);
}

void fun_0040e1d0(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx;
    s.dx=0;
    m.w32(self,0x00785afcu);
    auto next=m.r32(self+4u);
    s.cx=next;
    if(next!=0) {
        const auto prev=m.r32(self+8u);
        s.ax=prev;
        if(prev!=0) {
            m.w32(prev+4u,next);
            next=m.r32(self+4u);
            const auto tail=m.r32(self+8u);
            s.cx=tail;
            m.w32(next+8u,tail);
            m.w32(self+8u,0);
            m.w32(self+4u,0);
        }
    }
    if((s.arg[0]&1u)!=0) release_ptr(m,s,op,self);
    s.ax=self;
}

void fun_0042e140(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx;
    const auto enabled=m.r32(self+0x60u); s.ax=enabled;
    if(enabled==0) return;
    bool called=false;
    for(unsigned outer=0;outer<8;++outer) for(unsigned inner=0;inner<3;++inner) {
        const auto slot=self+4u*(outer*3u+inner);
        const auto p=m.r32(slot); s.ax=p;
        if(p!=0) { release_ptr(m,s,op,p); called=true; m.w32(slot,0); }
    }
    m.w32(self+0x60u,0);
    if(!called) s.ax=0;
}
void fun_00431280(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx;
    auto p=m.r32(self+0x18u); s.ax=p; if(p) release_ptr(m,s,op,p);
    p=m.r32(self+0x1cu); s.ax=p; if(p) release_ptr(m,s,op,p);
    release_ptr(m,s,op,self);
}

void fun_0042f460(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx; const auto p=m.r32(self+0x2cu); s.ax=p;
    if(p!=0) {
        if(m.r8(self+0x20u)!=0) {
            release_ptr(m,s,op,p); m.w8(self+0x20u,0);
        }
        m.w32(self+0x2cu,0);
    }
    m.w32(self+0x30u,0); m.w8(self+0x21u,0); m.w8(self+0x23u,0);
    m.w8(self+0x24u,0); m.w8(self+0x25u,0);
}

void fun_00438250(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx, other=s.arg[0];
    if(other==self) { s.ax=self; return; }
    const auto active=m.r8(self+8u); s.ax=byte_with(s.ax,active);
    if(active!=0) release_ptr(m,s,op,m.r32(self));
    m.w8(self+8u,0);
    const auto first=m.r32(other); s.cx=first; m.w32(self,first);
    const auto second=m.r32(other+4u); s.dx=second; m.w32(self+4u,second);
    s.ax=self;
}

void fun_00438290(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx; const auto enabled=m.r8(self+8u); s.ax=byte_with(s.ax,enabled);
    if(enabled!=0) release_ptr(m,s,op,m.r32(self));
    m.w32(self,0); m.w32(self+4u,0); m.w8(self+8u,0);
}
void fun_004382c0(Memory& m, State& s, const Operations& op) { fun_00438290(m,s,op); }
void fun_0048df30(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx, array=m.r32(self+0x3cu); s.ax=array;
    if(!array) return;
    s.ax=m.r32(self+0x40u);
    for(std::uint32_t i=0; s32(i)<s32(s.ax); ++i) {
        s.ax=m.r32(self+0x3cu);s.ax=m.r32(s.ax+i*4u);
        if(s.ax)release_ptr(m,s,op,s.ax);
        s.ax=m.r32(self+0x40u);
    }
    s.cx=m.r32(self+0x3cu);release_ptr(m,s,op,s.cx);
}

template<std::uint32_t Flag,std::uint32_t Pointer,std::uint32_t ClearFlag>
void free_flagged_field(Memory& m,State& s,const Operations& op,std::uint32_t self) {
    const auto flag=m.r8(self+Flag); s.ax=byte_with(s.ax,flag);
    if(flag!=0) {
        const auto p=m.r32(self+Pointer); s.ax=p;
        if(p!=0) { release_ptr(m,s,op,p); m.w32(self+Pointer,0); m.w8(self+ClearFlag,0); }
    }
}

void fun_0045e590(Memory& m, State& s, const Operations& op) { free_flagged_field<0x13e2u,0xb98u,0xb9cu>(m,s,op,s.cx); }
void fun_0045e5d0(Memory& m, State& s, const Operations& op) { free_flagged_field<0x11d0u,0x11ccu,0x11d0u>(m,s,op,s.cx); }
void fun_0045e610(Memory& m, State& s, const Operations& op) { free_flagged_field<0x11a4u,0x11a0u,0x11a4u>(m,s,op,s.cx); }
void fun_0045e650(Memory& m, State& s, const Operations& op) { free_flagged_field<0x11acu,0x11a8u,0x11acu>(m,s,op,s.cx); }
void fun_0045e690(Memory& m, State& s, const Operations& op) { free_flagged_field<0x11b4u,0x11b0u,0x11b4u>(m,s,op,s.cx); }
void fun_0045e6d0(Memory& m, State& s, const Operations& op) { free_flagged_field<0x11bcu,0x11b8u,0x11bcu>(m,s,op,s.cx); }

void fun_00491a00(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx; const auto p=m.r32(self+4u); s.ax=p; m.w32(self,0x007889d4u);
    if(p!=0 && m.r8(self+0xdu)!=0) { release_ptr(m,s,op,p); m.w32(self+4u,0); }
    m.w8(self+0xdu,0); m.w32(self+8u,0);
}
void fun_004b20c0(Memory& m, State& s, const Operations& op) {
    constexpr std::uint32_t cnt=0x0083b390u, arrp=0x0083b384u, flag=0x0083b38du;
    auto count=m.r32(cnt); s.ax=count;
    for(std::uint32_t i=0; static_cast<std::int32_t>(i)<static_cast<std::int32_t>(count); ++i) {
        const auto array=m.r32(arrp); s.ax=array;
        const auto item=m.r32(array+i*4u); s.ax=item;
        if(item) {
            const auto nested=m.r32(item+0x20u);
            s.cx=nested;
            if(nested) { m.w32(nested+0x5c4u,0); m.w32(item+0x20u,0); }
            release_ptr(m,s,op,item);
        }
        count=m.r32(cnt); s.ax=count;
    }
    const auto array=m.r32(arrp); s.ax=array; m.w32(cnt,0);
    if(array && m.r8(flag)) { release_ptr(m,s,op,array); m.w32(arrp,0); }
    m.w8(flag,0); m.w32(0x0083b388u,0);
}
void fun_004bacd0(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx,p=m.r32(self+8u); release_ptr(m,s,op,p); m.w32(self+8u,0);
}

template<std::uint32_t Tag,bool EarlyClear,bool WriteTag=true>
void free_link_field(Memory& m,State& s,const Operations& op,std::uint32_t self) {
    const auto p=m.r32(self+4u); s.ax=p;
    if constexpr(EarlyClear) m.w32(self+0x10u,0);
    if constexpr(WriteTag) m.w32(self,Tag);
    if(p!=0 && m.r8(self+0xdu)!=0) {
        const auto header=m.r32(p-4u); s.cx=header-1u;
        const auto base=p-4u; release_ptr(m,s,op,base);
        m.w32(self+4u,0);
    }
    m.w8(self+0xdu,0); m.w32(self+8u,0);
}
void fun_004ce240(Memory& m,State& s,const Operations& op) { free_link_field<0u,false,false>(m,s,op,s.cx); }
void fun_004ce3a0(Memory& m,State& s,const Operations& op) { free_link_field<0u,true,false>(m,s,op,s.cx); }
void fun_004f6360(Memory& m,State& s,const Operations& op) { free_link_field<0u,true,false>(m,s,op,s.cx); }
void fun_004f7710(Memory& m,State& s,const Operations& op) {
    const auto self=s.cx; const auto p=m.r32(self+4u); s.ax=p;
    if(p!=0 && m.r8(self+0xdu)!=0) {
        const auto header=m.r32(p-4u); s.cx=header-1u;
        const auto base=p-4u; release_ptr(m,s,op,base); m.w32(self+4u,0);
    }
    m.w8(self+0xdu,0); m.w32(self+8u,0);
}

void free_tagged_arg(Memory& m,State& s,const Operations& op,std::uint32_t self,std::uint32_t tag) {
    auto p=m.r32(self+4u); m.w32(self,tag);
    if(p) {
        const auto owned=m.r8(self+0xdu);s.cx=with_al(s.cx,owned);
        if(owned) {const auto base=p-4u;s.cx=m.r32(base)-1u;release_ptr(m,s,op,base);m.w32(self+4u,0);}
    }
    const auto argflag=static_cast<std::uint8_t>(s.arg[0]);
    m.w8(self+0xdu,0); m.w32(self+8u,0);
    if(argflag&1u) release_ptr(m,s,op,self);
    s.ax=self;
}
void fun_004ce670(Memory& m,State& s,const Operations& op) { free_tagged_arg(m,s,op,s.cx,0x78c7d4u); }
void fun_004ce710(Memory& m,State& s,const Operations& op) { free_tagged_arg(m,s,op,s.cx,0x78c7d4u); }
void fun_004f7d00(Memory& m,State& s,const Operations& op) { free_tagged_arg(m,s,op,s.cx,0x78dfacu); }
void fun_004f7da0(Memory& m,State& s,const Operations& op) { free_tagged_arg(m,s,op,s.cx,0x78dfacu); }
void fun_004ce6d0(Memory& m,State& s,const Operations& op) {
    const auto self=s.cx; const auto flags=static_cast<std::uint8_t>(s.arg[0]);
    s.cx=with_al(s.cx,flags);
    const auto p=(flags&2u)?self-4u:self;
    if(flags&2u) { s.ax=m.r32(p)-1u; }
    if(flags&1u) release_ptr(m,s,op,p);
    s.ax=p;
}
void fun_004f7d60(Memory& m,State& s,const Operations& op) { fun_004ce6d0(m,s,op); }

void fun_00567930(Memory& m,State& s,const Operations& op) {
    const auto self=s.cx, p=m.r32(self+4u);
    m.w32(self+0x10u,0);
    if(p && m.r8(self+0xdu)) {
        const auto base=p-4u, count=m.r32(base);
        for(std::uint32_t i=0;i<count;++i) {
            const auto rec=p+(count-1u-i)*0x24u;
            const auto item=m.r32(rec+4u); m.w32(rec,0x78576cu);
            if(item && m.r8(rec+0xdu)) { release_ptr(m,s,op,item); m.w32(rec+4u,0); }
            m.w8(rec+0xdu,0); m.w32(rec+8u,0);
        }
        s.cx=base; release_ptr(m,s,op,base);
        m.w32(self+4u,0);
    }
    m.w8(self+0xdu,0); m.w32(self+8u,0);
}

void fun_0050fed0(Memory& m, State& s, const Operations& op) { fun_0040e1d0(m,s,op); }
void fun_0058a920(Memory& m,State& s,const Operations& op) {
    const auto self=s.cx, p=m.r32(self+8u);
    release_ptr(m,s,op,p);
    if(s.arg[0]&1u) release_ptr(m,s,op,self);
    s.ax=self;
}
void fun_005881e0(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx,p=m.r32(self+4u); release_ptr(m,s,op,p); m.w32(self+4u,0);
}

void fun_00592870(Memory& m, State& s, const Operations& op) {
    const auto self=s.cx,p=m.r32(self+0x24u); s.ax=p;
    if(p!=0 && m.r8(self+0x12u)!=0) release_ptr(m,s,op,p);
    m.w32(self+0x24u,0);m.w8(self+0x12u,0);
}
void free_nonnull_field(Memory& m,State& s,const Operations& op,std::uint32_t self,std::uint32_t off) {
    const auto p=m.r32(self+off); s.ax=p;
    if(p!=0) release_ptr(m,s,op,p);
    m.w32(self+off,0);
}
void fun_0059b990(Memory& m,State& s,const Operations& op) { free_nonnull_field(m,s,op,s.cx,0xcu); }
void fun_0059bbb0(Memory& m,State& s,const Operations& op) { free_nonnull_field(m,s,op,s.cx,0xcu); }

void fun_0059cce0(Memory& m,State& s,const Operations& op) {
    const auto flag=m.r8(0x00a58bbcu); s.ax=byte_with(s.ax,flag);
    if(flag!=0) { const auto p=m.r32(0x00a58b7cu); s.ax=p; release_ptr(m,s,op,p); m.w8(0x00a58bbcu,0); }
    m.w32(0x00a58b7cu,0);
}

void fun_005a9300(Memory& m,State& s,const Operations& op) {
    const auto self=s.cx,p=m.r32(self+0x1cu); s.ax=p; m.w32(self,0x00791d38u);
    if(p!=0) {
        const auto flag=m.r8(self+0x3cu); s.cx=byte_with(s.cx,flag);
        if(flag!=0) { release_ptr(m,s,op,p); m.w32(self+0x1cu,0); m.w8(self+0x3cu,0); }
    }
    m.w32(self,0x00791d10u);
}
void fun_005a9ff0(Memory& m,State& s,const Operations& op) { fun_005a9300(m,s,op); }

void free_tagged_with_arg(Memory& m,State& s,const Operations& op,std::uint32_t self) {
    const auto p=m.r32(self+0x1cu); m.w32(self,0x791d38u);
    if(p) {
        const auto owned=m.r8(self+0x3cu);s.cx=with_al(s.cx,owned);
        if(owned){release_ptr(m,s,op,p);m.w32(self+0x1cu,0);m.w8(self+0x3cu,0);}
    }
    const auto flag=static_cast<std::uint8_t>(s.arg[0]);
    m.w32(self,0x791d10u);
    if(flag&1u) release_ptr(m,s,op,self);
    s.ax=self;
}
void fun_005ac8a0(Memory& m,State& s,const Operations& op) { free_tagged_with_arg(m,s,op,s.cx); }
void fun_005ac8f0(Memory& m,State& s,const Operations& op) { free_tagged_with_arg(m,s,op,s.cx); }
void fun_005ac940(Memory& m,State& s,const Operations& op) { free_tagged_with_arg(m,s,op,s.cx); }

const std::array<Entry,43>& entries_a() {
    static const std::array<Entry,43> value{{
        {0x7440u,fun_00407440},{0x83e0u,fun_004083e0},{0x8d20u,fun_00408d20},{0xe1d0u,fun_0040e1d0},{0x2e140u,fun_0042e140},
        {0x2f460u,fun_0042f460},{0x31280u,fun_00431280},{0x38250u,fun_00438250},{0x38290u,fun_00438290},{0x382c0u,fun_004382c0},
        {0x5e590u,fun_0045e590},{0x5e5d0u,fun_0045e5d0},{0x5e610u,fun_0045e610},{0x5e650u,fun_0045e650},{0x5e690u,fun_0045e690},{0x5e6d0u,fun_0045e6d0},
        {0x8df30u,fun_0048df30},{0x91a00u,fun_00491a00},{0xb20c0u,fun_004b20c0},{0xbacd0u,fun_004bacd0},{0xce240u,fun_004ce240},{0xce3a0u,fun_004ce3a0},
        {0xce670u,fun_004ce670},{0xce6d0u,fun_004ce6d0},{0xce710u,fun_004ce710},{0xf6360u,fun_004f6360},{0xf7710u,fun_004f7710},
        {0xf7d00u,fun_004f7d00},{0xf7d60u,fun_004f7d60},{0xf7da0u,fun_004f7da0},{0x10fed0u,fun_0050fed0},{0x167930u,fun_00567930},
        {0x1881e0u,fun_005881e0},{0x18a920u,fun_0058a920},{0x192870u,fun_00592870},{0x19b990u,fun_0059b990},{0x19bbb0u,fun_0059bbb0},
        {0x19cce0u,fun_0059cce0},{0x1a9300u,fun_005a9300},{0x1a9ff0u,fun_005a9ff0},{0x1ac8a0u,fun_005ac8a0},{0x1ac8f0u,fun_005ac8f0},{0x1ac940u,fun_005ac940}
    }};
    return value;
}
} // namespace ra2::recovered::heap_b29
