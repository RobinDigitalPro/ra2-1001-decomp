#include "recovered/recovery_b1022.hpp"
#include <stdexcept>
namespace ra2::recovered::b1022 {
namespace {void need(bool ok,const char*s){if(!ok)throw std::domain_error(s);}}
unsigned run(Memory&m,const Inputs&i,Api&a,unsigned root,Observation&o){
 need(root==0x68f70u||root==0x69020u,"1022 exact roots");
 const HANDLE h=reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(i.cx+0x10u)));
 need(h!=INVALID_HANDLE_VALUE,"1022 prepared live direct file handle");
 need(a.info(h,&o.info)!=FALSE,"1022 actual file information success");
 if(root==0x68f70u){
  // 630840 ignores converter BOOL and packs the two local WORDs. The bounded
  // route requires real conversion success and a nonzero packed result.
  need(a.to_dos(&o.info.ftLastWriteTime,&o.date,&o.time)!=FALSE,"1022 actual timestamp to DOS success");
  const unsigned result=(unsigned(o.date)<<16u)|unsigned(o.time);
  need(result!=0u,"1022 positive direct result avoids archive fallback");return result;
 }
 const unsigned packed=i.arg[0];
 need(a.from_dos(WORD(packed>>16u),WORD(packed),&o.converted)!=FALSE,"1022 genuine DOS timestamp conversion");
 // These are the exact 630890 pointer aliases. Both access and write are
 // updated; only creation is taken from the old file information structure.
 need(a.set(h,&o.info.ftCreationTime,&o.converted,&o.converted)!=FALSE,"1022 actual SetFileTime success");
 return 1u;
}
}
