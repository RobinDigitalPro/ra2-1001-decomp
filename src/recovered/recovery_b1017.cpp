#include "recovered/recovery_b1017.hpp"
#include <stdexcept>
namespace ra2::recovered::b1017 {
namespace {
void need(bool ok,const char*s){if(!ok)throw std::domain_error(s);}
HANDLE handle(unsigned v){return reinterpret_cast<HANDLE>(std::uintptr_t(v));}
void close_file(Memory&m,unsigned f,Api&a){
 // Original 468E10 clears the memory-reader fields before the raw close.
 m.w32(f+0x54u,0u);m.w32(f+0x58u,0u);m.w8(f+0x5cu,0u);m.w32(f+0x60u,0u);
 if(m.r32(f+0x10u)!=0xffffffffu){need(a.close(handle(m.r32(f+0x10u)))!=FALSE,"1017 genuine CloseHandle");m.w32(f+0x10u,0xffffffffu);}
}
unsigned open_file(Memory&m,unsigned f,Api&a,Observation&o){
 need(m.r32(f)==0x7856a0u&&m.r8(f+0x25u)==0u&&m.r32(f+8u)==0u&&m.r32(f+0xcu)==0xffffffffu,"1017 original direct-file record bounds");
 need(m.r32(f+0x54u)==0u&&m.r32(f+0x58u)==0u&&m.r32(0x838be0u)==0u,"1017 unbuffered direct-file environment");
 close_file(m,f,a);
 const char*name=reinterpret_cast<const char*>(std::uintptr_t(m.r32(f+0x14u)));
 // The original availability check opens and closes the actual physical file.
 const HANDLE probe=a.create(name,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
 need(probe!=INVALID_HANDLE_VALUE,"1017 positive physical availability");m.w32(f+0x10u,unsigned(reinterpret_cast<std::uintptr_t>(probe)));
 need(a.close(probe)!=FALSE,"1017 actual availability handle close");m.w32(f+0x10u,0xffffffffu);
 // 46FA10 -> 42F640 -> 6301A0; intermediate closes are now empty.
 close_file(m,f,a);m.w32(f+4u,1u);
 const HANDLE h=a.create(name,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);
 need(h!=INVALID_HANDLE_VALUE,"1017 positive physical open");o.opened=unsigned(reinterpret_cast<std::uintptr_t>(h));m.w32(f+0x10u,o.opened);
 return 1u;
}
}
unsigned run(Memory&m,const Inputs&i,Api&a,unsigned root,Observation&o){
 need(root==0x68e40u||root==0x3109a0u,"1017 exact roots");
 const unsigned f=root==0x68e40u?i.cx:i.arg[0];
 if(root==0x68e40u){need(i.arg[0]==1u,"1017 read mode only");return open_file(m,f,a,o);}
 open_file(m,f,a,o);DWORD got=0;
 need(a.read(handle(o.opened),o.header.data(),16u,&got,nullptr)!=FALSE&&got==16u,"1017 full actual header");
 for(unsigned j=0;j<16u;++j)m.w8(i.cx+j,o.header[j]);
 const unsigned rows=m.r32(i.cx+8u);need(rows>=1u&&rows<=8u,"1017 positive table rows 1..8");
 need(a.read(handle(o.opened),reinterpret_cast<void*>(std::uintptr_t(m.r32(i.cx+0x10u))),768u,&got,nullptr)!=FALSE&&got==768u,"1017 complete palette read");
 m.w8(0xa9e184u,0u);
 need(a.read(handle(o.opened),reinterpret_cast<void*>(std::uintptr_t(m.r32(i.cx+0x14u))),rows*256u,&got,nullptr)!=FALSE&&got==rows*256u,"1017 complete row data read");
 m.w8(0xa9e184u,0u);close_file(m,f,a);return 0u;
}
}
