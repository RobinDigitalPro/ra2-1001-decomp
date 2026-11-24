// PRIVATE Source (batch unallocated): 0x363380 root and its authentic callback 0x7122A0 (domain A: message 3, [owner+0x508]==-1). Emitted by emit_363380.py from the pinned listings.
// The callback is a lifted GUEST body reached through the pointer field [this+0x48]; the 24-byte inline jump table (0x71232C) is a separate constant of authenticated targets.
#include "recovered/numeric_b105_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <stdexcept>
namespace ra2::recovered::numeric_b105 {
void cb_7122a0(Memory&,State&,Frame&,const Operations&);
volatile std::uint32_t g_last_ucall=0,g_ucall_count=0,g_pc=0;   // driver diagnostics (same names as the 3013C0 unit)
static void guest_call(Memory& m,State& s,Frame& f,std::uint32_t target,std::uint32_t continuation){
  g_last_ucall=target;++g_ucall_count;f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
  if(target==0x007122a0u)cb_7122a0(m,s,child,Operations{});else throw std::domain_error("363380 callback target outside domain A");
  f.sp=child.sp;
}
void cb_7122a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L7122a0: { // 7122a0: mov eax, dword ptr [esp + 4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L7122a4: { // 7122a4: mov ecx, dword ptr [esp + 8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L7122a8: { // 7122a8: push ebx
    f.push(m,s.bx);
  }
  L7122a9: { // 7122a9: mov ebx, dword ptr [eax + 0xac]
    s.bx = m.r32((s.ax+0x000000acu));
  }
  L7122af: { // 7122af: lea eax, [ecx - 2]
    s.ax = (s.cx+0xfffffffeu);
  }
  L7122b2: { // 7122b2: cmp eax, 5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L7122b5: { // 7122b5: ja 0x712327
    if(integer::condition("JA",flags)) goto L712327;
  }
  L7122b7: { // 7122b7: jmp dword ptr [eax*4 + 0x71232c]
    { static const std::uint32_t tab[6]={0x007122beu,0x007122f1u,0x00712327u,0x00712327u,0x00712319u,0x00712321u}; const std::uint32_t t=tab[s.ax]; switch(t){case 0x007122beu: goto L7122be; case 0x007122f1u: goto L7122f1; case 0x00712319u: goto L712319; case 0x00712321u: goto L712321; case 0x00712327u: goto L712327; default: throw std::domain_error("363380 table target"); } }
  }
  L7122be: { throw std::domain_error("363380 domain A guard: callback msg 2 unclaimed"); }
  L7122f1: { // 7122f1: cmp dword ptr [ebx + 0x508], -1
    (void)integer::sub(m.r32((s.bx+0x00000508u)),0xffffffffu,32,flags);
  }
  L7122f8: { // 7122f8: je 0x712309
    if(integer::condition("JZ",flags)) goto L712309;
  }
  L7122fa: { throw std::domain_error("363380 domain A guard: msg 3 with [owner+0x508]!=-1 (0x7003B0 path) unclaimed"); }
  L712309: { // 712309: mov edx, dword ptr [ebx + 0x4fc]
    s.dx = m.r32((s.bx+0x000004fcu));
  }
  L71230f: { // 71230f: xor eax, eax
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L712311: { // 712311: mov dword ptr [ebx + 0x544], edx
    m.w32((s.bx+0x00000544u),s.dx);
  }
  L712317: { // 712317: pop ebx
    s.bx = f.pop(m);
  }
  L712318: { // 712318: ret 
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L712319: { throw std::domain_error("363380 domain A guard: callback msg 6 unclaimed"); }
  L712321: { throw std::domain_error("363380 domain A guard: callback msg 7 unclaimed"); }
  L712327: { // 712327: xor eax, eax
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L712329: { // 712329: pop ebx
    s.bx = f.pop(m);
  }
  L71232a: { // 71232a: ret 
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void root_363380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L763380: { // 763380: sub esp, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L763383: { // 763383: push ebx
    f.push(m,s.bx);
  }
  L763384: { // 763384: push ebp
    f.push(m,s.bp);
  }
  L763385: { // 763385: push esi
    f.push(m,s.si);
  }
  L763386: { // 763386: mov esi, ecx
    s.si = s.cx;
  }
  L763388: { // 763388: xor ebp, ebp
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L76338a: { // 76338a: push edi
    f.push(m,s.di);
  }
  L76338b: { // 76338b: mov eax, dword ptr [esi + 0x724]
    s.ax = m.r32((s.si+0x00000724u));
  }
  L763391: { // 763391: mov dword ptr [esp + 0x1c], edx
    m.w32((f.sp+0x0000001cu),s.dx);
  }
  L763395: { // 763395: cmp eax, ebp
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L763397: { // 763397: jbe 0x763409
    if(integer::condition("JBE",flags)) goto L763409;
  }
  L763399: { // 763399: mov dword ptr [esp + 0x10], ebp
    m.w32((f.sp+0x00000010u),s.bp);
  }
  L76339d: { // 76339d: mov dword ptr [esp + 0x18], eax
    m.w32((f.sp+0x00000018u),s.ax);
  }
  L7633a1: { // 7633a1: mov eax, dword ptr [esi + 0x734]
    s.ax = m.r32((s.si+0x00000734u));
  }
  L7633a7: { // 7633a7: mov ecx, dword ptr [esi + 0x738]
    s.cx = m.r32((s.si+0x00000738u));
  }
  L7633ad: { // 7633ad: mov edx, dword ptr [esp + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L7633b1: { // 7633b1: mov ebx, dword ptr [eax + ebp]
    s.bx = m.r32((s.ax+s.bp));
  }
  L7633b4: { // 7633b4: lea eax, [edx + ecx]
    s.ax = (s.dx+s.cx);
  }
  L7633b7: { // 7633b7: mov ecx, dword ptr [edx + ecx + 8]
    s.cx = m.r32((s.dx+s.cx+0x00000008u));
  }
  L7633bb: { // 7633bb: mov eax, dword ptr [eax]
    s.ax = m.r32((s.ax));
  }
  L7633bd: { // 7633bd: test eax, eax
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L7633bf: { // 7633bf: jbe 0x7633f0
    if(integer::condition("JBE",flags)) goto L7633f0;
  }
  L7633c1: { // 7633c1: lea edi, [ecx + 4]
    s.di = (s.cx+0x00000004u);
  }
  L7633c4: { // 7633c4: mov dword ptr [esp + 0x14], eax
    m.w32((f.sp+0x00000014u),s.ax);
  }
  L7633c8: { // 7633c8: mov eax, dword ptr [esp + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L7633cc: { // 7633cc: mov ecx, dword ptr [edi + 4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L7633cf: { // 7633cf: cmp ecx, eax
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L7633d1: { // 7633d1: jne 0x7633e2
    if(integer::condition("JNZ",flags)) goto L7633e2;
  }
  L7633d3: { // 7633d3: mov ecx, dword ptr [edi]
    s.cx = m.r32((s.di));
  }
  L7633d5: { // 7633d5: mov edx, dword ptr [edi - 4]
    s.dx = m.r32((s.di+0xfffffffcu));
  }
  L7633d8: { // 7633d8: push ecx
    f.push(m,s.cx);
  }
  L7633d9: { // 7633d9: push edx
    f.push(m,s.dx);
  }
  L7633da: { // 7633da: push ebx
    f.push(m,s.bx);
  }
  L7633db: { // 7633db: push esi
    f.push(m,s.si);
  }
  L7633dc: { // 7633dc: call dword ptr [esi + 0x48]
    { const std::uint32_t t=m.r32((s.si+0x00000048u)); s.arithmetic_flags=flags; guest_call(m,s,f,t,0x007633dfu); flags=s.arithmetic_flags; }
  }
  L7633df: { // 7633df: add esp, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L7633e2: { // 7633e2: mov eax, dword ptr [esp + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L7633e6: { // 7633e6: add edi, 0xc
    s.di = integer::add(s.di,0x0000000cu,32,flags);
  }
  L7633e9: { // 7633e9: dec eax
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L7633ea: { // 7633ea: mov dword ptr [esp + 0x14], eax
    m.w32((f.sp+0x00000014u),s.ax);
  }
  L7633ee: { // 7633ee: jne 0x7633c8
    if(integer::condition("JNZ",flags)) goto L7633c8;
  }
  L7633f0: { // 7633f0: mov ecx, dword ptr [esp + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L7633f4: { // 7633f4: mov eax, dword ptr [esp + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L7633f8: { // 7633f8: add ebp, 0x10
    s.bp = integer::add(s.bp,0x00000010u,32,flags);
  }
  L7633fb: { // 7633fb: add ecx, 0xc
    s.cx = integer::add(s.cx,0x0000000cu,32,flags);
  }
  L7633fe: { // 7633fe: dec eax
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L7633ff: { // 7633ff: mov dword ptr [esp + 0x10], ecx
    m.w32((f.sp+0x00000010u),s.cx);
  }
  L763403: { // 763403: mov dword ptr [esp + 0x18], eax
    m.w32((f.sp+0x00000018u),s.ax);
  }
  L763407: { // 763407: jne 0x7633a1
    if(integer::condition("JNZ",flags)) goto L7633a1;
  }
  L763409: { // 763409: mov eax, dword ptr [esi + 0x73c]
    s.ax = m.r32((s.si+0x0000073cu));
  }
  L76340f: { // 76340f: xor ebp, ebp
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L763411: { // 763411: cmp eax, ebp
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L763413: { // 763413: jbe 0x763485
    if(integer::condition("JBE",flags)) goto L763485;
  }
  L763415: { // 763415: mov dword ptr [esp + 0x10], ebp
    m.w32((f.sp+0x00000010u),s.bp);
  }
  L763419: { // 763419: mov dword ptr [esp + 0x14], eax
    m.w32((f.sp+0x00000014u),s.ax);
  }
  L76341d: { // 76341d: mov eax, dword ptr [esi + 0x744]
    s.ax = m.r32((s.si+0x00000744u));
  }
  L763423: { // 763423: mov ecx, dword ptr [esi + 0x748]
    s.cx = m.r32((s.si+0x00000748u));
  }
  L763429: { // 763429: mov edx, dword ptr [esp + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L76342d: { // 76342d: mov ebx, dword ptr [eax + ebp]
    s.bx = m.r32((s.ax+s.bp));
  }
  L763430: { // 763430: lea eax, [ecx + edx]
    s.ax = (s.cx+s.dx);
  }
  L763433: { // 763433: mov ecx, dword ptr [ecx + edx + 8]
    s.cx = m.r32((s.cx+s.dx+0x00000008u));
  }
  L763437: { // 763437: mov eax, dword ptr [eax]
    s.ax = m.r32((s.ax));
  }
  L763439: { // 763439: test eax, eax
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L76343b: { // 76343b: jbe 0x76346c
    if(integer::condition("JBE",flags)) goto L76346c;
  }
  L76343d: { // 76343d: lea edi, [ecx + 4]
    s.di = (s.cx+0x00000004u);
  }
  L763440: { // 763440: mov dword ptr [esp + 0x18], eax
    m.w32((f.sp+0x00000018u),s.ax);
  }
  L763444: { // 763444: mov eax, dword ptr [esp + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L763448: { // 763448: mov ecx, dword ptr [edi + 4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L76344b: { // 76344b: cmp ecx, eax
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L76344d: { // 76344d: jne 0x76345e
    if(integer::condition("JNZ",flags)) goto L76345e;
  }
  L76344f: { // 76344f: mov ecx, dword ptr [edi]
    s.cx = m.r32((s.di));
  }
  L763451: { // 763451: mov edx, dword ptr [edi - 4]
    s.dx = m.r32((s.di+0xfffffffcu));
  }
  L763454: { // 763454: push ecx
    f.push(m,s.cx);
  }
  L763455: { // 763455: push edx
    f.push(m,s.dx);
  }
  L763456: { // 763456: push ebx
    f.push(m,s.bx);
  }
  L763457: { // 763457: push esi
    f.push(m,s.si);
  }
  L763458: { // 763458: call dword ptr [esi + 0x48]
    { const std::uint32_t t=m.r32((s.si+0x00000048u)); s.arithmetic_flags=flags; guest_call(m,s,f,t,0x0076345bu); flags=s.arithmetic_flags; }
  }
  L76345b: { // 76345b: add esp, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L76345e: { // 76345e: mov eax, dword ptr [esp + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L763462: { // 763462: add edi, 0xc
    s.di = integer::add(s.di,0x0000000cu,32,flags);
  }
  L763465: { // 763465: dec eax
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L763466: { // 763466: mov dword ptr [esp + 0x18], eax
    m.w32((f.sp+0x00000018u),s.ax);
  }
  L76346a: { // 76346a: jne 0x763444
    if(integer::condition("JNZ",flags)) goto L763444;
  }
  L76346c: { // 76346c: mov ecx, dword ptr [esp + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L763470: { // 763470: mov eax, dword ptr [esp + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L763474: { // 763474: add ebp, 0x10
    s.bp = integer::add(s.bp,0x00000010u,32,flags);
  }
  L763477: { // 763477: add ecx, 0xc
    s.cx = integer::add(s.cx,0x0000000cu,32,flags);
  }
  L76347a: { // 76347a: dec eax
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L76347b: { // 76347b: mov dword ptr [esp + 0x10], ecx
    m.w32((f.sp+0x00000010u),s.cx);
  }
  L76347f: { // 76347f: mov dword ptr [esp + 0x14], eax
    m.w32((f.sp+0x00000014u),s.ax);
  }
  L763483: { // 763483: jne 0x76341d
    if(integer::condition("JNZ",flags)) goto L76341d;
  }
  L763485: { // 763485: pop edi
    s.di = f.pop(m);
  }
  L763486: { // 763486: pop esi
    s.si = f.pop(m);
  }
  L763487: { // 763487: pop ebp
    s.bp = f.pop(m);
  }
  L763488: { // 763488: pop ebx
    s.bx = f.pop(m);
  }
  L763489: { // 763489: add esp, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L76348c: { // 76348c: ret 
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void root363380_a(Memory& m,State& s,Frame& f){root_363380(m,s,f,Operations{});}
}
