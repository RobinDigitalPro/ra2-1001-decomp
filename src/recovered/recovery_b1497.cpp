#include "recovered/recovery_b1497.hpp"
#include "platform/signal1497.hpp"
using ra2::recovered::b1497::U;
namespace ui=ra2::recovered::b1497::signal;
extern "C" {
ui::Callback*signal1497_observation=nullptr;
volatile unsigned*signal1497_effect=nullptr;
unsigned*signal1497_slot=nullptr;
long*signal1497_recursion=nullptr;
void**signal1497_owner=nullptr;
long*signal1497_lock_count=nullptr;
unsigned signal1497_event_count=0;
// This is the application-owned signal action. It uses only its ABI argument
// and its own declared persistent effect cells; no GAME callback is replaced.
void __cdecl signal1497_action(int sig){signal1497_effect[0]=signal1497_effect[0]+1u;signal1497_effect[1]=unsigned(sig);}
__attribute__((naked,noinline)) void __cdecl signal1497_handler(int){
 asm volatile(
 "pushfl\n\tpushal\n\tmovl _signal1497_observation,%eax\n\t"
 "movl 0(%esp),%edx\n\tmovl %edx,0(%eax)\n\tmovl 4(%esp),%edx\n\tmovl %edx,4(%eax)\n\t"
 "movl 8(%esp),%edx\n\tmovl %edx,8(%eax)\n\tmovl 12(%esp),%edx\n\tmovl %edx,12(%eax)\n\t"
 "movl 16(%esp),%edx\n\tmovl %edx,16(%eax)\n\tmovl 20(%esp),%edx\n\tmovl %edx,20(%eax)\n\t"
 "movl 24(%esp),%edx\n\tmovl %edx,24(%eax)\n\tmovl 28(%esp),%edx\n\tmovl %edx,28(%eax)\n\t"
 "movl 32(%esp),%edx\n\tmovl %edx,32(%eax)\n\tmovl 36(%esp),%edx\n\tmovl %edx,36(%eax)\n\t"
 "movl 40(%esp),%edx\n\tmovl %edx,40(%eax)\n\tleal 36(%esp),%edx\n\tmovl %edx,44(%eax)\n\t"
 "fnsave 48(%eax)\n\tfrstor 48(%eax)\n\tmovl %fs:0,%edx\n\tmovl %edx,160(%eax)\n\t"
 "xorl %edx,%edx\n\tmovw %fs,%dx\n\tmovl %edx,164(%eax)\n\t"
 "movl _signal1497_slot,%edx\n\tmovl (%edx),%edx\n\tmovl %edx,168(%eax)\n\t"
 "movl _signal1497_recursion,%edx\n\tmovl (%edx),%edx\n\tmovl %edx,172(%eax)\n\t"
 "movl _signal1497_owner,%edx\n\tmovl (%edx),%edx\n\tmovl %edx,176(%eax)\n\t"
 "movl _signal1497_lock_count,%edx\n\tmovl (%edx),%edx\n\tmovl %edx,180(%eax)\n\t"
 "movl _signal1497_event_count,%edx\n\tmovl %edx,184(%eax)\n\t"
 "pushl 40(%esp)\n\tcall _signal1497_action\n\taddl $4,%esp\n\tmovl _signal1497_observation,%eax\n\t"
 "fnsave 192(%eax)\n\tfrstor 192(%eax)\n\tmovl %fs:0,%edx\n\tmovl %edx,304(%eax)\n\t"
 "xorl %edx,%edx\n\tmovw %fs,%dx\n\tmovl %edx,308(%eax)\n\tincl 312(%eax)\n\t"
 "popal\n\tpopfl\n\tpushfl\n\tpushal\n\tmovl _signal1497_observation,%eax\n\t"
 "movl 0(%esp),%edx\n\tmovl %edx,316(%eax)\n\tmovl 4(%esp),%edx\n\tmovl %edx,320(%eax)\n\t"
 "movl 8(%esp),%edx\n\tmovl %edx,324(%eax)\n\tmovl 12(%esp),%edx\n\tmovl %edx,328(%eax)\n\t"
 "movl 16(%esp),%edx\n\tmovl %edx,332(%eax)\n\tmovl 20(%esp),%edx\n\tmovl %edx,336(%eax)\n\t"
 "movl 24(%esp),%edx\n\tmovl %edx,340(%eax)\n\tmovl 28(%esp),%edx\n\tmovl %edx,344(%eax)\n\t"
 "movl 32(%esp),%edx\n\tmovl %edx,348(%eax)\n\tleal 36(%esp),%edx\n\tmovl %edx,352(%eax)\n\t"
 "popal\n\tpopfl\n\tret\n\t");
}
}
namespace ra2::recovered::b1497::signal {
static_assert(offsetof(Callback,after_fs)==304&&offsetof(Callback,count)==312,"1497 raw callback tail layout");
static_assert(offsetof(Callback,after_gpr)==316&&offsetof(Callback,after_flags)==348&&offsetof(Callback,exit_sp)==352,"1497 restored register observer layout");
U handler_address(){return code(&signal1497_handler);}
void Context::begin(Memory&m,volatile U*effect,U*slot,U sig){need(!active&&unowned()&&(sig==15||sig==22)&&effect&&slot,"1497 explicit caller-owned action input");memory_=&m;effect_=effect;slot_=slot;signal_=sig;event_count_=0;fault_=false;callback={};active=this;signal1497_observation=&callback;signal1497_effect=effect;signal1497_slot=slot;signal1497_recursion=&cs_.RecursionCount;signal1497_owner=reinterpret_cast<void**>(&cs_.OwningThread);signal1497_lock_count=&cs_.LockCount;signal1497_event_count=0;}
}
namespace ra2::recovered::b1497 {
namespace {namespace fp=ra2::platform::x87;U selected(U sig){signal::need(sig==15||sig==22,"1497 explicit signal15/22");return sig==15?0xb10578u:0xb10574u;}
template<class F>U with_fp(const Inputs&i,F fn){const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{U result=fn();i.fp.image=fp::capture_host();fp::restore_host(host);return result;}catch(...){fp::restore_host(host);throw;}}
}
U register_handler(Memory&m,const Inputs&i){return with_fp(i,[&]{const U at=selected(i.arg[0]);signal::need(i.arg[1]==signal::handler_address()&&i.arg[1]>4,"1497 own genuine function address");auto&c=signal::context();c.enter(m);const U old=m.r32(at);m.w32(at,i.arg[1]);c.leave(m);signal1497_event_count=c.events();return old;});}
U fun_00778430(Memory&m,const Inputs&i){return with_fp(i,[&]{const U at=selected(i.arg[0]),handler=m.r32(at);signal::need(handler==signal::handler_address(),"1497 actual previously registered owned handler");auto&c=signal::context();c.enter(m);m.w32(at,0);c.leave(m);signal1497_event_count=c.events();reinterpret_cast<Handler>(std::uintptr_t(handler))(int(i.arg[0]));return 0u;});}
}
