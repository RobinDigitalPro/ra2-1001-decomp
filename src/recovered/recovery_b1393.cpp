#include "recovery_b1393.hpp"
#include "platform/ole_stream951.hpp"
#include <array>
namespace ra2::recovered::b1393 {
namespace {
using U=std::uint32_t;namespace ole=ra2::platform::ole_stream951;
void need(bool b,const char* s){ole::need(b,s);}
IStream* stream(U address){
    need(address==ole::Stream::current().address(),"B1393 genuine live IStream");
    return reinterpret_cast<IStream*>(std::uintptr_t(address));
}
U read_word(IStream* p){U value=0;need(p->Read(&value,4,nullptr)==S_OK,"B1393 successful four-byte Read");return value;}
void append_identity(Memory& m,U saved,U self){
    // Original6951F0 capacity-room path; no controlled growth operation.
    const U count=m.r32(0xaa539cu),capacity=m.r32(0xaa5394u),table=m.r32(0xaa5390u);
    need(global_b26::s32(count)>=0&&global_b26::s32(count)<global_b26::s32(capacity)&&table,"B1393 mapping capacity");
    m.w32(0xaa539cu,count+1u);m.w32(table+8u*count,saved);m.w32(table+8u*count+4u,self);
}
void restore_base(Memory& m,U self,IStream* p,U size,U size_target){
    // 410120: first destination is its private nested stream argument word.
    const U saved=read_word(p);append_identity(m,saved,self);
    need(m.r32(m.r32(self)+0x30u)==size_target,"B1393 actual size virtual target");
    const U preserve=m.r32(self+0x1cu);
    std::array<std::uint8_t,0x178> bytes{};
    need(size<=bytes.size()&&p->Read(bytes.data(),size,nullptr)==S_OK,"B1393 complete genuine object Read");
    for(U k=0;k<size;++k)m.w8(self+k,bytes[k]);
    m.w32(self+0x1cu,preserve);
}
void noinit_base(Memory& m,U self){
    // Actual40FF60, including overwritten stores; its arg0 pointer is unused.
    m.w32(self+8u,0x785e44u);m.w32(self+12u,0x785e3cu);
    m.w32(self,0x785dd8u);m.w32(self+4u,0x785dbcu);
    m.w32(self+8u,0x785db4u);m.w32(self+12u,0x785dacu);
    need(m.r8(self+0x3du)==0u,"B1393 constructor-consistent no allocated name");
    m.w32(self+0x60u,0x82208cu);
    m.w32(self,0x785e88u);m.w32(self+4u,0x785e6cu);
    m.w32(self+8u,0x785e64u);m.w32(self+12u,0x785e5cu);
}
void vector_acb0(Memory& m,U vector){
    // Exact50ACB0(0,0), no allocation.
    m.w32(vector+4u,0u);m.w32(vector+8u,0u);m.w8(vector+12u,1u);m.w8(vector+13u,0u);m.w32(vector,0x78eb5cu);
}
void vector_a8d0(Memory& m,U vector){
    // Exact50A8D0(0,0), including its own base constructor stores.
    vector_acb0(m,vector);m.w32(vector+20u,10u);m.w32(vector+16u,0u);m.w32(vector,0x78eb7cu);
}
void vector_49bf0(Memory& m,U vector){
    m.w32(vector+4u,0u);m.w32(vector+8u,0u);m.w8(vector+12u,1u);m.w8(vector+13u,0u);
    m.w32(vector+20u,10u);m.w32(vector+16u,0u);m.w32(vector,0x78eb3cu);
}
void empty_fixup(Memory& m,U slot){need(m.r32(slot)==0u,"B1393 actual695170 constructor-default empty fixup");}
void timer_zero(Memory& m,U timer){const U epoch=m.r32(0xa2896cu);m.w32(timer,epoch);m.w32(timer+8u,0u);}
void tags(Memory& m,U self,U a,U b,U c,U d){m.w32(self,a);m.w32(self+4u,b);m.w32(self+8u,c);m.w32(self+12u,d);}
}
U fun_00715970(Memory& m,const Inputs& i){
    const U self=i.arg[0];IStream* p=stream(i.arg[1]);need(self!=0u,"B1393 object required");
    restore_base(m,self,p,0x178u,0x715c30u);
    noinit_base(m,self);
    const U vector=self+0x104u;vector_acb0(m,vector);m.w32(vector+20u,10u);m.w32(vector+16u,0u);m.w32(vector,0x78eb3cu);
    tags(m,self,0x799a98u,0x799a7cu,0x799a74u,0x799a6cu);
    vector_a8d0(m,vector);m.w32(vector,0x78eb3cu);
    // At third Read, LEA[T+18], T=entryESP-10, addresses outerarg1.
    i.arg[1]=read_word(p);need(i.arg[1]==0u,"B1393 original writer emitted empty vector count");
    need(m.r32(vector+16u)==0u,"B1393 rebuilt vector count");empty_fixup(m,self+0x140u);
    return 0u;
}
U fun_006de420(Memory& m,const Inputs& i){
    const U self=i.arg[0];IStream* p=stream(i.arg[1]);need(self!=0u,"B1393 object required");
    for(U offset:{0xf4u,0xfcu,0xf8u,0x110u,0x118u,0x114u})need(m.r32(self+offset)==0u,"B1393 constructor-empty owned resource");
    m.w32(self+0xf0u,0u);m.w32(self+0x10cu,0u);
    const U vector=self+0xc4u;need(m.r32(m.r32(vector)+12u)==0x50a560u,"B1393 genuine vector clear virtual");
    // Original50A560 sees actual null data and does not reach free.
    need(m.r32(vector+4u)==0u,"B1393 no owned vector allocation");
    m.w32(vector+16u,0u);m.w8(vector+13u,0u);m.w32(vector+8u,0u);
    restore_base(m,self,p,0x128u,0x6dfc80u);
    noinit_base(m,self);vector_a8d0(m,vector);m.w32(vector,0x78eb3cu);
    timer_zero(m,self+0x100u);timer_zero(m,self+0x11cu);
    tags(m,self,0x798758u,0x79873cu,0x798734u,0x79872cu);
    empty_fixup(m,self+0xe0u);vector_49bf0(m,vector);
    // PUSH0 then LEA[ESP+18], T=entryESP-10 => outerarg0.
    i.arg[0]=read_word(p);need(i.arg[0]==0u,"B1393 original writer emitted empty vector count");
    need(m.r32(vector+16u)==0u,"B1393 rebuilt vector count");
    for(U offset:{0x110u,0x114u,0x118u,0xf4u,0xf8u,0xfcu})m.w32(self+offset,0u);
    return 0u;
}
}
