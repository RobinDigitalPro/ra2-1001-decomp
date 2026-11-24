#include "recovered/recovery_b978.hpp"
#include "platform/observed_control978.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b978 {
using U=std::uint32_t;
static U existing(Memory&m,U key){if(m.r32(0xa5b1b8u)!=0x5d6fc0u||!m.r32(0xa5b1a4u)||m.r32(0xa5b1acu)!=7u)throw std::domain_error("978 original callback and positive128bucket table");U row=m.r32(m.r32(0xa5b1a0u)+4u*(key&127u));for(unsigned j=0;j<4u&&row;++j){if(m.r32(row)==key)return row;row=m.r32(row+0x204u);}throw std::domain_error("978 existing bounded key required");}
U fun_005e5050(Memory&m,const Inputs&i){const U row=existing(m,i.arg[0]);m.w32(row+0x24u,i.arg[1]);return 1u;}
U fun_005d9fc0(Memory&m,const Inputs&i){const U row=existing(m,i.cx),kind=m.r32(row+0x70u);const int id=ra2::platform::control978::id(reinterpret_cast<HWND>(std::uintptr_t(i.dx)));if(id==0x71c)throw std::domain_error("978 special helper route excluded");if(kind==0x94u){if(id==0x6ea)return m.r32(0xaa8bb4u);if(id==0x6eb)return m.r32(0xaa8b28u);if(id==0x6ec)return m.r32(0xaa8ba0u);}if((kind==0x103u||kind==0xbc7u)&&id==0x72b)return m.r32(0xaa8bacu);return 0u;}
}
