#include "recovered/recovery_b1062.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1062 {namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void put(Observation&o,unsigned at,unsigned x){for(unsigned k=0;k<4u;++k)o.file.at(at+k)=static_cast<unsigned char>(x>>(8u*k));}
unsigned word(const unsigned char*p){return unsigned(p[0])|(unsigned(p[1])<<8u)|(unsigned(p[2])<<16u)|(unsigned(p[3])<<24u);}
}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&a,Observation&o){
 need(m.r32(0xa588e0u)==0u&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0xb10adcu)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1062 original C-locale physical file ordinaryheap");
 const unsigned labels=m.r32(0xab7eb8u),strings=m.r32(0xab7ebcu),records=m.r32(0xab7ec0u),wide=m.r32(0xab7ec4u),extra=m.r32(0xab7ec8u);need(labels>=2u&&labels<=5u&&strings>=labels&&strings<=15u&&m.r32(0xab7ea8u)==0u&&m.r32(0xab7eccu)==1u,"1062 actual original positive header/initialized global allocation state");
 for(unsigned k=0;k<labels*40u;++k)need(h.r8(records+k)==0u,"1062 genuine producer zero-initialized label storage");for(unsigned k=0;k<strings;++k)need(h.r32(wide+k*4u)==0u&&h.r32(extra+k*4u)==0u,"1062 genuine producer zero-initialized ownership slots");
 std::string path;for(unsigned k=0;k<64u;++k){const unsigned x=m.r8(i.cx+k);if(!x)break;need(x<128u,"1062 finite original ASCII path");path+=char(x);}need(path.size()>=1u&&path.size()<64u,"1062 nonempty terminated physical filename");o.filename=h.allocate(unsigned(path.size()+1u));need(o.filename!=0u,"1062 positive actual filename clone");for(unsigned k=0;k<=path.size();++k)h.w8(o.filename+k,k<path.size()?unsigned(path[k]):0u);for(unsigned k=0;k<path.size();++k){const unsigned x=h.r8(o.filename+k);if(x>='a'&&x<='z')h.w8(o.filename+k,x-32u);}
 put(o,0u,0x7856a0u);put(o,4u,1u);put(o,0xcu,0xffffffffu);put(o,0x10u,0xffffffffu);put(o,0x14u,o.filename);o.file[0x1cu]=1u;put(o,0x3cu,0xffffffffu);put(o,0x40u,0xffffffffu);
 const auto name=reinterpret_cast<const char*>(std::uintptr_t(o.filename));const auto probe=[&](){HANDLE p=a.create_file_a(name,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(p!=INVALID_HANDLE_VALUE,"1062 genuine positive physical availability");put(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(p)));need(a.close_handle(p)!=FALSE,"1062 genuine probe close");put(o,0x10u,0xffffffffu);};probe();probe();HANDLE file=a.create_file_a(name,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(file!=INVALID_HANDLE_VALUE,"1062 original positive Open1");put(o,0x10u,unsigned(reinterpret_cast<std::uintptr_t>(file)));
 const auto read=[&](void*dst,unsigned n,bool eof=false){o.bytes_read=0u;need(a.read_file(file,dst,n,&o.bytes_read,nullptr)!=FALSE&&o.bytes_read==(eof?0u:n),"1062 exact genuine complete chunk or final EOF read");++o.read_calls;m.w8(0xa9e184u,0u);};
 read(o.header.data(),24u);need(word(o.header.data())==0x43534620u&&word(o.header.data()+8u)==labels&&word(o.header.data()+12u)==strings&&word(o.header.data()+20u)==m.r32(0x7e25f0u),"1062 actual binary initializer header counts agree with owned capacities");read(&o.tag,4u);
 unsigned next=0u;
 for(unsigned row=0;row<labels;++row){need(o.tag==0x4c424c20u,"1062 actual positive label tag");read(&o.count,4u);read(&o.length,4u);need(o.count>=1u&&o.count<=3u&&o.length>=1u&&o.length<=31u&&next+o.count<=strings,"1062 positive bounded original label/name/count");read(reinterpret_cast<void*>(0xab6e90u),o.length);m.w8(0xab6e90u+o.length,0u);for(unsigned k=0;k<=o.length;++k)h.w8(records+row*40u+k,m.r8(0xab6e90u+k));if(o.length>m.r32(0xab7ea8u))m.w32(0xab7ea8u,o.length);h.w32(records+row*40u+0x20u,o.count);h.w32(records+row*40u+0x24u,next);++o.labels;
  const unsigned count=o.count;
  for(unsigned q=0;q<count;++q,++next){read(&o.tag,4u);need(o.tag==0x53545220u||o.tag==0x53545257u,"1062 positive original STR/STRW variant");const unsigned tag=o.tag;read(&o.length,4u);need(o.length>=1u&&o.length<=64u,"1062 nonempty bounded original encoded UTF16");read(reinterpret_cast<void*>(0xab0e7cu),o.length*2u);m.w16(0xab0e7cu+o.length*2u,0u);for(unsigned k=0;k<o.length;++k){const unsigned x=m.r16(0xab0e7cu+k*2u);need(x!=0u,"1062 original inversion terminator not embedded in payload");m.w16(0xab0e7cu+k*2u,(~x)&0xffffu);}
   // Exact original in-place normalization; the independent test oracle uses
   // a separate high-level append/remove algorithm over its input records.
   unsigned out=0u,previous=0u;bool line_start=true;
   for(unsigned k=0;k<o.length;++k){const unsigned x=m.r16(0xab0e7cu+k*2u);need(x!=0u,"1062 positive decoded UTF16 has no embedded terminator");if(x==0x20u){if(previous==0x20u||line_start)continue;}else if(x==0xau||x==9u){if(previous==0x20u)out-=2u;m.w16(0xab0e7cu+out,x);out+=2u;previous=x;line_start=true;continue;}m.w16(0xab0e7cu+out,x);out+=2u;previous=x;line_start=false;}
   if(previous==0x20u)out-=2u;m.w16(0xab0e7cu+out,0u);need(out>=2u,"1062 useful nonempty normalized string");const unsigned owner=h.allocate(out+2u);need(owner!=0u,"1062 actual positive normalized wide allocation");h.w32(wide+next*4u,owner);for(unsigned k=0;k<out+2u;++k)h.w8(owner+k,m.r8(0xab0e7cu+k));++o.strings;
   // In original6EE2F8, four cdecl arguments remain live: [ESP24]=P14 tag.
   if(tag==0x53545257u){read(&o.length,4u);need(o.length>=1u&&o.length<=31u,"1062 positive original STRW extra");read(reinterpret_cast<void*>(0xab6e90u),o.length);m.w8(0xab6e90u+o.length,0u);const unsigned owned=h.allocate(o.length+1u);need(owned!=0u,"1062 actual nonempty STRW extra allocation");h.w32(extra+next*4u,owned);for(unsigned k=0;k<=o.length;++k)h.w8(owned+k,m.r8(0xab6e90u+k));++o.extras;}
  }
  read(&o.tag,4u,row+1u==labels);
 }
 need(next==strings,"1062 actual complete populated header count");put(o,0u,0x793c84u);need(a.close_handle(file)!=FALSE,"1062 original live file destructor closes actual read handle");put(o,0x10u,0xffffffffu);o.final_free=h.release(o.filename);need(o.final_free!=0u,"1062 actual owned filename destructor");put(o,0u,0x793c3cu);put(o,0x14u,0u);o.file[0x1cu]=0u;return 1u;
}
void cleanup(Memory&m,Heap&h){need(m.r32(0xab7ed8u)==0u&&m.r32(0xab7ed4u)==0u,"1062 original cleanup excludes unrelated linked owners");const unsigned n=m.r32(0xab7ebcu);for(unsigned g:{0xab7ec4u,0xab7ec8u}){const unsigned a=m.r32(g);need(a!=0u,"1062 genuine complete ownership array");for(unsigned k=0;k<n;++k){const unsigned p=h.r32(a+k*4u);if(p)need(h.release(p)!=0u,"1062 original complete owned string release");}need(h.release(a)!=0u,"1062 original pointer-array release");m.w32(g,0u);}need(h.release(m.r32(0xab7ec0u))!=0u,"1062 original label-array release");m.w32(0xab7ec0u,0u);m.w32(0xab7ed8u,0u);m.w32(0xab7ed4u,0u);m.w32(0xab7eccu,0u);}
}
