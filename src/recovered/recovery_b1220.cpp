#include "recovered/recovery_b1220.hpp"
#include <stdexcept>
namespace ra2::recovered::b1220{namespace{void need(bool x,const char*s){if(!x)throw std::domain_error(s);}unsigned byte(Memory&m,unsigned data,unsigned off){return m.r8(data+off);}unsigned word(Memory&m,unsigned data,unsigned off){return byte(m,data,off)|(byte(m,data,off+1u)<<8u)|(byte(m,data,off+2u)<<16u)|(byte(m,data,off+3u)<<24u);}void available(Memory&m,unsigned f,unsigned n){need(m.r32(f)==0x793bf4u&&m.r8(f+24u)==1u&&(m.r32(f+20u)&1u)&&m.r32(f+16u)<=m.r32(f+12u)&&n<=m.r32(f+12u)-m.r32(f+16u),"1220 actual open MemFile complete reads");}}
unsigned run(unsigned r,Memory&m,const Inputs&i,Heap&h){need(r==0x19b9b0u,"1220 exact loader");const unsigned self=i.cx,file=i.arg[0];need(m.r32(self+12u)==0u&&m.r32(file)==0x793bf4u&&m.r32(file+4u)&&m.r8(file+24u)==0u,"1220 actual fresh receiver and borrowed closed MemFile");m.w32(self+12u,0u);
 // Actual62F9B0 Open(1), including IsOpen before/after and exact mode/position stores.
 m.w32(file+16u,0u);m.w32(file+20u,1u);m.w8(file+24u,1u);available(m,file,24u);const auto data=m.r32(file+4u);const unsigned height=word(m,data,16u),width=word(m,data,20u);m.w32(file+16u,24u);m.w32(self+4u,width);m.w32(self+8u,height);need(width>=1u&&width<=4u&&height>=1u&&height<=4u,"1220 bounded positive original dimensions");const unsigned bytes=width*height*48u;const auto out=h.allocate(bytes);need(out!=0u,"1220 genuine positive grid allocation");m.w32(self+12u,out);
 // Actual62FA80 relative Seek(width*16,1), open+mode checked, no clamp reached.
 const unsigned seek=24u+width*16u;need(seek<=m.r32(file+12u),"1220 actual inbounds relative seek");m.w32(file+16u,seek);for(unsigned y=0;y<height;++y)for(unsigned x=0;x<width;++x){available(m,file,48u);const auto pos=m.r32(file+16u);for(unsigned j=0;j<48u;++j)h.w8(out+48u*(y*width+x)+j,m.r8(data+pos+j));m.w32(file+16u,pos+48u);}
 // Read48 produces all12 DWORDs before58CBE0 and REP MOVSD copy them; no private uninitialized values.
 m.w8(file+24u,0u);return 1u;}
unsigned cleanup(Memory&m,unsigned self,Heap&h){const auto p=m.r32(self+12u);need(p!=0u,"1220 actual59B990 positive owned cleanup");const auto eax=h.release(p);need(eax!=0u,"1220 full genuine HeapFree BOOL");m.w32(self+12u,0u);return eax;}
}
