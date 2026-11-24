#include "recovered/text_b96.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/global_b58_a.hpp"
#include "recovered/hash_wrappers.hpp"
#include "recovered/leaf_b15_a.hpp"
#include "recovered/leaf_containers.hpp"
#include "recovered/leaf_text_rng.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"

#include <array>
#include <cstdint>
#include <initializer_list>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_006eedc0(Memory&,const Inputs&);
std::uint32_t fun_006eee20(Memory&,const Inputs&);
}

namespace ra2::recovered::text_b96 {
namespace {
using global_b26::s32;

std::uint32_t compare(Memory& m,std::uint32_t a,std::uint32_t b) {
    Inputs in{}; in.arg[0]=a; in.arg[1]=b;
    return crt_b83::fun_0076d860(m,in);
}

std::uint32_t list_first(Memory& m,std::uint32_t sentinel) {
    std::array<std::uint8_t,32> scratch{};constexpr std::uint32_t base=0x33000000u,local_sentinel=base+4u,local_node=base+16u;
    const auto original=m.r32(sentinel);if(!original)return 0;
    leaf::Memory local(scratch.data(),base,static_cast<std::uint32_t>(scratch.size()));
    local.w32(local_sentinel,local_node);local.w32(local_node+8u,local_sentinel);
    leaf::Inputs in{};in.cx=local_sentinel;
    return leaf::fun_004072f0(local,in)?original:0u;
}
std::uint32_t list_next(Memory& m,std::uint32_t node,std::uint32_t sentinel) {
    std::array<std::uint8_t,40> scratch{};constexpr std::uint32_t base=0x33100000u,local_node=base+4u,local_next=base+16u,local_sentinel=base+28u;
    const auto next=m.r32(node);if(!next)return 0;
    leaf::Memory local(scratch.data(),base,static_cast<std::uint32_t>(scratch.size()));
    local.w32(local_node,next==sentinel?local_sentinel:local_next);
    local.w32(local_next+8u,local_node);local.w32(local_sentinel+8u,local_sentinel);
    leaf::Inputs in{};in.cx=local_node;
    return leaf::fun_00407310(local,in)?(next==sentinel?0u:next):0u;
}

void copy_narrow(Memory& m,std::uint32_t dst,std::uint32_t src,std::uint32_t limit) {
    for(std::uint32_t n=0;n<limit;++n) { const auto c=m.r8(src+n); m.w8(dst+n,c); if(!c)return; }
    m.w8(dst+limit,0);
}

void copy_wide(Memory& m,std::uint32_t dst,std::uint32_t src,std::uint32_t units) {
    for(std::uint32_t n=0;n<units;++n) { const auto c=m.r16(src+2u*n); m.w16(dst+2u*n,c); if(!c)return; }
    m.w16(dst+2u*units,0);
}

std::uint32_t sum_descriptor(Memory& m,std::uint32_t descriptor) {
    const auto count=m.r32(descriptor+8u), source=m.r32(descriptor+4u);
    if(s32(count)<0 || count>2u) throw std::domain_error("Block96 sum helper count outside 0..2");
    std::array<std::uint8_t,0x1020> scratch{};
    constexpr std::uint32_t base=0x30000000u, desc=base, values=base+0x1000u;
    leaf::Memory local(scratch.data(),base,static_cast<std::uint32_t>(scratch.size()));
    leaf::Inputs input{}; input.cx=desc;
    for(unsigned n=0;n<3;++n)local.w32(desc+n*4u,0);
    local.w32(desc+4u,values);local.w32(desc+8u,count);
    for(std::uint32_t n=0;n<count;++n)local.w32(values+4u*n,m.r32(source+4u*n));
    return leaf::fun_00491b70(local,input);
}

std::uint32_t indexed_outer_record(Memory& m,std::uint32_t container,std::uint32_t index) {
    // Run the accepted 0x90a30 address calculation in an isolated guest32 view,
    // then translate the returned stride offset back to the caller's mapped base.
    std::array<std::uint8_t,0x3000> scratch{};
    constexpr std::uint32_t base=0x31000000u, local_container=base, local_array=base+0x1000u, out=base+0x2000u;
    leaf::Memory local(scratch.data(),base,static_cast<std::uint32_t>(scratch.size()));
    const auto count=m.r32(container+0x54u), original_base=m.r32(container+0x50u);
    local.w32(local_container+0x50u,local_array);local.w32(local_container+0x54u,count);
    leaf::Inputs in{};in.cx=local_container;in.arg[0]=index;in.arg[1]=out;
    if(!leaf::fun_00490a30(local,in))return 0;
    const auto translated=local.r32(out);
    if(translated<local_array || translated-local_array>=count*0x44u)return 0;
    return original_base+(translated-local_array);
}

std::uint32_t folded_compare_n(Memory& m,std::uint32_t a,std::uint32_t b,std::uint32_t n) {
    Inputs in{};in.arg[0]=a;in.arg[1]=b;in.arg[2]=n;
    return crt_b83::fun_007711d0(m,in);
}
std::uint32_t wide_compare(Memory& m,std::uint32_t a,std::uint32_t b) {
    std::array<std::uint8_t,64> scratch{};constexpr std::uint32_t base=0x32000000u,left=base+0x10u,right=base+0x30u;
    leaf::Memory local(scratch.data(),base,static_cast<std::uint32_t>(scratch.size()));
    for(unsigned n=0;n<8;++n){local.w16(left+2u*n,m.r16(a+2u*n));local.w16(right+2u*n,m.r16(b+2u*n));if(!local.r16(left+2u*n)||!local.r16(right+2u*n))break;}
    leaf::Inputs in{};in.arg[0]=left;in.arg[1]=right;return leaf::fun_0076f113(local,in);
}

NameHashState load_hash(Memory& m,std::uint32_t p) {
    NameHashState s{};s.accumulator=m.r32(p);s.pending=m.r32(p+4u);
    for(unsigned k=0;k<4;++k)s.scratch[k]=static_cast<std::uint8_t>(m.r8(p+8u+k));
    s.completion_byte=static_cast<std::uint8_t>(m.r8(p+12u));return s;
}
void store_hash(Memory& m,std::uint32_t p,const NameHashState& s) {
    m.w32(p,s.accumulator);m.w32(p+4u,s.pending);
    for(unsigned k=0;k<4;++k)m.w8(p+8u+k,s.scratch[k]);m.w8(p+12u,s.completion_byte);
}
std::uint32_t append_normalized(Memory& m,std::uint32_t p,NameHashState& s,std::uint32_t byte) {
    store_hash(m,p,s);Inputs in{};in.cx=p;in.arg[0]=byte;
    const auto result=global_b26::fun_00493c60(m,in);s=load_hash(m,p);return result;
}
}

std::uint32_t fun_004063c0(Memory& m,const Inputs& i) {
    if(m.r32(0x008192f8u)==0)return 0;
    constexpr std::uint32_t sentinel=0x008192b0u;
    auto node=list_first(m,sentinel);
    for(unsigned n=0;n<16u && node && node!=sentinel;++n) {
        if(compare(m,i.cx,node+0x6cu)==0)return node;
        node=list_next(m,node,sentinel);
    }
    return 0; // The selected contract ends on a found node, before allocation/initialization.
}

std::uint32_t fun_0048de70(Memory& m,const Inputs& i) {
    const auto dst=i.cx;
    Inputs input_a{};input_a.cx=i.arg[0];const auto wide_a=global_b26::fun_006eedc0(m,input_a);
    copy_narrow(m,dst,wide_a,19u);
    Inputs input_b{};input_b.cx=i.arg[1];const auto wide_b=global_b26::fun_006eedc0(m,input_b);
    copy_narrow(m,dst+0x1cu,wide_b,19u);
    constexpr std::uint32_t sentinel=0xfffffffeu, minus_one=0xffffffffu;
    m.w32(dst+0x14u,sentinel);m.w32(dst+0x30u,sentinel);
    m.w32(dst+0x18u,sentinel);m.w32(dst+0x34u,sentinel);
    m.w32(dst+0x3cu,0);m.w32(dst+0x44u,minus_one);m.w32(dst+0x38u,minus_one);
    m.w8(dst+0x6cu,0);m.w32(dst+0x40u,0);m.w32(dst+0x48u,0);m.w32(dst+0x4cu,0);
    m.w32(dst+0x50u,0);m.w32(dst+0x54u,0);m.w32(dst+0x58u,0);m.w32(dst+0x5cu,0);
    m.w32(dst+0x68u,0);m.w32(dst+0x60u,0);m.w32(dst+0x64u,0);
    return dst;
}

std::uint32_t fun_0048dff0(Memory& m,const Inputs& i) {
    const auto aggregate=i.cx;
    auto remaining=m.r32(0x00a1a5d8u);
    auto table=m.r32(0x00a1a5ccu);
    if(remaining!=1u || (i.dx&0xffu)!=0u)throw std::domain_error("Block96 aggregate requires the one-record DL-zero route");
    std::uint32_t record=0;
    for(std::uint32_t n=0;n<remaining;++n) {
        const auto candidate=m.r32(table+4u*n);if(!candidate)continue;
        const auto object=m.r32(candidate+0x34u);
        if(m.r8(object+0x1a6u)==1u || m.r8(candidate+0x134u)==0u)continue;
        record=candidate;break;
    }
    if(!record)return 0;
    copy_wide(m,aggregate,record+0x15f16u,19u);
    m.w32(aggregate+0x28u,m.r32(record+0x15f40u));
    m.w32(aggregate+0x2cu,m.r8(record+0x13du)==0u?1u:0u);
    m.w32(aggregate+0x30u,m.r32(record+0x5360u)+m.r32(record+0x53b4u));
    std::uint32_t fixed=0;
    for(unsigned n=0;n<20;++n)fixed+=m.r32(record+0x5310u+4u*n);
    for(std::uint32_t n=0;n<remaining;++n)fixed+=m.r32(record+0x5364u+4u*n);
    m.w32(aggregate+0x40u,fixed);
    std::uint32_t sums=0;
    for(const auto off:{0x5460u,0x5470u,0x5480u,0x5490u})sums+=sum_descriptor(m,record+off);
    m.w32(aggregate+0x50u,m.r32(record+0x5360u)+m.r32(record+0x53b4u)+sums);
    const auto tail=m.r32(record+0x5418u);m.w32(aggregate+0x60u,s32(tail)>0?tail:0u);
    Inputs output{};output.cx=aggregate;
    return global_b26::fun_006eedc0(m,output); // 0x68f0 is a bare RET; it preserves this EAX.
}

std::uint32_t fun_005928a0(Memory& m,const Inputs& i) {
    if(!i.cx)return 0;
    std::array<std::uint8_t,65> name{};std::uint32_t n=0;
    for(;n<=64u;++n){name[n]=static_cast<std::uint8_t>(m.r8(i.cx+n));if(!name[n])break;}
    if(n>64u)return 0;
    const auto length=fun_00775160(name.data());
    if(length!=n)return 0;
    Inputs upper{};upper.arg[0]=i.cx;(void)crt_b83::fun_00781b14(m,upper);
    for(std::uint32_t k=0;k<n;++k)name[k]=static_cast<std::uint8_t>(m.r8(i.cx+k));
    NameHashState state{};
    const auto hash=fun_00493da0(state,name.data(),static_cast<std::int32_t>(n));
    const auto archive=m.r32(0x00a588e0u);
    if(!archive || !m.r32(archive+4u) || !m.r32(archive+8u))return 0;
    const auto count=m.r32(archive+0x14u),table=m.r32(archive+0x20u);
    if(s32(count)<=0 || count>32u)return 0;
    std::int32_t lo=0,hi=static_cast<std::int32_t>(count)-1;
    std::uint32_t entry=0;
    while(lo<=hi){const auto mid=lo+(hi-lo)/2;const auto p=table+12u*static_cast<std::uint32_t>(mid);const auto current=m.r32(p);
        if(s32(current)==s32(hash)){entry=p;break;}if(s32(current)<s32(hash))lo=mid+1;else hi=mid-1;}
    if(!entry)return 0;
    const auto offset=m.r32(entry+4u),size=m.r32(entry+8u);
    if(i.arg[0])m.w32(i.arg[0],archive);
    if(i.arg[2])m.w32(i.arg[2],size);
    const auto base=m.r32(archive+0x24u);
    if(i.arg[1])m.w32(i.arg[1],base?offset:offset+m.r32(archive+0x1cu));
    if(i.dx){m.w32(i.dx,0);if(base)m.w32(i.dx,base+offset);}
    return 1u; // The original defines AL on this hit route.
}

std::uint32_t fun_0059fbe0(Memory& m,const Inputs& i) {
    const auto container=m.r32(i.cx+0x40u);if(!container)return 0xffffffffu;
    const auto count=m.r32(container+0x54u);if(s32(count)<=0 || count>4u)return 0xffffffffu;
    const auto selected=m.r32(0x00a255e4u);if(!selected)return 0xffffffffu;
    const auto selected_record=m.r32(m.r32(0x00a25c0cu)+selected*4u);
    const auto name=selected_record+0x58u;
    std::uint32_t len=0;while(len<255u && m.r8(name+len))++len;
    if(!len || len==255u)return 0xffffffffu;
    std::uint32_t result=0xffffffffu;
    for(std::uint32_t outer=0;outer<count;++outer) {
        const auto base=indexed_outer_record(m,container,outer);if(!base)continue;
        const auto texts=m.r32(base+0x0cu);
        for(const auto off:{0u,0x104u,0x208u})
            if(folded_compare_n(m,texts+off,name,len)==0)result=outer;
    }
    return result;
}

std::uint32_t fun_005b7e20(Memory& m,const Inputs& i) {
    const auto query=i.cx?i.cx:0x00a256d0u;
    Inputs wide_in{};wide_in.cx=query;const auto wide_query=global_b26::fun_006eee20(m,wide_in);
    if(wide_compare(m,wide_query,0x00a2793eu)==0)return 1u;
    const auto count=m.r32(0x00a27db8u),table=m.r32(0x00a27dacu);
    if(s32(count)<=0 || count>4u)return 0xffffffffu;
    std::uint32_t last=0xffffffffu;
    for(std::uint32_t n=0;n<count;++n){
        const auto candidate=m.r32(table+4u*n);Inputs narrow_in{};narrow_in.cx=candidate;
        const auto narrow=global_b26::fun_006eedc0(m,narrow_in);
        if(compare(m,narrow,query)==0)last=n;
    }
    if(last==0xffffffffu)return last;
    return m.r32(m.r32(table+4u*last)+0x65u);
}

std::uint32_t fun_005cd1a0(Memory& m,const Inputs& i) {
    const auto receiver=i.cx,state_addr=i.arg[0];
    if(m.r32(receiver+0x30u)!=0 || m.r32(receiver+0x34u)!=0)
        throw std::domain_error("Block96 serializer route requires null optional child pointers");
    auto state=load_hash(m,state_addr);
    (void)fun_00493d10(state,m.r32(receiver+0x10u));store_hash(m,state_addr,state);
    auto result=append_normalized(m,state_addr,state,m.r8(receiver+0x20u));
    (void)result;
    (void)fun_00493d10(state,m.r32(receiver+0x6cu));store_hash(m,state_addr,state);
    result=append_normalized(m,state_addr,state,m.r8(receiver+0x74u));
    const auto mode=m.r32(0x00a255c8u);
    if(mode==0u || mode==5u){result=append_normalized(m,state_addr,state,m.r8(receiver+0x75u));result=append_normalized(m,state_addr,state,m.r8(receiver+0x77u));}
    result=append_normalized(m,state_addr,state,m.r8(receiver+0x76u));
    for(const auto off:{0x78u,0x79u,0x7au,0x7cu,0x7du})result=append_normalized(m,state_addr,state,m.r8(receiver+off));
    result=fun_00493d10(state,m.r32(receiver+0x88u));store_hash(m,state_addr,state);
    result=fun_00493d10(state,m.r32(receiver+0x8cu));store_hash(m,state_addr,state);
    result=fun_00493d10(state,m.r32(receiver+0x90u));store_hash(m,state_addr,state);
    return result;
}

std::uint32_t fun_00658560(Memory& m,const Inputs& i) {
    const auto object=i.cx,query=i.arg[0],requested=i.arg[1]&0xffu;
    std::uint32_t index=0xffffffffu;
    for(std::uint32_t n=0;n<50u;++n){
        const auto row=object+0x1a12u+n*0x29u;
        std::uint32_t k=0;for(;k<33u;++k){const auto a=m.r8(query+k),b=m.r8(row+k);if(a!=b)break;if(!a){index=n;break;}}
        if(index!=0xffffffffu)break;
    }
    if(index==0xffffffffu)return 0;
    const auto flag=object+0x1a3au+index*0x29u,old=m.r8(flag);
    if(old!=requested){m.w8(flag,requested);m.w8(object+0x222eu,1u);
        // Accepted 0x2a98a0 immediately returns for signed [0xaa7960] <= 0,
        // before observer-list reads or virtual callback dispatch.
        if(s32(m.r32(0x00aa7960u))>0)throw std::domain_error("Block96 observer callback route is excluded");
    }
    return old;
}

std::uint32_t fun_00770173(Memory& m,const Inputs& i) {
    const auto path=i.arg[0];std::array<std::uint8_t,65> bytes{};
    std::uint32_t k=0;for(;k<64u;++k){bytes[k]=static_cast<std::uint8_t>(m.r8(path+k));if(!bytes[k])break;}
    if(k==64u)return 0;
    const auto length=fun_00775160(bytes.data());if(length==0u)return 0;
    auto scan=path;std::uint32_t drive=i.arg[1],directory=i.arg[2],stem=i.arg[3],extension=i.arg[4];
    if(length>1u && m.r8(scan+1u)==':'){
        if(drive){Inputs cp{};cp.arg[0]=drive;cp.arg[1]=scan;cp.arg[2]=2;(void)crt_b83::fun_00777446(m,cp);m.w8(drive+2u,0);}
        scan+=2u;
    }else if(drive)m.w8(drive,0);
    i.arg[1]=0; // Original body clears stack argument 1 at [EBP+0xc].
    i.arg[0]=scan; // Original body stores the post-drive scan pointer at [EBP+8].
    std::uint32_t last_sep=0,dot=0,end=scan;
    while(m.r8(end)){
        const auto c=m.r8(end);
        if((m.r8(0x00b10be1u+c)&4u)!=0u){}
        else if(c=='/' || c=='\\')last_sep=end+1u;
        else if(c=='.')dot=end;
        ++end;
    }
    const auto file_start=last_sep?last_sep:scan;
    if(directory){const auto n=file_start-scan;Inputs cp{};cp.arg[0]=directory;cp.arg[1]=scan;cp.arg[2]=n;(void)crt_b83::fun_00777446(m,cp);m.w8(directory+n,0);}
    if(dot && dot>=file_start){
        if(stem){const auto n=dot-file_start;Inputs cp{};cp.arg[0]=stem;cp.arg[1]=file_start;cp.arg[2]=n;(void)crt_b83::fun_00777446(m,cp);m.w8(stem+n,0);}
        if(extension){Inputs cp{};cp.arg[0]=extension;cp.arg[1]=dot;cp.arg[2]=end-dot;(void)crt_b83::fun_00777446(m,cp);m.w8(extension+(end-dot),0);}
    }else{
        if(stem){const auto n=end-file_start;Inputs cp{};cp.arg[0]=stem;cp.arg[1]=file_start;cp.arg[2]=n;(void)crt_b83::fun_00777446(m,cp);m.w8(stem+n,0);}
        if(extension)m.w8(extension,0);
    }
    i.arg[0]=end; // Original body replaces stack argument 0 with the path terminator.
    i.arg[1]=last_sep; // Final caller word holds the last separator successor.
    return dot && dot>=file_start ? (extension ? extension : end) : extension;
}
} // namespace ra2::recovered::text_b96
