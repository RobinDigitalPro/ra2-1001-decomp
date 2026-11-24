#include "recovered/recovery_b915.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/recovery_b381.hpp"
#include "platform/current_crt_thread.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::recovery_b915 {
namespace {
using U=std::uint32_t;
using FInputs=ra2::recovered::floating_b61::Inputs;
void need(bool ok,const char* what){if(!ok)throw std::domain_error(what);}
std::string text(const Memory&m,U p,U limit=512){need(p!=0,"915 nonnull text");std::string s;for(U k=0;k<limit;++k){const auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("915 bounded NUL text");}
U hash(const std::string&s){return ra2::recovered::ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()),s.size(),nullptr);}
struct Reader {
 Memory&m;U ini,root,section,key_index,section_row;
 Reader(Memory&mm,U i):m(mm),ini(i),root(i+0x20u),section(0),key_index(0),section_row(0){
  const U nodes=m.r32(root);const U count=m.r32(root+4u);need(nodes&&count==1&&m.r8(root+12u)!=0,"915 one initialized sorted section");
  const U wanted=hash("no events");need(m.r32(nodes)==wanted,"915 no events section hash");section_row=nodes;section=m.r32(nodes+4u);need(section!=0,"915 section node");key_index=section+0x2cu;
  m.w32(root+0x10u,section_row);
 }
 U value_node(const std::string&key){
  const U nodes=m.r32(key_index),count=m.r32(key_index+4u);need(nodes&&count>=1&&count<=32&&m.r8(key_index+12u)!=0,"915 initialized key index");
  const auto wanted=static_cast<std::int32_t>(hash(key));U lo=0,hi=count;
  while(lo<hi){const U mid=lo+(hi-lo)/2;const auto got=static_cast<std::int32_t>(m.r32(nodes+mid*8u));if(got<wanted)lo=mid+1;else hi=mid;}
  need(lo<count&&m.r32(nodes+lo*8u)==static_cast<U>(wanted),"915 required positive INI key");
  const U row=nodes+lo*8u;m.w32(key_index+0x10u,row);return m.r32(row+4u);
 }
 std::string str(const std::string&key){const U node=value_node(key);const U p=m.r32(node+0x10u);need(p!=0,"915 string value pointer");return text(m,p,1024);}
 U integer(const std::string&key){const auto s=str(key);need(!s.empty(),"915 decimal field nonempty");U n=0;unsigned at=0;bool neg=false;if(s[at]=='+'||s[at]=='-'){neg=s[at++]=='-';}need(at<s.size(),"915 decimal digits");for(;at<s.size();++at){const auto c=static_cast<unsigned char>(s[at]);need(c>='0'&&c<='9',"915 decimal-only integer");const U d=c-'0';need(n<=(0x7fffffffu-d)/10u,"915 positive signed integer bounds");n=n*10u+d;}return neg?0u-n:n;}
};
void enum_single(Memory&m,U dst,const std::string&s){
 static const std::map<std::string,U> t{{"LOWEST",0},{"LOW",1},{"NORMAL",2},{"HIGH",3},{"CRITICAL",4}};
 const auto it=t.find(s);need(it!=t.end(),"915 priority table member");m.w32(dst,it->second);
}
U bit_tokens(const std::string&s,const std::map<std::string,U>&table){
 U result=0;std::size_t at=0;while(at<s.size()){while(at<s.size()&&(s[at]==' '||s[at]=='\t'||s[at]=='\n'))++at;if(at==s.size())break;auto end=at;while(end<s.size()&&s[end]!=' '&&s[end]!='\t'&&s[end]!='\n')++end;const auto it=table.find(s.substr(at,end-at));need(it!=table.end(),"915 token table entry");result|=it->second;at=end;}return result;
}
void update_control(Memory&m,U p,U rate){
 // Exact finite 0x407080 / 0x4070f0 route: initialized flag bit 0 avoids 0x4092d0.
 m.w32(p,m.r32(p)|1u);m.w32(p+8u,rate<<16u);
 const U end=m.r32(p+8u),cur=m.r32(p+4u);
 if(end!=cur&&(m.r8(p)&1u)){m.w32(p+4u,end);m.w32(p,m.r32(p)|2u);}
}
}
std::uint32_t fun_00708490(Memory&m,const Inputs&i,U entry_esp){
 const U self=i.cx,ini=i.arg[0];need(self&&ini,"915 receiver/INI positive route");const U owner=m.r32(self);need(owner!=0,"915 original [ESI] subobject pointer gate");need(m.r32(0x8192f8u)==0,"915 original no events section selector");
 Reader r(m,ini);
 const auto sounds=r.str("Sounds");need(sounds.empty(),"915 bounded no-list allocation route requires empty Sounds");
 const auto volume_default=m.r32(0x7e32d8u);need(volume_default==0x42a00000u,"915 pinned Volume fallback");
 FInputs vol;vol.cx=ini;vol.arg[0]=0x7b7c64u;vol.arg[1]=0x7e3398u;vol.arg[2]=0;vol.arg[3]=0;vol.fp=i.fp;
 (void)ra2::recovered::recovery_b381::fun_0050d7f0(m,vol);i.fp=vol.fp;
 // 0x708550 FMUL 0.01; both comparisons choose the strict positive interior path.
 i.fp.multiply32(m.r32(0x790dd0u));i.fp.compare32(0x3f800000u);const auto sw1=i.fp.waiting_status();
 const bool above_one=(sw1&0x4100u)==0;
 if(above_one){i.fp.pop_st0();i.fp.load32(m.r32(0x7867f8u));}
 i.fp.compare32(0);const auto sw2=i.fp.waiting_status();const bool not_positive=(sw2&0x0100u)!=0 || (sw2&0x4000u)!=0;
 if(not_positive){i.fp.pop_st0();i.fp.load32(0u);}
 i.fp.multiply32(m.r32(0x79276cu));const U cw=m.r16(0x7c3a04u);if(i.fp.control()!=cw)i.fp.load_control(static_cast<std::uint16_t>(cw));const U rate=static_cast<U>(i.fp.pop_integer64());
 update_control(m,owner+0x18u,rate);
 // VShift is a signed integer clamped by the exact leaf helper 0x406630.
 const U vshift=r.integer("VShift");m.w32(owner+0x68u,static_cast<std::int32_t>(vshift)>100?100:vshift);
 // MinVolume's accepted %f parser leaves one value in ST0; the root stores
 // the clamped float32 result at +0x54 after the original compare sequence.
 FInputs minv;minv.cx=ini;minv.arg[0]=0x7b7c64u;minv.arg[1]=0x7e3384u;minv.arg[2]=0;minv.arg[3]=0;minv.fp=i.fp;
 (void)ra2::recovered::recovery_b381::fun_0050d7f0(m,minv);i.fp=minv.fp;
 i.fp.multiply32(m.r32(0x790dd0u));U fbits=i.fp.store32();i.fp.compare_pop64(0x3ff0000000000000ull);const auto sw3=i.fp.waiting_status();
 const bool above_one_again=(sw3&0x4100u)==0;
 if(above_one_again)fbits=m.r32(0x7867f8u);
 else {i.fp.load32(fbits);i.fp.compare_pop32(0);const auto sw4=i.fp.waiting_status();if((sw4&0x0100u)!=0||(sw4&0x4000u)!=0)fbits=0u;}
 m.w32(owner+0x54u,fbits);
 const U priority_node=r.value_node("Priority");const auto priority=text(m,m.r32(priority_node+0x10u),32);enum_single(m,owner+0x40u,priority);
 const U attack=r.integer("Attack");m.w32(owner+0x138u,attack);
 const U decay=r.integer("Decay");m.w32(owner+0x13cu,decay);
 const auto control=r.str("Control");
 static const std::map<std::string,U> control_bits{{"ALL",4},{"LOOP",1},{"RANDOM",2},{"PREDELAY",8},{"INTERRUPT",0x10},{"ATTACK",0x20},{"DECAY",0x40},{"AMBIENT",0x80}};
 const U flags=bit_tokens(control,control_bits);m.w32(owner+0x10u,flags);if(flags&0x20u)m.w32(owner+0x138u,m.r32(owner+0x138u)==0?1:m.r32(owner+0x138u));else m.w32(owner+0x138u,0);if(flags&0x40u)m.w32(owner+0x13cu,m.r32(owner+0x13cu)==0?1:m.r32(owner+0x13cu));else m.w32(owner+0x13cu,0);
 // Original order places the two integer writes after the Control parse.
 const auto type=r.str("Type");static const std::map<std::string,U> type_bits{{"AMBIENT",0x1000},{"VIOLENT",1},{"MOVEMENT",2},{"QUIET",4},{"LOUD",8},{"GLOBAL",0x10},{"SCREEN",0x20},{"LOCAL",0x40},{"PLAYER",0x80},{"NORMAL",0},{"GUN_SHY",0x200},{"NOISE_SHY",0x100},{"UNSHROUD",0x400},{"SHROUD",0x800}};m.w32(owner+0x14u,0x20u|bit_tokens(type,type_bits));
 m.w32(owner+0x48u,r.integer("Limit"));m.w32(owner+0x4cu,r.integer("Loop"));m.w32(owner+0x50u,r.integer("Range"));
 auto parse_pair=[&](const std::string&value){
  std::size_t a=0;while(a<value.size()&&(value[a]==' '||value[a]=='\t'||value[a]=='\n'))++a;
  auto b=a;while(b<value.size()&&value[b]!=' '&&value[b]!='\t'&&value[b]!='\n')++b;need(b>a,"915 pair first integer");
  auto c=b;while(c<value.size()&&(value[c]==' '||value[c]=='\t'||value[c]=='\n'))++c;
  auto d=c;while(d<value.size()&&value[d]!=' '&&value[d]!='\t'&&value[d]!='\n')++d;need(d>c,"915 pair second integer");
  auto number=[](const std::string&v,std::size_t x,std::size_t y){U n=0;for(auto k=x;k<y;++k){need(v[k]>='0'&&v[k]<='9',"915 pair decimal");n=n*10u+U(v[k]-'0');}return n;};
  return std::array<U,2>{number(value,a,b),number(value,c,d)};
 };
 const auto delay=parse_pair(r.str("Delay"));m.w32(owner+0x58u,delay[0]);m.w32(owner+0x5cu,delay[1]);
 const auto fshift_text=r.str("FShift");const auto fshift=parse_pair(fshift_text);m.w32(owner+0x60u,fshift[0]);m.w32(owner+0x64u,fshift[1]);
 // Original 0x76e802 obtains the actual CRT thread object through the TLS
 // slot at 0x817778. Its final token cursor points at the NUL ending the
 // second FShift number, in the root's local buffer at entry_esp-0x800.
 const U thread=ra2::platform::current_crt_thread(m.r32(0x817778u));
 m.w32(thread+0x18u,entry_esp-0x800u+U(fshift_text.size()));
 return (fshift[1]&0xffffff00u)|1u;
}
}
