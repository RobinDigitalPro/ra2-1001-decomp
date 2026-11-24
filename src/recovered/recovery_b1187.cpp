#include "recovery_b1187.hpp"
#include "recovered/name_hash.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1187{
static void need(bool x){if(!x)throw std::domain_error("1187 exact positive one-key INI type publication");}
static std::string owned(Heap&h,unsigned p){std::string s;for(unsigned k=0;k<64u;++k){const auto c=h.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("1187 bounded owned ASCII input");}
static std::string record(Memory&m,unsigned p){std::string s;for(unsigned k=0;k<25u;++k){const auto c=m.r8(p+k);if(!c)return s;s+=char(c);}throw std::domain_error("1187 actual410580 bounded name");}
static unsigned hash(const std::string&s){return ini_name_hash(reinterpret_cast<const unsigned char*>(s.data()),s.size(),nullptr);}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,State&){const bool enable=root==0x1d540u;need(enable||root==0x2b51f0u);need(i.dx==(enable?0u:1u));if(!enable)need(i.cx==0x821ae0u);const auto ini=i.cx,row=m.r32(ini+48u);need(m.r32(ini)==0x78db34u&&m.r32(ini+36u)==1u&&m.r8(ini+44u)==1u&&row==m.r32(ini+32u));const auto section=h.r32(row+4u);need(h.r32(section)==0x78eba4u&&h.r32(section+48u)==1u&&h.r8(section+56u)==1u);const auto section_name=owned(h,h.r32(section+12u));need(section_name==(enable?"AITriggerTypesEnable":"TeamTypes")&&h.r32(row)==hash(section_name));
 //1D540 firstactual50BF50 lookup misses the genuinely absent AITriggerTypes section.
 //The1-entry signed search returns0 without replacing the warm cache on a miss.
 if(enable)need(hash("AITriggerTypes")!=h.r32(row));
 const auto kr=h.r32(section+60u);need(kr==h.r32(section+44u));const auto node=h.r32(kr+4u);need(h.r32(node)==0x78eb9cu);const auto key=owned(h,h.r32(node+12u)),value=owned(h,h.r32(node+16u));need(h.r32(kr)==hash(key));const auto wanted=enable?key:value;need(enable?(key=="TriggerA"||key=="TriggerB"):(key=="0"&&(value=="TeamA"||value=="TeamB")));
 const auto g=enable?0xa25590u:0xa28888u;need(m.r32(g)==(enable?0x78d0a4u:0x78d624u)&&m.r32(g+8u)==10u&&m.r32(g+16u)==2u&&m.r8(g+13u)==1u);const auto entries=m.r32(g+4u);unsigned found=0u;for(unsigned k=0;k<2u;++k){const auto q=h.r32(entries+4u*k);if(record(m,q+36u)==wanted){found=q;break;}}need(found!=0u);
 if(enable){need(m.r8(found+164u)==0u&&value.size()==1u&&m.r32(0xb10530u)==0u);unsigned c=static_cast<unsigned char>(value[0]);if(c>='a'&&c<='z')c-=32u;need(c=='1'||c=='Y'||c=='T'); //Actual76E313 fastC-uppercase +50E9E0/EC true jump-table entries.
  m.w8(found+164u,1u);return 1u; //Finalactualsectionkeycount reload, fullDWORD.
 }
 //True797898+64 target6B4980 calls4107E0. No[TeamA/B] detail section exists:
 //50BE00 1-entry miss XORs fullEAX0; both AL-only false epilogues preserve0.
 need(m.r32(found)==0x797898u&&m.r32(0x7978fcu)==0x6b4980u&&hash(wanted)!=h.r32(row)&&m.r32(found+224u)==0u);m.w32(found+224u,i.dx);return 0u;
}
unsigned cleanup(unsigned root,Memory&m,Heap&h,unsigned ini){need(root==0x1d540u||root==0x2b51f0u);const auto globalindex=m.r32(ini+32u),section=h.r32(globalindex+4u),sectionname=h.r32(section+12u),keyindex=h.r32(section+44u),node=h.r32(keyindex+4u),keyname=h.r32(node+12u),value=h.r32(node+16u),registry=m.r32((root==0x1d540u?0xa25590u:0xa28888u)+4u);unsigned result=0u;for(auto p:{sectionname,keyname,value,node,keyindex,section,globalindex,registry}){result=h.release(p);need(result!=0u);}return result;}
}
