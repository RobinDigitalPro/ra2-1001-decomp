#include "recovered/recovery_b1637.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1637 {
namespace {
void need(bool b){if(!b)throw std::domain_error("1637 finite first uppercase name/two changed scalar route");}
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
U fun_00732490(Memory&m,const Inputs&i,b979::Heap&heap,b1633::Api&api,U root_pre_call_S){
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();
 try{
 need(std::uint64_t(root_pre_call_S)>=0x28ull+0x624ull&&i.cx&&i.dx<=8&&i.arg[0]<=8);
 need(m.r32(0xb10530)==0&&m.r32(0x817554)==0&&m.r32(0xb10e14)==0);
 const U player=m.r32(0xa27dc4);need(player);const auto name=wide(m,player),query=ascii(m,m.r32(i.cx));need(name==query);
 need(m.r32(player+0x4d)==0&&m.r32(player+0x55)==0);
 const U old_country=m.r32(player+0x49),old_palette=m.r32(player+0x51);need(old_country<=8&&old_palette<=8);
 need(i.dx==(old_country+1)%9&&i.arg[0]==(old_palette+2)%9);
 fp::restore_host(i.fp.image);
 U input_lower=lower(heap,query); // owners0,1;free0
 U record_wide=copy_wide(heap,name); // owner2
 U record_ascii=convert(heap,record_wide,U(name.size())); //3,4,free3,5,free4
 drop(heap,record_wide); //free2
 U record_lower=lower(heap,bytes(heap,record_ascii)); //6,7,free6
 const bool match=equal(heap,input_lower,record_lower);drop(heap,record_lower);need(match);drop(heap,record_ascii); //free7,5
 // Actual72A500(C2,C9) both miss the sole BC row. Their return is ignored.
 need(api.parent&&m.r32(0xb0d858)==1&&m.r32(0xb0d634)==0xbc&&m.r32(0xb0d630)==U(reinterpret_cast<std::uintptr_t>(api.parent)));
 U changed=0;if(old_country!=i.dx){m.w32(player+0x49,i.dx);m.w32(player+0x4d,0xffffffffu);changed=1;}
 // 664E90 reads INITIAL+55 into EDX0 before664EF0 overwrites memory+55.
 // 664EF0 never changes EDX; subsequent XORDL therefore leaves fullEDX0.
 if(old_palette!=i.arg[0]){m.w32(player+0x51,i.arg[0]);m.w32(player+0x55,0xffffffffu);}
 Inputs child=i;child.ax=i.arg[0];child.cx=0;child.dx=0;child.fp.image=fp::capture_host();
 // Child args are unused analysis carriers, not Original F..F+3C snapshots.
 (void)b1636::fun_00734590(m,child,heap,api,root_pre_call_S-0x28u);
 i.fp.image=child.fp.image;fp::restore_host(child.fp.image);
 drop(heap,input_lower); //finalowner1, after unchanged childowners8..23 closed
 i.fp.image=fp::capture_host();fp::restore_host(host);return changed;
 }catch(...){fp::restore_host(host);throw;}
}
}
