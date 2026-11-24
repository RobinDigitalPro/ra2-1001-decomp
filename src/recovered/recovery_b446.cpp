#include "recovered/recovery_b446.hpp"
#include "platform/x87_scalar_b46.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b446 {
namespace {
void need(bool ok,const char* text){if(!ok)throw std::domain_error(text);}
std::uint64_t read64(Memory&m,std::uint32_t a){return std::uint64_t(m.r32(a))|(std::uint64_t(m.r32(a+4u))<<32);}
std::uint64_t numerator(ra2::platform::x87::State&fp,std::uint32_t health){
 fp.load_integer32(health);return fp.pop64();
}
bool compare_pop(ra2::platform::x87::State&fp,Memory&m,std::uint32_t address){
 fp.compare_pop64(read64(m,address));
 return (fp.status()&0x4100u)!=0u; // x87 C0|C3: ST0 less-than-or-equal to memory operand.
}
}

std::uint32_t fun_005ccd40(Memory&m,const Inputs&i){
 const auto object=i.cx;
 const auto vtable=m.r32(object);
 need(vtable==0x00787bbcu,"B446 requires constructor-proven BuildingClass vptr");
 need(m.r32(vtable+0x84u)==0x004538b0u,"B446 requires original BuildingClass +84 property getter");
 const auto property=m.r32(object+0x418u);
 need(property!=0u,"B446 positive health route needs initialized property object");
 const auto config=m.r32(0x00821b88u);
 need(config!=0u,"B446 health route requires initialized global threshold table");
 const auto health=m.r32(object+0x6cu);
 const auto high=config+0x1370u,low=config+0x1368u;
 auto& fp=i.fp;
 const auto first_numerator=numerator(fp,health);
 fp.load_integer32(m.r32(property+0xa0u));
 ra2::platform::x87_scalar_b46::reverse_divide64(fp,first_numerator);
 if(compare_pop(fp,m,high)&&static_cast<std::int32_t>(health)>0)return 0u;

 const auto second_numerator=numerator(fp,health);
 fp.load_integer32(m.r32(property+0xa0u));
 ra2::platform::x87_scalar_b46::reverse_divide64(fp,second_numerator);
 if(compare_pop(fp,m,high))return 2u;

 const auto third_numerator=numerator(fp,health);
 fp.load_integer32(m.r32(property+0xa0u));
 ra2::platform::x87_scalar_b46::reverse_divide64(fp,third_numerator);
 return compare_pop(fp,m,low)?1u:2u;
}
}
