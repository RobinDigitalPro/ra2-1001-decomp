#include "recovered/construct_b101.hpp"

#include "recovered/allocation_families.hpp"
#include "recovered/construct_b94.hpp"
#include "recovered/leaf_b15_a.hpp"
#include "recovered/leaf_b21_c.hpp"
#include "recovered/preallocated_b66.hpp"
#include "recovered/text_bytes.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::construct_b101 {
using namespace global_b26;
namespace {
constexpr std::uint32_t ones=0xffffffffu;

void append_one(Memory& m,std::uint32_t count_at,std::uint32_t capacity_at,
                std::uint32_t table_at,std::uint32_t object,const char* why) {
    const auto count=m.r32(count_at),capacity=m.r32(capacity_at);
    if(s32(count)<0 || s32(capacity)<0 || s32(count)>=s32(capacity))
        throw std::domain_error(why);
    m.w32(count_at,count+1u);
    m.w32(m.r32(table_at)+count*4u,object);
}

void append_then_index(Memory& m,std::uint32_t count_at,std::uint32_t capacity_at,
                       std::uint32_t table_at,std::uint32_t object,
                       std::uint32_t index_at,const char* why) {
    append_one(m,count_at,capacity_at,table_at,object,why);
    const auto count=m.r32(count_at),table=m.r32(table_at);
    std::uint32_t index=ones;
    for(std::uint32_t n=0;n<count;++n) if(m.r32(table+n*4u)==object){index=n;break;}
    m.w32(index_at,index);
}

void init_base(Memory& m,std::uint32_t object,std::uint32_t source) {
    Inputs in{};in.cx=object;in.arg[0]=source;
    (void)construct_b94::fun_00410580(m,in);
}

void init_ff10(Memory& m,std::uint32_t object) {
    (void)global_b26::fun_0040ff10_composed(m,object);
}

void init_ffd0(Memory& m,std::uint32_t arg) {
    (void)global_b26::fun_0040ffd0_zero_global_composed(m,arg);
}

void call_5bf0(Memory& m,std::uint32_t object) {
    std::array<std::uint8_t,16> bytes{};
    for(std::uint32_t n=0;n<bytes.size();++n)bytes[n]=static_cast<std::uint8_t>(m.r8(object+n));
    leaf::Memory local(bytes.data(),object,static_cast<std::uint32_t>(bytes.size()));
    leaf::Inputs in{};in.cx=object;(void)leaf::fun_00405bf0(local,in);
    for(std::uint32_t n=0;n<bytes.size();++n)m.w8(object+n,bytes[n]);
}

void call_zero_array_helper(Memory& m,std::uint32_t object,bool short_array,
                            std::uint32_t rva) {
    std::array<std::uint8_t,0x18> bytes{};
    for(std::uint32_t n=0;n<bytes.size();++n)bytes[n]=static_cast<std::uint8_t>(m.r8(object+n));
    leaf::Memory local(bytes.data(),object,static_cast<std::uint32_t>(bytes.size()));
    leaf::Inputs in{};in.cx=object;in.arg[0]=0;in.arg[1]=0;
    const AllocationWrapperOperations no_allocation{nullptr,nullptr,nullptr};
    if(rva==0x6cc20u) (void)ra2::recovered::fun_0046cc20(local,in,no_allocation);
    else if(rva==0xfaac0u) (void)ra2::recovered::fun_004faac0(local,in,no_allocation);
    else if(rva==0xfab10u) (void)ra2::recovered::fun_004fab10(local,in,no_allocation);
    else if(rva==0xfab60u) (void)ra2::recovered::fun_004fab60(local,in,no_allocation);
    else if(rva==0x10acb0u) (void)ra2::recovered::fun_0050acb0(local,in,no_allocation);
    else throw std::domain_error("Block101 unexpected nested zero-array helper");
    (void)short_array;
    for(std::uint32_t n=0;n<bytes.size();++n)m.w8(object+n,bytes[n]);
}

void clear_bytes(Memory& m,std::uint32_t address,std::uint32_t count) {
    for(std::uint32_t n=0;n<count;++n)m.w8(address+n,0);
}
void forward_copy_dwords(Memory& m,std::uint32_t dst,std::uint32_t src,std::uint32_t count) {
    for(std::uint32_t n=0;n<count;++n){const auto value=m.r32(src+n*4u);m.w32(dst+n*4u,value);}
}
}

std::uint32_t fun_0041c5c0(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);
    m.w32(c+0x98,ones);m.w32(c+0xa8,ones);
    m.w32(c+0xb8,0);m.w32(c+0xc0,0);m.w32(c+0xc8,0);
    m.w32(c+0xbc,0x3ff00000u);m.w32(c+0xc4,0x3ff00000u);m.w32(c+0xcc,0x3ff00000u);
    m.w8(c+0xd2,1);m.w8(c+0xd3,1);m.w8(c+0xd4,1);
    for(std::uint32_t o=0x9c;o<=0xa0;o+=4)m.w32(c+o,0);
    m.w8(c+0xa4,0);m.w32(c+0xac,0);m.w32(c+0xb0,0);
    m.w8(c+0xd0,0);m.w8(c+0xd1,0);m.w32(c+0xd8,0);m.w32(c+0xdc,0);m.w32(c+0xe0,0);
    m.w32(c+0x104,0);m.w32(c+0x108,0);
    m.w32(c,0x00786780u);m.w32(c+4,0x00786764u);m.w32(c+8,0x0078675cu);m.w32(c+0xc,0x00786754u);
    for(std::uint32_t n=0;n<8;++n)m.w32(c+0xe4+n*4u,0);
    append_one(m,0x00a255a0u,0x00a25598u,0x00a25594u,c,"Block101 0x1c5c0 registry growth excluded");
    return c;
}

std::uint32_t fun_00470b10(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);const auto zero=0u,minus=ones;
    m.w32(c+0x24,m.r32(0x00838f18u));m.w32(c+0x28,zero);m.w32(c+0x2c,zero);m.w32(c+0x30,zero);m.w32(c+0x34,zero);
    m.w32(c+0x38,0xffffu);m.w32(c+0x3c,zero);m.w32(c+0x40,zero);m.w32(c+0x44,minus);m.w32(c+0x48,minus);m.w32(c+0x4c,zero);
    m.w32(c+0x50,minus);m.w32(c+0x54,minus);m.w32(c+0x58,minus);m.w32(c+0x5c,minus);m.w32(c+0x60,minus);m.w32(c+0x64,minus);
    m.w32(c+0x68,zero);m.w32(c+0x6c,zero);m.w32(c+0x70,zero);m.w32(c+0x74,zero);m.w32(c+0x78,zero);
    m.w16(c+0x116,0xffffu);m.w32(c+0x12c,m.r32(c+0x12c)&0xffffffe0u);
    m.w16(c+0x108,0);m.w32(c+0xdc,0);m.w32(c+0xe0,0);m.w32(c+0xe4,0);m.w32(c+0xe8,0);
    m.w32(c+0xec,0);m.w32(c+0xf0,0);for(std::uint32_t o=0x10a;o<=0x114;o+=2)m.w16(c+o,0x3e8u);
    m.w32(c+0xf4,0);m.w32(c+0xf8,0);m.w32(c+0xfc,0);m.w32(c+0x100,0);m.w32(c+0x104,0x10000u);
    m.w8(c+0x118,0xff);for(std::uint32_t o=0x119;o<=0x11f;++o)m.w8(c+o,0);m.w8(c+0x120,0xfe);m.w8(c+0x121,0xfe);m.w8(c+0x122,0);
    m.w32(c+0x130,1);m.w32(c+0x134,0);m.w8(c+0x138,0);m.w32(c+0x13c,0);
    m.w32(c+0x140,m.r32(c+0x140)&0xff800000u);
    m.w32(c,0x00788b04u);m.w32(c+4,0x00788ae8u);m.w32(c+8,0x00788ae0u);m.w32(c+0xc,0x00788ad8u);
    clear_bytes(m,c+0x7c,0x30);clear_bytes(m,c+0xac,0x30);init_ffd0(m,c+4);
    m.w8(c+0x124,0);m.w8(c+0x128,0);return c;
}

std::uint32_t fun_00670790(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);
    m.w32(c+0x9c,0);m.w32(c+0xa0,0);m.w8(c+0xa4,1);m.w8(c+0xa5,0);m.w32(c+0xac,10);m.w32(c+0xa8,0);m.w32(c+0x98,0x007889f4u);
    m.w32(c,0x00796118u);m.w32(c+4,0x007960fcu);m.w32(c+8,0x007960f4u);m.w32(c+0xc,0x007960ecu);
    init_ffd0(m,c+4);
    append_one(m,0x0084e4f0u,0x0084e4e8u,0x0084e4e4u,c,"Block101 0x270790 registry growth excluded");return c;
}

std::uint32_t fun_006a8ec0(Memory& m,const Inputs& i) {
    if(i.arg[0]!=0)throw std::domain_error("Block101 0x2a8ec0 non-null child chain excluded");
    const auto c=i.cx;init_ff10(m,c);
    m.w32(c+0x24,i.arg[0]);m.w32(c+0x28,0);m.w32(c+0x2c,0);m.w32(c+0x30,m.r32(0x00aa7930u));m.w8(c+0x34,0);m.w8(c+0x35,0);
    m.w32(c,0x007975a8u);m.w32(c+4,0x0079758cu);m.w32(c+8,0x00797584u);m.w32(c+0xc,0x0079757cu);
    append_one(m,0x00aa7960u,0x00aa7958u,0x00aa7954u,c,"Block101 0x2a8ec0 registry one growth excluded");
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block101 0x2a8ec0 registry two growth excluded");
    append_one(m,0x00aa8860u,0x00aa8858u,0x00aa8854u,c,"Block101 0x2a8ec0 registry three growth excluded");
    return c;
}

std::uint32_t fun_006e3170(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);
    m.w32(c+0x98,ones);for(std::uint32_t o=0x9c;o<=0x9f;++o)m.w8(c+o,1);m.w8(c+0xa0,0);
    m.w32(c+0xa4,0);m.w32(c+0xa8,0);m.w32(c+0xac,0);m.w32(c+0xb0,0);
    m.w32(c,0x00798934u);m.w32(c+4,0x00798918u);m.w32(c+8,0x00798910u);m.w32(c+0xc,0x00798908u);
    append_one(m,0x00aa87b0u,0x00aa87a8u,0x00aa87a4u,c,"Block101 0x2e3170 registry one growth excluded");
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block101 0x2e3170 registry two growth excluded");
    m.w32(c+0x98,m.r32(0x0084e548u));
    append_one(m,0x0084e548u,0x0084e540u,0x0084e53cu,c,"Block101 0x2e3170 registry three growth excluded");return c;
}

std::uint32_t fun_006b4000(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);
    m.w32(c+0x98,ones);m.w32(c+0x9c,ones);m.w32(c+0xa0,1);
    for(std::uint32_t o=0xa4;o<=0xb3;++o)m.w8(c+o,0);
    m.w32(c+0xb4,7);m.w32(c+0xb8,ones);m.w32(c+0xbc,0);m.w32(c+0xc0,0);m.w32(c+0xc4,0);m.w32(c+0xc8,0);m.w32(c+0xcc,ones);m.w32(c+0xd0,ones);m.w32(c+0xd4,0);m.w32(c+0xd8,0);m.w32(c+0xdc,0);m.w32(c+0xe0,0);m.w32(c+0xe4,9);
    m.w8(c+0xe8,1);m.w8(c+0xe9,0);m.w8(c+0xea,0);m.w8(c+0xeb,0);m.w8(c+0xec,0);m.w8(c+0xed,1);m.w8(c+0xee,0);m.w8(c+0xef,0);
    m.w32(c,0x00797898u);m.w32(c+4,0x0079787cu);m.w32(c+8,0x00797874u);m.w32(c+0xc,0x0079786cu);
    append_then_index(m,0x00a28898u,0x00a28890u,0x00a2888cu,c,c+0x98,"Block101 0x2b4000 registry one growth excluded");
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block101 0x2b4000 registry two growth excluded");return c;
}

std::uint32_t fun_00714cc0(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);
    m.w32(c+0x98,0);m.w32(c+0x9c,0);m.w32(c+0xf8,0);m.w32(c+0xfc,0x3ff00000u);m.w32(c+0x100,0);
    m.w32(c+0x108,0);m.w32(c+0x10c,0);m.w8(c+0x110,1);m.w8(c+0x111,0);m.w32(c+0x118,10);m.w32(c+0x114,0);m.w32(c+0x104,0x0078eb3cu);
    m.w32(c+0x120,0);m.w32(c+0x124,0);m.w32(c+0x128,0);m.w32(c+0x12c,0x3f800000u);m.w8(c+0x130,0);m.w32(c+0x134,5);m.w32(c+0x138,0x3f800000u);m.w32(c+0x13c,0);m.w32(c+0x140,0);
    for(std::uint32_t o=0x144;o<=0x158;++o)m.w8(c+o,0);m.w32(c+0x15c,0);for(std::uint32_t o=0x160;o<=0x166;++o)m.w8(c+o,0);for(std::uint32_t o=0x168;o<=0x174;o+=4)m.w32(c+o,0);
    m.w32(c,0x00799a98u);m.w32(c+4,0x00799a7cu);m.w32(c+8,0x00799a74u);m.w32(c+0xc,0x00799a6cu);init_ffd0(m,c+4);
    append_one(m,0x00821e50u,0x00821e48u,0x00821e44u,c,"Block101 0x314cc0 registry one growth excluded");
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block101 0x314cc0 registry two growth excluded");
    m.w32(c+0xa0,0);m.w32(c+0xa4,0x3ff00000u);forward_copy_dwords(m,c+0xa8,c+0xa0,20);return c;
}

std::uint32_t fun_00727a60(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);
    m.w32(c+0x98,0);m.w32(c+0x9c,1);for(std::uint32_t o=0xa0;o<=0xb8;o+=4)m.w32(c+o,0);
    call_zero_array_helper(m,c+0xbc,true,0x6cc20u);m.w32(c+0xbc+0x14,10);m.w32(c+0xbc+0x10,0);m.w32(c+0xbc,0x007889f4u);
    call_zero_array_helper(m,c+0xd8,false,0x10acb0u);m.w32(c+0xd8+0x14,10);m.w32(c+0xd8+0x10,0);m.w32(c+0xd8,0x0078eb3cu);
    m.w32(c+0xf4,0);m.w32(c+0xf8,0);for(std::uint32_t o=0xfc;o<=0x10e;++o)m.w8(c+o,0);m.w8(c+0x10f,1);
    for(std::uint32_t o=0x110;o<=0x112;++o)m.w8(c+o,0);m.w8(c+0x113,1);for(std::uint32_t o=0x114;o<=0x116;++o)m.w8(c+o,0);
    m.w32(c+0x118,0);for(std::uint32_t o=0x11c;o<=0x123;++o)m.w8(c+o,0);m.w8(c+0x124,10);for(std::uint32_t o=0x125;o<=0x12b;++o)m.w8(c+o,0);m.w32(c+0x12c,0);
    m.w32(c,0x0079a300u);m.w32(c+4,0x0079a2d4u);m.w32(c+8,0x0079a2f8u);m.w32(c+0xc,0x0079a2f0u);init_ffd0(m,c+4);
    append_one(m,0x00821ee0u,0x00821ed8u,0x00821ed4u,c,"Block101 0x327a60 registry growth excluded");return c;
}

std::uint32_t fun_00691dd0(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);
    m.w32(c+0x24,i.arg[0]);m.w32(c+0x28,i.arg[1]);m.w32(c+0x2c,m.r32(0x00a2896cu));m.w32(c+0x34,0);m.w32(c+0x40,0);m.w8(c+0x3c,0);m.w32(c+0x44,0);m.w8(c+0x48,1);
    m.w32(c+0x50,0);m.w32(c+0x4a,m.r32(0x00aa5270u));m.w32(c+0x5c,ones);m.w32(c+0x60,ones);
    m.w8(c+0x54,0);m.w8(c+0x55,0);m.w8(c+0x56,0);m.w8(c+0x57,0);m.w8(c+0x58,0);
    m.w32(c,0x007970b8u);m.w32(c+4,0x0079709cu);m.w32(c+8,0x00797094u);m.w32(c+0xc,0x0079708cu);init_ffd0(m,c+4);
    append_one(m,0x00a1e068u,0x00a1e060u,0x00a1e05cu,c,"Block101 0x291dd0 registry one growth excluded");
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block101 0x291dd0 registry two growth excluded");
    append_one(m,0x00aa8820u,0x00aa8818u,0x00aa8814u,c,"Block101 0x291dd0 registry three growth excluded");return c;
}

std::uint32_t fun_006a29c0(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);m.w32(c+0x24,ones);
    for(std::uint32_t o=0x28;o<=0x50;o+=4)m.w32(c+o,0);
    m.w32(c,0x00797504u);m.w32(c+4,0x007974e8u);m.w32(c+8,0x007974e0u);m.w32(c+0xc,0x007974d8u);
    append_then_index(m,0x00aa78a0u,0x00aa7898u,0x00aa7894u,c,c+0x24,"Block101 0x2a29c0 registry one growth excluded");
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block101 0x2a29c0 registry two growth excluded");
    append_one(m,0x00aa87b0u,0x00aa87a8u,0x00aa87a4u,c,"Block101 0x2a29c0 registry three growth excluded");
    m.w8(c+0x54,0);m.w32(c+0x74,0);return c;
}

std::uint32_t fun_005cde80(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);
    m.w8(c+0x98,0);m.w8(c+0x99,0);m.w8(c+0x9a,0);m.w32(c+0x9c,0);m.w32(c+0xa0,0);m.w32(c+0xa4,0);m.w8(c+0xa8,0);
    for(std::uint32_t o=0xac;o<=0xc4;o+=4)m.w32(c+o,0);
    for(std::uint32_t n=0;n<15;++n){m.w32(c+0xc8+n*8u,0);m.w32(c+0xcc+n*8u,0);}
    for(std::uint32_t n=0;n<15;++n){m.w32(c+0x140+n*8u,0);m.w32(c+0x144+n*8u,0);}
    m.w8(c+0x1b8,0);m.w32(c+0x1bc,0);m.w32(c+0x1c0,ones);m.w32(c+0x1c4,ones);m.w8(c+0x1c8,0);
    m.w8(c+0x1e1,0);m.w8(c+0x1e2,0);m.w8(c+0x1e3,0);m.w8(c+0x1fe,1);m.w8(c+0x200,1);m.w8(c+0x201,1);m.w8(c+0x205,1);
    for(std::uint32_t o=0x1fc;o<=0x20a;++o)if(o!=0x1fe&&o!=0x200&&o!=0x201&&o!=0x205)m.w8(c+o,0);m.w8(c+0x20b,0x80);m.w8(c+0x20c,0x80);m.w8(c+0x20d,0x80);
    m.w32(c+0x210,0x10);for(std::uint32_t o=0x214;o<=0x218;o+=4)m.w32(c+o,0);m.w32(c+0x21c,0);m.w8(c+0x220,0);
    for(std::uint32_t o=0x224;o<=0x230;o+=4)m.w32(c+o,0);m.w8(c+0x234,0);for(std::uint32_t o=0x238;o<=0x260;o+=4)if(o!=0x248&&o!=0x25c)m.w32(c+o,0);m.w8(c+0x248,0);m.w8(c+0x25c,0);
    m.w32(c,0x007926b8u);m.w32(c+4,0x0079269cu);m.w32(c+8,0x00792694u);m.w32(c+0xc,0x0079268cu);
    // Original copies six dwords plus the terminator from the initialized name field.
    for(std::uint32_t n=0;n<6;++n)m.w32(c+0x1c8+n*4u,m.r32(c+0x24+n*4u));m.w8(c+0x1e0,m.r8(c+0x24+24u));
    // 0x36dd10 is called on the original initialized zero bytes at 0x8248a4.
    std::array<std::uint8_t,24> input{},tmp{};for(std::uint32_t n=0;n<24;++n)input[n]=static_cast<std::uint8_t>(m.r8(0x008248a4u+n));
    (void)ra2::recovered::fun_0076dd10(tmp.data(),input.data(),24u);
    for(std::uint32_t n=0;n<24;++n)m.w8(c+0x1e3+n,tmp[n]);m.w8(c+0x1fb,0);
    append_one(m,0x00a5ab08u,0x00a5ab00u,0x00a5aafcu,c,"Block101 0x1cde80 registry growth excluded");return c;
}

std::uint32_t fun_00694650(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);m.w32(c+0x9c,0);m.w32(c+0xa0,ones);m.w32(c+0xa4,ones);m.w32(c+0xa8,ones);m.w32(c+0xac,ones);m.w32(c+0xb0,0x1194u);m.w32(c+0xb4,ones);m.w32(c+0xb8,0);m.w32(c+0xbc,0);m.w32(c+0xc0,0);m.w8(c+0xc4,0);
    m.w32(c+0xe4,ones);m.w8(c+0xdd,0);m.w8(c+0xde,1);m.w8(c+0xdf,0);m.w8(c+0xe0,0);m.w8(c+0xe1,0);m.w8(c+0xe8,0);m.w8(c+0xe9,0);
    m.w32(c,0x00797160u);m.w32(c+4,0x00797144u);m.w32(c+8,0x0079713cu);m.w32(c+0xc,0x00797134u);init_ffd0(m,c+4);
    const auto old=m.r32(0x00a27f98u);m.w32(c+0x98,old);
    append_one(m,0x00a27f98u,0x00a27f90u,0x00a27f8cu,c,"Block101 0x294650 registry growth excluded");
    for(std::uint32_t n=0;n<6;++n)m.w32(c+0xc4+n*4u,m.r32(c+0x24+n*4u));m.w8(c+0xdc,m.r8(c+0x24+24u));return c;
}

std::uint32_t fun_005ca970(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);m.w32(c+0x24,0);m.w32(c+0x28,0);m.w32(c+0x2c,0);m.w32(c+0x6c,0xff);m.w32(c+0x70,0xff);
    m.w8(c+0x76,1);m.w8(c+0x7d,1);m.w8(c+0x85,1);m.w32(c+0x30,0);m.w32(c+0x34,0);m.w32(c+0x38,0);m.w32(c+0x64,ones);m.w8(c+0x68,0);m.w8(c+0x74,0);m.w8(c+0x75,0);m.w8(c+0x77,0);m.w8(c+0x78,0);m.w8(c+0x79,0);m.w8(c+0x7a,0);m.w8(c+0x7b,0);m.w8(c+0x7c,0);m.w32(c+0x80,ones);m.w8(c+0x84,0);
    m.w32(c+0x88,m.r32(0x00a5aa68u));m.w32(c+0x8c,m.r32(0x00a5aa6cu));m.w32(c+0x90,m.r32(0x00a5aa70u));m.w32(c+0x94,0);
    m.w32(c,0x00792458u);m.w32(c+4,0x0079243cu);m.w32(c+8,0x00792434u);m.w32(c+0xc,0x0079242cu);call_5bf0(m,c+0x3c);call_5bf0(m,c+0x50);
    append_one(m,0x00a27fc8u,0x00a27fc0u,0x00a27fbcu,c,"Block101 0x1ca970 registry one growth excluded");
    append_one(m,0x00aa8878u,0x00aa8870u,0x00aa886cu,c,"Block101 0x1ca970 registry two growth excluded");
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block101 0x1ca970 registry three growth excluded");
    append_one(m,0x00aa8770u,0x00aa8768u,0x00aa8764u,c,"Block101 0x1ca970 registry four growth excluded");
    m.w8(c+0x14,m.r8(c+0x14)|2u);return c;
}

std::uint32_t fun_004f85f0(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_base(m,c,i.arg[0]);
    m.w8(c+0x98,0);m.w32(c+0xb4,ones);m.w32(c+0xb8,ones);m.w32(c+0xbc,ones);m.w32(c+0xc0,0);
    for(std::uint32_t o=0xc8;o<=0xe8;o+=8){m.w32(c+o,0);m.w32(c+o+4,0x3ff00000u);}
    m.w32(c+0xf0,0);m.w32(c+0xf8,0);m.w32(c+0xec,0x3ff00000u);m.w32(c+0xf4,0x3ff00000u);m.w32(c+0xfc,0x3ff00000u);
    for(std::uint32_t o=0x100;o<=0x148;o+=4)m.w32(c+o,0x3f800000u);
    call_zero_array_helper(m,c+0x14c,true,0xfaac0u);m.w32(c+0x160,10);m.w32(c+0x15c,0);m.w32(c+0x14c,0x0078e0f8u);
    call_zero_array_helper(m,c+0x168,true,0xfab10u);m.w32(c+0x17c,10);m.w32(c+0x178,0);m.w32(c+0x168,0x0078e0d8u);
    call_zero_array_helper(m,c+0x184,true,0xfab60u);m.w32(c+0x198,10);m.w32(c+0x194,0);m.w32(c+0x184,0x0078e0b8u);
    m.w8(c+0x1a4,0x41);m.w8(c+0x1a5,0);m.w8(c+0x1a6,0);m.w8(c+0x1a7,1);m.w8(c+0x1a8,0);
    m.w32(c,0x0078e048u);m.w32(c+4,0x0078e02cu);m.w32(c+8,0x0078e024u);m.w32(c+0xc,0x0078e01cu);init_ffd0(m,c+4);
    m.w8(c+0x1a0,0);
    append_one(m,0x00a1e048u,0x00a1e040u,0x00a1e03cu,c,"Block101 0xf85f0 registry growth excluded");
    const auto count=m.r32(0x00a1e048u),table=m.r32(0x00a1e03cu);std::uint32_t first=ones,second=ones;
    for(std::uint32_t n=0;n<count;++n)if(m.r32(table+n*4u)==c){if(first==ones)first=n;if(second==ones)second=n;}
    m.w32(c+0xb8,first);m.w32(c+0xb4,second);return c;
}
}
