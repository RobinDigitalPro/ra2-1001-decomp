#include "recovered/recovery_b1205.hpp"
#include <stdexcept>
namespace ra2::recovered::b1205 {namespace {
void need(bool x){if(!x)throw std::domain_error("1205 finite genuine passenger chain append");}
void infantry_limbo(Memory&m,unsigned head,Observation&o){
 need(m.r32(head)==0x78e540u&&m.r32(0x78e540u+0xd0u)==0x504390u);++o.virtual_dispatches;++o.limbo_calls;
 const unsigned loco=m.r32(head+0x564u);need(loco&&m.r32(loco)==0x78c004u&&m.r32(0x78c004u+0xacu)==0x4a4970u);++o.virtual_dispatches;
 // Actual4A4970 is RET4. Actual504390 then follows4C97D0 ->6B9AF0 ->62E100 ->5CBD90.
 m.w32(head+0x5d0u,2u);m.w8(head+0x5c3u,0u);m.w32(head+0x5acu,0u);
 need(m.r8(head+0x76u)==1u);need(m.r8(0xa285a8u)==0u);
}
unsigned unit_type(Memory&m,unsigned carrier,Observation&o){need(m.r32(carrier)==0x798c88u&&m.r32(0x798c88u+0x80u)==0x6b6910u&&m.r32(0x798c88u+0x84u)==0x6f9c70u);o.virtual_dispatches+=2u;++o.type_queries;return m.r32(carrier+0x5acu);}
void append(Memory&m,unsigned header,unsigned head,Observation&o){need(head);infantry_limbo(m,head,o);unsigned tail=head;for(unsigned n=0;;++n){need(n<4u);const unsigned next=m.r32(tail+0x30u);if(!next)break;need((m.r8(next+0x14u)&4u)!=0u);tail=next;}
 m.w32(tail+0x30u,m.r32(header+4u));m.w32(header+4u,head);unsigned count=0u,node=head;
 do{need(++count<=7u);node=m.r32(node+0x30u);if(!node)break;need((m.r8(node+0x14u)&4u)!=0u);}while(true);
 m.w32(header,count);++o.insertions;++o.positive_transitions;
}
}
unsigned run(Memory&m,Inputs&i,Heap&,unsigned root,unsigned,Observation&o){need(root==0xcca80u);const unsigned carrier=i.cx,head=i.arg[0];append(m,carrier+0xf8u,head,o);const auto first=unit_type(m,carrier,o);need(first&&m.r32(first)==0x7991b8u&&m.r32(first+0x4e8u)==0xffffffffu);const auto final=unit_type(m,carrier,o);need(final==first&&m.r8(final+0x701u)==0u);return final;}
}
