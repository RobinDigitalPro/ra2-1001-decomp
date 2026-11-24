#include "recovered/recovery_b1617.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1617 {namespace {
void need_at(bool v,int line){if(!v)throw std::domain_error("1617 finite mode2 guard line "+std::to_string(line));}
#define need(v) need_at((v),__LINE__)
int s16(U x){return std::int16_t(x);}int s8(U x){return std::int8_t(x);}
void surface(Memory&m,U p,U w){need(p&&m.r32(p)==0x785ef8&&m.r32(p+4)==w&&m.r32(p+8)==1&&m.r32(p+12)==0&&m.r32(p+16)==2&&m.r32(p+24)==2*w&&m.r8(p+28)==1&&m.r32(p+20));}
U lock(Memory&m,U p,U x=0,U y=0){m.w32(p+12,m.r32(p+12)+1);return m.r32(p+20)+y*m.r32(p+24)+x*m.r32(p+16);}
U unlock(Memory&m,U p){U v=m.r32(p+12)-1;m.w32(p+12,v);return(v&0xffffff00)|1;}
U ring(Memory&m,U p){need(p&&m.r32(p+4)==0&&m.r32(p+16)==0&&m.r32(p+32)==8&&m.r32(p+40)==4);U s=m.r32(p+20);surface(m,s,4);need(m.r32(p+28)==m.r32(s+20)+8);U q=lock(m,s);unlock(m,s);q+=m.r32(p+16);if(q>=m.r32(p+28))q-=m.r32(p+32);return q;}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 (void)heap;need(root==0x305440);const U self=i.cx;
 need(m.r16(self+0xe0)==5&&m.r16(self+0xe2)==7&&m.r32(self+0xe4)==0&&m.r32(self+0xe8)==0);
 const U map=0x81a820,entries=m.r32(map+0x138);need(entries&&m.r32(map+0x13c)==4096);const U cell=m.r32(entries+3589*4);
 need(cell&&(m.r32(cell+0x140)&0x400000)==0&&m.r8(cell+0x11b)==0&&m.r16(cell+0x10c)==0);
 const U scene=m.r32(0x821cac);need(m.r32(scene+0xb0)==U(-60)&&m.r32(scene+0xb4)==137&&m.r32(scene+0xdb0)==0);
 const U clip=0x821970,shp=m.r32(0xab821c);need(shp&&m.r16(shp+2)==1&&m.r16(shp+4)==1&&m.r16(shp+6)==1&&m.r16(shp+8)==0&&m.r16(shp+10)==0&&m.r16(shp+12)==1&&m.r16(shp+14)==1&&m.r8(shp+16)==2&&m.r32(shp+28)==0x100&&m.r16(shp+0x100)==3&&m.r8(shp+0x102));
 for(U k=0;k<4;++k)need(m.r32(clip+4*k)==(k<2?0:1));
 // Real packed-cell coordinate conversion and numeric receiver translation.
 int X=int(m.r16(self+0xe0))*256+128,Y=int(m.r16(self+0xe2))*256+128,Z=0;
 int x=(X-Y)*30/256-int(std::int32_t(m.r32(scene+0xb0)));
 int y=(X+Y)*15/256-int(std::int32_t(m.r32(scene+0xb4)));
 need(m.r32(0xaa5f90)==0&&m.r32(0xaa5f94)==0&&m.r32(0xaa6070)==0&&m.r32(0xaa6074)==0&&m.r32(0x785728)==0&&m.r32(0x78572c)==0x3fe00000&&m.r32(0x7c3a04)==0xe7f);
 need(i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&~0x3800)==0);
 auto& state=i.fp;state.load_integer32(U(Z));state.multiply64(floating_b61::read64(m,0xaa5f90));
 {ra2::platform::x87::Image host;U value=0;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfiaddl %[value]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(state.image.bytes):[value]"m"(value):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
 state.add64(floating_b61::read64(m,0x785728));if(state.image.word(0)!=m.r32(0x7c3a04))state.load_control(std::uint16_t(m.r32(0x7c3a04)));const int height=int(state.pop_integer64());y-=height+58;
 need(x==0&&y==0);
 // Real69FB50 reject: caller queue Y=local0+clipY0+58 > clipHeight1+32.
 const int queue_y=y+int(std::int32_t(m.r32(clip+4)))+58;need(queue_y>int(m.r32(clip+12))+32);
 const U house=m.r32(0xa1e0e4),schemes=m.r32(0xa9ea04);need(m.r32(house+0x15f40)==1&&m.r32(0xa9ea10)==2&&m.r32(0xa9ea08)==10);
 const U scheme=m.r32(schemes+4);need(m.r32(scheme)==2&&m.r32(scheme+0x310)==53&&m.r32(scheme+0x330)==16);const U name=m.r32(scheme+0x304);constexpr char expected_name[]="next.pal";for(U k=0;k<sizeof(expected_name);++k)need(m.r8(name+k)==U(expected_name[k]));const U ctx=m.r32(scheme+0x30c);need(ctx&&m.r32(ctx)==0x7905bc&&m.r32(ctx+4)==2&&m.r32(ctx+0x16c)==53&&m.r32(ctx+0x174)==m.r32(ctx+0x170)+26*512&&m.r32(ctx+0x178)==0&&m.r32(ctx+0x17c)==0);
 const U first=m.r32(ctx+8);need(first&&m.r32(first)==0x78943c&&m.r32(first+4)==m.r32(ctx+0x174));
 const U desc=m.r32(ctx+0x138),table=m.r32(desc+8),palette=m.r32(desc+4);need(m.r32(desc)==0x789008&&m.r32(0x78900c)==0x48aea0&&palette==m.r32(ctx+0x170)&&m.r32(table+0x20000)==53&&m.r32(table+0x20004)==78&&m.r16(table)==0);
 for(U k=0;k<256;++k)need(m.r16(palette+2*k)==0); // Actual53-row producer's row0, not N1.
 const U pattern[]{1,1,1,1,0xffffffffu,1};for(U k=0;k<6;++k)need(m.r32(0x7b90f8+4*k)==pattern[k]);need(m.r8(0x836dc0)==0);
 const U slots[]{0x411370,0x4112f0,0x4113b0,0x4113c0,0x4112c0,0x4112d0},offsets[]{0x5c,0x60,0x70,0x74,0x7c,0x80};for(U k=0;k<6;++k)need(m.r32(0x785ef8+offsets[k])==slots[k]);
 const U dst=m.r32(0x821c9c);surface(m,dst,1);const U dr=m.r32(0x821fac),ar=m.r32(0x8198f4);need(m.r16(dr+0x24)==0);const U depth=ring(m,dr),aux=ring(m,ar);need(m.r16(depth)==0&&m.r16(aux)==0&&m.r16(m.r32(dst+20))!=0);
 m.w32(ctx+0x17c,0);
 // Disjoint public field projections; full tables remain owned by fixture arena.
 const U addresses[]{self,cell,scene,entries,house,scheme,ctx,desc,table,palette,dst,dr,ar,m.r32(dst+20),depth,aux,m.r32(dr+20),m.r32(ar+20),shp,schemes,name,first};
 const U sizes[]{0xec,0x144,0xdb4,4096*4,0x15f44,0x33c,0x1b4,12,0x20008,53*512,32,0x2c,0x2c,2,8,8,32,32,0x103,40,9,8};
 for(U a=0;a<22;++a){need(addresses[a]&&std::uint64_t(addresses[a])+sizes[a]<=0x100000000ull);for(U b=a+1;b<22;++b)need(std::uint64_t(addresses[a])+sizes[a]<=addresses[b]||std::uint64_t(addresses[b])+sizes[b]<=addresses[a]);}
 U destination=lock(m,dst);
 const int source_row=s16(m.r16(dr+0x24))-y;
 const int baseDepth=-17-15*s8(m.r8(cell+0x11b));
 const int divisor=int(m.r32(0x7b90f8+4));
 const int d=((source_row+baseDepth)/divisor)*divisor;need(d==-17); // Actual pattern0 row/base/divisor; argA0=0 skips height correction.
 U stream=shp+m.r32(shp+28)+2,count=1,dc=depth,ac=aux,skip=0;
 // Actual48AEA0 RLE traversal, table lookup and signed depth comparison.
 while(count){U pixel=m.r8(stream++);if(!pixel){U n=m.r8(stream++);need(n&&n<=count);count-=n;destination+=2*n;dc+=2*n;ac+=2*n;skip+=n;}else{
  const int delta=s8(m.r8(0x836dc0+skip));if(d-delta<int(m.r16(dc))){const U scale=m.r16(cell+0x10c);const U phase=std::min(254u,(scale*261u)>>11);U index=m.r16(table+(phase<<9)+2*m.r16(ac))|pixel;m.w16(destination,m.r16(palette+2*index));}
  ++skip;--count;destination+=2;dc+=2;ac+=2;
 }
 if(dc>=m.r32(dr+28))dc-=m.r32(dr+32);if(ac>=m.r32(ar+28))ac-=m.r32(ar+32);
 }
 U eax=unlock(m,dst);need(eax==1); // Source temporary unlock likewise returns full1.
 eax=(eax&0xffffff00u)|1u; //434F80 MOV AL,1.
 const U temporary_owner=0;eax=(eax&0xffffff00u)|temporary_owner; //438290 produced owner0, no free.
 return eax;
}
}
