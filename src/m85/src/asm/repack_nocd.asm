;******************************************************************************
;*                               O P E N  T S
;******************************************************************************
;* SPDX-License-Identifier: GPL-3.0-or-later
;* Copyright 2025 Electronic Arts Inc.
;* Copyright 2026 OpenTS contributors
;* Copyright 2026 ra2-decomp contributors
;*
;* Contains material derived from Electronic Arts source code.
;* Modified by OpenTS contributors, 2026.
;* EA's GPLv3 Section 7 additional terms and supplemental warranty
;* disclaimers apply; see LICENSE.md.
;******************************************************************************

; repack_nocd.asm -- the repack's no-CD patches of GAME.EXE 1.001, as shipped.
;
; The baseline GAME.EXE of this reconstruction is a repacked 1.001 whose CD checks were binary-patched
; in place. By user decision (2026-11-21) those patches are reconstructed like all other code, as labelled
; repack deltas. VC6 cannot produce the patched bytes from C++, so the three affected functions are written
; here by hand, byte for byte as shipped:
;
;   DiskSwap::Get_Disk_ID       0x4981C0  480 bytes  (diskswap.cpp)  14 bytes patched at +000
;   DiskSwap::Force_Available   0x4983A0  336 bytes  (diskswap.cpp)  32-byte window patched at +034..+053
;   VolumeCheck                 0x709C50  416 bytes  (volinfo.cpp)   17 bytes patched in five places
;
; The ORIGINAL, unpatched logic of these functions remains in P/src/m85/src/diskswap.cpp and volinfo.cpp;
; that C++ compiles to exactly these bytes except for the patched bytes marked "; repack delta:" below.
; Everything that is not marked is the VC6 code of that C++ (/O2 /Ob2 /Gr /GR /Gy), including the code the
; patches made unreachable; it is kept because it is part of the shipped bytes. Comments in brackets name
; the C++ statement a block came from.
;
; One data delta belongs to the same patch set: the format literal "%c:\\" that Get_Disk_ID and the
; CDControlClass routines share (pooled at 0x7BD334) was overwritten with ".\\", so every "drive root" those
; routines build is the current directory. The code below therefore references the shipped literal ".\\"
; (??_C@_02OFKN@?4?2?$AA@), as cdcntrl.cpp already does.
;
; Assembler notes (UASM, see W/tools/level2_check.py): the procedures carry the exact mangled C++ names, every
; relocation is a symbolic EXTERN (imports as __imp__Name@N), and each PROC ends with the VC6 /Gy alignment
; padding (nop) up to the next function, so a PROC is exactly the original function extent.

		.386
		.model	flat
		option	casemap:none

; ---- imports (kernel32 / user32), bound through the import address table ----
EXTERN	__imp__wsprintfA:DWORD
EXTERN	__imp__GetVolumeInformationA@32:DWORD
EXTERN	__imp__GetLastError@0:DWORD
EXTERN	__imp__CreateFileA@28:DWORD
EXTERN	__imp__CloseHandle@4:DWORD
EXTERN	__imp__GetLogicalDriveStringsA@8:DWORD
EXTERN	__imp__GetDriveTypeA@4:DWORD
EXTERN	__imp__GetDiskFreeSpaceA@20:DWORD

; ---- CRT ----
EXTERN	_sprintf:NEAR
EXTERN	_stricmp:NEAR

; ---- game code and data (C++ symbols of other translation units) ----
EXTERN	??RSystemTimerClass@@QBEHXZ:NEAR			; int SystemTimerClass::operator()() const
EXTERN	?Set_CD_Drive@CDFileClass@@SIXH@Z:NEAR			; static void __fastcall CDFileClass::Set_CD_Drive(int)
EXTERN	?Refresh_Search_Drives@CDFileClass@@SIXXZ:NEAR		; static void __fastcall CDFileClass::Refresh_Search_Drives()
EXTERN	?DebugString@@YAXPBDZZ:NEAR				; void DebugString(char const *, ...)
EXTERN	?CurrentCDDrive@CDFileClass@@0HA:DWORD			; static int CDFileClass::CurrentCDDrive
EXTERN	?CDList@@3VGetCDClass@@A:DWORD				; GetCDClass CDList (+68h CDCount, +6Ch CDIndex)
EXTERN	?RequiredCD@CD@@0W4DiskID@@A:DWORD			; static DiskID CD::RequiredCD
EXTERN	??_7CD@@6B@:DWORD					; const CD::`vftable' (slot 0 = Force_Available)

PUBLIC	?Get_Disk_ID@DiskSwap@@SI?AW4DiskID@@HH@Z
PUBLIC	?Force_Available@DiskSwap@@UAE_NW4DiskID@@@Z
PUBLIC	?VolumeCheck@@YI_NXZ

;------------------------------------------------------------------------------
; Data. String literals carry their VC6 names (/GF pooled literals); the checker verifies them by content.
;------------------------------------------------------------------------------
_DATA		SEGMENT DWORD PUBLIC FLAT 'DATA'
PUBLIC	??_C@_02OFKN@?4?2?$AA@
PUBLIC	??_C@_04FIJC@RA?$CFd?$AA@
PUBLIC	??_C@_0N@KIKC@?$CFc?3?2RA?$CFd?4dsk?$AA@
PUBLIC	??_C@_0BP@MGCA@GetDiskFreeSpace?$CI?$CJ?5failed?3?5?$CFs?6?$AA@
PUBLIC	??_C@_0CF@MONL@GetVolumeInformation?$CI?$CJ?5?9?5failed?3@
PUBLIC	??_C@_0CD@KBGG@VolumeCheck?$CI?$CJ?5?9?5GetVolInfo?5faile@
PUBLIC	_?_last@?1??Force_Available@DiskSwap@@UAE_NW4DiskID@@@Z@4HA

; repack delta (data): originally "%c:\\" (??_C@_04POLC@?$CFc?3?2?$AA@); shipped as ".\\" at 0x7BD334
??_C@_02OFKN@?4?2?$AA@						db	".\", 0
??_C@_04FIJC@RA?$CFd?$AA@					db	"RA%d", 0
??_C@_0N@KIKC@?$CFc?3?2RA?$CFd?4dsk?$AA@			db	"%c:\RA%d.dsk", 0
??_C@_0BP@MGCA@GetDiskFreeSpace?$CI?$CJ?5failed?3?5?$CFs?6?$AA@	db	"GetDiskFreeSpace() failed: %s", 10, 0
??_C@_0CF@MONL@GetVolumeInformation?$CI?$CJ?5?9?5failed?3@	db	"GetVolumeInformation() - failed: %s", 10, 0
??_C@_0CD@KBGG@VolumeCheck?$CI?$CJ?5?9?5GetVolInfo?5faile@	db	"VolumeCheck() - GetVolInfo failed", 10, 0

; static int _last = -1;   (function-local static of DiskSwap::Force_Available, 0x7C0D84)
		ALIGN	4
_?_last@?1??Force_Available@DiskSwap@@UAE_NW4DiskID@@@Z@4HA	dd	-1
_DATA		ENDS

;------------------------------------------------------------------------------
; repack delta (data): a variable the patch added at 0xB11EE0, in the zero-filled slack of the last .data page
; beyond the section's VirtualSize (0xB11E44). Force_Available's patch remembers the last disk it accepted here.
;------------------------------------------------------------------------------
_BSS		SEGMENT DWORD PUBLIC FLAT 'BSS'
PUBLIC	_RepackNoCD_LastDisk
_RepackNoCD_LastDisk	dd	?
_BSS		ENDS


;==============================================================================
; DiskID __fastcall DiskSwap::Get_Disk_ID(int cd_drive /*ECX*/, int timeout /*EDX*/)     0x4981C0
;
; Original 1.001 (diskswap.cpp): read the volume label of drive cd_drive ("%c:\\"), retrying while the drive
; reports ERROR_NOT_READY until the timeout expires; match it against "RA1".."RA8", then confirm the disc by
; opening "%c:\\RAn.dsk" (two attempts). Returns the disc index or DISK_ANY (-1).
;
; Shipped: the first 14 bytes (the prologue) are replaced, so the function now returns at once:
;     return (caller's EDI == 1) ? 1 : 0;
; EDI is not an argument; it is whatever the caller holds. Force_Available, the only caller that matters, keeps
; the requested disk in EDI, so for the two game discs (0, 1) the patched function reports exactly the disc
; being asked for. Everything after +00E is the original code, now unreachable.
;==============================================================================
_TEXT$GetDiskID	SEGMENT PARA PUBLIC FLAT 'CODE'
?Get_Disk_ID@DiskSwap@@SI?AW4DiskID@@HH@Z	PROC
; repack delta (14 bytes, +000..+00D): replaces the prologue
;     sub esp,148h / push ebx / push ebp / push esi / push edi / mov edi,ecx / mov esi,edx
		cmp	edi, 1		; repack delta
		je	gdi_008		; repack delta
		xor	eax, eax		; repack delta: return 0
		ret		; repack delta
gdi_008:
		mov	eax, 1		; repack delta: return 1
		ret		; repack delta
; ---- original code from here on (unreachable after the patch) ----
; [CDTimerClass<SystemTimerClass> timer; timer = timeout;]
		lea	ecx, [esp+18h]
		call	??RSystemTimerClass@@QBEHXZ
		lea	ecx, [esp+30h]
		mov	dword ptr [esp+14h], eax
		mov	dword ptr [esp+1Ch], 0
		call	??RSystemTimerClass@@QBEHXZ
; [cd = cd_drive + 'A'; wsprintf(buffer, "%c:\\", cd);]  (the literal is shipped as ".\\", see the header)
		mov	ebp, dword ptr [__imp__wsprintfA]
		add	edi, 41h
		mov	dword ptr [esp+14h], eax
		mov	eax, dword ptr [esp+30h]
		push	edi
		lea	ecx, [esp+3Ch]
		push	offset ??_C@_02OFKN@?4?2?$AA@
		push	ecx
		mov	dword ptr [esp+24h], eax
		mov	dword ptr [esp+28h], esi
		call	ebp
		add	esp, 0Ch
; [GetVolumeInformation(buffer, volume_name, sizeof(volume_name) - 1, NULL, &filename_length, &misc_dword, NULL, 0)]
		mov	ebx, dword ptr [__imp__GetVolumeInformationA@32]
		lea	edx, [esp+28h]
		lea	eax, [esp+24h]
		push	0
		push	0
		push	edx
		push	eax
		push	0
		lea	ecx, [esp+0ECh]
		push	7Fh
		lea	edx, [esp+50h]
		push	ecx
		push	edx
		call	ebx
		test	eax, eax
		jne	gdi_0EC
; [failure: if (!timer) return DISK_ANY;]
gdi_080:
		mov	eax, dword ptr [esp+14h]
		mov	esi, dword ptr [esp+1Ch]
		cmp	eax, -1
		je	gdi_0A4
		lea	ecx, [esp+18h]
		call	??RSystemTimerClass@@QBEHXZ
		sub	eax, dword ptr [esp+14h]
		cmp	eax, esi
		jge	gdi_133
		sub	esi, eax
gdi_0A4:
		test	esi, esi
		je	gdi_133
; [if (GetLastError() != ERROR_NOT_READY) return DISK_ANY;]  then retry the label
		call	dword ptr [__imp__GetLastError@0]
		cmp	eax, 15h
		jne	gdi_133
		push	edi
		lea	eax, [esp+3Ch]
		push	offset ??_C@_02OFKN@?4?2?$AA@
		push	eax
		call	ebp
		add	esp, 0Ch
		lea	ecx, [esp+28h]
		lea	edx, [esp+24h]
		lea	eax, [esp+0D8h]
		push	0
		push	0
		push	ecx
		push	edx
		push	0
		push	7Fh
		lea	ecx, [esp+50h]
		push	eax
		push	ecx
		call	ebx
		test	eax, eax
		je	gdi_080
; [success: for (i = 0; i < 8; i++) { sprintf(volname_label, "RA%d", i + 1); if (!stricmp(...)) { index = i; break; } }]
gdi_0EC:
		xor	ebx, ebx
		mov	dword ptr [esp+10h], ebx
		jmp	gdi_0F8
gdi_0F4:
		mov	ebx, dword ptr [esp+10h]
gdi_0F8:
		lea	esi, [ebx+1]
		lea	edx, [esp+0B8h]
		push	esi
		push	offset ??_C@_04FIJC@RA?$CFd?$AA@
		push	edx
		call	_sprintf
		lea	eax, [esp+0E4h]
		lea	ecx, [esp+0C4h]
		push	eax
		push	ecx
		call	_stricmp
		add	esp, 14h
		test	eax, eax
		je	gdi_141
		cmp	esi, 8
		mov	dword ptr [esp+10h], esi
		jl	gdi_0F4
; [return DISK_ANY;]
gdi_133:
		pop	edi
		pop	esi
		pop	ebp
		or	eax, 0FFFFFFFFh
		pop	ebx
		add	esp, 148h
		ret
; [if (index > -1): open "%c:\\RA%d.dsk" to verify the disc, at most two attempts]
gdi_141:
		cmp	ebx, -1
		jle	gdi_133
		lea	esi, [ebx+1]
		lea	edx, [esp+38h]
		push	esi
		push	edi
		push	offset ??_C@_0N@KIKC@?$CFc?3?2RA?$CFd?4dsk?$AA@
		push	edx
		mov	dword ptr [esp+30h], 0
		call	ebp
		add	esp, 10h
		mov	ebx, dword ptr [__imp__CreateFileA@28]
		lea	eax, [esp+38h]
		push	0
		push	80h
		push	3
		push	0
		push	1
		push	80000000h
		push	eax
		call	ebx
		cmp	eax, -1
		jne	gdi_1C3
gdi_186:
		mov	eax, dword ptr [esp+20h]
		inc	eax
		cmp	eax, 2
		mov	dword ptr [esp+20h], eax
		jge	gdi_133
		push	esi
		push	edi
		lea	ecx, [esp+40h]
		push	offset ??_C@_0N@KIKC@?$CFc?3?2RA?$CFd?4dsk?$AA@
		push	ecx
		call	ebp
		add	esp, 10h
		lea	edx, [esp+38h]
		push	0
		push	80h
		push	3
		push	0
		push	1
		push	80000000h
		push	edx
		call	ebx
		cmp	eax, -1
		je	gdi_186
; [CloseHandle(handle); return (DiskID)index;]
gdi_1C3:
		push	eax
		call	dword ptr [__imp__CloseHandle@4]
		mov	eax, dword ptr [esp+10h]
		pop	edi
		pop	esi
		pop	ebp
		pop	ebx
		add	esp, 148h
		ret
; VC6 /Gy alignment padding up to 0x4983A0
		db	7 dup (90h)
?Get_Disk_ID@DiskSwap@@SI?AW4DiskID@@HH@Z	ENDP
_TEXT$GetDiskID	ENDS

;==============================================================================
; bool __thiscall DiskSwap::Force_Available(DiskID disk)                                  0x4983A0
;
; Original 1.001 (diskswap.cpp): make sure the requested disc is in some CD drive -- the current drive, the last
; drive, then all drives, prompting through Request_Disk (vtable +4) -- and announce a newly found disc through
; Swap (vtable +8).
;
; Shipped: a 32-byte window after the first Get_Disk_ID call is replaced:
;     if (cd_current != disk) return true;              // with the patched Get_Disk_ID: any disc but 0 and 1
;     if (RepackNoCD_LastDisk == disk) return true;      // already accepted
;     RepackNoCD_LastDisk = disk;
;     goto set_drive;                                    // Set_CD_Drive(current drive), Refresh_Search_Drives(), Swap
; ECX still holds the current drive at set_drive because the patched Get_Disk_ID leaves ECX alone. The drive
; searches (+054..+0FB) are the original code, now unreachable.
;==============================================================================
_TEXT$ForceAvail	SEGMENT PARA PUBLIC FLAT 'CODE'
?Force_Available@DiskSwap@@UAE_NW4DiskID@@@Z	PROC
; [if (disk == DISK_LOCAL) return true;]   EDI = disk, EBX = this, [esp+10h] = new_cd_drive = 0
		sub	esp, 8
		push	ebx
		push	ebp
		push	esi
		push	edi
		mov	edi, dword ptr [esp+1Ch]
		mov	ebx, ecx
		cmp	edi, -2
		mov	dword ptr [esp+14h], ebx
		mov	dword ptr [esp+10h], 0
		je	fa_13B
; [current_drive = CDFileClass::Get_CD_Drive(); cd_current = Get_Disk_ID(current_drive, 1*TIMER_SECOND);]
		mov	esi, dword ptr [?CurrentCDDrive@CDFileClass@@0HA]
		mov	edx, 3Ch
		mov	ecx, esi
		call	?Get_Disk_ID@DiskSwap@@SI?AW4DiskID@@HH@Z
; repack delta (32 bytes, +034..+053): replaces
;     cmp eax,-1 / jle +04E / cmp edi,eax / je +042 / cmp edi,-1 / jne +04E /
;     test esi,esi / mov [esp+10h],esi / jne +10A / mov ecx,[CDFileClass::LastCDDrive]
;   i.e. [if (cd_current > DISK_ANY && (disk == cd_current || disk == DISK_ANY)) new_cd_drive = current_drive;
;         if (!new_cd_drive) { last_drive = CDFileClass::Get_Last_CD_Drive(); ...]
		cmp	eax, edi		; repack delta: Get_Disk_ID result != disk
		jne	fa_13B		; repack delta: -> return true
		cmp	dword ptr [_RepackNoCD_LastDisk], edi		; repack delta: already accepted this disk?
		je	fa_13B		; repack delta: -> return true
		mov	dword ptr [_RepackNoCD_LastDisk], eax		; repack delta: remember it (EAX == disk here)
		jmp	fa_0FC		; repack delta: -> Set_CD_Drive(ECX = current drive)
		nop		; repack delta: filler
		nop		; repack delta: filler
; ---- original code, unreachable after the patch ----
; [if (last_drive && last_drive != CDFileClass::Get_CD_Drive()) cd_current = Get_Disk_ID(last_drive, 10*TIMER_SECOND) ...]
		test	ecx, ecx
		je	fa_080
		cmp	ecx, dword ptr [?CurrentCDDrive@CDFileClass@@0HA]
		je	fa_080
		mov	edx, 258h
		call	?Get_Disk_ID@DiskSwap@@SI?AW4DiskID@@HH@Z
		cmp	eax, -1
		jle	fa_080
		cmp	edi, eax
		je	fa_10A
		cmp	edi, -1
		je	fa_13B
; [search all CD drives: for (i = 0; i < CDList.Get_Number_Of_Drives(); i++) { cd_drive = CDList.Get_Next_CD_Drive(); ... }]
fa_080:
		mov	ebp, 78h
fa_085:
		mov	ecx, dword ptr [?CDList@@3VGetCDClass@@A+68h]		; CDList.CDCount
		xor	ebx, ebx
		test	ecx, ecx
		jle	fa_0DF
fa_091:
		test	ecx, ecx
		je	fa_0B4
		mov	eax, dword ptr [?CDList@@3VGetCDClass@@A+6Ch]		; CDList.CDIndex
		cmp	eax, ecx
		jne	fa_0A5
		xor	eax, eax
		mov	dword ptr [?CDList@@3VGetCDClass@@A+6Ch], eax		; CDList.CDIndex
fa_0A5:
		mov	esi, dword ptr [?CDList@@3VGetCDClass@@A+eax*4]		; CDList.CDDrives[]
		inc	eax
		mov	dword ptr [?CDList@@3VGetCDClass@@A+6Ch], eax		; CDList.CDIndex
		jmp	fa_0B7
fa_0B4:
		or	esi, 0FFFFFFFFh
fa_0B7:
		mov	edx, ebp
		mov	ecx, esi
		call	?Get_Disk_ID@DiskSwap@@SI?AW4DiskID@@HH@Z
		cmp	eax, -1
		jle	fa_0CE
		cmp	edi, eax
		je	fa_0DB
		cmp	edi, -1
		je	fa_0DB
fa_0CE:
		mov	ecx, dword ptr [?CDList@@3VGetCDClass@@A+68h]		; CDList.CDCount
		inc	ebx
		cmp	ebx, ecx
		jl	fa_091
		jmp	fa_0DF
fa_0DB:
		mov	dword ptr [esp+10h], esi
; [if (new_cd_drive > DISK_FIRST) ... else if (!Request_Disk(disk)) ...; drive_search_timeout = 5*TIMER_SECOND;]
fa_0DF:
		mov	ecx, dword ptr [esp+10h]
		test	ecx, ecx
		jg	fa_0FC
		mov	ecx, dword ptr [esp+14h]
		push	edi
		mov	eax, dword ptr [ecx]
		call	dword ptr [eax+4]		; Request_Disk (vtable +4)
		test	al, al
		je	fa_12F
		mov	ebp, 12Ch
		jmp	fa_085
; ---- reached again from the patch ----
; [CDFileClass::Set_CD_Drive(new_cd_drive); CDFileClass::Refresh_Search_Drives();]
fa_0FC:
		call	?Set_CD_Drive@CDFileClass@@SIXH@Z
		call	?Refresh_Search_Drives@CDFileClass@@SIXXZ
; [if (disk > DISK_ANY && _last != disk) { _last = disk; return Swap(disk); }]
		mov	ebx, dword ptr [esp+14h]
fa_10A:
		cmp	edi, -1
		jle	fa_13B
		cmp	dword ptr [_?_last@?1??Force_Available@DiskSwap@@UAE_NW4DiskID@@@Z@4HA], edi
		je	fa_13B
		mov	dword ptr [_?_last@?1??Force_Available@DiskSwap@@UAE_NW4DiskID@@@Z@4HA], edi
		mov	edx, dword ptr [ebx]
		push	edi
		mov	ecx, ebx
		call	dword ptr [edx+8]		; Swap (vtable +8)
		pop	edi
		pop	esi
		pop	ebp
		pop	ebx
		add	esp, 8
		ret	4
; [return false;]
fa_12F:
		pop	edi
		pop	esi
		pop	ebp
		xor	al, al
		pop	ebx
		add	esp, 8
		ret	4
; [return true;]
fa_13B:
		pop	edi
		pop	esi
		pop	ebp
		mov	al, 1
		pop	ebx
		add	esp, 8
		ret	4
; VC6 /Gy alignment padding up to 0x4984F0
		db	9 dup (90h)
?Force_Available@DiskSwap@@UAE_NW4DiskID@@@Z	ENDP
_TEXT$ForceAvail	ENDS

;==============================================================================
; bool __fastcall VolumeCheck(void)                                                       0x709C50
;
; Original 1.001 (volinfo.cpp): walk GetLogicalDriveStrings; for every CD-ROM drive read the volume
; information (GetVolInfo, inlined) and return true when the label is "RA1".."RA8"; otherwise ask
; CD().Force_Available(). The volume scan from TS 1.13 is compiled in.
;
; Shipped: five patches (17 bytes) force success. The drive string is overwritten with ".\\" (the current
; directory) instead of testing GetDriveType() == DRIVE_CDROM, both failure branches and the free-space reject
; are skipped, and the label comparison returns true whatever the label is.
;==============================================================================
_TEXT$VolCheck	SEGMENT PARA PUBLIC FLAT 'CODE'
?VolumeCheck@@YI_NXZ	PROC
; [if (!GetLogicalDriveStrings(sizeof(buffer), buffer)) return false;]
		sub	esp, 1D0h
		lea	eax, [esp+0CCh]
		push	ebx
		push	ebp
		push	esi
		push	edi
		push	eax
		push	104h
		call	dword ptr [__imp__GetLogicalDriveStringsA@8]
		test	eax, eax
		jne	vc_02E
		pop	edi
		pop	esi
		pop	ebp
		xor	al, al
		pop	ebx
		add	esp, 1D0h
		ret
; [drive_root_name = buffer; while (strlen(drive_root_name) != 0) {]
vc_02E:
		lea	edi, [esp+0DCh]
		or	ecx, 0FFFFFFFFh
		xor	eax, eax
		lea	esi, [esp+0DCh]
		repne scasb
		not	ecx
		dec	ecx
		je	vc_161
		mov	ebx, dword ptr [__imp__GetDriveTypeA@4]
		mov	ebp, dword ptr [__imp__GetDiskFreeSpaceA@20]
; loop head (also the target of the loop-back jne at +15B)
; repack delta (12 bytes, +058..+063): replaces  push esi / call ebx / cmp eax,5 / jne +141
;   [if (GetDriveType(drive_root_name) == DRIVE_CDROM)]; shipped: *(DWORD *)drive_root_name = '\.' (".\", 0, 0)
vc_058:
		mov	dword ptr [esi], 5C2Eh		; repack delta: ".\", 0, 0 over the drive string
		nop		; repack delta: filler
		nop		; repack delta: filler
		nop		; repack delta: filler
		nop		; repack delta: filler
		nop		; repack delta: filler
		nop		; repack delta: filler
; [GetVolInfo (inlined): memset(&info, 0, sizeof(info)); info.DriveType = GetDriveType(drive_root_name);]
		mov	ecx, 24h
		xor	eax, eax
		lea	edi, [esp+4Ch]
		push	esi
		rep stosd
		call	ebx
; [if (GetDiskFreeSpace(drive_root_name, &sectorspercluster, &bytespersector, &freeclustercount, &totalclustercount) == 0)]
		lea	ecx, [esp+1Ch]
		lea	edx, [esp+10h]
		mov	dword ptr [esp+4Ch], eax
		push	ecx
		lea	eax, [esp+18h]
		push	edx
		lea	ecx, [esp+20h]
		push	eax
		push	ecx
		push	esi
		call	ebp
		test	eax, eax
; repack delta (1 byte, +091): jne +09B (75h) -> jmp +09B (EBh); the failure report below is skipped
		jmp	vc_09B		; repack delta: was jne
; [DebugString("GetDiskFreeSpace() failed: %s\n", ...); GetVolInfo returns false] continues in the report at +0F8  (unreachable)
		push	eax
		push	offset ??_C@_0BP@MGCA@GetDiskFreeSpace?$CI?$CJ?5failed?3?5?$CFs?6?$AA@
		jmp	vc_0F8
; [info.FreeSpace = freeclustercount * bytespersector * sectorspercluster; if (freeclustercount != 0) return false;]
vc_09B:
		mov	eax, dword ptr [esp+18h]
		mov	ecx, dword ptr [esp+10h]
		imul	eax, dword ptr [esp+14h]
		mov	edx, eax
		imul	edx, ecx
		test	ecx, ecx
		mov	dword ptr [esp+0D4h], edx
; repack delta (2 bytes, +0B6): jne +100 (75h 48h) -> nop nop; a drive with free space is no longer rejected
		nop		; repack delta: was jne vc_100 (75h 48h)
		nop		; repack delta
; [info.TotalSpace = ...; GetVolumeInformation(drive_root_name, info.VolumeName, 64, &serial, &maxlen, &flags, info.FileSystemName, 64)]
		imul	eax, dword ptr [esp+1Ch]
		mov	dword ptr [esp+0D8h], eax
		lea	eax, [esp+94h]
		push	40h
		lea	ecx, [esp+2Ch]
		push	eax
		lea	edx, [esp+28h]
		push	ecx
		lea	eax, [esp+9Ch]
		push	edx
		push	eax
		lea	ecx, [esp+64h]
		push	40h
		push	ecx
		push	esi
		call	dword ptr [__imp__GetVolumeInformationA@32]
		test	eax, eax
; repack delta (1 byte, +0F0): jne +10F (75h) -> jmp +10F (EBh); the failure path below is skipped
		jmp	vc_10F		; repack delta: was jne
; [DebugString("GetVolumeInformation() - failed: %s\n", ...); DebugString("VolumeCheck() - GetVolInfo failed\n"); next drive]  (unreachable)
		push	eax
		push	offset ??_C@_0CF@MONL@GetVolumeInformation?$CI?$CJ?5?9?5failed?3@
vc_0F8:
		call	?DebugString@@YAXPBDZZ
		add	esp, 8
		push	offset ??_C@_0CD@KBGG@VolumeCheck?$CI?$CJ?5?9?5GetVolInfo?5faile@
		call	?DebugString@@YAXPBDZZ
		add	esp, 4
		jmp	vc_141
; [for (i = 0; i < 8; i++) { sprintf(name, "RA%d", i + 1); if (!stricmp(name, info.VolumeName)) return true; }]
vc_10F:
		xor	eax, eax
vc_111:
		lea	edi, [eax+1]
		lea	edx, [esp+2Ch]
		push	edi
		push	offset ??_C@_04FIJC@RA?$CFd?$AA@
		push	edx
		call	_sprintf
		lea	eax, [esp+5Ch]
		lea	ecx, [esp+38h]
		push	eax
		push	ecx
		call	_stricmp
		add	esp, 14h
		test	eax, eax
; repack delta (1 byte, +138): je +18A (74h) -> jmp +18A (EBh); return true after the first comparison
		jmp	vc_18A		; repack delta: was je
; (unreachable from here to +160 after the patches)
		mov	eax, edi
		cmp	eax, 8
		jl	vc_111
; [drive_root_name += strlen(drive_root_name) + 1;]  }
vc_141:
		mov	edi, esi
		or	ecx, 0FFFFFFFFh
		xor	eax, eax
		repne scasb
		not	ecx
		dec	ecx
		lea	esi, [esi+ecx+1]
		or	ecx, 0FFFFFFFFh
		mov	edi, esi
		repne scasb
		not	ecx
		dec	ecx
		jne	vc_058
; [return CD().Force_Available();]  -- a temporary CD whose vptr is set, slot 0 called directly (devirtualised)
vc_161:
		mov	edx, dword ptr [?RequiredCD@CD@@0W4DiskID@@A]
		lea	ecx, [esp+20h]
		push	edx
		mov	dword ptr [esp+24h], offset ??_7CD@@6B@		; temporary CD object: vptr
		call	dword ptr [??_7CD@@6B@]		; CD::Force_Available (slot 0)
		test	al, al
		pop	edi
		pop	esi
		pop	ebp
		pop	ebx
		setne	al
		add	esp, 1D0h
		ret
; [return true;]
vc_18A:
		pop	edi
		pop	esi
		pop	ebp
		mov	al, 1
		pop	ebx
		add	esp, 1D0h
		ret
; VC6 /Gy alignment padding up to 0x709DF0
		db	9 dup (90h)
?VolumeCheck@@YI_NXZ	ENDP
_TEXT$VolCheck	ENDS

		END
