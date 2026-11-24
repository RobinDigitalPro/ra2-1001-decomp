#include "platform/exception1496.hpp"
namespace ra2::platform::exception1496 {
Provider*Provider::active=nullptr;
Provider::Provider(){require(!active,"1496 one active provider");thread=GetCurrentThreadId();active=this;registration=AddVectoredExceptionHandler(1,handler);if(!registration){active=nullptr;throw std::runtime_error("1496 real VEH registration failed");}registered_handle=ptr(registration);}
Provider::~Provider(){if(registration)RemoveVectoredExceptionHandler(registration);if(active==this)active=nullptr;}
void Provider::close(){require(active==this&&registration,"1496 own live registration");removal_result=RemoveVectoredExceptionHandler(registration);require(removal_result!=0,"1496 actual VEH removal");registration=nullptr;active=nullptr;}
void Provider::expect(U carrier,U record,const std::array<std::uint8_t,84>&bytes){require(!calls,"1496 fresh observation");expected_carrier=carrier;expected_record=record;expected=bytes;}
LONG CALLBACK Provider::handler(EXCEPTION_POINTERS*x){
 Provider*p=active;if(!p||!x||!x->ExceptionRecord||!x->ContextRecord)return EXCEPTION_CONTINUE_SEARCH;
 auto*r=x->ExceptionRecord;
 if(fs_thread()!=p->thread||p->calls!=1||p->event.matched||r->ExceptionCode!=0xc0000090u||r->ExceptionFlags!=0||r->NumberParameters!=1||r->ExceptionInformation[0]!=p->expected_record){++p->unexpected;return EXCEPTION_CONTINUE_SEARCH;}
 // No allocation, API, logging, FP operation or context mutation in the VEH.
 const volatile unsigned char*b=reinterpret_cast<const volatile unsigned char*>(p->expected_record);
 for(U k=0;k<84;++k)if(b[k]!=p->expected[k]){++p->unexpected;return EXCEPTION_CONTINUE_SEARCH;}
 p->event.exception=*r;p->event.context_address=ptr(x->ContextRecord);p->event.exception_address=ptr(r);
 const volatile unsigned char*c=reinterpret_cast<const volatile unsigned char*>(x->ContextRecord);
 auto*before=reinterpret_cast<unsigned char*>(&p->event.context_before);auto*after=reinterpret_cast<unsigned char*>(&p->event.context_after);
 for(U k=0;k<sizeof(CONTEXT);++k)before[k]=c[k];
 for(U k=0;k<84;++k)p->event.record_before[k]=b[k];
 for(U k=0;k<84;++k)p->event.record_after[k]=b[k];
 for(U k=0;k<sizeof(CONTEXT);++k)after[k]=c[k];
 p->event.matched=1;return EXCEPTION_CONTINUE_EXECUTION;
}
void Provider::raise(U code,U flags,U count,const U*args){
 require(active==this&&calls==0&&code==0xc0000090u&&flags==0&&count==1&&ptr(args)==expected_carrier&&args[0]==expected_record,"1496 exact real RaiseException arguments");
 ++calls;event.code=code;event.flags=flags;event.count=count;event.carrier=ptr(args);event.record=args[0];event.thread=thread;event.fs_before=fs_head();event.selector_before=fs_selector();event.api_before=fp::capture_host();
 RaiseException(code,flags,count,reinterpret_cast<const ULONG_PTR*>(args));
 event.api_after=fp::capture_host();event.fs_after=fs_head();event.selector_after=fs_selector();
}
void Provider::verify()const{require(calls==1&&unexpected==0&&event.matched==1,"1496 actual one matching continued exception");require(event.record_before==expected&&event.record_after==expected,"1496 full raw record unmodified by VEH");require(!std::memcmp(&event.context_before,&event.context_after,sizeof(CONTEXT)),"1496 actual OS context unmodified");require(fp::same_numeric(event.api_before,event.api_after),"1496 real exception boundary full80 unchanged");require(event.fs_before==event.fs_after&&event.selector_before==event.selector_after,"1496 FS restored");}
}
