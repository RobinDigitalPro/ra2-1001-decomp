#include "recovery_b336.hpp"
#include "construct_b101.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b336 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::uint16_t u16(const Memory&m,std::uint32_t p){return std::uint16_t(m.r8(p))|std::uint16_t(m.r8(p+1u)<<8);}
std::uint32_t u32(const Memory&m,std::uint32_t p){return std::uint32_t(u16(m,p))|(std::uint32_t(u16(m,p+2u))<<16);}
std::uint32_t pull_literal_chunk(Memory&m,Heap&heap,std::uint32_t source,std::uint32_t output,
                                 std::uint32_t expected_raw,std::array<std::uint8_t,16>& out,
                                 std::uint32_t& offset){
    const auto compressed=u16(m,source+offset),raw=u16(m,source+offset+2u);
    need(raw==expected_raw&&compressed==std::uint32_t(raw)+4u,
         "B336 uses the exact 53c600 short-literal output-size relation");
    const auto p=source+offset+4u;
    need(m.r8(p)==raw+17u,"B336 literal token matches 53c600's short-input encoding");
    const auto temp=heap.allocate(compressed);
    need(temp!=0,"B336 excludes temporary compressed-buffer allocation failure");
    for(std::uint32_t n=0;n<compressed;++n)heap.w8(temp+n,std::uint8_t(m.r8(p+n)));
    for(std::uint32_t n=0;n<raw;++n){out[n]=std::uint8_t(m.r8(p+1u+n));heap.w8(output+n,out[n]);}
    need(m.r8(p+1u+raw)==0x11u&&m.r8(p+2u+raw)==0&&m.r8(p+3u+raw)==0,
         "B336 compressed span has the exact 53c600 end marker and zero tail");
    offset+=4u+compressed;
    (void)heap.release(temp);
    return raw;
}
}

std::uint32_t fun_0054b550(Memory&m,const Inputs&i,Heap&heap){
    constexpr std::uint32_t x_global=0x00a56e5cu,y_global=0x00a56e5eu;
    const auto manager=i.cx,source_object=i.arg[0];
    need(manager&&source_object,"B336 positive route requires manager and initialized source object");
    need(m.r32(source_object)==0x007899e8u,"B336 source object uses the caller-proven vtable");
    const auto base=m.r32(source_object+0x0cu),length=m.r32(source_object+0x10u);
    auto cursor=m.r32(source_object+0x18u);
    need(m.r32(source_object+8)==0&&base&&cursor==0&&length>=30,"B336 source has exactly two writer-compatible chunks");
    const auto output=heap.allocate(0x4000u);
    need(output!=0,"B336 excludes the 0x4000 reader-buffer allocation failure");
    std::array<std::uint8_t,16> first{};
    std::array<std::uint8_t,16> second{};
    auto offset=cursor;
    pull_literal_chunk(m,heap,base,output,10u,first,offset);
    pull_literal_chunk(m,heap,base,output,4u,second,offset);
    need(offset==30u&&length==30u,"B336 byte source spans exactly both encoded records");
    m.w32(source_object+0x18u,offset);

    const auto x=std::int16_t(std::uint16_t(first[0])|(std::uint16_t(first[1])<<8));
    const auto y=std::int16_t(std::uint16_t(first[2])|(std::uint16_t(first[3])<<8));
    const auto packed=(std::uint32_t(std::uint16_t(y))<<9)+std::uint32_t(std::uint16_t(x));
    need(x==1&&y==0&&packed==1u,"B336 bounded positive coordinate resolves row one");
    need(u16(m,x_global)==0&&u16(m,y_global)==0,"B336 sentinel globals are zero");
    const auto cells=m.r32(manager+0x138u);
    const auto cell=u32(m,cells+4u);
    need(cell!=0&&cell!=0x00a57610u,"B336 row one is a distinct live map cell");

    m.w32(cell+0x38u,0xffffu);
    const auto raw_value=std::uint32_t(first[4])|(std::uint32_t(first[5])<<8)|
        (std::uint32_t(first[6])<<16)|(std::uint32_t(first[7])<<24);
    m.w32(cell+0x38u,raw_value);
    const auto current=m.r32(cell+0x38u);
    const auto count=m.r32(0x00a3ab10u),table=m.r32(0x00a3ab04u);
    need(count==1u&&table,"B336 conversion table has one initialized entry");
    const auto entry=m.r32(table);
    const auto threshold=m.r32(entry),increment=m.r32(entry+4u);
    need(threshold==0x100u&&increment==2u,"B336 uses the exact conversion row");
    m.w32(cell+0x38u,current==0xffffu?current:(std::int32_t(threshold)>std::int32_t(current)?current:current+increment));
    // The stream's 0x120 is converted by the one threshold/increment row.
    // Root fields are +0x11a and +0x11b (not +0x152/+0x153).
    m.w8(cell+0x11au,first[8]);m.w8(cell+0x11bu,first[9]);

    const auto sx=std::int16_t(std::uint16_t(second[0])|(std::uint16_t(second[1])<<8));
    const auto sy=std::int16_t(std::uint16_t(second[2])|(std::uint16_t(second[3])<<8));
    need(sx==0&&sy==0&&u16(m,x_global)==0&&u16(m,y_global)==0,
         "B336 second coordinate is the successful zero sentinel");
    Inputs reset{};reset.cx=0x00a57610u;(void)construct_b101::fun_00470b10(m,reset);
    (void)heap.release(output);
    m.w32(source_object+8,0); // Actual6906b0 detaches the temporary reader.
    return (source_object&0xffffff00u)|1u;
}

std::uint32_t fun_0054b670(Memory&m,const Inputs&i,Heap&heap){
    constexpr std::uint32_t x_global=0x00a56e5cu,y_global=0x00a56e5eu;
    const auto manager=i.cx,source_object=i.arg[0];
    need(manager&&source_object,"B336 sibling positive route requires manager and initialized source object");
    need(m.r32(source_object)==0x007899e8u,"B336 source object uses the caller-proven vtable");
    const auto base=m.r32(source_object+0x0cu),length=m.r32(source_object+0x10u);
    const auto cursor=m.r32(source_object+0x18u);
    need(m.r32(source_object+8)==0&&base&&cursor==0&&length==31u,"B336 sibling source has the exact three-attribute stream extent");
    const auto output=heap.allocate(0x4000u);
    need(output!=0,"B336 sibling excludes the 0x4000 reader-buffer allocation failure");
    std::array<std::uint8_t,16> first{},second{};auto offset=cursor;
    pull_literal_chunk(m,heap,base,output,11u,first,offset);pull_literal_chunk(m,heap,base,output,4u,second,offset);
    need(offset==31u,"B336 sibling byte source spans both encoded chunks");m.w32(source_object+0x18u,offset);
    const auto x=std::int16_t(std::uint16_t(first[0])|(std::uint16_t(first[1])<<8));
    const auto y=std::int16_t(std::uint16_t(first[2])|(std::uint16_t(first[3])<<8));
    const auto packed=(std::uint32_t(std::uint16_t(y))<<9)+std::uint32_t(std::uint16_t(x));
    need(x==1&&y==0&&packed==1u,"B336 sibling positive coordinate resolves row one");
    need(u16(m,x_global)==0&&u16(m,y_global)==0,"B336 sibling sentinel globals are zero");
    const auto cells=m.r32(manager+0x138u),cell=u32(m,cells+4u);
    need(cell&&cell!=0x00a57610u,"B336 sibling row one is a distinct live map cell");
    m.w32(cell+0x38u,0xffffu);
    const auto raw_value=std::uint32_t(first[4])|(std::uint32_t(first[5])<<8)|(std::uint32_t(first[6])<<16)|(std::uint32_t(first[7])<<24);
    m.w32(cell+0x38u,raw_value);const auto current=m.r32(cell+0x38u);
    const auto count=m.r32(0x00a3ab10u),table=m.r32(0x00a3ab04u);
    need(count==1u&&table,"B336 sibling conversion table has one initialized entry");
    const auto entry=m.r32(table),threshold=m.r32(entry),increment=m.r32(entry+4u);
    need(threshold==0x100u&&increment==2u,"B336 sibling uses the exact conversion row");
    m.w32(cell+0x38u,current==0xffffu?current:(std::int32_t(threshold)>std::int32_t(current)?current:current+increment));
    m.w8(cell+0x11au,first[8]);m.w8(cell+0x11bu,first[9]);m.w8(cell+0x119u,first[10]);
    const auto sx=std::int16_t(std::uint16_t(second[0])|(std::uint16_t(second[1])<<8));
    const auto sy=std::int16_t(std::uint16_t(second[2])|(std::uint16_t(second[3])<<8));
    need(sx==0&&sy==0&&u16(m,x_global)==0&&u16(m,y_global)==0,"B336 sibling second coordinate is the successful sentinel");
    Inputs reset{};reset.cx=0x00a57610u;(void)construct_b101::fun_00470b10(m,reset);
    (void)heap.release(output);
    m.w32(source_object+8,0); // Actual6906b0 detaches the temporary reader.
    return (source_object&0xffffff00u)|1u;
}
}
