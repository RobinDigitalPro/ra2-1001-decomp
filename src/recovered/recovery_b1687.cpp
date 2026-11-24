#include "recovery_b1687.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1687 {
namespace {
using U=std::uint32_t;
void require(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
bool disjoint(U a,U an,U b,U bn){return std::uint64_t(a)+an<=b||std::uint64_t(b)+bn<=a;}
struct Domain {U owner,node,destination;};
Domain normal_domain(Memory&m,U r){
    const U o=m.r32(r),n=m.r32(r+0xc),d=m.r32(r+4);
    require(o&&o<=0xffffff50u&&r==o+0x18&&n&&n<=0xffffffc0u&&d&&d<=0xffffd7f0u,
            "1221F0 normal actual owner/node/backing addresses");
    require(disjoint(o,176,n,64)&&disjoint(o,176,d,0x2810)&&disjoint(n,64,d,0x2810),
            "1221F0 distinct live owner/node/backing allocation spans");
    require((d&3u)==0&&m.r32(o)==1&&m.r32(o+4)==n&&m.r32(o+8)==n&&
            m.r32(o+0xc)==o+4&&m.r32(o+0x10)==0&&m.r32(o+0x14)==0x2800&&
            m.r32(o+0x98)==2,"1221F0 genuine normal singleton controller fields");
    require(m.r32(n)==o+4&&m.r32(n+4)==o+4&&m.r32(n+0x10)==d&&
            m.r32(n+0x14)==0&&m.r32(n+0x18)==d&&m.r32(n+0x1c)==0x2800&&
            m.r32(n+0x20)==d&&m.r32(n+0x24)==0x2800&&m.r32(n+0x28)==d&&
            m.r32(n+0x2c)==0x2800&&m.r32(n+0x30)==o&&m.r32(n+0x34)==0,
            "1221F0 normal circular singleton node slots");
    for(U j=0;j<2;++j){const U q=o+0x18+j*0x40;
        require(m.r32(q)==o&&m.r32(q+4)==d&&m.r32(q+8)==0&&m.r32(q+0xc)==n&&
                m.r32(q+0x10)==0&&m.r32(q+0x14)==j&&m.r32(q+0x18)==0&&
                m.r32(q+0x1c)==1&&m.r32(q+0x28)==n&&m.r32(q+0x2c)==0&&
                m.r32(q+0x30)==0&&m.r32(q+0x34)==(j?0xfffffc17u:0x2417u)&&
                m.r32(q+0x38)==0xfffffc17u,"1221F0 actual selected normal record pair");
    }
    return {o,n,d};
}
U cursor_pass(Memory&,U,U,Observation&);
// Actual 409020 normal complete-node commit. Keep each transient field store,
// including restoration of node slots and the final zero-advance 4090E0 call.
U commit(Memory&m,U r,Observation&out){
    ++out.commits;
    const U amount=m.r32(r+0x2c);
    if(amount==0)return 0;
    U other_index=m.r32(r+0x14)+1u;
    if(other_index==2)other_index=0;
    const U controller=m.r32(r),other=controller+0x18+(other_index<<6);
    m.w32(r+0x38,m.r32(r+0x38)+amount);
    m.w32(other+0x34,m.r32(other+0x34)+amount);
    U node=m.r32(r+0x28),left=amount;
    for(U visits=0;;++visits){
        require(visits<2,"1221F0 finite singleton commit traversal");
        const U selector=m.r32(r+0x14),slot=node+(selector<<3)+0x20;
        const U available=m.r32(slot+4);
        if(global_b26::s32(available)>global_b26::s32(left)){
            m.w32(slot,m.r32(slot)+left);
            m.w32(slot+4,m.r32(slot+4)-left);
            break;
        }
        left-=available;
        m.w32(slot,m.r32(node+0x18));
        m.w32(slot+4,m.r32(node+0x1c));
        const U sentinel=m.r32(node+0x30)+4u;
        node=m.r32(node);
        if(node==sentinel){node=m.r32(node);if(node==sentinel)node=0;}
        if(left==0)break;
    }
    m.w32(r+0x28,node);
    m.w32(r+0x2c,0);
    m.w32(r+0xc,node);
    if(node){const U selector=m.r32(r+0x14);m.w32(r+4,m.r32(node+(selector<<3)+0x20));}
    else m.w32(r+4,0);
    m.w32(r+8,0);
    m.w32(r+0x10,m.r32(r+0x10)&0xfffffffeu);
    (void)cursor_pass(m,r,0,out);
    return amount;
}
// Actual 4090E0 arithmetic is DWORD modulo32, signed for JGE/JL, unsigned
// for the controller cycle comparison and DIV. No floating point operations.
U cursor_pass(Memory&m,U r,U amount,Observation&out){
    ++out.cursor_passes;
    U left=m.r32(r+0x34)-m.r32(r+0x38)-m.r32(r+0x2c);
    if(left==0){m.w32(r+8,0);return 0;}
    if(global_b26::s32(left)<global_b26::s32(amount))amount=left;
    const U slot_offset=(m.r32(r+0x14)<<3)+0x20;
    U accumulated=0;
    for(U visits=0;;++visits){
        require(visits<3,"1221F0 finite singleton cursor traversal");
        const U node=m.r32(r+0xc);
        if((m.r8(r+0x10)&1u)!=0)m.w32(r+8,left);
        else{
            U bounded=m.r32(node+slot_offset+4)-m.r32(r+4);
            bounded+=m.r32(node+slot_offset);
            m.w32(r+8,global_b26::s32(bounded)<global_b26::s32(left)?bounded:left);
        }
        if(amount==0)break;
        const U available=m.r32(r+8);
        U moved,next_pointer;
        if(global_b26::s32(amount)<global_b26::s32(available)){
            moved=amount;next_pointer=m.r32(r+4)+amount;
        }else{
            moved=available;
            const U sentinel=m.r32(node+0x30)+4u;
            U next=m.r32(node);
            if(next==sentinel){next=m.r32(next);if(next==sentinel)next=0;}
            const U committed_node=m.r32(r+0x28);
            m.w32(r+0xc,next);
            if(next==committed_node){
                m.w32(r+0x10,m.r32(r+0x10)|1u);
                next_pointer=m.r32(next+0x18);
            }else next_pointer=m.r32(next+slot_offset);
        }
        amount-=moved;
        accumulated+=moved;
        m.w32(r+4,next_pointer);
        left-=moved;
    }
    const U progress=m.r32(r+0x2c)+accumulated;
    const U cursor=m.r32(r+0x30)+accumulated;
    const U controller=m.r32(r);
    m.w32(r+0x2c,progress);
    m.w32(r+0x30,cursor);
    const U cycle=m.r32(controller+0x14);
    if(cursor>=cycle){require(cycle!=0,"1221F0 normal nonzero controller cycle");m.w32(r+0x30,cursor%cycle);}
    if(progress!=0&&m.r32(r+0x18)==0)(void)commit(m,r,out);
    return accumulated;
}
// Actual 408F50 caller arg1 is NULL, so its output count is a private local.
// Representing that local never writes Root's caller16 or fabricated stack bytes.
U read_transfer(Memory&m,U r,U file,U count,Services&api,Observation&out){
    (void)cursor_pass(m,r,0,out);
    out.local_count=0;
    U remaining=count;
    for(U iterations=0;;++iterations){
        require(iterations<2,"1221F0 finite complete read transfer");
        U request=m.r32(r+8);
        if(global_b26::s32(request)>global_b26::s32(remaining))request=remaining;
        if(request==0)return 1;
        require(m.r32(r+0x14)==0,"1221F0 read selector skips actual fwrite branch");
        const U destination=m.r32(r+4);
        ++out.reads;
        const U read=api.read(destination,1,request,file);
        require(read==request&&request==0x2800,"1221F0 actual complete positive file read");
        if(global_b26::s32(read)<0)m.w32(r+0x24,0x80040000u);
        if(read==0)return 2;
        if(read==0xffffffffu)return 0;
        (void)cursor_pass(m,r,read,out);
        remaining-=read;
        out.local_count+=read;
        out.transferred=out.local_count;
        if(remaining==0)return 1;
    }
}
}
unsigned run(Memory&m,const Inputs&i,Services&api,Observation&out){
    out={};out.stage=1;
    if(m.r32(0xa39ef0)==0)return 0;
    if(m.r32(0xa39f10)!=0)return 0;
    api.enter(0xa39ec0);out.stage=2;
    ++out.opens;
    const U file=api.open(i.cx,0x7c8d2c);
    m.w32(0xa39f10,file);
    m.w32(0xa39f14,0);
    out.file=file;out.stage=3;
    if(file){
        const U receiver=m.r32(0xa39f08);
        m.w32(0xa39eec,2);
        const U count=m.r32(receiver+0x34)-m.r32(receiver+0x38);
        out.requested=count;
        const U current_file=m.r32(0xa39f10),current_receiver=m.r32(0xa39f08);
        const Domain domain=normal_domain(m,current_receiver);
        require(count==0x2800&&current_file==file,"1221F0 normal unchanged single-stream publication");
        out.owner=domain.owner;out.node=domain.node;out.destination=domain.destination;
        out.stage=4;
        out.transfer_return=read_transfer(m,current_receiver,current_file,count,api,out);
        if(out.transfer_return!=1)m.w32(0xa39f14,1);
    }
    out.stage=5;
    api.leave(0xa39ec0);
    out.stage=6;
    return m.r32(0xa39f10)!=0?1u:0u;
}
unsigned run(Memory&m,const Inputs&i,Services&api){Observation out;return run(m,i,api,out);}
}
