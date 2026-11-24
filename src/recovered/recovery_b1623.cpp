#include "recovered/recovery_b1623.hpp"
#include <stdexcept>
namespace ra2::recovered::b1623 {namespace {
void need(bool v){if(!v)throw std::domain_error("1623 finite default constructor");}
void empty(Memory&m,U p,U tag){m.w32(p+4,0);m.w32(p+8,0);m.w8(p+12,1);m.w8(p+13,0);m.w32(p,tag);}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){(void)heap;need(root==0x267ac0&&i.arg[1]==0&&i.cx>=0x10000000&&std::uint64_t(i.cx)+0x1bc<=0x100000000ull);const U self=i.cx,first=self+0x188,second=self+0x1a4;
 need(m.r32(0x794538)==0x669150);constexpr char text[]="No Digest";for(U k=0;k<sizeof(text);++k)need(m.r8(0x7dd378+k)==U(text[k]));
 // Full genuine66A420/66A470 zero-count paths, followed by Root's derived stores.
 // No existing helper's one-element/allocation contract is broadened.
 empty(m,first,0x7944cc);m.w32(first+0x14,10);m.w32(first+0x10,0);m.w32(first,0x79452c);
 empty(m,second,0x7944ec);m.w32(second+0x14,10);m.w32(second,0x79450c);m.w32(second+0x10,0);
 m.w16(self,0);m.w8(self+0x15b,0);for(U k=0;k<sizeof(text);++k)m.w8(self+0x15c+k,m.r8(0x7dd378+k));m.w8(self+0x17c,1);m.w32(self+0x180,2);m.w32(self+0x184,4);
 // The Root itself produced first.vptr=79452C; actual+0C is669150.
 // Its pointer is genuinely0 from the constructor, so no release/provider runs.
 need(m.r32(first)==0x79452c&&m.r32(first+4)==0);m.w32(first+0x10,0);m.w8(first+13,0);m.w32(first+8,0);
 // F=S-1F4; [F+1FC]=S+8 is arg1 (filename), not arg0. Real NULL skips IO.
 return self;
}}
