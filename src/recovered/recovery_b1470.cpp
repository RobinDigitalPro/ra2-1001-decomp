#include "recovered/recovery_b1470.hpp"
#include <stdexcept>
namespace ra2::recovered::b1470 {
namespace {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
template<class M>void empty_ref(M&m,U self){m.w32(self,0x793cccu);m.w32(self+4u,0u);}
template<class D,class V>void assign_oldnull(D&dst,U self,V&values,U value){
 //630AD0 equality/nonnull-increment/oldnull publication, RET4.
 const U old=dst.r32(self+4u);need(old==0u,"1470 genuinely fresh refwrapper");
 if(value!=old){if(value)values.w32(value+4u,values.r32(value+4u)+1u);dst.w32(self+4u,value);}
}
void inner_owner(Memory&m,Heap&h,U wrapper,U input_wrapper){
 //71DA10: real16-byte owner, empty member-ref then assignment; no oldowner.
 const U object=h.allocate(16u);need(object!=0u,"1470 actual inner owner");
 h.w32(object+4u,0u);h.w32(object,0x793cd4u);empty_ref(h,object+8u);h.w32(object+8u,0x79a034u);
 need(m.r32(input_wrapper+4u)==0u,"1470 original metadata has no history member");
 assign_oldnull(h,object+8u,m,m.r32(input_wrapper+4u));h.w32(object,0x79a024u);
 empty_ref(m,wrapper);m.w32(wrapper,0x799ebcu);assign_oldnull(m,wrapper,h,object);
}
void four_refs(Memory&m,Heap&h,U self){
 //71BC00(self,4,null): successful allocated-array branch and four real630A80 calls.
 m.w32(self+4u,0u);m.w32(self+8u,4u);m.w8(self+0xcu,1u);m.w8(self+0xdu,0u);m.w32(self,0x799ec4u);
 const U array=h.allocate(36u);need(array!=0u,"1470 actual four-reference array");h.w32(array,4u);
 for(U k=0;k<4u;++k){empty_ref(h,array+4u+8u*k);h.w32(array+4u+8u*k,0x799e7cu);}
 m.w32(self+4u,array+4u);m.w8(self+0xdu,1u);
}
void clone_ansi(Memory&m,Heap&h,U output,U input){
 //7592C0 clears the fresh holder, then measures and copies the source includingNUL.
 m.w32(output,0u);const U src=m.r32(input);need(src!=0u,"1470 nonempty named inputholder");
 U length=0;while(m.r8(src+length)){need(length<15u,"1470 bounded ANSI name");++length;}
 need(length>0u,"1470 useful nonempty name");const U owner=h.allocate(length+1u);need(owner,"1470 actual ANSI owner");m.w32(output,owner);
 for(U k=0;k<=length;++k)h.w8(owner+k,m.r8(src+k));
}
struct LocalFile {
 //Only reached constructor-produced fields. Unread native local padding has no modelinput.
 U vptr,offset,length,handle,name,buffer,buffer_size;bool own_name,buffer_owned,buffer_active,buffer_dirty,available,search_override;
};
void optional_history(Memory&m,Heap&h,FileApi&api){
 //42F1F0 +46F930: every reached local read follows an explicit original store.
 LocalFile f{0x78773cu,0u,0xffffffffu,0xffffffffu,0u,0u,0u,false,false,false,false,false,false};
 f.vptr=0x785658u;
 need(m.r32(f.vptr+4u)==0x401940u&&m.r32(f.vptr+0x18u)==0x42f600u,"1470 actual CCFile virtual targets");
 //46FD50 ->42F550 ->630110 ->779146/775160/779010, fresh oldfilename0.
 need(f.name==0u&&!f.own_name,"1470 fresh CCFile filename");f.offset=0;f.length=0xffffffffu;
 constexpr char text[]="WDTHist.INI";
 for(U k=0;k<12u;++k)need(m.r8(0x7e4d9cu+k)==U(std::uint8_t(text[k])),"1470 original filename bytes");
 f.name=h.allocate(12u);need(f.name,"1470 actual temporary filename");for(U k=0;k<12u;++k)h.w8(f.name+k,m.r8(0x7e4d9cu+k));f.own_name=true;
 need(!f.search_override&&m.r32(0x838be0u)==0u,"1470 original no-searchpath projection");
 //42F5E0 ->630240(arg0=0). Actual42F600/630A70 returnclosed forFFFFFFFF.
 need(!f.available&&!f.buffer_active&&f.handle==0xffffffffu,"1470 constructor-produced closed file");
 const HANDLE handle=api.create_file_a(reinterpret_cast<const char*>(std::uintptr_t(f.name)),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
 f.handle=U(reinterpret_cast<std::uintptr_t>(handle));need(f.handle==0xffffffffu,"1470 genuine optional-history absence");
 //630240's XOR AL,AL yieldsFFFFFF00; root tests onlyAL. No fabricated API result.
 const U availability=f.handle&0xffffff00u;need((availability&0xffu)==0u,"1470 original availability branch");
 //42F250 and630060: empty buffer, actual closed-file query, then ownedname release.
 f.vptr=0x78773cu;need(f.buffer==0u&&!f.buffer_owned,"1470 no unproduced bufferowner");f.buffer_size=0;f.buffer_active=false;f.buffer_dirty=false;f.available=false;
 f.vptr=0x793c84u;need(m.r32(0x793c9cu)==0x630a70u&&f.handle==0xffffffffu,"1470 actual closed RawFile cleanup target");
 if(f.own_name&&f.name){(void)h.release(f.name);f.name=0;f.own_name=false;}f.vptr=0x793c3cu;
}
}
std::uint32_t configure_crt(Memory&m,const Inputs&i){if(i.arg[0]>1016u)return 0u;m.w32(0x817554u,i.arg[0]);return 1u;}
std::uint32_t fun_0071ab00(Memory&m,const Inputs&i,Heap&h,FileApi&api){
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1470 actual configured ordinary heap");
 const U self=i.cx,input=m.r32(i.arg[1]+4u);need(input&&m.r32(input)==0x79a1dcu&&m.r32(input+8u)==0x79a034u&&m.r32(input+0xcu)==0u,"1470 genuine metadata empty-member constructor projection");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  m.w32(self+4u,0u);m.w32(self,0x793cd4u);empty_ref(m,self+8u);m.w32(self+8u,0x799eb4u);assign_oldnull(m,self+8u,m,input);
  inner_owner(m,h,self+0x10u,input+8u);four_refs(m,h,self+0x18u);
  m.w32(self+0x18u,0x799e94u);m.w32(self+0x2cu,10u);m.w32(self+0x28u,0u);m.w32(self+0x44u,0u);clone_ansi(m,h,self+0x48u,i.arg[0]);
  m.w32(self,0x799e84u);for(U off:{0x34u,0x38u,0x3cu,0x40u})m.w32(self+off,0u);
  need(m.r32(input+0xcu)==0u,"1470 no prior history member");optional_history(m,h,api);
  //self+30,26/27 and all remaining raw receiver bytes are deliberately retained.
  i.fp.image=fp::capture_host();fp::restore_host(host);return self;
 }catch(...){fp::restore_host(host);throw;}
}
}
