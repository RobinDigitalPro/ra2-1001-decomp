#include "recovery_b1700.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
// BEGIN mechanical component preflight
namespace ra2::recovered::recovery_b1700::helpers {
namespace {
constexpr U self=0x18001000u,child=0x18002000u,tag=0x18003000u;
constexpr U table=0x798c88u,table_size=0x4cu;
struct Range {U base,size;};
void need(bool v,const char*why){if(!v)throw std::domain_error(why);}
std::uint64_t end(const Range&r){return std::uint64_t(r.base)+r.size;}
void mapped(const Memory&m,const Range&r){
 need(r.size&&end(r)<=0x100000000ULL,"4F840 logical mapped range wraps");
 // Adapter coverage only: discard every value. No private input is seeded,
 // and a successful read is not an OS ownership, protection or RW proof.
 for(U k=0;k<r.size;++k)(void)m.r8(r.base+k);
}
}

void require_selected_basis(const Memory&m,const State&s,const Frame&f){
 need(s.cx==self,"4F840 finite borrowed Self address");
 need(f.sp==f.entry_sp,"4F840 actual initial Root Frame");
 need(f.entry_sp>=0x60u&&std::uint64_t(f.entry_sp)+0x44u<=0x100000000ULL,
      "4F840 complete getter/Root/return/caller16 extent");
 const std::array<Range,5> ranges{{{self,0x600u},{child,0x200u},
     {tag,0x20u},{table,table_size},{f.entry_sp-0x60u,0xa4u}}};
 for(std::size_t a=0;a<ranges.size();++a){
  need(end(ranges[a])<=0x100000000ULL,"4F840 finite public range wraps");
  for(std::size_t b=a+1;b<ranges.size();++b)
   need(end(ranges[a])<=ranges[b].base||end(ranges[b])<=ranges[a].base,
        "4F840 Self/Child/Tag/table/actual stack alias");
 }
 for(const auto&r:ranges)mapped(m,r);
 need(m.r32(f.entry_sp)==f.outer_return,"4F840 actual outer return word");
 need(m.r32(self)==table&&m.r32(table+0x48u)==0x5cd4d0u,
      "4F840 normal primary and genuine reached getter target");
 // The packet/baseline must separately authenticate all 76 table bytes.
 // This gate proves coverage and the only reached slot, not the other bytes.
 need(m.r32(self+0x418u)==tag&&m.r32(self+0x1b8u)==1u&&
      m.r8(self+0x5bbu)==0u&&m.r32(self+0x5bcu)==0xffffffffu,
      "4F840 selected borrowed phase/counter/tag inputs");
 for(U k=0;k<18u;++k)
  need(m.r32(self+0x454u+4u*k)==(k==7u?child:0u),
       "4F840 exact one-child slot7 input");
 need(m.r8(child+0x158u)!=0u,"4F840 material incoming child byte");
 const U x=m.r32(self+0x88u),y=m.r32(self+0x8cu),z=m.r32(self+0x90u);
 need((x==0x180u&&y==0xfffffe80u&&z==0x2au)||
      (x==0xfffffe80u&&y==0x180u&&z==0xffffffffu),
      "4F840 exact two declared signed-coordinate inputs");
 // All caller16 values, Self75 and all other public/private bytes remain
 // opaque. OpaqueTag contents are never semantic Root input on this route.
 // No FP, EFLAGS, LastError, pointer value or memory state is normalized.
}
} // namespace ra2::recovered::recovery_b1700::helpers
// END mechanical component preflight
// BEGIN mechanical component getter
namespace ra2::recovered::recovery_b1700::getter_model {
void actual_primary48(Memory& m,State& s,Frame& caller,U continuation,U actual_target){
    // Domain check is outside the selected callee and changes no guest state.
    if(continuation!=0x44f869u || actual_target!=0x5cd4d0u)
        throw std::domain_error("4F840 primary48 target/continuation outside finite contract");
    caller.push(m,continuation); //44F866 actual CALL return word
    Frame f{caller.sp,caller.sp,continuation};
L5cd4d0: //MOV EAX,[ESP+4] [8b442404]
    s.ax=m.r32(f.sp+4u);
L5cd4d4: //ADD ECX,88 [81c188000000]
    s.cx=direct_b33::integer::add(s.cx,0x88u,32,s.arithmetic_flags);
L5cd4da: //PUSH ESI [56]
    f.push(m,s.si);
L5cd4db: //MOV EDX,EAX [8bd0]
    s.dx=s.ax;
L5cd4dd: //MOV ESI,[ECX] [8b31]
    s.si=m.r32(s.cx);
L5cd4df: //MOV [EDX],ESI [8932]
    m.w32(s.dx,s.si);
L5cd4e1: //MOV ESI,[ECX+4] [8b7104]
    s.si=m.r32(s.cx+4u);
L5cd4e4: //MOV [EDX+4],ESI [897204]
    m.w32(s.dx+4u,s.si);
L5cd4e7: //POP ESI [5e]
    s.si=f.pop(m);
L5cd4e8: //MOV ECX,[ECX+8] [8b4908]
    s.cx=m.r32(s.cx+8u);
L5cd4eb: //MOV [EDX+8],ECX [894a08]
    m.w32(s.dx+8u,s.cx);
L5cd4ee: //RET4 [c20400]
    recovery_b566::finish(m,s,f,4u);
    caller.sp=f.sp;
}
}
// END mechanical component getter
// BEGIN mechanical component root
namespace ra2::recovered::recovery_b1700 {
namespace ix=direct_b33::integer;
void execute_selected(Memory&m,State&s,Frame&f){
    helpers::require_selected_basis(m,s,f); // readonly, before first guest instruction
L44f840: // SUB ESP,0x44 [83ec44]
    f.sp=ix::sub(f.sp,0x44u,32,s.arithmetic_flags);
L44f843: // PUSH EBX [53]
    f.push(m,s.bx);
L44f844: // PUSH EBP [55]
    f.push(m,s.bp);
L44f845: // PUSH ESI [56]
    f.push(m,s.si);
L44f846: // MOV ESI,ECX [8bf1]
    s.si=s.cx;
L44f848: // XOR EBP,EBP [33ed]
    s.bp=ix::logical(s.bp^s.bp,32,s.arithmetic_flags);
L44f84a: // PUSH EDI [57]
    f.push(m,s.di);
L44f84b: // MOV EAX,dword ptr [ESI + 0x418] [8b8618040000]
    s.ax=m.r32(s.si+0x418u);
L44f851: // MOV dword ptr [ESP + 0x10],ESI [89742410]
    m.w32(f.sp+0x10u,s.si);
L44f855: // CMP EAX,EBP [3bc5]
    (void)ix::sub(s.ax,s.bp,32,s.arithmetic_flags);
L44f857: // JZ 0x00450028 [0f84cb070000]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("4F840 escaped selected nonnull418 at44F857");
L44f85d: // MOV EAX,dword ptr [ESI] [8b06]
    s.ax=m.r32(s.si);
L44f85f: // LEA ECX,[ESP + 0x44] [8d4c2444]
    s.cx=f.sp+0x44u;
L44f863: // PUSH ECX [51]
    f.push(m,s.cx);
L44f864: // MOV ECX,ESI [8bce]
    s.cx=s.si;
L44f866: // CALL dword ptr [EAX + 0x48] [ff5048]
    getter_model::actual_primary48(m,s,f,0x44f869u,m.r32(s.ax+0x48u));
L44f869: // MOV ECX,EAX [8bc8]
    s.cx=s.ax;
L44f86b: // MOV EAX,dword ptr [ECX] [8b01]
    s.ax=m.r32(s.cx);
L44f86d: // CDQ [99]
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
L44f86e: // AND EDX,0xff [81e2ff000000]
    s.dx=ix::logical(s.dx&0xffu,32,s.arithmetic_flags);
L44f874: // ADD EAX,EDX [03c2]
    s.ax=ix::add(s.ax,s.dx,32,s.arithmetic_flags);
L44f876: // SAR EAX,0x8 [c1f808]
    s.ax=ix::shift(s.ax,8u,32,s.arithmetic_flags,ix::Shift::arithmetic_right);
L44f879: // MOV word ptr [ESP + 0x30],AX [6689442430]
    m.w16(f.sp+0x30u,s.ax&0xffffu);
L44f87e: // MOV EAX,dword ptr [ECX + 0x4] [8b4104]
    s.ax=m.r32(s.cx+4u);
L44f881: // CDQ [99]
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
L44f882: // AND EDX,0xff [81e2ff000000]
    s.dx=ix::logical(s.dx&0xffu,32,s.arithmetic_flags);
L44f888: // ADD EAX,EDX [03c2]
    s.ax=ix::add(s.ax,s.dx,32,s.arithmetic_flags);
L44f88a: // SAR EAX,0x8 [c1f808]
    s.ax=ix::shift(s.ax,8u,32,s.arithmetic_flags,ix::Shift::arithmetic_right);
L44f88d: // MOV word ptr [ESP + 0x32],AX [6689442432]
    m.w16(f.sp+0x32u,s.ax&0xffffu);
L44f892: // MOV EAX,dword ptr [ESI + 0x1b8] [8b86b8010000]
    s.ax=m.r32(s.si+0x1b8u);
L44f898: // CMP EAX,0x1 [83f801]
    (void)ix::sub(s.ax,1u,32,s.arithmetic_flags);
L44f89b: // JNZ 0x0044f936 [0f8595000000]
    if(ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("4F840 escaped selected state1 at44F89B");
L44f8a1: // MOV AL,byte ptr [ESI + 0x5bd] [8a86bd050000]
    s.ax=(s.ax&0xffffff00u)|m.r8(s.si+0x5bdu);
L44f8a7: // CMP AL,0xf [3c0f]
    (void)ix::sub(s.ax&255u,0xfu,8,s.arithmetic_flags);
L44f8a9: // JGE 0x0044fa9a [0f8deb010000]
    if(ix::condition("JGE",s.arithmetic_flags)) throw std::domain_error("4F840 escaped selected signedFF at44F8A9");
L44f8af: // INC AL [fec0]
    s.ax=(s.ax&0xffffff00u)|ix::increment(s.ax&255u,8,s.arithmetic_flags);
L44f8b1: // CMP AL,0x1 [3c01]
    (void)ix::sub(s.ax&255u,1u,8,s.arithmetic_flags);
L44f8b3: // MOV byte ptr [ESI + 0x5bd],AL [8886bd050000]
    m.w8(s.si+0x5bdu,s.ax&255u);
L44f8b9: // JZ 0x0044f8c3 [7408]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("4F840 unselected Self75 store at44F8B9");
L44f8bb: // CMP AL,0x6 [3c06]
    (void)ix::sub(s.ax&255u,6u,8,s.arithmetic_flags);
L44f8bd: // JZ 0x0044f8c3 [7404]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("4F840 unselected Self75 store at44F8BD");
L44f8bf: // CMP AL,0xb [3c0b]
    (void)ix::sub(s.ax&255u,0xbu,8,s.arithmetic_flags);
L44f8c1: // JNZ 0x0044f8c7 [7504]
    if(ix::condition("JNZ",s.arithmetic_flags)) goto L44f8c7; throw std::domain_error("4F840 unselected Self75 store at44F8C1");
L44f8c7: // MOVSX EBX,AL [0fbed8]
    s.bx=U(ix::sign_extend(s.ax,8));
L44f8ca: // CMP EBX,0xf [83fb0f]
    (void)ix::sub(s.bx,0xfu,32,s.arithmetic_flags);
L44f8cd: // JNZ 0x0044f8e2 [7513]
    if(ix::condition("JNZ",s.arithmetic_flags)) goto L44f8e2; throw std::domain_error("4F840 unselected secondary dispatch at44F8CD");
L44f8e2: // LEA ECX,[ESI + 0x454] [8d8e54040000]
    s.cx=s.si+0x454u;
L44f8e8: // MOV EDI,0x12 [bf12000000]
    s.di=0x12u;
L44f8ed: // MOV EAX,dword ptr [ECX] [8b01]
    s.ax=m.r32(s.cx);
L44f8ef: // CMP EAX,EBP [3bc5]
    (void)ix::sub(s.ax,s.bp,32,s.arithmetic_flags);
L44f8f1: // JZ 0x0044f8f9 [7406]
    if(ix::condition("JZ",s.arithmetic_flags)) goto L44f8f9;
L44f8f3: // MOV byte ptr [EAX + 0x158],BL [889858010000]
    m.w8(s.ax+0x158u,s.bx&255u);
L44f8f9: // ADD ECX,0x4 [83c104]
    s.cx=ix::add(s.cx,4u,32,s.arithmetic_flags);
L44f8fc: // DEC EDI [4f]
    s.di=ix::decrement(s.di,32,s.arithmetic_flags);
L44f8fd: // JNZ 0x0044f8ed [75ee]
    if(ix::condition("JNZ",s.arithmetic_flags)) goto L44f8ed;
L44f8ff: // CMP byte ptr [ESI + 0x5bd],0xf [80bebd0500000f]
    (void)ix::sub(m.r8(s.si+0x5bdu),0xfu,8,s.arithmetic_flags);
L44f906: // JNZ 0x0044fa9a [0f858e010000]
    if(ix::condition("JNZ",s.arithmetic_flags)) goto L44fa9a; throw std::domain_error("4F840 unselected phase transition at44F906");
L44fa9a: // CMP dword ptr [ESI + 0x1b8],0x2 [83beb801000002]
    (void)ix::sub(m.r32(s.si+0x1b8u),2u,32,s.arithmetic_flags);
L44faa1: // JNZ 0x0044fabd [751a]
    if(ix::condition("JNZ",s.arithmetic_flags)) goto L44fabd; throw std::domain_error("4F840 unselected phase284 at44FAA1");
L44fabd: // MOV EAX,dword ptr [ESI + 0x1b8] [8b86b8010000]
    s.ax=m.r32(s.si+0x1b8u);
L44fac3: // TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax&s.ax,32,s.arithmetic_flags);
L44fac5: // JNZ 0x0044fae1 [751a]
    if(ix::condition("JNZ",s.arithmetic_flags)) goto L44fae1; throw std::domain_error("4F840 unselected phase280 at44FAC5");
L44fae1: // MOV AL,byte ptr [ESI + 0x5bb] [8a86bb050000]
    s.ax=(s.ax&0xffffff00u)|m.r8(s.si+0x5bbu);
L44fae7: // TEST AL,AL [84c0]
    (void)ix::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags);
L44fae9: // JZ 0x00450028 [0f8439050000]
    if(ix::condition("JZ",s.arithmetic_flags)) goto L450028; throw std::domain_error("4F840 unselected observer/grid route at44FAE9");
L450028: // POP EDI [5f]
    s.di=f.pop(m);
L450029: // POP ESI [5e]
    s.si=f.pop(m);
L45002a: // POP EBP [5d]
    s.bp=f.pop(m);
L45002b: // POP EBX [5b]
    s.bx=f.pop(m);
L45002c: // ADD ESP,0x44 [83c444]
    f.sp=ix::add(f.sp,0x44u,32,s.arithmetic_flags);
L45002f: // RET 0x4 [c20400]
    recovery_b566::finish(m,s,f,4u); return;
}
} // namespace ra2::recovered::recovery_b1700
// END mechanical component root
