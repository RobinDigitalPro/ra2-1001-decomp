#include "recovered/recovery_b1496.hpp"
namespace ra2::recovered::b1496 {
namespace {using U=std::uint32_t;
std::uint64_t read64(Memory&m,U a){return m.r32(a)|(std::uint64_t(m.r32(a+4))<<32);}
void write64(Memory&m,U a,std::uint64_t v){m.w32(a,U(v));m.w32(a+4,U(v>>32));}
}
std::uint32_t fun_007787f2(Memory&m,const Inputs&i,ExceptionAPI&api){
 if(!platform::x87::same_numeric(platform::x87::capture_host(),i.fp.image))throw std::domain_error("1496 actual hardware entry must match declared FP image");
 const U record=i.arg[0],control=i.arg[1],mask=i.arg[2]&255u,result=i.arg[5];
 if(mask!=8u)throw std::domain_error("1496 finite invalid-operation packet");
 m.w32(record+4,0);m.w32(record+8,0);m.w32(record+12,0);
 i.arg[2]=0xc0000090u;m.w32(record+4,m.r32(record+4)|0x10u);
 constexpr U src[]{0,2,3,4,5},dst[]{4,3,2,1,0};
 for(U k=0;k<5;++k){const U b=1u<<dst[k];m.w32(record+8,(m.r32(record+8)&~b)|(((~m.r32(control)>>src[k])&1u)<<dst[k]));}
 const U status=i.fp.waiting_status();
 for(U k=0;k<5;++k)if(status&(1u<<src[k]))m.w32(record+12,m.r32(record+12)|(1u<<dst[k]));
 switch(m.r32(control)&0xc00u){case 0:m.w32(record,m.r32(record)&~3u);break;case 0x400:m.w32(record,(m.r32(record)&~2u)|1u);break;case 0x800:m.w32(record,(m.r32(record)&~1u)|2u);break;case 0xc00:m.w32(record,m.r32(record)|3u);break;}
 switch(m.r32(control)&0x300u){case 0:m.w32(record,(m.r32(record)&0xffffffebu)|8u);break;case 0x200:m.w32(record,(m.r32(record)&0xffffffe7u)|4u);break;case 0x300:m.w32(record,m.r32(record)&0xffffffe3u);break;default:throw std::domain_error("1496 reserved PC excluded");}
 m.w32(record,(m.r32(record)&0xfffe001fu)|((i.arg[3]&0xfffu)<<5));
 m.w32(record+0x20,(m.r32(record+0x20)|1u)&0xffffffe3u);m.w32(record+0x20,m.r32(record+0x20)|2u);
 i.fp.load64(read64(m,i.arg[4]));write64(m,record+0x10,i.fp.pop64());
 m.w32(record+0x50,(m.r32(record+0x50)|1u)&0xffffffe3u);m.w32(record+0x50,m.r32(record+0x50)|2u);
 i.fp.load64(read64(m,result));write64(m,record+0x40,i.fp.pop64());
 (void)i.fp.status();i.fp.clear_exceptions();
 // The real API sees the exact currently modeled x87 environment. Its genuine
 // poststate is captured before restoring the C++ host environment.
 auto host=platform::x87::capture_host();platform::x87::restore_host(i.fp.image);
 api.raise(i.arg[2],0,1,i.arg.data());
 i.fp.image=platform::x87::capture_host();platform::x87::restore_host(host);
 for(U k=0;k<5;++k)if(m.r8(record+8)&(1u<<dst[k]))m.w32(control,m.r32(control)&~(1u<<src[k]));
 switch(m.r32(record)&3u){case 0:m.w32(control,m.r32(control)&0xfffff3ffu);break;case 1:m.w32(control,(m.r32(control)&0xfffff7ffu)|0x400u);break;case 2:m.w32(control,(m.r32(control)&0xfffffbffu)|0x800u);break;case 3:m.w8(control+1,m.r8(control+1)|0xcu);break;}
 // Preserve the original PC reconstruction mask FFFFF3FF literally.
 switch((m.r32(record)>>2)&7u){case 0:m.w32(control,(m.r32(control)&0xfffff3ffu)|0x300u);break;case 1:m.w32(control,(m.r32(control)&0xfffff3ffu)|0x200u);break;case 2:m.w32(control,m.r32(control)&0xfffff3ffu);break;default:break;}
 i.fp.load64(read64(m,record+0x40));write64(m,result,i.fp.pop64());
 platform::x87::restore_host(i.fp.image);
 return record;
}
}
