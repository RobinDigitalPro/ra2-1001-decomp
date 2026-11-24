#include "recovery_b1249_parser.inc"
unsigned run(unsigned root,Memory&m,const Inputs&,const CallFrame&frame,Heap&h,FileApi&api,Observation&o){
 need(root==0x1187b0u&&frame.entry_esp>0x10000u&&(frame.entry_esp&3u)==0u,"1249 original root and explicit produced call-frame address");
 need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0x838be0u)==0u&&m.r32(0xa588e0u)==0u&&m.r8(0xa9e184u)==0u&&m.r32(0x81776cu)==1u,"1249 cold ordinary physical file/C-locale route");
 need(m.r32(0x81a6c0u)==0u,"1249 genuine cold unowned output index");
 const auto name=read_z(m,0x7c87d8u);need(name=="KEYBOARD.INI","1249 original literal name");o.filename=h.allocate(unsigned(name.size()+1u));write_z(h,o.filename,name);o.reader=h.allocate_reader();const auto path=reinterpret_cast<const char*>(std::uintptr_t(o.filename));for(unsigned k=0;k<2u;++k){const auto probe=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(probe!=INVALID_HANDLE_VALUE&&api.close_handle(probe)!=FALSE,"1249 real availability probes");}
 const auto input=api.create_file_a(path,GENERIC_READ,3u,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(input!=INVALID_HANDLE_VALUE,"1249 real read owner");DWORD got=0u,eof=0u;need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(o.reader)),4096u,&got,nullptr)!=FALSE&&got>0u&&got<128u,"1249 actual singleton text");need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(o.reader+got)),4096u-got,&eof,nullptr)!=FALSE&&eof==0u,"1249 real EOF1");need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(o.reader)),4096u,&eof,nullptr)!=FALSE&&eof==0u,"1249 real EOF2");
 const std::string bytes(reinterpret_cast<const char*>(std::uintptr_t(o.reader)),got);const auto close=bytes.find("]\r\n"),equal=bytes.find('=',close+3u);need(bytes.front()=='['&&close!=std::string::npos&&equal!=std::string::npos&&bytes.substr(bytes.size()-2u)=="\r\n","1249 reached singleton CRLF grammar");const auto sectiontext=bytes.substr(1u,close-1u),keytext=bytes.substr(close+3u,equal-close-3u),value=bytes.substr(equal+1u,bytes.size()-equal-3u);need(sectiontext=="Hotkey"&&keytext=="PlanningMode"&&value=="65","1249 useful exact original command/key binding");
 const auto section=h.allocate(68u),section_name=h.allocate(unsigned(sectiontext.size()+1u)),node=h.allocate(40u),copy=h.allocate(unsigned(value.size()+1u)),key=h.allocate(unsigned(keytext.size()+1u)),keytable=h.allocate(80u),sectiontable=h.allocate(80u);write_z(h,section_name,sectiontext);write_z(h,copy,value);write_z(h,key,keytext);build_single_section(h,h,section,section_name,node,key,copy,keytable,sectiontable,sectiontext,keytext);h.free_reader(o.reader);need(api.close_handle(input)!=FALSE,"1249 parser closes actual read handle");
 // Native50BF50/C250/CC40 warm the singleton indexes; no synthetic sort callback.
 h.w8(section+0x38u,1u);h.w32(section+0x3cu,keytable);
 need(m.r32(0x81a6a8u)==1u,"1249 actual singleton borrowed command registry");const auto command=m.r32(m.r32(0x81a69cu));need(command&&m.r32(command)==0x78edd4u&&m.r32(0x78edd8u)==0x51add0u,"1249 genuine original name getter vtable");need(read_z(m,0x7c7c88u)==keytext,"1249 actual51ADD0 constant name producer");++o.name_callbacks;
 m.w32(0x81a6c0u,0u);m.w32(0x81a6c4u,0u);m.w32(0x81a6c8u,0u);m.w8(0x81a6ccu,0u);m.w32(0x81a6d0u,0u);
 // Original51DCA0(10) allocates exactly ten 8-byte pairs from the cold index.
 o.index=h.allocate(80u);m.w32(0x81a6c0u,o.index);m.w32(0x81a6c8u,10u);m.w32(0x81a6d0u,0u);h.w32(o.index,65u);h.w32(o.index+4u,command);m.w32(0x81a6c4u,1u);m.w8(0x81a6ccu,0u);++o.positive_assignments;
 // Unlike1034, original518956 destroys the file before its local INI.
 o.final_filename_free_bool=h.release(o.filename);need(o.final_filename_free_bool!=0u,"1249 real filename release BOOL");destroy_single_section(h,section,node,sectiontable,0u);
 // Original50AD20's final LEA EAX,[ESI+8] uses ESI=entryESP-B4.
 // Root51898B then writes AL=1. No private value or original return is an input.
 const unsigned empty_head=frame.entry_esp-0xb4u+8u;return(empty_head&0xffffff00u)|1u;
}
}
