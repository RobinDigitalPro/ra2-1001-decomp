#include "recovered/lookup_b92.hpp"
#include "recovered/crt_b83.hpp"
namespace ra2::recovered::lookup_b92 {
namespace {
using global_b26::s32;
std::uint32_t compare(Memory& m,std::uint32_t a,std::uint32_t b){Inputs q{};q.arg[0]=a;q.arg[1]=b;return crt_b83::fun_0076d860(m,q);}
std::uint32_t scan(Memory& m,std::uint32_t key,std::uint32_t count_at,std::uint32_t table_at,unsigned sentinels,unsigned offset,bool pointer_result,std::uint32_t type=0,std::uint32_t type_offset=0){
 if(sentinels>=1&&compare(m,key,0x007b8e5cu)==0)return 0;
 if(sentinels>=2&&compare(m,key,0x007b907cu)==0)return 0;
 const auto count=m.r32(count_at);if(s32(count)<=0)return 0;
 const auto table=m.r32(table_at);
 for(std::uint32_t n=0;n<count;++n){const auto rec=m.r32(table+n*4u);auto name=rec+offset;if(offset==0x304u)name=m.r32(name);if(compare(m,key,name)!=0)continue;if(type_offset&&m.r32(rec+type_offset)!=type)continue;return pointer_result?rec:n;}
 return 0;
}
}
std::uint32_t fun_004264a0(Memory& m,const Inputs& i){return scan(m,i.cx,0x0084e520u,0x0084e514u,2,0x24u,true);}
std::uint32_t fun_0045dd50(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a1e018u,0x00a1e00cu,2,0x24u,true);}
std::uint32_t fun_00464980(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a1e030u,0x00a1e024u,1,0x24u,false);}
std::uint32_t fun_004f9850(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a1e048u,0x00a1e03cu,2,0x24u,true);}
std::uint32_t fun_0050a320(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a27fb0u,0x00a27fa4u,2,0x24u,true);}
std::uint32_t fun_00618720(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a1e110u,0x00a1e104u,1,0x24u,false);}
std::uint32_t fun_00618980(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a1e110u,0x00a1e104u,2,0x24u,true);}
std::uint32_t fun_006198e0(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a1e140u,0x00a1e134u,2,0x24u,true);}
std::uint32_t fun_0065ac50(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a9ea10u,0x00a9ea04u,0,0x304u,false,i.arg[2],0x310u);}
std::uint32_t fun_0065ff20(Memory& m,const Inputs& i){return scan(m,i.cx,0x0084e598u,0x0084e58cu,2,0x24u,true);}
std::uint32_t fun_00694e70(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a27f98u,0x00a27f8cu,2,0x24u,true);}
std::uint32_t fun_006aa370(Memory& m,const Inputs& i){return scan(m,i.cx,0x00aa79b8u,0x00aa79acu,2,0x24u,true);}
std::uint32_t fun_006b5160(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a28898u,0x00a2888cu,2,0x24u,true);}
std::uint32_t fun_006dace0(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a27f80u,0x00a27f74u,2,0x24u,true);}
std::uint32_t fun_00700100(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a1e088u,0x00a1e07cu,2,0x24u,true);}
std::uint32_t fun_00703940(Memory& m,const Inputs& i){return scan(m,i.cx,0x00a28730u,0x00a28724u,2,0x24u,true);}
std::uint32_t fun_00728a60(Memory& m,const Inputs& i){return scan(m,i.cx,0x00821ee0u,0x00821ed4u,2,0x24u,true);}
} // namespace ra2::recovered::lookup_b92
