#include "recovered/recovery_b1703.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b1703::calls {
namespace integer=direct_b33::integer;

void house_4e73d0(Memory& m,State& s,Frame& caller,U continuation,U actual_target){
 if(actual_target!=0x004e73d0u)throw std::domain_error("1b6760 unreviewed House target");
 caller.push(m,continuation);
 Frame f{caller.sp,caller.sp,continuation};
 U flags=s.arithmetic_flags;

 L004e73d0: { // 0x4e73d0: 8a813f010000 MOV AL,byte ptr [ECX + 0x13f]
  s.ax=(s.ax&0xffffff00u)|m.r8(s.cx+0x13fu);
 }
 L004e73d6: { // 0x4e73d6: 83ec0c SUB ESP,0xc
  f.sp=integer::sub(f.sp,0xcu,32,flags);
 }
 L004e73d9: { // 0x4e73d9: 84c0 TEST AL,AL
  integer::logical(s.ax&0xffu,8,flags);
 }
 L004e73db: { // 0x4e73db: 8a813e010000 MOV AL,byte ptr [ECX + 0x13e]
  s.ax=(s.ax&0xffffff00u)|m.r8(s.cx+0x13eu);
 }
 L004e73e1: { // 0x4e73e1: 7540 JNZ 0x004e7423
  if(integer::condition("JNZ",flags))goto L004e7423;
 }
 L004e73e3: { // 0x4e73e3: 84c0 TEST AL,AL
  integer::logical(s.ax&0xffu,8,flags);
 }
 L004e73e5: { // 0x4e73e5: 7536 JNZ 0x004e741d
  if(integer::condition("JNZ",flags))goto L004e741d;
 }
 L004e73e7: { // 0x4e73e7: 8a8140010000 MOV AL,byte ptr [ECX + 0x140]
  s.ax=(s.ax&0xffffff00u)|m.r8(s.cx+0x140u);
 }
 L004e73ed: { // 0x4e73ed: 84c0 TEST AL,AL
  integer::logical(s.ax&0xffu,8,flags);
 }
 L004e73ef: { // 0x4e73ef: 752c JNZ 0x004e741d
  if(integer::condition("JNZ",flags))goto L004e741d;
 }
 L004e73f1: { // 0x4e73f1: 56 PUSH ESI
  f.push(m,s.si);
 }
 L004e73f2: { // 0x4e73f2: c6813e01000001 MOV byte ptr [ECX + 0x13e],0x1
  m.w8(s.cx+0x13eu,1u);
 }
 L004e73f9: { // 0x4e73f9: a16c89a200 MOV EAX,[0x00a2896c]
  s.ax=m.r32(0x00a2896cu);
 }
 L004e73fe: { // 0x4e73fe: 8db1e0010000 LEA ESI,[ECX + 0x1e0]
  s.si=s.cx+0x1e0u;
 }
 L004e7404: { // 0x4e7404: 33d2 XOR EDX,EDX
  s.dx=integer::logical(0u,32,flags);
 }
 L004e7406: { // 0x4e7406: 8906 MOV dword ptr [ESI],EAX
  m.w32(s.si,s.ax);
 }
 L004e7408: { // 0x4e7408: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
  // This is the natural earlier B843 saved-EBX word, never a supplied value.
  s.ax=m.r32(f.sp+8u);
 }
 L004e740c: { // 0x4e740c: 894604 MOV dword ptr [ESI + 0x4],EAX
  m.w32(s.si+4u,s.ax);
 }
 L004e740f: { // 0x4e740f: 8a813e010000 MOV AL,byte ptr [ECX + 0x13e]
  s.ax=(s.ax&0xffffff00u)|m.r8(s.cx+0x13eu);
 }
 L004e7415: { // 0x4e7415: 895608 MOV dword ptr [ESI + 0x8],EDX
  m.w32(s.si+8u,s.dx);
 }
 L004e7418: { // 0x4e7418: 5e POP ESI
  s.si=f.pop(m);
 }
 L004e7419: { // 0x4e7419: 83c40c ADD ESP,0xc
  f.sp=integer::add(f.sp,0xcu,32,flags);
 }
 L004e741c: { // 0x4e741c: c3 RET
  goto finish_return;
 }
 L004e741d: { // 0x4e741d: 8a813e010000 MOV AL,byte ptr [ECX + 0x13e]
  s.ax=(s.ax&0xffffff00u)|m.r8(s.cx+0x13eu);
 }
 L004e7423: { // 0x4e7423: 83c40c ADD ESP,0xc
  f.sp=integer::add(f.sp,0xcu,32,flags);
 }
 L004e7426: { // 0x4e7426: c3 RET
  goto finish_return;
 }
 finish_return:
 s.arithmetic_flags=flags;
 recovery_b566::finish(m,s,f,0u);
 caller.sp=f.sp;
}
} // namespace ra2::recovered::recovery_b1703::calls
