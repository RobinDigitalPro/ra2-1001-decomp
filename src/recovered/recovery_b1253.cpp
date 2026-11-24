#include "recovery_b1253.hpp"
#include "recovered/leaf_containers.hpp"
#include <stdexcept>
namespace ra2::recovered::b1253 {
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 if(root!=0x1c00u)throw std::domain_error("1253 exact archive-cache root");
 const unsigned head=i.cx+12u;unsigned node=m.r32(head);
 // The supported positive two-node producer state contains the requested
 // loaded member in second position. Preserve the original search and writes.
 while(node!=head){
  if(++o.visited>2u)throw std::domain_error("1253 two produced cache nodes");
  if(m.r32(node+0x14u)==i.dx&&m.r32(node+0x18u)!=0u){
   leaf::Inputs call{};call.cx=node;leaf::fun_00407380(m,call);++o.unlink_calls;
   call.cx=head;call.dx=node;leaf::fun_00407370(m,call);++o.insert_calls;
   return node;
  }
  node=m.r32(node);
 }
 throw std::domain_error("1253 selected useful loaded cache HIT only");
}
}
