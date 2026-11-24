#include "recovered/construct_b94.hpp"

#include "recovered/leaf_b15_a.hpp"
#include "recovered/leaf_b17_scalars.hpp"
#include "recovered/preallocated_b66.hpp"
#include "recovered/text_bytes.hpp"

#include <array>
#include <memory>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&, const Inputs&);
std::uint32_t fun_0047b3e0(Memory&, const Inputs&);
}

namespace ra2::recovered::construct_b94 {
using namespace global_b26;
namespace {
constexpr std::uint32_t zero=0;

void require_direct(std::uint32_t count,std::uint32_t capacity,const char* message) {
    if (s32(count)<0 || s32(capacity)<0 || s32(count)>=s32(capacity))
        throw std::domain_error(message);
}

void append_one(Memory& m,std::uint32_t count_at,std::uint32_t capacity_at,
                std::uint32_t table_at,std::uint32_t object,const char* message) {
    const auto capacity=m.r32(capacity_at),count=m.r32(count_at);
    require_direct(count,capacity,message);
    m.w32(count_at,count+1u);
    m.w32(m.r32(table_at)+count*4u,object);
}

std::uint32_t init_ff10(Memory& m,std::uint32_t object) {
    return fun_0040ff10_composed(m,object);
}

void compose_5bf0(Memory& m,std::uint32_t object) {
    std::array<std::uint8_t,16> bytes{};
    for (unsigned n=0;n<bytes.size();++n) bytes[n]=static_cast<std::uint8_t>(m.r8(object+n));
    leaf::Memory local(bytes.data(),object,static_cast<std::uint32_t>(bytes.size()));
    leaf::Inputs in{}; in.cx=object;
    (void)leaf::fun_00405bf0(local,in);
    for (unsigned n=0;n<bytes.size();++n) m.w8(object+n,bytes[n]);
}

// 0x545500 consumes the packed caller coordinate through a pointer to two
// little-endian WORDs. A private guest32 view supplies that observed stack
// input and calls the accepted lookup implementation without changing caller
// stack memory or the fixture's declared spans.
std::uint32_t coordinate_index(std::uint32_t packed) {
    const auto x=sx16(packed),y=sx16(packed>>16);
    const auto index=static_cast<std::uint32_t>(static_cast<std::int32_t>(y)*512+
                                                static_cast<std::int32_t>(x));
    if (s32(index)<0 || index>=0x40000u)
        throw std::domain_error("Block94 lookup coordinate outside prepared table domain");
    return index;
}

std::uint32_t composed_cell_lookup(Memory& source,std::uint32_t packed,
                                  std::uint32_t original_cell) {
    constexpr std::uint32_t context=0x81a820u;
    constexpr std::uint32_t coord_address=0x7e000000u;
    constexpr std::uint32_t table_address=0x7e100000u;
    constexpr std::uint32_t cell_address=0x7e300000u;
    const auto index=coordinate_index(packed);

    std::array<std::uint8_t,0x1000> context_page{};
    const auto context_base=context&~0xfffu;
    for (unsigned n=0;n<context_page.size();++n)
        context_page[n]=static_cast<std::uint8_t>(source.r8(context_base+n));
    std::vector<std::uint8_t> table_bytes(static_cast<std::size_t>(index)*4u+4u);
    std::array<std::uint8_t,4> coord_bytes{};
    std::array<std::uint8_t,0x120> cell_bytes{};
    table_bytes[index*4u]=static_cast<std::uint8_t>(cell_address);
    table_bytes[index*4u+1u]=static_cast<std::uint8_t>(cell_address>>8);
    table_bytes[index*4u+2u]=static_cast<std::uint8_t>(cell_address>>16);
    table_bytes[index*4u+3u]=static_cast<std::uint8_t>(cell_address>>24);
    for (unsigned n=0;n<4;++n) coord_bytes[n]=static_cast<std::uint8_t>(packed>>(n*8));
    cell_bytes[0x11b]=static_cast<std::uint8_t>(source.r8(original_cell+0x11bu));
    const auto cell_state=source.r32(original_cell+0x38u);
    for (unsigned n=0;n<4;++n) cell_bytes[0x38+n]=static_cast<std::uint8_t>(cell_state>>(n*8));

    leaf::Memory context_span(context_page.data(),context_base,0x1000u);
    leaf::Memory coord_span(coord_bytes.data(),coord_address,4u);
    leaf::Memory table_span(table_bytes.data(),table_address,static_cast<std::uint32_t>(table_bytes.size()));
    leaf::Memory cell_span(cell_bytes.data(),cell_address,static_cast<std::uint32_t>(cell_bytes.size()));
    Memory local;
    local.add(context_span); local.add(coord_span); local.add(table_span); local.add(cell_span);
    local.w32(context+0x138u,table_address);

    // 0x7b3e0 reads six fixed global range starts. Copy exactly the pages
    // containing those accepted helper inputs into stable local views.
    constexpr std::array<std::uint32_t,2> bases={0x00a3a000u,0x00a54000u};
    std::array<std::array<std::uint8_t,0x1000>,bases.size()> global_bytes{};
    std::array<std::unique_ptr<leaf::Memory>,bases.size()> global_spans{};
    for (std::size_t p=0;p<bases.size();++p) {
        for (unsigned n=0;n<0x1000;++n)
            global_bytes[p][n]=static_cast<std::uint8_t>(source.r8(bases[p]+n));
        global_spans[p]=std::make_unique<leaf::Memory>(global_bytes[p].data(),bases[p],0x1000u);
        local.add(*global_spans[p]);
    }
    local.w32(table_address+index*4u,cell_address);
    Inputs lookup{}; lookup.cx=context; lookup.arg[0]=coord_address;
    const auto first=fun_00545500(local,lookup);
    const auto observed=local.r8(first+0x11bu);
    const auto second=fun_00545500(local,lookup);
    Inputs convert{}; convert.cx=second;
    const auto converted=fun_0047b3e0(local,convert);
    return (observed&0xffu) | ((converted&0xffu)<<8);
}
}

std::uint32_t fun_00410580(Memory& m,const Inputs& i) {
    const auto receiver=i.cx,source=i.arg[0];
    (void)init_ff10(m,receiver);
    m.w8(receiver+0x24u,0); m.w8(receiver+0x3du,0); m.w8(receiver+0x64u,0);
    m.w32(receiver,0x00785e88u); m.w32(receiver+4u,0x00785e6cu);
    m.w32(receiver+8u,0x00785e64u); m.w32(receiver+0xcu,0x00785e5cu);

    std::array<std::uint8_t,49> local{};
    std::array<std::uint8_t,24> input{};
    std::array<std::uint8_t,48> padded{};
    for (unsigned n=0;n<input.size();++n) input[n]=static_cast<std::uint8_t>(m.r8(source+n));
    (void)ra2::recovered::fun_0076dd10(local.data(),input.data(),24u);
    local[24]=0;
    // The first 25-byte string copy is followed by the accepted 48-byte
    // bounded copy, which zero-pads after the early NUL.
    for (unsigned n=0;n<25;++n) m.w8(receiver+0x24u+n,local[n]);
    (void)ra2::recovered::fun_0076dd10(padded.data(),local.data(),48u);
    for (unsigned n=0;n<padded.size();++n) local[n]=padded[n];
    for (unsigned n=0;n<49;++n) m.w8(receiver+0x64u+n,local[n]);
    m.w32(receiver+0x60u,0x0082208cu);
    append_one(m,0x00a28588u,0x00a28580u,0x00a2857cu,receiver,
               "Block94 0x10580 registry growth route excluded");
    return receiver;
}

std::uint32_t fun_00435aa0(Memory& m,const Inputs& i) {
    const auto c=i.cx;
    (void)init_ff10(m,c);
    m.w32(c+0x54u,zero); m.w32(c,0x00787a08u); m.w32(c+4u,0x007879ecu);
    m.w32(c+8u,0x007879e4u); m.w32(c+0xcu,0x007879dcu);
    m.w32(c+0x28u,zero); m.w32(c+0x2cu,zero); m.w8(c+0x58u,0);
    compose_5bf0(m,c+0x3cu);
    const auto parent=m.r32(0x00821b88u);
    m.w32(c+0x50u,m.r32(parent+0x204u));
    append_one(m,0x00836ed0u,0x00836ec8u,0x00836ec4u,c,
               "Block94 0x35aa0 registry growth route excluded");
    return c;
}

std::uint32_t fun_005354f0(Memory& m,const Inputs& i) {
    const auto c=i.cx;
    (void)init_ff10(m,c);
    m.w32(c+0x24u,0); m.w32(c+0x28u,0); m.w32(c+0x2cu,0); m.w32(c+0x30u,0);
    m.w32(c+0x38u,m.r32(0x00a56438u)); m.w32(c+0x3cu,m.r32(0x00a5643cu));
    m.w32(c+0x44u,0); m.w8(c+0x48u,0); m.w32(c+0x40u,m.r32(0x00a56440u));
    m.w32(c,0x00790540u); m.w32(c+4u,0x00790524u); m.w32(c+8u,0x0079051cu);
    m.w32(c+0xcu,0x00790514u);
    append_one(m,0x00a56458u,0x00a56450u,0x00a5644cu,c,
               "Block94 0x1354f0 registry growth route excluded");
    return c;
}

std::uint32_t fun_0056a660(Memory& m,const Inputs& i) {
    const auto c=i.cx,packed=i.arg[0];
    m.w32(c,0); m.w32(c+4u,0);
    const auto id=m.r32(0x00a58640u);
    m.w32(c+8u,id); m.w32(c+0xcu,0);
    const auto source_table=m.r32(0x0081a958u);
    const auto cell=m.r32(source_table+coordinate_index(packed)*4u);
    const auto values=composed_cell_lookup(m,packed,cell);
    const auto observed=sx8(values&0xffu);
    const auto converted=(values>>8)&0xffu;
    m.w32(c+0x10u,static_cast<std::uint32_t>(observed)); m.w8(c+0x14u,converted);
    m.w32(c+0x16u,packed); m.w8(c+0x1au,0); m.w8(c+0x1bu,1);
    m.w32(c+0x1cu,0); m.w32(c+0x20u,0); m.w8(c+0x24u,0);
    m.w32(c+0x28u,0x007875a0u); m.w32(c+0x2cu,0); m.w32(c+0x30u,0);
    m.w8(c+0x34u,1); m.w8(c+0x35u,0); m.w32(c+0x38u,0);
    m.w32(c+0x3cu,0x000186a0u); m.w32(c+0x40u,0); m.w32(c+0x44u,0);
    m.w32(c+0x48u,0); m.w32(c+0x4cu,0);
    m.w32(0x00a58640u,id+1u);
    append_one(m,0x00a57950u,0x00a57948u,0x00a57944u,c,
               "Block94 0x16a660 registry growth route excluded");
    return c;
}

std::uint32_t fun_005b1840(Memory& m,const Inputs& i) {
    const auto c=i.cx;
    const auto range=i.arg[10]-8u;
    m.w32(c+0x2c4u,range);
    std::array<std::uint8_t,1> dummy{}; leaf::Memory local(dummy.data(),0x1000u,1u);
    leaf::Inputs empty_input{}; (void)leaf::fun_004068f0(local,empty_input);
    for (unsigned n=0;n<7;++n) m.w32(c+0x1480u+n*4u,0x00010001u);

    const auto arg0=i.arg[0],arg1=i.arg[1],arg2=i.arg[2],arg3=i.arg[3],arg4=i.arg[4];
    m.w32(c,0); m.w32(c+4u,arg0); m.w32(c+8u,arg1);
    m.w32(c+0xcu,s32(arg2)>14?14u:arg2); m.w32(c+0x10u,s32(arg3)>112?112u:arg3);
    m.w32(c+0x14u,0x13u); m.w8(c+0x18u,static_cast<std::uint8_t>(i.arg[7]));
    m.w8(c+0x19u,0);
    const auto p=i.arg[5],q=i.arg[6];
    if(p==0xffffffffu || q==0xffffffffu) {
        m.w8(c+0x1au,1); m.w32(c+0x1cu,arg0); m.w32(c+0x20u,arg1);
    } else {
        m.w8(c+0x1au,0); m.w32(c+0x1cu,p); m.w32(c+0x20u,q);
    }
    m.w32(c+0x24u,0); m.w16(c+0x28u,0); m.w16(c+0x16cu,0);
    m.w32(c+0x2b0u,0); m.w32(c+0x2b4u,0); m.w16(c+0x2b8u,0);
    auto end=i.arg[9];
    if(s32(end)>=s32(m.r32(c+0x10u))) end=m.r32(c+0x10u)-1u;
    auto start=i.arg[8];auto result=end; if(s32(start)>=s32(end)) {start=end-1u;result=start;}
    m.w32(c+0x2bcu,start); m.w32(c+0x2c0u,end);
    return result;
}

std::uint32_t fun_00691d00(Memory& m,const Inputs& i) {
    const auto c=i.cx; (void)init_ff10(m,c);
    m.w32(c+0x24u,0); m.w32(c+0x28u,0); m.w32(c+0x34u,0);
    m.w32(c+0x2cu,m.r32(0x00a2896cu)); m.w32(c+0x40u,0); m.w8(c+0x3cu,0);
    m.w32(c+0x44u,0); m.w8(c+0x48u,1); m.w32(c+0x4au,m.r32(0x00aa5270u));
    m.w32(c+0x50u,0); for(unsigned n=0;n<5;++n)m.w8(c+0x54u+n,0);
    m.w32(c+0x60u,0xffffffffu); m.w32(c,0x007970b8u); m.w32(c+4u,0x0079709cu);
    m.w32(c+8u,0x00797094u); m.w32(c+0xcu,0x0079708cu); m.w32(c+0x38u,0x0082208cu);
    append_one(m,0x00a1e068u,0x00a1e060u,0x00a1e05cu,c,
               "Block94 0x291d00 registry growth route excluded");
    return c;
}

std::uint32_t fun_006e24e0(Memory& m,const Inputs& i) {
    const auto c=i.cx; (void)init_ff10(m,c);
    const auto arg=i.arg[0];
    m.w32(c+0x24u,arg); m.w32(c+0x28u,0); m.w8(c+0x2cu,0);
    m.w32(c+0x30u,m.r32(0x00a2896cu)); m.w32(c+0x38u,0); m.w32(c+0x3cu,0);
    m.w8(c+0x40u,1); m.w32(c,0x00798888u); m.w32(c+4u,0x0079886cu);
    m.w32(c+8u,0x00798864u); m.w32(c+0xcu,0x0079885cu);
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block94 0x2e24e0 registry 1 growth excluded");
    append_one(m,0x00aa8860u,0x00aa8858u,0x00aa8854u,c,"Block94 0x2e24e0 registry 2 growth excluded");
    append_one(m,0x00a286f0u,0x00a286e8u,0x00a286e4u,c,"Block94 0x2e24e0 registry 3 growth excluded");
    return c;
}

std::uint32_t fun_007197b0(Memory& m,const Inputs& i) {
    const auto c=i.cx,index=i.arg[0]; (void)init_ff10(m,c);
    m.w32(c+0x24u,0xffffffffu); m.w32(c+0x2cu,0); m.w32(c+0x30u,0);
    m.w8(c+0x34u,1); m.w8(c+0x35u,0); m.w32(c+0x28u,0x00799e1cu);
    m.w32(c+0x3cu,0xau); m.w32(c+0x38u,0);
    m.w32(c,0x00799db8u); m.w32(c+4u,0x00799d9cu);
    m.w32(c+8u,0x00799d94u); m.w32(c+0xcu,0x00799d8cu);
    if(s32(index)>=0 && index<0xcu)
        append_one(m,0x00b0d018u,0x00b0d010u,0x00b0d00cu,c,
                   "Block94 0x3197b0 registry growth route excluded");
    return c;
}
}
