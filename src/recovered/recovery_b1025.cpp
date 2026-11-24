#include "recovered/recovery_b1025.hpp"
#include <stdexcept>
#include <string>
namespace ra2::recovered::b1025 {
namespace {
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
void init(Memory&m,unsigned p){m.w32(p,0x7856a0u);m.w32(p+4u,1u);m.w32(p+8u,0u);m.w32(p+0xcu,0xffffffffu);m.w32(p+0x10u,0xffffffffu);m.w32(p+0x14u,0u);for(unsigned k=0x18u;k<=0x1cu;++k)m.w8(p+k,0u);for(unsigned k=0x20u;k<=0x25u;++k)m.w8(p+k,0u);for(unsigned k=0x28u;k<=0x4cu;k+=4u)m.w32(p+k,k==0x3cu||k==0x40u?0xffffffffu:0u);m.w8(p+0x50u,0u);m.w32(p+0x54u,0u);m.w32(p+0x58u,0u);m.w8(p+0x5cu,0u);m.w32(p+0x60u,0u);}
void put(Observation&o,unsigned at,unsigned x){for(unsigned k=0;k<4u;++k)o.file[at+k]=static_cast<unsigned char>(x>>(8u*k));}
void upper(Memory&m,unsigned p){for(unsigned k=0;k<9u;++k){const auto x=m.r8(p+k);if(x>='a'&&x<='z')m.w8(p+k,x-32u);}}
void upper(Heap&h,unsigned p){for(unsigned k=0;k<9u;++k){const auto x=h.r8(p+k);if(x>='a'&&x<='z')h.w8(p+k,x-32u);}}
HANDLE handle(unsigned v){return reinterpret_cast<HANDLE>(std::uintptr_t(v));}
}
void prepare(Memory&m,Inputs&i,unsigned base,unsigned root,unsigned length,unsigned offset){const std::string name="whole.bin";for(unsigned k=0;k<=name.size();++k)m.w8(base+0x600u+k,k<name.size()?static_cast<unsigned char>(name[k]):0u);i.cx=base+0x400u;
 if(root==0x6fd50u){init(m,i.cx);i.arg[0]=base+0x600u;}
 else if(root==0x950f0u){i.cx=base+0x500u;m.w32(i.cx,base+0x600u);i.dx=base+0x700u;}
 else {need(root==0x192610u,"1025 exact prepare root");m.w32(i.cx+0xcu,base+0x600u);m.w8(i.cx+0x10u,0u);m.w8(i.cx+0x12u,0u);m.w32(i.cx+0x18u,length);m.w32(i.cx+0x1cu,offset);m.w32(i.cx+0x24u,0u);m.w32(base+0x500u,base+0x2000u);m.w32(base+0x504u,length+16u);i.arg[0]=base+0x500u;}
}
unsigned run(Memory&m,const Inputs&i,Heap&h,Api&a,unsigned root,Observation&o){need(root==0x6fd50u||root==0x950f0u||root==0x192610u,"1025 exact roots");need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u&&m.r32(0xa588e0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0x838be0u)==0u,"1025 ordinary heap C locale empty archives/direct physical file");const unsigned source=root==0x6fd50u?i.arg[0]:root==0x950f0u?m.r32(i.cx):m.r32(i.cx+0xcu);
 if(root==0x950f0u){m.w8(i.dx,0u);upper(m,source);} //1924C0 uppercases holder chars before cloning.
 if(root==0x192610u){need(m.r32(i.cx+0x24u)==0u&&m.r8(i.cx+0x10u)==0u&&i.arg[0]!=0u&&m.r32(i.arg[0]+4u)>=m.r32(i.cx+0x18u),"1025 cold valid caller buffer before original filename construction");m.w32(i.cx+0x24u,m.r32(i.arg[0]));}
 const unsigned name=h.allocate(10u);o.name=name;for(unsigned k=0;k<10u;++k)h.w8(name+k,m.r8(source+k));
 if(root==0x6fd50u){need(m.r32(i.cx)==0x7856a0u&&m.r32(i.cx+0x14u)==0u&&m.r32(i.cx+0x10u)==0xffffffffu,"1025 authentic empty file constructor route");m.w32(i.cx+8u,0u);m.w32(i.cx+0xcu,0xffffffffu);m.w32(i.cx+0x14u,name);m.w8(i.cx+0x1cu,1u);return name;}
 const auto path=reinterpret_cast<const char*>(std::uintptr_t(name));put(o,0,0x7856a0u);put(o,4,1u);put(o,0xc,0xffffffffu);put(o,0x10,0xffffffffu);put(o,0x14,name);o.file[0x1c]=1u;put(o,0x3c,0xffffffffu);put(o,0x40,0xffffffffu);
 const auto probe=[&](){const HANDLE p=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(p!=INVALID_HANDLE_VALUE,"1025 positive physical probe");put(o,0x10,unsigned(reinterpret_cast<std::uintptr_t>(p)));need(a.close_handle(p)!=FALSE,"1025 probe caller-owned close");put(o,0x10,0xffffffffu);};
 const auto open=[&](bool cached_size=false){probe();const HANDLE p=a.create_file_a(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(p!=INVALID_HANDLE_VALUE,"1025 actual sequential read open");put(o,0x10,unsigned(reinterpret_cast<std::uintptr_t>(p)));if(cached_size)need(a.seek(p,0,nullptr,FILE_BEGIN)==0u,"1025 original cached-size read-open initial absolute seek");return p;};
 const auto close=[&](HANDLE p){need(a.close_handle(p)!=FALSE,"1025 actual physical file close");put(o,0x10,0xffffffffu);};
 if(root==0x950f0u){probe();probe();HANDLE file=open();const unsigned bytes=a.size(file,nullptr);need(bytes>=51u&&bytes<=304u,"1025 positive bounded whole file size");put(o,0xc,bytes);close(file);o.payload=h.allocate(bytes);file=open(true);need(a.seek(file,0,nullptr,FILE_CURRENT)==0u,"1025 original read queries current physical cursor");o.bytes_read=0;need(a.read_file(file,reinterpret_cast<void*>(std::uintptr_t(o.payload)),bytes,&o.bytes_read,nullptr)!=FALSE&&o.bytes_read==bytes,"1025 whole nonempty actual file read");m.w8(0xa9e184u,0u);close(file);m.w8(i.dx,1u);}
 else {need(m.r32(i.cx+0x24u)==m.r32(i.arg[0])&&m.r8(i.cx+0x10u)==0u,"1025 published external-buffer unhashed positive archive-record read");const unsigned length=m.r32(i.cx+0x18u),offset=m.r32(i.cx+0x1cu);need(length>=33u&&length<=256u&&offset>=1u&&offset<=31u&&m.r32(i.arg[0]+4u)>=length,"1025 finite positive bounded caller storage");o.payload=m.r32(i.arg[0]);const HANDLE file=open();const unsigned bytes=a.size(file,nullptr);need(bytes>=offset+length,"1025 actual file covers declared subrange");put(o,8,offset);put(o,0xc,bytes);need(a.seek(file,LONG(offset),nullptr,FILE_BEGIN)==offset&&a.seek(file,0,nullptr,FILE_CURRENT)==offset,"1025 exact original positive bias/current seeks");o.bytes_read=0;need(a.read_file(file,reinterpret_cast<void*>(std::uintptr_t(o.payload)),length,&o.bytes_read,nullptr)!=FALSE&&o.bytes_read==length,"1025 actual nonempty subrange read into caller storage");m.w8(0xa9e184u,0u);close(file);}
 o.final_free=h.release(name);need(o.final_free!=0u,"1025 actual local CCFile filename owner free");return root==0x950f0u?o.payload:(o.final_free&0xffffff00u)|1u;
}
void cleanup(Memory&m,const Inputs&i,Heap&h,unsigned root,Observation&o){if(root==0x950f0u)need(h.release(o.payload)!=0u,"1025 caller releases retained file payload");else if(root==0x6fd50u){need(h.release(o.name)!=0u,"1025 raw destructor frees owned filename");m.w32(i.cx,0x793c3cu);m.w32(i.cx+0x14u,0u);m.w8(i.cx+0x1cu,0u);m.w32(i.cx+0x2cu,0u);m.w32(i.cx+0x30u,0u);for(unsigned k:{0x21u,0x23u,0x24u,0x25u})m.w8(i.cx+k,0u);}}
}
