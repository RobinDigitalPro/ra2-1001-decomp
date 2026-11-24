#include "recovered/recovery_b871.hpp"
#include <string>
#include <stdexcept>
namespace ra2::recovered::recovery_b871 {
namespace {using Memory=global_b26::Memory;using Heap=platform::ordinary_heap::Heap;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
std::string z(const Memory&m,unsigned p){need(p,"871 nonnull string");std::string s;for(unsigned k=0;k<128;++k){auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("871 bounded string");}
void put(Memory&m,unsigned p,const std::string&s){for(unsigned k=0;k<s.size();++k)m.w8(p+k,static_cast<unsigned char>(s[k]));m.w8(p+unsigned(s.size()),0);}
enum class Kind{Inline,Integer,Boolean,House,Linked,Waypoint};
struct Field{unsigned key,offset;Kind kind;const char*text;};
constexpr Field fields[]={{0x7b9234,0x64,Kind::Inline,"Name"},
{0x7b922c,0x3d,Kind::Inline,"UIName"},
{0x7e0984,0xa0,Kind::Integer,"VeteranLevel"},
{0x7e0978,0xa4,Kind::Boolean,"Loadable"},
{0x7e0970,0xa5,Kind::Boolean,"Full"},
{0x7e0964,0xa6,Kind::Boolean,"Annoyance"},
{0x7e0958,0xa7,Kind::Boolean,"GuardSlower"},
{0x7b8dd0,0xc0,Kind::House,"House"},
{0x7e090c,0xa8,Kind::Boolean,"Recruiter"},
{0x7e094c,0xa9,Kind::Boolean,"Autocreate"},
{0x7e0940,0xaa,Kind::Boolean,"Prebuild"},
{0x7e0934,0xab,Kind::Boolean,"Reinforce"},
{0x7e092c,0xb0,Kind::Boolean,"Droppod"},
{0x7e0918,0xb1,Kind::Boolean,"UseTransportOrigin"},
{0x7e0904,0xac,Kind::Boolean,"Whiner"},
{0x7e08ec,0xae,Kind::Boolean,"LooseRecruit"},
{0x7e08e0,0xad,Kind::Boolean,"Aggressive"},
{0x7e08fc,0xaf,Kind::Boolean,"Suicide"},
{0x7e08c8,0xb4,Kind::Integer,"Priority"},
{0x7e08c4,0xb8,Kind::Integer,"Max"},
{0x7c5944,0xc4,Kind::Integer,"TechLevel"},
{0x7e063c,0x9c,Kind::Integer,"Group"},
{0x7e08d4,0xb3,Kind::Boolean,"OnTransOnly"},
{0x7e08b4,0xea,Kind::Boolean,"AvoidThreats"},
{0x7e08a8,0xeb,Kind::Boolean,"IonImmune"},
{0x7e0874,0xec,Kind::Boolean,"TransportsReturnOnUnload"},
{0x7e0858,0xed,Kind::Boolean,"AreTeamMembersRecruitable"},
{0x7bbbcc,0xee,Kind::Boolean,"IsBaseDefense"},
{0x7e0890,0xef,Kind::Boolean,"OnlyTargetHouseEnemy"},
{0x7b8c74,0xc8,Kind::Linked,"Tag"},
{0x7b8c2c,0xcc,Kind::Waypoint,"Waypoint"},
{0x7e0844,0xd0,Kind::Waypoint,"TransportWaypoint"},
{0x7b8d30,0xd8,Kind::Linked,"Script"},
{0x7b8ce4,0xdc,Kind::Linked,"TaskForce"}};
std::string waypoint(unsigned v){need(v<=701,"871 bounded nonnegative waypoint");if(v<26)return std::string(1,char(v+65));return std::string(1,char(v/26+64))+char(v%26+65);}
}
std::uint32_t serialize_child(Memory&m,const global_b26::Inputs&i,const SerializerCase&c,Heap&h){
 need(i.cx==c.object&&i.arg[0]==c.ini_root,"871 original thiscall arguments");
 auto o=c.object,section=o+0x24;need(!z(m,section).empty(),"871 positive inline section");
 need(m.r32(c.ini_root+0x24)==2&&m.r32(c.ini_root+0x28)==10&&m.r8(c.ini_root+0x2c)==0,"871 bounded Settings plus new TeamTypes root");
 need(!probe_section(m,h,c.ini_root,section),"871 original clear lookup finds absent target");
 for(const auto&f:fields){need(z(m,f.key)==f.text,"871 binary key literal");std::string value;
  switch(f.kind){
   case Kind::Inline:if(f.offset==0x3d&&!m.r8(o+f.offset))continue;value=z(m,o+f.offset);break;
   case Kind::Integer:value=std::to_string(global_b26::s32(m.r32(o+f.offset)));break;
   case Kind::Boolean:value=m.r8(o+f.offset)?"yes":"no";break;
   case Kind::House:need(m.r32(o+f.offset)==0,"871 selected null House member");value=z(m,0x7b8e5c);need(value=="<none>","871 original none literal");break;
   case Kind::Linked:{auto linked=m.r32(o+f.offset);need(linked,"871 selected Tag/Script/TaskForce positive");value=z(m,linked+0x24);break;}
   case Kind::Waypoint:value=waypoint(m.r32(o+f.offset));put(m,0xb0d048,value);break;
  }
  need(!value.empty(),"871 selected nonempty output");put(m,c.value_scratch,value);
  write_absent(m,h,c.ini_root,section,f.key,c.value_scratch);
 }
 return 1;
}
}

namespace ra2::recovered::recovery_b871 {
std::uint32_t fun_006b52f0(global_b26::Memory&m,const global_b26::Inputs&i,const SerializerCase&c,platform::ordinary_heap::Heap&h){
 need(i.cx==c.ini_root,"871 outer INI receiver");const auto count=m.r32(0xa28898),table=m.r32(0xa2888c);need(count>=1&&count<=4&&table,"871 bounded registry");
 need(z(m,0x7e0994)=="TeamTypes"&&!probe_section(m,h,c.ini_root,0x7e0994),"871 original count lookup misses absentTeamTypes");
 need(!probe_section(m,h,c.ini_root,0x7e0994),"871 nonnull clear misses absentTeamTypes");unsigned matched=0;
 for(unsigned k=0;k<m.r32(0xa28898);++k){auto object=m.r32(m.r32(0xa2888c)+4*k);need(object,"871 registry nonnullmember");if(m.r32(object+0xe0)!=i.dx)continue;
  need(matched++==0&&object==c.object,"871 exactly one matching selected member");need(m.r32(object)==0x797898&&m.r32(0x797900)==0x6b4dc0,"871 authentic original virtual target");
  put(m,c.key_scratch,"0");write_absent(m,h,c.ini_root,0x7e0994,c.key_scratch,object+0x24);
  global_b26::Inputs child{};child.cx=object;child.arg[0]=c.ini_root;serialize_child(m,child,c,h);
 }
 need(matched==1,"871 positive one-match route");return m.r32(0xa28898);
}
}
