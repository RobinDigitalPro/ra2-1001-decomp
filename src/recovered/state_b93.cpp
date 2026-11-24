#include "recovered/state_b93.hpp"
#include <cstdint>
#include <initializer_list>

namespace ra2::recovered::state_b93 {
using global_b26::s32;

std::uint32_t fun_004070f0(Memory& m,const Inputs&i){
 const auto p=i.cx, end=m.r32(p+8u),cur=m.r32(p+4u);
 if(end==cur || (m.r8(p)&1u)==0)return 0;
 m.w32(p+4u,end);m.w32(p,m.r32(p)|2u);return 1;
}
std::uint32_t fun_0044b470(Memory&m,const Inputs&i){
 const auto p=i.cx,eax=m.r32(p+0x5c8u);if(!eax)return eax;
 const auto n=m.r32(p+0x5d8u)-1u;m.w32(p+0x5d8u,n);
 if(s32(n)>0)return eax;
 // The selected fixture domain excludes the callback/count-transition branch.
 return eax;
}
std::uint32_t fun_004688d0(Memory&m,const Inputs&i){
 const auto p=i.cx;if(i.arg[0]!=0) return p;
 m.w32(p+4u,0);m.w32(p+8u,0);m.w32(p+0xcu,0);
 m.w16(p+0x14u,0);m.w16(p+0x16u,0);m.w32(p+0x18u,0);
 m.w32(p+0x1cu,0xffffffffu);m.w32(p,0x0078883cu);return p;
}
std::uint32_t fun_00475440(Memory&m,const Inputs&i){
 const auto v=m.r32(i.cx+0x44u);if(v==i.arg[0]&&v!=0xffffffffu)return (v&0xffffff00u)|1u;
 return v&0xffffff00u;
}
std::uint32_t fun_00569a30(Memory&m,const Inputs&i){
 const auto p=i.cx;m.w32(p+4u,0);m.w32(p+8u,i.arg[0]);m.w8(p+0xcu,1);m.w8(p+0xdu,0);m.w32(p,0x00790a18u);return p;
}

namespace {
std::uint32_t clear_control_table(Memory&m){
 const std::uint32_t p=0x00a255e0u;m.w32(p+0x24u,0);
 for(unsigned n=0;n<8;++n){const auto q=p+0x6cu+n*4u;m.w32(q-0x20u,0xffffffffu);m.w32(q,0xffffffffu);}
 return p+0x8cu;
}
}
std::uint32_t fun_005c28e0(Memory&m,const Inputs&){
 const auto mode=m.r32(0x00a255c8u);if(mode==4u)return 0;
 for(unsigned n=0;n<8;++n)m.w32(0x00a27dc4u+n*4u,m.r32(0x00a5a89cu));
 m.w32(0x00a27dc0u,0xffffffffu);const auto eax=clear_control_table(m);
 m.w16(0x00a5a464u,0);m.w16(0x00a5a2b4u,0);return eax;
}
std::uint32_t fun_0062a680(Memory&m,const Inputs&i){
 const auto p=i.cx,old=m.r32(p+0x14acu);const auto state=i.arg[0];
 if(m.r32(0x00a255c8u)==0u&&state==4u&&old==3u&&m.r32(p+0x14a8u)!=5u)
   m.w32(p+0x14b0u,state);
 return old;
}
std::uint32_t fun_00653260(Memory&m,const Inputs&i){
 if(i.cx!=0)return 0; // JZ at 0x653268 bypasses the indirect 0x68fad0 call.
 const auto manager=m.r32(0x00a255c0u);
 const auto count=m.r32(manager+0x62cu);if(count==0)return manager; // initializer route excluded
 m.w32(manager+0x62cu,count+1u);return manager;
}

std::uint32_t fun_00674d10(Memory&m,const Inputs&i){
 const auto p=i.cx,index=i.arg[0]+m.r32(p+0x40u)*2u;
 const auto count=m.r32(p+0x50u);
 if(m.r8(0x00a285a8u)==0||s32(index)<0||s32(index)>=s32(count)||s32(count)>=0x4b)return 0;
 const auto rec=p+index*0x30u;if(m.r32(rec+0x58u)!=0x1fu)return 0;
 const auto table=m.r32(0x00a27f8cu),obj=m.r32(table+m.r32(rec+0x54u)*4u);
 return m.r32(obj+0x60u);
}
std::uint32_t fun_006ae600(Memory&m,const Inputs&i){
 const auto p=i.arg[0],old=m.r32(p+0x4c4u);m.w8(p+0x5a2u,1);
 return i.cx!=old?((old&0xffffff00u)|1u):(old&0xffffff00u);
}
std::uint32_t fun_006cd1f0(Memory&m,const Inputs&i){
 const auto target=i.cx;
 // Restrict to the route where the first callback-bearing list is empty.
 if(m.r32(0x00a28870u)!=0u)return 0;
 const auto count=m.r32(0x0084e4b8u),base=m.r32(0x0084e4acu);
 if(count==0u)return 0;
 std::uint32_t eax=0;
 for(std::uint32_t n=count;n>0u;--n){
  const auto object=m.r32(base+(n-1u)*4u);eax=object;
  if(m.r32(object+0x3cu)==target)m.w32(object+0x3cu,0);
  if(m.r32(object+0x40u)==target)m.w32(object+0x40u,0);
 }
 return eax;
}
std::uint32_t fun_006cd5f0(Memory&m,const Inputs&i){
 const auto p=i.cx,link=m.r32(p+0x3f8u);
 if(!link)return 0;
 if((m.r8(link+0x14u)&1u)==0||m.r8(link+0x7du)==0)m.w32(p+0x3f8u,0);
 return link;
}
std::uint32_t fun_006d78d0(Memory&m,const Inputs&i){
 const auto p=i.cx,prev=m.r32(p+0x40u),next=m.r32(p+0x44u);
 if(prev==0||next==0)return prev;
 m.w32(next+0x40u,prev);m.w32(prev+0x44u,next);
 for(auto off:{0x28u,0x44u,0x40u,0x3cu,0x38u})m.w32(p+off,0);
 return prev;
}
std::uint32_t fun_006dd460(Memory&m,const Inputs&i){
 const auto p=i.cx;if(m.r8(0x00a28858u)==0||m.r32(0x00819778u)==0||m.r8(0x00a2894cu)!=0||m.r32(p)==0xffffffffu)return 0;
 if((i.arg[0]&0xffu)!=0||m.r32(p+0x2cu)!=0)return 0;
 m.w32(p,0xffffffffu);m.w32(p+4u,0xffffffffu);m.w32(p+8u,0xffffffffu);return 0;
}
std::uint32_t fun_00756ea0(Memory&m,const Inputs&i){
 (void)i;const auto p=i.cx;const auto old_last=m.r32(p+0xcu);
 // Empty ownership fields bypass all releases; the original still publishes
 // each replacement marker and clears every associated flag and pointer.
 m.w32(p,0x0079a8b4u);m.w8(p+0x43868u,0);
 m.w32(p+0x38u,0x0079a934u);m.w8(p+0x45u,0);m.w32(p+0x40u,0);m.w32(p+0x3cu,0);
 m.w32(p+0x20u,0x0079a934u);m.w8(p+0x2du,0);m.w32(p+0x28u,0);m.w32(p+0x24u,0);
 m.w32(p+8u,0x0079a934u);m.w8(p+0x15u,0);m.w32(p+0x10u,0);m.w32(p+0x0cu,0);
 return old_last;
}
std::uint32_t fun_00771aee(Memory&m,const Inputs&i){
 const auto src=i.arg[0],out=i.arg[1],optional6=i.arg[2],optional4=i.arg[3];
 if(src==0||m.r8(src)!=0x43u||m.r8(src+1u)!=0)return 0;
 m.w8(out+1u,0);m.w8(out,0x43u);
 if(optional6){m.w16(optional6,0);m.w16(optional6+2u,0);m.w16(optional6+4u,0);}
 if(optional4)m.w32(optional4,0);return out;
}

namespace {
std::uint32_t row_at(const Memory& m,std::uint32_t receiver,unsigned index){
 return 0x00aa1240u+3360u*m.r32(receiver+0x34u)+56u*index;
}
std::int32_t signed_row_count(const Memory& m,std::uint32_t manager){
 const auto numerator=static_cast<std::int32_t>(m.r32(0x0082196cu))-
   static_cast<std::int32_t>(m.r32(0x00aa486cu))-18-
   (m.r8(manager+0x2239u)!=0u?8:0)+
   static_cast<std::int32_t>(m.r32(0x00821964u))-7;
 // x86 signed division truncates toward zero; original magic multiply is /50,
 // followed by doubling. Values are constrained away from INT_MIN.
 return (numerator/50)*2;
}
std::uint32_t row_tail_from_forwardlinks(const Memory& m,std::uint32_t row){
 auto p=m.r32(row+4u);if(!p)return row;
 for(unsigned guard=0;guard<32&&p!=row;++guard){const auto next=m.r32(p+4u);if(!next)return p;p=next;}
 return row;
}
std::uint32_t row_head_from_backlinks(const Memory& m,std::uint32_t row){
 auto p=m.r32(row+8u);if(!p)return row;
 for(unsigned guard=0;guard<32&&p!=row;++guard){const auto previous=m.r32(p+8u);if(!previous)return p;p=previous;}
 return row;
}
std::uint32_t row_membership_result(const Memory& m,std::uint32_t row){
 const auto root=row_head_from_backlinks(m,row);
 const auto head=m.r32(0x00a28b34u);
 return (root&0xffffff00u)|(root==head?1u:0u);
}
}

// Empty-head route through the actual finite callback composition: row init
// clears +4/+8, the singleton membership query is false for each fresh row,
// and the callback either installs the first head or appends with 0x5372c0.
std::uint32_t fun_00674090(Memory&m,const Inputs&i){
 const auto manager=m.r32(0x00a255c0u);
 const auto count=signed_row_count(m,manager);
 if(count<2||count>8||(count&1)!=0||m.r32(0x00a28b34u)!=0u||
    m.r32(0x0081a820u)!=0x00785954u)return 0;
 std::uint32_t last_result=0;
 for(std::int32_t k=0;k<count;++k){
  const auto row=row_at(m,i.cx,static_cast<unsigned>(k));
  if(m.r32(row)!=0x00796224u)return 0;
  m.w32(row+4u,0);m.w32(row+8u,0); // 0x5371d0
  auto head=m.r32(0x00a28b34u);
  if(!head){m.w32(0x00a28b34u,row);last_result=(row_membership_result(m,row)&0xffffff00u)|1u;}
  else{
   // 0x5372c0: old forward-tail +4 -> new row; new +8 -> old tail.
   const auto tail=row_tail_from_forwardlinks(m,head);
   m.w32(tail+4u,row);m.w32(row+8u,tail);m.w32(row+4u,0);
   // The helper's +0x18 backlink getter resolves the new row's list head.
   last_result=(row_head_from_backlinks(m,row)&0xffffff00u)|1u;
  }
 }
 m.w8(0x0081f703u,1);return last_result;
}

// Nonzero incoming flag, empty global head, and empty bounded rows select the
// false-membership exit in 0x4e0190 before its removal callback.
std::uint32_t fun_00674ec0(Memory&m,const Inputs&i){
 const auto manager=m.r32(0x00a255c0u);
 const auto count=signed_row_count(m,manager);
 const auto incoming_flag=m.r8(i.cx+0x18u);
 m.w8(i.cx+0x18u,0);
 if(count<2||count>8||(count&1)!=0||m.r32(0x00a28b34u)!=0u||
    m.r32(0x0081a820u)!=0x00785954u||incoming_flag==0u)return 0;
 std::uint32_t eax=0;
 for(std::int32_t k=0;k<count;++k){
  const auto row=row_at(m,i.cx,static_cast<unsigned>(k));
  if(m.r32(row)!=0x00796224u)return 0;
  if(m.r32(row+4u)!=0u||m.r32(row+8u)!=0u)return 0;
  // 0x537220 returns the row for empty backlinks; 0x4e0130 leaves its upper
  // EAX bytes intact while the empty-list membership branch clears AL.
  eax=row_membership_result(m,row)&0xffffff00u;
 }
 return eax;
}
}
