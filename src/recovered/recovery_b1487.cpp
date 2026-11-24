#include "recovered/recovery_b1487.hpp"
#include "recovered/construct_b102.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/decimal_text.hpp"
#include <string>
#include <array>
namespace ra2::recovered::b1487 { namespace {
using U=std::uint32_t;void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
std::string z(Memory&m,U a){std::string s;for(U k=0;k<128;++k){auto c=m.r8(a+k);if(!c)return s;s+=char(c);}throw std::domain_error("1487 bounded NUL");}
void sort_one(IniIndexEntry*,std::int32_t n,IniIndexKind,void*){need(n==1,"1487 actual qsort count1 return");}
std::int32_t upper(std::int32_t x,void*){return x>='a'&&x<='z'?x-32:x;}
// Logical views are explicitly assembled from the original binary graph. They
// are never reinterpret_cast to original classes. No missing callback result.
struct Graph {
 Memory&m;U p,s,node,rt,kt;std::string key,value;IniIndexEntry r{},k{};IniValue v{};IniKeyNode linked{},left{},right{};IniSection section{};IniIndex root{};
 Graph(Memory&mem,U a):m(mem),p(a){
  need(m.r32(p)==0x78db34&&m.r32(p+0x24)==1&&m.r32(p+0x28)==10,"1487 actual manager count/cap");rt=m.r32(p+0x20);s=m.r32(rt+4);kt=m.r32(s+0x2c);node=m.r32(kt+4);
  need(m.r32(s)==0x78eba4&&m.r32(node)==0x78eb9c&&m.r32(s+0x30)==1&&m.r32(s+0x34)==10,"1487 actual section/key graph");
  need(m.r32(s+0x18)==node&&m.r32(node+4)==s+0x20&&m.r32(node+8)==s+0x14,"1487 genuine linked row and sentinel roles");
  need(m.r8(p+0x2c)<=1&&m.r8(s+0x38)<=1&&(!m.r32(p+0x30)||m.r32(p+0x30)==rt)&&(!m.r32(s+0x3c)||m.r32(s+0x3c)==kt),"1487 one-row cache identity");
  key=z(m,m.r32(node+0xc));value=z(m,m.r32(node+0x10));need(key=="0"&&value=="TypeA0"&&z(m,m.r32(s+0xc))=="Tiberiums","1487 finite meaningful input");
  v.text=reinterpret_cast<const std::uint8_t*>(value.c_str());k={global_b26::s32(m.r32(kt)),&v};section.keys={&k,1,std::uint8_t(m.r8(s+0x38)),m.r32(s+0x3c)?&k:nullptr,10};linked={&right,&left,reinterpret_cast<const std::uint8_t*>(key.c_str())};section.first=&linked;r={global_b26::s32(m.r32(rt)),&section};root={&r,1,std::uint8_t(m.r8(p+0x2c)),m.r32(p+0x30)?&r:nullptr,10};
 }
 void flush(){m.w8(p+0x2c,root.sorted);m.w32(p+0x30,root.cached?rt:0);m.w8(s+0x38,section.keys.sorted);m.w32(s+0x3c,section.keys.cached?kt:0);}
};
std::int32_t classify(std::uint8_t c,U mask,void*x){auto&m=*static_cast<Memory*>(x);need(m.r32(0x81776c)==1&&m.r32(0x817560)==0x81756a,"1487 original singlebyte classification");return std::int32_t(m.r16(m.r32(0x817560)+2*c)&mask);}
}
U configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1487 explicit setter0");m.w32(0x817554,0);return 1;}
U fun_006de2b0(Memory&m,const Inputs&i,Heap&heap){
 need(m.r32(0x817554)==0,"1487 explicit ordinary CRT configuration");Graph graph(m,i.cx);const auto section=z(m,0x7e1d74);need(section=="Tiberiums","1487 original section literal");IniOperations op{ini_name_hash,sort_one,upper,nullptr,nullptr,nullptr};const auto*name=reinterpret_cast<const std::uint8_t*>(section.c_str());const U count=U(fun_0050bf50(&graph.root,name,op));graph.flush();need(count==1,"1487 positive one-entry import");
 std::array<std::uint8_t,0x200>scratch{};constexpr U localbase=0x7da00000;leaf::Memory local(scratch.data(),localbase,U(scratch.size()));Memory mm=m;mm.add(local);
 for(U ordinal=0;ordinal<count;++ordinal){const auto*key=fun_0050c250(&graph.root,name,std::int32_t(ordinal),op);graph.flush();need(key,"1487 produced key");const auto length=fun_0050ddf0(&graph.root,name,key,reinterpret_cast<const std::uint8_t*>(""),scratch.data()+0x10,24,op);graph.flush();need(length==6,"1487 produced nonempty TypeA0 name");DecimalOperations dec{classify,&m};const U index=fun_0076e73d(key,dec);need(index==0&&m.r32(0xaa8648)==0,"1487 real index>=zero count selects NEW constructor");
  const U owner=heap.allocate(296);need(owner,"1487 successful actual296 allocation");std::array<std::uint8_t,304>bytes{};for(U k=0;k<304;++k)bytes[k]=std::uint8_t(heap.r8(owner+k));leaf::Memory owned(bytes.data(),owner,304);Memory ctor=mm;ctor.add(owned);global_b26::Inputs child{};child.cx=owner;child.arg[0]=localbase+0x10;need(construct_b102::fun_006ddc60(ctor,child)==owner,"1487 unchanged real B102 result");
  // Actual798758+64 dispatches6DDFF0. Its firstcall4107E0 queries
  // object+24 using50BE00; absentdetailsection takes exact RET4/AL0 paths.
  // Do NOT call incompatible publictext_b104, which lacks this earlyguard.
  need(ctor.r32(owner)==0x798758&&m.r32(0x7987bc)==0x6ddff0,"1487 genuine reader vslot");const auto detail=z(ctor,owner+0x24);const auto*found=fun_0050be00(&graph.root,reinterpret_cast<const std::uint8_t*>(detail.c_str()),op);graph.flush();need(found==nullptr,"1487 actual missing optional detailsection");
  for(U k=0;k<304;++k)heap.w8(owner+k,bytes[k]);
 }
 // Real50BE00 miss sets entireEAX0; bothnestedXORAL preserve0;
 // root MOVAL1 therefore returns full1, with no pointerhighbits retained.
 return 1;
}
}
