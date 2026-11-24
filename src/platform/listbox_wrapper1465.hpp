#pragma once
#include "platform/custom_listbox1462.hpp"
namespace ra2::recovered::b1465::ui {
namespace base=b1462::ui;using base::U;using base::ptr;using base::addr;using base::need;using base::getdc;using base::send;using base::releasedc;
struct Query{U parent,id,result;bool operator==(const Query&o)const{return parent==o.parent&&id==o.id&&result==o.result;}};
inline std::vector<Query>queries;
inline HWND WINAPI getitem(HWND h,int id){auto&c=base::context();need(h==c.parent()&&id==0x53f,"1465 exact direct child query");auto result=::GetDlgItem(h,id);need(result==c.listbox(),"1465 genuine nonnull child; fallback excluded");queries.push_back({ptr(h),U(id),ptr(result)});return result;}
// The callback implementation, actual oldOS procedure and hash provider are
// unchanged B1462. Only this finite fixture's genuine child ID differs.
class Windows:public base::Windows{
public:
 Windows(){if(0x53f!=0x53f){SetLastError(0);const auto old=SetWindowLongPtrA(listbox(),GWLP_ID,0x53f);need(old==0x53f&&GetLastError()==0,"1465 genuine fixture child-ID publication");}verify_structure();}
 void verify_structure()const{char name[32]{};need(IsWindow(parent())&&IsWindow(listbox())&&!IsWindowVisible(parent())&&!IsWindowVisible(listbox())&&GetParent(listbox())==parent()&&GetDlgItem(parent(),0x53f)==listbox(),"1465 exact real hidden child/parent");need(GetClassNameA(listbox(),name,32)&&lstrcmpiA(name,"LISTBOX")==0&&GetWindowLongPtrA(listbox(),GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(os()),"1465 genuine restored OS class/procedure");}
 void verify_empty()const{verify_structure();need(SendMessageA(listbox(),LB_GETCOUNT,0,0)==0&&SendMessageA(listbox(),LB_GETCURSEL,0,0)==LB_ERR,"1465 actual empty rows");}
 void verify_populated(U,const std::array<U,1>&owners)const{verify_structure();need(SendMessageA(listbox(),LB_GETCOUNT,0,0)==1&&SendMessageA(listbox(),LB_GETCURSEL,0,0)==LB_ERR,"1465 actual one unselected row");char text[32]{};need(SendMessageA(listbox(),LB_GETTEXT,0,reinterpret_cast<LPARAM>(text))==5&&std::string(text)=="XYXYX","1465 actual formatted UTF16 result reaches OS row");need(U(SendMessageA(listbox(),LB_GETITEMDATA,0,0))==owners[0]&&SendMessageA(listbox(),LB_GETTOPINDEX,0,0)==0,"1465 actual raw owner/topindex");}
 void clear_fixture(){need(!base::active,"1465 fixture cleanup after proof");SendMessageA(listbox(),LB_RESETCONTENT,0,0);ValidateRect(listbox(),nullptr);verify_empty();}
 void begin(Memory&m,base::Adapter&h,bool original){queries.clear();base::Windows::begin(m,h,original);}
};
inline void verify_query(const Windows&w){need(queries==std::vector<Query>{{ptr(w.parent()),0x53f,ptr(w.listbox())}},"1465 exact real GetDlgItem count/input/result");}
}
