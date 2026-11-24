#include "recovery_b1396.hpp"
#include "platform/ole_stream951.hpp"
#include <array>
namespace ra2::recovered::b1396 {
namespace {
using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
void need(bool b,const char* s){ole::need(b,s);}
U read_word(IStream* p){U v=0;need(p->Read(&v,4,nullptr)==S_OK,"B1396 complete count/ID Read");return v;}
void read_blob(Memory& m,U address,IStream* p,U size){
    // Fully produced OS Read storage; no original private-stack input is modeled.
    std::array<std::uint8_t,90000> bytes{};need(size<=bytes.size(),"B1396 bounded raw Read");
    need(p->Read(bytes.data(),size,nullptr)==S_OK,"B1396 complete genuine bulk Read");
    for(U k=0;k<size;++k)m.w8(address+k,bytes[k]);
}
void vector_base(Memory& m,U v,U tag){
    m.w32(v+4u,0u);m.w32(v+8u,0u);m.w8(v+12u,1u);m.w8(v+13u,0u);m.w32(v,tag);
}
void vector_derived(Memory& m,U v,U base,U tag){
    vector_base(m,v,base);m.w32(v,tag);m.w32(v+20u,10u);m.w32(v+16u,0u);
}
void nested_constructor(Memory& m,U v){
    // Actual42CA50: 42D430(0,0), twice42D4A0(0,0), then derived tags.
    vector_derived(m,v+4u,0x787600u,0x7875c0u);
    vector_derived(m,v+0x20u,0x7875e0u,0x7875a0u);
    vector_derived(m,v+0x38u,0x7875e0u,0x7875a0u);m.w32(v,0x787590u);
}
void noinit_constructor(Memory& m,U s){
    // Exact40FF60 and E0D10 finite no-allocation branches in original order.
    m.w32(s+8u,0x785e44u);m.w32(s+12u,0x785e3cu);m.w32(s,0x785dd8u);
    m.w32(s+4u,0x785dbcu);m.w32(s+8u,0x785db4u);m.w32(s+12u,0x785dacu);
    vector_derived(m,s+0x38u,0x78db04u,0x78dae4u);
    for(U o:{0x50u,0x68u,0x80u,0x98u,0xb0u})vector_derived(m,s+o,0x78d384u,0x78d364u);
    vector_derived(m,s+0x19cu,0x78da44u,0x78da24u);
    m.w32(s+0x1c8u,m.r32(0xa2896cu));m.w32(s+0x1d0u,0u);
    for(U k=0;k<12u;++k)vector_base(m,s+0x5420u+16u*k,0x7895acu);
    vector_derived(m,s+0x54f4u,0x78de84u,0x78de64u);vector_derived(m,s+0x550cu,0x78dea4u,0x78de44u);
    for(U k=0;k<3u;++k){const U t=s+0x5560u+44u*k;m.w32(t,m.r32(0xa2896cu));m.w32(t+8u,0x7fffffffu);m.w8(t+12u,0u);m.w32(t+16u,0u);m.w32(t+40u,0u);}
    nested_constructor(m,s+0x55f0u);vector_derived(m,s+0x15f48u,0x7896a0u,0x7896a0u);
    m.w32(s,0x78dde0u);m.w32(s+4u,0x78ddc4u);m.w32(s+8u,0x78ddbcu);m.w32(s+12u,0x78ddb4u);
    m.w32(s+0x24u,0x78dd74u);m.w32(s+0x28u,0x78dd4cu);m.w32(s+0x2cu,0x78dd34u);
}
void clear_empty(Memory& m,U v,U target){
    need(m.r32(m.r32(v)+12u)==target,"B1396 genuine cleanup virtual");
    need(m.r32(v+4u)==0u,"B1396 no owned allocation");
    m.w32(v+16u,0u);m.w8(v+13u,0u);m.w32(v+8u,0u);
}
void empty_fixup(Memory& m,U slot){need(m.r32(slot)==0u,"B1396 actual695170 null field");}
void restore_nested(Memory& m,U s,IStream* p){
    need(m.r32(m.r32(s))==0x42c6a0u,"B1396 genuine nested restore virtual");
    read_blob(m,s,p,120u);
    vector_derived(m,s+4u,0x787600u,0x7875c0u);
    // Actual42CE60(0,0) is a distinct helper with the same derived stores.
    vector_derived(m,s+0x20u,0x7875e0u,0x7875a0u);vector_derived(m,s+0x38u,0x7875e0u,0x7875a0u);m.w32(s,0x787590u);
    for(U k=0;k<3u;++k)need(read_word(p)==0u,"B1396 three nested writer counts");
    empty_fixup(m,s+0x74u);
}
void restore_small_array(Memory& m,U v,IStream* p){
    //491BF0 reinitializes the16-byte header; its Read changes only its nested arg0.
    vector_base(m,v,0x7895acu);need(read_word(p)==0u,"B1396 small-array count0");
    need(m.r32(m.r32(v)+8u)==0x46ccb0u,"B1396 genuine resize target");
    need(m.r32(m.r32(v)+12u)==0x491b50u,"B1396 genuine clear target");
    need(m.r32(v+8u)==0u,"B1396 resize0 calls zero-iteration original clear");
    //46CCB0 sets AL1 after491B50;491BF0 subsequently returns full0.
}
}
U fun_004ecf60(Memory& m,const Inputs& i){
    const U s=i.arg[0],address=i.arg[1];need(s&&address==ole::Stream::current().address(),"B1396 actual live receiver/COM stream");
    auto* p=reinterpret_cast<IStream*>(std::uintptr_t(address));
    for(U o:{0x50u,0x68u,0x80u,0x98u,0xb0u})clear_empty(m,s+o,0x4d40d0u);
    need(m.r32(s+0x15f58u)==0u,"B1396 empty owned actor list");clear_empty(m,s+0x15f48u,0x492f00u);
    need(m.r32(s+0x1acu)==0u,"B1396 empty old widget list");
    const U id=read_word(p),count=m.r32(0xaa539cu),capacity=m.r32(0xaa5394u),table=m.r32(0xaa5390u);
    need(global_b26::s32(count)>=0&&global_b26::s32(count)<global_b26::s32(capacity)&&table,"B1396 identity mapping capacity room");
    m.w32(0xaa539cu,count+1u);m.w32(table+8u*count,id);m.w32(table+8u*count+4u,s);
    need(m.r32(m.r32(s)+0x30u)==0x4edd90u,"B1396 original90000-byte size provider");
    const U old_ref=m.r32(s+0x1cu);need(old_ref==0u,"B1396 constructor-consistent preserved reference");
    read_blob(m,s,p,90000u);m.w32(s+0x1cu,old_ref);noinit_constructor(m,s);
    restore_nested(m,s+0x55f0u,p);
    for(U k=0;k<12u;++k)restore_small_array(m,s+0x5420u+16u*k,p);
    for(U o:{0x34u,0x52dcu,0x52e0u,0x52d8u,0x52e4u,0x52e8u,0x52ecu,0x52f0u,0x52f4u,0x52f8u,0x5410u})empty_fixup(m,s+o);
    for(U k=0;k<12u;++k)empty_fixup(m,s+0x158u+4u*k);
    for(U k=0;k<3u;++k)need(m.r32(s+0x5570u+44u*k)==0u,"B1396 actual4A6820 rebuilt empty records");
    for(U k=0;k<9u;++k){
        i.arg[1]=read_word(p);const U prior=i.arg[1];i.arg[1]-=1u;
        need(prior==0u,"B1396 original outer count loop reads0 then decrements arg1");
    }
    need(read_word(p)==0u,"B1396 final private flag excludes OleLoad");
    return 0u;
}
}
