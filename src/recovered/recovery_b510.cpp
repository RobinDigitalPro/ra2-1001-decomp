#include "recovery_b510.hpp"
#include "allocation_wrappers.hpp"
#include <stdexcept>
namespace ra2::recovery_b510 {
namespace {
unsigned allocate(unsigned n,unsigned flag,void* context){
 if(flag!=1)throw std::domain_error("510 original new wrapper flag");
 return static_cast<Heap*>(context)->allocate(n);
}
void empty_vector(Heap&h,unsigned p,unsigned vptr){
 h.w32(p+4,0);h.w32(p+8,0);h.w8(p+12,1);h.w8(p+13,0);
 h.w32(p,vptr);h.w32(p+20,10);h.w32(p+16,0);
}
}
unsigned fun_005fbd00(Memory&m,const Inputs&i,Heap&h){
 const auto self=i.cx;const ra2::recovered::AllocationWrapperOperations op{allocate,nullptr,&h};
 m.w32(self,0xffffffff);
 const auto a=ra2::recovered::fun_0076d957(24,op);
 if(!a)throw std::domain_error("510 first allocation success required");
 empty_vector(h,a,0x78955c);m.w32(self+4,a);
 const auto b=ra2::recovered::fun_0076d957(24,op);
 if(!b)throw std::domain_error("510 second allocation success required");
 empty_vector(h,b,0x792b18);m.w32(self+8,b);
 const auto c=ra2::recovered::fun_0076d957(16,op);
 if(!c)throw std::domain_error("510 owner allocation success required");
 h.w32(c+4,0x5fb1f0);h.w32(c+8,31);h.w32(c+12,10);
 const auto array=ra2::recovered::fun_0076d957(0x2ec,op);
 if(!array)throw std::domain_error("510 array allocation success required");
 h.w32(array,31);
 for(unsigned k=0;k<31;++k)empty_vector(h,array+4+24*k,0x792b38);
 h.w32(c,array+4);
 // The original second pass writes the same growth value to every vector.
 for(unsigned k=0;k<31;++k)h.w32(array+4+24*k+20,10);
 m.w32(self+12,c);return self;
}
}
