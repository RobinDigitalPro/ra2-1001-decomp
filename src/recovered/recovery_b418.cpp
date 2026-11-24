#include "recovery_b418.hpp"
#include "recovered/allocation_wrappers.hpp"
#include "recovered/recovery42_cleanup.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b418 {
namespace {
std::uint32_t release(std::uint32_t p,void*context){return static_cast<Heap*>(context)->release(p);}
constexpr std::array<std::uint32_t,3> callback_owned{0xaa8c14u,0xaa8c1cu,0xaa8c24u};
constexpr std::array<std::uint32_t,8> slots{0xaa8c44u,0xaa8c48u,0xaa8c4cu,0xaa8c50u,0xaa8c54u,0xaa8c58u,0xaa8c5cu,0xaa8c60u};
constexpr std::array<std::uint32_t,10> flags{0xaa8cbcu,0xaa8cbdu,0xaa8cbeu,0xaa8cbfu,0xaa8cc0u,0xaa8cc1u,0xaa8cc2u,0xaa8cc3u,0xaa8cc4u,0xaa8cc5u};
}
std::uint32_t fun_006e92c0(Memory&m,const Inputs&,Heap&heap){
 for(auto a:{0xaa8c18u,0xaa8c20u,0xaa8c28u})if(m.r32(a))throw std::domain_error("B418 excludes virtual resource cleanup");
 const ra2::recovered::AllocationWrapperOperations ops{nullptr,release,&heap};std::uint32_t eax=0;
 for(auto a:callback_owned){const auto p=m.r32(a);if(!p)throw std::domain_error("B418 requires three owned buffers");eax=ra2::recovered::fun_0076d67b(p,ops);m.w32(a,0);}
 return eax;
}
std::uint32_t fun_006e80e0(Memory&m,const Inputs&in,Heap&heap){
 if(m.r8(0xaa8c2cu)==0u)throw std::domain_error("B418 requires nonzero root cleanup guard");
 for(auto a:flags)if(m.r8(a)!=1u)throw std::domain_error("B418 requires ten set auxiliary ownership flags");
 for(auto a:{0xaa8c18u,0xaa8c20u,0xaa8c28u})if(m.r32(a)!=0u)throw std::domain_error("B418 excludes indirect callback/object branches");
 if(m.r32(0x81f830u)!=0u)throw std::domain_error("B418 requires original helper zero guard");
 m.w8(0xaa8c2cu,0u);
 // Reuse the accepted positive 10-flag cleanup contract at 0x2e9150.
 ra2::recovered::recovery42_cleanup::State state{};state.ax=in.ax;state.cx=in.cx;state.dx=in.dx;state.arg=in.arg;
 ra2::recovered::recovery42_cleanup::fun_006e9150(m,state,heap);
 const ra2::recovered::AllocationWrapperOperations ops{nullptr,release,&heap};
 std::uint32_t eax=fun_006e92c0(m,in,heap);
 for(unsigned k=0;k<slots.size();++k){const auto p=m.r32(slots[k]);if(!p)throw std::domain_error("B418 requires eight distinct nonnull root-owned blocks");eax=ra2::recovered::fun_0076d67b(p,ops);if(k+1<slots.size())m.w32(slots[k],0u);}
 m.w32(slots.back(),0u);
 // Original 0x1197e0 sees [0x81f830]==0 and returns EAX=1.
 return 1u;
}
}
