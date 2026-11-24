#pragma once
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"
#include <stdexcept>

// B781-only transitions for the exact [3,11,11,13,13,6,6] schedule. These
// are deliberately not exposed as a general allocator implementation.
namespace ra2::platform::small_crt_heap781::string781 {
using U=std::uint32_t;
inline void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
struct C { U record,arena,metadata; };
inline C current(X86Memory&m){
 const U r=m.r32(0xb10e0c),a=m.r32(r+0x0c),d=m.r32(r+0x10);
 need(r&&a&&d&&m.r32(0xb10e14)==1&&m.r32(0xb10e18)==r,"B781 exact one-region state");
 need(m.r32(r+4)==1&&m.r32(r+8)==0x7fffffff&&m.r32(d)==0,"B781 fresh page-zero state");
 return {r,a,d};
}
inline U head(C c,unsigned cls){return c.metadata+0x144u+cls*8u;}
inline U bit(unsigned cls){return 0x80000000u>>cls;}
inline void link_remove(X86Memory&m,U p){const U n=m.r32(p+4),q=m.r32(p+8);m.w32(q+4,n);m.w32(n+8,q);}
inline void insert_front(X86Memory&m,U h,U p){const U n=m.r32(h+4);m.w32(p+4,n);m.w32(p+8,h);m.w32(h+4,p);m.w32(n+8,p);}
inline void class_add(X86Memory&m,C c,unsigned cls,U p,U span){
 const U h=head(c,cls),b=bit(cls);need(m.r8(c.metadata+4+cls)==0,"B781 target class must be empty");
 need(m.r32(h+4)==h&&m.r32(h+8)==h,"B781 target sentinel must be empty");
 insert_front(m,h,p);m.w8(c.metadata+4+cls,1);m.w32(c.record,m.r32(c.record)|b);m.w32(c.metadata+0x44,m.r32(c.metadata+0x44)|b);
 m.w32(p,span);m.w32(p+span-4,span);
}
inline void class_remove(X86Memory&m,C c,unsigned cls,U p){
 const U h=head(c,cls),b=bit(cls);need(m.r8(c.metadata+4+cls)==1&&m.r32(h+4)==p&&m.r32(h+8)==p,"B781 source class must contain the exact single node");
 link_remove(m,p);m.w8(c.metadata+4+cls,0);m.w32(c.record,m.r32(c.record)&~b);m.w32(c.metadata+0x44,m.r32(c.metadata+0x44)&~b);
}
inline void class_add_existing(X86Memory&m,C c,unsigned cls,U p,U span){
 const U h=head(c,cls),b=bit(cls);const auto count=m.r8(c.metadata+4+cls);
 need(count==1&&m.r32(h+4)!=h&&m.r32(h+8)!=h,"B781 existing class0 node required before second insert");
 // This metadata byte counts occupied class lists/chunk classes, not nodes.
 // The original increments it only when a class list changes empty->nonempty.
 insert_front(m,h,p);
 m.w32(p,span);m.w32(p+span-4,span);
}
inline void class_remove_member(X86Memory&m,C c,unsigned cls,U p){
 const U h=head(c,cls),b=bit(cls);const auto count=m.r8(c.metadata+4+cls);
 need(count==1&&m.r32(h+4)!=h&&m.r32(h+8)!=h,"B781 occupied two-node class0 list required before right unlink");
 // Removing one node from a still-nonempty class list does not decrement the
 // class occupancy byte or clear the class bitmap.
 link_remove(m,p);
 need((m.r32(c.record)&b)!=0&&(m.r32(c.metadata+0x44)&b)!=0,"B781 surviving class0 map bit");
}
inline U free_number_merge_class1(X86Memory&m,U user){
 const C c=current(m);const U p=user-4,h1=head(c,1),h2=head(c,2);
 need(user==c.arena+0xff0&&m.r32(p)==0x11&&m.r32(p-4)==0x20&&m.r32(p+0x10)==0xffffffff,"B781 number free must merge with left class1 and right sentinel");
 const U left=p-0x20;need(m.r32(left)==0x20&&m.r32(left+4)==h1&&m.r32(left+8)==h1,"B781 exact left class1 block");
 need(m.r32(h2+4)==h2&&m.r32(h2+8)==h2&&m.r8(c.metadata+6)==0,"B781 class2 destination empty");
 class_remove(m,c,1,left);const U span=0x30;
 m.w32(left,span);m.w32(left+span-4,span);class_add(m,c,2,left,span);
 const U live=m.r32(c.metadata+0x144);need(live==2,"B781 expected two live blocks before number free");m.w32(c.metadata+0x144,live-1);
 return left;
}
inline U allocate6_from_class2(X86Memory&m,U entry_esp){
 const C c=current(m);need(m.r32(entry_esp+4)==6,"B781 request 6");
 const U h=head(c,2),p=m.r32(h+4);need(p==c.arena+0xfcc&&m.r8(c.metadata+6)==1&&m.r32(p)==0x30&&m.r32(p+4)==h&&m.r32(p+8)==h,"B781 sole class2 span30");
 class_remove(m,c,2,p);const U low=0x20,high=0x10,allocated=p+low,tag=high+1;
 class_add(m,c,1,p,low);m.w32(allocated,tag);m.w32(allocated+high-4,tag);
 const U live=m.r32(c.metadata+0x144);need(live==1,"B781 one live block before class2 split");m.w32(c.metadata+0x144,live+1);m.w32(c.metadata,0);
 return allocated+4;
}
inline U allocate6_from_class1(X86Memory&m,U entry_esp){
 const C c=current(m);need(m.r32(entry_esp+4)==6,"B781 request 6");
 const U h=head(c,1),p=m.r32(h+4);need(p==c.arena+0xfcc&&m.r8(c.metadata+5)==1&&m.r32(p)==0x20&&m.r32(p+4)==h&&m.r32(p+8)==h,"B781 sole class1 span20");
 class_remove(m,c,1,p);const U low=0x10,high=0x10,allocated=p+low,tag=high+1;
 class_add(m,c,0,p,low);m.w32(allocated,tag);m.w32(allocated+high-4,tag);
 const U live=m.r32(c.metadata+0x144);need(live==2,"B781 two live blocks before class1 split");m.w32(c.metadata+0x144,live+1);m.w32(c.metadata,0);
 return allocated+4;
}
inline void release_key_merge_both(X86Memory&m,U user){
 const C c=current(m);const U p=user-4,h0=head(c,0);
 need(user==c.arena+0xfb0&&m.r32(p)==0x21&&m.r32(p-4)==0xfa0&&m.r32(p+0x20)==0x10,"B781 final key lies between class63 and class0");
 const U left=p-0xfa0,right=p+0x20,span=0xfd0,h63=head(c,63);
 need(left==c.arena+0x0c&&m.r32(left)==0xfa0&&m.r32(left+4)==c.arena+0x100c&&m.r32(left+8)==h63,"B781 left class63 ring node");
 need(right==c.arena+0xfcc&&m.r32(right)==0x10&&m.r32(head(c,0)+4)==c.arena+0xfec&&m.r32(head(c,0)+8)==right&&m.r32(right+4)==head(c,0)&&m.r32(right+8)==c.arena+0xfec,"B781 right class0 is the second free-list node");
 class_remove_member(m,c,0,right);m.w32(left,span);m.w32(left+span-4,span);
 const U live=m.r32(c.metadata+0x144);need(live==2,"B781 expected receiver and table temp live before final-key release");m.w32(c.metadata+0x144,live-1);
}
} // namespace ra2::platform::small_crt_heap781::string781
