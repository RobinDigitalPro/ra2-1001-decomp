#include "recovery_b1360.hpp"
#include "recovered/rng_b70.hpp"
#include <stdexcept>
namespace ra2::recovered::b1360 {
namespace {
using U=std::uint32_t;
void need(bool yes,const char* why){if(!yes)throw std::domain_error(why);}
U original_4e0750_positive(Memory& m,U self){
    need((m.r8(0xa2896cu)&1u)==0u,"B1360 even-epoch coordinate-state update");
    const U x=m.r32(self+4u),y=m.r32(self+8u);
    need(floating_b61::s32(x)>0&&floating_b61::s32(y)>0,"B1360 positive coordinate-state fields");
    m.w32(self+4u,1u-x);m.w32(self+8u,1u-y);
    return y; // Actual4E0750 last MOV EAX reads the original second field.
}
U original_499800_forward(Memory& m,const Inputs& i){
    // Original499800 forwards the two caller words, same receiver, thenRET8.
    // They are unused by this reached4E0750 branch. No historical B33 seam.
    return original_4e0750_positive(m,i.cx);
}
U original_70b510_positive(Memory& m){
    const U count=m.r32(0xab82f8u);
    need(count>=1u&&count<=0x7fffffffu,"B1360 positive decrement counter");
    const U next=m.r32(0xab82f8u)-1u;m.w32(0xab82f8u,next);return next;
}
U original_406f30(Memory& m){return m.r32(0x819778u)!=0u?1u:0u;}
void original_4068f0_ret(){
    // Actual provider is exactly C3: no memory, register or FP operation.
}
void outside_left_of_rect(Memory& m,U point,U rect,U offset){
    const U left=m.r32(rect)+offset;
    const U top=m.r32(rect+4u),width=m.r32(rect+8u);(void)top;
    need(floating_b61::s32(width)>0&&floating_b61::s32(m.r32(rect+12u))>0,"B1360 nonempty actual rectangle");
    need(floating_b61::s32(m.r32(point))<floating_b61::s32(left),"B1360 point left of real rectangle");
}
}
U fun_00627350(Memory& m,const Inputs& i){
    (void)original_499800_forward(m,i);
    const U shift=m.r32(0x821978u);
    need(m.r8(0xa28770u)==0u,"B1360 zero horizontal rectangle shift");
    const U offset=0u&shift;
    outside_left_of_rect(m,i.arg[1],0xa9dfb0u,offset);
    outside_left_of_rect(m,i.arg[1],0xa9de80u,offset);
    need(m.r32(i.arg[0])==0x80f3u,"B1360 command80F3 route");
    m.w32(0xa28988u,1u);
    need(m.r32(0xae0a68u)==0u&&m.r32(i.cx+0x14acu)!=4u,"B1360 no mode provider branch");
    return original_70b510_positive(m);
}
U fun_006dd170(Memory& m,const Inputs& i){
    need(m.r8(0xa28858u)==1u&&original_406f30(m)==1u&&m.r8(0xa2894cu)==0u,"B1360 enabled pending-state cancellation");
    need(m.r32(i.cx+0x2cu)==0u&&i.arg[0]==0xffffffffu,"B1360 detached provider and cancellation sentinel");
    need(m.r8(0xa28858u)==1u&&original_406f30(m)==1u&&m.r8(0xa2894cu)==0u,"B1360 stable cancellation globals");
    need(m.r32(i.cx)!=0xffffffffu,"B1360 pending record must be present");
    const U old_value=m.r32(i.cx+4u);(void)old_value;
    original_4068f0_ret();
    need(m.r32(i.cx+0x2cu)==0u,"B1360 stable detached provider");
    m.w32(i.cx,0xffffffffu);m.w32(i.cx+4u,0xffffffffu);m.w32(i.cx+8u,0xffffffffu);
    m.w8(i.cx+0x11u,0u);
    return m.r32(i.cx);
}
U fun_004e7ed0(Memory& m,const Inputs& i){
    const U start=m.r32(i.cx+0x5530u),duration=m.r32(i.cx+0x5538u),epoch=m.r32(0xa2896cu);
    need(epoch>=2u&&epoch<0x7ffffc00u&&start==epoch-1u&&duration==10u,"B1360 genuinely active timer");
    need(m.r32(i.cx+0x54f0u)==0xffffffffu,"B1360 no current linked-house slot");
    need(m.r32(0xa255c8u)==0u,"B1360 selected session mode");
    const U rules=m.r32(0x821b88u);
    need(m.r32(i.cx+0x194u)==0u&&m.r32(rules+0x10a0u)==10u,"B1360 below actual rules threshold");
    need(m.r32(i.cx+0x198u)==2u&&m.r32(i.cx+0x5408u)==epoch,"B1360 positive mode2 to3 transition");
    m.w32(i.cx+0x198u,3u);
    need(m.r32(0xa255c8u)==0u,"B1360 stable session mode");
    const U state=m.r32(0xa255c0u)+0x218u;
    need(m.r8(state)==0u&&m.r32(state+4u)==0u&&m.r32(state+8u)==1u,"B1360 enabled real RNG state");
    need((m.r32(state+0xcu)^m.r32(state+0x10u))<=6u,"B1360 one authentic bounded RNG update");
    Inputs child=i;child.cx=state;child.arg[0]=1u;child.arg[1]=7u;
    const U random=ra2::recovered::rng_b70::fun_0062fe40(m,child);
    i.fp=child.fp;
    return random+0x69u;
}
}
