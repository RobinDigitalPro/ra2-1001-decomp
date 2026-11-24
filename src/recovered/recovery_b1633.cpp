#include "recovered/recovery_b1633.hpp"
#include "recovered/recovery_b899.hpp"
#include "recovered/recovery_b1016_lookup.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
#include <string>
#include <vector>
namespace ra2::recovered::b1633 {
namespace {
namespace fp=ra2::platform::x87;
void need(bool v,const char*e){if(!v)throw std::domain_error(e);}
U ptr(HWND h){return U(reinterpret_cast<std::uintptr_t>(h));}
constexpr std::array<std::array<U,2>,8> outputs{{{{0xa5a230,36}},{{0xa5a254,36}},{{0xa5a278,36}},{{0xa5a2b4,114}},{{0xa5a464,114}},{{0xa5a5c4,36}},{{0xaa4bf0,0x304}},{{0xa27dc4,32}}}};
void separate_from_outputs(U a,U n){need(std::uint64_t(a)+n<=0x100000000ull,"1633 extent no wrap");for(auto r:outputs)need(std::uint64_t(a)+n<=r[0]||std::uint64_t(r[0])+r[1]<=a,"1633 public input/output disjoint extents");}
bool disjoint(U a,U n,U b,U z){return std::uint64_t(a)+n<=b||std::uint64_t(b)+z<=a;}
std::u16string wide(Memory&m,U p,U max){need(p,"1633 nonnull UTF16");std::u16string s;for(U k=0;k<=max;++k){auto c=m.r16(p+2*k);if(!c)return s;s.push_back(char16_t(c));}throw std::domain_error("1633 bounded UTF16 terminator");}
std::string ascii(Memory&m,U p,U max){std::string s;for(U k=0;k<=max;++k){auto c=m.r8(p+k);if(!c)return s;s.push_back(char(c));}throw std::domain_error("1633 bounded ASCII terminator");}
void copy_wide(Memory&m,U dst,const std::u16string&s){for(U k=0;k<s.size();++k)m.w16(dst+2*k,s[k]);m.w16(dst+2*U(s.size()),0);}
void copy_ascii(Memory&m,U dst,const std::string&s){for(U k=0;k<s.size();++k)m.w8(dst+k,U(std::uint8_t(s[k])));m.w8(dst+U(s.size()),0);}
// Exact bounded %d, result (7D128C bytes 25 64 2C 00), not a general formatter.
std::string decimal_csv(const std::array<U,8>&v){std::string s;for(U x:v){need(x<=8,"1633 one-digit signed decimal");s.push_back(char('0'+x));s.push_back(',');}return s;}
U control_node(Memory&m,U hwnd){
 constexpr U owner=0xa5b1a0;need(m.r32(owner+4)==16&&m.r32(owner+8)==128&&m.r32(owner+12)==7&&m.r32(owner+24)==0x5d6fc0,"1633 genuine sixteen-HWND scalar registry");
 U node=m.r32(m.r32(owner)+4*(hwnd&127));for(U k=0;node&&k<16;++k){if(m.r32(node)==hwnd)return node;node=m.r32(node+0x204);}throw std::domain_error("1633 real HWND absent/cyclic registry");
}
// Actual 5DA440 matched-record writes and unchanged User32 call. No text setter.
void update(Memory&m,Api&a,U hwnd,U value){const U p=control_node(m,hwnd)+4;m.w32(p+0x70,2);m.w32(p+0x14,value);(void)a.invalidate_rect(reinterpret_cast<HWND>(std::uintptr_t(hwnd)),nullptr,TRUE);}
}
U fun_005c3880(Memory&m,const Inputs&i,Heap&heap,Api&a){
 const auto host=fp::capture_host();
 try{
 need(a.root_pre_call_S>=36u,"1633 authenticated pre-CALL S witness");
 need((i.dx&255)==0&&i.cx==ptr(a.parent)&&a.parent&&a.get_dlg_item&&a.invalidate_rect,"1633 exact DL0/owned HWND/API scope");
 need(m.r32(0xa255c8)==1&&m.r32(0x817554)==0&&m.r32(0xb10e14)==0&&m.r32(0x81776c)==1,"1633 mode1 ordinary CRT/singlebyte formatter route");
 need(m.r8(0x7d128c)=='%'&&m.r8(0x7d128d)=='d'&&m.r8(0x7d128e)==','&&m.r8(0x7d128f)==0&&m.r16(0xa2793e)==0,"1633 authentic format and empty special-name literal");
 std::array<U,8> players{},country{},palette{};std::u16string joined;
 for(U k=0;k<8;++k){
  const U p=m.r32(0xa27dc4+4*k);players[k]=p;separate_from_outputs(p,0x69);need(p,"1633 positive player/name record");
  for(U t:{0xa5a89cu,0xa5a8a0u,0xa5a8a4u,0xa5a8a8u,0xa5a8acu,0xa5a8b0u})need(p!=m.r32(t),"1633 ordinary non-sentinel player");
  for(U j=0;j<k;++j)need(disjoint(p,0x69,players[j],0x69),"1633 distinct nonoverlapping player records");
  const auto name=wide(m,p,6);need(!name.empty()&&m.r32(p+0x65)!=1,"1633 B899 positive name/ordinary status");
  need(m.r32(p+0x4d)!=0xfffffffe&&m.r32(p+0x55)!=0xfffffffe,"1633 actual country/palette direct getter arms");
  country[k]=m.r32(p+0x49);palette[k]=m.r32(p+0x51);need(country[k]<=8&&palette[k]<=8,"1633 bounded actual numeric player values");joined+=name;joined.push_back(u',');
 }
 need(joined.size()<=56&&wide(m,0xa5a2b4,56)==joined,"1633 actual post-B899 caption equality excludes missing child");
 const auto countries=decimal_csv(country),palettes=decimal_csv(palette);
 need(ascii(m,0xa5a278,16)==countries&&ascii(m,0xa5a254,16)==palettes,"1633 real regenerated CSV equality excludes rebuilds");
 // Validate sixteen actual STATIC bindings and collision chains before mutation.
 std::array<U,16> nodes{};
 for(U k=0;k<16;++k){need(a.controls[k],"1633 sixteen genuine supplied HWNDs");nodes[k]=control_node(m,ptr(a.controls[k]));separate_from_outputs(nodes[k],0x208);const U p=nodes[k]+4;need(std::uint64_t(nodes[k])+0x208u<=0x100000000ull,"1633 full record extent/no wrap");(void)m.r8(nodes[k]+0x207);
  need(m.r32(p+0x68)==2&&m.r32(p+0x70)==0&&m.r32(p+0x24)==0,"1633 normal Static kind2/cold flags/nonpaint fields");
  for(U j=0;j<k;++j)need(ptr(a.controls[k])!=ptr(a.controls[j])&&disjoint(nodes[k],0x208,nodes[j],0x208),"1633 unique HWND/record extents");
  for(U player:players)need(disjoint(nodes[k],0x208,player,0x69),"1633 record/player extents disjoint");
 }
 fp::restore_host(i.fp.image);
  for(U k=0;k<8;++k){const auto h=a.get_dlg_item(a.parent,int(0x6d2+k));need(h==a.controls[k],"1633 actual first STATIC control");update(m,a,ptr(h),0);}
  // 76EFC9 source=[ESP+8], destination=[ESP+4]: save OLD joined state.
  copy_wide(m,0xa5a464,wide(m,0xa5a2b4,56));
  recovery_b899::Inputs b{};b.ax=i.ax;b.cx=0xa5a2b4;b.dx=i.dx;b.arg=i.arg;b.stack_minus8=i.stack_minus8;b.arithmetic_flags=i.arithmetic_flags;
  (void)recovery_b899::fun_005c2b20(m,b,heap,a.root_pre_call_S-24u); // Authenticated pre-CALL witness only; child entry S-28. No stack mapping/writes.
  need(wide(m,0xa5a2b4,56)==wide(m,0xa5a464,56),"1633 computed caption compare0");
  for(U k=0;k<8;++k){const auto h=a.get_dlg_item(a.parent,int(0x6da+k));need(h==a.controls[8+k],"1633 actual second STATIC control");b1016::lookup199::Inputs q{};q.cx=country[k];const U resource=b1016::lookup199::fun_004d0b50(m,q,heap);update(m,a,ptr(h),resource);}
  copy_ascii(m,0xa5a5c4,ascii(m,0xa5a278,16));m.w8(0xa5a278,0);std::string s;
  for(U value:country){const char local[3]{char('0'+value),',',0};s+=local;copy_ascii(m,0xa5a278,s);}
  need(ascii(m,0xa5a5c4,16)==ascii(m,0xa5a278,16),"1633 actual country CSV compare0");
  copy_ascii(m,0xa5a230,ascii(m,0xa5a254,16));m.w8(0xa5a254,0);s.clear();
  for(U value:palette){const char local[3]{char('0'+value),',',0};s+=local;copy_ascii(m,0xa5a254,s);}
  need(ascii(m,0xa5a230,16)==ascii(m,0xa5a254,16),"1633 final palette CSV compare0");
  i.fp.image=fp::capture_host();fp::restore_host(host);return 0;
 }catch(...){fp::restore_host(host);throw;}
}
}
