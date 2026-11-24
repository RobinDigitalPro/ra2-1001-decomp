#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <vector>
#include "platform/x87_state.hpp"
namespace ra2::platform::cleanup1464 {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
struct Event{U kind{},arg{},result{},eax_in{},esi_in{},fsbefore{},fsafter{};std::array<std::uint8_t,24>lockbefore{},lockafter{};fp::Image before{},after{};};
U pointer(const void*);U fshead();U fsselector();
class Provider {
 CRITICAL_SECTION*cs_{};bool installed_{};U prior_{},callback_{};std::vector<Event>events_;
public:
 explicit Provider(void*storage);~Provider();Provider(const Provider&)=delete;Provider&operator=(const Provider&)=delete;
 U setup();void begin();U enter(U);U restore(U);U leave(U);void finish();
 U lock()const;U prior()const{return prior_;}U callback()const{return callback_;}U thread()const;
 const std::vector<Event>&events()const{return events_;}void record(Event e){events_.push_back(e);}
 std::array<std::uint8_t,24>lock_bytes()const;void balanced()const;
 static U enter_thunk();static U filter_thunk();static U leave_thunk();
};
}
