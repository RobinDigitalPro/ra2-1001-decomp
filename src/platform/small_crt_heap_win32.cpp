#include "small_crt_heap_b337.hpp"
#include "small_crt_heap_formatted309.hpp"
#include "small_crt_heap_insertion305.hpp"
#include "small_crt_heap_constructor291.hpp"
#include "small_crt_heap_512.hpp"
#include "small_crt_heap_palette248.hpp"
#include "small_crt_heap_ini234.hpp"
#include "small_crt_heap_constructor226.hpp"
#include "small_crt_heap_tuple223.hpp"
#include "platform/small_crt_heap_palette208.hpp"
#include "small_crt_heap_win32.hpp"
#include "small_crt_heap_string169.hpp"
#include "small_crt_heap_empty173.hpp"
#include "small_crt_heap_empty236.hpp"
#include <cstring>
#include <stdexcept>
#include <sstream>

namespace ra2::platform::small_crt_heap {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::runtime_error(why);}
unsigned addr(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
bool range(unsigned a,unsigned n,unsigned base,unsigned size){return a>=base&&std::uint64_t(a)+n<=std::uint64_t(base)+size;}
unsigned get(const std::vector<unsigned char>&v,unsigned off){unsigned x;std::memcpy(&x,v.data()+off,4);return x;}
void put(std::vector<unsigned char>&v,unsigned off,unsigned x){std::memcpy(v.data()+off,&x,4);}
std::vector<unsigned char> bytes(unsigned p,unsigned n){auto*b=reinterpret_cast<unsigned char*>(p);return {b,b+n};}
}
Heap* Heap::active_=nullptr;
Heap::Heap(Memory&m,unsigned table,HANDLE heap,CRITICAL_SECTION*lock,unsigned request,unsigned seed):memory_(m),table_(table),heap_(heap),lock_(lock),request_(request),seed_(seed){
 static_assert(sizeof(void*)==4,"x86 required");
 need(table&&heap&&lock,"small heap environment absent");
 need((request>=2&&request<=12)||request==20||request==24||request==32||request==40||request==60||request==88||request==111||request==156||request==212||request==232||request==424||request==512||request==768,"unsupported selected request");
 need(m.r32(0xb10e14)==0&&m.r32(0xb10e18)==table&&m.r32(0xb10e1c)==addr(heap),"fresh CRT globals required");
 need(HeapValidate(heap,0,reinterpret_cast<void*>(table))&&HeapSize(heap,0,reinterpret_cast<void*>(table))>=320,"actual region table invalid");
 requests_.push_back(request);
}
Heap::Heap(Memory&m,unsigned table,HANDLE heap,CRITICAL_SECTION*lock,std::vector<unsigned>requests,std::vector<unsigned>pointers,unsigned seed)
 :Heap(m,table,heap,lock,requests.empty()?0:(requests.front()==1?2:requests.front()==68?88:requests.front()==16?20:requests.front()),seed){
 if(requests==std::vector<unsigned>{32}||requests==std::vector<unsigned>{40}){
  need(pointers.empty()&&m.r32(0xb10e10)==0&&m.r32(0xb10e08)==0,"236 exact class2 terminal recipe/tracker");terminal_class2_=true;
 }else if(requests==std::vector<unsigned>{16}){
  need(pointers==std::vector<unsigned>{0xfe0},"306 exact child-to-ordinary pointer schema");request_=16;
 }else if(requests==std::vector<unsigned>{1}){
  need(pointers.empty(),"288 exact standalone1 recipe has no internal pointer schema");request_=1;
 }else if(requests==std::vector<unsigned>{512}){
  need(pointers.empty(),"282 exact standalone512 recipe has no internal pointer schema");
 }else if(requests==palette248::request_vector()){
  need(pointers==palette248::pointer_offsets(),"248 exact69 constructor/map/descriptor pointers");
 }else if(b337::valid_recipe(requests)){
  need(pointers==b337::pointer_offsets(),"337 exact ten internal node/clone links");
 }else if(ini234::valid_recipe(requests)){
  need(pointers==ini234::pointer_offsets(requests),"234 exact66 internal node/clone links required");
 }else if(requests==formatted309::requests()){
  need(pointers==formatted309::pointer_offsets(),"309 exact ten internal live pointers");request_=68;
 }else if(requests==insertion305::requests()){
  need(pointers==insertion305::pointer_offsets(),"305 exact ten internal live pointers");request_=68;
 }else if(requests==constructor291::requests()){
  need(pointers==constructor291::pointer_offsets(),"291 exact six live internal pointer fields");
 }else if(requests==constructor226::requests()){
  need(pointers==std::vector<unsigned>{0xf38,0xf40,0xf64,0xf6c,0xfa4,0xfb0,0xfb4,0xfc0},"226 exact eight nested-pointer fields");
 }else if(requests==tuple223::requests()){
  need(pointers==std::vector<unsigned>{0xfd4,0xfe4},"223 exact two stale full-pointer fields");request_=1;
 }else if(requests==palette208::requests()){
  need(pointers.empty(),"208 payloads contain no internal CRT pointers");
 }else if(requests==std::vector<unsigned>{9}){
  need(pointers.empty()&&m.r32(0xb10e10)==0&&m.r32(0xb10e08)==0,"199 one request9 and zero empty-chunk tracker required");
  terminal_single9_=true;
 }else if(requests==std::vector<unsigned>{20}){
  need(pointers.empty()&&m.r32(0xb10e10)==0&&m.r32(0xb10e08)==0,"173 one fresh allocation and zero empty-chunk tracker required");
 }else if(requests.size()==6){
  need(requests==std::vector<unsigned>{3,11,11,13,13,13},"exact six-allocation string sequence required");
  need(pointers==std::vector<unsigned>{0xff0,0xff4},"exact final free-class0 pointer schema required");
 }else if(requests.size()==2){
  need(requests[0]>=2&&requests[0]<=12&&requests[1]>=2&&requests[1]<=12,"two bounded short-string allocations required");
  need(pointers.empty(),"two string payloads have no internal pointer cells");
 }else if(requests.size()==4){
  need(requests==std::vector<unsigned>{9,40,3,2},"only the four-allocation UTF16 INI sequence supported");
  need(pointers==std::vector<unsigned>{0xfbc,0xfc0,0xfe0,0xfe4},"exact node clone and freed class1 link schema required");
 }else{
  need(requests.size()==3&&requests[0]==40,"only the three-allocation INI insertion sequence supported");
  need(requests[1]>=2&&requests[1]<=12&&requests[2]>=2&&requests[2]<=12,"bounded short value/key allocations required");
  need(pointers==std::vector<unsigned>{0xfdc,0xfe0},"only INI node name/value pointer schema supported");
 }
 requests_=std::move(requests);arena_pointer_offsets_=std::move(pointers);
}
Heap::~Heap(){if(active_==this)active_=nullptr;if(ordinary_)HeapFree(heap_,0,reinterpret_cast<void*>(ordinary_));if(arena_)VirtualFree(reinterpret_cast<void*>(arena_),0,MEM_RELEASE);if(metadata_)HeapFree(heap_,0,reinterpret_cast<void*>(metadata_));}
bool Heap::owned(unsigned a,unsigned n) const{return range(a,n,table_,320)||(metadata_&&range(a,n,metadata_,0x41c4))||(committed_&&range(a,n,arena_,0x8000))||(ordinary_&&range(a,n,ordinary_,ordinary_bytes_));}
std::uint8_t Heap::r8(unsigned a)const{if(owned(a,1))return *reinterpret_cast<unsigned char*>(a);if(range(a,1,0x7d100000,8))return reinterpret_cast<const unsigned char*>(scratch_)[a-0x7d100000];return memory_.r8(a);}
unsigned Heap::r32(unsigned a)const{unsigned x=0;for(unsigned k=0;k<4;++k)x|=unsigned(r8(a+k))<<(8*k);return x;}
void Heap::w8(unsigned a,std::uint8_t v){if(owned(a,1))*reinterpret_cast<unsigned char*>(a)=v;else if(range(a,1,0x7d100000,8))reinterpret_cast<unsigned char*>(scratch_)[a-0x7d100000]=v;else memory_.w8(a,v);}
void Heap::w32(unsigned a,unsigned v){for(unsigned k=0;k<4;++k)w8(a+k,std::uint8_t(v>>(8*k)));}
unsigned Heap::heap_alloc(unsigned heap,unsigned flags,unsigned size){
 if(flags==0){
  const bool backing136=request_==60&&committed_&&size==0x2810;
  const bool backing306=request_==16&&committed_&&size==0x1810&&r32(metadata_+0x144)==1;
  const bool building252=request_==4&&!committed_&&next_allocation_==0&&size==0x5e0;
  need(heap==addr(heap_)&&(backing136||building252||backing306)&&!ordinary_,"only the specified ordinary allocation order/size supported");
  auto*p=static_cast<unsigned char*>(HeapAlloc(heap_,0,size));need(p!=nullptr,"real ordinary backing failed");ordinary_=addr(p);ordinary_bytes_=size;
  need(HeapValidate(heap_,0,p)&&HeapSize(heap_,0,p)>=size,"ordinary backing bounds invalid");
  for(unsigned k=0;k<size;++k)p[k]=static_cast<unsigned char>(seed_*73+k*131+(k>>3)+0x5d);
  events_.push_back({6,0,size,0xd4000000,0});return ordinary_;
 }
 need(heap==addr(heap_)&&flags==8&&size==0x41c4&&!metadata_,"only first zeroed metadata allocation supported");
 auto*p=HeapAlloc(heap_,flags,size);need(p!=nullptr,"real metadata allocation failed");metadata_=addr(p);
 need(HeapValidate(heap_,0,p)&&HeapSize(heap_,0,p)>=size,"real metadata bounds invalid");
 events_.push_back({2,flags,size,0xd2000000,0});return metadata_;
}
unsigned Heap::virtual_alloc(unsigned address,unsigned size,unsigned type,unsigned protection){
 need(protection==PAGE_READWRITE,"unexpected arena protection");
 if(type==MEM_RESERVE){need(!address&&!arena_&&size==0x100000,"unexpected reserve");auto*p=VirtualAlloc(nullptr,size,type,protection);need(p!=nullptr,"real reserve failed");arena_=addr(p);events_.push_back({3,0,size,type,protection});return arena_;}
 need(type==MEM_COMMIT&&address==arena_&&size==0x8000&&!committed_,"unexpected commit");
 auto*p=VirtualAlloc(reinterpret_cast<void*>(address),size,type,protection);need(addr(p)==arena_,"real commit failed");committed_=true;events_.push_back({4,0xd3000000,size,type,protection});return addr(p);
}
void Heap::enter(){need(addr(lock_)==memory_.r32(0x81729c),"original lock9 identity mismatch");events_.push_back({1,addr(lock_),0,0,0});EnterCriticalSection(lock_);}
void Heap::leave(){events_.push_back({5,addr(lock_),0,0,0});LeaveCriticalSection(lock_);}
unsigned Heap::allocate_building252(){
 need(request_==4&&requests_==std::vector<unsigned>{4}&&!committed_&&!ordinary_,"252 ordinary object must precede small child");
 return heap_alloc(addr(heap_),0,0x5e0);
}
unsigned Heap::building252_pointer()const{
 need(request_==4&&ordinary_&&ordinary_bytes_==0x5e0,"252 ordinary object identity absent");
 return ordinary_;
}
unsigned Heap::backing306_pointer()const{need(request_==16&&ordinary_&&ordinary_bytes_==0x1810,"306 exact ordinary backing identity");return ordinary_;}
unsigned Heap::allocate(unsigned request){
 if(request_==16&&request==0x1804){need(committed_&&r32(metadata_+0x144)==1,"306 exactly one small owner before ordinary backing");return heap_alloc(addr(heap_),0,0x1810);}
 if(requests_==std::vector<unsigned>{512}){
  need(request==512&&next_allocation_==0&&memory_.r32(0x817554)==1016,"282 exact first512 allocation required");
  w32(0x7d100004,512);enter();unsigned result;
  try{result=fresh512::allocate_fresh512_uppermask_class32(*this,*this,request,0x7d100000);}catch(...){leave();throw;}
  leave();++next_allocation_;need(result==arena_+0xdf0,"282 exact live allocation identity");return result;
 }
 if(requests_==palette248::request_vector()){
  const auto n=next_allocation_;need(n<29&&request==requests_[n]&&memory_.r32(0x817554)==1016,"248 exact29 allocation recipe");
  enter();unsigned result;
  try{result=n==0?palette248::allocate_first(*this,*this,request,0x7d100000,palette248::requests):palette248::allocate_existing(*this,request,0x7d100000,n,palette248::requests);}catch(...){leave();throw;}
  leave();++next_allocation_;unsigned offset=0x1000;
  for(unsigned k=0;k<=n;++k)offset-=(requests_[k]+0x17)&~15u;
  need(result==arena_+offset&&r32(metadata_+0x144)==n+1,"248 exact allocation identity/live count");return result;
 }

 if(tuple223_sequence()){
  const unsigned frees[]{0,0,0,1,3,4,4,5,7,7,8,10,10,11};
  const unsigned offsets[]{0xff0,0xfd0,0xfc0,0xfe0,0xff0,0xfe0,0xfd0,0xfe0,0xfe0,0xfd0,0xfe0,0xfe0,0xfd0,0xfe0};
  const auto n=next_allocation_;need(n<14&&request==requests_[n]&&tuple223_releases_==frees[n]&&memory_.r32(0x817554)==1016,"223 exact allocation request/interleave/threshold");
  w32(0x7d100004,request);enter();unsigned result;
  try{
   if(n==0)result=fun_007736d3_allocate_first_small_block(*this,*this,request,0x7d100000);
   else if(n==3)result=tuple223::allocate_class1_span20_split10(*this,request,0x7d100000,2);
   else if(n==4||n==7||n==10||n==13)result=tuple223::allocate_exact_class0_span10(*this,request,0x7d100000,offsets[n],n==4?1:2);
   else result=fun_007736d3_allocate_existing_first_chunk(*this,request,0x7d100000);
  }catch(...){leave();throw;}leave();need(result==arena_+offsets[n],"223 actual returned allocation identity");++next_allocation_;return result;
 }

 if(string169_sequence()){
  need(next_allocation_<6&&request==requests_[next_allocation_]&&memory_.r32(0x817554)==1016,"169 exact allocation request/order");
  const unsigned expected_releases[]{0,0,0,0,1,3};
  need(string169_releases_==expected_releases[next_allocation_],"169 allocation interleave");
  w32(0x7d100004,request);enter();unsigned result;
  try{
   if(next_allocation_==0)result=fun_007736d3_allocate_first_small_block(*this,*this,request,0x7d100000);
   else if(next_allocation_<=2)result=fun_007736d3_allocate_existing_first_chunk(*this,request,0x7d100000);
   else if(next_allocation_==3)result=string169::allocate_class63_request13_for_concat(*this,0x7d100000);
   else result=string169::allocate_exact_class1_20(*this,0x7d100000);
  }catch(...){leave();throw;}
  leave();const unsigned offsets[]{0xff0,0xfd0,0xfb0,0xf90,0xfb0,0xfd0};
  need(result==arena_+offsets[next_allocation_],"169 actual returned identity");++next_allocation_;return result;
 }
 if(request_==60&&request==0x2801){need(committed_&&memory_.r32(0xb10e14)==1,"small node must precede ordinary backing");return heap_alloc(addr(heap_),0,(request+15)&~15u);}
 need(next_allocation_<requests_.size()&&request==requests_[next_allocation_]&&memory_.r32(0x817554)==1016,"selected small-allocation sequence/threshold required");
 enter();unsigned result;
 try{result=next_allocation_==0?fun_007736d3_allocate_first_small_block(*this,*this,request,0x7d100000):requests_==formatted309::requests()?formatted309::allocate_existing_first_chunk(*this,request,0x7d100000,next_allocation_,requests_):requests_==insertion305::requests()?insertion305::allocate_existing_first_chunk(*this,request,0x7d100000,next_allocation_,requests_):requests_==constructor291::requests()?constructor291::allocate_existing_first_chunk(*this,request,0x7d100000,next_allocation_,requests_):b337::valid_recipe(requests_)?b337::allocate_existing_first_chunk(*this,request,0x7d100000,next_allocation_,requests_):ini234::valid_recipe(requests_)?ini234::allocate_existing_first_chunk(*this,request,0x7d100000,next_allocation_,requests_):requests_==constructor226::requests()?constructor226::allocate_existing_first_chunk(*this,request,0x7d100000,next_allocation_,requests_):requests_==palette208::requests()?palette208::allocate_existing_first_chunk(*this,request,0x7d100000,next_allocation_,requests_):fun_007736d3_allocate_existing_first_chunk(*this,request,0x7d100000);}catch(...){leave();throw;}
 leave();++next_allocation_;return result;
}
unsigned Heap::normalize_user_pointer(unsigned result)const{
 if(tuple223_sequence()){validate_tuple223_result(result);return 0xd3000000+result-arena_;}
 if(string169_sequence()){validate_string169_result(result);return 0xd3000000+result-arena_;}
 need(metadata_&&committed_,"small result has no real allocation");unsigned offset=0x1000;bool found=false;
 for(auto request:requests_){const auto rounded=(request+0x17)&~15u;offset-=rounded;if(result==arena_+offset){need(r32(result-4)==rounded+1&&r32(result+rounded-8)==rounded+1,"published small slot tags invalid");found=true;break;}}
 need(found,"small result outside declared allocation identities");
 return 0xd3000000+result-arena_;
}
unsigned Heap::first_user_pointer()const{
 return user_pointer(0);
}
unsigned Heap::user_pointer(unsigned ordinal)const{
 if(tuple223_sequence()){need(ordinal==4,"223 only final surviving allocation5 is exposed");validate_tuple223_result(arena_+0xff0);return arena_+0xff0;}
 if(string169_sequence()){
  need(ordinal==5,"169 only final surviving ordinal is exposed");const auto result=arena_+0xfd0;
  validate_string169_result(result);return result;
 }
 const bool released=committed_&&metadata_&&requests_==std::vector<unsigned>{9,40,3,2}&&r32(arena_+0xfdc)==0x20;
 need(committed_&&metadata_&&ordinal<requests_.size()&&(!released||ordinal!=0)&&r32(metadata_+0x144)==requests_.size()-(released?1:0),"exact declared number of live small allocations required");
 unsigned consumed=0,offset=0x1000;
 for(unsigned n=0;n<requests_.size();++n){const auto rounded=(requests_[n]+0x17)&~15u;consumed+=rounded;if(n<=ordinal)offset-=rounded;}
 need(r32(arena_+0x0c)==0xff0-consumed,"actual residual extent disagrees with live allocation sequence");
 const auto result=arena_+offset;(void)normalize_user_pointer(result);return result;
}
void Heap::release(unsigned user){
 if(tuple223_sequence()){
  const unsigned allocated[]{3,4,4,5,7,8,8,10,11,11,13,14,14};
  const unsigned offsets[]{0xfd0,0xfc0,0xff0,0xfe0,0xfe0,0xfd0,0xfe0,0xfe0,0xfd0,0xfe0,0xfe0,0xfd0,0xfe0};
  const auto n=tuple223_releases_;need(n<13&&next_allocation_==allocated[n]&&user==arena_+offsets[n],"223 exact free ordinal, live identity and interleave");
  enter();try{
   if(n==0)tuple223::release_isolated_span(*this,user,0x20,0xfd0,3);
   else if(n==1)tuple223::release_span10_between_class63_and_class0(*this,user,3);
   else if(n==2)tuple223::release_isolated_span(*this,user,0x10,0xff0,2);
   else if(n==4||n==7||n==10)tuple223::release_isolated_span(*this,user,0x10,0xfe0,3);
   else tuple223::release_left_class63_span10(*this,user,offsets[n]==0xfd0?0xfc0:0xfd0,offsets[n]==0xfd0?3:2);
  }catch(...){leave();throw;}leave();++tuple223_releases_;return;
 }

 if(terminal_class2_){
  need(requests_.size()==1&&(request_==32||request_==40)&&next_allocation_==1&&!empty173_released_&&user==arena_+0xfd0,"236 one selected class2 terminal release");
  enter();try{empty236::release_last_class2(*this,user);}catch(...){leave();throw;}
  leave();empty173_released_=true;return;
 }
 if(request_==20||terminal_single9_){
  need(requests_==std::vector<unsigned>{terminal_single9_?9u:20u}&&next_allocation_==1&&!empty173_released_&&user==arena_+0xfe0,"exactly one last-live class1 release required");
  enter();try{empty173::release_last_class1(*this,user);}catch(...){leave();throw;}
  leave();empty173_released_=true;return;
 }
 if(string169_sequence()){
  need(string169_releases_<5,"169 release count");
  const unsigned allocations[]{4,5,5,6,6},offsets[]{0xfb0,0xf90,0xfd0,0xfb0,0xff0};
  const unsigned spans[]{0x20,0x20,0x20,0x20,0x10},lefts[]{0,0xf80,0,0xfa0,0};
  const auto n=string169_releases_;
  need(next_allocation_==allocations[n]&&user==arena_+offsets[n],"169 exact free order/identity");
  enter();try{
   if(lefts[n])string169::release_left_class63_same_class(*this,user,lefts[n]);
   else string169::release_empty_class0_or_class1(*this,user,spans[n]);
  }catch(...){leave();throw;}leave();++string169_releases_;return;
 }
 need(requests_==std::vector<unsigned>{9,40,3,2}&&next_allocation_==4&&user==user_pointer(0),
      "only the first temporary after the complete four-allocation sequence can be released");
 enter();try{fun_007733a8_release_class1_temporary(*this,user);}catch(...){leave();throw;}leave();
}
State Heap::snapshot(unsigned result)const{
 if(request_==20||terminal_single9_||terminal_class2_){need(result==0,"terminal snapshot has no surviving user pointer");validate_empty173_result();}
 else (void)normalize_user_pointer(result);
 need(memory_.r32(0xb10e14)==1&&memory_.r32(0xb10e0c)==table_,"small region globals differ");
 MEMORY_BASIC_INFORMATION q{};need(VirtualQuery(reinterpret_cast<void*>(arena_),&q,sizeof(q))&&q.State==MEM_COMMIT&&q.Protect==PAGE_READWRITE&&q.RegionSize==0x8000,"committed chunk protection/size differs");
 need(VirtualQuery(reinterpret_cast<void*>(arena_+0x8000),&q,sizeof(q))&&q.State==MEM_RESERVE,"uncommitted rest of arena changed");
 State s{bytes(table_,320),bytes(metadata_,0x41c4),bytes(arena_,0x8000),events_,(request_==20||terminal_single9_||terminal_class2_)?0u:result-arena_,{}};
 if(ordinary_)s.ordinary=bytes(ordinary_,ordinary_bytes_);
 const auto normalize=[&](std::vector<unsigned char>&v,unsigned off){const auto x=get(v,off);unsigned y;
  if(range(x,1,metadata_,0x41c4))y=0xd2000000+x-metadata_;
  else if(range(x,1,arena_,0x8000))y=0xd3000000+x-arena_;
  else if(ordinary_&&range(x,1,ordinary_,ordinary_bytes_))y=0xd4000000+x-ordinary_;
  else throw std::runtime_error("declared small CRT pointer escaped allocation identity");put(v,off,y);
 };
 // Exact pointer schema from 0x373a8d; never mask pointer-looking scalar bytes.
 normalize(s.table,12);normalize(s.table,16);
 for(unsigned n=0;n<63;++n){normalize(s.metadata,0x148+n*8);normalize(s.metadata,0x14c+n*8);}
 normalize(s.metadata,0x340);normalize(s.metadata,0x344);
 for(unsigned n=0;n<8;++n){normalize(s.arena,n*0x1000+0x10);normalize(s.arena,n*0x1000+0x14);}
 if(request_==16){need(ordinary_&&ordinary_bytes_==0x1810&&get(s.arena,0xfe0)==ordinary_+4,"306 child-to-row pointer identity");}
 if(request_==60){need(ordinary_&&ordinary_bytes_==0x2810,"node backing allocation missing");normalize(s.arena,0xfc0);normalize(s.arena,0xfc8);}
 if(request_==4&&ordinary_){need(ordinary_bytes_==0x5e0&&get(s.ordinary,0xcc)==first_user_pointer(),"252 sole child pointer identity");normalize(s.ordinary,0xcc);}
 for(auto offset:arena_pointer_offsets_)normalize(s.arena,offset);
 if(tuple223_sequence()){
  // Only the high halves of the exact class0 links survive two-byte strings.
  // Verify their origin before canonicalizing; keep both low bytes untouched.
  const auto high=(metadata_+0x144)>>16;
  for(unsigned offset:{0xfd2u,0xfe2u}){
   need((unsigned(s.arena[offset])|(unsigned(s.arena[offset+1])<<8))==high,"223 stale link high-half identity");
   s.arena[offset]=0; s.arena[offset+1]=0xd2;
  }
 }

 return s;
}
bool Heap::tuple223_sequence()const{return requests_==tuple223::requests();}
void Heap::validate_tuple223_result(unsigned result)const{
 need(committed_&&metadata_&&result==arena_+0xff0,"223 final live string identity");
 need(r32(metadata_+0x144)==1&&r32(arena_+0xc)==0xfe0&&r32(arena_+0xfe8)==0xfe0&&r32(arena_+0xfec)==0x11&&r32(arena_+0xff8)==0x11,"223 sole live span and residual boundary tags");
 need(r32(table_)==0&&r32(table_+4)==1&&r32(table_+8)==0x7fffffff&&r32(metadata_+0x44)==0&&r32(metadata_+0xc4)==1&&r8(metadata_+4)==0&&r8(metadata_+5)==0,"223 exact final maps and lower classes");
 const auto head0=metadata_+0x144,head1=metadata_+0x14c,head63=metadata_+0x33c;
 need(r32(head0+4)==head0&&r32(head0+8)==head0&&r32(head1+4)==head1&&r32(head1+8)==head1&&r32(head63+4)==arena_+0xc&&r32(head63+8)==arena_+0x700c,"223 final free lists");
 need(r32(arena_+0xfd4)==head0&&r32(arena_+0xfe4)==head0,"223 two retained full-pointer identities");
 for(unsigned page=0;page<8;++page){const auto base=arena_+page*0x1000,node=base+0xc;
  need(r32(base+8)==0xffffffff&&r32(base+0xffc)==0xffffffff&&r32(node+4)==(page==7?head63:node+0x1000)&&r32(node+8)==(page==0?head63:node-0x1000),"223 original physical pages and ring");
  if(page)need(r32(node)==0xff0&&r32(base+0xff8)==0xff0,"223 unallocated page extents");
 }
 need(events_.size()==57,"223 27 real lock pairs and3 real backing operations");const unsigned first[]{1,2,3,4,5};
 for(unsigned k=0;k<5;++k)need(events_[k][0]==first[k],"223 original backing API order");
 for(unsigned k=5;k<57;++k)need(events_[k][0]==((k&1)?1u:5u),"223 remaining lock pair order");
}
void Heap::validate_empty173_result()const{
 need(metadata_&&committed_&&memory_.r32(0xb10e10)==table_&&memory_.r32(0xb10e08)==0,"173 empty-chunk tracker");
 need(r32(metadata_+0x144)==0&&r32(table_)==0&&r32(table_+4)==1&&r32(table_+8)==0x7fffffffu,"173 no live blocks and unchanged availability maps");
 need(r8(metadata_+0x43)==1&&r32(metadata_+0x44)==0&&r32(metadata_+0xc4)==1,"173 chunk class summaries");
 const auto head=metadata_+0x33c;
 need(r32(head+4)==arena_+0xc&&r32(head+8)==arena_+0x700c,"173 class63 endpoints");
 for(unsigned page=0;page<8;++page){
  const auto base=arena_+page*0x1000,node=base+0xc;
  need(r32(base+8)==0xffffffffu&&r32(node)==0xff0&&r32(base+0xff8)==0xff0&&r32(base+0xffc)==0xffffffffu,"173 every physical page is a full free span");
  need(r32(node+4)==(page==7?head:node+0x1000)&&r32(node+8)==(page==0?head:node-0x1000),"173 retained eight-extent class63 ring");
 }
 const unsigned kinds[]{1,2,3,4,5,1,5};need(events_.size()==7,"173 actual allocation and release API count");
 for(unsigned n=0;n<7;++n)need(events_[n][0]==kinds[n],"173 actual allocation and release API order");
}
bool Heap::string169_sequence()const{return requests_==std::vector<unsigned>{3,11,11,13,13,13};}
void Heap::validate_string169_result(unsigned result)const{
 need(committed_&&metadata_&&result==arena_+0xfd0,"169 final published address");
 // Derive physical liveness on both sides. The unchanged original does not
 // call the portable allocation/release methods or their sequence counters.
 unsigned cursor=arena_+0xc,live=0,found=0;
 while(cursor<arena_+0xffc){
  const auto tag=r32(cursor),span=tag&~1u;
  need(tag!=0xffffffffu&&span>=0x10&&(span&15)==0&&span<=arena_+0xffc-cursor,"169 physical span");
  need(r32(cursor+span-4)==tag,"169 matching boundary tags");
  if(tag&1){++live;found=cursor+4;}cursor+=span;
 }
 need(cursor==arena_+0xffc&&r32(cursor)==0xffffffffu&&live==1&&found==result&&r32(metadata_+0x144)==1,"169 sole physical live block");
 need(r32(result-4)==0x21&&r32(result+0x18)==0x21&&r32(arena_+0xc)==0xfc0&&r32(arena_+0xfec)==0x10,"169 final residual/live/free spans");
 for(unsigned page=1;page<8;++page){
  const auto base=arena_+page*0x1000;
  need(r32(base+8)==0xffffffffu&&r32(base+0xc)==0xff0&&r32(base+0xff8)==0xff0&&r32(base+0xffc)==0xffffffffu,"169 other page extents");
 }
 need(events_.size()==25,"169 eleven lock pairs and three real backing operations");
 const unsigned initial[]{1,2,3,4,5};
 for(unsigned k=0;k<5;++k)need(events_[k][0]==initial[k],"169 initial real API order");
 for(unsigned k=5;k<25;++k)need(events_[k][0]==((k&1)?1u:5u),"169 actual lock pair order");
}
void Heap::activate(){need(!active_,"another smallheap observer active");active_=this;}
void Heap::deactivate(){need(active_==this,"wrong smallheap observer");active_=nullptr;}
void* WINAPI Heap::allocate_iat(HANDLE h,DWORD f,SIZE_T n){need(active_!=nullptr,"missing original smallheap observer");return reinterpret_cast<void*>(active_->heap_alloc(addr(h),f,unsigned(n)));}
void* WINAPI Heap::virtual_iat(void*p,SIZE_T n,DWORD t,DWORD f){need(active_!=nullptr,"missing original smallheap observer");return reinterpret_cast<void*>(active_->virtual_alloc(addr(p),unsigned(n),t,f));}
void WINAPI Heap::enter_iat(CRITICAL_SECTION*p){need(active_&&p==active_->lock_,"wrong original lock enter");active_->enter();}
void WINAPI Heap::leave_iat(CRITICAL_SECTION*p){need(active_&&p==active_->lock_,"wrong original lock leave");active_->leave();}
void Heap::bind_original(){
 *reinterpret_cast<unsigned*>(0x785270)=addr(reinterpret_cast<void*>(&allocate_iat));
 *reinterpret_cast<unsigned*>(0x785290)=addr(reinterpret_cast<void*>(&virtual_iat));
 *reinterpret_cast<unsigned*>(0x7851dc)=addr(reinterpret_cast<void*>(&enter_iat));
 *reinterpret_cast<unsigned*>(0x7851e0)=addr(reinterpret_cast<void*>(&leave_iat));
}
void compare(const State&a,const State&b){
 need(a.return_offset==b.return_offset,"smallheap result offset mismatch");need(a.events==b.events,"smallheap real API events mismatch");
 const auto check=[](const auto&x,const auto&y,const char*name){need(x.size()==y.size(),"smallheap extent mismatch");for(unsigned k=0;k<x.size();++k)if(x[k]!=y[k]){std::ostringstream e;e<<name<<" mismatch offset0x"<<std::hex<<k<<" cpp="<<unsigned(x[k])<<" original="<<unsigned(y[k]);throw std::runtime_error(e.str());}};
 check(a.table,b.table,"region table");check(a.metadata,b.metadata,"region metadata");check(a.arena,b.arena,"committed arena");
 check(a.ordinary,b.ordinary,"ordinary backing payload");
}
}
