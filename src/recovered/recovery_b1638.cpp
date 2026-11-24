#include "recovered/recovery_b1638.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
#include <string>
#include <array>
namespace ra2::recovered::b1638 {
namespace {
void need(bool b){if(!b)throw std::domain_error("1638 finite first uppercase name/status reset route");}
std::string ascii(Memory&m,U p){need(p);std::string s;for(U k=0;k<7;++k){U c=m.r8(p+k);if(!c){need(!s.empty());return s;}need(c>='A'&&c<='Z');s+=char(c);}need(false);return {};}
std::string wide(Memory&m,U p){need(p);std::string s;for(U k=0;k<7;++k){U c=m.r16(p+2*k);if(!c){need(!s.empty());return s;}need(c>='A'&&c<='Z');s+=char(c);}need(false);return {};}
U clone(b979::Heap&h,const std::string&s){U p=h.allocate(U(s.size()+1));need(p);h.w8(p,0);for(U k=0;k<s.size();++k)h.w8(p+k,U((unsigned char)s[k]));h.w8(p+U(s.size()),0);return p;}
std::string bytes(b979::Heap&h,U p){need(p);std::string s;for(U k=0;k<7;++k){U c=h.r8(p+k);if(!c)return s;s+=char(c);}need(false);return {};}
void drop(b979::Heap&h,U&p){need(p&&h.release(p)!=0);p=0;}
// Whole75A7B0: clone, actual C-locale ASCII lower operation, clone result,
// free temporary. Caller output-holder is abstract local state, not gueststack.
U lower(b979::Heap&h,const std::string&s){U temp=clone(h,s);for(U k=0;k<s.size();++k){U c=h.r8(temp+k);if(c>='A'&&c<='Z')h.w8(temp+k,c+32);}U result=clone(h,bytes(h,temp));drop(h,temp);return result;}
U copy_wide(b979::Heap&h,const std::string&s){U p=h.allocate(2*U(s.size()+1));need(p);h.w8(p,0);h.w8(p+1,0);for(U k=0;k<s.size();++k){h.w8(p+2*k,U((unsigned char)s[k]));h.w8(p+2*k+1,0);}h.w8(p+2*U(s.size()),0);h.w8(p+2*U(s.size())+1,0);return p;}
// Whole35CBC0 selected wide-copy/low-byte conversion. It clears/publishes
// output without reading any previous unproduced output holder value.
U convert(b979::Heap&h,U widep,U length){std::string s;for(U k=0;k<length;++k){need(h.r8(widep+2*k+1)==0);s+=char(h.r8(widep+2*k));}U converted=clone(h,s),joined=clone(h,bytes(h,converted));drop(h,converted);U published=clone(h,bytes(h,joined));drop(h,joined);return published;}
bool equal(b979::Heap&h,U a,U b){for(U k=0;k<7;++k){U x=h.r8(a+k),y=h.r8(b+k);if(x!=y)return false;if(!x)return true;}need(false);return false;}
}
U fun_00732090(Memory&m,const Inputs&i,b979::Heap&heap,b1633::Api&api,U root_pre_call_S){
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();
 try{
 need(std::uint64_t(root_pre_call_S)>=0x98ull+0x624ull&&i.cx&&i.dx==0);
 need(m.r32(0xb0e5f0)==0&&m.r32(0xb0fc00)==0&&m.r32(0xb10100)==0);
 need(m.r32(0xb10530)==0&&m.r32(0x817554)==0&&m.r32(0xb10e14)==0);
 need(m.r32(0xa27db8)==8);
 const U table=m.r32(0xa27dac),query_pointer=m.r32(i.cx);
 const auto query=ascii(m,query_pointer);
 std::array<U,11> addresses{};std::array<U,11> sizes{};
 addresses[0]=i.cx;sizes[0]=4;addresses[1]=query_pointer;sizes[1]=U(query.size()+1);
 addresses[2]=table;sizes[2]=32;
 constexpr std::array<std::array<U,2>,8> outputs{{{{0xa5a230,36}},{{0xa5a254,36}},{{0xa5a278,36}},{{0xa5a2b4,114}},{{0xa5a464,114}},{{0xa5a5c4,36}},{{0xaa4bf0,0x304}},{{0xa27dc4,32}}}};
 // Complete public borrowed spans, no wrap or overlap with child output fields.
 // The table is an explicit numeric vector projection, not a vptr/provider.
 auto extent=[&](U a,U n){const auto lo=std::uint64_t(a),end=lo+n;need(lo>=0x10000000ull&&end<=0x70000000ull);(void)m.r8(a);(void)m.r8(U(end-1));for(auto r:outputs)need(end<=r[0]||std::uint64_t(r[0])+r[1]<=lo);};
 extent(addresses[0],sizes[0]);extent(addresses[1],sizes[1]);extent(table,32);
 std::array<U,8> players{};
 for(U k=0;k<8;++k){const U p=m.r32(table+4*k);players[k]=p;need(p==m.r32(0xa27dc4+4*k));addresses[3+k]=p;sizes[3+k]=0x69;extent(p,0x69);(void)wide(m,p);need(m.r32(p+0x65)==(k==0?1u:0u));}
 for(U k=0;k<addresses.size();++k)for(U j=0;j<k;++j)need(std::uint64_t(addresses[k])+sizes[k]<=addresses[j]||std::uint64_t(addresses[j])+sizes[j]<=addresses[k]);
 const auto name=wide(m,players[0]);need(name==query);
 need(api.parent&&m.r32(0xb0d858)==1&&m.r32(0xb0d634)==0xbc&&m.r32(0xb0d630)==U(reinterpret_cast<std::uintptr_t>(api.parent)));
 fp::restore_host(i.fp.image);
 // Whole7592C0 fresh copy: nonempty75A0E0 selects the actual inputholder.
 // Actual null B0E5F0 comparison is false, so5C5930 is excluded.
 U primary=clone(heap,query); //owner0, holderF18
 // B0FC00=0 skips the complete first connection search.
 U query_lower=lower(heap,bytes(heap,primary)); //owners1,2;free1, outputF20
 U record_wide=copy_wide(heap,name); //owner3, outputF1C
 U record_ascii=convert(heap,record_wide,U(name.size())); //4,5,free4,6,free5;outputF14
 drop(heap,record_wide); //free3
 U record_lower=lower(heap,bytes(heap,record_ascii)); //7,8,free7;outputF24
 const bool match=equal(heap,query_lower,record_lower);drop(heap,record_lower);need(match);drop(heap,record_ascii); //free8,6
 // SETZ F13 is produced from authenticated B10100==0 before its only read.
 // First index0 also dominates exclusion of the networking/virtual branch.
 m.w32(players[0]+0x65,0);
 Inputs child=i;child.cx=0;child.dx=0;child.fp.image=fp::capture_host();
 // AX/highDX and arg copies here are unused abstract carriers, not Original
 // volatile-register or unproduced child-caller-word observations.
 (void)b1636::fun_00734590(m,child,heap,api,root_pre_call_S-0x98u);
 i.fp.image=child.fp.image;fp::restore_host(child.fp.image);
 drop(heap,query_lower); //free2 after childowners9..24 closed
 // Whole759320 ->76D67B ->76DF28 preserves full actual HeapFreeBOOL in EAX.
 // Do not replace this provider return with1, AL, or a mask.
 need(primary);const U result=heap.release(primary);need(result!=0);primary=0; //free0
 i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
