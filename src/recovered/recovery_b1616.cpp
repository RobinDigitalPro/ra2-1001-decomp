#include "recovered/recovery_b1616.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1616 {namespace {
void need(bool v){if(!v)throw std::domain_error("1616 finite Wall0 1x1 RLE53 two-byte renderer");}
int s16(U x){return std::int16_t(x);}int s8(U x){return std::int8_t(x);}
void surface(Memory&m,U p,U w){need(p&&m.r32(p)==0x785ef8&&m.r32(p+4)==w&&m.r32(p+8)==1&&m.r32(p+12)==0&&m.r32(p+16)==2&&m.r32(p+24)==2*w&&m.r8(p+28)==1&&m.r32(p+20));}
U lock(Memory&m,U p,U x=0,U y=0){m.w32(p+12,m.r32(p+12)+1);return m.r32(p+20)+y*m.r32(p+24)+x*m.r32(p+16);}
U unlock(Memory&m,U p){U v=m.r32(p+12)-1;m.w32(p+12,v);return(v&0xffffff00)|1;}
U ring(Memory&m,U p){need(p&&m.r32(p+4)==0&&m.r32(p+16)==0&&m.r32(p+32)==8&&m.r32(p+40)==4);U s=m.r32(p+20);surface(m,s,4);need(m.r32(p+28)==m.r32(s+20)+8);U q=lock(m,s);unlock(m,s);q+=m.r32(p+16);if(q>=m.r32(p+28))q-=m.r32(p+32);return q;}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 (void)heap;need(root==0x745c0);const U cell=i.cx,point=i.arg[0],clip=i.arg[1];
 need(m.r32(cell+0x44)==0&&(m.r32(cell+0x140)&0x80)==0&&m.r8(cell+0x11b)==0&&m.r8(cell+0x11e)==0&&m.r16(cell+0x10a)==0&&m.r32(cell+0x34));
 const U types=m.r32(0xa1e11c),type=m.r32(types);need(m.r32(type)==0x7929c8&&m.r32(type+0x264)==0&&m.r32(type+0x268)!=9&&m.r8(type+0x278)==1&&m.r8(type+0x279)==0&&m.r32(0x792a64)==0x5d57d0);
 const U shp=m.r32(type+0xa4);need(shp&&m.r8(type+0xa8)==1);
 need(m.r16(shp+2)==1&&m.r16(shp+4)==1&&m.r16(shp+6)==1&&m.r16(shp+8)==0&&m.r16(shp+10)==0&&m.r16(shp+12)==1&&m.r16(shp+14)==1&&m.r8(shp+16)==2&&m.r32(shp+28)==0x100&&m.r16(shp+0x100)==3&&m.r8(shp+0x102)!=0);
 need(m.r32(clip)==0&&m.r32(clip+4)==0&&m.r32(clip+8)==1&&m.r32(clip+12)==1&&m.r32(0x821970)==0&&m.r32(0x821974)==0&&m.r32(0x821978)==1&&m.r32(0x82197c)==1);
 // Actual5D46D0 Wall278 and475040 field projection, followed by Root point arithmetic.
 need(m.r32(point)==U(-30)&&m.r32(point+4)==U(-3));
 int ox=30,oy=-12+int(m.r32(0x821974))+15-15*s8(m.r8(cell+0x11b));
 int x=std::int32_t(m.r32(point))+ox-int(m.r32(clip)),y=std::int32_t(m.r32(point+4))+oy-int(m.r32(clip+4));need(x==0&&y==0);
 const U house=m.r32(0xa1e0e4),schemes=m.r32(0xa9ea04);need(m.r32(house+0x15f40)==1&&m.r32(0xa9ea10)==2&&m.r32(0xa9ea08)==10);
 const U scheme=m.r32(schemes+4);need(m.r32(scheme)==2&&m.r32(scheme+0x310)==53&&m.r32(scheme+0x330)==16);const U name=m.r32(scheme+0x304);constexpr char expected_name[]="next.pal";for(U k=0;k<sizeof(expected_name);++k)need(m.r8(name+k)==U(expected_name[k]));const U ctx=m.r32(scheme+0x30c);need(ctx&&m.r32(ctx)==0x7905bc&&m.r32(ctx+4)==2&&m.r32(ctx+0x16c)==53&&m.r32(ctx+0x174)==m.r32(ctx+0x170)+26*512&&m.r32(ctx+0x178)==0&&m.r32(ctx+0x17c)==0);
 const U first=m.r32(ctx+8);need(first&&m.r32(first)==0x78943c&&m.r32(first+4)==m.r32(ctx+0x174));
 const U desc=m.r32(ctx+0x158),table=m.r32(desc+8),palette=m.r32(desc+4);need(m.r32(desc)==0x788fa8&&m.r32(0x788fac)==0x48bc60&&palette==m.r32(ctx+0x170)&&m.r32(table+0x20000)==53&&m.r32(table+0x20004)==78&&m.r16(table)==0);
 for(U k=0;k<256;++k)need(m.r16(palette+2*k)==0); // Actual53-row producer's row0, not N1.
 for(U k=0;k<6;++k)need(m.r32(0x7b9128+4*k)==(k==1||k==3?3u:k==5?0u:1u));need(m.r8(0x836dc0)==0);
 const U slots[]{0x411370,0x4112f0,0x4113b0,0x4113c0,0x4112c0,0x4112d0},offsets[]{0x5c,0x60,0x70,0x74,0x7c,0x80};for(U k=0;k<6;++k)need(m.r32(0x785ef8+offsets[k])==slots[k]);
 const U dst=m.r32(0x821c9c);surface(m,dst,1);const U dr=m.r32(0x821fac),ar=m.r32(0x8198f4);need(m.r16(dr+0x24)==0);const U depth=ring(m,dr),aux=ring(m,ar);need(m.r16(depth)==0xffff&&m.r16(aux)==0&&m.r16(m.r32(dst+20))!=0);
 // Root474642 overwrites its own public arg0 with produced height offset.
 const int height=15*s8(m.r8(cell+0x11b));i.arg[0]=U(height);m.w32(ctx+0x17c,0);
 // Exclude aliases between the declared public live record/buffer extents.
 const U addresses[]{cell,type,house,scheme,ctx,desc,table,palette,dst,dr,ar,m.r32(dst+20),depth,aux,m.r32(dr+20),m.r32(ar+20),shp,point,clip,schemes,types,name,first};
 const U sizes[]{0x144,0x286,0x15f44,0x33c,0x1b4,12,0x20008,53*512,32,0x2c,0x2c,2,8,8,32,32,0x103,8,16,40,16,9,8};
 for(U a=0;a<23;++a){need(addresses[a]&&std::uint64_t(addresses[a])+sizes[a]<=0x100000000ull);for(U b=a+1;b<23;++b)need(std::uint64_t(addresses[a])+sizes[a]<=addresses[b]||std::uint64_t(addresses[b])+sizes[b]<=addresses[a]);}
 U destination=lock(m,dst); // Temporary source Surface has produced C0 and owner0; no guest-public writes.
 // Authentic pattern2 integer row-depth recipe, including the quotient/remainder correction.
 const int base=-2-height,width=int(m.r32(0x7b9130)),period=int(m.r32(0x7b9134));
 // 435108 divides record+C by record+8;43510A retains that quotient in ECX.
 const int row_step=period/width;
 int row=s16(m.r16(dr+0x24))+int(m.r32(dr+4))-y-1-y+1;row=int(U(row)&65535)+base;int d=(row/row_step)*row_step-(1/row_step);int remainder=1%row_step;int remain=period-remainder;if(remain==period)d+=int(m.r32(0x7b9138));need(d==0);
 U stream=shp+m.r32(shp+28)+2,count=1,dc=depth,ac=aux,skip=0;
 // Actual48BC60 RLE traversal, table lookup and signed depth comparison.
 while(count){U pixel=m.r8(stream++);if(!pixel){U n=m.r8(stream++);need(n&&n<=count);count-=n;destination+=2*n;dc+=2*n;ac+=2*n;skip+=n;}else{
  const int delta=s8(m.r8(0x836dc0+skip));if(d-delta<int(m.r16(dc))){const U scale=m.r16(cell+0x10a);const U phase=std::min(254u,(scale*261u)>>11);U index=m.r16(table+(phase<<9)+2*m.r16(ac))|pixel;m.w16(destination,m.r16(palette+2*index));m.w16(dc,U(d-delta));}
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
