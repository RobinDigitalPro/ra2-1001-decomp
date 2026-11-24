#include "recovered/recovery_b765.hpp"
#include <stdexcept>

namespace b765 {
namespace {
constexpr std::uint32_t E_POINTER=0x80004003u, E_NOINTERFACE=0x80004002u;
std::uint32_t query(Memory& m,const Inputs& i,std::uint32_t table) {
    const auto self=i.arg[0], iid=i.arg[1], out=i.arg[2];
    const auto expected_vptr=table==0x79a5f0u?0x79a60cu:table==0x79a5b0u?0x79a5ccu:0x79a7dcu;
    const auto expected_addref=table==0x79a5f0u?0x752030u:table==0x79a5b0u?0x7521a0u:0x752c00u;
    if(m.r32(table+4)!=0||m.r32(table+8)!=1||m.r32(table+0x14)!=0||m.r32(self)!=expected_vptr||m.r32(expected_vptr+4)!=expected_addref)
        throw std::domain_error("B765 outside original terminal table/authentic vptr contract");
    if(!out) return E_POINTER;
    m.w32(out,0);
    const auto a=m.r32(iid), b=m.r32(iid+4), c=m.r32(iid+8), d=m.r32(iid+12);
    if(a==0 && b==0 && c==0xc0 && d==0x46000000u) {
        const auto vtable=m.r32(self);
        const auto addref=m.r32(vtable+4);
        if(addref!=0x752030u && addref!=0x7521a0u && addref!=0x752c00u)
            throw std::domain_error("B765 fixture reached an unpinned AddRef slot");
        m.w32(self+4,m.r32(self+4)+1u);
        m.w32(out,self);
        return 0;
    }
    const auto own_guid=m.r32(table);
    if(own_guid && m.r32(own_guid)==a && m.r32(own_guid+4)==b &&
       m.r32(own_guid+8)==c && m.r32(own_guid+12)==d && m.r32(table+8)==1u) {
        const auto vtable=m.r32(self);
        const auto addref=m.r32(vtable+4);
        if(addref!=0x752030u && addref!=0x7521a0u && addref!=0x752c00u)
            throw std::domain_error("B765 own-IID path reached an unpinned AddRef slot");
        m.w32(self+4,m.r32(self+4)+1u);
        m.w32(out,self+m.r32(table+4));
        return 0;
    }
    if(m.r32(table+0x14)==0) return E_NOINTERFACE;
    throw std::domain_error("B765 bounded fixture unexpectedly needs an interface-list callback");
}
}
std::uint32_t query_3520a0(Memory&m,const Inputs&i){return query(m,i,0x79a5f0u);}
std::uint32_t query_352210(Memory&m,const Inputs&i){return query(m,i,0x79a5b0u);}
std::uint32_t query_352c70(Memory&m,const Inputs&i){return query(m,i,0x79a598u);}
}
