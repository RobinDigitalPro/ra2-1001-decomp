#include "recovered/recovery_b1118.hpp"
#include <algorithm>
#include <cstring>
#include <stdexcept>
namespace ra2::recovered::b1118 {
static Context*active=nullptr;static DWORD thread=0u;
static void need(bool v){if(!v)throw std::domain_error("1118 bounded originalGAME typedCOM factory/object closure");}
static Context&ctx(){need(active&&thread==GetCurrentThreadId());return *active;}
static unsigned ptr(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
static unsigned raw(void*p){return ptr(p);}static void*pointer(unsigned p){return reinterpret_cast<void*>(std::uintptr_t(p));}
static constexpr GUID unknown{0u,0u,0u,{0xc0u,0u,0u,0u,0u,0u,0u,0x46u}},factory_iid{1u,0u,0u,{0xc0u,0u,0u,0u,0u,0u,0u,0x46u}},persist_stream{0x109u,0u,0u,{0xc0u,0u,0u,0u,0u,0u,0u,0x46u}},persist{0x10cu,0u,0u,{0xc0u,0u,0u,0u,0u,0u,0u,0x46u}},loco{0x070f3290u,0x9841u,0x11d1u,{0xb7u,9u,0u,0xa0u,0x24u,0xddu,0xafu,0xd1u}},piggyback{0x92fea800u,0xa184u,0x11d1u,{0xb7u,0x0au,0u,0xa0u,0x24u,0xddu,0xafu,0xd1u}};
static bool same(REFIID a,REFIID b){return std::memcmp(&a,&b,16u)==0;}
static ULONG WINAPI f_add(void*);static ULONG WINAPI f_release(void*);static HRESULT WINAPI o_qi(void*,REFIID,void**);static ULONG WINAPI o_add(void*);static ULONG WINAPI o_release(void*);
static HRESULT WINAPI f_qi(void*self,REFIID iid,void**out){if(!out)return HRESULT(0x80004003u);*out=nullptr;if(same(iid,unknown)||same(iid,factory_iid))*out=self;if(!*out)return HRESULT(0x80004002u);f_add(self);return S_OK;}
static ULONG WINAPI f_add(void*self){auto&c=ctx();c.heap.r32(raw(self)+4u);return ULONG(c.api.increment(reinterpret_cast<volatile LONG*>(std::uintptr_t(raw(self)+4u))));}
static ULONG WINAPI f_release(void*self){auto&c=ctx();c.heap.r32(raw(self)+4u);const auto result=c.api.decrement(reinterpret_cast<volatile LONG*>(std::uintptr_t(raw(self)+4u)));if(result==0)c.heap.release(raw(self));return ULONG(result);}
static unsigned destroy(unsigned self,unsigned flags){auto&h=ctx().heap;need((flags&1u)!=0u&&h.r32(self+44u)==0u);const auto vt=vtable_addresses();h.w32(self,vt[1]);h.w32(self+4u,vt[2]);h.w32(self+24u,vt[3]);h.w32(self,0x78e3b4u);h.w32(self+4u,0x78e2ecu);h.w32(self+12u,0u);h.release(self);return self;}
static unsigned __attribute__((thiscall)) o_delete(void*self,unsigned flags){return destroy(raw(self),flags);}
static unsigned construct_object(){auto&c=ctx();auto&h=c.heap;const auto self=h.allocate(48u);if(!self)return 0u;h.w32(self+8u,0u);h.w32(self+12u,0u);h.w8(self+16u,1u);h.w8(self+17u,1u);h.w32(self+20u,0u);h.w8(self+28u,0u);for(unsigned k=0;k<3u;++k)h.w32(self+32u+4u*k,c.memory.r32(0x83ad50u+4u*k));h.w32(self+44u,0u);const auto vt=vtable_addresses();h.w32(self,vt[1]);h.w32(self+4u,vt[2]);h.w32(self+24u,vt[3]);return self;}
static HRESULT WINAPI f_create(void*,IUnknown*outer,REFIID iid,void**out){if(!out)return HRESULT(0x80070057u);*out=nullptr;if(outer)return HRESULT(0x80040110u);const auto self=construct_object();if(!self)return HRESULT(0x8007000eu);const auto result=o_qi(pointer(self),iid,out);if(FAILED(result))destroy(self,1u);return result;}
static HRESULT WINAPI f_lock(void*self,BOOL lock){auto&h=ctx().heap;const auto p=raw(self)+4u;h.w32(p,h.r32(p)+(lock?1u:0xffffffffu));return S_OK;}
static ULONG WINAPI o_add(void*self){auto&c=ctx();const auto p=raw(self);c.memory.w32(0xa56744u,c.memory.r32(0xa56744u)+1u);c.heap.r32(p+20u);return ULONG(c.api.increment(reinterpret_cast<volatile LONG*>(std::uintptr_t(p+20u))));}
static ULONG WINAPI o_release(void*self){auto&c=ctx();const auto p=raw(self);c.memory.w32(0xa56744u,c.memory.r32(0xa56744u)-1u);c.heap.r32(p+20u);const auto result=c.api.decrement(reinterpret_cast<volatile LONG*>(std::uintptr_t(p+20u)));if(result==0)destroy(p,1u);return ULONG(result);}
static HRESULT WINAPI o_qi(void*self,REFIID iid,void**out){if(!out)return HRESULT(0x80004003u);*out=nullptr;const auto p=raw(self);if(same(iid,unknown)||same(iid,loco))*out=pointer(p+4u);if(same(iid,persist_stream)||same(iid,persist))*out=self;if(!*out&&same(iid,piggyback))*out=pointer(p+24u);if(!*out)return HRESULT(0x80004002u);o_add(self);return S_OK;}
static HRESULT WINAPI q4(void*p,REFIID i,void**out){return o_qi(pointer(raw(p)-4u),i,out);}static ULONG WINAPI a4(void*p){return o_add(pointer(raw(p)-4u));}static ULONG WINAPI r4(void*p){return o_release(pointer(raw(p)-4u));}
static HRESULT WINAPI q18(void*p,REFIID i,void**out){return o_qi(pointer(raw(p)-24u),i,out);}static ULONG WINAPI a18(void*p){return o_add(pointer(raw(p)-24u));}static ULONG WINAPI r18(void*p){return o_release(pointer(raw(p)-24u));}
static const std::array<unsigned,5>factory_table{{ptr(reinterpret_cast<void*>(&f_qi)),ptr(reinterpret_cast<void*>(&f_add)),ptr(reinterpret_cast<void*>(&f_release)),ptr(reinterpret_cast<void*>(&f_create)),ptr(reinterpret_cast<void*>(&f_lock))}};
// Only reached IUnknown prefixes and deleting destructor are implemented.
// Other IPersist/ILocomotion methods remain excluded; null slots never execute.
static const std::array<unsigned,9>object_table{{ptr(reinterpret_cast<void*>(&o_qi)),ptr(reinterpret_cast<void*>(&o_add)),ptr(reinterpret_cast<void*>(&o_release)),0u,0u,0u,0u,0u,ptr(reinterpret_cast<void*>(&o_delete))}};
static const std::array<unsigned,3>second_table{{ptr(reinterpret_cast<void*>(&q4)),ptr(reinterpret_cast<void*>(&a4)),ptr(reinterpret_cast<void*>(&r4))}},third_table{{ptr(reinterpret_cast<void*>(&q18)),ptr(reinterpret_cast<void*>(&a18)),ptr(reinterpret_cast<void*>(&r18))}};
std::array<unsigned,4>vtable_addresses(){static_assert(sizeof(void*)==4u,"1118 realx86COM numericprefix layout");return{{ptr(factory_table.data()),ptr(object_table.data()),ptr(second_table.data()),ptr(third_table.data())}};}
Activation::Activation(Context&c):prior(active){need(!active);active=&c;thread=GetCurrentThreadId();}Activation::~Activation(){active=prior;if(!active)thread=0u;}
unsigned construct_factory(Context&c){need(active==&c);const auto self=c.heap.allocate(8u);need(self);c.heap.w32(self,vtable_addresses()[0]);c.heap.w32(self+4u,0u);return self;}
unsigned run(Memory&m,const Inputs&i,Api&a){need(m.r32(i.cx)==0u&&i.arg[0]==0x78cfb0u&&i.arg[1]==0u&&i.arg[2]==7u);const auto&clsid=*reinterpret_cast<const GUID*>(0x78cfb0u);const auto&unknown_iid=*reinterpret_cast<const GUID*>(0x7b95a0u);const auto&loco_iid=*reinterpret_cast<const GUID*>(0x7b9590u);auto result=a.create(clsid,nullptr,i.arg[2],unknown_iid,reinterpret_cast<void**>(&i.arg[1]));if(FAILED(result))return unsigned(result);auto*p=reinterpret_cast<IUnknown*>(std::uintptr_t(i.arg[1]));result=a.run(p);if(SUCCEEDED(result))result=p->QueryInterface(loco_iid,reinterpret_cast<void**>(std::uintptr_t(i.cx)));p->Release();return unsigned(result);}
}
