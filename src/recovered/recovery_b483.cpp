#include "recovery_b483.hpp"
#include "platform/observed_file483.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b483 {
using U=std::uint32_t;using File=platform::file483::File;
namespace {void live(Memory&m,U p){if(m.r32(p)!=0x793c84||m.r32(p+0x10)!=0xffffffffu||m.r32(p+8)!=0||m.r32(p+0xc)!=0xffffffffu||!m.r32(p+0x14))throw std::domain_error("483 closed named raw-file route");}}
U fun_006301a0(Memory&m,const Inputs&i){live(m,i.cx);if(i.arg[0]!=1)throw std::domain_error("483 read-only existing fixture");m.w32(i.cx+4,1);m.w32(i.cx+0x10,File::open(true));return 1;}
U fun_00630240(Memory&m,const Inputs&i){live(m,i.cx);U h=0;
 if(i.arg[0]){auto call=i;call.arg[0]=1;fun_006301a0(m,call);h=m.r32(i.cx+0x10);}else{h=File::open(false);m.w32(i.cx+0x10,h);}
 const auto result=File::close(h);m.w32(i.cx+0x10,0xffffffffu);return (result&0xffffff00u)|1;
}
}
