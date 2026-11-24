#include "platform/cleanup1464.hpp"
#include <cstring>
#include <stdexcept>
namespace ra2::platform::cleanup1464 {
static void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
U pointer(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
U fshead(){U x;asm volatile("movl %%fs:0,%0":"=r"(x));return x;}
U fsselector(){unsigned short x;asm volatile("movw %%fs,%0":"=r"(x));return x;}
static Provider*active=nullptr;static Event pending;
extern "C" {void*cleanup1464_enter=nullptr;void*cleanup1464_leave=nullptr;void*cleanup1464_filter=nullptr;fp::Image cleanup1464_before,cleanup1464_after;U cleanup1464_eax=0,cleanup1464_esi=0;}
extern "C" void cleanup1464_begin(U kind,U arg){pending={};pending.kind=kind;pending.arg=arg;pending.eax_in=cleanup1464_eax;pending.esi_in=cleanup1464_esi;pending.fsbefore=fshead();pending.before=cleanup1464_before;pending.lockbefore=active->lock_bytes();}
extern "C" void cleanup1464_end(U result){pending.result=result;pending.fsafter=fshead();pending.after=cleanup1464_after;pending.lockafter=active->lock_bytes();active->record(pending);}
#define OBSERVER(NAME,KIND,TARGET) extern "C" __attribute__((naked,noinline)) U WINAPI NAME(void*){asm volatile( \
 "movl %eax,_cleanup1464_eax\n\tmovl %esi,_cleanup1464_esi\n\tpushl %ebp\n\tmovl %esp,%ebp\n\tpushfl\n\tpushal\n\tfnsave _cleanup1464_before\n\tfrstor _cleanup1464_before\n\tpushl 8(%ebp)\n\tpushl $" #KIND "\n\tcall _cleanup1464_begin\n\taddl $8,%esp\n\tfrstor _cleanup1464_before\n\tpopal\n\tpopfl\n\tpushl 8(%ebp)\n\tcall *_" #TARGET "\n\tpushfl\n\tpushal\n\tfnsave _cleanup1464_after\n\tfrstor _cleanup1464_after\n\tpushl %eax\n\tcall _cleanup1464_end\n\taddl $4,%esp\n\tfrstor _cleanup1464_after\n\tpopal\n\tpopfl\n\tpopl %ebp\n\tret $4\n\t");}
OBSERVER(cleanup1464_observed_enter,1,cleanup1464_enter)
OBSERVER(cleanup1464_observed_filter,2,cleanup1464_filter)
OBSERVER(cleanup1464_observed_leave,3,cleanup1464_leave)
#undef OBSERVER
// Raw EAX survives this caller and the transparent observer. It is not a C++ void return.
extern "C" __attribute__((naked,noinline)) U cleanup1464_raw(void*,U,U,U){asm volatile("pushl %ebp\n\tmovl %esp,%ebp\n\tpushl %esi\n\tmovl 16(%ebp),%eax\n\tmovl 20(%ebp),%esi\n\tpushl 12(%ebp)\n\tcall *8(%ebp)\n\tpopl %esi\n\tpopl %ebp\n\tret\n\t");}
static LONG WINAPI projected_filter(EXCEPTION_POINTERS*){TerminateProcess(GetCurrentProcess(),99);return EXCEPTION_CONTINUE_SEARCH;}
Provider::Provider(void*storage):cs_(static_cast<CRITICAL_SECTION*>(storage)){
 need(!active,"1464 nonreentrant scoped provider");active=this;events_.reserve(4);callback_=pointer(reinterpret_cast<void*>(&projected_filter));
 cleanup1464_enter=reinterpret_cast<void*>(GetProcAddress(GetModuleHandleA("kernel32.dll"),"EnterCriticalSection"));cleanup1464_leave=reinterpret_cast<void*>(GetProcAddress(GetModuleHandleA("kernel32.dll"),"LeaveCriticalSection"));cleanup1464_filter=reinterpret_cast<void*>(GetProcAddress(GetModuleHandleA("kernel32.dll"),"SetUnhandledExceptionFilter"));need(cleanup1464_enter&&cleanup1464_leave&&cleanup1464_filter,"1464 genuine APIs");InitializeCriticalSection(cs_);balanced();
}
Provider::~Provider(){if(installed_)SetUnhandledExceptionFilter(reinterpret_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(prior_));if(cs_->RecursionCount==1&&pointer(cs_->OwningThread)==GetCurrentThreadId())LeaveCriticalSection(cs_);DeleteCriticalSection(cs_);active=nullptr;}
U Provider::lock()const{return pointer(cs_);}U Provider::thread()const{return GetCurrentThreadId();}
std::array<std::uint8_t,24> Provider::lock_bytes()const{std::array<std::uint8_t,24>b{};std::memcpy(b.data(),cs_,24);return b;}
void Provider::balanced()const{need(cs_->LockCount==-1&&cs_->RecursionCount==0&&cs_->OwningThread==nullptr,"1464 real balanced critical section");}
U Provider::setup(){balanced();need(!installed_,"1464 previous restoration verified");prior_=pointer(reinterpret_cast<void*>(SetUnhandledExceptionFilter(reinterpret_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(callback_))));installed_=true;return prior_;}
void Provider::begin(){need(installed_,"1464 actual compiled-filter projection required");balanced();events_.clear();}
U Provider::enter(U arg){need(arg==lock(),"1464 real warm lock identity");return cleanup1464_raw(reinterpret_cast<void*>(&cleanup1464_observed_enter),arg,13,0x8172ac);}
U Provider::restore(U arg){need(arg==prior_,"1464 actual prior filter identity");return cleanup1464_raw(reinterpret_cast<void*>(&cleanup1464_observed_filter),arg,0x77e415,0x7b7830);}
U Provider::leave(U arg){need(arg==lock(),"1464 same real lock identity");return cleanup1464_raw(reinterpret_cast<void*>(&cleanup1464_observed_leave),arg,13,0x2468ace0);}
void Provider::finish(){balanced();need(installed_&&events_.size()==3&&events_[1].result==callback_,"1464 one genuine restore of compiled filter");const U actual=pointer(reinterpret_cast<void*>(SetUnhandledExceptionFilter(reinterpret_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(prior_))));need(actual==prior_,"1464 actual previous filter restored");installed_=false;}
U Provider::enter_thunk(){return pointer(reinterpret_cast<void*>(&cleanup1464_observed_enter));}U Provider::filter_thunk(){return pointer(reinterpret_cast<void*>(&cleanup1464_observed_filter));}U Provider::leave_thunk(){return pointer(reinterpret_cast<void*>(&cleanup1464_observed_leave));}
}
