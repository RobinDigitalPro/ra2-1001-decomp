#include "recovered/indirect_b32_memory.hpp"

namespace ra2::recovered::indirect_b32 {
namespace {
constexpr std::uint32_t counter_9310=0x0081989cu;
constexpr std::uint32_t callback_9310=0x00785524u;
constexpr std::uint32_t cellptr_9310_a=0x00785754u;
constexpr std::uint32_t cellptr_9310_b=0x00785750u;

void call(Memory& m,State& s,Frame& f,const Operations& o,std::uint32_t target,
          std::uint32_t words,std::uint32_t cleanup) {
    f.argument_words=words;f.callback_cleanup=cleanup;invoke(m,s,f,o,target);
}

void fun_00409310(Memory& m,State& s,Frame& f,const Operations& o) {
    f.push(m,s.bx);f.push(m,s.bp);f.push(m,s.si);f.push(m,s.di);
    s.ax=m.r32(counter_9310);s.ax+=1u;m.w32(counter_9310,s.ax);
    s.si=m.r32(counter_9310);
    s.cx=m.r32(cellptr_9310_a);s.dx=m.r32(cellptr_9310_b);
    s.di=m.r32(s.cx);s.bx=m.r32(s.dx);
    s.ax=m.r32(counter_9310);
    if(s.si!=s.ax) {
        do { s.si=m.r32(counter_9310);s.ax=m.r32(counter_9310); }
        while(s.si!=s.ax);
    }
    s.bp=m.r32(callback_9310);
    for(;;) {
        call(m,s,f,o,s.bp,0,0);
        if(s.ax<s.bx)s.di+=1u;
        s.cx=m.r32(cellptr_9310_a);m.w32(s.cx,s.di);
        s.dx=m.r32(cellptr_9310_b);m.w32(s.dx,s.ax);
        s.ax=m.r32(counter_9310);
        if(s.si==s.ax)break;
        s.si=m.r32(counter_9310);
    }
    s.ax=m.r32(0x007b7d78u);s.dx=m.r32(0x007b7d7cu);
    s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.bx=f.pop(m);
    finish(m,s,f,0);
}

void fun_00495fb0(Memory& m,State& s,Frame& f,const Operations& o) {
    for(;;) {
        s.ax=m.r32(0x0083a708u);
        f.push(m,2u);f.push(m,s.ax);
        s.cx=m.r32(s.ax);
        const auto target=m.r32(s.cx+0x34u);
        call(m,s,f,o,target,2,8);
        if(s.ax==0u||s.ax==0x887601c2u)break;
    }
    finish(m,s,f,0);
}

void fun_004b4ad0(Memory& m,State& s,Frame& f,const Operations& o) {
    for(;;) {
        s.ax=m.r32(0x0083dd68u);
        if(s.ax==0u)break;
        s.ax=m.r32(0x0083dd5cu);s.cx=m.r32(s.ax);
        if(s.cx!=0u) {
            s.dx=m.r32(s.cx);f.push(m,1u);
            call(m,s,f,o,m.r32(s.dx+0x20u),1,4);
        }
        s.ax=m.r32(0x0083dd68u);
        if(s.ax==0u)break;
    }
    finish(m,s,f,0);
}

void fun_004b4b00(Memory& m,State& s,Frame& f,const Operations& o) {
    s.ax=m.r32(0x0083dd68u);f.push(m,s.si);s.si=s.ax-1u;
    if(s32(s.si)>=0) {
        for(;;) {
            s.cx=m.r32(0x0083dd5cu);s.cx=m.r32(s.cx+s.si*4u);
            s.dx=m.r32(s.cx+0x30u);s.ax=m.r32(s.cx+0x2cu);s.dx+=s.ax;
            s.ax=m.r32(0x00a2896cu);
            if(s32(s.ax)>=s32(s.dx)&&s.cx!=0u) {
                s.ax=m.r32(s.cx);f.push(m,1u);
                call(m,s,f,o,m.r32(s.ax+0x20u),1,4);
            }
            s.si-=1u;
            if(s32(s.si)<0)break;
        }
    }
    s.si=f.pop(m);finish(m,s,f,0);
}

void fun_004eb8e0(Memory& m,State& s,Frame& f,const Operations& o) {
    f.push(m,s.di);s.di=m.r32(f.entry_sp+4u);s.ax=m.r32(s.di+0x20cu);
    if(s32(s.ax)<=0) { s.ax=1u;s.di=f.pop(m);finish(m,s,f,4);return; }
    f.push(m,s.bx);s.bx=m.r32(s.di+0x54u);f.push(m,s.si);s.si=0;
    if(s32(s.bx)>0) {
        for(;;) {
            s.ax=m.r32(s.di+0x48u);s.cx=m.r32(s.ax+s.si*4u);
            if(s.cx!=0u) {
                s.ax=with_al(s.ax,m.r8(s.cx+0x76u));
                if((s.ax&0xffu)==0u) {
                    s.ax=m.r32(s.cx+0x6cu);
                    if(s32(s.ax)>0) {
                        s.dx=m.r32(s.cx);f.push(m,1u);
                        call(m,s,f,o,m.r32(s.dx+0x188u),1,4);
                    }
                }
            }
            s.si+=1u;
            if(s32(s.si)>=s32(s.bx))break;
        }
    }
    s.si=f.pop(m);s.bx=f.pop(m);s.ax=0;s.di=f.pop(m);finish(m,s,f,4);
}

void fun_005211f0(Memory& m,State& s,Frame& f,const Operations& o) {
    f.push(m,s.si);s.si=0x00a39a78u;
    while(s32(s.si)<s32(0x00a39bb8u)) {
        s.cx=m.r32(s.si);
        if(s.cx!=0u) {
            s.ax=m.r32(s.cx);f.push(m,1u);
            call(m,s,f,o,m.r32(s.ax),1,4);
        }
        m.w32(s.si,0u);s.si+=4u;
    }
    s.si=f.pop(m);finish(m,s,f,0);
}

void fun_005b2740(Memory& m,State& s,Frame& f,const Operations& o) {
    f.push(m,s.si);f.push(m,s.di);s.di=s.cx;s.si=0;s.ax=m.r32(s.di);
    while(s.ax!=0u) {
        s.dx=m.r32(s.ax);s.cx=s.ax;s.si+=1u;
        call(m,s,f,o,m.r32(s.dx+4u),0,0);
        if(s.ax==0u)break;
    }
    s.ax=with_al(s.ax,m.r8(s.di+0x19u));
    if((s.ax&0xffu)!=0u) {
        s.ax=with_al(s.ax,m.r8(s.di+0x1au));
        if((s.ax&0xffu)!=0u)s.si+=1u;
    }
    s.ax=s.si;s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,0);
}

void fun_005b2890(Memory& m,State& s,Frame& f,const Operations& o) {
    f.push(m,s.si);f.push(m,s.di);s.di=s.cx;
    s.ax=m.r8(s.di+0x19u);
    if((s.ax&0xffu)!=0u) {
        s.ax=with_al(s.ax,m.r8(s.di+0x1au));
        if((s.ax&0xffu)!=0u) { s.si=m.r32(s.di+0x14u);s.ax=m.r32(s.di+8u);s.si+=s.ax; }
        else s.si=m.r32(s.di+8u);
    } else s.si=m.r32(s.di+8u);
    s.ax=m.r32(s.di);
    while(s.ax!=0u) {
        s.dx=m.r32(s.ax);s.cx=s.ax;m.w32(s.ax+0x10u,s.si);
        call(m,s,f,o,m.r32(s.dx+4u),0,0);
        s.si+=m.r32(s.di+0x14u);
        if(s.ax==0u)break;
    }
    s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,0);
}

void fun_006a95f0(Memory& m,State& s,Frame& f,const Operations& o) {
    s.ax=m.r32(0x00aa7960u);
    if(s32(s.ax)>0) {
        for(;;) {
            s.ax=m.r32(0x00aa7954u);s.cx=m.r32(s.ax);
            if(s.cx!=0u) {
                s.dx=m.r32(s.cx);f.push(m,1u);
                call(m,s,f,o,m.r32(s.dx+0x20u),1,4);
            }
            s.ax=m.r32(0x00aa7960u);
            if(s32(s.ax)<=0)break;
        }
    }
    finish(m,s,f,0);
}

void fun_006b2e60(Memory& m,State& s,Frame& f,const Operations& o) {
    f.push(m,s.bx);f.push(m,s.bp);s.bp=s.cx;f.push(m,s.si);f.push(m,s.di);s.di=0;
    s.ax=m.r32(s.bp+0x24u);s.ax=m.r32(s.ax+0xdcu);s.cx=m.r32(s.ax+0x9cu);
    if(s32(s.cx)>0) {
        s.bx=0xa8u;
        for(;;) {
            s.ax=m.r32(s.bp+0x24u);s.ax=m.r32(s.ax+0xdcu);
            s.si=m.r32(s.bx+s.ax);s.cx=s.si;s.dx=m.r32(s.si);
            call(m,s,f,o,m.r32(s.dx+0x2cu),0,0);
            if(s.ax==3u) {
                s.ax=m.r32(s.si+0x52cu);
                if(s32(s.ax)>0) {
                    s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=with_al(s.ax,1u);
                    s.bx=f.pop(m);finish(m,s,f,0);return;
                }
            }
            s.ax=m.r32(s.bp+0x24u);s.ax=m.r32(s.ax+0xdcu);s.di+=1u;s.bx+=8u;
            if(s32(s.di)>=s32(m.r32(s.ax+0x9cu)))break;
        }
    }
    s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=with_al(s.ax,0u);s.bx=f.pop(m);
    finish(m,s,f,0);
}

void fun_006b4360(Memory& m,State& s,Frame& f,const Operations& o) {
    s.ax=m.r32(0x0084e4b8u);f.push(m,s.si);s.si=0;f.push(m,s.di);s.di=s.cx;
    if(s32(s.ax)>0) {
        s.ax=m.r32(0x0084e4acu);
        for(;;) {
            s.cx=m.r32(s.ax+s.si*4u);
            if(s.di==m.r32(s.cx+0x24u)) {
                if(s.cx!=0u) {
                    s.dx=m.r32(s.cx);f.push(m,1u);
                    call(m,s,f,o,m.r32(s.dx+0x20u),1,4);
                }
                s.si-=1u;
            }
            s.ax=m.r32(0x0084e4b8u);s.si+=1u;
            if(s32(s.si)>=s32(s.ax))break;
            s.ax=m.r32(0x0084e4acu);
        }
    }
    s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,0);
}
}

const std::array<Entry,11>& entries_c() {
    static const std::array<Entry,11> entries{{
        {0x9310,fun_00409310},{0x95fb0,fun_00495fb0},{0xb4ad0,fun_004b4ad0},
        {0xb4b00,fun_004b4b00},{0xeb8e0,fun_004eb8e0},{0x1211f0,fun_005211f0},
        {0x1b2740,fun_005b2740},{0x1b2890,fun_005b2890},{0x2a95f0,fun_006a95f0},
        {0x2b2e60,fun_006b2e60},{0x2b4360,fun_006b4360}
    }};
    return entries;
}
} // namespace ra2::recovered::indirect_b32
