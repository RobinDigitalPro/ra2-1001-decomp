#pragma once
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::audio377 {
struct Lock {void* first=nullptr;unsigned first_size=0;void* second=nullptr;unsigned second_size=0;};
struct Boundary {
 virtual ~Boundary()=default;
 virtual void enter()=0;virtual void leave()=0;
 virtual void position_zero(unsigned buffer)=0;
 virtual void cursors(unsigned buffer,unsigned&play,unsigned&write)=0;
 virtual Lock lock(unsigned buffer,unsigned bytes)=0;
 virtual void unlock(unsigned buffer,Lock)=0;
 virtual void volume(unsigned buffer,std::int32_t)=0;
 virtual void pan(unsigned buffer,std::int32_t)=0;
 virtual void frequency(unsigned buffer,unsigned)=0;
 virtual void play(unsigned buffer)=0;
};
inline Boundary*active=nullptr;
inline Boundary&host(){if(!active)throw std::logic_error("audio377 real platform boundary missing");return *active;}
}
