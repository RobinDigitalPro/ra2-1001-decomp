#include "recovered/recovery_b1680.hpp"
#include <stdexcept>
namespace ra2::recovered::b1680 {
namespace {
void need(bool b){if(!b)throw std::domain_error("281D00 private positive PCX/cache route");}
unsigned ptr(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
HANDLE handle(unsigned p){return reinterpret_cast<HANDLE>(std::uintptr_t(p));}
void file_word(Observation&o,unsigned p,unsigned n){for(unsigned k=0;k<4u;++k)o.file[p+k]=static_cast<unsigned char>(n>>(8u*k));}
unsigned file_read(const Observation&o,unsigned p){unsigned n=0u;for(unsigned k=0;k<4u;++k)n|=unsigned(o.file[p+k])<<(8u*k);return n;}
void construct_file(Observation&o,unsigned name){
    // Exact 89 initialized bytes from authentic file constructors. Bytes
    // 1D..1F,26..27,51..53,5D..5F remain outside this producer's claim.
    constexpr unsigned spans[][2]{{0u,0x1du},{0x20u,0x26u},{0x28u,0x51u},{0x54u,0x5du},{0x60u,0x64u}};
    for(const auto&span:spans)for(unsigned p=span[0];p<span[1];++p)o.file[p]=0u;
    file_word(o,0u,0x7856a0u);file_word(o,4u,1u);
    file_word(o,12u,0xffffffffu);file_word(o,16u,0xffffffffu);
    file_word(o,20u,name);o.file[28u]=1u;
    file_word(o,60u,0xffffffffu);file_word(o,64u,0xffffffffu);
}
void read_exact(Memory&m,unsigned f,Api&a,Observation&o,void*out,unsigned n){
    o.got=0u;
    need(a.read_file(handle(file_read(o,16u)),out,n,&o.got,nullptr)!=FALSE&&o.got==n);
    m.w8(0xa9e184u,0u);
}
unsigned decode(Memory&m,unsigned f,Heap&h,Api&a,Observation&o){
    need(file_read(o,0u)==0x7856a0u&&file_read(o,12u)==0xffffffffu&&file_read(o,16u)==0xffffffffu);
    need(o.file[0x25u]==0u&&file_read(o,0x54u)==0u);
    const auto name=file_read(o,20u);
    // Authentic uppercase conversion is a no-op for this selected input.
    const auto path=reinterpret_cast<LPCSTR>(std::uintptr_t(name));
    const auto probe=[&](){
        const auto file=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
        need(file!=INVALID_HANDLE_VALUE);file_word(o,16u,ptr(file));
        need(a.close_handle(file)!=FALSE);file_word(o,16u,0xffffffffu);
    };
    probe();probe();
    const auto file=a.create_file_a(path,GENERIC_READ,3u,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);
    need(file!=INVALID_HANDLE_VALUE);file_word(o,16u,ptr(file));
    read_exact(m,f,a,o,o.header.data(),128u);
    const auto word=[&](unsigned p){return unsigned(o.header[p])|(unsigned(o.header[p+1u])<<8u);};
    need(o.header[0]==10u&&o.header[1]==5u&&o.header[2]==1u&&o.header[3]==8u&&o.header[65u]==1u);
    const auto w=word(8u)-word(4u)+1u,height=word(10u)-word(6u)+1u,logical=w*height;
    need(w>=40u&&w<=52u&&!(w&1u)&&height>=34u&&height<=36u&&word(66u)==w);
    o.surface=h.allocate(32u);need(o.surface);const auto s=o.surface;
    h.w32(s,0x785f8cu);h.w32(s+4u,w);h.w32(s+8u,height);
    h.w32(s+12u,0u);h.w32(s+16u,1u);
    o.pixels=h.allocate(logical);need(o.pixels);
    h.w32(s+20u,o.pixels);h.w32(s+24u,logical);h.w8(s+28u,1u);
    h.w32(s,0x785ef8u);h.w32(s+12u,1u);
    read_exact(m,f,a,o,o.pool.data(),2048u);
    unsigned input=0u,output=0u;
    while(output<logical){
        need(input<2048u);auto value=o.pool[input++];unsigned count=1u;
        if((value&0xc0u)==0xc0u){count=value&63u;need(count&&input<2048u);value=o.pool[input++];}
        need(count<=logical-output);
        for(unsigned k=0;k<count;++k)h.w8(o.pixels+output+k,value);
        output+=count;
    }
    need(input<2048u);h.w32(s+12u,0u);
    // Full604CF0 nonzero-EDX plane1 path: file seek(-768,END), then
    // read768. With +54/+25=0 and +C=-1 this is actual630550 unknown-size
    // SetFilePointer, without loaded-buffer arithmetic or GetFileSize.
    o.seek_result=a.seek(file,LONG(-768),nullptr,FILE_END);
    need(o.seek_result!=0xffffffffu);
    read_exact(m,f,a,o,o.palette.data(),768u);
    need(a.close_handle(file)!=FALSE);file_word(o,16u,0xffffffffu);
    file_word(o,84u,0u);file_word(o,88u,0u);o.file[92u]=0u;file_word(o,96u,0u);
    return s;
}
unsigned hash12(Heap&h,unsigned text){
    unsigned value=12u;
    for(unsigned k=0;k<12u;++k){
        const auto c=h.r8(text+k);const auto signed_byte=(c&0x80u)?c|0xffffff00u:c;
        value+=signed_byte+k;value=(value<<8u)^(value>>24u);
    }
    need(h.r8(text+12u)==0u);return value;
}
unsigned short ratio(Memory&m,unsigned self){
    const long long count=static_cast<long long>(m.r32(self+4u));
    const int capacity=static_cast<int>(m.r32(self+8u));
    const auto threshold=reinterpret_cast<const double*>(std::uintptr_t(self+0x28u));
    unsigned short status;
#if defined(__i386__)
    // Read actual receiver threshold. Preserve actual incoming guest x87
    // state: no save/restore, FLDCW, status reset or register normalization.
    asm volatile("fildll %[count]\n\tfidivl %[capacity]\n\tfcompl %[threshold]\n\tfnstsw %%ax"
        : "=a"(status)
        : [count]"m"(count),[capacity]"m"(capacity),[threshold]"m"(*threshold)
        : "memory","st");
#else
#error This private proposal requires the existing Windows x86 toolchain.
#endif
    need((status&0x100u)!=0u);return status;
}
}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&a,Observation&o){
    need(!(i.arithmetic_flags&0x400u)&&i.arg[1]==1u&&i.arg[2]==0u);
    need(m.r32(0xa588e0u)==0u&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u);
    need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);
    const auto self=i.cx,buckets=m.r32(self);
    need(buckets&&m.r32(self+4u)==0u&&m.r32(self+8u)==128u&&m.r32(self+12u)==7u);
    need(m.r32(self+16u)==0u&&m.r8(self+20u)==0u&&m.r32(self+24u)==0x6814e0u);
    need(m.r32(self+32u)==0x9999999au&&m.r32(self+36u)==0x3fc99999u);
    need(m.r32(self+40u)==0x9999999au&&m.r32(self+44u)==0x3fe99999u&&m.r32(self+48u)==128u);
    // External fixture proves actual normal constructor and bucket ownership.
    for(unsigned k=0;k<128u;++k)need(h.r32(buckets+4u*k)==0u);
    const auto name=i.arg[0];
    need(m.r8(name)=='P'&&m.r8(name+1u)=='C'&&m.r8(name+2u)=='X');
    for(unsigned k=3u;k<8u;++k)need(m.r8(name+k)>='0'&&m.r8(name+k)<='9');
    need(m.r8(name+8u)=='.'&&m.r8(name+9u)=='P'&&m.r8(name+10u)=='C'&&m.r8(name+11u)=='X'&&m.r8(name+12u)==0u);
    for(auto&c:o.palette)c=0u; // Actual root's initial256 RGB-zero stores.
    o.file_clone=h.allocate(13u);need(o.file_clone);
    for(unsigned k=0;k<13u;++k)h.w8(o.file_clone+k,m.r8(name+k));
    construct_file(o,o.file_clone);
    // Access the actual observation file bytes directly. No Memory copy,
    // vector growth, descriptor setup or host allocation inside the guest.
    decode(m,ptr(o.file.data()),h,a,o);
    o.temporary=h.allocate(13u);need(o.temporary);
    for(unsigned k=0;k<13u;++k)h.w8(o.temporary+k,m.r8(name+k));
    // Selected75A760/76FB34 C-locale path lowercases ASCII uppercase only.
    for(unsigned k=0;k<12u;++k){const auto c=h.r8(o.temporary+k);if(c>='A'&&c<='Z')h.w8(o.temporary+k,c+32u);}
    // Empty pre-count skips lookup, duplicate removal and old surface free.
    o.node=h.allocate(0x30cu);need(o.node);
    h.w32(o.node,0u);h.w32(o.node+4u,0u);
    o.node_key=h.allocate(13u);need(o.node_key);h.w32(o.node,o.node_key);
    h.w8(o.node_key,0u);
    for(unsigned k=0;k<13u;++k)h.w8(o.node_key+k,h.r8(o.temporary+k));
    h.w32(o.node+4u,o.surface);
    for(unsigned k=0;k<768u;++k)h.w8(o.node+8u+k,o.palette[k]);
    h.w32(o.node+0x308u,0u);
    o.hash=hash12(h,o.temporary);o.bucket=o.hash&127u;
    const auto slot=buckets+4u*o.bucket,prior=h.r32(slot);
    h.w32(slot,o.node);if(prior)h.w32(o.node+0x308u,prior);
    m.w32(self+4u,1u);
    o.ratio_status=ratio(m,self);
    o.temporary_free=h.release(o.temporary);need(o.temporary_free!=0u);
    // Temporary holder clears privately; Observation retains its allocation
    // identity for external pre-free evidence, not as a live pointer claim.
    file_word(o,84u,0u);file_word(o,88u,0u);o.file[92u]=0u;
    file_word(o,0u,0x785658u); // Base cleanup then raw filename destructor.
    file_word(o,0u,0x78773cu); //42F250 entry store.
    file_word(o,48u,0u);o.file[33u]=0u;o.file[35u]=0u;
    o.file[36u]=0u;o.file[37u]=0u;
    file_word(o,0u,0x793c84u); //630060, before actual filename free.
    o.file_free=h.release(o.file_clone);need(o.file_free!=0u);
    file_word(o,0u,0x793c3cu);file_word(o,20u,0u);o.file[28u]=0u;
    return 1u; // Defined AL only. Raw original upper24 remain unclaimed.
}
}

