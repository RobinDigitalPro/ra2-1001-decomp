#include "recovery_b334.hpp"
#include "recovered/scanner_input.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::recovery_b334 {
using namespace global_b26;
namespace {
constexpr std::uint32_t format_va=0x007c1640u, no_angle_va=0x007b8e5cu, no_plain_va=0x007b907cu;
constexpr std::uint32_t first_table_global=0x00a27fa4u, first_count_global=0x00a27fb0u, compare_mode_global=0x00b10530u;
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
struct ScanOutputs { std::uint32_t* integer; std::uint8_t* string; };
std::int32_t finite_percent_d_comma_s(ScannerBuffer& s,const std::uint8_t* f,void* va,void*) {
    need(f[0]=='%'&&f[1]=='d'&&f[2]==','&&f[3]=='%'&&f[4]=='s'&&f[5]==0,"B334 uses pinned %d,%s format");
    auto& out=*static_cast<ScanOutputs*>(va); auto* p=s.cursor; unsigned number=0,digits=0;
    while(*p>='0'&&*p<='9'){number=number*10u+unsigned(*p-'0');++p;++digits;need(digits<=3u,"B334 decimal field is bounded to three digits");}
    if(!digits)return 0;
    *out.integer=number;
    if(*p++!=',')return 1;
    unsigned length=0;
    while(*p&&*p!=' '&&*p!='\t'&&*p!='\r'&&*p!='\n'){
        need(length<7u,"B334 name fits its 8-byte original comparison window");out.string[length++]=*p++;
    }
    if(!length)return 1;
    out.string[length]=0;s.cursor=p;s.remaining=0;return 2;
}
std::array<std::uint8_t,64> read_guest_string(const Memory&m,std::uint32_t p){
    need(p!=0,"B334 input string is nonnull");std::array<std::uint8_t,64> out{};
    for(unsigned n=0;n<out.size();++n){out[n]=std::uint8_t(m.r8(p+n));if(!out[n])return out;}
    throw std::domain_error("B334 input is at most 63 bytes");
}
std::array<std::uint8_t,6> read_format(const Memory&m){std::array<std::uint8_t,6> f{};for(unsigned n=0;n<f.size();++n)f[n]=std::uint8_t(m.r8(format_va+n));return f;}
std::uint8_t lower_ascii(std::uint8_t c){return c>='A'&&c<='Z'?std::uint8_t(c+0x20u):c;}
bool equal_guest(const std::uint8_t* local,const Memory&m,std::uint32_t guest){
    // The selected 0x76d860 mode-zero route compares at most eight bytes,
    // ASCII-folding A..Z. Inputs and pinned row names terminate within 8.
    for(unsigned n=0;n<8;++n){auto a=local[n],b=std::uint8_t(m.r8(guest+n));if(lower_ascii(a)!=lower_ascii(b))return false;if(!a)return true;}
    return false;
}
std::uint32_t find_first_table(const Memory&m,const std::uint8_t* name){
    need(m.r32(compare_mode_global)==0,"B334 selects accepted 0x76d860 mode zero");
    if(equal_guest(name,m,no_angle_va)||equal_guest(name,m,no_plain_va))return 0xffffffffu;
    const auto count=m.r32(first_count_global),base=m.r32(first_table_global);
    need(count==1u&&base,"B334 fixture has one live first-table row");
    const auto row=m.r32(base);
    need(row!=0,"B334 first-table row is nonnull");
    return equal_guest(name,m,row+0x24u)?0u:0xffffffffu;
}
}
std::uint32_t fun_004b4570(Memory&m,const Inputs&i){
    const auto receiver=i.cx,input_pointer=i.arg[0];
    need(receiver&&input_pointer,"B334 requires nonnull receiver and input text");
    auto input=read_guest_string(m,input_pointer);auto format=read_format(m);
    need(format==std::array<std::uint8_t,6>{'%','d',',','%','s',0},"B334 format bytes must be original %d,%s");
    std::array<std::uint8_t,64> parsed_name{};
    ScanOutputs out{&i.arg[0],parsed_name.data()};
    // Original root zeros both receiver dwords before scanning; it then writes
    // parsed caller arg0 to +0 and the found row pointer to +4.
    m.w32(receiver,0);m.w32(receiver+4u,0);
    const auto assigned=fun_0076f070(input.data(),format.data(),&out,finite_percent_d_comma_s,nullptr);
    need(assigned==2,"B334 positive route scans both decimal and name fields");
    need(parsed_name[0]!=0,"B334 requires a nonempty scanned name");
    const auto index=find_first_table(m,parsed_name.data());
    need(index==0u,"B334 requires a positive first-row exact name hit");
    const auto base=m.r32(first_table_global),row=m.r32(base+index*4u);
    m.w32(receiver,i.arg[0]);
    m.w32(receiver+4u,row);
    return receiver;
}
}
