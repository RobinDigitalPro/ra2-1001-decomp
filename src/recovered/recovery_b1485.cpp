#include "recovered/recovery_b1485.hpp"
#include "recovered/recovery_b626.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/lookup_b92.hpp"
#include <string>
#include <array>
namespace ra2::recovered::b1485 { namespace {
using U=std::uint32_t;void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
std::string z(Memory&m,U a){std::string s;for(U k=0;k<128;++k){auto c=m.r8(a+k);if(!c)return s;s+=char(c);}throw std::domain_error("1485 bounded NUL");}
void sort_one(IniIndexEntry*,std::int32_t n,IniIndexKind,void*){need(n==1,"1485 actual qsort count1 return");}
std::int32_t upper(std::int32_t x,void*){return x>='a'&&x<='z'?x-32:x;}
// Logical views are explicitly assembled from the original binary graph. They
// are never reinterpret_cast to original classes. No missing callback result.
struct Graph {
 Memory&m;U p,s,node,rt,kt;std::string key,value;IniIndexEntry r{},k{};IniValue v{};IniKeyNode linked{},left{},right{};IniSection section{};IniIndex root{};
 Graph(Memory&mem,U a):m(mem),p(a){
  need(m.r32(p)==0x78db34&&m.r32(p+0x24)==1&&m.r32(p+0x28)==10,"1485 actual manager count/cap");rt=m.r32(p+0x20);s=m.r32(rt+4);kt=m.r32(s+0x2c);node=m.r32(kt+4);
  need(m.r32(s)==0x78eba4&&m.r32(node)==0x78eb9c&&m.r32(s+0x30)==1&&m.r32(s+0x34)==10,"1485 actual section/key graph");
  need(m.r32(s+0x18)==node&&m.r32(node+4)==s+0x20&&m.r32(node+8)==s+0x14,"1485 genuine linked row and sentinel roles");
  need(m.r8(p+0x2c)<=1&&m.r8(s+0x38)<=1&&(!m.r32(p+0x30)||m.r32(p+0x30)==rt)&&(!m.r32(s+0x3c)||m.r32(s+0x3c)==kt),"1485 one-row cache identity");
  key=z(m,m.r32(node+0xc));value=z(m,m.r32(node+0x10));need(key=="0"&&value=="TypeA0"&&z(m,m.r32(s+0xc))=="Terrain","1485 finite meaningful input");
  v.text=reinterpret_cast<const std::uint8_t*>(value.c_str());k={global_b26::s32(m.r32(kt)),&v};section.keys={&k,1,std::uint8_t(m.r8(s+0x38)),m.r32(s+0x3c)?&k:nullptr,10};linked={&right,&left,reinterpret_cast<const std::uint8_t*>(key.c_str())};section.first=&linked;r={global_b26::s32(m.r32(rt)),&section};root={&r,1,std::uint8_t(m.r8(p+0x2c)),m.r32(p+0x30)?&r:nullptr,10};
 }
 void flush(){m.w8(p+0x2c,root.sorted);m.w32(p+0x30,root.cached?rt:0);m.w8(s+0x38,section.keys.sorted);m.w32(s+0x3c,section.keys.cached?kt:0);}
};
std::int32_t classify(std::uint8_t c,U mask,void*x){auto&m=*static_cast<Memory*>(x);need(m.r32(0x81776c)==1&&m.r32(0x817560)==0x81756a,"1485 original singlebyte classification");return std::int32_t(m.r16(m.r32(0x817560)+2*c)&mask);}
}
U configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1485 explicit setter0");m.w32(0x817554,0);return 1;}
U fun_006d9520(Memory&m,const Inputs&i,Heap&heap){
 need(m.r32(0x817554)==0&&m.r32(0xb10530)==0,"1485 real CRT and ASCII mode");need(m.r16(0xaa7e70)==0&&m.r16(0xaa7e72)==0&&m.r32(0xa255c0)==0,"1485 exact original zero descriptor and handle domain");
 Graph graph(m,i.cx);const auto section=z(m,m.r32(0x798238));need(section=="Terrain","1485 pinned section literal");IniOperations op{ini_name_hash,sort_one,upper,nullptr,nullptr,nullptr};const auto*name=reinterpret_cast<const std::uint8_t*>(section.c_str());const U count=U(fun_0050bf50(&graph.root,name,op));graph.flush();need(count==1,"1485 actual one-entry query");
 std::array<std::uint8_t,0x200>scratch{};constexpr U stackbase=0x7da00000;leaf::Memory local(scratch.data(),stackbase,U(scratch.size()));Memory mm=m;mm.add(local);
 for(U ordinal=0;ordinal<count;++ordinal){const auto*key=fun_0050c250(&graph.root,name,std::int32_t(ordinal),op);graph.flush();need(key,"1485 actual nonempty enumeration");const auto n=fun_0050ddf0(&graph.root,name,key,reinterpret_cast<const std::uint8_t*>(""),scratch.data()+0x20,128,op);graph.flush();need(n==6,"1485 real bounded TypeA0 copy");
  lookup_b92::Inputs lookup{};lookup.cx=stackbase+0x20;const U type=lookup_b92::fun_006dace0(mm,lookup);need(type,"1485 genuine registry name hit");DecimalOperations dec{classify,&m};const U packed=fun_0076e73d(key,dec);need(packed==0,"1485 genuine enumerated zero coordinate");U coord;
  if(global_b26::s32(m.r32(0xa28964))>=4){const auto value=global_b26::s32(packed);coord=(U(value%1000)&0xffffu)|(U(value/1000)<<16);}else{const auto value=global_b26::s32(packed);coord=(U(value%128)&0xffffu)|(U(value/128)<<16);}mm.w32(stackbase+0x10,coord);
  const U owner=heap.allocate(200);need(owner,"1485 actual successful allocation");std::array<std::uint8_t,208>bytes{};for(U k=0;k<208;++k)bytes[k]=std::uint8_t(heap.r8(owner+k));leaf::Memory owned(bytes.data(),owner,208);Memory ctor=mm;ctor.add(owned);Inputs child=i;child.cx=owner;child.arg[0]=type;child.arg[1]=stackbase+0x10;
  // Proven root S-A8 allocator, nested CALL at76D95D -> S-B4=ctorE-8.
  // This translates produced caller history; native bridge seeds no privateword.
  child.stack_minus8=0x76d962;need(recovery_b626::fun_006d8690(ctor,child)==owner,"1485 genuine B626 result");for(U k=0;k<208;++k)heap.w8(owner+k,bytes[k]);
 }
 return count;
}
}
