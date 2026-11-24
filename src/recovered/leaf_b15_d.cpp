// Block15 parent group: exact observed guest32 operations; names retain original VA.
#include "leaf_b15_d.hpp"
namespace ra2::recovered::leaf {
// RVA 0x2a7940: cx+74 readable; arg0 null or writable through +554f; AL is 1 on both paths; EAX upper bits are arg0-derived. Receiver/output alias allowed.
std::uint32_t fun_006a7940(Memory& m,const Inputs& i) { const auto a=i.arg[0]; if(a)m.w32(a+0x554c,m.r32(i.cx+0x74)); return 1; }
// RVA 0x2a93d0: cx+30 readable, arg0 writable dword. Load precedes output store; EAX output pointer.
std::uint32_t fun_006a93d0(Memory& m,const Inputs& i) { const auto v=m.r32(i.cx+0x30); m.w32(i.arg[0],v); return i.arg[0]; }
// RVA 0x2a9420: Finite null-terminated chain from cx+28 via node+28; arg0 is an opaque comparison value; AL Boolean.
std::uint32_t fun_006a9420(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0x28);p;p=m.r32(p+0x28)) if(p==i.arg[0])return 1; return 0; }
// RVA 0x2a9840: Finite chain via +28; every node+24 is a valid object readable at +a0. AL Boolean.
std::uint32_t fun_006a9840(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0x28);p;p=m.r32(p+0x28)) if(m.r8(m.r32(p+0x24)+0xa0))return 1; return 0; }
// RVA 0x2ac180: Signed nonpositive count yields zero; positive count finite and stride8 dwords readable. Modulo32 sum.
std::uint32_t fun_006ac180(Memory& m,const Inputs& i) { auto count=m.r32(i.cx+0x9c),a=i.cx+0xa4,sum=0u; if(s32(count)>0) do {sum+=m.r32(a);a+=8;}while(--count); return sum; }
// RVA 0x2b0050: Finite null-terminated chain via +4c8; tests each byte+32d, including empty chain true. AL only.
std::uint32_t fun_006b0050(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0x54);p;p=m.r32(p+0x4c8)) if(!m.r8(p+0x32d))return 0; return 1; }
// RVA 0x2b2fe0: Finite chain at +54/+4c8; writable node+d8, next pointer read after store. EAX ends null.
std::uint32_t fun_006b2fe0(Memory& m,const Inputs& i) { auto p=m.r32(i.cx+0x54);const auto value=i.arg[0];while(p){m.w32(p+0xd8,value);p=m.r32(p+0x4c8);}return 0; }
// RVA 0x2b50b0: cx+9c/dc readable; nonnull fallback object+98 readable only when first value -1; -2 unchanged.
std::uint32_t fun_006b50b0(Memory& m,const Inputs& i) { auto a=m.r32(i.cx+0x9c); if(a==0xffffffffu){const auto p=m.r32(i.cx+0xdc);if(p)a=m.r32(p+0x98);}return a; }
// RVA 0x2cc350: Readable cx+32a byte; Boolean AL.
std::uint32_t fun_006cc350(Memory& m,const Inputs& i) { return m.r8(i.cx+0x32a)!=0; }
// RVA 0x2cd9d0: Readable cx+100 dword; full EAX Boolean.
std::uint32_t fun_006cd9d0(Memory& m,const Inputs& i) { return m.r32(i.cx+0x100)!=0xffffffffu; }
// RVA 0x2cdbb0: arg0 null or readable dword. Short circuit nonnull-value predicate.
std::uint32_t fun_006cdbb0(Memory& m,const Inputs& i) { return i.arg[0] && m.r32(i.arg[0])!=0; }
// RVA 0x2ce3f0: Readable receiver dword+3fc; signed positive test, full EAX Boolean.
std::uint32_t fun_006ce3f0(Memory& m,const Inputs& i) { return s32(m.r32(i.cx+0x3fc))>0; }
// RVA 0x2d0230: Readable receiver+74c dword and +5e4 byte; +74c value is tested, never dereferenced. AL Boolean.
std::uint32_t fun_006d0230(Memory& m,const Inputs& i) { return m.r32(i.cx+0x74c)!=0 && m.r8(i.cx+0x5e4)==0; }
// RVA 0x2d0490: Receiver+74c/+768 null or objects readable at +9c when reached. Same nonnull pointer succeeds without object read. AL Boolean.
std::uint32_t fun_006d0490(Memory& m,const Inputs& i) { const auto a=m.r32(i.cx+0x74c);if(!a)return 0;const auto b=m.r32(i.cx+0x768);if(a==b)return 1;if(s32(m.r32(a+0x9c))>1)return 1;return b && s32(m.r32(b+0x9c))>1; }
// RVA 0x2d4b30: Pure modulo32 address arithmetic cx+28*arg0+74c; no memory access or claim that returned address is mapped.
std::uint32_t fun_006d4b30(Memory& m,const Inputs& i) { return i.cx+28u*i.arg[0]+0x74c; }
// RVA 0x2d4bf0: Readable receiver dword+704; signed positive test, full EAX Boolean.
std::uint32_t fun_006d4bf0(Memory& m,const Inputs& i) { return s32(m.r32(i.cx+0x704))>0; }
// RVA 0x2dcf00: Count+24, pointer+18; valid reached index*4 dword, unsigned bounds. Fallback 0x7e1bb8 is opaque numeric output, never dereferenced. Add 0 modulo32.
std::uint32_t fun_006dcf00(Memory& m,const Inputs& i) { const auto index=i.arg[0],count=m.r32(i.cx+0x24);if(index<count)return m.r32(m.r32(i.cx+0x18)+index*4)+0x0;return 0x7e1bb8; }
// RVA 0x2dcf20: Writable receiver through +2f; only explicit fields written, padding preserved; encoded address tag 7986bc remains opaque. Returns receiver.
std::uint32_t fun_006dcf20(Memory& m,const Inputs& i) { const auto c=i.cx;for(auto o:{0u,4u,8u})m.w32(c+o,0xffffffff);m.w32(c+0xc,255);m.w8(c+0x10,0);m.w8(c+0x11,0);m.w8(c+0x12,0);m.w32(c+0x18,0);m.w32(c+0x1c,0);m.w8(c+0x20,1);m.w8(c+0x21,0);m.w32(c+0x14,0x7986bc);m.w32(c+0x28,10);m.w32(c+0x24,0);m.w32(c+0x2c,0);return c; }
// RVA 0x2dcf70: Count+24, pointer+18; valid reached index*4 dword, unsigned bounds. Fallback 0x0 is opaque numeric output, never dereferenced. Add 512 modulo32.
std::uint32_t fun_006dcf70(Memory& m,const Inputs& i) { const auto index=i.arg[0],count=m.r32(i.cx+0x24);if(index<count)return m.r32(m.r32(i.cx+0x18)+index*4)+0x200;return 0x0; }
// RVA 0x2dd830: Count+24, pointer+18; valid reached index*4 dword, signed nonnegative bounds. Fallback 0x7b907c is opaque numeric output, never dereferenced. Add 0 modulo32.
std::uint32_t fun_006dd830(Memory& m,const Inputs& i) { const auto index=i.arg[0],count=m.r32(i.cx+0x24);if(s32(index)>=0 && s32(index)<s32(count))return m.r32(m.r32(i.cx+0x18)+index*4)+0x0;return 0x7b907c; }
// RVA 0x2e1050: Writable five receiver dwords; arg0 unused despite RET4; no ownership/free behavior inferred.
std::uint32_t fun_006e1050(Memory& m,const Inputs& i) { for(auto o:{0x18u,0x1cu,0x20u,0x24u,4u})m.w32(i.cx+o,0);return 0; }
// RVA 0x2e1540: cx+10 null or readable dword pointer; arg0 readable if first pointer nonnull; AL comparison result.
std::uint32_t fun_006e1540(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+0x10);return p && m.r32(p)==m.r32(i.arg[0]); }
// RVA 0x2e3440: Finite null chain from receiver+ac via node+28; node+2c tag compared to 26; semantic enum identity unknown. AL result.
std::uint32_t fun_006e3440(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0xac);p;p=m.r32(p+0x28))if(m.r32(p+0x2c)==0x1a)return 1;return 0; }
// RVA 0x2e3470: Finite null chain from receiver+ac via node+28; node+2c tag compared to 25; semantic enum identity unknown. AL result.
std::uint32_t fun_006e3470(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0xac);p;p=m.r32(p+0x28))if(m.r32(p+0x2c)==0x19)return 1;return 0; }
// RVA 0x2e34a0: Finite null chain from receiver+ac via node+28; node+2c tag compared to 24; semantic enum identity unknown. AL result.
std::uint32_t fun_006e34a0(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0xac);p;p=m.r32(p+0x28))if(m.r32(p+0x2c)==0x18)return 1;return 0; }
// RVA 0x2e34d0: Finite null chain from receiver+b0 via node+28; node+2c tag compared to 15; semantic enum identity unknown. AL result.
std::uint32_t fun_006e34d0(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0xb0);p;p=m.r32(p+0x28))if(m.r32(p+0x2c)==0xf)return 1;return 0; }
// RVA 0x2e3500: Finite chain at +ac/+28; tag+2c matches 27 or 28, then payload+34 equals arg0. Short-circuit reads retained; AL only.
std::uint32_t fun_006e3500(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0xac);p;p=m.r32(p+0x28)){auto t=m.r32(p+0x2c);if((t==0x1b||t==0x1c)&&m.r32(p+0x34)==i.arg[0])return 1;}return 0; }
// RVA 0x2e3540: Finite chain at +ac/+28; tag+2c matches 36 or 37, then payload+34 equals arg0. Short-circuit reads retained; AL only.
std::uint32_t fun_006e3540(Memory& m,const Inputs& i) { for(auto p=m.r32(i.cx+0xac);p;p=m.r32(p+0x28)){auto t=m.r32(p+0x2c);if((t==0x24||t==0x25)&&m.r32(p+0x34)==i.arg[0])return 1;}return 0; }
// RVA 0x2ee9f0: Writable ordered inclusive byte span cx..dx, or cx>=dx no-op; first endpoint pair alone can change ASCII case before reversal. Signed byte comparisons. No EAX claim: no-op path leaves incoming EAX undefined to this adapter.
std::uint32_t fun_006ee9f0(Memory& m,const Inputs& i) { auto l=i.cx,r=i.dx;bool first=true;while(l<r){auto a=m.r8(l),b=m.r8(r);if(first){if(s32(sx8(a))>=65&&s32(sx8(a))<=90&&s32(sx8(b))>=97&&s32(sx8(b))<=122){a=(a+32)&255;b=(b+224)&255;}first=false;}m.w8(r,a);--r;m.w8(l,b);++l;}return 0; }
// RVA 0x301090: Writable receiver through +803; exactly512 initial dwords cleared, counter then set from arg0. Return arg0.
std::uint32_t fun_00701090(Memory& m,const Inputs& i) { m.w32(i.cx+0x800,512);auto n=0u,a=i.cx;do{m.w32(a,0);const auto bound=m.r32(i.cx+0x800);++n;a+=4;if(s32(n)>=s32(bound))break;}while(true);m.w32(i.cx+0x800,i.arg[0]);return i.arg[0]; }
// RVA 0x3010d0: Signed nonpositive count returns0; positive count at+800 bounds readable dword sequence. Tests count<=10, wider valid readable spans follow same loop; modulo32 sum.
std::uint32_t fun_007010d0(Memory& m,const Inputs& i) { auto n=m.r32(i.cx+0x800),p=i.cx,sum=0u;if(s32(n)>0)do{sum+=m.r32(p);p+=4;}while(--n);return sum; }
// RVA 0x301100: Signed counter+800 <=512 in accepted domain or nonpositive; clear that many receiver words, reload limit after each store, return iterations. No count/header overlap tested beyond512.
std::uint32_t fun_00701100(Memory& m,const Inputs& i) { auto n=0u,p=i.cx;if(s32(m.r32(i.cx+0x800))>0)do{m.w32(p,0);const auto limit=m.r32(i.cx+0x800);++n;p+=4;if(s32(n)>=s32(limit))break;}while(true);return n; }
// RVA 0x3075d0: Signed last-index field0; negative skips, otherwise clears indices0 through current last-index inclusive. Pointer+8 and limit reloaded per iteration, finite backing array disjoint from header in tests; header0 cleared on every exit.
std::uint32_t fun_007075d0(Memory& m,const Inputs& i) { auto n=0u;if(s32(m.r32(i.cx))>=0)do{const auto p=m.r32(i.cx+8);++n;m.w32(p+n*4-4,0);if(s32(n)>s32(m.r32(i.cx)))break;}while(true);m.w32(i.cx,0);return n; }
// RVA 0x3076e0: Receiver readable/writable through+47; masks only low flags nibble; other explicit fields reset. Tag78dabc opaque; padding preserved.
std::uint32_t fun_007076e0(Memory& m,const Inputs& i) { const auto c=i.cx;const auto flags=m.r32(c+0x44)&0xfffffff0u;m.w32(c+4,0);m.w16(c+8,0);m.w16(c+0xa,0);m.w32(c+0x3c,0);m.w32(c+0x40,0);m.w32(c+0x44,flags);m.w32(c,0x78dabc);m.w8(c+0x2a,0);m.w8(c+0xc,0);return c; }
// RVA 0x307d30: Unsigned endpoint comparisons against receiver+3c/+40; preserves original behavior even for inverted intervals. Returns -1,0,or new upper field; not generalized interval validity.
std::uint32_t fun_00707d30(Memory& m,const Inputs& i) { const auto lo=i.arg[0],hi=i.arg[1],oldhi=m.r32(i.cx+0x40);if(lo>oldhi)return 0xffffffffu;const auto oldlo=m.r32(i.cx+0x3c);if(hi<oldlo)return 0;if(lo>oldlo)m.w32(i.cx+0x3c,lo);if(hi<oldhi)m.w32(i.cx+0x40,hi);return m.r32(i.cx+0x40); }
// RVA 0x3080e0: Writable8bytes at cx; arg0 low byte selects high word0x3ff00000 or0, lowword0. Stored bits may represent double; no floatingpoint computation claimed. AL retains inputbyte.
std::uint32_t fun_007080e0(Memory& m,const Inputs& i) { m.w32(i.cx,0);m.w32(i.cx+4,(i.arg[0]&255)?0x3ff00000:0);return i.arg[0]&255; }
// RVA 0x308110: Writable8bytes at cx; arg0 low byte selects high word0x40000000 or0, lowword0. Stored bits may represent double; no floatingpoint computation claimed. AL retains inputbyte.
std::uint32_t fun_00708110(Memory& m,const Inputs& i) { m.w32(i.cx,0);m.w32(i.cx+4,(i.arg[0]&255)?0x40000000:0);return i.arg[0]&255; }
// RVA 0x30e420: Receiver+10 points to readable stride12 array; receiver+14 opaque base; arg0 valid index; output modulo32 base+(arrayword+arg1)*164, no output dereference.
std::uint32_t fun_0070e420(Memory& m,const Inputs& i) { const auto a=m.r32(i.cx+0x10),b=m.r32(i.cx+0x14);return b+(m.r32(a+i.arg[0]*12)+i.arg[1])*164; }
// RVA 0x311780: Readable/writable field+1d4; arg0 -1 queries without write; all paths return previous value.
std::uint32_t fun_00711780(Memory& m,const Inputs& i) { const auto old=m.r32(i.cx+0x1d4);if(i.arg[0]!=0xffffffffu)m.w32(i.cx+0x1d4,i.arg[0]);return old; }
// RVA 0x31b670: Receiver+4 valid object readable at+10, receiver+8 unsigned index; unsigned less-than count Boolean.
std::uint32_t fun_0071b670(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+4),index=m.r32(i.cx+8);return index<m.r32(p+0x10); }
// RVA 0x31bfb0: Receiver+c null or object readable dword+8; null fallback0; raw field return.
std::uint32_t fun_0071bfb0(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+0xc);return p?m.r32(p+0x8):0; }
// RVA 0x31f330: arg0 two readable coordinate dwords; receiver+54/+58 origins +5c/+60 extents; signed comparisons after modulo32 endpoint additions, half-open bounds; no positivity assumption.
std::uint32_t fun_0071f330(Memory& m,const Inputs& i) { const auto p=i.arg[0],x=m.r32(p),left=m.r32(i.cx+0x54);if(s32(x)<s32(left)||s32(x)>=s32(left+m.r32(i.cx+0x5c)))return 0;const auto y=m.r32(p+4),top=m.r32(i.cx+0x58);return s32(y)>=s32(top)&&s32(y)<s32(top+m.r32(i.cx+0x60)); }
// RVA 0x321e50: Receiver+c null or object readable dword+18; null fallback0; raw field return.
std::uint32_t fun_00721e50(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+0xc);return p?m.r32(p+0x18):0; }
// RVA 0x321e70: Receiver+c null or object readable byte+14; null fallback1; zero-extended byte.
std::uint32_t fun_00721e70(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+0xc);return p?m.r8(p+0x14):1; }
// RVA 0x321e90: Receiver+c null or object readable dword+24; null fallback0; subtract1 modulo32.
std::uint32_t fun_00721e90(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+0xc);return p?m.r32(p+0x24)-1u:0; }
// RVA 0x324f00: Writable12bytes at cx; two inputwords and opaque tag79a20c stored; returns receiver, no original class/ownership claim.
std::uint32_t fun_00724f00(Memory& m,const Inputs& i) { m.w32(i.cx+4,i.arg[0]);m.w32(i.cx+8,i.arg[1]);m.w32(i.cx,0x79a20c);return i.cx; }
// RVA 0x324f20: Receiver+4 valid object readable at+10, receiver+8 unsigned index; unsigned less-than count Boolean.
std::uint32_t fun_00724f20(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+4),index=m.r32(i.cx+8);return index<m.r32(p+0x10); }
// RVA 0x328620: Receiver+a0 valid object readable bytes+274/+275. Full EAX mask assembled from two nonzero predicates.
std::uint32_t fun_00728620(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+0xa0);auto v=m.r8(p+0x274)?4u:0u;if(m.r8(p+0x275))v|=0xb8;return v; }
// RVA 0x328650: Receiver+ac null or object byte+144 readable; AL Boolean.
std::uint32_t fun_00728650(Memory& m,const Inputs& i) { const auto p=m.r32(i.cx+0xac);return p && m.r8(p+0x144)!=0; }
// RVA 0x32e570: Receiver+1c dword and +8 byte; change sets dirty byte1, equal input preserves byte; EAX inputword.
std::uint32_t fun_0072e570(Memory& m,const Inputs& i) { const auto a=i.arg[0];if(a!=m.r32(i.cx+0x1c)){m.w32(i.cx+0x1c,a);m.w8(i.cx+8,1);}return a; }
}
