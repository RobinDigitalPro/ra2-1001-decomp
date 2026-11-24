#include "recovery_b348.hpp"
#include "platform/x87_b61.hpp"
#include "platform/x87_extended_b40.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b348 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}

std::uint32_t pinned_positive_sqrt(Memory& m,Inputs const& i,std::uint64_t sum) {
    auto& fp=i.fp;
    fp.load64(sum); // 0x4ba080: FLD qword [ESP+4]
    fp.compare32(m.r32(0x00785738u)); // FCOM zero on the selected route
    need((fp.status()&0x4000u)==0,"348 excludes zero squared distance");
    fp.compare32(m.r32(0x00785738u));
    need((fp.status()&0x4100u)==0,"348 excludes negative/zero squared distance");
    const auto bits=fp.pop32(); // FSTP float
    std::uint32_t ecx=bits&0x007fffffu;
    std::uint32_t eax=(bits>>23)-0x7fu;
    if((eax&1u)!=0u)ecx|=0x00800000u;
    const auto ax=static_cast<std::uint16_t>(eax);
    const auto half=static_cast<std::int16_t>(ax)>>1;
    eax=static_cast<std::uint32_t>(static_cast<std::int32_t>(half))+0x7fu;
    ecx>>=10;
    const auto table=m.r32(0x0080013cu+ecx*4u);
    eax<<=23;
    const auto result=table+eax;
    need((sum==0x4039000000000000ull && result==0x40a00000u) ||
         (sum==0x40f9000000000000ull && result==0x43a00000u),
         "348 requires the pinned exact square-root table rows 25->5 and 102400->320");
    fp.load32(result); // 0x4ba080: FLD synthesized float result
    return result;
}

std::uint32_t exact_distance(Memory& m,Inputs const& i,std::int32_t dx,std::int32_t dy,std::int32_t dz) {
    auto& fp=i.fp;
    // Original FILD sequence at 0x44d7d0, 0x44d7de, 0x44d7e2.
    fp.load_integer32(static_cast<std::uint32_t>(dy));
    fp.load_integer32(static_cast<std::uint32_t>(dz));
    fp.load_integer32(static_cast<std::uint32_t>(dx));
    // Exact register operations at 0x44d7e6..0x44d7f4.
    fp.load_st0(); ra2::platform::x87_extended::multiply_st1(fp);
    fp.load_st2(); ra2::platform::x87_extended::multiply_st3(fp);
    fp.add_pop();
    ra2::platform::x87_b61::reg<0xd9c3>(fp); ra2::platform::x87_extended::multiply_st4(fp);
    fp.add_pop();
    const auto sum=fp.pop64(); // FSTP qword local at 0x44d7f6
    ra2::platform::x87_b61::reg<0xddd8>(fp);
    ra2::platform::x87_b61::reg<0xddd8>(fp);
    ra2::platform::x87_b61::reg<0xddd8>(fp);
    need(sum==0x4039000000000000ull || sum==0x40f9000000000000ull,
         "348 only models exact 3-4-0 or 192-256-0 squares");
    (void)pinned_positive_sqrt(m,i,sum);
    need(fp.control()==m.r32(0x007c3a04u),"348 excludes the 0x76aa50 control-word replacement route");
    return static_cast<std::uint32_t>(fp.pop_integer64()); // exact FISTP qword, then EAX low dword
}
}

std::uint32_t fun_0044d790(Memory& m,const Inputs& i) {
    const auto receiver=i.cx;
    const auto other=i.arg[0];
    need(receiver&&other,"348 requires two nonnull coordinate objects");
    const auto vptr=m.r32(receiver);
    need(vptr==0x0078612cu && m.r32(vptr+0x48u)==0x005cd4d0u &&
         m.r32(other)==vptr,"348 uses the constructor-proven 0x78612c class on both getters");
    const auto x1=static_cast<std::int32_t>(m.r32(receiver+0x88u));
    const auto y1=static_cast<std::int32_t>(m.r32(receiver+0x8cu));
    const auto z1=static_cast<std::int32_t>(m.r32(receiver+0x90u));
    const auto x2=static_cast<std::int32_t>(m.r32(other+0x88u));
    const auto y2=static_cast<std::int32_t>(m.r32(other+0x8cu));
    const auto z2=static_cast<std::int32_t>(m.r32(other+0x90u));
    const auto dx=static_cast<std::int64_t>(x1)-x2;
    const auto dy=static_cast<std::int64_t>(y1)-y2;
    const auto dz=static_cast<std::int64_t>(z1)-z2;
    need((dx==3&&dy==4&&dz==0)||(dx==-3&&dy==-4&&dz==0)||
         (dx==192&&dy==256&&dz==0)||(dx==-192&&dy==-256&&dz==0),
         "348 fixture is limited to the pinned exact norm routes");
    const auto distance=exact_distance(m,i,static_cast<std::int32_t>(dx),
                                       static_cast<std::int32_t>(dy),
                                       static_cast<std::int32_t>(dz));
    const auto inner=m.r32(receiver+0x418u);
    need(inner!=0u,"348 requires the observed receiver+0x418 pointee");
    const auto limit=m.r32(inner+0x1390u);
    need(limit<=0x100u,"348 bounds the shifted signed limit");
    const auto rhs=limit<<8;
    const auto less_equal=static_cast<std::int32_t>(distance)<=static_cast<std::int32_t>(rhs);
    return (distance&0xffffff00u)|(less_equal?1u:0u); // MOV AL,CL preserves EAX[31:8]
}
}
