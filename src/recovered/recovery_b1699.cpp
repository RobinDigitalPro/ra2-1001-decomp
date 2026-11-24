#include "recovery_b1699.hpp"
#include <cstdint>
#include <stdexcept>


namespace ra2::recovered::b1699::helpers {
namespace {
constexpr U self=0x18001000u,buffer=0x18002000u,capacity=0x400u;
constexpr U table=0x78773cu,table_extent=0x18u;
void need(bool v,const char*why){if(!v)throw std::domain_error(why);}
void mapped(const Memory&m,U start,U size){
 need(size&&std::uint64_t(start)+size<=0x100000000ULL,"2F290 mapped span wraps");
 // Adapter coverage probes only. Values are discarded; these are not writes,
 // expected private bytes, physical ownership observations or RW proofs.
 for(U k=0;k<size;++k)(void)m.r8(start+k);
}
void separate(U a,U an,U b,U bn){
 need(std::uint64_t(a)+an<=b||std::uint64_t(b)+bn<=a,"2F290 finite ranges alias");
}
}

void require_selected_basis(const Memory&m,const State&s,const Frame&f){
 // Runs before the Source Root's first PUSH/store. No state is initialized here.
 need(s.cx==self,"2F290 finite compatible Self address");
 need(f.sp==f.entry_sp,"2F290 actual initial caller Frame");
 need(f.entry_sp>=0x28u&&std::uint64_t(f.entry_sp)+68<=0x100000000ULL,
      "2F290 complete nested frame and caller16 extent");
 const U stack=f.entry_sp-0x28u;
 constexpr U stack_size=0x28u+68u;
 separate(self,0x50u,buffer,capacity);
 separate(self,0x50u,table,table_extent);
 separate(buffer,capacity,table,table_extent);
 separate(stack,stack_size,self,0x50u);
 separate(stack,stack_size,buffer,capacity);
 separate(stack,stack_size,table,table_extent);
 mapped(m,self,0x50u);mapped(m,buffer,capacity);
 mapped(m,table,table_extent);mapped(m,stack,stack_size);
 need(m.r32(f.entry_sp)==f.outer_return,"2F290 real outer return word");
 need(m.r32(f.entry_sp+4)==capacity&&m.r32(f.entry_sp+8)==buffer,
      "2F290 exact declared N400 and nonnull owned-buffer input");
 need(m.r32(self)==table&&m.r32(table+0x14u)==0x42f5e0u,
      "2F290 authentic declared primary and actual slot14 target");
 need(m.r32(self+0x14u)==0&&m.r8(self+0x25u)==0&&m.r32(self+0x2cu)==0,
      "2F290 genuine wrapper/zero-field prefix and initial buffer branch");
 need(!(s.arithmetic_flags&0x400u),"2F290 finite physical DF0 domain");
 // Caller words2..15 and all other Self/buffer/private bytes stay opaque.
 // Self44 need not be forced: the selected Root itself stores zero before use.
}
} // namespace ra2::recovered::b1699::helpers

namespace ra2::recovered::b1699 {
namespace ix=direct_b33::integer;
void execute_selected(Memory& m,State& s,Frame& f){
helpers::require_selected_basis(m,s,f);
L42f290: // PUSH EBX [53]
f.push(m,s.bx);
L42f291: // PUSH EBP [55]
f.push(m,s.bp);
L42f292: // PUSH ESI [56]
f.push(m,s.si);
L42f293: // MOV ESI,ECX [8bf1]
s.si = s.cx;
L42f295: // XOR EBX,EBX [33db]
s.bx = ix::logical(s.bx ^ s.bx,32,s.arithmetic_flags);
L42f297: // PUSH EDI [57]
f.push(m,s.di);
L42f298: // CMP dword ptr [ESI + 0x2c],EBX [395e2c]
(void)ix::sub(m.r32(s.si + 0x2c),s.bx,32,s.arithmetic_flags);
L42f29b: // JZ 0x0042f2ba [741d]
if(ix::condition("JZ",s.arithmetic_flags)) goto L42f2ba; throw std::domain_error("2F290 finite PC escape at 42f29b");
L42f2ba: // MOV EAX,dword ptr [ESI] [8b06]
s.ax = m.r32(s.si);
L42f2bc: // PUSH EBX [53]
f.push(m,s.bx);
L42f2bd: // MOV ECX,ESI [8bce]
s.cx = s.si;
L42f2bf: // CALL dword ptr [EAX + 0x14] [ff5014]
helpers::actual_slot14(m,s,f,0x42f2c2u,m.r32(s.ax+0x14u));
L42f2c2: // TEST AL,AL [84c0]
(void)ix::logical((s.ax&255u) & (s.ax&255u),8,s.arithmetic_flags);
L42f2c4: // JZ 0x0042f2d2 [740c]
if(ix::condition("JZ",s.arithmetic_flags)) goto L42f2d2; throw std::domain_error("2F290 finite PC escape at 42f2c4");
L42f2d2: // MOV dword ptr [ESI + 0x44],EBX [895e44]
m.w32(s.si + 0x44,s.bx);
L42f2d5: // MOV EDI,dword ptr [ESP + 0x14] [8b7c2414]
s.di = m.r32(f.sp + 0x14);
L42f2d9: // MOV EBP,dword ptr [ESP + 0x18] [8b6c2418]
s.bp = m.r32(f.sp + 0x18);
L42f2dd: // CMP EDI,EBX [3bfb]
(void)ix::sub(s.di,s.bx,32,s.arithmetic_flags);
L42f2df: // JZ 0x0042f320 [743f]
if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2F290 finite PC escape at 42f2df");
L42f2e1: // CMP EDI,0x400 [81ff00040000]
(void)ix::sub(s.di,0x400u,32,s.arithmetic_flags);
L42f2e7: // JGE 0x0042f2fd [7d14]
if(ix::condition("JGE",s.arithmetic_flags)) goto L42f2fd; throw std::domain_error("2F290 finite PC escape at 42f2e7");
L42f2fd: // CMP EDI,EBX [3bfb]
(void)ix::sub(s.di,s.bx,32,s.arithmetic_flags);
L42f2ff: // MOV dword ptr [ESI + 0x30],EDI [897e30]
m.w32(s.si + 0x30,s.di);
L42f302: // JNZ 0x0042f30c [7508]
if(ix::condition("JNZ",s.arithmetic_flags)) goto L42f30c; throw std::domain_error("2F290 finite PC escape at 42f302");
L42f30c: // MOV EAX,dword ptr [ESI + 0x30] [8b4630]
s.ax = m.r32(s.si + 0x30);
L42f30f: // CMP EAX,EBX [3bc3]
(void)ix::sub(s.ax,s.bx,32,s.arithmetic_flags);
L42f311: // JZ 0x0042f450 [0f8439010000]
if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2F290 finite PC escape at 42f311");
L42f317: // CMP EBP,EBX [3beb]
(void)ix::sub(s.bp,s.bx,32,s.arithmetic_flags);
L42f319: // JZ 0x0042f328 [740d]
if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2F290 finite PC escape at 42f319");
L42f31b: // MOV dword ptr [ESI + 0x2c],EBP [896e2c]
m.w32(s.si + 0x2c,s.bp);
L42f31e: // JMP 0x0042f334 [eb14]
goto L42f334;
L42f334: // CMP dword ptr [ESI + 0x2c],EBX [395e2c]
(void)ix::sub(m.r32(s.si + 0x2c),s.bx,32,s.arithmetic_flags);
L42f337: // JZ 0x0042f445 [0f8408010000]
if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2F290 finite PC escape at 42f337");
L42f33d: // MOV EAX,dword ptr [ESI + 0x44] [8b4644]
s.ax = m.r32(s.si + 0x44);
L42f340: // OR EBP,0xffffffff [83cdff]
s.bp = ix::logical(s.bp | 0xffffffffu,32,s.arithmetic_flags);
L42f343: // CMP EAX,EBX [3bc3]
(void)ix::sub(s.ax,s.bx,32,s.arithmetic_flags);
L42f345: // MOV byte ptr [ESI + 0x20],0x1 [c6462001]
m.w8(s.si + 0x20,0x1u);
L42f349: // MOV byte ptr [ESI + 0x22],BL [885e22]
m.w8(s.si + 0x22,(s.bx&255u));
L42f34c: // MOV dword ptr [ESI + 0x34],EBX [895e34]
m.w32(s.si + 0x34,s.bx);
L42f34f: // MOV dword ptr [ESI + 0x38],EBX [895e38]
m.w32(s.si + 0x38,s.bx);
L42f352: // MOV dword ptr [ESI + 0x3c],EBP [896e3c]
m.w32(s.si + 0x3c,s.bp);
L42f355: // MOV dword ptr [ESI + 0x40],EBP [896e40]
m.w32(s.si + 0x40,s.bp);
L42f358: // MOV dword ptr [ESI + 0x48],EBX [895e48]
m.w32(s.si + 0x48,s.bx);
L42f35b: // MOV dword ptr [ESI + 0x4c],EBX [895e4c]
m.w32(s.si + 0x4c,s.bx);
L42f35e: // JZ 0x0042f438 [0f84d4000000]
if(ix::condition("JZ",s.arithmetic_flags)) goto L42f438; throw std::domain_error("2F290 finite PC escape at 42f35e");
L42f438: // MOV byte ptr [ESI + 0x25],0x1 [c6462501]
m.w8(s.si + 0x25,0x1u);
L42f43c: // POP EDI [5f]
s.di = f.pop(m);
L42f43d: // POP ESI [5e]
s.si = f.pop(m);
L42f43e: // POP EBP [5d]
s.bp = f.pop(m);
L42f43f: // MOV AL,0x1 [b001]
s.ax = (s.ax&0xffffff00u)|(0x1u&255u);
L42f441: // POP EBX [5b]
s.bx = f.pop(m);
L42f442: // RET 0x8 [c20800]
recovery_b566::finish(m,s,f,8u); return;
}
} // namespace ra2::recovered::b1699
namespace ra2::recovered::b1699::helpers {
namespace {
// Exact18-byte zero-field prefix from accepted630240 instruction evidence.
// This is not the B483 file-open domain and never invokes its virtual path.
void leaf_00630240_zero(Memory& m,State& s,Frame& caller){
 caller.push(m,0x42f5f3u); Frame f{caller.sp,caller.sp,0x42f5f3u};
 f.push(m,s.si);                              // 630240 PUSH ESI [56]
 s.si=s.cx;                                  // 630241 MOV ESI,ECX [8bf1]
 f.push(m,s.di);                              // 630243 PUSH EDI [57]
 s.ax=m.r32(s.si+0x14u);                     // 630244 [8b4614]
 (void)direct_b33::integer::logical(s.ax&s.ax,32,s.arithmetic_flags); // 630247 [85c0]
 if(direct_b33::integer::condition("JNZ",s.arithmetic_flags))
  throw std::domain_error("2F290630240 left zero-field prefix"); // 630249 [7507]
 s.di=f.pop(m);                              // 63024B [5f]
 s.ax=(s.ax&0xffffff00u)|direct_b33::integer::logical((s.ax&255u)^(s.ax&255u),8,s.arithmetic_flags); //63024C [32c0]
 s.si=f.pop(m);                              // 63024E [5e]
 recovery_b566::finish(m,s,f,4u);caller.sp=f.sp; //63024F RET4 [c20400]
}
}
void actual_slot14(Memory& m,State& s,Frame& caller,U continuation,U actual_target){
 if(continuation!=0x42f2c2u || actual_target!=0x42f5e0u)
  throw std::domain_error("2F290 actual slot14 target/caller outside finite contract");
 caller.push(m,continuation);Frame f{caller.sp,caller.sp,continuation};
 s.ax=(s.ax&0xffffff00u)|m.r8(s.cx+0x25u);    //42F5E0 MOV AL,[ECX+25] [8a4125]
 (void)direct_b33::integer::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags); //42F5E3 [84c0]
 if(!direct_b33::integer::condition("JZ",s.arithmetic_flags))
  throw std::domain_error("2F29042F5E0 left fresh+25zero route"); //42F5E5 [7405]
 f.push(m,0u);                               //42F5EC PUSH0 [6a00]
 leaf_00630240_zero(m,s,f);                   //42F5EE CALL630240 [e84d0c2000]
 recovery_b566::finish(m,s,f,4u);caller.sp=f.sp; //42F5F3 RET4 [c20400]
}
} // namespace
