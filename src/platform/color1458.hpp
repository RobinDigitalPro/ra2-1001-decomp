#pragma once
#include "platform/dialog1023.hpp"
#include "platform/x87_state.hpp"
#include <memory>
namespace ra2::recovered::b1458::color {
namespace ui=ra2::recovered::b1023::ui;using U=std::uint32_t;
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
inline U fs_head(){U x;asm volatile("movl %%fs:0,%0":"=r"(x));return x;}
inline U fs_selector(){unsigned short x;asm volatile("movw %%fs,%0":"=r"(x));return x;}
class Windows {
    std::unique_ptr<ui::Windows> base_;
    HWND text_=nullptr;LONG proc_=0,style_=0;RECT rect_{};
public:
    Windows():base_(new ui::Windows){
        // Keep the unchanged accepted BUTTON423 fixture present but unused.
        // Original resource274 has STATIC695/50020000; this finite hidden
        // projection omits WS_VISIBLE and does not execute resource startup.
        text_=CreateWindowExA(0,"STATIC","color-query",WS_CHILD|WS_GROUP|SS_LEFT,4,30,100,18,
            base_->dialog(),reinterpret_cast<HMENU>(std::uintptr_t(0x695)),GetModuleHandleW(nullptr),nullptr);
        ui::need(text_!=nullptr,"1458 genuine Static695");
        proc_=GetWindowLongA(text_,GWL_WNDPROC);style_=GetWindowLongA(text_,GWL_STYLE);
        ui::need(proc_&&GetWindowRect(text_,&rect_),"1458 actual static procedure/rectangle");
        verify();
    }
    ~Windows(){if(text_)DestroyWindow(text_);}
    Windows(const Windows&)=delete;
    ui::Windows& base()const{return *base_;}
    HWND text()const{return text_;}
    void verify()const{
        ui::need(base_&&text_&&IsWindow(text_)&&GetParent(text_)==base_->dialog()&&GetDlgItem(base_->dialog(),0x695)==text_&&GetDlgCtrlID(text_)==0x695,"1458 real live Static695 child identity");
        char cls[32]{},caption[32]{};RECT now{};
        ui::need(GetClassNameA(text_,cls,32)>0&&lstrcmpiA(cls,"STATIC")==0&&GetWindowTextA(text_,caption,32)==11&&std::strcmp(caption,"color-query")==0,"1458 genuine static class/caption");
        ui::need(!IsWindowVisible(text_)&&GetWindowLongA(text_,GWL_WNDPROC)==proc_&&GetWindowLongA(text_,GWL_STYLE)==style_&&GetWindowRect(text_,&now)&&std::memcmp(&now,&rect_,sizeof(now))==0,"1458 unchanged original OS procedure/style/geometry");
    }
    void reset(U context){base_->reset(context,0x1f77c0);verify();}
    void begin(){verify();base_->begin();}
    void finish(){base_->finish();verify();}
    void close(){
        ui::need(!ui::active,"1458 cleanup outside observation");
        const auto host=platform::x87::capture_host();const U fs=fs_head(),sel=fs_selector();
        ui::need(text_&&DestroyWindow(text_)!=FALSE,"1458 actual Static cleanup");text_=nullptr;base_.reset();
        const auto after=platform::x87::capture_host();
        ui::need(platform::x87::same_numeric(host,after)&&fs_head()==fs&&fs_selector()==sel,"1458 real fixture cleanup hostFP/FS");
    }
};
}
