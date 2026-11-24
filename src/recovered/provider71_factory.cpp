#include "provider71_factory.hpp"
#include "provider71_count2.hpp"
#include <stdexcept>

namespace ra2::recovered::provider71_factory {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}

// Actual 47FEA0, restricted to the table produced by the count2 constructor.
void clear_table(Memory& m,unsigned p){
    need(m.r32(p)==0x788db4&&m.r32(p+4)==1&&m.r32(p+8)==2,
         "1670 exact constructed table");
    for(unsigned o:{0x2cu,0x3cu,0x14u,0x18u,0x1cu,0x20u,0x28u,0x38u})m.w32(p+o,0);
    const auto row=m.r32(p+0x24);
    for(unsigned bit:{1u,2u,4u})m.w32(row,m.r32(row)&~bit);
    for(unsigned o:{4u,8u,12u,16u,24u})m.w32(row+o,0);
    m.w32(m.r32(p+0x30),0);
    for(unsigned n=0;n<2;++n){
        const auto col=m.r32(p+0x34)+20*n;
        for(unsigned bit:{1u,2u,4u})m.w32(col,m.r32(col)&~bit);
        m.w32(col+4,0);m.w32(col+12,0);
        m.w32(m.r32(p+0x40)+4*n,0);
    }
    for(unsigned o:{0x44u,0x48u,0x4cu,0x54u})m.w32(p+o,0);
}

// Constructor-installed 78F684+4 -> 522FE0 -> 481170 -> 47FEA0.
void reset_created_object(Memory& m,unsigned p){
    need(m.r32(p)==0x78f684,"1670 actual constructor addresspoint");
    for(unsigned o:{0x34u,0x38u,0x3cu,0x40u,8u,12u,16u,20u,24u})m.w32(p+o,0);
    m.w32(p+0x44,0xffffffff);m.w32(p+0x48,0xffffffff);
    clear_table(m,m.r32(p+4));
}

unsigned create(Memory& m,const Inputs& parent,const Operations& op,unsigned manager,unsigned color){
    const auto p=op.allocate(op.context,m,0xd8);
    need(p!=0,"1670 successful outer allocation");
    auto child=parent;child.cx=p;
    child.arg[0]=1;child.arg[1]=2;child.arg[2]=61;
    // Only these low WORDs are consumed by the authenticated constructor.
    child.arg[3]=m.r16(manager+0x20);child.arg[4]=color;
    need(count2::construct(m,child,{op.context,op.allocate})==p,
         "1670 constructor returns receiver");
    return p;
}
}

unsigned fun_00523fb0(Memory& m,const Inputs& i,const Operations& op){
    const auto self=i.cx;
    need(self==0xa285c8&&op.context&&op.allocate,"1670 fixed borrowed manager and owned allocator");
    need(m.r32(0xa255c8)==4&&m.r32(0x821f90)!=0,"1670 positive mode4 presence input");
    need(m.r8(self+4)==0&&m.r8(self+5)==0&&m.r32(self+0x44)==0&&
         m.r32(self+0x48)==0&&m.r32(self+0x4c)==0&&m.r32(self+0x50)==0,
         "1670 cold manager without old allocations");
    need(m.r32(self+8)==61&&m.r32(self+12)==1&&
         m.r32(self+0x18)==61&&m.r32(self+0x1c)==1,
         "1670 exact two 1x2 payload61 constructor domains");
    m.w8(self+4,1);m.w32(self+0x44,0);
    const auto first=create(m,i,op,self,0x1236);
    m.w32(self+0x48,first);reset_created_object(m,first);
    m.w32(first+0x28,m.r32(self+0x58));
    m.w32(first+0x2c,m.r32(self+0x5c));
    m.w32(first+0x30,m.r32(self+0x60));
    const auto second=create(m,i,op,self,0xcdef);
    m.w32(self+0x4c,second);reset_created_object(m,second);
    m.w32(second+0x28,m.r32(self+0x58));
    m.w32(second+0x2c,m.r32(self+0x5c));
    m.w32(second+0x30,m.r32(self+0x60));
    // Actual call-free 522FF0; the caller produces all argument copies first.
    const auto arg4=m.r32(self+0x68),arg3=m.r32(self+0x8c),arg2=m.r32(self+0x74);
    const auto arg1=m.r32(self+0x88),arg0=m.r32(self+0x70),edx=m.r32(self+0x24);
    const auto cx=m.r16(self+0x22);
    m.w16(0xa3a010,cx);m.w32(0xa39ff0,edx);
    m.w32(0xa3a004,arg0);m.w32(0xa3a020,arg1);
    m.w32(0xa39fd8,arg2);m.w32(0xa39fb0,arg3);
    m.w32(0xa3a014,arg4);
    m.w32(0xa3a044,1);
    m.w8(self+5,1);
    return 1;
}
}
