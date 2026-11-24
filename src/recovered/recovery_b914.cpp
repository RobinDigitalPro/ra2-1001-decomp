#include "recovered/recovery_b914.hpp"
#include "recovered/recovery_b253.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/crt_classify.hpp"
#include "platform/current_crt_thread.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>
namespace ra2::recovered::recovery_b914 { namespace {
using U=std::uint32_t;
struct Classifier { const CrtClassification* table; };
std::int32_t classify(std::uint8_t c,U mask,void* p){
 const auto& t=*static_cast<Classifier*>(p)->table;
 if(mask==8u)return static_cast<std::int32_t>(fun_0076e521(c,t));
 if(mask==4u)return static_cast<std::int32_t>(fun_0076e4cc(c,t));
 throw std::domain_error("914 decimal parser requested unobserved CRT mask");
}
std::vector<std::uint8_t> read_z(Memory&m,U p){if(!p)throw std::domain_error("914 null token");std::vector<std::uint8_t> out;for(U k=0;k<64;++k){U c=m.r8(p+k);out.push_back(static_cast<std::uint8_t>(c));if(!c)return out;}throw std::domain_error("914 token exceeds bound");}
U parse(Memory&m,U p,const DecimalOperations&ops){auto s=read_z(m,p);const U v=fun_0076e73d(s.data(),ops);const auto signed_v=global_b26::s32(v);if(signed_v < -999 || signed_v > 999)throw std::domain_error("914 numeric fixture outside [-999,999]");return v;}
U next(Memory&m){Inputs call{};call.arg[0]=0;call.arg[1]=0x7b9950u;return recovery_b253::fun_0076e802(m,call);}
}
U fun_006a2eb0(Memory&m,const Inputs&i){
 const U receiver=i.cx;if(!receiver)throw std::domain_error("914 finite route requires receiver in ECX");
 if(m.r32(0x81776cu)!=1u||m.r32(0x817560u)!=0x81756au)throw std::domain_error("914 requires original single-byte CRT table");
 std::array<std::uint16_t,257> flags{};const U tab=m.r32(0x817560u)-2u;for(U k=0;k<flags.size();++k)flags[k]=static_cast<std::uint16_t>(m.r16(tab+2u*k));
 const CrtClassification ctype{1,flags.data(),nullptr,nullptr};Classifier cx{&ctype};const DecimalOperations decimal{classify,&cx};
 constexpr U targets[10]={0x6a2f0fu,0x6a2f17u,0x6a2f54u,0x6a2f91u,0x6a2fc8u,0x6a2f17u,0x6a30a5u,0x6a30b4u,0x6a30c3u,0x6a2f0fu};
 m.w32(receiver+0x74u,0u);
 U token=next(m);if(!token)throw std::domain_error("914 requires eight nonempty CSV tokens");m.w32(receiver+0x2cu,parse(m,token,decimal));
 token=next(m);if(!token)throw std::domain_error("914 missing selector");const U selector=parse(m,token,decimal);if(selector>9u||targets[selector]!=(selector==5u?0x6a2f17u:selector==9u?0x6a2f0fu:0u))throw std::domain_error("914 selector outside reviewed jump-table entries 5/9");
 token=next(m);if(!token)throw std::domain_error("914 missing selector payload");const U third=parse(m,token,decimal);
 if(selector==5u){if(third!=0xffffffffu)throw std::domain_error("914 selector5 route requires observed -1 clear arm");m.w32(receiver+0x30u,0u);}else m.w32(receiver+0x74u,third);
 constexpr U fields[4]={0x34u,0x38u,0x3cu,0x40u};
 for(U k=0;k<4;++k){token=next(m);if(!token)throw std::domain_error("914 missing common numeric field");m.w32(receiver+fields[k],parse(m,token,decimal));}
 token=next(m);if(!token)throw std::domain_error("914 missing final numeric field");const U result=parse(m,token,decimal);
 if(selector==5u)m.w32(receiver+0x74u,result);else m.w32(receiver+0x48u,result);
 return result;
}
}
