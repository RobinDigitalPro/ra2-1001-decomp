#include "recovered/indirect_b31_memory.hpp"
#include <string>

namespace ra2::recovered::indirect_b31 {
namespace {

void call(Memory& m, State& s, Frame& f, const Operations& op, std::uint32_t target) {
    invoke(m, s, f, op, target);
}

void complete(Memory& m, State& s, Frame& f, std::uint32_t cleanup) {
    if(f.sp!=f.entry_sp)throw std::runtime_error("B31 complete stack delta="+std::to_string(std::int64_t(f.sp)-std::int64_t(f.entry_sp)));
    indirect_b31::finish(m, s, f, cleanup);
}

// The two accessors share the same original instruction shape. The selector
// changes only the final field read after the callback/index scan.
void indexed_max_field(Memory& m, State& s, Frame& f, const Operations& op,
                       std::uint32_t result_offset) {
    f.push(m, s.si);
    s.si = s.cx;
    s.ax = with_al(s.ax, m.r8(s.si + 4u));
    bool early = (s.ax & 0xffu) == 0;
    if (!early) {
        s.ax = with_al(s.ax, m.r8(s.si + 5u));
        early = (s.ax & 0xffu) == 0;
    }
    if (!early) {
        s.cx = m.r32(s.si + 0x44u);
        early = s.cx == 0;
    }
    if (early) {
        s.ax = 0;
        s.si = f.pop(m);
        complete(m, s, f, 4u);
        return;
    }
    s.ax = m.r32(f.sp + 8u);
    if (s.ax != 0xffffffffu) {
        s.dx = m.r32(s.si);
        f.push(m, s.ax);
        s.cx = s.si;
        call(m, s, f, op, m.r32(s.dx + 0x18u));
        if (s.ax == 0xffffffffu) {
            s.ax = 0;
            s.si = f.pop(m);
            complete(m, s, f, 4u);
            return;
        }
        s.ax = m.r32(s.si + s.ax * 4u + 0x28u);
        s.si = f.pop(m);
        s.cx = m.r32(s.ax + 4u);
        s.ax = m.r32(s.cx + result_offset);
        complete(m, s, f, 4u);
        return;
    }

    // Only the original -1 argument path reaches the maximum scan.
    s.ax = 0;
    if (s32(s.cx) > 0) {
        s.dx = s.si + 0x28u;
        s.si = s.cx;
        do {
            s.cx = m.r32(s.dx);
            s.cx = m.r32(s.cx + 4u);
            s.cx = m.r32(s.cx + result_offset);
            if (s32(s.cx) > s32(s.ax)) s.ax = s.cx;
            s.dx += 4u;
            --s.si;
        } while (s.si != 0);
    }
    s.si = f.pop(m);
    complete(m, s, f, 4u);
}

void fun_00524d60(Memory& m, State& s, Frame& f, const Operations& op) {
    indexed_max_field(m, s, f, op, 0x28u);
}
void fun_00524dd0(Memory& m, State& s, Frame& f, const Operations& op) {
    indexed_max_field(m, s, f, op, 0x38u);
}

void fun_005298f0(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(s.cx);
    call(m, s, f, op, m.r32(s.ax + 0x9cu));
    s.cx = s.ax;
    if (s.cx == 0) {
        s.ax = with_al(s.ax, 0);
        complete(m, s, f, 12u);
        return;
    }
    f.push(m, s.bx);
    f.push(m, s.si);
    s.si = m.r32(s.cx + 4u);
    s.si *= m.r32(s.cx);
    s.ax = m.r32(f.sp + 0x0cu);
    s.dx = s32(s.ax) < 0 ? 0xffffffffu : 0u;
    if (!s.si || (s.ax == 0x80000000u && s.si == 0xffffffffu))
        throw std::domain_error("Block31 0x1298f0 excluded IDIV fault");
    const auto dividend = std::int64_t(s32(s.dx)) * 0x100000000ll + s.ax;
    const auto quotient = dividend / std::int64_t(s32(s.si));
    const auto remainder = dividend % std::int64_t(s32(s.si));
    s.ax = std::uint32_t(quotient);
    s.dx = std::uint32_t(remainder);
    s.si = m.r32(f.sp + 0x10u);
    s.ax = m.r32(s.cx + 8u);
    s.dx = m.r32(s.cx + s.dx * 4u + 0x10u);
    m.w32(s.si,s.ax);
    s.ax = m.r32(f.sp + 0x14u);
    s.cx = m.r32(s.cx + 0x0cu);
    m.w32(s.ax,s.cx);
    if(s.dx && (m.r8(s.dx+0x24u)&1u)){
        s.si=m.r32(s.dx+4u);
        s.bx=m.r32(s.dx+0x18u);
        s.si-=s.bx;
        s.si+=s.cx;
        m.w32(s.ax,s.si);
    }
    s.si=f.pop(m);s.ax=with_al(s.ax,1u);s.bx=f.pop(m);
    complete(m, s, f, 12u);
}

void fun_00529990(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax = m.r32(s.cx);
    call(m, s, f, op, m.r32(s.ax + 0x9cu));
    s.cx = s.ax;
    if (s.cx == 0) {
        s.ax = with_al(s.ax, 0);
        complete(m, s, f, 4u);
        return;
    }
    f.push(m, s.si);
    s.si = m.r32(s.cx + 4u);
    s.si *= m.r32(s.cx);
    s.ax = m.r32(f.sp + 8u);
    s.dx = s32(s.ax) < 0 ? 0xffffffffu : 0u;
    if (!s.si || (s.ax == 0x80000000u && s.si == 0xffffffffu))
        throw std::domain_error("Block31 0x129990 excluded IDIV fault");
    const auto dividend = std::int64_t(s32(s.dx)) * 0x100000000ll + s.ax;
    const auto quotient = dividend / std::int64_t(s32(s.si));
    const auto remainder = dividend % std::int64_t(s32(s.si));
    s.ax = std::uint32_t(quotient);
    s.dx = std::uint32_t(remainder);
    s.si = f.pop(m);
    s.cx = m.r32(s.cx + s.dx * 4u + 0x10u);
    if (s.cx == 0) s.ax = with_al(s.ax,0);
    else s.ax = (m.r32(s.cx + 0x24u) >> 2) & 1u;
    complete(m, s, f, 4u);
}

void copy_triplet_after_predicate(Memory& m, State& s, Frame& f,
                                  const Operations& op, std::uint32_t fallback_page,
                                  std::uint32_t first_offset) {
    f.push(m, s.si);
    s.si = m.r32(f.sp + 8u);
    f.push(m, s.di);
    f.push(m, s.si);
    s.ax = m.r32(s.si);
    call(m, s, f, op, m.r32(s.ax + 0x10u));
    const bool accepted = (s.ax & 0xffu) != 0;
    const auto out = m.r32(f.sp + 0x10u);
    s.ax = out;
    if (accepted) {
        s.cx = m.r32(s.si + first_offset);
        s.dx = m.r32(s.si + first_offset + 4u);
        s.si = m.r32(s.si + first_offset + 8u);
    } else {
        s.cx = m.r32(fallback_page);
        s.dx = m.r32(fallback_page + 4u);
        s.si = m.r32(fallback_page + 8u);
    }
    s.di = out;
    m.w32(s.di, s.cx);
    m.w32(s.di + 4u, s.dx);
    m.w32(s.di + 8u, s.si);
    s.di = f.pop(m);
    s.si = f.pop(m);
    complete(m, s, f, 8u);
}
void fun_0052d5c0(Memory& m, State& s, Frame& f, const Operations& op) {
    copy_triplet_after_predicate(m, s, f, op, 0x00a56010u, 0x38u);
}
void fun_0058e560(Memory& m, State& s, Frame& f, const Operations& op) {
    copy_triplet_after_predicate(m, s, f, op, 0x00a58730u, 0x14u);
}

void fun_00537140(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m, s.si);
    s.si = s.cx;
    s.cx = m.r32(f.sp + 8u);
    s.dx = 0;
    m.w32(s.si + 4u, s.dx);
    m.w32(s.si + 8u, s.dx);
    m.w32(s.si, 0x0078c8b4u);
    s.ax = m.r32(s.cx + 4u);
    m.w32(s.cx + 4u, s.si);
    m.w32(s.si + 8u, s.cx);
    m.w32(s.si + 4u, s.ax);
    if (s.ax != 0) {
        m.w32(s.ax + 8u, s.si);
        s.ax = m.r32(s.si);
        s.cx = s.si;
        call(m, s, f, op, m.r32(s.ax + 0x18u));
        s.ax = s.si;
    }
    s.si = f.pop(m);
    complete(m, s, f, 4u);
}

void fun_00537280(Memory& m, State& s, Frame& f, const Operations& op) {
    s.dx = m.r32(f.sp + 4u);
    s.ax = m.r32(s.dx + 4u);
    m.w32(s.dx + 4u, s.cx);
    m.w32(s.cx + 8u, s.dx);
    m.w32(s.cx + 4u, s.ax);
    if (s.ax != 0) {
        m.w32(s.ax + 8u, s.cx);
        s.ax = m.r32(s.cx);
        call(m, s, f, op, m.r32(s.ax + 0x18u));
    }
    complete(m, s, f, 4u);
}

void fun_005392c0(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m, s.si);
    s.si = s.cx;
    s.ax = 0;
    s.cx = s.si + 0x20u;
    m.w32(s.cx + 4u, s.ax);
    m.w32(s.cx + 8u, s.ax);
    m.w8(s.cx + 0xcu, 1u);
    m.w8(s.cx + 0xdu, s.ax);
    m.w32(s.cx, 0x00790824u);
    m.w32(s.cx + 0x14u, 0xau);
    m.w32(s.cx + 0x10u, s.ax);
    m.w32(s.si + 4u, s.ax);
    m.w32(s.si + 0xcu, s.ax);
    m.w32(s.si + 0x14u, s.ax);
    s.ax = m.r32(s.cx);
    m.w32(s.si, 0x007907fcu);
    m.w32(s.si + 8u, 0x007ca620u);
    m.w32(s.si + 0x10u, 0x800u);
    call(m, s, f, op, m.r32(s.ax + 0xcu));
    s.ax = s.si;
    s.si = f.pop(m);
    complete(m, s, f, 0u);
}

void fun_0053b620(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m,s.si); s.si=m.r32(f.sp+0x0cu); // entry arg1
    if(!s.si){s.ax=0x80004003u;s.si=f.pop(m);complete(m,s,f,8u);return;}
    s.cx=m.r32(f.sp+8u);s.ax=m.r32(s.cx);call(m,s,f,op,m.r32(s.ax+0x24u));
    s.ax+=4u;m.w32(s.si,s.ax);m.w32(s.si+4u,0u);s.ax=0;
    s.si=f.pop(m);complete(m,s,f,8u);
}

void fun_0053c2f0(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m,s.di);s.di=m.r32(f.sp+8u);
    if(s.di){s.ax=m.r32(s.di);s.cx=s.di;call(m,s,f,op,m.r32(s.ax+0x2cu));}
    if(s.di && s.ax==0x2cu){
        s.cx=m.r32(0x84e4a0u);s.dx=0;
        if(s32(s.cx)>0){
            f.push(m,s.si);s.si=m.r32(0x84e494u);
            while(true){
                if(s.di==m.r32(s.si+s.dx*4u)){
                    if(s32(s.dx)<s32(s.cx)){
                        --s.cx;s.ax=s.dx;m.w32(0x84e4a0u,s.cx);
                        if(s32(s.dx)<s32(s.cx)){
                            do {
                                s.cx=m.r32(s.si+s.ax*4u+4u);
                                m.w32(s.si+s.ax*4u,s.cx);
                                s.cx=m.r32(0x84e4a0u);s.si=m.r32(0x84e494u);
                                ++s.ax;
                            } while(s32(s.ax)<s32(s.cx));
                        }
                    }
                    --s.dx;
                }
                ++s.dx;
                if(s32(s.dx)>=s32(s.cx))break;
            }
            s.si=f.pop(m);
        }
    }
    s.di=f.pop(m);complete(m,s,f,8u);
}

void fun_0053c550(Memory& m, State& s, Frame& f, const Operations& op) {
    s.ax=m.r32(f.sp+4u);f.push(m,s.si);s.si=s.cx;
    if(m.r8(s.ax+0x84u)){
        s.dx=m.r32(s.si);s.ax=f.sp+8u;f.push(m,s.ax);s.cx=s.si;
        call(m,s,f,op,m.r32(s.dx+0x10u));
        if(s.ax!=0xffffffffu){s.cx=m.r32(s.si+0x10u);
            if(s32(s.ax)<s32(s.cx)){--s.cx;m.w32(s.si+0x10u,s.cx);
                if(s32(s.ax)<s32(s.cx)){
                    do {s.cx=m.r32(s.si+4u);++s.ax;s.dx=m.r32(s.cx+s.ax*4u);
                         m.w32(s.cx+s.ax*4u-4u,s.dx);s.cx=m.r32(s.si+0x10u);
                    } while(s32(s.ax)<s32(s.cx));
                }
            }
        }
        s.ax=m.r32(f.sp+8u);m.w8(s.ax+0x84u,0);
    }
    s.si=f.pop(m);complete(m,s,f,4u);
}

void fun_00545800(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m,s.si);s.si=s.cx;s.cx=s.si+0x134u;
    if(s.cx){m.w32(s.cx+4u,0);m.w32(s.cx+8u,0);m.w8(s.cx+0xcu,1);m.w8(s.cx+0xdu,0);m.w32(s.cx,0x790998u);}
    s.dx=m.r32(s.si+0x150u);s.ax=m.r32(s.cx);f.push(m,0);f.push(m,s.dx);call(m,s,f,op,m.r32(s.ax+8u));
    s.cx=m.r32(s.si+0x150u);s.ax=0;
    if(s32(s.cx)>0){do{s.cx=m.r32(s.si+0x138u);++s.ax;m.w32(s.cx+s.ax*4u-4u,0);s.cx=m.r32(s.si+0x150u);}while(s32(s.ax)<s32(s.cx));}
    s.si=f.pop(m);complete(m,s,f,0);
}

void fun_005687a0(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m,s.bx);f.push(m,s.si);s.si=s.cx;s.bx=0;
    m.w32(s.si+4u,0);m.w32(s.si+8u,0);m.w8(s.si+0xcu,1);m.w8(s.si+0xdu,0);
    m.w32(s.si,0x790ab8u);m.w32(s.si+0x14u,10);m.w32(s.si+0x10u,0);
    call(m,s,f,op,m.r32(0x790ac4u));
    m.w16(s.si+0x18u,0);m.w32(s.si+0x1cu,0);m.w32(s.si+0x20u,0);
    s.ax=s.si;s.si=f.pop(m);s.bx=f.pop(m);complete(m,s,f,0);
}

void fun_00569b50(Memory& m, State& s, Frame& f, const Operations& op) {
    f.push(m,s.si);s.si=s.cx;
    s.cx=m.r32(s.si+8u);s.ax=m.r32(s.si+0x10u);
    if(s32(s.ax)>=s32(s.cx)){
        s.ax=with_al(s.ax,m.r8(s.si+0x0du));
        if(s.cx==0u){
            s.ax=m.r32(s.si+0x14u);
            if(s32(s.ax)>0){
                s.dx=m.r32(s.si);s.ax+=s.cx;
                f.push(m,0u);f.push(m,s.ax);s.cx=s.si;
                call(m,s,f,op,m.r32(s.dx+8u));
                if((s.ax&0xffu)==0u){s.ax=with_al(s.ax,0u);s.si=f.pop(m);complete(m,s,f,4u);return;}
                goto append;
            }
        }
        s.ax=with_al(s.ax,0u);s.si=f.pop(m);complete(m,s,f,4u);return;
    }
append:
    s.ax=m.r32(s.si+0x10u);s.cx=s.ax+1u;s.dx=s.ax+s.ax*2u;s.ax=m.r32(s.si+4u);
    m.w32(s.si+0x10u,s.cx);s.si=f.pop(m);
    s.cx=s.ax+s.dx*4u;s.dx=m.r32(f.sp+4u);s.ax=m.r32(s.dx);m.w32(s.cx,s.ax);
    s.ax=m.r32(s.dx+4u);m.w32(s.cx+4u,s.ax);s.ax=with_al(s.ax,1u);
    s.dx=m.r32(s.dx+8u);m.w32(s.cx+8u,s.dx);
    complete(m,s,f,4u);
}

void fun_0059a7f0(Memory& m,State& s,Frame& f,const Operations& op){
    s.ax=m.r32(0xa58b28u);s.cx=0;m.w8(0xa58b21u,0);
    if(s.ax){m.w8(0xa58b22u,0);f.push(m,0);f.push(m,s.ax);call(m,s,f,op,m.r32(0x785498u));}
    complete(m,s,f,0);
}
void fun_0059d880(Memory& m,State& s,Frame& f,const Operations& op){
    s.ax=m.r32(0xae0a68u);
    if(s32(s.ax)>0){s.ax=m.r32(0xae0a5cu);f.push(m,s.cx);s.ax=m.r32(s.ax);s.cx=s.ax;s.dx=m.r32(s.ax);call(m,s,f,op,m.r32(s.dx+8u));}
    complete(m,s,f,0);
}
void fun_005a8b00(Memory& m,State& s,Frame& f,const Operations& op){
    f.sp-=8u;f.push(m,s.si);const auto local=f.sp+4u;s.si=s.cx; s.ax=local;f.push(m,s.ax);
    call(m,s,f,op,m.r32(0x7851ccu));
    if(s.ax){s.cx=m.r32(f.sp+8u);s.ax=m.r32(f.sp+4u);m.w32(s.si,s.cx);}
    else {m.w32(s.si,0);s.ax=0;}
    s.si=f.pop(m);f.sp+=8u;complete(m,s,f,0);
}
void fun_005ac4d0(Memory& m,State& s,Frame& f,const Operations& op){
    f.push(m,s.si);s.si=s.cx;s.cx=m.r32(s.si+0x24u);m.w32(s.si,0x791e54u);
    if(s.cx){s.ax=m.r32(s.cx);f.push(m,1);call(m,s,f,op,m.r32(s.ax));}
    m.w32(s.si,0x791d10u);s.si=f.pop(m);complete(m,s,f,0);
}

void append_global(Memory&m,State&s,Frame&f,const Operations&op,std::uint32_t root,
                   std::uint32_t count_addr,std::uint32_t cap_addr,std::uint32_t grow_addr,
                   std::uint32_t data_addr,std::uint32_t sorted_addr,std::uint32_t object){
    s.ax=m.r32(count_addr);s.si=object;const auto cap=m.r32(cap_addr);
    if(s32(cap)>=s32(s.ax)){
        s.cx=m.r8(sorted_addr);if(!s.cx&&s.ax)goto done;
        s.cx=m.r32(grow_addr);if(s32(s.cx)<=0)goto done;
        s.cx+=s.ax;s.dx=m.r32(root);f.push(m,0);f.push(m,s.cx);s.cx=root;
        call(m,s,f,op,m.r32(s.dx+8u));if(!(s.ax&0xffu))goto done;
    }
    s.cx=m.r32(count_addr);s.ax=s.cx;m.w32(count_addr,s.cx+1u);m.w32(m.r32(data_addr)+s.ax*4u,s.si);
done:
    complete(m,s,f,0);
}
void fun_005b2b10(Memory&m,State&s,Frame&f,const Operations&op){
    // The global container compares capacity/count before optional growth.
    f.push(m,s.si);s.ax=m.r32(0xa59520u);s.si=s.cx;
    if(s32(m.r32(0xa59528u))<s32(s.ax))goto add;
    if(!m.r8(0xa59525u)&&s.ax)goto out;
    s.cx=m.r32(0xa5952cu);if(s32(s.cx)<=0)goto out;
    s.cx+=s.ax;s.ax=m.r32(0xa59518u);f.push(m,0);f.push(m,s.cx);s.cx=0xa59518u;
    call(m,s,f,op,m.r32(s.ax+8u));if(!(s.ax&0xffu))goto out;
add:
    s.cx=m.r32(0xa59528u);s.ax=s.cx;m.w32(0xa59528u,s.cx+1u);s.cx=m.r32(0xa5951cu);m.w32(s.cx+s.ax*4u,s.si);
out:s.si=f.pop(m);complete(m,s,f,0);
}
void fun_005b2b70(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);s.dx=m.r32(0xa59518u);m.w32(f.sp,s.cx);s.ax=f.sp;f.push(m,s.ax);s.cx=0xa59518u;
    call(m,s,f,op,m.r32(s.dx+0x10u));
    if(s.ax!=0xffffffffu){s.cx=m.r32(0xa59528u);if(s32(s.ax)<s32(s.cx)){
        --s.cx;m.w32(0xa59528u,s.cx);
        if(s32(s.ax)<s32(s.cx)){do{ s.cx=m.r32(0xa5951cu);++s.ax;s.dx=m.r32(s.cx+s.ax*4u);m.w32(s.cx+s.ax*4u-4u,s.dx);s.cx=m.r32(0xa59528u);}while(s32(s.ax)<s32(s.cx));}
    }}
    s.cx=f.pop(m);complete(m,s,f,0);
}
void fun_005b6410(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.si);s.si=s.cx;f.push(m,s.di);s.di=m.r32(f.sp+0x0cu);s.ax=m.r32(s.si);f.push(m,s.di);call(m,s,f,op,m.r32(s.ax+4u));
    if(s.ax&0xffu){s.cx=m.r32(0xa27dacu);s.ax=m.r32(s.si+8u);s.dx=m.r32(s.cx+s.di*4u);s.di=f.pop(m);s.si=f.pop(m);m.w32(s.dx+0x59u,s.ax);s.ax=with_al(s.ax,1);}
    else{s.di=f.pop(m);s.si=f.pop(m);}
    complete(m,s,f,4u);
}
void fun_005b6730(Memory&m,State&s,Frame&f,const Operations&op){
    s.cx=m.r32(0x821f90u);f.push(m,s.si);s.si=0;m.w16(0xa2793eu,0);
    if(s.cx){s.ax=m.r32(s.cx);f.push(m,1);call(m,s,f,op,m.r32(s.ax));}
    m.w32(0x821f90u,0);s.si=f.pop(m);complete(m,s,f,0);
}

void call_index_triplet(Memory&m,State&s,Frame&f,const Operations&op,std::uint32_t offset,
                        std::uint32_t pushes,std::uint32_t cleanup,std::uint32_t retclean){
    f.push(m,s.si);s.si=s.cx;s.ax=m.r32(s.si+0x3cu);
    if(!s.ax){s.ax=0;s.si=f.pop(m);complete(m,s,f,retclean);return;}
    s.cx=m.r32(s.si+0x38u);
    if(pushes==2){s.dx=m.r32(f.sp+8u);f.push(m,s.dx);s.dx=m.r32(f.sp+0xcu);f.push(m,s.dx);}
    else if(pushes==3){s.dx=m.r32(f.sp+0x10u);f.push(m,0);f.push(m,s.dx);s.dx=m.r32(f.sp+0x14u);f.push(m,s.dx);s.dx=m.r32(f.sp+0x14u);f.push(m,s.dx);}
    s.ax=m.r32(s.cx);call(m,s,f,op,m.r32(s.ax+offset));
    if(!s.ax)m.w32(s.si+0x68u,m.r32(s.si+0x68u)+1u);
    (void)cleanup;s.si=f.pop(m);complete(m,s,f,retclean);
}
void fun_005c8c80(Memory&m,State&s,Frame&f,const Operations&op){call_index_triplet(m,s,f,op,8u,3u,12u,12u);}
void fun_005c8cc0(Memory&m,State&s,Frame&f,const Operations&op){
    s.ax=m.r32(s.cx+0x3cu);if(!s.ax){s.ax=0;complete(m,s,f,8);return;}
    s.dx=m.r32(f.sp+8u);s.cx=m.r32(s.cx+0x38u);f.push(m,s.dx);s.dx=m.r32(f.sp+8u);s.ax=m.r32(s.cx);f.push(m,s.dx);call(m,s,f,op,m.r32(s.ax+0x10u));complete(m,s,f,8);
}
void fun_005ca5f0(Memory&m,State&s,Frame&f,const Operations&op){call_index_triplet(m,s,f,op,8u,3u,12u,16u);}
void fun_005cd490(Memory&m,State&s,Frame&f,const Operations&op){
    f.sp-=12u;s.ax=m.r32(s.cx);s.dx=f.sp;f.push(m,s.si);f.push(m,s.dx);call(m,s,f,op,m.r32(s.ax+0x48u));
    s.dx=s.ax;s.si=m.r32(f.sp+0x14u);s.ax=m.r32(s.dx);s.cx=m.r32(s.dx+4u);s.dx=m.r32(s.dx+8u);m.w32(f.sp+0xcu,s.dx);
    s.dx=m.r32(s.si);s.ax-=s.dx;s.dx=s.ax;s.ax=m.r32(s.si+4u);s.ax=s.cx-s.ax;s.si=f.pop(m);s.cx=s.ax;s.ax=s.cx;s.cx=s.dx;s.ax*=s.ax;s.cx*=s.cx;s.ax+=s.cx;f.sp+=12u;complete(m,s,f,4u);
}
void fun_005cda70(Memory&m,State&s,Frame&f,const Operations&op){
    s.ax=with_al(s.ax,m.r8(s.cx+0x74u));if(!(s.ax&0xffu)){s.ax=with_al(s.ax,0);complete(m,s,f,0);return;}
    s.ax=m.r32(s.cx);call(m,s,f,op,m.r32(s.ax+0x1b0u));s.cx=m.r32(0xa5aaa8u);s.dx=s.cx+s.cx;
    s.ax=with_al(s.ax,s32(s.ax)<s32(s.dx)?1u:0u);complete(m,s,f,0);
}
void fun_005cdaa0(Memory&m,State&s,Frame&f,const Operations&op){
    s.ax=with_al(s.ax,m.r8(s.cx+0x74u));if(!(s.ax&0xffu)){s.ax=with_al(s.ax,0);complete(m,s,f,0);return;}
    s.ax=m.r32(s.cx);call(m,s,f,op,m.r32(s.ax+0x1b0u));s.cx=m.r32(0xa5aaa8u);s.dx=s.cx+s.cx;
    s.ax=with_al(s.ax,s32(s.ax)>=s32(s.dx)?1u:0u);complete(m,s,f,0);
}
void fun_005cdb80(Memory&m,State&s,Frame&f,const Operations&op){
    s.ax=m.r32(s.cx);f.sp-=12u;s.dx=f.sp;f.push(m,s.si);f.push(m,s.dx);call(m,s,f,op,m.r32(s.ax+0x48u));
    s.cx=s.ax;s.ax=m.r32(f.sp+0x14u);s.dx=s.ax;s.si=m.r32(s.cx);m.w32(s.dx,s.si);s.si=m.r32(s.cx+4u);m.w32(s.dx+4u,s.si);
    s.si=f.pop(m);s.cx=m.r32(s.cx+8u);m.w32(s.dx+8u,s.cx);f.sp+=12u;complete(m,s,f,8u);
}

void fun_005d5c10(Memory&m,State&s,Frame&f,const Operations&op){
    s.dx=m.r32(f.sp+8u);f.push(m,s.si);s.si=s.cx;s.cx=m.r32(f.sp+8u);s.ax=s.si;m.w32(s.ax,s.cx);
    s.cx=m.r32(f.sp+0x10u);m.w32(s.ax+4u,s.dx);s.dx=0;m.w32(s.si+0xcu,0);m.w32(s.si+0x14u,0);m.w32(s.ax+8u,s.cx);s.ax=m.r32(f.sp+0x14u);m.w32(s.si+0x10u,s.ax);
    s.ax=m.r32(0xa5ad28u);if(s32(m.r32(0xa5ad30u))>=s32(s.ax)){
        if(m.r8(0xa5ad2du)||!s.ax){s.cx=m.r32(0xa5ad34u);if(s32(s.cx)>0){s.cx+=s.ax;f.push(m,0);s.dx=m.r32(0xa5ad20u);f.push(m,s.cx);s.cx=0xa5ad20u;call(m,s,f,op,m.r32(s.dx+8u));if(s.ax&0xffu)goto add;}}
    }else goto add;
    goto done;
add:s.cx=m.r32(0xa5ad30u);s.ax=s.cx;m.w32(0xa5ad30u,s.cx+1u);s.cx=m.r32(0xa5ad24u);m.w32(s.cx+s.ax*4u,s.si);
done:s.ax=s.si;s.si=f.pop(m);complete(m,s,f,16u);
}
void fun_005d5c90(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);s.dx=m.r32(0xa5ad20u);s.ax=f.sp;m.w32(f.sp,s.cx);f.push(m,s.ax);s.cx=0xa5ad20u;call(m,s,f,op,m.r32(s.dx+0x10u));
    if(s.ax!=0xffffffffu){s.cx=m.r32(0xa5ad30u);if(s32(s.ax)<s32(s.cx)){--s.cx;m.w32(0xa5ad30u,s.cx);if(s32(s.ax)<s32(s.cx)){do{s.cx=m.r32(0xa5ad24u);++s.ax;s.dx=m.r32(s.cx+s.ax*4u);m.w32(s.cx+s.ax*4u-4u,s.dx);s.cx=m.r32(0xa5ad30u);}while(s32(s.ax)<s32(s.cx));}}}
    s.cx=f.pop(m);complete(m,s,f,0);
}

std::uint32_t find_hash_node(Memory&m,State&s,Frame&f,const Operations&op,std::uint32_t key_slot){
    // The wrappers load this global into EAX before their computed call.
    s.ax=m.r32(0xa5b1a4u);
    if(!s.ax)return 0;
    s.cx=key_slot;call(m,s,f,op,m.r32(0xa5b1b8u));
    s.cx=m.r32(0xa5b1acu);s.dx=1u<<(s.cx&31u);--s.dx;s.dx&=s.ax;
    s.ax=m.r32(0xa5b1a0u);s.ax=m.r32(s.ax+s.dx*4u);
    while(s.ax && m.r32(s.ax)!=m.r32(key_slot))s.ax=m.r32(s.ax+0x204u);
    return s.ax;
}
void fun_005da550(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);f.push(m,s.si);s.si=s.dx;m.w32(f.sp+4u,s.cx);
    const auto node=find_hash_node(m,s,f,op,f.sp+4u);
    if(node){s.ax=node+4u;if(s.ax)m.w32(s.ax+0xc0u,s.si);}
    s.si=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}
void fun_005dcae0(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);f.push(m,s.bx);f.push(m,s.si);s.si=0;s.bx=with_al(s.bx,s.dx);
    m.w32(f.sp+8u,s.cx);const auto node=find_hash_node(m,s,f,op,f.sp+8u);
    if(!node)m.w8(s.si+0xbcu,std::uint8_t(s.bx));else m.w8(node+0xc0u,std::uint8_t(s.bx));
    s.si=f.pop(m);s.bx=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}
void fun_005dcb50(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);f.push(m,s.si);s.si=0;m.w32(f.sp+4u,s.cx);const auto node=find_hash_node(m,s,f,op,f.sp+4u);
    s.ax=with_al(s.ax,node?m.r8(node+0xc0u):m.r8(s.si+0xbcu));s.si=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}
void hash_byte_update(Memory&m,State&s,Frame&f,const Operations&op,std::uint32_t offset,
                      std::uint32_t entry_offset,std::uint8_t value,bool preserve_regs){
    f.push(m,s.cx);f.push(m,s.si);if(preserve_regs)f.push(m,s.di);s.si=0;m.w32(f.sp+(preserve_regs?8u:4u),s.cx);
    const auto keyslot=f.sp+(preserve_regs?8u:4u);const auto node=find_hash_node(m,s,f,op,keyslot);
    if(node)m.w8(node+entry_offset,value);else m.w8(s.si+offset,value);
    if(preserve_regs)s.di=f.pop(m);s.si=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}
void fun_005de740(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);f.push(m,s.si);f.push(m,s.di);s.si=0;m.w32(f.sp+8u,s.cx);const auto node=find_hash_node(m,s,f,op,f.sp+8u);
    s.dx=1u;
    if(node){s.di=f.pop(m);m.w8(node+0xc1u,std::uint8_t(s.dx));}else{m.w8(s.si+0xbdu,std::uint8_t(s.dx));s.di=f.pop(m);}
    s.si=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}
void fun_005de7b0(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);f.push(m,s.bx);f.push(m,s.si);s.bx=0;s.si=0;m.w32(f.sp+8u,s.cx);const auto node=find_hash_node(m,s,f,op,f.sp+8u);
    if(node)m.w8(node+0xc1u,0);else m.w8(s.si+0xbdu,0);
    s.si=f.pop(m);s.bx=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}
void fun_005de820(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);f.push(m,s.si);f.push(m,s.di);s.si=0;m.w32(f.sp+8u,s.cx);const auto node=find_hash_node(m,s,f,op,f.sp+8u);
    s.dx=1u;
    if(node){s.di=f.pop(m);m.w8(node+0xd8u,std::uint8_t(s.dx));}else{m.w8(s.si+0xd4u,std::uint8_t(s.dx));s.di=f.pop(m);}
    s.si=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}
void hash_magic_flag(Memory&m,State&s,Frame&f,const Operations&op,std::uint32_t field,std::uint32_t flag,
                     std::uint32_t magic1,std::uint32_t magic2){
    f.push(m,s.cx);f.push(m,s.si);s.si=0;m.w32(f.sp+4u,s.cx);const auto node=find_hash_node(m,s,f,op,f.sp+4u);
    const auto entry=node?node+4u:s.si;
    const auto value=m.r32(entry+field);const auto b=(value==magic1||value==magic2)?1u:0u;m.w8(entry+flag,std::uint8_t(b));s.ax=b;s.si=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}
void fun_005e2a30(Memory&m,State&s,Frame&f,const Operations&op){hash_magic_flag(m,s,f,op,0x6cu,0xd7u,0x103u,0xbc7u);}
void fun_005e2b10(Memory&m,State&s,Frame&f,const Operations&op){hash_magic_flag(m,s,f,op,0x6cu,0xd8u,0x108u,0xbc6u);}
void fun_005e2de0(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);f.push(m,s.si);s.si=0;m.w32(f.sp+4u,s.cx);const auto node=find_hash_node(m,s,f,op,f.sp+4u);s.ax=m.r32((node?node:s.si)+ (node?0x70u:0x6cu));s.si=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}

void hash_value_find(Memory&m,State&s,Frame&f,const Operations&op,std::uint32_t link_offset){
    f.push(m,s.si);s.si=s.cx;f.push(m,s.di);
    s.ax=m.r32(s.si+4u);
    if(!s.ax){s.di=f.pop(m);s.ax=with_al(s.ax,0);s.si=f.pop(m);complete(m,s,f,8u);return;}
    s.di=m.r32(f.sp+0xcu);s.cx=s.di;
    call(m,s,f,op,m.r32(s.si+0x18u));
    s.cx=m.r32(s.si+0xcu);s.dx=1u<<(s.cx&31u);--s.dx;s.dx&=s.ax;
    s.ax=m.r32(s.si);s.ax=m.r32(s.ax+s.dx*4u);
    if(!s.ax){s.di=f.pop(m);s.ax=with_al(s.ax,0);s.si=f.pop(m);complete(m,s,f,8);return;}
    while(m.r32(s.ax)!=m.r32(s.di)){s.ax=m.r32(s.ax+link_offset);if(!s.ax){s.di=f.pop(m);s.ax=with_al(s.ax,0);s.si=f.pop(m);complete(m,s,f,8);return;}}
    if(!s.ax){s.di=f.pop(m);s.ax=with_al(s.ax,0);s.si=f.pop(m);complete(m,s,f,8);return;}
    const auto out=m.r32(f.sp+0x10u);
    s.cx=out;s.ax+=4u;s.di=f.pop(m);s.si=f.pop(m);m.w32(out,s.ax);s.ax=with_al(s.ax,1);complete(m,s,f,8);
}
void fun_005f93c0(Memory&m,State&s,Frame&f,const Operations&op){hash_value_find(m,s,f,op,0x204u);}
void fun_005f9590(Memory&m,State&s,Frame&f,const Operations&op){hash_value_find(m,s,f,op,8u);}

void fun_00606640(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.si);s.si=s.cx;f.push(m,s.di);s.di=0;s.ax=m.r32(s.si+4u);m.w32(s.si,0x789a20u);
    if(s.ax){s.cx=m.r32(s.si+8u);m.w32(s.ax+8u,s.cx);}
    s.cx=m.r32(s.si+8u);if(s.cx){s.ax=m.r32(s.si+4u);s.dx=m.r32(s.cx);f.push(m,s.ax);call(m,s,f,op,m.r32(s.dx+0xcu));}
    m.w32(s.si+8u,0);m.w32(s.si+4u,0);s.di=f.pop(m);s.si=f.pop(m);complete(m,s,f,0);
}
void fun_006066d0(Memory&m,State&s,Frame&f,const Operations&op){
    s.cx=m.r32(s.cx+4u);if(!s.cx){s.ax=m.r32(f.sp+8u);complete(m,s,f,8);return;}
    s.dx=m.r32(f.sp+8u);s.ax=m.r32(s.cx);f.push(m,s.dx);s.dx=m.r32(f.sp+8u);f.push(m,s.dx);call(m,s,f,op,m.r32(s.ax+0x10u));complete(m,s,f,8);
}
void fun_006076d0(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.si);s.si=m.r32(f.sp+8u);f.push(m,s.di);s.di=s.cx;
    if(m.r32(s.di+0x18u)!=s.si){
      if(s.si){s.cx=m.r32(s.si+8u);if(s.cx){s.ax=m.r32(s.cx);f.push(m,0);call(m,s,f,op,m.r32(s.ax+0xcu));m.w32(s.si+8u,0);}}
      s.ax=m.r32(s.di+0x18u);if(s.ax)m.w32(s.ax+8u,0);
      if(s.si){m.w32(s.di+0x18u,s.si);s.cx=s.di+0x14u;m.w32(s.si+8u,s.cx);}else m.w32(s.di+0x18u,0);
      s.dx=s.di+0x14u;m.w32(s.di+0x1cu,s.di);m.w32(s.di+4u,s.dx);
    }
    s.di=f.pop(m);s.si=f.pop(m);complete(m,s,f,4);
}
void fun_00607a10(Memory&m,State&s,Frame&f,const Operations&op){
    s.ax=m.r32(f.sp+8u);f.push(m,s.si);s.si=s.cx;f.push(m,s.di);s.di=m.r32(f.sp+0xcu);s.cx=0;s.dx=0;
    m.w32(s.si+0x10u,s.ax);m.w32(s.si+4u,0);m.w32(s.si+8u,0);m.w8(s.si+0xcu,1);
    s.dx=s.di?1u:0u;
    const auto sub=s.si+0x14u;m.w32(sub+4u,0);m.w32(sub+8u,0);m.w32(sub+0xcu,0);m.w32(sub+0x18u,0);m.w32(sub+0x1cu,s.dx);m.w32(sub,0x791448u);
    m.w32(s.si+0x38u,0);m.w32(s.si+0x13cu,0);m.w32(s.si+0x140u,0);s.ax=sub;f.push(m,s.ax);s.cx=s.si;m.w32(s.si+0x34u,s.di);m.w32(s.si,0x793178u);call(m,s,f,op,m.r32(0x79317cu));
    s.ax=s.si;s.di=f.pop(m);s.si=f.pop(m);complete(m,s,f,8);
}
void fun_00607a80(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.si);s.si=s.cx;f.push(m,s.di);s.di=m.r32(f.sp+0xcu);
    if(m.r32(s.si+0x18u)!=s.di){
      if(s.di){s.cx=m.r32(s.di+8u);if(s.cx){s.ax=m.r32(s.cx);f.push(m,0);call(m,s,f,op,m.r32(s.ax+4u));m.w32(s.di+8u,0);}}
      s.ax=m.r32(s.si+0x18u);if(s.ax)m.w32(s.ax+8u,0);
      s.cx=s.si+0x14u;m.w32(s.si+0x18u,s.di);m.w32(s.si+0x1cu,s.si);m.w32(s.si+4u,s.cx);if(s.di)m.w32(s.di+8u,s.si);
    }
    s.di=f.pop(m);s.si=f.pop(m);complete(m,s,f,4);
}

void fun_0060b780(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.si);f.push(m,s.di);s.di=s.cx;s.cx=m.r32(s.di+0xcu);s.ax=m.r32(s.di+0x14u);s.si=s.di+4u;
    bool append=s32(s.ax)<s32(s.cx);
    if(!append){
        if(m.r8(s.si+0xdu)||!s.cx){s.ax=m.r32(s.si+0x14u);
            if(s32(s.ax)>0){s.dx=m.r32(s.si);s.ax+=s.cx;f.push(m,0);f.push(m,s.ax);s.cx=s.si;call(m,s,f,op,m.r32(s.dx+8u));append=(s.ax&0xffu)!=0;}
        }
    }
    if(append){s.ax=m.r32(s.si+0x10u);s.dx=m.r32(s.si+4u);s.cx=s.ax+1u;m.w32(s.si+0x10u,s.cx);s.cx=m.r32(f.sp+0xcu);m.w32(s.dx+s.ax*4u,s.cx);}
    if(m.r32(s.di+0x8cu)==0xffffffffu){s.dx=m.r32(s.di+0x14u)-1u;m.w32(s.di+0x8cu,s.dx);}
    s.di=f.pop(m);s.si=f.pop(m);complete(m,s,f,4);
}
void fun_0060c230(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.si);s.si=s.cx;if(!s.si)goto done;s.ax=with_al(s.ax,m.r8(s.si+0x1cu));if(s.ax&0xffu)goto done;m.w8(s.si+0x1cu,1);
    s.ax=m.r32(0xa5e2b8u);if(s32(m.r32(0xa5e2c0u))<s32(s.ax))goto add;
    if(m.r8(0xa5e2bdu)||!s.ax){s.cx=m.r32(0xa5e2c4u);if(s32(s.cx)>0){s.cx+=s.ax;s.ax=m.r32(0xa5e2b0u);f.push(m,0);f.push(m,s.cx);s.cx=0xa5e2b0u;call(m,s,f,op,m.r32(s.ax+8u));if(s.ax&0xffu)goto add;}}
    goto done;
add:s.cx=m.r32(0xa5e2c0u);s.ax=s.cx;m.w32(0xa5e2c0u,s.cx+1u);s.cx=m.r32(0xa5e2b4u);m.w32(s.cx+s.ax*4u,s.si);
done:s.si=f.pop(m);complete(m,s,f,0);
}
void fun_00610790(Memory&m,State&s,Frame&f,const Operations&op){
    f.push(m,s.cx);f.push(m,s.si);s.si=s.cx;s.ax=m.r32(s.si);call(m,s,f,op,m.r32(s.ax+0x16cu));
    bool ok=false;
    if(s.ax==0xbu){
        if(!s.si)ok=true;
        else {s.cx=(m.r8(s.si+0x14u)>>2)&1u;m.w8(f.sp+7u,std::uint8_t(s.cx));
            if(!s.cx)ok=true;
            else {s.ax=m.r32(s.si+0x494u);if(!s.ax){s.ax=m.r32(s.si+0x228u);ok=(s.ax==0);}}
        }
    }
    s.ax=with_al(s.ax,ok?1u:0u);s.si=f.pop(m);s.cx=f.pop(m);complete(m,s,f,0);
}

void remove_array(Memory&m,State&s,Frame&f,const Operations&op,std::uint32_t count_addr,
                  std::uint32_t data_addr,std::uint32_t method_offset,std::uint32_t retclean){
    f.push(m,s.si);s.si=s.cx;s.cx=m.r32(f.sp+8u);s.ax=m.r32(s.si);f.push(m,s.cx);s.cx=s.si;call(m,s,f,op,m.r32(s.ax+method_offset));
    if(s.ax!=0xffffffffu){s.cx=m.r32(s.si+0x10u);if(s32(s.ax)<s32(s.cx)){--s.cx;m.w32(s.si+0x10u,s.cx);
        if(s32(s.ax)<s32(s.cx)){do{s.cx=m.r32(s.si+4u);++s.ax;s.dx=m.r32(s.cx+s.ax*4u);m.w32(s.cx+s.ax*4u-4u,s.dx);s.cx=m.r32(s.si+0x10u);}while(s32(s.ax)<s32(s.cx));}
        s.ax=with_al(s.ax,1);s.si=f.pop(m);complete(m,s,f,retclean);return;
    }}
    s.ax=with_al(s.ax,0);s.si=f.pop(m);complete(m,s,f,retclean);
}
void fun_00612970(Memory&m,State&s,Frame&f,const Operations&op){remove_array(m,s,f,op,0,0,0x10u,4u);}
void fun_00612f70(Memory&m,State&s,Frame&f,const Operations&op){remove_array(m,s,f,op,0,0,0x10u,4u);}
void fun_006132a0(Memory&m,State&s,Frame&f,const Operations&op){remove_array(m,s,f,op,0,0,0x10u,4u);}

} // namespace

const std::array<Entry,54>& entries_b() {
    static const std::array<Entry,54> entries{{
        {0x124d60u,fun_00524d60},{0x124dd0u,fun_00524dd0},
        {0x1298f0u,fun_005298f0},{0x129990u,fun_00529990},
        {0x12d5c0u,fun_0052d5c0},{0x137140u,fun_00537140},
        {0x137280u,fun_00537280},{0x1392c0u,fun_005392c0},
        {0x13b620u,fun_0053b620},{0x13c2f0u,fun_0053c2f0},{0x13c550u,fun_0053c550},
        {0x145800u,fun_00545800},{0x1687a0u,fun_005687a0},{0x169b50u,fun_00569b50},
        {0x18e560u,fun_0058e560},{0x19a7f0u,fun_0059a7f0},{0x19d880u,fun_0059d880},
        {0x1a8b00u,fun_005a8b00},{0x1ac4d0u,fun_005ac4d0},{0x1b2b10u,fun_005b2b10},
        {0x1b2b70u,fun_005b2b70},{0x1b6410u,fun_005b6410},{0x1b6730u,fun_005b6730},
        {0x1c8c80u,fun_005c8c80},{0x1c8cc0u,fun_005c8cc0},{0x1ca5f0u,fun_005ca5f0},
        {0x1cd490u,fun_005cd490},{0x1cda70u,fun_005cda70},{0x1cdaa0u,fun_005cdaa0},
        {0x1cdb80u,fun_005cdb80},{0x1d5c10u,fun_005d5c10},{0x1d5c90u,fun_005d5c90},
        {0x1da550u,fun_005da550},{0x1dcae0u,fun_005dcae0},{0x1dcb50u,fun_005dcb50},
        {0x1de740u,fun_005de740},{0x1de7b0u,fun_005de7b0},{0x1de820u,fun_005de820},
        {0x1e2a30u,fun_005e2a30},{0x1e2b10u,fun_005e2b10},{0x1e2de0u,fun_005e2de0},
        {0x1f93c0u,fun_005f93c0},{0x1f9590u,fun_005f9590},{0x206640u,fun_00606640},
        {0x2066d0u,fun_006066d0},{0x2076d0u,fun_006076d0},{0x207a10u,fun_00607a10},
        {0x207a80u,fun_00607a80},{0x20b780u,fun_0060b780},{0x20c230u,fun_0060c230},
        {0x210790u,fun_00610790},{0x212970u,fun_00612970},{0x212f70u,fun_00612f70},
        {0x2132a0u,fun_006132a0}
    }};
    return entries;
}
} // namespace ra2::recovered::indirect_b31












