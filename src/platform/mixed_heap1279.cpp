#define NOMINMAX
#include "platform/mixed_heap1279.hpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <utility>

namespace ra2::platform::mixed_heap1279 {
namespace {
void need(bool ok,const char* why){if(!ok){std::fprintf(stderr,"B1279 adapter: %s\n",why);throw std::domain_error(why);}}
U addr(const void* p){const auto n=reinterpret_cast<std::uintptr_t>(p);need(n<=0xffffffffu,"x86 address");return static_cast<U>(n);}
bool within(U a,U n,U base,U size){return base&&a>=base&&std::uint64_t(a)+n<=std::uint64_t(base)+size;}
[[noreturn]] void callback_fail(const char* why="caught adapter exception") noexcept {std::fprintf(stderr,"B1279 callback: %s\n",why);RaiseFailFastException(nullptr,nullptr,0);std::abort();}
U round16(U n){need(n&&n<=0xffffffe0u,"ordinary request outside B1279 bound");return(n+15u)&~15u;}
U function(const char* name){auto* p=GetProcAddress(GetModuleHandleW(L"kernel32.dll"),name);need(p!=nullptr,"Kernel32 function unavailable");return addr(reinterpret_cast<const void*>(p));}
void bind(U va,const char* name,U replacement){auto* slot=reinterpret_cast<volatile U*>(va);need(*slot==function(name),"original IAT entry differs from real Kernel32");*slot=replacement;}
}
Heap* Heap::active_original_=nullptr;

Heap::Heap(Memory& m,HANDLE h,U table,CRITICAL_SECTION* lock,bool portable)
 :memory_(m),handle_(h),table_(table),lock_(lock),portable_(portable){
 static_assert(sizeof(void*)==4,"B1279 native adapter requires Windows x86");
 need(h&&table&&lock,"B1279 initialized CRT prerequisites");
 need(HeapValidate(h,0,reinterpret_cast<void*>(std::uintptr_t(table)))&&
      HeapSize(h,0,reinterpret_cast<void*>(std::uintptr_t(table)))>=320,
      "B1279 real 320-byte CRT region table");
 if(portable_&&!torn_down_){
  need(memory_.r32(0x00b10e14u)==0u,"B1279 portable CRT starts empty");
  memory_.w32(0x00b10e18u,table_);memory_.w32(0x00b10e0cu,table_);
  memory_.w32(0x00b10e1cu,addr(h));memory_.w32(0x00b10e10u,0u);
  memory_.w32(0x00b10e08u,0u);
 }else need(memory_.r32(0x00b10e18u)==table_&&
            memory_.r32(0x00b10e1cu)==addr(h),"B1279 attached original CRT identities");
 need(memory_.r32(0x00817554u)==0u,"B1279 exact threshold zero");
}
Heap::~Heap(){
 if(active_original_==this)active_original_=nullptr;
 if(portable_&&!torn_down_){
  if(arena_)VirtualFree(reinterpret_cast<void*>(std::uintptr_t(arena_)),0,MEM_RELEASE);
  if(metadata_)HeapFree(handle_,0,reinterpret_cast<void*>(std::uintptr_t(metadata_)));
  if(table_)HeapFree(handle_,0,reinterpret_cast<void*>(std::uintptr_t(table_)));
  if(handle_)HeapDestroy(handle_);
 }
}
void Heap::reset_observation(){need(blocks_.empty()&&!metadata_&&!arena_,"B1279 reset requires fresh CRT instance");
 addresses_.clear();events_.clear();prefree_.clear();small_allocs_=small_frees_=0;}
U Heap::record_user(U p,U span,bool small){
 need(p&&blocks_.find(p)==blocks_.end(),"B1279 duplicate/null owner");
 if(small){need(arena_&&within(p,span,arena_,0x8000u),"B1279 interior CRT owner");}
 else{need(HeapValidate(handle_,0,reinterpret_cast<void*>(std::uintptr_t(p)))&&
           HeapSize(handle_,0,reinterpret_cast<void*>(std::uintptr_t(p)))>=span,
           "B1279 real ordinary owner bounds");}
 const U ordinal=static_cast<U>(addresses_.size());blocks_.emplace(p,Block{span,ordinal,small});
 addresses_.push_back(p);events_.push_back({Event::user_alloc,ordinal,span,p});
 if(!small){auto* q=reinterpret_cast<std::uint8_t*>(std::uintptr_t(p));
  for(U k=0;k<span;++k)q[k]=std::uint8_t((ordinal*73u+k*131u+(k>>3u)+0x5du)&0xffu);}
 return p;
}
U Heap::ordinary_alloc(U n){const U span=round16(n);auto* p=HeapAlloc(handle_,0,span);
 need(p!=nullptr,"B1279 real ordinary HeapAlloc success path");return record_user(addr(p),span,false);}
void Heap::enter(){need(memory_.r32(0x0081729cu)==addr(lock_),"B1279 original lock9 identity");
 pending_live_=metadata_?r32(metadata_+0x144u):0u;
 pending_free_bytes_.clear();
 if(!portable_&&small_allocs_==2u&&small_frees_<2u&&pending_live_==2u-small_frees_){
  const U p=arena_+(small_frees_?0xfe0u:0xff0u);
  const auto it=blocks_.find(p);need(it!=blocks_.end()&&it->second.small,"B1279 pending small free owner");
  pending_free_ordinal_=it->second.ordinal;pending_free_bytes_=bytes(p,16u);
 }
 events_.push_back({Event::enter9,0u,addr(lock_),0u});EnterCriticalSection(lock_);}
void Heap::leave(){events_.push_back({Event::leave9,0u,addr(lock_),0u});LeaveCriticalSection(lock_);
 if(portable_)return;
 const U live=metadata_?r32(metadata_+0x144u):0u;
 if(live==pending_live_)return;
 if(live==pending_live_+1u){
  need(small_allocs_<2u&&live==small_allocs_+1u,"B1279 original small allocation ordinal");
  const U p=arena_+(small_allocs_?0xfe0u:0xff0u);
  need(r32(p-4u)==0x11u,"B1279 original interior allocation tag");
  record_user(p,16u,true);++small_allocs_;
 }else if(pending_live_==live+1u){
  need(small_frees_<2u&&pending_live_==2u-small_frees_,"B1279 original small free order");
  const U p=arena_+(small_frees_?0xfe0u:0xff0u);
  auto it=blocks_.find(p);need(it!=blocks_.end()&&it->second.small,"B1279 original small free ownership");
  need(pending_free_bytes_.size()==16u&&pending_free_ordinal_==it->second.ordinal,
       "B1279 small PREFREE snapshot must precede original mutation");
  prefree_.push_back({it->second.ordinal,pending_free_bytes_});
  events_.push_back({Event::user_free,it->second.ordinal,16u,p});
  blocks_.erase(it);++small_frees_;
 }else need(false,"B1279 unexpected CRT live-count transition");
}
U Heap::allocate(U n){
 if(n)return ordinary_alloc(n);
 need(portable_&&small_allocs_<2u&&memory_.r32(0x00817554u)==0u,
      "B1279 only two literal zero requests take the small route");
 scratch_[1]=0u;enter();U p=0u;
 try{p=small_allocs_==0u?
      small_crt_heap1279::allocate_first_zero(view_,*this,0u,0x7d100000u):
      small_crt_heap1279::allocate_second_zero(view_,0u,0x7d100000u);
 }catch(...){leave();throw;}
 leave();need(p==arena_+(small_allocs_?0xfe0u:0xff0u),"B1279 exact zero owner slot");
 record_user(p,16u,true);++small_allocs_;return p;
}
U Heap::ordinary_free(U p){auto it=blocks_.find(p);need(it!=blocks_.end()&&!it->second.small,"B1279 ordinary free owner");
 enter();leave();prefree_.push_back({it->second.ordinal,bytes(p,it->second.span)});
 const U result=HeapFree(handle_,0,reinterpret_cast<void*>(std::uintptr_t(p)));
 events_.push_back({Event::user_free,it->second.ordinal,it->second.span,result});
 need(result!=0u,"B1279 real ordinary HeapFree");blocks_.erase(it);return result;}
U Heap::release(U p){need(portable_&&p,"B1279 portable release only");auto it=blocks_.find(p);
 need(it!=blocks_.end(),"B1279 release exact live owner");
 if(!it->second.small)return ordinary_free(p);
 need(small_frees_<2u&&p==arena_+(small_frees_?0xfe0u:0xff0u),
      "B1279 actual zero-owner release order");
 prefree_.push_back({it->second.ordinal,bytes(p,16u)});enter();
 try{if(small_frees_==0u)small_crt_heap1279::release_first_zero(view_,p);
     else small_crt_heap1279::release_second_zero(view_,p);}
 catch(...){leave();throw;}
 leave();events_.push_back({Event::user_free,it->second.ordinal,16u,p});
 blocks_.erase(it);++small_frees_;return p;
}
U Heap::allocate_reader(){need(false,"B1279 does not allocate file readers");return 0u;}
void Heap::free_reader(U){need(false,"B1279 does not free file readers");}
bool Heap::owns(U a,U n) const{
 if(within(a,n,table_,320u)||within(a,n,metadata_,0x41c4u)||
    within(a,n,arena_,committed_?0x8000u:0u)||within(a,n,0x7d100000u,8u))return true;
 for(const auto& [p,b]:blocks_)if(!b.small&&within(a,n,p,b.span))return true;
 return false;
}
void Heap::require_live(U a,U n) const{need(owns(a,n),"B1279 access outside declared real allocation/CRT state");}
U Heap::r8(U a)const{if(within(a,1u,0x7d100000u,8u))return reinterpret_cast<const std::uint8_t*>(scratch_.data())[a-0x7d100000u];
 if(owns(a,1u))return *reinterpret_cast<const std::uint8_t*>(std::uintptr_t(a));return memory_.r8(a);}
U Heap::r32(U a)const{U v=0;for(U k=0;k<4u;++k)v|=r8(a+k)<<(8u*k);return v;}
void Heap::w8(U a,U v){if(within(a,1u,0x7d100000u,8u))reinterpret_cast<std::uint8_t*>(scratch_.data())[a-0x7d100000u]=std::uint8_t(v);
 else if(owns(a,1u))*reinterpret_cast<std::uint8_t*>(std::uintptr_t(a))=std::uint8_t(v);else memory_.w8(a,v);}
void Heap::w32(U a,U v){for(U k=0;k<4u;++k)w8(a+k,v>>(8u*k));}
U Heap::heap_alloc(U heap,U flags,U n){need(portable_&&heap==addr(handle_)&&flags==8u&&n==0x41c4u&&!metadata_,
 "B1279 genuine metadata HeapAlloc(HEAP_ZERO_MEMORY,0x41c4)");
 auto* p=HeapAlloc(handle_,flags,n);need(p!=nullptr,"B1279 real metadata allocation");
 metadata_=addr(p);need(HeapValidate(handle_,0,p)&&HeapSize(handle_,0,p)>=n,"B1279 metadata bounds");
 events_.push_back({Event::metadata_alloc,0u,n,metadata_});return metadata_;}
U Heap::virtual_alloc(U address,U n,U type,U protection){
 need(portable_&&protection==PAGE_READWRITE,"B1279 real VirtualAlloc protection");
 if(type==MEM_RESERVE){need(!address&&!arena_&&n==0x100000u,"B1279 1MiB reserve");
  auto* p=VirtualAlloc(nullptr,n,type,protection);need(p!=nullptr,"B1279 real reserve");arena_=addr(p);
  events_.push_back({Event::reserve,0u,n,arena_});return arena_;}
 need(type==MEM_COMMIT&&address==arena_&&n==0x8000u&&!committed_,"B1279 first 32KiB commit");
 auto* p=VirtualAlloc(reinterpret_cast<void*>(std::uintptr_t(address)),n,type,protection);
 need(addr(p)==arena_,"B1279 real commit identity");committed_=true;
 events_.push_back({Event::commit,0u,n,arena_});return arena_;
}
std::vector<Owner> Heap::live()const{std::vector<Owner> out;for(auto [p,b]:blocks_)out.push_back({p,b.span,b.ordinal,b.small});
 std::sort(out.begin(),out.end(),[](const auto& a,const auto& b){return a.ordinal<b.ordinal;});return out;}
std::vector<std::uint8_t> Heap::bytes(U p,U n)const{need(owns(p,n),"B1279 requested raw snapshot extent");
 const auto* q=reinterpret_cast<const std::uint8_t*>(std::uintptr_t(p));return{q,q+n};}
std::vector<std::uint8_t> Heap::table_bytes()const{return bytes(table_,320u);}
std::vector<std::uint8_t> Heap::metadata_bytes()const{return bytes(metadata_,0x41c4u);}
std::vector<std::uint8_t> Heap::arena_bytes()const{return bytes(arena_,0x8000u);}

void Heap::install_original_iat(){need(!portable_&&!active_original_,"B1279 one original observer");
 bind(0x785270u,"HeapAlloc",addr(reinterpret_cast<const void*>(&iat_heap_alloc)));
 bind(0x785268u,"HeapFree",addr(reinterpret_cast<const void*>(&iat_heap_free)));
 bind(0x785290u,"VirtualAlloc",addr(reinterpret_cast<const void*>(&iat_virtual_alloc)));
 bind(0x78528cu,"VirtualFree",addr(reinterpret_cast<const void*>(&iat_virtual_free)));
 bind(0x785188u,"HeapDestroy",addr(reinterpret_cast<const void*>(&iat_heap_destroy)));
 bind(0x7851dcu,"EnterCriticalSection",addr(reinterpret_cast<const void*>(&iat_enter)));
 bind(0x7851e0u,"LeaveCriticalSection",addr(reinterpret_cast<const void*>(&iat_leave)));
 active_original_=this;active_=true;
}
void Heap::deactivate_original_iat(){need(active_original_==this,"B1279 wrong original observer");
 const std::pair<U,U> slots[]{
  {0x785270u,addr(reinterpret_cast<const void*>(&iat_heap_alloc))},
  {0x785268u,addr(reinterpret_cast<const void*>(&iat_heap_free))},
  {0x785290u,addr(reinterpret_cast<const void*>(&iat_virtual_alloc))},
  {0x78528cu,addr(reinterpret_cast<const void*>(&iat_virtual_free))},
  {0x785188u,addr(reinterpret_cast<const void*>(&iat_heap_destroy))},
  {0x7851dcu,addr(reinterpret_cast<const void*>(&iat_enter))},
  {0x7851e0u,addr(reinterpret_cast<const void*>(&iat_leave))}};
 const char* names[]{"HeapAlloc","HeapFree","VirtualAlloc","VirtualFree",
                     "HeapDestroy","EnterCriticalSection","LeaveCriticalSection"};
 for(U k=0;k<7u;++k){auto* slot=reinterpret_cast<volatile U*>(slots[k].first);
  need(*slot==slots[k].second,"B1279 active IAT slot changed unexpectedly");*slot=function(names[k]);}
 active_original_=nullptr;active_=false;}
void* WINAPI Heap::iat_heap_alloc(HANDLE h,DWORD flags,SIZE_T n){auto* self=active_original_;
 if(!self||h!=self->handle_||n>0xffffffffu)callback_fail("HeapAlloc handle/size");
 try{
  if(flags==8u&&n==0x41c4u&&!self->metadata_){auto* p=HeapAlloc(h,flags,n);
   need(p!=nullptr,"B1279 original metadata allocation failed");self->metadata_=addr(p);
   self->events_.push_back({Event::metadata_alloc,0u,U(n),self->metadata_});return p;}
  need(flags==0u&&n>0u,"B1279 original ordinary HeapAlloc flags/size");
  auto* p=HeapAlloc(h,flags,n);need(p!=nullptr,"B1279 original ordinary allocation failed");
  self->record_user(addr(p),U(n),false);return p;
 }catch(...){callback_fail();}
}
BOOL WINAPI Heap::iat_heap_free(HANDLE h,DWORD flags,LPVOID p){auto* self=active_original_;
 if(!self||h!=self->handle_||flags||!p)callback_fail("HeapFree handle/flags/pointer");
 try{const U raw=addr(p);auto it=self->blocks_.find(raw);
  if(self->teardown_mode_&&raw==self->metadata_){
   need(self->events_.size()>=2u&&self->events_.back().kind==Event::release_region,
        "B1279 metadata free follows arena release");
   const BOOL ok=HeapFree(h,0,p);
   self->events_.push_back({Event::metadata_free,0u,0x41c4u,U(ok)});
   need(ok!=FALSE,"B1279 original metadata HeapFree result");return ok;}
  if(self->teardown_mode_&&raw==self->table_){
   need(!self->events_.empty()&&self->events_.back().kind==Event::metadata_free,
        "B1279 table free follows metadata free");
   const BOOL ok=HeapFree(h,0,p);
   self->events_.push_back({Event::table_free,0u,320u,U(ok)});
   need(ok!=FALSE,"B1279 original table HeapFree result");return ok;}
  need(it!=self->blocks_.end()&&!it->second.small,"B1279 original ordinary free identity");
  self->prefree_.push_back({it->second.ordinal,self->bytes(raw,it->second.span)});
  const BOOL ok=HeapFree(h,0,p);self->events_.push_back({Event::user_free,it->second.ordinal,it->second.span,U(ok)});
  if(ok)self->blocks_.erase(it);return ok;
 }catch(...){callback_fail();}
}
void* WINAPI Heap::iat_virtual_alloc(LPVOID address,SIZE_T n,DWORD type,DWORD protection){auto* self=active_original_;
 if(!self||n>0xffffffffu||protection!=PAGE_READWRITE)callback_fail();
 try{if(type==MEM_RESERVE){need(!address&&n==0x100000u&&!self->arena_,"B1279 original reserve tuple");
   auto* p=VirtualAlloc(address,n,type,protection);need(p!=nullptr,"B1279 original reserve failed");
   self->arena_=addr(p);self->events_.push_back({Event::reserve,0u,U(n),self->arena_});return p;}
  need(type==MEM_COMMIT&&addr(address)==self->arena_&&n==0x8000u&&!self->committed_,
       "B1279 original commit tuple");auto* p=VirtualAlloc(address,n,type,protection);
  need(addr(p)==self->arena_,"B1279 original commit failed");self->committed_=true;
  self->events_.push_back({Event::commit,0u,U(n),self->arena_});return p;
 }catch(...){callback_fail();}
}
BOOL WINAPI Heap::iat_virtual_free(LPVOID p,SIZE_T n,DWORD type){auto* self=active_original_;
 if(!self||!self->teardown_mode_||addr(p)!=self->arena_)callback_fail();
 try{if(type==MEM_DECOMMIT){
   need(n==0x100000u&&self->committed_,"B1279 original first teardown decommit tuple");
   const BOOL ok=VirtualFree(p,n,type);
   self->events_.push_back({Event::decommit,0u,0x100000u,U(ok)});
   need(ok!=FALSE,"B1279 original decommit result");return ok;}
  need(type==MEM_RELEASE&&n==0u&&self->events_.back().kind==Event::decommit,
       "B1279 original arena release after decommit");
  const BOOL ok=VirtualFree(p,n,type);
  self->events_.push_back({Event::release_region,0u,0x100000u,U(ok)});
  need(ok!=FALSE,"B1279 original region release result");return ok;
 }catch(...){callback_fail();}
}
BOOL WINAPI Heap::iat_heap_destroy(HANDLE h){auto* self=active_original_;
 if(!self||!self->teardown_mode_||h!=self->handle_)callback_fail();
 try{need(!self->events_.empty()&&self->events_.back().kind==Event::table_free,
          "B1279 original HeapDestroy follows table free");
  const BOOL ok=HeapDestroy(h);
  self->events_.push_back({Event::heap_destroy,0u,0u,U(ok)});
  need(ok!=FALSE,"B1279 original HeapDestroy result");self->torn_down_=true;return ok;
 }catch(...){callback_fail();}
}
void Heap::teardown_portable(){
 need(portable_&&!torn_down_&&blocks_.empty()&&metadata_&&arena_,
      "B1279 portable teardown requires closed users and live backings");
 const auto* a=reinterpret_cast<void*>(std::uintptr_t(arena_));
 const auto* m=reinterpret_cast<void*>(std::uintptr_t(metadata_));
 const auto* t=reinterpret_cast<void*>(std::uintptr_t(table_));
 U ok=VirtualFree(const_cast<void*>(a),0x100000u,MEM_DECOMMIT);
 events_.push_back({Event::decommit,0u,0x100000u,ok});need(ok!=0u,"B1279 portable decommit");
 ok=VirtualFree(const_cast<void*>(a),0u,MEM_RELEASE);
 events_.push_back({Event::release_region,0u,0x100000u,ok});need(ok!=0u,"B1279 portable region release");
 ok=HeapFree(handle_,0,const_cast<void*>(m));
 events_.push_back({Event::metadata_free,0u,0x41c4u,ok});need(ok!=0u,"B1279 portable metadata free");
 ok=HeapFree(handle_,0,const_cast<void*>(t));
 events_.push_back({Event::table_free,0u,320u,ok});need(ok!=0u,"B1279 portable table free");
 ok=HeapDestroy(handle_);
 events_.push_back({Event::heap_destroy,0u,0u,ok});need(ok!=0u,"B1279 portable heap destroy");
 torn_down_=true;
}
void Heap::begin_original_teardown(){
 need(!portable_&&active_original_==this&&!teardown_mode_&&!torn_down_&&
      blocks_.empty()&&metadata_&&arena_,"B1279 actual teardown prerequisites");
 teardown_mode_=true;
}
void Heap::end_original_teardown(){
 need(teardown_mode_&&torn_down_&&events_.size()>=5u,
      "B1279 original five-operation teardown incomplete");
 const Event::Kind kinds[]{Event::decommit,Event::release_region,
   Event::metadata_free,Event::table_free,Event::heap_destroy};
 for(U k=0;k<5u;++k)need(events_[events_.size()-5u+k].kind==kinds[k],
                       "B1279 original teardown API ordering");
 teardown_mode_=false;
}
void WINAPI Heap::iat_enter(LPCRITICAL_SECTION p){auto* self=active_original_;
 if(!self||p!=self->lock_)callback_fail("critical-section identity");
 try{self->enter();}catch(...){callback_fail();}
}
void WINAPI Heap::iat_leave(LPCRITICAL_SECTION p){auto* self=active_original_;
 if(!self||p!=self->lock_)callback_fail("critical-section identity");
 try{self->leave();}catch(...){callback_fail();}
}
}
