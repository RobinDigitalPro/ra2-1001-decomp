#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1509 {
using U=std::uint32_t;using Memory=floating_b61::Memory;using Inputs=floating_b61::Inputs;
namespace fp=platform::x87;
namespace detail {
inline void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
inline U get(const std::uint8_t*p,U n){return U(p[n])|(U(p[n+1])<<8)|(U(p[n+2])<<16)|(U(p[n+3])<<24);}
inline U address(const void*p){const auto v=reinterpret_cast<std::uintptr_t>(p);need(v<=0xffffffffu,"1509 real32-bit provider destination");return U(v);}
inline void domain(const fp::Image&f){
 constexpr unsigned short cw[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool valid=false;for(auto c:cw)valid|=f.word(0)==c;need(valid,"1509 exact12 maskedCW");
 const U sw=f.word(4),top=(sw>>11)&7,tag=f.word(8);need((sw&~0x7f3fu)==0,"1509 noSF/ES/B");bool empty=false;U depth=0;
 for(U k=0;k<8;++k){const U t=(tag>>(2*((top+k)&7)))&3;need(t==0||t==3,"1509 normal/emptytags");if(t==3)empty=true;else{need(!empty,"1509 contiguousstack");++depth;}const U e=(f.bytes[36+10*k]|(U(f.bytes[37+10*k])<<8))&0x7fff;need((f.bytes[35+10*k]&0x80)&&e>0&&e<0x7fff,"1509 everyrawslotnormal includingemptystales");}
 need(depth<=4,"1509 peak4 temporaryregisters excludesdepth5..8");
}

// Each provider boundary consumes and updates the current explicit model State.
// The fixture installs that state, makes the actual OS/heap operation and captures
// its resulting full physical image. No callback may silently assume FP unchanged.
// Heap: allocate(bytes,State&),release(pointer,State&),r8/r32/w8/w32.
// Api: probe(path,State&),open(path,true,State&),read(handle,dest,n,State&),
// seek(handle,offset,origin,State&),close(handle,State&). All addresses are real32.
// probe uses READ/shareREAD/OPEN_EXISTING/NORMAL and closes its probe handle;
// open uses READ/shareREAD|WRITE/OPEN_EXISTING/NORMAL|SEQUENTIAL_SCAN.
template<class M>inline void initialize_file(M&m,U p,U name){
 m.w32(p,0x7856a0);m.w32(p+4,1);m.w32(p+8,0);m.w32(p+12,~0u);m.w32(p+16,~0u);m.w32(p+20,name);m.w16(p+24,0);m.w16(p+26,0);m.w8(p+28,1);
 for(U off:{32u,33u,34u,35u,36u,37u})m.w8(p+off,0);
 for(U off:{40u,44u,48u,52u,56u,68u,72u,76u})m.w32(p+off,0);
 m.w32(p+60,~0u);m.w32(p+64,~0u);m.w8(p+80,0);m.w32(p+84,0);m.w32(p+88,0);m.w8(p+92,0);m.w32(p+96,0);
}
inline void original_file_slots(Memory&m){
 for(const auto p:std::array<std::array<U,2>,6>{{{{0x18,0x468e00}},{{0x1c,0x468e40}},{{0x24,0x468c80}},{{0x28,0x468d10}},{{0x2c,0x468d70}},{{0x34,0x468e10}}}})
  need(m.r32(0x7856a0+p[0])==p[1],"1509 authentic CCFile slots");
}
template<class Heap,class Api>class File {
 Memory&globals;Heap&heap;Api&api;fp::State&state;
 std::array<std::uint8_t,100> storage; // eleven opaque bytes remain uninitialized
 leaf::Memory bytes;U name{},position{},length;
 void closed(){need(bytes.r32(16)==~0u,"1509 actual closed handle");}
 public:
 File(Memory&m,Heap&h,Api&a,fp::State&f,const std::array<std::uint8_t,256>&path,U n):globals(m),heap(h),api(a),state(f),bytes(storage.data(),0,100),length(n){
  name=heap.allocate(10,state);need(name!=0,"1509 owned10-byte filename");
  for(U k=0;k<10;++k)heap.w8(name+k,path[k]);initialize_file(bytes,0,name);
 }
 void exists(){closed();need(api.probe(name,state)!=0,"1509 positive physical Exists");closed();}
 void open(){closed();need(bytes.r32(8)==0&&bytes.r32(12)==~0u&&bytes.r8(37)==0&&bytes.r32(84)==0,"1509 unbuffered unbiased unknown-size route");
  need(api.probe(name,state)!=0,"1509 Open physical probe");const U handle=api.open(name,true,state);need(handle!=~0u,"1509 positive physical sequential Open1");bytes.w32(16,handle);bytes.w32(4,1);position=0;
 }
 void read(U destination,U n){need(bytes.r32(16)!=~0u&&n&&position<=length&&n<=length-position&&globals.r8(0xa9e184)==0,"1509 actual unbuffered complete read domain");
  need(api.read(bytes.r32(16),destination,n,state)==n,"1509 physical ReadFile complete bytes");globals.w8(0xa9e184,0);position+=n;
 }
 void seek(U offset){need(bytes.r32(16)!=~0u&&position<=length&&offset<=length-position,"1509 inbounds relative seek");
  const U next=api.seek(bytes.r32(16),offset,1,state);need(next==position+offset,"1509 actual relative SetFilePointer");position=next;
 }
 void close(){need(bytes.r32(16)!=~0u,"1509 parser closes open file");api.close(bytes.r32(16),state);bytes.w32(16,~0u);}
 U destroy(){closed();bytes.w32(0,0x7856a0);bytes.w32(96,0);bytes.w32(84,0);bytes.w32(88,0);bytes.w8(92,0);bytes.w32(0,0x785658);bytes.w32(0,0x78773c);bytes.w32(48,0);for(U off:{33u,35u,36u,37u})bytes.w8(off,0);bytes.w32(0,0x793c84);
  const U result=heap.release(name,state);need(result!=0,"1509 actual filename HeapFree succeeds");bytes.w32(0,0x793c3c);bytes.w32(20,0);bytes.w8(28,0);return result;
 }
};
inline U vector_ctor(U self){return self;}
inline void construct_vectors(U p){for(U k=0;k<8;++k)need(vector_ctor(p+0x40+12*k)==p+0x40+12*k,"1509 genuine no-store vector constructor");}
template<class Heap>inline void initialize_vxl(Heap&h,U self){h.w8(self,0);for(U off:{4u,8u,12u,16u,20u,24u})h.w32(self+off,0);}
template<class Heap>inline void initialize_hva(Heap&h,U self){h.w8(self,0);for(U off:{4u,8u,12u})h.w32(self+off,0);}
template<class Heap,class Api>inline U parse_vxl(Heap&h,const Inputs&i,U self,File<Heap,Api>&file){
 need(h.r8(self)==0&&h.r32(self+4)==0&&h.r32(self+8)==0&&h.r32(self+12)==0&&h.r32(self+16)==0&&h.r32(self+20)==0&&h.r32(self+24)==0,"1509 fresh VXL fields only");
 h.w32(self+16,0);h.w32(self+20,0);h.w32(self+24,0);file.open();
 std::array<std::uint8_t,32> header;file.read(address(header.data()),32);
 need(get(header.data(),16)==1&&get(header.data(),20)==1&&get(header.data(),24)==1&&get(header.data(),28)==16,"1509 onepalette/onesection/onetail/nonempty16body");
 h.w32(self+4,get(header.data(),20));h.w32(self+8,get(header.data(),24));h.w32(self+12,get(header.data(),28));
 const U heads=h.allocate(12,i.fp);need(heads!=0,"1509 positiveheaderowner");h.w32(self+16,heads);
 const U tails=h.allocate(164,i.fp);need(tails!=0,"1509 positivetailowner");construct_vectors(tails);h.w32(self+20,tails);
 const U body=h.allocate(16,i.fp);need(body!=0,"1509 positivebodyowner");h.w32(self+24,body);
 file.seek(770);std::array<std::uint8_t,28> section;file.read(address(section.data()),28);h.w32(heads,get(section.data(),16));h.w32(heads+4,get(section.data(),20));h.w8(heads+8,section[24]);
 file.read(body,16);std::array<std::uint8_t,92> tail;file.read(address(tail.data()),92);
 need(get(tail.data(),0)==0&&get(tail.data(),4)==4&&get(tail.data(),8)==8&&get(tail.data(),12)==0x3f800000,"1509 finitebodyoffsets andnormalscale1");
 constexpr std::array<U,6> bounds{0x3f800000,0x40000000,0x40400000,0x40800000,0x40a00000,0x40c00000};for(U k=0;k<6;++k)need(get(tail.data(),64+4*k)==bounds[k],"1509 literalnondegeneratebounds1/2/3..4/5/6");
 domain(i.fp.image);
 // All three allocations precede this exact50-instruction explicit x87 model.
 // Host hardware images remain separate: State operations save/restore host.
 std::array<U,0x140/4> local;for(U k=0;k<92;k+=4)local[(0x84+k)/4]=get(tail.data(),k);local[0x14/4]=get(tail.data(),76);local[0x18/4]=get(tail.data(),80);local[0x1c/4]=get(tail.data(),84);
  i.fp.load32(local[0x90/4]); // 0x70e115 fld dword ptr [esp + 0x90]
 h.w32(tails+0xc,i.fp.pop32()); // 0x70e123 fstp dword ptr [eax + ebp + 0xc]
 i.fp.load32(local[0xc4/4]); // 0x70e144 fld dword ptr [esp + 0xc4]
 i.fp.load32(local[0xc8/4]); // 0x70e14b fld dword ptr [esp + 0xc8]
 i.fp.load32(local[0xcc/4]); // 0x70e152 fld dword ptr [esp + 0xcc]
 i.fp.load32(local[0xd0/4]); // 0x70e159 fld dword ptr [esp + 0xd0]
 local[0x6c/4]=i.fp.pop32(); // 0x70e16e fstp dword ptr [esp + 0x6c]
 i.fp.load32(local[0xd4/4]); // 0x70e172 fld dword ptr [esp + 0xd4]
 local[0x70/4]=i.fp.pop32(); // 0x70e18b fstp dword ptr [esp + 0x70]
 i.fp.load32(local[0xcc/4]); // 0x70e18f fld dword ptr [esp + 0xcc]
 local[0x74/4]=i.fp.pop32(); // 0x70e196 fstp dword ptr [esp + 0x74]
 i.fp.load32(local[0x14/4]); // 0x70e19a fld dword ptr [esp + 0x14]
 local[0x44/4]=i.fp.pop32(); // 0x70e1ae fstp dword ptr [esp + 0x44]
 i.fp.load_st1(); // 0x70e1b8 fld st(1)
 local[0x48/4]=i.fp.pop32(); // 0x70e1bd fstp dword ptr [esp + 0x48]
 i.fp.load_st0(); // 0x70e1cb fld st(0)
 local[0x4c/4]=i.fp.pop32(); // 0x70e1cd fstp dword ptr [esp + 0x4c]
 i.fp.load_st2(); // 0x70e1d9 fld st(2)
 local[0x78/4]=i.fp.pop32(); // 0x70e1e1 fstp dword ptr [esp + 0x78]
 i.fp.load_st1(); // 0x70e1e8 fld st(1)
 local[0x7c/4]=i.fp.pop32(); // 0x70e1f4 fstp dword ptr [esp + 0x7c]
 i.fp.load_st0(); // 0x70e200 fld st(0)
 local[0x80/4]=i.fp.pop32(); // 0x70e202 fstp dword ptr [esp + 0x80]
 i.fp.load_st2(); // 0x70e20b fld st(2)
 local[0x5c/4]=i.fp.pop32(); // 0x70e217 fstp dword ptr [esp + 0x5c]
 i.fp.load32(local[0x18/4]); // 0x70e21b fld dword ptr [esp + 0x18]
 local[0x60/4]=i.fp.pop32(); // 0x70e21f fstp dword ptr [esp + 0x60]
 local[0x64/4]=i.fp.pop32(); // 0x70e22d fstp dword ptr [esp + 0x64]
 i.fp.load32(local[0x14/4]); // 0x70e231 fld dword ptr [esp + 0x14]
 local[0x20/4]=i.fp.pop32(); // 0x70e23d fstp dword ptr [esp + 0x20]
 i.fp.load32(local[0x18/4]); // 0x70e241 fld dword ptr [esp + 0x18]
 local[0x24/4]=i.fp.pop32(); // 0x70e24b fstp dword ptr [esp + 0x24]
 i.fp.load32(local[0x1c/4]); // 0x70e24f fld dword ptr [esp + 0x1c]
 local[0x28/4]=i.fp.pop32(); // 0x70e256 fstp dword ptr [esp + 0x28]
 i.fp.load32(local[0x14/4]); // 0x70e25a fld dword ptr [esp + 0x14]
 local[0x2c/4]=i.fp.pop32(); // 0x70e270 fstp dword ptr [esp + 0x2c]
 i.fp.load_st0(); // 0x70e27a fld st(0)
 local[0x30/4]=i.fp.pop32(); // 0x70e27f fstp dword ptr [esp + 0x30]
 i.fp.load32(local[0x1c/4]); // 0x70e283 fld dword ptr [esp + 0x1c]
 local[0x34/4]=i.fp.pop32(); // 0x70e291 fstp dword ptr [esp + 0x34]
 i.fp.load_st1(); // 0x70e29d fld st(1)
 local[0x38/4]=i.fp.pop32(); // 0x70e2a5 fstp dword ptr [esp + 0x38]
 local[0x3c/4]=i.fp.pop32(); // 0x70e2ac fstp dword ptr [esp + 0x3c]
 i.fp.load32(local[0x1c/4]); // 0x70e2b0 fld dword ptr [esp + 0x1c]
 local[0x40/4]=i.fp.pop32(); // 0x70e2c9 fstp dword ptr [esp + 0x40]
 local[0x50/4]=i.fp.pop32(); // 0x70e2d3 fstp dword ptr [esp + 0x50]
 i.fp.load32(local[0x18/4]); // 0x70e2d7 fld dword ptr [esp + 0x18]
 local[0x54/4]=i.fp.pop32(); // 0x70e2de fstp dword ptr [esp + 0x54]
 i.fp.load32(local[0x1c/4]); // 0x70e2e2 fld dword ptr [esp + 0x1c]
 local[0x58/4]=i.fp.pop32(); // 0x70e2f7 fstp dword ptr [esp + 0x58]
 for(U k=0;k<48;++k)h.w8(tails+0x10+k,tail[16+k]);
 constexpr U from[8][3]{{0x6c,0x70,0x74},{0x44,0x48,0x4c},{0x78,0x7c,0x80},{0x5c,0x60,0x64},{0x20,0x24,0x28},{0x2c,0x30,0x34},{0x38,0x3c,0x40},{0x50,0x54,0x58}};
 for(U k=0;k<8;++k)for(U axis=0;axis<3;++axis)h.w32(tails+0x40+12*k+4*axis,local[from[k][axis]/4]);
 for(U k=0;k<4;++k)h.w8(tails+0xa0+k,tail[88+k]);for(U k=0;k<3;++k)h.w32(tails+4*k,body+get(tail.data(),4*k));

 file.close();return 1;
}
template<class Heap,class Api>inline U parse_hva(Heap&h,const Inputs&i,U self,File<Heap,Api>&file){
 need(h.r8(self)==0&&h.r32(self+4)==0&&h.r32(self+8)==0&&h.r32(self+12)==0,"1509 fresh HVA fields only");h.w32(self+12,0);file.open();
 std::array<std::uint8_t,24> header;file.read(address(header.data()),24);const U height=get(header.data(),16),width=get(header.data(),20);
 need(height==1&&width==1,"1509 exact one-grid88-byte HVA");h.w32(self+4,width);h.w32(self+8,height);
 const U grid=h.allocate(48,i.fp);need(grid!=0,"1509 genuine positive HVA grid owner");h.w32(self+12,grid);file.seek(16);
 std::array<std::uint8_t,48> matrix;file.read(address(matrix.data()),48);
 // Actual 58CBE0 plus REP MOVSD: all twelve produced DWORDs, no private seed.
 for(U k=0;k<48;++k)h.w8(grid+k,matrix[k]);file.close();return 1;
}
inline U format_stem(Memory&m,U base,bool barrel,std::array<std::uint8_t,256>&stem){
 const char*required=barrel?"B":"T0";U n=0;for(;required[n];++n){need(m.r8(base+n)==U(required[n]),"1509 finite exact original base");stem[n]=std::uint8_t(required[n]);}
 need(m.r8(base+n)==0,"1509 exact base terminator");const char*suffix=barrel?"BARL":"TUR";for(U k=0;suffix[k];++k)stem[n++]=std::uint8_t(suffix[k]);stem[n]=0;return n;
}
inline void make_path(const std::array<std::uint8_t,256>&stem,U n,const char*extension,std::array<std::uint8_t,256>&path){
 // Null drive/directory bypasses 775260; extension already begins with dot.
 for(U k=0;k<n;++k)path[k]=stem[k];for(U k=0;k<5;++k)path[n+k]=std::uint8_t(extension[k]);
 need(n+5==10&&path[9]==0,"1509 exact ten produced filename bytes");
}
template<class Heap,class Api>inline U run(U rva,Memory&m,const Inputs&i,Heap&h,Api&a){
 need(rva==0x1ce7e0||rva==0x1cea80,"1509 two named roots only");need(i.arg[0]&&i.arg[1]==0&&!(i.arithmetic_flags&0x400),"1509 nonnull index0 DFclear");domain(i.fp.image);
 need(m.r32(0xa588e0)==0&&m.r32(0xb10530)==0&&m.r32(0x838be0)==0&&m.r8(0xa9e184)==0,"1509 genuine coldcache physical route");original_file_slots(m);
 const bool barrel=rva==0x1cea80;const U slot=barrel?0x140:0xc8;
 std::array<std::uint8_t,256> stem,path;const U n=format_stem(m,i.arg[0],barrel,stem);make_path(stem,n,".VXL",path);
 File<Heap,Api> vxl_file(m,h,a,i.fp,path,938);vxl_file.exists();
 const U vxl=h.allocate(28,i.fp);need(vxl!=0,"1509 positive VXL outer28");initialize_vxl(h,vxl);need(parse_vxl(h,i,vxl,vxl_file)==1,"1509 complete positive VXL constructor");m.w32(i.cx+slot,vxl);need(h.r8(vxl)==0,"1509 VXL constructor success byte");
 const U n2=format_stem(m,i.arg[0],barrel,stem);make_path(stem,n2,".HVA",path);File<Heap,Api> hva_file(m,h,a,i.fp,path,88);
 const U hva=h.allocate(16,i.fp);need(hva!=0,"1509 positive HVA outer16");initialize_hva(h,hva);need(parse_hva(h,i,hva,hva_file)==1,"1509 complete positive HVA constructor");m.w32(i.cx+slot+4,hva);need(h.r8(hva)==0,"1509 HVA constructor success byte");
 // Exact nine 59BB20 x87 operations for three translations. Scale comes from
 // actual VXL tail storage; State includes every prior physical provider effect.
 domain(i.fp.image);const U metadata=h.r32(vxl+16),tails=h.r32(vxl+20);const U selected_index=h.r32(metadata+12u*0u)+0u;need(selected_index==0,"1509 finite actual70E420 section/tail index0");const U selected_tail=tails+164u*selected_index;const U scale=h.r32(selected_tail+12),grid=h.r32(hva+12);need(scale==0x3f800000,"1509 actual parsed VXL scale1");
 for(U off:{12u,28u,44u}){const U value=h.r32(grid+off),exponent=(value>>23)&255;need(exponent>0&&exponent<255,"1509 normal finite translation");i.fp.load32(scale);i.fp.multiply32(value);h.w32(grid+off,i.fp.pop32());}
 (void)hva_file.destroy();const U final_free=vxl_file.destroy();return (final_free&0xffffff00u)|1u;
}
} // namespace detail
template<class Heap,class Api>inline U fun_005ce7e0(Memory&m,const Inputs&i,Heap&h,Api&a){return detail::run(0x1ce7e0,m,i,h,a);}
template<class Heap,class Api>inline U fun_005cea80(Memory&m,const Inputs&i,Heap&h,Api&a){return detail::run(0x1cea80,m,i,h,a);}
} // namespace ra2::recovered::b1509