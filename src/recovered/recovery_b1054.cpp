#include "recovered/recovery_b1054.hpp"
#include <stdexcept>
namespace ra2::recovered::b1054 {
static void need(bool ok){if(!ok)throw std::domain_error("1054 outside positive footprint contract");}
std::uint32_t fun_00450db0(Memory&m,const Inputs&i){
 const auto r=i.cx,type=m.r32(r+0x418u),house=m.r32(r+0x1b4u),kind=m.r32(type+0xc78u);
 const int radius=global_b26::s32(m.r32(m.r32(0x821b88u)+0x10c8u));
 need(kind==0u&&radius>0&&radius<=4&&(i.arg[0]&255u)!=0u);
 const int width=int(m.r32(0x7bac08u+kind*4u))+2*radius,height=int(m.r32(0x7bac60u+kind*4u))+2*radius;
 const int x=int(std::int16_t(global_b26::s32(m.r32(r+0x88u))/256-radius)),y=int(std::int16_t(global_b26::s32(m.r32(r+0x8cu))/256-radius));
 need(width>0&&height>0&&x>=0&&y>=0&&x+width<512&&y+height<512);
 const auto bit=1u<<(m.r32(house+0x30u)&31u),table=m.r32(0x81a958u);
 for(int col=x;col<x+width;++col)for(int row=y;row<y+height;++row){const auto cell=m.r32(table+4u*unsigned(row*512+col));need(cell!=0u);m.w32(cell+0xdcu,m.r32(cell+0xdcu)|bit);}
 const auto bounds=house+0x5644u;
 if(m.r32(bounds)==0u)m.w32(bounds,unsigned(x));if(m.r32(bounds+4u)==0u)m.w32(bounds+4u,unsigned(y));
 int left=global_b26::s32(m.r32(bounds)),top=global_b26::s32(m.r32(bounds+4u));
 int w=global_b26::s32(m.r32(bounds+8u)),h=global_b26::s32(m.r32(bounds+12u));
 if(x<left){w+=left-x;left=x;m.w32(bounds,unsigned(left));m.w32(bounds+8u,unsigned(w));}
 if(x+width>left+w){w=x-left+width;m.w32(bounds+8u,unsigned(w));}
 if(y<top){h+=top-y;top=y;m.w32(bounds+4u,unsigned(top));m.w32(bounds+12u,unsigned(h));}
 if(y+height>top+h)m.w32(bounds+12u,unsigned(y-top+height));
 return(bounds&0xffffff00u)|(i.arg[0]&255u);
}
}
