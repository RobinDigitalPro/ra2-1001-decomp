#include "recovery_b1262.hpp"
#include <stdexcept>
namespace ra2::recovered::b1262 {
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 if(root!=0x2c70u||(i.cx!=0u&&i.cx!=0xffffffffu))throw std::domain_error("1262 public local0 or original default-1");
 const unsigned local=i.cx==0xffffffffu?0u:i.cx;
 // Original4072F0 is a joined PE/arena read here. Its accepted leaf logic
 // rejects the sentinel by node==node[8]; it does not mutate the list.
 const unsigned head=m.r32(0x7b78f8u);++o.list_reads;
 unsigned node=head?m.r32(head):0u;if(node&&node==m.r32(node+8u))node=0u;
 if(!node)throw std::domain_error("1262 actual produced nonempty descriptor list");
 ++o.visited;if(m.r32(node+0x18u)!=1u||local!=0u)throw std::domain_error("1262 actual one-device descriptor count");
 const unsigned cached=m.r32(node+0x1cu+4u*local);
 if(!cached)throw std::domain_error("1262 useful existing cached slot");
 ++o.hits;m.w32(cached+0x10u,m.r32(cached+0x10u)+1u);++o.retains;
 return cached;
}
}
