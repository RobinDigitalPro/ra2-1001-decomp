#include "recovered/recovery_b875.hpp"
#include <array>
namespace ra2::recovered::recovery_b875 {
U fun_0077a184(Memory&m,const Inputs&i,platform::ordinary_heap::Heap&h,const LocaleOps&ops){if(!i.arg[0]||m.r32(0xb10828)!=2)throw std::domain_error("875 positive cachedANSI route");U daylc=m.r16(0xb106ea),formatlc=m.r16(0xb106ec),dest=i.arg[0];
 auto put=[&](U lc,U type,U off){std::array<char,128>buf{};int n=ops.ansi(ops.context,lc,type,buf.data(),128);if(n<=0||n>64||buf[n-1])throw std::domain_error("875 successful boundedlocalequery");U p=h.allocate(n);if(!p)throw std::domain_error("875 successfulallocation");m.w32(dest+off,p);for(int k=0;k<n;++k)h.w8(p+k,std::uint8_t(buf[k]));};
 for(U k=0;k<7;++k)put(daylc,0x31+k,k<6?4+4*k:0);
 for(U k=0;k<7;++k)put(daylc,0x2a+k,k<6?0x20+4*k:0x1c);
 for(U k=0;k<12;++k)put(daylc,0x44+k,0x38+4*k);
 for(U k=0;k<12;++k)put(daylc,0x38+k,0x68+4*k);
 put(daylc,0x28,0x98);put(daylc,0x29,0x9c);put(formatlc,0x1f,0xa0);put(formatlc,0x20,0xa4);put(formatlc,0x1003,0xa8);return 0;}
}
