#include "recovery_b838.hpp"
#include "recovered/recovery_b481.hpp"
#include "recovered/recovery_b342.hpp"
#include "recovered/name_hash.hpp"
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b838 {
namespace {
using U=std::uint32_t;
[[noreturn]] void bad(const char*s){throw std::domain_error(s);}
void need(bool b,const char*s){if(!b)bad(s);}
U hash(const char*s){return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s),std::char_traits<char>::length(s),nullptr);}
std::int32_t shash(U h){return h<=0x7fffffffu?static_cast<std::int32_t>(h):-1-static_cast<std::int32_t>(0xffffffffu-h);}
std::string zstr(const Memory&m,U p,U cap=128){need(p,"B838 null bounded string");std::string s;for(U k=0;k<cap;++k){auto c=static_cast<char>(m.r8(p+k));if(!c)return s;s.push_back(c);}bad("B838 unterminated bounded string");}
U section_row(const Memory&m,U ini,const char* name){const U table=m.r32(ini+0x20u),count=m.r32(ini+0x24u),wanted=static_cast<U>(shash(hash(name)));for(U k=0;k<count;++k)if(m.r32(table+8u*k)==wanted)return table+8u*k;bad("B838 required original INI section is absent");}
void verify_named_entry(const Memory&m,U ini,const char*outer){const U row=section_row(m,ini,outer),section=m.r32(row+4u),node=m.r32(section+0x18u);need(node,"B838 outer section has no linked key");const U name=m.r32(node+0x0cu);need(zstr(m,name)=="unit","B838 bounded outer key must name unit");const U ki=section+0x2cu,table=m.r32(ki),count=m.r32(ki+4u);need(count==1u,"B838 contract requires one outer key");const U val=m.r32(table+4u),text=m.r32(val+0x10u);need(zstr(m,text)=="unit","B838 bounded outer value must resolve to unit");}
U object_in(const Memory&m,U table,U count,U vptr,U target){for(U k=0;k<count;++k){U obj=m.r32(table+4u*k);if(obj&&zstr(m,obj+0x24u)=="unit"){need(m.r32(obj)==vptr,"B838 matching object has an unexpected original vptr");need(m.r32(vptr+0x64u)==target,"B838 pinned original vslot target changed");return obj;}}bad("B838 exact original registry lacks matching unit object");}
U call_with_unit_view(Memory&m,U ini,U unitrow,U object,bool first,U status){const U root=ini+0x20u,oldtable=m.r32(root),oldcount=m.r32(root+4u),oldcap=m.r32(root+8u),oldflags=m.r32(root+12u);m.w32(root,unitrow);m.w32(root+4u,1u);m.w32(root+8u,1u);m.w8(root+12u,1u);m.w32(root+16u,0u);Inputs cb{};cb.cx=object;cb.arg[0]=ini;cb.dx=status;const U result=first?recovery_b481::fun_004651f0(m,cb):recovery_b342::fun_0065fbc0(m,cb);const U cache=m.r32(root+16u);m.w32(root,oldtable);m.w32(root+4u,oldcount);m.w32(root+8u,oldcap);m.w32(root+12u,oldflags);m.w32(root+16u,cache?unitrow:0u);return result;}
}
std::uint32_t fun_00465320(Memory&m,const Inputs&i){const U ini=i.cx;verify_named_entry(m,ini,"Battles");const U unitrow=section_row(m,ini,"unit");const U obj=object_in(m,m.r32(0x00a1e094u),m.r32(0x00a1e0a0u),0x7886a0u,0x4651f0u);need(m.r32(obj)==0x7886a0u&&m.r32(0x788704u)==0x4651f0u,"B838 original Battles vslot");return call_with_unit_view(m,ini,unitrow,obj,true,0u);}
std::uint32_t fun_0065fc90(Memory&m,const Inputs&i){const U ini=i.cx;verify_named_entry(m,ini,"ScriptTypes");const U unitrow=section_row(m,ini,"unit");const U obj=object_in(m,m.r32(0x0084e58cu),m.r32(0x0084e598u),0x794260u,0x65fbc0u);need(m.r32(obj)==0x794260u&&m.r32(0x7942c4u)==0x65fbc0u,"B838 original ScriptTypes vslot");const U result=call_with_unit_view(m,ini,unitrow,obj,false,i.dx);m.w32(obj+0x9cu,i.dx);return result;}
}
