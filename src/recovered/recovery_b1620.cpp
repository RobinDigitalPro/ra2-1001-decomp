#include "recovered/recovery_b1620.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1620 { namespace {
void need_at(bool b,int line){if(!b)throw std::domain_error("1620 finite guard line "+std::to_string(line));}
#define need(x) need_at((x),__LINE__)
int s16(U x){return std::int16_t(x);}int s8(U x){return std::int8_t(x);}
void surface(Memory&m,U p,U w){need(p&&m.r32(p)==0x785ef8&&m.r32(p+4)==w&&m.r32(p+8)==1&&m.r32(p+12)==0&&m.r32(p+16)==2&&m.r32(p+20)&&m.r32(p+24)==w*2&&m.r8(p+28)==1);}
U lock(Memory&m,U p){m.w32(p+12,m.r32(p+12)+1);return m.r32(p+20);}
U unlock(Memory&m,U p){U value=m.r32(p+12)-1;m.w32(p+12,value);return(value&0xffffff00u)|1u;}
U ring(Memory&m,U p){need(p&&m.r32(p+4)==0&&m.r32(p+16)==0&&m.r32(p+32)==8&&m.r16(p+36)==0&&m.r32(p+40)==4);const U s=m.r32(p+20);surface(m,s,4);need(m.r32(p+28)==m.r32(s+20)+8);U q=lock(m,s);unlock(m,s);q+=m.r32(p+16);if(q>=m.r32(p+28))q-=m.r32(p+32);return q;}
U query(Memory&m,const Inputs&i,U c,U type){
 need(m.r32(0xa283c4)==0&&m.r8(0xa28953)==0&&m.r8(0xa285a8)==1);
 need(m.r32(c+0xe4)==0&&m.r32(c+0xe8)==0&&m.r32(c+0x44)==0xffffffffu&&m.r32(c+0xec)==0&&m.r8(c+0x124)==0);
 need(m.r32(type+0xbf0)==0&&m.r8(type+0x1351)==0&&m.r8(type+0x1358)==0&&m.r8(type+0x1359)==0&&m.r8(type+0xada)==0);
 // Actual471260/471360 select the empty live list after Root produces point0,0.
 const U private_point[]{0,0};need(private_point[0]*7==0&&private_point[1]*7==0);
 const int x=s16(m.r16(c+0x24)),y=s16(m.r16(c+0x26)),z=s8(m.r8(c+0x11b));
 const int f0=int(m.r32(0x81a910)),f8=int(m.r32(0x81a918)),fc=int(m.r32(0x81a91c));
 const bool inside=x+y>f0+2*fc+z&&x+y<=f0+2*(int(m.r32(0x81a924))+fc)+2+z&&x-y<2*(int(m.r32(0x81a920))+f8)-f0&&y-x<f0-2*f8;need(inside);
 U ax=9*m.r32(c+0xec)+m.r32(type+0x5a4);need(ax==0);
 i.fp.load32(m.r32(0x8391d0+4*ax));i.fp.compare_pop32(m.r32(0x785738));
 ax=(ax&0xffff0000u)|i.fp.status();return(ax&0xffffff00u)|((ax&0x4000)?0u:1u);
}
}
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 (void)heap;need(root==0x73b20);const U cell=i.cx,point=i.arg[0],clip=i.arg[1];
 need(cell&&m.r32(cell)==0x788b04&&m.r16(cell+0x24)==15&&m.r16(cell+0x26)==15&&m.r8(cell+0x11b)==0&&m.r8(cell+0x11c)==0&&m.r32(cell+0x12c)==0xa&&m.r32(cell+0x140)==0);
 need((i.arg[2]&255)==0&&m.r32(point)==U(-30)&&m.r32(point+4)==1);for(U k=0;k<4;++k)need(m.r32(clip+4*k)==(k<2?0:1));
 need(m.r32(0x81a910)==20&&m.r32(0x81a918)==0&&m.r32(0x81a91c)==0&&m.r32(0x81a920)==20&&m.r32(0x81a924)==20);
 const U type=m.r32(0x81b9c4),entries=m.r32(0x81a958),count=m.r32(0x81a95c),owner=m.r32(0xa1e0e4);need(type&&entries&&count>=8192&&count<=40000&&m.r32(type)==0x7881f8&&m.r32(0x788224)==0x45e970&&m.r32(type+0x5a4)==0&&m.r8(type+0xc20)==0&&m.r8(0x81b99c)==1&&owner&&m.r32(owner)==0x78dde0);
 const U kind=7;need(kind==7);const U selector=m.r32(type+0x5a4);
 const int height_offset=-1-15*s8(m.r8(cell+0x11b));int base_depth=-2-15*s8(m.r8(cell+0x11b));if(m.r8(cell+0x11c))base_depth-=10;need(base_depth==-2);
 //557070 constructs world coordinate and always calls the warm4702C0 height recipe.
 const int wx=s16(m.r16(cell+0x24))*256+128,wy=s16(m.r16(cell+0x26))*256+128;const U index=U(wy/256)*512+U(wx/256);need(index<count&&m.r32(entries+4*index)==cell);
 need(m.r8(0x838f70)==7&&m.r32(0x838f80)==256&&m.r32(0x785728)==0&&m.r32(0x78572c)==0x3fe00000&&m.r32(0x7c3a04)==0xe7f&&m.r32(0x8391d0)==0x3f800000&&m.r32(0x785738)==0);
 const U cw=i.fp.image.word(0);need((cw&0xf0ff)==0x7f&&(cw&0x300)!=0x100&&i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&~0x3800)==0);
 i.fp.load_integer32(U(s8(m.r8(cell+0x11b))*int(m.r32(0x838f80))));i.fp.add64(floating_b61::read64(m,0x785728));if(i.fp.image.word(0)!=m.r32(0x7c3a04))i.fp.load_control(std::uint16_t(m.r32(0x7c3a04)));const int real_height=int(i.fp.pop_integer64());need(real_height==0);
 //564F30 divides real Z, and mutates only its consumed outgoing argument copy.
 const int divisor=int(m.r32(0xa57848));need(divisor==256);const int quotient=real_height/divisor;need((quotient&1)==0);const U child_packed=U(std::uint16_t(wx/256-quotient/2))|(U(std::uint16_t(wy/256-quotient/2))<<16);need(child_packed==0x000f000f&&index<40000&&m.r32(entries+4*index)==cell);
 const U height_predicate=(m.r32(cell+0x12c)&8)?0u:1u;need(height_predicate==0&&selector==0);
 const U query_eax=query(m,i,cell,type);need((query_eax&255)==1&&m.r32(type+0xbf0)==0);const U query_flag=query_eax&255;
 const int x=int(std::int32_t(m.r32(point)))+30,y=int(std::int32_t(m.r32(point+4)))+height_offset;need(x==0&&y==0);
 const U pattern[]{1,1,1,1,0xffffffffu,1};for(U k=0;k<6;++k)need(m.r32(0x7b90f8+4*k)==pattern[k]);
 const U mode=0x20600;need(mode==0x20600&&m.r32(0x7bebac)==0x3000);
 const U shp=m.r32(0x83a944);need(shp&&m.r16(shp+2)==1&&m.r16(shp+4)==1&&m.r16(shp+6)==1&&m.r16(shp+8)==0&&m.r16(shp+10)==0&&m.r16(shp+12)==1&&m.r16(shp+14)==1&&m.r8(shp+16)==2&&m.r32(shp+28)==0x100&&m.r16(shp+0x100)==3&&m.r8(shp+0x102)==1);
 const U ctx=m.r32(0x81a704),palette=m.r32(ctx+0x170),desc=m.r32(ctx+0xd0),first=m.r32(ctx+8);need(ctx&&palette&&desc&&first&&m.r32(ctx)==0x7905bc&&m.r32(ctx+4)==2&&m.r32(ctx+0x16c)==53&&m.r32(ctx+0x174)==palette+26*512&&m.r32(ctx+0x178)==0&&m.r32(ctx+0x17c)==0);
 need(m.r32(first)==0x78943c&&m.r32(first+4)==m.r32(ctx+0x174)&&m.r32(desc)==0x789140&&m.r32(desc+4)==m.r32(ctx+0x174)&&m.r32(0x789144)==0x4895f0);
 const U slots[]{0x411370,0x4112f0,0x4113b0,0x4113c0,0x4112c0,0x4112d0},offsets[]{0x5c,0x60,0x70,0x74,0x7c,0x80};for(U k=0;k<6;++k)need(m.r32(0x785ef8+offsets[k])==slots[k]);
 const U dst=m.r32(0x821c9c),dr=m.r32(0x821fac),ar=m.r32(0x8198f4);surface(m,dst,1);const U depth=ring(m,dr),aux=ring(m,ar);need(m.r16(depth)==0&&m.r16(aux)==0&&m.r16(m.r32(dst+20))==1);
 const U addresses[]{cell,type,entries,owner,point,clip,ctx,palette,desc,first,dst,dr,ar,m.r32(dst+20),depth,aux,m.r32(dr+20),m.r32(ar+20),shp};const U sizes[]{0x144,0x1388,count*4,0x15f44,8,16,0x1b4,53*512,8,8,32,0x2c,0x2c,2,8,8,32,32,0x103};
 for(U a=0;a<std::size(addresses);++a){need(addresses[a]&&std::uint64_t(addresses[a])+sizes[a]<=0x100000000ull);for(U b=a+1;b<std::size(addresses);++b)need(std::uint64_t(addresses[a])+sizes[a]<=addresses[b]||std::uint64_t(addresses[b])+sizes[b]<=addresses[a]);}
 // Genuine nonallocating holder, normal software lock, one clipped RLE row.
 m.w32(ctx+0x17c,0);U destination=lock(m,dst),stream=shp+m.r32(shp+28)+2,remaining=1;
 while(remaining){const U literal=m.r8(stream++);if(!literal){const U skip=m.r8(stream++);need(skip&&skip<=remaining);remaining-=skip;destination+=2*skip;}else{const U source=m.r16(m.r32(desc+4)+2*literal);m.w16(destination,source);destination+=2;--remaining;}}
 U eax=unlock(m,dst);need(eax==1);eax=(eax&0xffffff00u)|1u;const U temporary_owner=0;eax=(eax&0xffffff00u)|temporary_owner;return(eax&0xffffff00u)|query_flag;
}
}
