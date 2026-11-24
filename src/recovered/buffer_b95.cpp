#include "buffer_b95.hpp"
#include "text_b68.hpp"
#include "text_b76.hpp"
namespace ra2::recovered::buffer_b95 {
using U=std::uint32_t;
using global_b26::s32;
// These guest-memory views cover only the finite routes in block95_contracts.
// Original small scalar helpers below are expressed in this memory adapter;
// their unchanged x86 bodies are also executed by the comparison harness.
std::uint32_t fun_004046e0(Memory&m,const Inputs&i){
 const U r=i.cx,n=m.r32(r+0xa8)-1;m.w32(r+0x1e0,n);m.w32(r+0xac,0);
 for(U k=0;k<n;++k)m.w32(r+0x160+4*k,k+1);
 return m.r32(r+0x28)+0x1c; // original tail helper 0x2030
}
std::uint32_t fun_00408b50(Memory&m,const Inputs&i){
 const U o=i.cx,head=m.r32(o+4),selected=o+0x18+64*i.dx;
 U node=head,ordinal=0;
 while(node&&node!=o+4){const U p=m.r32(node+0x18),n=m.r32(node+0x1c);m.w32(node+0x20,p);m.w32(node+0x24,n);m.w32(node+0x28,p);m.w32(node+0x2c,n);m.w32(node+0x34,ordinal++);node=m.r32(node);}
 for(U p=o+0x4c;p<=o+0x8c;p+=0x40){m.w32(p-0xc,head);m.w32(p,0xfffffc17);m.w32(p+4,0xfffffc17);m.w32(p-4,0);m.w32(p-8,0);m.w32(p-0x28,head);m.w32(p-0x30,head?m.r32(head+0x20+8*m.r32(p-0x20)):0);m.w32(p-0x2c,0);m.w32(p-0x24,m.r32(p-0x24)&~1u);}
 m.w32(o+0x4c,m.r32(o+0x4c)+m.r32(o+0x14));m.w32(selected+0x1c,m.r32(selected+0x1c)+1);m.w32(o+0x98,m.r32(o+0x98)+1);return selected;
}
std::uint32_t fun_00409020(Memory&m,const Inputs&i){
 const U r=i.cx,owner=m.r32(r),mode=m.r32(r+0x14),consumed=m.r32(r+0x2c),slot=0x20+8*mode;
 const U other=owner+0x18+64*(mode==1?0:mode+1);m.w32(r+0x38,m.r32(r+0x38)+consumed);m.w32(other+0x34,m.r32(other+0x34)+consumed);
 U left=consumed,node=m.r32(r+0x28);
 while(left){const U available=m.r32(node+slot+4);if(s32(available)<=s32(left)){left-=available;m.w32(node+slot,m.r32(node+0x18));m.w32(node+slot+4,m.r32(node+0x1c));const U sentinel=m.r32(node+0x30)+4;node=m.r32(node);if(node==sentinel){node=m.r32(node);if(node==sentinel)node=0;}}
 else {m.w32(node+slot,m.r32(node+slot)+left);m.w32(node+slot+4,available-left);left=0;}}
 m.w32(r+0x28,node);m.w32(r+0x2c,0);m.w32(r+0xc,node);m.w32(r+4,node?m.r32(node+slot):0);m.w32(r+8,0);m.w32(r+0x10,m.r32(r+0x10)&~1u);
 Inputs q=i;q.dx=0;text_b76::fun_004090e0(m,q);return consumed;
}
std::uint32_t fun_00435590(Memory&m,const Inputs&i){
 const U r=i.cx,src=i.arg[0],count=i.arg[1];i.arg[0]=0;Inputs q{};q.arg={r+0x10,src,count};global_b26::fun_0076ebd0(m,q);m.w32(r+0x18,count);return 0;
}
std::uint32_t fun_00494920(Memory&m,const Inputs&i){
 const U r=i.arg[0],dst=i.arg[1],count=i.arg[2],out=i.arg[3];m.w8(r+0x10,1);if(out)m.w32(out,0);Inputs q{};q.arg={dst,m.r32(r+0x28)+m.r32(r+0x18)-m.r32(r+0x14),count};global_b26::fun_0076ebd0(m,q);i.arg[1]+=count;m.w32(r+0x14,m.r32(r+0x14)-count);if(out)m.w32(out,count);return 0;
}
std::uint32_t fun_00530580(Memory&m,const Inputs&i){
 const U r=i.cx,tail=m.r32(r+0x318);
 // 0x130be0 and 0x130b80: full, nonempty ring with nonzero head word.
 if(((tail+1)&255)!=m.r32(r+0x314)||!m.r16(r+0x114+2*m.r32(r+0x314)))throw std::domain_error("530580 refill route excluded");
 auto pop=[&](){U h=m.r32(r+0x314);if(h==tail)return U(0);U value=m.r16(r+0x114+2*h);m.w32(r+0x314,(h+1)&255);return value;};
 const U code=pop(),kind=code&255;if(kind==1||kind==2||kind==4){U x=pop();m.w32(r,x);U y=pop();m.w32(r+0xc,x);m.w32(r+4,y);m.w32(r+0x10,y);}else if(kind==10)m.w16(r+8,pop());return code;
}
std::uint32_t fun_00530730(Memory&m,const Inputs&i){
 const U r=i.cx,kind=i.arg[0]&65535,flag=i.arg[1]&255;
 // Original 0x1228e0 mode write, with the selected nonzero global gate.
 if(m.r32(0xa39eec))m.w16(0xa39c10+2*(kind&255),flag?0:0x8000);
 const U tail=m.r32(r+0x318),next=(tail+1)&255;if(next==m.r32(r+0x314))return 0;
 m.w16(r+0x114+2*tail,kind|(flag?0x800:0));m.w32(r+0x318,next);return 1;
}
std::uint32_t fun_005f8260(Memory&m,const Inputs&i){
 const U r=i.cx,src=i.arg[0],a=m.r32(r+0x28),b=m.r32(r+0x34),c=m.r32(r+0x3c);
 for(U k=0;k<512;k+=4)m.w32(r+k,m.r32(src+k));m.w32(r+0x28,a);m.w32(r+0x34,b);m.w32(r+0x3c,c);return r;
}
std::uint32_t fun_0077673f(Memory&m,const Inputs&i){
 const U r=i.arg[0],index=m.r32(r+0x10);
 const U stream_flag=index<m.r32(0xb10e00)?m.r8(m.r32(0xb10d00+4*(index>>5))+4+36*(index&31))&0x40:0;
 if(!stream_flag||r!=0x817010)throw std::domain_error("77673f stream scope");m.w32(0xb10450,m.r32(0xb10450)+1);
 const U buffer=m.r32(0xb10564);if(!buffer||(m.r16(r+0xc)&0x10c))throw std::domain_error("77673f allocator route excluded");
 m.w32(r+0x18,0x1000);m.w32(r+8,buffer);m.w32(r,buffer);m.w32(r+4,0x1000);m.w16(r+0xc,m.r16(r+0xc)|0x1102);return 1;
}
}
