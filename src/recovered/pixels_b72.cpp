#include "recovered/pixels_b72.hpp"
#include "recovered/global_b27_memory.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::pixels_b72 {
namespace {
using U = std::uint32_t;
inline U a(const Inputs& i,unsigned n){return i.arg[n];}

// The byte decoder uses the same four computed-dispatch arms as the original
// code; FE consumes input without completing a symbol, FF completes the
// pending group and terminates the input stream.
U decode6(Memory&m,const Inputs&i){
 U src=i.cx,dest=a(i,0),left=i.dx,cap=a(i,1),out=0;
 if(!src||!dest||!left||!cap)return 0;
 i.arg[0]=0;
 if(global_b26::s32(left)<=0||global_b26::s32(cap)<=0)return 0;
 while(left&&cap){
   U word=0,symbols=0;i.arg[1]=0;
   while(left&&symbols<4u){U v=m.r8(src++);--left;v=m.r8(0x787624u+v);if(v==0xfeu)continue;if(v==0xffu){left=0;break;}
     const U lane=symbols;
     if(lane==0)word=(word&0xff03ffffu)|((v&0x3fu)<<18);
     else if(lane==1)word=(word&0xfffc0fffu)|((v&0x3fu)<<12);
     else if(lane==2)word=(word&0xfffff03fu)|((v&0x3fu)<<6);
     else word=(word&0xffffffc0u)|(v&0x3fu);
     ++symbols;
   }
   i.arg[1]=word;
   m.w8(dest++,word>>16);--cap;++out;
   if(cap&&symbols>2u){m.w8(dest++,word>>8);--cap;++out;}
   if(cap&&symbols>3u){m.w8(dest++,word);--cap;++out;}
 }
 i.arg[0]=out;return out;
}

U blend_ring(Memory&m,const Inputs&i){
 U remain=a(i,2), cur=a(i,4), src=a(i,5), count=a(i,6),destination=a(i,0);
 U scaled=(global_b26::s32(count)>0)?count:0u;
 // The machine sequence is SHL 6, ADD original, LEA [x+4*(65*x)]: 261*x.
 U factor=global_b26::sar(scaled*261u,11u);
 if(global_b26::s32(factor)>254)factor=254;
 U outbase=m.r32(i.cx+8u)+factor*512u,gate_cursor=a(i,1);
 i.arg[4]=src;i.arg[6]=outbase;
 if(global_b26::s32(remain)<=0)return remain;
 U mask=m.r16(i.cx+0x0cu);
 const U palette=m.r32(i.cx+4u);
 // The positive arg2 value is copied into the caller's arg5 slot as the
 // loop counter. Arg2 itself becomes the gate byte's low-byte scratch.
 i.arg[5]=remain;
 while(remain){
   const U expected=m.r16(cur);
   if(global_b26::s32(i.arg[3])<global_b26::s32(expected)){
     const U gate=m.r8(gate_cursor);
     i.arg[2]=(i.arg[2]&0xffffff00u)|gate;
     if(gate){
       const U color=m.r16(src), lutidx=m.r16(outbase+color*2u);
       const U old=m.r16(destination);
       const U blended=(((m.r16(palette+((lutidx|gate)&0xffffu)*2u)>>2)&mask)*3u+
                        ((old>>2)&mask))&0xffffu;
       m.w16(destination,blended);m.w16(cur,i.arg[3]);
     }
   }
   destination+=2u;cur+=2u;src+=2u;
   const U ring1=m.r32(0x821facu),ring2=m.r32(0x8198f4u);
   if(cur>=m.r32(ring1+0x1cu))cur-=m.r32(ring1+0x20u);
   if(src>=m.r32(ring2+0x1cu))src-=m.r32(ring2+0x20u);
   ++gate_cursor;i.arg[1]=gate_cursor;
   --remain;i.arg[5]=remain;i.arg[4]=src;
 }
 return 0;
}

// The 0x3688b0 state machine copies blocks of 4 x 16-bit values from a
// 32-byte-stride table. 0x2000 repeats that record; 0x4000 skips 8 bytes.
U lcw_rows(Memory&m,const Inputs&i){
 U src=a(i,1),dst=a(i,2);
 const U record_base=a(i,0),block_step=a(i,5)*2u;
 const U end=dst+a(i,4)*a(i,5)*8u;
 U row_base=dst,row_end=dst+a(i,3)*8u,eax=end;
 i.arg[4]=row_end;i.arg[5]=row_base;
 if(dst>=end)return eax;
 while(dst<end){
   U code=m.r16(src);src+=2u;i.arg[2]=src;
   const U idx=code&0x1fffu,kind=code&0xe000u;
   eax=idx;
   const U record=record_base+idx*32u;
   if(kind==0x2000u){
     for(U n=0;n<4u;++n){
       for(U j=0;j<4u;++j){const U x=m.r16(record+n*8u+j*2u);if(x!=0x8000u)m.w16(dst+j*2u,x);}
       dst+=block_step;
     }
     eax=block_step*4u;dst+=8u-eax;
   }else if(kind==0u){
     for(U n=0;n<4u;++n){m.w32(dst,m.r32(record+n*8u));m.w32(dst+4u,m.r32(record+n*8u+4u));dst+=block_step;}
     eax=block_step*4u;dst+=8u-eax;
   }else if(kind==0x4000u){dst+=8u;}
   if(dst==row_end){
     row_base+=block_step*4u;dst=row_base;
     eax=a(i,3);row_end=row_base+eax*8u;
     i.arg[5]=row_base;i.arg[4]=row_end;
   }
 }
 return eax;
}

U pal_rows(Memory&m,const Inputs&i){
 const U dict=a(i,0),input=a(i,1);U out=a(i,2);
 i.arg[5]<<=1u;const U pitch_out=i.arg[5]*4u;
 const U total=a(i,4)*a(i,3),end=input+total;U p=input,eax=total;
 while(p<end){
   const U row_start=out;U ecx=a(i,3);
   while(ecx){
     U ebx=(m.r8(p+total)<<8)|m.r8(p);++p;
     if(ebx&0x8000u){
       ebx=(ebx&0x7fffu)*2u;const U table=m.r32(0xab8094u);const U ax=m.r16(table+ebx);eax=(ax<<16)|ax;
       // The original emits four planes at offsets 0, arg5, 2*arg5, 3*arg5;
       // every plane contains two adjacent dwords per source pixel.
       m.w32(out,eax);m.w32(out+4u,eax);
       m.w32(out+i.arg[5],eax);m.w32(out+i.arg[5]+4u,eax);
       m.w32(out+i.arg[5]*2u,eax);m.w32(out+i.arg[5]*2u+4u,eax);
       m.w32(out+i.arg[5]*3u,eax);m.w32(out+i.arg[5]*3u+4u,eax);
     }else{
       ebx=dict+(ebx<<5);
       eax=m.r32(ebx);m.w32(out,eax);eax=m.r32(ebx+4u);m.w32(out+4u,eax);
       eax=m.r32(ebx+8u);m.w32(out+i.arg[5],eax);eax=m.r32(ebx+12u);m.w32(out+i.arg[5]+4u,eax);
       eax=m.r32(ebx+16u);m.w32(out+i.arg[5]*2u,eax);eax=m.r32(ebx+20u);m.w32(out+i.arg[5]*2u+4u,eax);
       eax=m.r32(ebx+24u);m.w32(out+i.arg[5]*3u,eax);m.w32(out+i.arg[5]*3u+4u,m.r32(ebx+28u));
     }
     out+=8u;--ecx;
   }
   out=row_start+pitch_out;
 }
 return eax;
}

// Shared finite LCW token engine. The first source byte is a stream selector:
// nonzero starts the ordinary stream; zero consumes a prefix and uses the
// relative-copy form for its extended command.
U lcw_expand(Memory&m,U src,U dst,U limit){
 const U start=dst;U end=dst+limit;
 const bool zero=m.r8(src)==0u;if(zero)++src;
 while(dst<end){
   U ctl=m.r8(src++),count=0,from=0;
   bool literal=false,short_copy=false;
   if((ctl&0x80u)==0){count=(ctl>>4)+3u;const U back=((ctl&15u)<<8)|m.r8(src++);from=dst-back;short_copy=true;}
   else if((ctl&0x40u)==0){if(ctl==0x80u)break;count=ctl&0x3fu;}
   else if(ctl==0xfeu){count=m.r16(src);src+=2u;const U value=m.r8(src++);count=std::min(count,end-dst);while(count--){m.w8(dst++,value);}continue;}
   else {if(ctl==0xffu){count=m.r16(src);src+=2u;}else count=(ctl&0x3fu)+3u;const U off=m.r16(src);src+=2u;from=zero?dst-off:start+off;}
   count=std::min(count,end-dst);
   if((ctl&0xc0u)==0x80u && ctl!=0xfeu && ctl!=0xffu){literal=true;}
   if(literal){while(count--)m.w8(dst++,m.r8(src++));}
   else { (void)short_copy; while(count--) {m.w8(dst,m.r8(from));++dst;++from;} }
 }
 return dst-start;
}

inline U palette_blend(Memory&m,U src,U dst,U lut,U shift,U redshift,U greenmask,U redmask=0xffffffffu){
 const U alpha=m.r8(src);if(!alpha)return 0xffffffffu;
 const U index=m.r16(dst);const U base=lut+index*4u;
 U lane[3]{};for(unsigned c=0;c<3;++c){const U p=m.r8(base+c);lane[c]=(((p*alpha)>>8)+p)>>shift;}
 U red=lane[1]<<redshift;red&=redmask;U green=(lane[2]<<10)&greenmask;U blue=lane[0]>>1u;
 return (blue|red|green)&0xffffu;
}

U mmx_pixels(Memory&m,const Inputs&i,unsigned variant){
 U src=a(i,0),dst=a(i,1),src_pitch=a(i,2),dst_pitch=a(i,3),width=a(i,4),rows=a(i,5),lut=a(i,6);U eax=width;
 while(rows){eax=0;U s=src,d=dst;U count=width;
   while(count){const U alpha=m.r8(s);eax=(eax&0xffffff00u)|alpha;
     if(alpha){const U idx=m.r16(d),base=lut+idx*4u;U lane[3]{};
       for(unsigned c=0;c<3;++c){const U p=m.r8(base+c);lane[c]=std::min(255u,((p*alpha)>>8)+p)>>2u;}
       U blue=lane[0],red=lane[1],green=lane[2],pixel=0;
       switch(variant){
       case 0: pixel=((blue>>1u)|((red<<5u)&0xffffu)|((green<<10u)&0xf800u));break;
       case 1: pixel=(blue|((red<<5u)&0xffffu)|((green<<10u)&0x7c00u));break;
       case 2: pixel=(blue|((red<<6u)&0xffffu)|((green<<10u)&0xf800u));break;
       default: pixel=((blue>>1u)|(((red<<4u)&0x423a0a60u)&0xffffu)|((green<<10u)&0xffffu));break;
       }
       m.w16(d,pixel);eax=(variant==2?red<<6u:variant==3?(red<<4u)&0x423a0a60u:red<<5u);
     }
     ++s;d+=2u;--count;
   }
   src+=src_pitch;dst+=dst_pitch;--rows;
 }
 return eax;
}

U transform_word(Memory&m,U v){
 U ebx=v,edx=v&0xffffu;ebx=(ebx>>8)|(ebx<<24);ebx=(ebx&0xffffff00u)|m.r8(0xa29424u+edx);ebx=(ebx&0xffff00ffu)|(v&0xff00u);U eax=v&0x00ffff00u;ebx=(ebx>>8)|(ebx<<24);eax>>=8;ebx=(ebx&0xffff00ffu)|(m.r8(0xa29424u+eax)<<8);return (ebx>>16)|(ebx<<16);
}
void helper_cb0(Memory&m,U src,U dst,U len){const U n=(len-2u)>>1u;for(U j=0;j<n;++j)m.w32(dst+j*4u,transform_word(m,m.r32(src+j*2u)));const U off=n*2u,ax=m.r16(src+off);m.w8(dst+n*4u,ax);m.w8(dst+n*4u+1u,m.r8(0xa29424u+ax));m.w8(dst+n*4u+2u,ax>>8);m.w8(dst+n*4u+3u,0);}
void helper_d12(Memory&m,U a0,U b,U out,U count){for(U j=0;j<count*2u;++j){const U idx=m.r8(a0+j)|(m.r8(b+j)<<8);m.w8(out+j,m.r8(0xa29424u+idx));}}
}

std::uint32_t fun_0042d640(Memory&m,const Inputs&i){return decode6(m,i);}
std::uint32_t fun_004894b0(Memory&m,const Inputs&i){return blend_ring(m,i);}
std::uint32_t fun_007688b0(Memory&m,const Inputs&i){return lcw_rows(m,i);}
std::uint32_t fun_0076b6c0(Memory&m,const Inputs&i){return pal_rows(m,i);}
std::uint32_t fun_0076cd2b(Memory&m,const Inputs&i){return lcw_expand(m,a(i,0),a(i,1),a(i,2));}
std::uint32_t fun_00783dc0(Memory&m,const Inputs&i){return mmx_pixels(m,i,0);}
std::uint32_t fun_00783f02(Memory&m,const Inputs&i){
 // This sibling uses PSRLW3; the other three use PSRLW2.
 U src=a(i,0),dst=a(i,1),eax=0;
 for(U row=0;row<a(i,5);++row){eax=0;
  for(U x=0;x<a(i,4);++x){const U alpha=m.r8(src+x);eax=(eax&0xffffff00u)|alpha;
   if(alpha){const U lut=a(i,6)+m.r16(dst+x*2u)*4u;U v[3];
    for(unsigned c=0;c<3;++c){const U p=m.r8(lut+c);v[c]=std::min(255u,p+((p*alpha)>>8u))>>3u;}
    eax=v[1]<<5u;m.w16(dst+x*2u,v[0]|eax|((v[2]<<10u)&0x7c00u));
   }
  }
  src+=a(i,2);dst+=a(i,3);
 }
 return eax;
}
std::uint32_t fun_00784040(Memory&m,const Inputs&i){return mmx_pixels(m,i,2);}
std::uint32_t fun_00784180(Memory&m,const Inputs&i){return mmx_pixels(m,i,3);}
std::uint32_t fun_00784b41(Memory&m,const Inputs&i){const U src=a(i,0),dst=a(i,1),rows=a(i,2),width=a(i,3),stride=a(i,4);const U pairs=(width-2u)>>1u;for(U r=0;r<rows;++r){U p=src+r*width,d=dst+r*stride;for(U j=0;j<pairs;++j){m.w32(d+j*4u,transform_word(m,m.r32(p+j*2u)));}const U off=pairs*2u,tail=m.r16(p+off);m.w8(d+pairs*4u,tail);m.w8(d+pairs*4u+1u,m.r8(0xa29424u+tail));m.w8(d+pairs*4u+2u,tail>>8);m.w8(d+pairs*4u+3u,0);}i.arg[2]=0;return i.ax;}
std::uint32_t fun_00784be6(Memory&m,const Inputs&i){const U src=a(i,0),dst=a(i,1),rows=a(i,2),width=a(i,3),stride=a(i,4);for(U r=0;r<rows;++r){const U d=dst+r*(stride&~1u),dup=0x8141a4u;const U pairs=(width-2u)>>1u;for(U j=0;j<pairs;++j){const U v=transform_word(m,m.r32(src+r*width+j*2u));m.w32(d+j*4u,v);m.w32(dup+j*4u,v);}const U tail=m.r16(src+r*width+pairs*2u),at=d+pairs*4u,dt=dup+pairs*4u;m.w8(at,tail);m.w8(dt,tail);m.w8(at+1,m.r8(0xa29424u+tail));m.w8(dt+1,m.r8(0xa29424u+tail));m.w8(at+2,tail>>8);m.w8(dt+2,tail>>8);m.w8(at+3,0);m.w8(dt+3,0);for(U j=0;j<(width>>1u);++j)m.w32(d+(stride>>1u)+j*4u,m.r32(dup+j*4u));}i.arg[2]=0;return i.ax;}
std::uint32_t fun_00784d3b(Memory&m,const Inputs&i){
 U src=a(i,0),dst=a(i,1),n=a(i,2),width=a(i,3);
 if(n<2u)throw std::domain_error("Block72 composed row count requires at least two");
 i.arg[4]>>=1u;const U stride=i.arg[4];
 U wa=0x812da0u,wb=0x8137a0u;
 helper_cb0(m,src,wa,width);std::swap(wa,wb);src+=width;--n;
 do{
  helper_cb0(m,src,wa,width);helper_d12(m,wb,wa,0x8141a4u,width);
  for(U j=0;j<width/2u;++j)m.w32(dst+j*4u,m.r32(wb+j*4u));
  for(U j=0;j<width/2u;++j)m.w32(dst+stride+j*4u,m.r32(0x8141a4u+j*4u));
  dst+=stride*2u;src+=width;--n;std::swap(wa,wb);
 }while(n);
 helper_cb0(m,src,wa,width);
 for(U j=0;j<width/2u;++j)m.w32(dst+j*4u,m.r32(wa+j*4u));
 i.arg[0]=src;i.arg[2]=0;return i.ax;
}
}
