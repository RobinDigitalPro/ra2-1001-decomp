#include "recovered/indirect_b31_memory.hpp"

namespace ra2::recovered::indirect_b31 {
namespace {
inline void call(Memory& m, State& s, Frame& f, const Operations& o, std::uint32_t slot) {
    invoke(m,s,f,o,m.r32(slot));
}
inline void set_al(State& s,std::uint32_t v){s.ax=with_al(s.ax,v);}
}

void fun_00613570(Memory&m,State&s,Frame&f,const Operations&o){
 const auto p=s.cx,oldsi=s.si;f.push(m,oldsi);s.si=p;s.cx=m.r32(f.sp+8);s.ax=m.r32(p);f.push(m,s.cx);s.cx=p;
 f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.ax+0x10);
 auto idx=s.ax;
 if(idx!=0xffffffffu){
   s.cx=m.r32(p+0x10);
   if(s32(idx)<s32(s.cx)){
   --s.cx;m.w32(p+0x10,s.cx);
   if(s32(idx)<s32(s.cx)){
     do{s.cx=m.r32(p+4);++s.ax;s.dx=m.r32(s.cx+4u*s.ax);m.w32(s.cx+4u*s.ax-4u,s.dx);s.cx=m.r32(p+0x10);}while(s32(s.ax)<s32(s.cx));
   }
     set_al(s,1);
   }else set_al(s,0);
 }else set_al(s,0);
 s.si=f.pop(m);finish(m,s,f,4);
}
void fun_00615020(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx,oldsi=s.si;f.push(m,oldsi);s.si=p;s.cx=m.r32(p);if(s.cx){s.ax=m.r32(s.cx);f.push(m,1);f.argument_words=1;f.callback_cleanup=4;invoke(m,s,f,o,m.r32(s.ax));m.w32(p,0);}s.si=f.pop(m);finish(m,s,f,0);}
void fun_0062e4e0(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx,oldbx=s.bx,oldsi=s.si,olddi=s.di;f.push(m,oldbx);f.push(m,oldsi);s.si=m.r32(f.sp+0xc);f.push(m,olddi);s.di=p;s.bx=m.r32(p+0xd0);if(s32(s.si)>s32(s.bx)){s.ax=m.r32(p+0xc8);s.cx=p+0xc8;f.push(m,0);f.push(m,s.si);f.argument_words=2;f.callback_cleanup=8;invoke(m,s,f,o,m.r32(s.ax+8));s.ax=s.bx;if(s32(s.bx)<s32(s.si)){do{s.cx=m.r32(s.di+0xcc);++s.ax;m.w32(s.cx+4*s.ax-4,0);}while(s32(s.ax)<s32(s.si));}}s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);finish(m,s,f,4);}
void fun_0062f940(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;s.ax=m.r32(s.si);call(m,s,f,o,s.ax+0x18);if((s.ax&255)==0){m.w32(s.si+0xc,0);s.ax=1;}else s.ax=0;s.si=f.pop(m);finish(m,s,f,0);}
void fun_0062f960(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;s.ax=m.r32(s.si);call(m,s,f,o,s.ax+0x18);if((s.ax&255)==0){m.w32(s.si+0xc,0);s.ax=1;}else s.ax=0;s.si=f.pop(m);finish(m,s,f,0);}
void fun_0062fa80(Memory&m,State&s,Frame&f,const Operations&o){
 const auto p=s.cx;f.push(m,s.si);s.si=p;
 s.ax=m.r32(s.si+4);
 if(s.ax==0){s.ax=m.r32(s.si+0x10);s.si=f.pop(m);finish(m,s,f,8);return;}
 s.ax=m.r32(s.si);call(m,s,f,o,s.ax+0x18);
 if((s.ax&255u)==0){s.ax=m.r32(s.si+0x10);s.si=f.pop(m);finish(m,s,f,8);return;}
 s.ax=with_al(s.ax,m.r8(s.si+0x14));s.dx=m.r32(s.si+0xc);
 const auto flags=s.ax&255u;s.cx=s.dx;
 if(flags&2u)s.cx=m.r32(s.si+8);
 auto op=m.r32(f.entry_sp+8);s.ax=op;
 if(s.ax==0){s.ax=m.r32(f.entry_sp+4);m.w32(s.si+0x10,s.ax);}
 else if(--s.ax==0){s.ax=m.r32(f.entry_sp+4);f.push(m,s.di);s.di=m.r32(s.si+0x10);s.di+=s.ax;m.w32(s.si+0x10,s.di);s.di=f.pop(m);}
 else if(--s.ax==0){s.ax=m.r32(f.entry_sp+4);s.ax+=s.cx;m.w32(s.si+0x10,s.ax);}
 else s.ax=m.r32(s.si+0x10);
 s.ax=m.r32(s.si+0x10);
 if(s32(s.ax)<0)m.w32(s.si+0x10,0);
 if(s32(m.r32(s.si+0x10))>s32(s.cx))m.w32(s.si+0x10,s.cx);
 s.ax=m.r32(s.si+0x10);
 if(s32(s.ax)>s32(s.dx))m.w32(s.si+0xc,s.ax);
 s.si=f.pop(m);finish(m,s,f,8);
}
void fun_00630ad0(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;f.push(m,s.di);s.di=m.r32(f.entry_sp+4);if(s.di!=m.r32(s.si+4)){if(s.di)m.w32(s.di+4,m.r32(s.di+4)+1);s.cx=m.r32(s.si+4);if(s.cx){m.w32(s.si+4,0);s.ax=m.r32(s.cx);call(m,s,f,o,s.ax+8);}m.w32(s.si+4,s.di);}s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,4);}
void fun_0066b3b0(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=m.r32(f.entry_sp+4);s.cx=m.r32(s.si-0x14);s.ax=s.si-0x14;f.push(m,s.ax);call(m,s,f,o,s.cx+0x10);if(s.ax&255){set_al(s,0);}else{s.ax=m.r32(s.si+0x50);if(s.ax){s.ax=with_al(s.ax,m.r8(s.si+0x4d));if(s.ax&255)set_al(s,1);else set_al(s,0);}else set_al(s,0);}s.si=f.pop(m);finish(m,s,f,4);}
void fun_006906b0(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;f.push(m,s.di);s.di=0;s.ax=m.r32(s.si+4);m.w32(s.si,0x7899f8);if(s.ax)m.w32(s.ax+8,m.r32(s.si+8));s.cx=m.r32(s.si+8);if(s.cx){s.ax=m.r32(s.si+4);s.dx=m.r32(s.cx);f.push(m,s.ax);call(m,s,f,o,s.dx+4);}m.w32(s.si+8,0);m.w32(s.si+4,0);s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,0);}
void fun_006906f0(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=m.r32(f.entry_sp+4);f.push(m,s.di);s.di=s.cx;if(m.r32(s.di+4)!=s.si){if(s.si){s.cx=m.r32(s.si+8);if(s.cx){s.ax=m.r32(s.cx);f.push(m,0);call(m,s,f,o,s.ax+4);m.w32(s.si+8,0);}}s.ax=m.r32(s.di+4);if(s.ax)m.w32(s.ax+8,0);m.w32(s.di+4,s.si);if(s.si)m.w32(s.si+8,s.di);}s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,4);}
void fun_00690740(Memory&m,State&s,Frame&f,const Operations&o){s.cx=m.r32(s.cx+4);if(!s.cx){s.ax=0;finish(m,s,f,8);return;}s.dx=m.r32(f.entry_sp+8);s.ax=m.r32(s.cx);f.push(m,s.dx);s.dx=m.r32(f.entry_sp+4);f.push(m,s.dx);f.argument_words=2;f.callback_cleanup=8;call(m,s,f,o,s.ax+8);finish(m,s,f,8);}
void fun_006925e0(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.cx);const auto p=s.cx;s.dx=with_al(s.dx,m.r8(p+0x55));if((s.dx&255)==0){set_al(s,0);s.cx=f.pop(m);finish(m,s,f,0);return;}m.w8(p+0x57,0);m.w8(p+0x55,0);s.dx=m.r32(0x00a1e0e8);s.ax=f.sp;m.w32(f.sp,p);f.push(m,s.ax);s.cx=0x00a1e0e8;f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.dx+0x10);s.cx=m.r32(0x00a1e0f8);if(s.ax!=0xffffffffu&&s32(s.ax)<s32(s.cx)){--s.cx;m.w32(0x00a1e0f8,s.cx);if(s32(s.ax)<s32(s.cx)){do{s.cx=m.r32(0x00a1e0ec);++s.ax;s.dx=m.r32(s.cx+4*s.ax);m.w32(s.cx+4*s.ax-4,s.dx);s.cx=m.r32(0x00a1e0f8);}while(s32(s.ax)<s32(s.cx));}}set_al(s,1);s.cx=f.pop(m);finish(m,s,f,0);}
void fun_00694390(Memory&m,State&s,Frame&f,const Operations&o){fun_00613570(m,s,f,o);}
void fun_00695170(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.bx);f.push(m,s.di);s.di=m.r32(f.entry_sp+8);if(!s.di){s.ax=0x80004003u;s.di=f.pop(m);s.bx=f.pop(m);finish(m,s,f,8);return;}s.bx=m.r32(s.di);if(!s.bx){s.ax=0;s.di=f.pop(m);s.bx=f.pop(m);finish(m,s,f,8);return;}const auto obj=m.r32(f.entry_sp+4);f.push(m,s.si);s.cx=m.r32(obj+0xc);s.si=obj+4;s.ax=m.r32(obj+0x14);if(s32(s.ax)>=s32(s.cx)){s.ax=with_al(s.ax,m.r8(s.si+0xd));if((s.ax&255)!=0||s.cx==0){s.ax=m.r32(s.si+0x14);if(s32(s.ax)<=0)goto i5170_no_insert;s.dx=m.r32(s.si);s.ax+=s.cx;f.push(m,0);f.push(m,s.ax);s.cx=s.si;f.argument_words=2;f.callback_cleanup=8;call(m,s,f,o,s.dx+8);if((s.ax&255)==0)goto i5170_no_insert;}else goto i5170_no_insert;}
{s.ax=m.r32(s.si+0x10);s.dx=m.r32(s.si+4);s.cx=s.ax+1;m.w32(s.si+0x10,s.cx);m.w32(s.dx+8*s.ax,s.bx);m.w32(s.dx+8*s.ax+4,s.di);}i5170_no_insert:m.w32(s.di,0);s.si=f.pop(m);s.di=f.pop(m);s.ax=0;s.bx=f.pop(m);finish(m,s,f,8);}
void fun_006951f0(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.bx);s.bx=m.r32(f.entry_sp+8);f.push(m,s.si);s.ax=m.r32(f.entry_sp+4);s.si=s.ax+0x1c;f.push(m,s.di);s.di=m.r32(f.entry_sp+12);const auto p=m.r32(f.entry_sp+4);s.cx=m.r32(p+0x2c);s.ax=m.r32(s.si+8);if(s32(s.cx)>=s32(s.ax)){s.cx=with_al(s.cx,m.r8(s.si+0xd));if((s.cx&255)!=0||s.ax==0){s.cx=m.r32(s.si+0x14);if(s32(s.cx)<=0)goto i51f0_done;s.dx=m.r32(s.si);s.cx+=s.ax;f.push(m,0);f.push(m,s.cx);s.cx=s.si;f.argument_words=2;f.callback_cleanup=8;call(m,s,f,o,s.dx+8);if((s.ax&255)==0)goto i51f0_done;}else goto i51f0_done;}
 {s.ax=m.r32(s.si+0x10);s.dx=m.r32(s.si+4);s.cx=s.ax+1;m.w32(s.si+0x10,s.cx);m.w32(s.dx+8*s.ax,s.bx);m.w32(s.dx+8*s.ax+4,s.di);}i51f0_done:s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);s.ax=0;finish(m,s,f,12);}
void fun_006a9310(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;m.w8(s.si+0x34,1);s.ax=m.r32(0xaa87e8);s.cx=m.r32(0xaa87f0);bool add=s32(s.cx)<s32(s.ax);if(!add){s.cx=with_al(s.cx,m.r8(0xaa87ed));if((s.cx&255)!=0||s.ax==0){s.cx=m.r32(0xaa87f4);if(s32(s.cx)>0){s.cx+=s.ax;s.ax=m.r32(0xaa87e0);f.push(m,0);f.push(m,s.cx);s.cx=0xaa87e0;f.argument_words=2;f.callback_cleanup=8;call(m,s,f,o,s.ax+8);add=(s.ax&255)!=0;}}}if(add){s.cx=m.r32(0xaa87f0);s.ax=s.cx;++s.cx;m.w32(0xaa87f0,s.cx);s.cx=m.r32(0xaa87e4);m.w32(s.cx+4*s.ax,s.si);}s.si=f.pop(m);finish(m,s,f,0);}
void fun_006b5de0(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;s.cx=m.r32(s.si+8);s.ax=m.r32(s.si+0x10);if(s32(s.ax)<s32(s.cx))goto b5_add;s.ax=with_al(s.ax,m.r8(s.si+0xd));if((s.ax&255)==0&&s.cx!=0)goto b5_fail;s.ax=m.r32(s.si+0x14);if(s32(s.ax)<=0)goto b5_fail;s.dx=m.r32(s.si);s.ax+=s.cx;f.push(m,0);f.push(m,s.ax);s.cx=s.si;f.argument_words=2;f.callback_cleanup=8;call(m,s,f,o,s.dx+8);if((s.ax&255)==0)goto b5_fail;
b5_add:s.ax=m.r32(s.si+0x10);s.dx=m.r32(s.si+4);s.cx=s.ax+1;m.w32(s.si+0x10,s.cx);s.cx=m.r32(f.entry_sp+4);s.si=m.r32(s.cx);m.w32(s.dx+8*s.ax,s.si);s.cx=m.r32(s.cx+4);s.si=f.pop(m);m.w32(s.dx+8*s.ax+4,s.cx);set_al(s,1);finish(m,s,f,4);return;
b5_fail:set_al(s,0);s.si=f.pop(m);finish(m,s,f,4);}
void fun_006cdbf0(Memory&m,State&s,Frame&f,const Operations&o){auto v=m.r32(f.entry_sp+4);if(v){m.w8(s.cx+0x170,1);s.ax=m.r32(0xa2896c);m.w32(s.cx+0x174,s.ax);}s.dx=m.r32(s.cx);call(m,s,f,o,s.dx+0x428);finish(m,s,f,4);}
void fun_006d52b0(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=m.r32(f.entry_sp+4);f.push(m,s.di);f.push(m,s.si);s.ax=m.r32(s.si);f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.ax+0x10);if(s.ax&255){s.ax=m.r32(f.entry_sp+8);s.cx=m.r32(s.si+0x18);s.dx=m.r32(s.si+0x1c);s.si=m.r32(s.si+0x20);}else{s.cx=m.r32(s.si+8)+0x88;s.ax=s.cx;s.cx=m.r32(s.ax);s.dx=m.r32(s.ax+4);s.si=m.r32(s.ax+8);s.ax=m.r32(f.entry_sp+8);}s.di=s.ax;m.w32(s.di,s.cx);m.w32(s.di+4,s.dx);m.w32(s.di+8,s.si);s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,8);}
void fun_006d6e40(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=m.r32(f.entry_sp+4);s.cx=m.r32(s.si-0x14);s.ax=s.si-0x14;f.push(m,s.ax);call(m,s,f,o,s.cx+0x10);if(s.ax&255){set_al(s,0);}else{s.ax=m.r32(s.si+0x30);if(!s.ax)set_al(s,0);else{s.ax=with_al(s.ax,m.r8(s.si+0x1d));if(s.ax&255)set_al(s,0);else{s.dx=m.r32(s.si-0xc);s.ax=with_al(s.ax,m.r8(s.dx+0x210));if(s.ax&255)set_al(s,0);else{s.ax=m.r32(s.si+0x20);if(s.ax)set_al(s,0);else set_al(s,1);}}}}s.si=f.pop(m);finish(m,s,f,4);}
void fun_006e2c50(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;m.w8(s.si+0x2c,1);s.ax=m.r32(0xaa87e8);s.cx=m.r32(0xaa87f0);bool add=s32(s.cx)<s32(s.ax);if(!add){s.cx=with_al(s.cx,m.r8(0xaa87ed));if((s.cx&255)!=0||s.ax==0){s.cx=m.r32(0xaa87f4);if(s32(s.cx)>0){s.cx+=s.ax;s.ax=m.r32(0xaa87e0);f.push(m,0);f.push(m,s.cx);s.cx=0xaa87e0;f.argument_words=2;f.callback_cleanup=8;call(m,s,f,o,s.ax+8);add=(s.ax&255)!=0;}}}if(add){s.cx=m.r32(0xaa87f0);s.ax=s.cx;++s.cx;m.w32(0xaa87f0,s.cx);s.cx=m.r32(0xaa87e4);m.w32(s.cx+4*s.ax,s.si);}s.si=f.pop(m);finish(m,s,f,0);}
void fun_006e4f00(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=m.r32(f.entry_sp+4);f.push(m,s.si);s.ax=m.r32(s.si);f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.ax+0x10);if(!(s.ax&255)){set_al(s,0);}else{s.cx=m.r32(s.si+0x14);s.ax=1;if(s.cx==1)set_al(s,0);}s.si=f.pop(m);finish(m,s,f,4);}
void fun_006e4f30(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=m.r32(f.entry_sp+4);f.push(m,s.di);f.push(m,s.si);s.ax=m.r32(s.si);f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.ax+0x10);if(s.ax&255){s.ax=m.r32(f.entry_sp+8);s.cx=m.r32(s.si+0x18);s.dx=m.r32(s.si+0x1c);s.si=m.r32(s.si+0x20);}else{s.cx=m.r32(s.si+8)+0x88;s.ax=s.cx;s.cx=m.r32(s.ax);s.dx=m.r32(s.ax+4);s.si=m.r32(s.ax+8);s.ax=m.r32(f.entry_sp+8);}s.di=s.ax;m.w32(s.di,s.cx);m.w32(s.di+4,s.dx);m.w32(s.di+8,s.si);s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,8);}
void fun_006ea7d0(Memory&m,State&s,Frame&f,const Operations&o){s.cx=m.r32(0xaa8dc0);if(s.cx){s.ax=m.r32(s.cx);f.push(m,1);f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.ax);m.w32(0xaa8dc0,0);}finish(m,s,f,0);}
void fun_006ec490(Memory&m,State&s,Frame&f,const Operations&o){s.ax=with_al(s.ax,m.r8(0xaa8dba));if((s.ax&255)==0){m.w8(0xaa8dba,1);f.callback_cleanup=0;f.argument_words=0;invoke(m,s,f,o,m.r32(0x785524));m.w32(0xaa8dbc,s.ax);}finish(m,s,f,0);}
void fun_006f9640(Memory&m,State&s,Frame&f,const Operations&o){auto v=m.r32(f.entry_sp+4);s.ax=v;if(v!=0xffffffffu&&m.r32(s.cx+0x5b4)==0xffffffffu){m.w32(s.cx+0x5b4,v);s.ax=m.r32(s.cx);f.push(m,2);call(m,s,f,o,s.ax+0x11c);set_al(s,1);}else set_al(s,0);finish(m,s,f,4);}
void fun_006f9670(Memory&m,State&s,Frame&f,const Operations&o){s.dx=m.r32(s.cx+0x5b4);s.ax=0xffffffffu;if(s.dx!=0xffffffffu){m.w32(s.cx+0x5b4,s.ax);s.ax=m.r32(s.cx);f.push(m,2);call(m,s,f,o,s.ax+0x11c);set_al(s,1);}else set_al(s,0);finish(m,s,f,0);}
void fun_006fe8e0(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=s.cx;s.ax=m.r32(s.si);m.w8(s.si+0x170,0);call(m,s,f,o,s.ax+0x428);m.w32(s.si+0x40c,0);m.w32(s.si+0x410,0);s.si=f.pop(m);finish(m,s,f,0);}
void fun_00712ad0(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=m.r32(f.entry_sp+4);f.push(m,s.di);f.push(m,s.si);s.ax=m.r32(s.si);f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.ax+0x10);if(s.ax&255){s.ax=m.r32(f.entry_sp+8);s.cx=m.r32(s.si+0x18);s.dx=m.r32(s.si+0x1c);s.si=m.r32(s.si+0x20);}else{s.ax=m.r32(f.entry_sp+8);s.cx=m.r32(0xae0ae0);s.dx=m.r32(0xae0ae4);s.si=m.r32(0xae0ae8);}s.di=s.ax;m.w32(s.di,s.cx);m.w32(s.di+4,s.dx);m.w32(s.di+8,s.si);s.di=f.pop(m);s.si=f.pop(m);finish(m,s,f,8);}
void fun_00714760(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=m.r32(f.entry_sp+4);s.cx=m.r32(s.si-0x14);s.ax=s.si-0x14;f.push(m,s.ax);call(m,s,f,o,s.cx+0x10);if(s.ax&255)set_al(s,0);else{s.ax=m.r32(s.si+0x20);if(s.ax){s.ax=with_al(s.ax,m.r8(s.si+0x1d));if(s.ax&255)set_al(s,0);else set_al(s,1);}else set_al(s,0);}s.si=f.pop(m);finish(m,s,f,4);}
void fun_00719b40(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx; s.dx=m.r32(f.entry_sp+4);f.push(m,s.si);s.si=p;f.push(m,s.dx);s.ax=m.r32(s.si+0x28);s.cx=s.si+0x28;f.argument_words=1;f.callback_cleanup=4;invoke(m,s,f,o,m.r32(s.ax+0x14));s.cx=m.r32(s.si+0x24);++s.ax;if(s.cx!=0xffffffffu&&s.ax==m.r32(s.si+0x38))s.ax=s.cx;if(s32(s.ax)<0||s32(s.ax)>=s32(m.r32(s.si+0x38))){s.ax=0;s.si=f.pop(m);finish(m,s,f,4);return;}s.cx=m.r32(s.si+0x2c);s.ax=s.cx+12u*s.ax;s.si=f.pop(m);finish(m,s,f,4);}
namespace {
void reset_with_optional_call(Memory&m,State&s,Frame&f,const Operations&o,bool clear_extra){
 const auto p=s.cx;
 f.push(m,s.bx); f.push(m,s.si);
 f.callback_cleanup=4; f.argument_words=1;
 s.si=p; s.bx=0;
 const auto child=m.r32(p+4); s.cx=child;
 if(clear_extra)m.w32(p+0x10,0);
 if(child!=0 && m.r8(p+0xd)!=0){
   // The original loads EAX=[ECX], pushes 3, and calls through [EAX].
   s.ax=m.r32(child);f.push(m,3); f.argument_words=1; f.callback_cleanup=4;
   invoke(m,s,f,o,m.r32(s.ax));
   m.w32(p+4,0);
 }
 m.w8(p+0xd,0); m.w32(p+8,0);
 s.si=f.pop(m); s.bx=f.pop(m);
 finish(m,s,f,0);
}
}
void fun_0071b5f0(Memory&m,State&s,Frame&f,const Operations&o){reset_with_optional_call(m,s,f,o,true);}
void fun_0071b8d0(Memory&m,State&s,Frame&f,const Operations&o){reset_with_optional_call(m,s,f,o,false);}
void fun_0071c750(Memory&m,State&s,Frame&f,const Operations&o){reset_with_optional_call(m,s,f,o,true);}
void fun_0071cc80(Memory&m,State&s,Frame&f,const Operations&o){reset_with_optional_call(m,s,f,o,false);}
void fun_0071fb40(Memory&m,State&s,Frame&f,const Operations&o){reset_with_optional_call(m,s,f,o,true);}
void fun_0071fe40(Memory&m,State&s,Frame&f,const Operations&o){reset_with_optional_call(m,s,f,o,false);}
void fun_007215e0(Memory&m,State&s,Frame&f,const Operations&o){reset_with_optional_call(m,s,f,o,true);}
void fun_007218b0(Memory&m,State&s,Frame&f,const Operations&o){reset_with_optional_call(m,s,f,o,false);}
void fun_0074a150(Memory&m,State&s,Frame&f,const Operations&o){s.ax=m.r32(0xa5a874);if(s.ax){s.cx=m.r32(s.ax);f.push(m,0x7e89b8);f.push(m,s.ax);f.argument_words=2;f.callback_cleanup=8;call(m,s,f,o,s.cx+0x3c);}finish(m,s,f,0);}
void fun_0075dcd0(Memory&m,State&s,Frame&f,const Operations&o){
 const auto p=s.cx, entry=f.entry_sp;
 s.ax=p;
 f.sp-=0x20;
 s.cx=m.r32(p+0x50);
 f.push(m,s.bp);
 if(s32(s.cx)<=0){s.bp=f.pop(m);f.sp+=0x20;finish(m,s,f,0);return;}
 s.cx=m.r32(p+0x54);if(s32(s.cx)<=0){s.bp=f.pop(m);f.sp+=0x20;finish(m,s,f,0);return;}
 s.cx=m.r32(p+0x24);if(!s.cx){s.bp=f.pop(m);f.sp+=0x20;finish(m,s,f,0);return;}
 s.bp=m.r32(p+0x44);if(!s.bp){s.bp=f.pop(m);f.sp+=0x20;finish(m,s,f,0);return;}
 s.dx=m.r32(p+0x48);s.dx+=m.r32(p+0x2c);
 f.push(m,s.bx);s.bx=m.r32(p+0x54);
 f.push(m,s.si);s.si=m.r32(p+0x4c);s.si+=m.r32(p+0x30);
 f.push(m,s.di);s.di=m.r32(p+0x50);
 m.w32(entry-0x10,s.dx);
 s.ax=0;f.push(m,1);m.w32(entry-0x20,s.ax);m.w32(entry-0x1c,s.ax);
 f.push(m,s.ax);s.ax=f.sp+0x18u;f.push(m,s.ax);
 m.w32(entry-8,s.di);m.w32(entry-4,s.bx);m.w32(entry-0xc,s.si);m.w32(entry-0x18,s.di);m.w32(entry-0x14,s.bx);
 f.push(m,s.bp);s.ax=entry-0x10;f.push(m,s.ax);
 const auto child=s.cx; s.dx=m.r32(child); s.ax=entry-0x10;
 f.argument_words=5;f.callback_cleanup=20;invoke(m,s,f,o,m.r32(s.dx+8));
 s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);s.bp=f.pop(m);f.sp+=0x20;finish(m,s,f,0);
}
void fun_00761630(Memory&m,State&s,Frame&f,const Operations&o){s.cx=m.r32(s.cx+0x14);if(s.cx){s.ax=m.r32(s.cx);f.push(m,1);f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.ax);}finish(m,s,f,0);}
void fun_00761aa0(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.sp-=0x10;const auto l=f.sp;s.dx=m.r32(p+0x2c);m.w32(l+0xc,s.dx);s.ax=0;s.dx=m.r32(f.entry_sp+4);m.w32(l,s.ax);m.w32(l+4,s.ax);s.ax=m.r32(p+0x28);s.cx=m.r32(p+0x14);s.dx&=0xffffu;m.w32(l+8,s.ax);s.ax=m.r32(s.cx);f.push(m,s.dx);s.dx=f.sp+4;f.push(m,s.dx);f.argument_words=2;f.callback_cleanup=8;call(m,s,f,o,s.ax+0x14);f.sp+=16;finish(m,s,f,4);}
void fun_007668e0(Memory&m,State&s,Frame&f,const Operations&o){
 const auto p=s.cx,entry=f.entry_sp,oldbx=s.bx,oldbp=s.bp,oldsi=s.si,olddi=s.di;
 f.push(m,p);f.push(m,oldbx);f.push(m,oldbp);f.push(m,oldsi);
 s.ax=s.dx;s.si=p;m.w32(entry-4,s.ax);f.push(m,olddi);
 const auto record=m.r32(p+0x164);s.bp=record;s.di=m.r32(p+0x768);
 s.bx=m.r32(record);s.ax=(s.ax+1u);s.ax=(s.ax&0xffffff00u)|((s.ax&0xffu)&0xfeu);
 s.di-=s.ax;s.bx+=s.di;
 f.push(m,s.ax);f.push(m,s.bx);f.push(m,5);f.push(m,p);
 f.argument_words=4;f.callback_cleanup=0;invoke(m,s,f,o,m.r32(p+0x40));f.sp+=16;
 if(s.ax!=0){s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=0xfffffffcu;s.bx=f.pop(m);s.cx=f.pop(m);finish(m,s,f,0);return;}
 m.w32(p+0x174,0);m.w32(s.bp+0xc,10);m.w32(s.bp+0x10,s.di);m.w32(p+0x168,s.bp);s.ax=m.r32(s.bp+4);m.w32(p+0x164,s.ax);
 if(m.r16(p+0xe8)<3){const auto saved_ecx=m.r32(f.sp+0x10);s.cx=saved_ecx;m.w8(s.bx+saved_ecx+1,0x80);}
 s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.ax=0xffffffffu;s.bx=f.pop(m);s.cx=f.pop(m);finish(m,s,f,0);
}
void fun_00768460(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;f.push(m,s.di);s.di=s.dx;f.push(m,s.si);m.w32(s.si+0x148,0);f.argument_words=1;f.callback_cleanup=0;invoke(m,s,f,o,m.r32(s.si+0x50));f.sp+=4;s.ax=s.ax*60u;s.dx=0;const auto den=m.r32(s.si+0x78);if(!den)throw std::domain_error("excluded DIV zero");const auto q=s.ax/den,rem=s.ax%den;s.di-=q;s.ax=m.r32(s.si+0x148);s.di-=s.ax;m.w32(s.si+0x148,s.di);s.di=f.pop(m);s.si=f.pop(m);s.dx=rem;finish(m,s,f,0);}
void fun_007684b0(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;f.push(m,s.si);f.argument_words=1;f.callback_cleanup=0;invoke(m,s,f,o,m.r32(s.si+0x50));s.ax=s.ax*60u;s.dx=0;f.sp+=4;const auto den=m.r32(s.si+0x78);if(!den)throw std::domain_error("excluded DIV zero");s.cx=s.ax/den;s.dx=s.ax%den;s.ax=m.r32(s.si+0x148);s.ax+=s.cx;s.si=f.pop(m);finish(m,s,f,0);}
void fun_007684e0(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;f.push(m,s.di);f.push(m,s.si);s.di=m.r32(s.si+0x78);f.argument_words=1;f.callback_cleanup=0;invoke(m,s,f,o,m.r32(s.si+0x50));const auto dividend=s.ax*60u;s.dx=0;f.sp+=4;if(!s.di)throw std::domain_error("excluded DIV zero");const auto quotient=dividend/s.di,rem=dividend%s.di;s.di=f.pop(m);s.cx=quotient;s.dx=rem;s.ax=m.r32(s.si+0x148);s.ax+=s.cx;s.si=f.pop(m);finish(m,s,f,0);}
void fun_0077333f(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,0x140);f.push(m,0);f.push(m,m.r32(0xb10e1c));f.argument_words=3;f.callback_cleanup=12;call(m,s,f,o,0x785270);m.w32(0xb10e18,s.ax);if(!s.ax){finish(m,s,f,0);return;}m.w32(0xb10e10,0);m.w32(0xb10e14,0);f.push(m,1);m.w32(0xb10e0c,s.ax);m.w32(0xb10e04,0x10);s.ax=f.pop(m);finish(m,s,f,0);}
void fun_007742a8(Memory&m,State&s,Frame&f,const Operations&o){f.argument_words=1;f.callback_cleanup=0;s.ax=m.r32(0xb10558);if(!s.ax){s.ax=0;finish(m,s,f,0);return;}f.push(m,m.r32(f.entry_sp+4));invoke(m,s,f,o,s.ax);s.cx=f.pop(m);if(!s.ax){s.ax=0;finish(m,s,f,0);return;}f.push(m,1);s.ax=f.pop(m);finish(m,s,f,0);}
void fun_0077b49b(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.bp);s.bp=f.sp;f.sp-=0x94;s.ax=s.bp-0x94;m.w32(s.ax,0x94);f.push(m,s.ax);f.argument_words=1;f.callback_cleanup=4;invoke(m,s,f,o,m.r32(0x78517c));if(s.ax&&m.r32(s.bp-0x84)==2)s.ax=1;else s.ax=0;f.sp=s.bp;s.bp=f.pop(m);finish(m,s,f,0);}
void fun_0077d58d(Memory&m,State&s,Frame&f,const Operations&o){s.ax=m.r32(f.entry_sp+4);s.cx=s.ax;s.ax&=0x1fu;s.cx=sar(s.cx,5);s.ax=s.ax*9u;s.cx=m.r32(0xb10d00+4*s.cx);s.ax=s.cx+4*s.ax+0xc;f.push(m,s.ax);f.argument_words=1;f.callback_cleanup=4;invoke(m,s,f,o,m.r32(0x7851e0));finish(m,s,f,0);}
void fun_00780cfc(Memory&m,State&s,Frame&f,const Operations&o){f.push(m,s.si);s.si=1;f.push(m,m.r32(f.entry_sp+4));f.argument_words=1;f.callback_cleanup=4;invoke(m,s,f,o,m.r32(0x785154));if(s.ax)s.si=0;s.ax=s.si;s.si=f.pop(m);finish(m,s,f,0);}
void fun_00781910(Memory&m,State&s,Frame&f,const Operations&o){const auto p=s.cx;f.push(m,s.si);s.si=p;s.ax=m.r32(f.entry_sp+4);m.w32(s.si+0xc,0);m.w32(s.si+4,s.ax);s.ax=m.r32(f.entry_sp+8);m.w32(s.si,0x79d4d8);m.w32(s.si+8,s.ax);if(s.ax&&m.r8(f.entry_sp+12)){s.cx=m.r32(s.ax);f.push(m,s.ax);f.argument_words=1;f.callback_cleanup=4;call(m,s,f,o,s.cx+4);}s.ax=s.si;s.si=f.pop(m);finish(m,s,f,12);}

const std::array<Entry,53>& entries_c(){static const std::array<Entry,53> a{{
{0x213570,fun_00613570},{0x215020,fun_00615020},{0x22e4e0,fun_0062e4e0},{0x22f940,fun_0062f940},{0x22f960,fun_0062f960},{0x22fa80,fun_0062fa80},{0x230ad0,fun_00630ad0},{0x26b3b0,fun_0066b3b0},{0x2906b0,fun_006906b0},{0x2906f0,fun_006906f0},{0x290740,fun_00690740},{0x2925e0,fun_006925e0},{0x294390,fun_00694390},{0x295170,fun_00695170},{0x2951f0,fun_006951f0},{0x2a9310,fun_006a9310},{0x2b5de0,fun_006b5de0},{0x2cdbf0,fun_006cdbf0},{0x2d52b0,fun_006d52b0},{0x2d6e40,fun_006d6e40},{0x2e2c50,fun_006e2c50},{0x2e4f00,fun_006e4f00},{0x2e4f30,fun_006e4f30},{0x2ea7d0,fun_006ea7d0},{0x2ec490,fun_006ec490},{0x2f9640,fun_006f9640},{0x2f9670,fun_006f9670},{0x2fe8e0,fun_006fe8e0},{0x312ad0,fun_00712ad0},{0x314760,fun_00714760},{0x319b40,fun_00719b40},{0x31b5f0,fun_0071b5f0},{0x31b8d0,fun_0071b8d0},{0x31c750,fun_0071c750},{0x31cc80,fun_0071cc80},{0x31fb40,fun_0071fb40},{0x31fe40,fun_0071fe40},{0x3215e0,fun_007215e0},{0x3218b0,fun_007218b0},{0x34a150,fun_0074a150},{0x35dcd0,fun_0075dcd0},{0x361630,fun_00761630},{0x361aa0,fun_00761aa0},{0x3668e0,fun_007668e0},{0x368460,fun_00768460},{0x3684b0,fun_007684b0},{0x3684e0,fun_007684e0},{0x37333f,fun_0077333f},{0x3742a8,fun_007742a8},{0x37b49b,fun_0077b49b},{0x37d58d,fun_0077d58d},{0x380cfc,fun_00780cfc},{0x381910,fun_00781910}}};return a;}
} // namespace ra2::recovered::indirect_b31
