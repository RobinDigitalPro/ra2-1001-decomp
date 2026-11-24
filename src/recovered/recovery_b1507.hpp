#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b999_parser.inc"
} // The existing parser fragment leaves its owning namespace open.
#include <array>
namespace ra2::recovered::b1507 {
using U=std::uint32_t;using Memory=b999::Memory;using Inputs=b999::Inputs;
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
// Finite existing-file route of original RVA 0x263180. Heap and file providers
// bind at compilation; OS calls and observation storage stay in the fixture.
struct Observation{U entry_s{},ini{},file{},final_free{},eax{};std::array<unsigned char,32>digest{};};
inline void initialize_ini(Memory&m,U p){m.w32(p,0x78db34);m.w32(p+4,0x785aec);m.w32(p+8,0x785afc);m.w32(p+12,p+20);m.w32(p+16,0);m.w32(p+20,0x785afc);m.w32(p+24,0);m.w32(p+28,p+8);for(U off:{32u,36u,40u,48u,52u})m.w32(p+off,0);m.w8(p+44,0);}
inline void initialize_file(Memory&m,U p,U name){m.w32(p,0x7856a0);m.w32(p+4,1);m.w32(p+8,0);m.w32(p+12,~0u);m.w32(p+16,~0u);m.w32(p+20,name);m.w16(p+24,0);m.w16(p+26,0);m.w8(p+28,1);for(U off:{32u,33u,34u,35u,36u,37u})m.w8(p+off,0);for(U off:{40u,44u,48u,52u,56u,68u,72u,76u})m.w32(p+off,0);m.w32(p+60,~0u);m.w32(p+64,~0u);m.w8(p+80,0);m.w32(p+84,0);m.w32(p+88,0);m.w8(p+92,0);m.w32(p+96,0);}
// Exact finite existing-file route; original private bytes are never supplied.
template<class Heap,class Api>
inline U fun_00663180(Memory&m,const Inputs&in,Heap&h,Api&a,U S,Observation&o){
 need(in.arg[0]==0&&in.arg[2]==0&&in.dx==40,"1507 positive finite caller domain");need(m.r32(0xa588e0)==0&&m.r32(0xb10530)==0&&m.r32(0x838be0)==0,"1507 genuine coldcache input");need(m.r32(0xa25c18)==1,"1507 single matching registry record");const U row=m.r32(m.r32(0xa25c0c));const auto filename=ra2::recovered::b999::read_z(m,in.cx);need(filename=="P1507.INI"&&ra2::recovered::b999::read_z(m,row+0x58)==filename,"1507 actual filename match");o.entry_s=S;o.ini=S-0xbcu;o.file=S-0x84u;
 const U name=h.allocate(10);ra2::recovered::b999::write_z(h,name,filename);initialize_file(m,o.file,name);const char*path=reinterpret_cast<const char*>(std::uintptr_t(name));
 // Two root Exists calls, then Size's physicalavailability+temporaryopen.
 a.probe(path);a.probe(path);a.probe(path);a.probe(path);auto temp=a.open(path,true);m.w32(o.file+16,U(std::uintptr_t(temp)));need(a.size(temp)==in.dx,"1507 actual exact size");m.w32(o.file+12,40);a.close(temp);m.w32(o.file+16,~0u);initialize_ini(m,o.ini);
 const U buffer=h.allocate_reader();a.probe(path);a.probe(path);auto file=a.open(path,true);m.w32(o.file+16,U(std::uintptr_t(file)));need(a.seek(file,FILE_BEGIN)==0,"1507 known size reopen starts0");need(a.seek(file,FILE_CURRENT)==0,"1507 rawread current0");need(a.read(file,buffer,40)==40,"1507 clamp4096 request to40");
 
 const std::string text(reinterpret_cast<const char*>(std::uintptr_t(buffer)),40),prefix="[Profile001]\r\nPlayerFaction=";need(text.size()==40&&text.compare(0,prefix.size(),prefix)==0&&text.substr(38)=="\r\n","1507 unchanged B99940B grammar");const auto value=text.substr(prefix.size(),10);need(value.compare(0,9,"Profile00")==0&&value[9]>='0'&&value[9]<='9',"1507 B999 literal value domain");
 const U section=h.allocate(68),sn=h.allocate(11),node=h.allocate(40),copy=h.allocate(11),key=h.allocate(14),kt=h.allocate(80);need(a.seek(file,FILE_CURRENT)==40,"1507 later EOF afterkeytable");const U st=h.allocate(80);ra2::recovered::b999::write_z(h,sn,"Profile001");ra2::recovered::b999::write_z(h,copy,value);ra2::recovered::b999::write_z(h,key,"PlayerFaction");ra2::recovered::b999::build_single_section(h,h,section,sn,node,key,copy,kt,st,"Profile001","PlayerFaction");h.w32(section+4,o.ini+20);h.w32(section+8,o.ini+8);m.w32(o.ini+12,section);m.w32(o.ini+28,section);m.w32(o.ini+32,st);m.w32(o.ini+36,1);m.w32(o.ini+40,10);h.free_reader(buffer);a.close(file);m.w32(o.file+16,~0u);m.w32(o.file+84,0);m.w32(o.file+88,0);m.w8(o.file+92,0);m.w32(o.file+96,0);
 // Nonempty real parser graph, missing Digest section. Original hash/findmiss,
 // strncpy32, forcedlastNUL andtrim return this exact literal without newheap.
 need(h.r32(st)==ra2::recovered::b999::hash_text("Profile001")&&h.r32(st)!=ra2::recovered::b999::hash_text("Digest"),"1507 actual section hashmiss");const char fallback[]="No digest here mate. Nope.";for(U k=0;k<32;++k){const auto ch=k<sizeof(fallback)?static_cast<unsigned char>(fallback[k]):0;o.digest[k]=ch;m.w8(S-32+k,ch);}h.capture_live();
 for(U k=0;k<10;++k)m.w8(in.cx+k,m.r8(row+0x58+k));ra2::recovered::b999::destroy_single_section(h,section,node,st,0);initialize_ini(m,o.ini);m.w32(o.ini+4,0x785af4);
 m.w32(o.file,0x78773c);m.w32(o.file,0x793c84);o.final_free=h.release(name);m.w32(o.file,0x793c3c);m.w32(o.file+20,0);m.w8(o.file+28,0);o.eax=(o.final_free&0xffffff00u)|1u;return o.eax;
}
}
