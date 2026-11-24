#include "recovered/text_b86.hpp"

#include "recovered/global_b27_memory.hpp"
#include "recovered/direct_b34_memory.hpp"
#include "recovered/leaf_b17_scalars.hpp"
#include "recovered/leaf_text_rng.hpp"
#include "recovered/scan_primitives.hpp"
#include "recovered/text_b68.hpp"
#include "recovered/text_b76.hpp"
#include "recovered/text_bytes.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::text_b86 {
namespace {
using U = std::uint32_t;

std::uint32_t length8(Memory& m, U p, U bound=4096) {
    for (U n=0;n<bound;++n) if (!m.r8(p+n)) return n;
    throw std::domain_error("Block86 bounded text lacks NUL");
}
std::uint32_t length16(Memory& m,U p,U bound=4096) {
    for(U n=0;n<bound;++n) if(!m.r16(p+2u*n)) return n;
    throw std::domain_error("Block86 bounded UTF-16 text lacks NUL");
}
bool equal16(Memory& m,U a,U b) {
    // The accepted leaf helper requires one checked contiguous guest span. Copy
    // only the two bounded input strings into a temporary address space, then
    // compose the original helper at its actual call site.
    std::vector<std::uint8_t> scratch;
    const auto append=[&](U p){
        for(U n=0;n<4096;++n){const U c=m.r16(p+2u*n);scratch.push_back(std::uint8_t(c));scratch.push_back(std::uint8_t(c>>8));if(!c)return;}
        throw std::domain_error("Block86 comparator exceeded the finite string bound");
    };
    append(a);const U second=0x10000000u+static_cast<U>(scratch.size());append(b);
    ra2::recovered::leaf::Memory local(scratch.data(),0x10000000u,static_cast<U>(scratch.size()));
    ra2::recovered::leaf::Inputs input{};input.arg[0]=0x10000000u;input.arg[1]=second;
    return ra2::recovered::leaf::fun_0076f113(local,input)==0;
}
bool ctype_space(Memory& m, U byte, U arena_anchor) {
    if(byte>=128u) throw std::domain_error("Block86 ASCII ctype route excludes non-ASCII");
    struct CallbackContext { const ra2::recovered::direct_b33::Entry* helper{}; };
    const auto callback=[](ra2::recovered::direct_b33::Memory& memory,
                           ra2::recovered::direct_b33::State& state,
                           const ra2::recovered::direct_b33::Call& call,void* opaque) {
        const auto* context=static_cast<CallbackContext*>(opaque);
        if(call.target!=0x3774e0u||!context->helper||!context->helper->function)
            throw std::domain_error("Block86 CRT route reached an excluded helper boundary");
        ra2::recovered::direct_b33::Frame frame{call.sp,call.sp,call.return_address,
                                                call.return_address,call.cleanup,
                                                call.argument_words,call.target};
        context->helper->function(memory,state,frame,
            ra2::recovered::direct_b33::Operations{nullptr,nullptr});
    };
    const auto& entries=ra2::recovered::direct_b33::entries_c();
    const auto wrapper=std::find_if(entries.begin(),entries.end(),[](const auto& e){return e.rva==0x3703a8u;});
    const auto helper=std::find_if(entries.begin(),entries.end(),[](const auto& e){return e.rva==0x3774e0u;});
    if(wrapper==entries.end()||helper==entries.end()||!wrapper->function||!helper->function)
        throw std::logic_error("Block86 accepted CRT helper chain unavailable");
    CallbackContext context{&*helper};
    const U sp=arena_anchor+0x8000u,ret=0xdecafbadU;
    std::array<std::uint8_t,192> stack_before{};
    for(U n=0;n<stack_before.size();++n)stack_before[n]=static_cast<std::uint8_t>(m.r8(sp-64u+n));
    m.w32(sp,ret);m.w32(sp+4u,byte);
    ra2::recovered::direct_b33::State state{};
    ra2::recovered::direct_b33::Frame frame{sp,sp,ret,0u,0u,1u,0x3774e0u};
    wrapper->function(m,state,frame,ra2::recovered::direct_b33::Operations{callback,&context});
    for(U n=0;n<stack_before.size();++n)m.w8(sp-64u+n,stack_before[n]);
    return state.ax!=0u;
}
U last_character_pointer(Memory& m,U begin,U end) {
    // Reproduce the caller's actual 0x775260 invocation. The selected simple
    // route returns end-1 when begin<end and [0xb10adc]==0; its other call
    // boundaries remain unreachable for this contract.
    const U sp=begin+0x9000u,ret=0xdecafbadU;
    std::array<std::uint8_t,192> stack_before{};
    for(U n=0;n<stack_before.size();++n)stack_before[n]=static_cast<std::uint8_t>(m.r8(sp-64u+n));
    m.w32(sp,ret);m.w32(sp+4u,begin);m.w32(sp+8u,end);
    ra2::recovered::direct_b34::State state{};
    ra2::recovered::direct_b34::Frame frame{};
    frame.entry_sp=sp;frame.sp=sp;frame.outer_return=ret;frame.argument_words=2u;
    const auto& entries=ra2::recovered::direct_b34::entries_c();
    const auto it=std::find_if(entries.begin(),entries.end(),[](const auto& e){return e.rva==0x375260u;});
    if(it==entries.end()||!it->function)throw std::logic_error("Block86 accepted path character helper unavailable");
    it->function(m,state,frame,ra2::recovered::direct_b34::Operations{nullptr,nullptr});
    for(U n=0;n<stack_before.size();++n)m.w8(sp-64u+n,stack_before[n]);
    return state.ax;
}
U read_word_string(Memory& m,U p,std::vector<std::uint8_t>& out) {
    out.clear();
    for(U n=0;n<4096;++n){const U c=m.r16(p+2u*n);out.push_back(std::uint8_t(c));out.push_back(std::uint8_t(c>>8));if(!c)return n+1u;}
    throw std::domain_error("Block86 global string exceeds bound");
}
void write8(Memory& m,U p,const std::string& s,bool nul=true) {for(U n=0;n<s.size();++n)m.w8(p+n,std::uint8_t(static_cast<unsigned char>(s[n])));if(nul)m.w8(p+U(s.size()),0);}
void write16(Memory& m,U p,const std::u16string& s,bool nul=true) {for(U n=0;n<s.size();++n)m.w16(p+2u*n,s[n]);if(nul)m.w16(p+2u*U(s.size()),0);}

} // namespace

std::uint32_t fun_00408e00(Memory& m,const Inputs& i) {
    const U stream=i.cx, caller=i.dx, request=i.arg[0];
    Inputs first{};first.cx=stream;first.dx=0;
    (void)ra2::recovered::text_b76::fun_004090e0(m,first);
    const U amount=std::min(request,m.r32(stream+8u));
    if(!amount)return 0;
    U src,dst;
    if(m.r32(stream+0x14u)){src=m.r32(stream+4u);dst=caller;}
    else {src=caller;dst=m.r32(stream+4u);}
    U n=amount;
    while(n>=4u){const U v=m.r32(src);m.w32(dst,v);src+=4u;dst+=4u;n-=4u;}
    while(n--){const U v=m.r8(src++);m.w8(dst++,v);}
    Inputs after{};after.cx=stream;after.dx=amount;
    (void)ra2::recovered::text_b76::fun_004090e0(m,after);
    i.arg[0]=request-amount;
    return amount;
}

std::uint32_t fun_00431370(Memory& m,const Inputs& i) {
    const U object=i.cx,font=m.r32(i.cx+4u),fallback=m.r32(i.cx+8u);
    const U text=i.arg[0],width_out=i.arg[1],height_out=i.arg[2];
    const U table=m.r32(font+0x18u),stride=m.r32(font+0x14u),glyphs=m.r32(font+0x1cu);
    U width=0,max_width=0;
    for(U n=0;n<16;++n){
        const U ch=m.r16(text+2u*n);if(!ch)break;
        U glyph=m.r16(table+ch*2u),data=0;
        if(glyph)data=glyphs+(glyph-1u)*stride;
        if(!data)data=fallback;
        if(data)width+=m.r8(data)+m.r32(object+0x2cu);
        if(width>max_width)max_width=width;
    }
    m.w32(width_out,max_width);
    m.w32(height_out,m.r32(object+0x1cu));
    i.arg[0]=max_width;
    return (height_out&0xffffff00u)|1u;
}

std::uint32_t fun_005c2970(Memory& m,const Inputs& i) {
    const U query=i.cx;
    constexpr U globals[]={0x00a5a89cu,0x00a5a8a0u,0x00a5a8a4u,0x00a5a8a8u,0x00a5a8acu,0x00a5a8b0u};
    for(U slot:globals){const U candidate=m.r32(slot);if(equal16(m,query,candidate))return candidate;}
    const U count=m.r32(0x00a27db8u),array=m.r32(0x00a27dacu);
    for(U n=0;n<count;++n){const U candidate=m.r32(array+4u*n);if(equal16(m,query,candidate))return candidate;}
    return 0;
}

std::uint32_t fun_0061f140(Memory& m,const Inputs& i) {
    const U object=i.cx,count=m.r8(object),header=i.arg[0],payload=i.arg[1];
    if(count<2u||count>8u)throw std::domain_error("Block86 cache count outside 2..8");
    const U payload_bytes=5u*(count-1u);
    U found=0xffffffffu;
    for(U slot=0;slot<8u;++slot){
        const U row=0x00a5e800u+slot*0x280u;
        if(m.r32(0x00a93910u+slot*4u)!=count)continue;
        bool same=true;
        for(U n=0;n<5u;++n){const U a=m.r8(header+n),b=m.r8(row+n);if(a!=b){same=false;break;}}
        if(!same)continue;
        for(U n=0;n<payload_bytes;++n){const U a=m.r8(payload+n),b=m.r8(row+5u+n);if(a!=b){same=false;break;}}
        if(same){found=slot;break;}
    }
    if(found!=0xffffffffu){
        if(i.arg[2]&0xffu){
            m.w32(i.dx,m.r32(i.dx)+5u-payload_bytes-5u);
            m.w8(object,0);m.w8(header+6u,found);
        }
        return 1u;
    }
    if(!(i.arg[2]&255u))return 0u;
    U replacement=0,best_age=0xffffffffu;
    for(U slot=0;slot<8u;++slot){const U stamp=m.r32(0x00a939f4u+slot*4u);if(!stamp){replacement=slot;break;}const U age=m.r32(0x00a2896cu)-stamp;if(global_b26::s32(age)>global_b26::s32(best_age)){best_age=age;replacement=slot;}}
    // The cache-miss route pushes EBX (selected slot), EDX (count), then 0x7d69a4.
    std::array<std::uint8_t,1> scratch{};
    ra2::recovered::leaf::Memory leaf_mem(scratch.data(),0x10000000u,1u);
    ra2::recovered::leaf::Inputs leaf_in{};
    leaf_in.arg[0]=0x007d69a4u;leaf_in.arg[1]=count;leaf_in.arg[2]=replacement;
    (void)ra2::recovered::leaf::fun_004068f0(leaf_mem,leaf_in);
    const U row=0x00a5e800u+replacement*0x280u,now=m.r32(0x00a2896cu);
    m.w32(0x00a939f4u+replacement*4u,now);
    for(U n=0;n<5u;++n)m.w8(row+n,m.r8(header+n));
    for(U n=0;n<payload_bytes;++n)m.w8(row+5u+n,m.r8(payload+n));
    m.w32(0x00a93910u+replacement*4u,count);
    m.w8(header+6u,replacement);
    return 0;
}

std::uint32_t fun_006582c0(Memory& m,const Inputs& i) {
    const U object=i.cx,query=i.arg[0],incoming=i.arg[1];
    U last=0;
    for(U slot=0;slot<50u;++slot){
        U a=query,b=object+0x1210u+slot*0x29u;
        for(;;){const U x=m.r8(a),y=m.r8(b);if(x!=y){last=x<y?0xffffffffu:1u;break;}if(!x){last=0;break;}++a;++b;}
        if(!last){const U status=m.r8(object+0x1210u+slot*0x29u+0x28u);if(status==(incoming&0xffu))return status;}
    }
    return (last&0xffffff00u)|1u;
}

std::uint32_t fun_006edf40(Memory& m,const Inputs& i) {
    const U source=i.dx,out1=i.arg[0],out2=i.arg[1];
    U capacity=i.arg[2],p=source,d=out1,mode=0;
    bool slash=false;
    for(U n=0;n<64u;++n){
        U c=m.r8(p++);
        if(!c)throw std::domain_error("Block86 first field has no bounded quote");
        if(c=='\n'){slash=false;c=' ';}
        else if(c=='\\'){slash=!slash;}
        else if(c=='"'){if(!slash)break;slash=false;}
        else slash=false;
        if(ctype_space(m,c,out1))c=' ';
        m.w8(d++,c);if(capacity)--capacity;i.arg[2]=capacity;if(!capacity)break;
    }
    m.w8(d,0);
    U dest=out2,last=0,length=0;
    for(U n=0;n<64u;++n){
        U c=m.r8(p++);
        if(c=='\n')break;
        const bool space=ctype_space(m,c,out2);
        if(mode==0){if(space||c=='=')continue;mode=1;}
        if(mode==1){
            const bool valid=(c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='_';
            if(valid){m.w8(dest++,c);last=c;++length;continue;}
            mode=2;
        }
    }
    m.w8(dest,0);
    if(length&&last>='0'&&last<='9'){m.w8(dest,'e');m.w8(dest+1u,0);}
    return last;
}

std::uint32_t fun_0076e02b(Memory& m,const Inputs& i) {
    const U destination=i.arg[0],element=i.arg[1],count=i.arg[2],descriptor=i.arg[3];
    const U total=element*count,source=m.r32(descriptor),available=m.r32(descriptor+4u);
    if(!element||!count||!total||total>32u||available<total)
        throw std::domain_error("Block86 supplied-buffer descriptor outside finite route");
    if(!(m.r16(descriptor+0x0cu)&0x10cu))throw std::domain_error("Block86 supplied buffer flag path not selected");
    Inputs copy{};copy.arg[0]=destination;copy.arg[1]=source;copy.arg[2]=total;
    (void)ra2::recovered::global_b26::fun_007745e0(m,copy);
    m.w32(descriptor,source+total);m.w32(descriptor+4u,available-total);
    i.arg[0]=0;i.arg[3]=m.r32(descriptor+0x18u);
    return count;
}

std::uint32_t fun_0076eb30(Memory& m,const Inputs& i) {
    (void)m.r32(0x00b10adcu);
    const U output=i.arg[0],drive=i.arg[1],directory=i.arg[2],filename=i.arg[3],extension=i.arg[4];
    U d=output;
    if(drive&&m.r8(drive)){m.w8(d++,m.r8(drive));m.w8(d++,':');}
    const U dir_len=directory?length8(m,directory,121u):0u;
    for(U n=0;n<dir_len;++n)m.w8(d++,m.r8(directory+n));
    if(dir_len){const U last_pointer=last_character_pointer(m,directory,directory+dir_len);const U last=m.r8(last_pointer);if(last!='/'&&last!='\\')m.w8(d++,'\\');}
    const U name_len=filename?length8(m,filename,121u):0u;
    for(U n=0;n<name_len;++n)m.w8(d++,m.r8(filename+n));
    const U ext_len=extension?length8(m,extension,121u):0u;
    if(ext_len&&m.r8(extension)!='.')m.w8(d++,'.');
    for(U n=0;n<ext_len;++n)m.w8(d++,m.r8(extension+n));
    m.w8(d,0);
    return extension ? extension+ext_len+1u : 0u;
}

std::uint32_t fun_00771c2e(Memory& m,const Inputs& i) {
    const U output=i.arg[0],original=i.arg[1];
    std::array<std::uint8_t,0x88> zeroes{};
    (void)ra2::recovered::fun_0077b620(zeroes.data(),0,0x88u);
    for(U n=0;n<zeroes.size();++n)m.w8(output+n,zeroes[n]);
    if(m.r8(original)=='.')return 0xffffffffu;
    U source=original;
    auto scan=[&](U src){
        global_b27::State st{};st.arg[0]=src;st.arg[1]=0x0079c6f0u;
        const auto& entries=global_b27::entries_c();
        const auto it=std::find_if(entries.begin(),entries.end(),[](const auto& e){return e.rva==0x371310u;});
        if(it==entries.end())throw std::logic_error("Block86 accepted scanner unavailable");
        it->function(m,st);return st.ax;
    };
    for(U mode=0;mode<3u;++mode){
        i.arg[1]=mode;
        const U length=scan(source),delim=m.r8(source+length);
        if(!length)return 0xffffffffu;
        if(mode<2u){if(length>=64u||(mode==0u&&delim=='.')||(mode==1u&&delim=='_'))return 0xffffffffu;}
        else if(length>7u||(delim&&delim!=','))return 0xffffffffu;
        std::array<std::uint8_t,64> src{},dst{};
        for(U n=0;n<length;++n)src[n]=static_cast<std::uint8_t>(m.r8(source+n));
        (void)ra2::recovered::fun_0076dd10(dst.data(),src.data(),length);
        const U offset=mode==0u?0u:(mode==1u?0x40u:0x80u);
        for(U n=0;n<length;++n)m.w8(output+offset+n,dst[n]);
        if(mode==2u)return 0;
        if(!delim)return 0xffffffffu;
        source+=length+1u;
    }
    return 0xffffffffu;
}

} // namespace ra2::recovered::text_b86
