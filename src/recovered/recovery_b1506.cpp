#include "recovered/recovery_b1506.hpp"
#include <stdexcept>
namespace ra2::recovered::b1506 {namespace {
void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
U get(const std::uint8_t*p,U n){return U(p[n])|(U(p[n+1])<<8)|(U(p[n+2])<<16)|(U(p[n+3])<<24);}
U fs_head(){U x;asm volatile("movl %%fs:0,%0":"=r"(x));return x;}
U fs_selector(){unsigned short x;asm volatile("movw %%fs,%0":"=r"(x));return x;}
void domain(const fp::Image&f){
 constexpr unsigned short cw[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool valid=false;for(auto c:cw)valid|=f.word(0)==c;need(valid,"1506 exact12 maskedCW");
 const U sw=f.word(4),top=(sw>>11)&7,tag=f.word(8);need((sw&~0x7f3fu)==0,"1506 noSF/ES/B");bool empty=false;U depth=0;
 for(U k=0;k<8;++k){const U t=(tag>>(2*((top+k)&7)))&3;need(t==0||t==3,"1506 normal/emptytags");if(t==3)empty=true;else{need(!empty,"1506 contiguousstack");++depth;}const U e=(f.bytes[36+10*k]|(U(f.bytes[37+10*k])<<8))&0x7fff;need((f.bytes[35+10*k]&0x80)&&e>0&&e<0x7fff,"1506 everyrawslotnormal includingemptystales");}
 need(depth<=4,"1506 peak4 temporaryregisters excludesdepth5..8");
}
class MemFile {
 Memory&m;U f;Observation&o;
 void event(U slot,U a,U b,U result){need(o.event_count<7,"1506 exact7Fileevents");o.file_events[o.event_count++]={slot,a,b,result,m.r32(f+16)};}
 void open_state(){need(m.r8(f+24)==1&&(m.r32(f+20)&1)&&m.r32(f+16)<=m.r32(f+12),"1506 originalopenReadmodeposition");}
 public:MemFile(Memory&memory,U file,Observation&out):m(memory),f(file),o(out){
  need(m.r32(f)==0x793bf4&&m.r32(f+4)&&m.r32(f+8)==938&&m.r32(f+12)==938&&m.r32(f+16)==0&&m.r32(f+20)==1&&m.r8(f+24)==0&&m.r8(f+25)==0,"1506 genuineborrowed62F8B0 MemFileprojection");
  for(auto p:std::array<std::array<U,2>,5>{{{{0x18,0x62f990}},{{0x1c,0x62f9b0}},{{0x24,0x62fa00}},{{0x28,0x62fa80}},{{0x34,0x62fba0}}}})need(m.r32(0x793bf4+p[0])==p[1],"1506 actualoriginalMemFilemethodslot");
 }
 void open(){need(m.r8(f+24)==0,"1506 originalIsOpen false beforeOpen1");m.w32(f+16,0);m.w32(f+20,1);m.w8(f+24,1);event(0x1c,1,0,1);}
 template<class Store>void read(U n,Store store){open_state();const U pos=m.r32(f+16),len=m.r32(f+12);need(n&&n<=len-pos,"1506 completepositive62FA00 read");const U source=m.r32(f+4)+pos;for(U k=0;k<n;++k)store(k,m.r8(source+k));m.w32(f+16,pos+n);event(0x24,n,0,n);}
 void seek(U n){open_state();const U pos=m.r32(f+16);need(n<=m.r32(f+12)-pos,"1506 inboundsrelativeSeek1");m.w32(f+16,pos+n);event(0x28,n,1,pos+n);}
 void close(){open_state();m.w8(f+24,0);event(0x34,0,0,0);} // void placeholder0, not nativeEAX
};
// Genuine3-byte70C890 body. The array loop invokes this exact no-store
// constructor eight times; it does not manufacture successful parser effects.
U vector_ctor(U self){return self;}
void construct_vectors(U p,Observation&o){for(U k=0;k<8;++k){need(vector_ctor(p+0x40+12*k)==p+0x40+12*k,"1506 actualtinyctorEAX");++o.constructor_calls;}}
}
U fun_0070dd20(Memory&m,const Inputs&i,Heap&h,Observation&o){
 domain(i.fp.image);need(!(i.arithmetic_flags&0x400)&&i.arg[1]==0,"1506 DFclear paletteoption0");need(o.event_count==0&&o.constructor_calls==0&&o.owners==std::array<U,3>{},"1506 freshobservation");const U self=i.cx;
 need(m.r8(self)==0&&m.r32(self+4)==0&&m.r32(self+8)==0&&m.r32(self+12)==0&&m.r32(self+16)==0&&m.r32(self+20)==0&&m.r32(self+24)==0,"1506 genuine70DC40 initializedfields only, opaque1..3 untouched");
 m.w32(self+16,0);m.w32(self+20,0);m.w32(self+24,0);MemFile file(m,i.arg[0],o);file.open();
 std::array<std::uint8_t,32> header;file.read(32,[&](U k,U b){header[k]=std::uint8_t(b);});
 need(get(header.data(),16)==1&&get(header.data(),20)==1&&get(header.data(),24)==1&&get(header.data(),28)==16,"1506 onepalette/onesection/onetail/nonempty16body");
 m.w32(self+4,get(header.data(),20));m.w32(self+8,get(header.data(),24));m.w32(self+12,get(header.data(),28));
 const U heads=h.allocate(12);need(heads!=0,"1506 positiveheaderowner");m.w32(self+16,heads);o.owners[0]=heads;
 const U tails=h.allocate(164);need(tails!=0,"1506 positivetailowner");construct_vectors(tails,o);m.w32(self+20,tails);o.owners[1]=tails;
 const U body=h.allocate(16);need(body!=0,"1506 positivebodyowner");m.w32(self+24,body);o.owners[2]=body;
 file.seek(770);std::array<std::uint8_t,28> section;file.read(28,[&](U k,U b){section[k]=std::uint8_t(b);});h.w32(heads,get(section.data(),16));h.w32(heads+4,get(section.data(),20));h.w8(heads+8,section[24]);
 file.read(16,[&](U k,U b){h.w8(body+k,b);});std::array<std::uint8_t,92> tail;file.read(92,[&](U k,U b){tail[k]=std::uint8_t(b);});
 need(get(tail.data(),0)==0&&get(tail.data(),4)==4&&get(tail.data(),8)==8&&get(tail.data(),12)==0x3f800000,"1506 finitebodyoffsets andnormalscale1");
 constexpr std::array<U,6> bounds{0x3f800000,0x40000000,0x40400000,0x40800000,0x40a00000,0x40c00000};for(U k=0;k<6;++k)need(get(tail.data(),64+4*k)==bounds[k],"1506 literalnondegeneratebounds1/2/3..4/5/6");
 o.actual_provider_prefix_fp=fp::capture_host();o.prefix_fs_head=fs_head();o.prefix_fs_selector=fs_selector();
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
 file.close();need(o.event_count==7&&o.constructor_calls==8,"1506 exactprovider/constructorledger");return 1;
}
}
