#include "recovered/recovery_b1635.hpp"
#include <stdexcept>
#include "recovered/name_hash.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1635 {
namespace {
void need(bool b){if(!b)throw std::domain_error("1635 finite Scenario-only constructor draft");}
std::string guest(const Memory&m,U p){need(p!=0);std::string z;for(U k=0;k<32;++k){U c=m.r8(p+k);if(!c)return z;need(c>=32&&c<=126);z+=char(c);}need(false);return {};}
std::string bytes(const Heap&h,U p){need(p!=0);std::string z;for(U k=0;k<32;++k){U c=h.r8(p+k);if(!c)return z;z+=char(c);}need(false);return {};}
U clone(Heap&h,const std::string&z){U p=h.allocate(U(z.size()+1));need(p!=0);h.w8(p,0);for(U k=0;k<z.size();++k)h.w8(p+k,U((unsigned char)z[k]));h.w8(p+U(z.size()),0);return p;}
void drop(Heap&h,U&p){if(p){need(h.release(p)!=0);p=0;}}
void assign(Heap&h,U&p,const std::string&z){drop(h,p);p=clone(h,z);}
void field(Memory&m,Heap&h,U at,const std::string&z){U p=m.r32(at);assign(h,p,z);m.w32(at,p);}
// Actual one-row sorted/warm INI projection, as authored by the normal
// B1624 parser graph. No external provider/callback result is substituted.
U name_hash(const std::string&z){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(z.data()),z.size(),nullptr);}
bool lookup(Memory&m,U ini,U section_holder,const char*key,std::string&value){
 need(m.r32(ini)==0x785ae4&&m.r32(ini+4)==0x785aec&&m.r32(ini+8)==0x785afc);
 const std::string section=guest(m,m.r32(section_holder));
 const U section_hash=name_hash(section),key_hash=name_hash(key);
 const U sections=m.r32(ini+0x20);need(sections&&m.r32(ini+0x24)==1&&m.r8(ini+0x2c)==1&&m.r32(ini+0x30)==sections);
 need(m.r32(sections)==section_hash);
 const U object=m.r32(sections+4);need(object!=0);
 const U keys=m.r32(object+0x2c);need(keys&&m.r32(object+0x30)==1&&m.r8(object+0x38)==1&&m.r32(object+0x3c)==keys);
 need(m.r32(keys)==name_hash("Scenario"));
 // 5105A0's signed one-element search returns null for every unequal hash.
 // A miss leaves the previously valid cache unchanged. These full warm
// public graphs are preserved, rather than normalized after the operation.
 if(m.r32(keys)!=key_hash){value.clear();return false;}
 const U node=m.r32(keys+4);need(node!=0);value=guest(m,m.r32(node+0x10));
 need(value=="Profile000");return true;
}
std::string decimal(U n){need(n<=255);char a[4];U len=0;do{a[len++]=char('0'+n%10);n/=10;}while(n);std::string z;while(len)z+=a[--len];return z;}
// Whole75AFF0/759640 selected nonnull-prefix/nonnull-numeric-holder route.
U text_key(Heap&h,U number){U prefix=clone(h,"Text"),work=clone(h,bytes(h,prefix));U joined=clone(h,bytes(h,work)+bytes(h,number));drop(h,work);work=joined;U out=clone(h,bytes(h,work));drop(h,work);drop(h,prefix);return out;}
}
U fun_005ad600(Memory&m,const Inputs&i,Heap&h){
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();
 try{fp::restore_host(i.fp.image);
 need(i.cx&&i.arg[0]&&i.arg[1]);const U self=i.cx,source=i.arg[0],section=i.arg[1];need(guest(m,m.r32(section))=="Profile001");(void)m.r8(self+0x6b);
 // Only constructor-authored fields. Opaque padding remains untouched.
 for(U off:{0u,4u,8u,12u,16u,24u,28u,32u})m.w32(self+off,0);
 for(U k=0;k<3;++k){const U at=self+0x24+0x18*k;m.w32(at,0x791f7c-0x20*k);m.w32(at+4,0);m.w32(at+8,0);m.w8(at+12,1);m.w8(at+13,0);m.w32(at+16,0);m.w32(at+20,10);}
 // 759570 fresh destination copies the section holder; 759500(NULL) allocates1.
 field(m,h,self,guest(m,m.r32(section)));field(m,h,self+4,"");U result=0;
 auto query=[&](U fallback,U key){std::string value;const std::string name=bytes(h,key);bool hit=lookup(m,source,section,name.c_str(),value);need(hit==(name=="Scenario"));if(hit)need(value=="Profile000");else{need(value.empty());value=bytes(h,fallback);}assign(h,result,value);return U(value.size());};
 auto fixed=[&](const char*key){U fallback=clone(h,""),name=clone(h,key);U n=query(fallback,name);drop(h,name);drop(h,fallback);return n;};
 need(fixed("Scenario")==10);field(m,h,self+4,bytes(h,result));
 // 75B4B0(NULL): real2-byte UTF16 allocation, not a null holder.
 U wide=h.allocate(2);need(wide);h.w8(wide,0);h.w8(wide+1,0);m.w32(self+16,wide);need(fixed("Description")==0);
 field(m,h,self+12,"");need(fixed("VoiceOver")==0);field(m,h,self+8,"");need(fixed("MapVQ")==0);
 m.w32(self+20,0);field(m,h,self+24,"");field(m,h,self+28,"");need(fixed("Overlays")==0);
 field(m,h,self+32,"");need(fixed("ClickMap")==0);
 for(U n=1;n<8;++n){U fallback=clone(h,""),number=clone(h,decimal(n)),key=text_key(h,number);need(query(fallback,key)==0);drop(h,key);drop(h,number);drop(h,fallback);}
 need(fixed("Targets")==0);
 for(U n=0;n<256;++n){U fallback=clone(h,""),key=clone(h,decimal(n));need(query(fallback,key)==0);drop(h,key);drop(h,fallback);}
 drop(h,result);i.fp.image=fp::capture_host();fp::restore_host(host);return self;
 }catch(...){fp::restore_host(host);throw;}
}
}
