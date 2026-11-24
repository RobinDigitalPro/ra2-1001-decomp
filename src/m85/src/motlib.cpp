/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "always.h"

#include "motlib.h"

#include "wwfile.h"

#include "voxel.hh"

#include "audioctl.h" // level-2 1.001: the audio test keys of the debug window
#include "audevent.h"
#include "audplay.h"
#include "auddsnd.h"
#include "voc.h"

// level-2 1.001: the debug text window kept by this object file (0x59A570..0x59AF50 in 1.001). Adopted from gibbo101 motlib.cpp and
// debugpage.h; the names are provisional, the layout (0x2738 bytes) was checked against 1.001's constructor.
#include <string.h>

struct DebugPage { // level-2 1.001: one 80 x 25 page of text and attributes, drawn into the debug window
	char Text[80][25];
	int Attr[80][25];
	int Pad[2];
	int Index;
	int Field271C;
	int Field2720;
	int Field2724;
	int Field2728;
	int Columns;
	int Rows;
	bool Dirty;

	DebugPage(int index) :
		Index(index), Field271C(0), Field2720(0), Field2724(0), Field2728(0), Columns(80), Rows(25)
	{
		Clear(); // level-2 1.001: expanded inline, the executable's Reset is a separate call
	}
	void Reset(void); // 0x19B080: the same steps as Clear, but the executable calls it out of line (the A, I and M keys of the window)
	void Clear(void)
	{
		Blank();
		Dirty = true;
		Refresh(0, 0, 80, 25);
	}
	void Blank(void)
	{
		for (int row = 0; row < 25; row++) {
			for (int col = 0; col < 80; col++) {
				Text[col][row] = ' ';
				Attr[col][row] = 0;
			}
		}
	}
	void Refresh(int x, int y, int w, int h); // 0x19B880
};

extern DebugPage * DebugPages[8]; // 0xA58A58
extern HINSTANCE DebugInstance; // 0xA58B18
extern HWND DebugParentWindow; // 0xA58B1C
extern bool DebugEnabled; // 0xA58B20
extern bool DebugShowPending; // 0xA58B21
extern bool DebugVisible; // 0xA58B22
extern DebugPage * CurrentDebugPage; // 0xA58B24
extern HWND DebugWindow; // 0xA58B28
extern HGDIOBJ DebugFont; // 0xA58B2C
extern TEXTMETRIC DebugTextMetric; // 0xA58AB8
extern int DebugBackColor; // 0xA58A18
extern int DebugTextColor; // 0xA58A00
extern void Create_Debug_Window(void); // 0x19A920
extern void __fastcall Set_Debug_Window_Style(HWND window); // 0x122060
extern void __fastcall Release_Debug_Window_Style(HWND window); // 0x1220C0
extern BOOL CALLBACK Debug_Window_Proc(HWND, UINT, WPARAM, LPARAM); // 0x19AAD0
extern AudioController * DebugAudioController; // 0xA58B0C
extern AudioController DebugAudioControllerObject; // 0xA58A88
extern int DebugEventCursor; // 0xA58B08
extern int DebugEventChannel; // 0xA58B14
extern int DebugStreamCount; // 0xA58B10
extern AudioStreamer * DebugStreams[5]; // 0xA58A04
extern int DebugToggle; // 0xA58B04
extern int AudioEventTypeCount; // 0xAB83C0
int __fastcall Voc_Find_Index(char const * name); // 0x309500
void __fastcall Audio_Play_Test_Event(int index, int a, int b); // 0x30A480
void __fastcall Audio_Stop_All(void); // 0x006E20

void __fastcall Debug_Window_Init(HINSTANCE instance, HWND window, bool enabled) // level-2 1.001: 0x19A570, adopted from gibbo101 (FUN_005BC180)
{
	DebugInstance = instance;
	DebugParentWindow = window;
	DebugEnabled = enabled;
	for (int i = 0; i < 8; i++) {
		DebugPages[i] = new DebugPage(i);
	}
	CurrentDebugPage = DebugPages[0];
	for (int j = 0; j < 8; j++) {
		DebugPages[j]->Clear(); // level-2 1.001: inline
	}
	if (DebugShowPending && DebugEnabled) {
		if (DebugWindow == NULL) {
			Create_Debug_Window();
		}
		DebugVisible = true;
		ShowWindow(DebugWindow, SW_SHOWNORMAL);
		SetFocus(DebugParentWindow);
	}
}

void __fastcall Debug_Window_Shutdown(void) // level-2 1.001: 0x19A6F0, adopted from gibbo101 (FUN_005BC300)
{
	for (int i = 0; i < 8; i++) {
		if (DebugPages[i] != NULL) {
			delete DebugPages[i];
			DebugPages[i] = NULL;
		}
	}
	if (DebugWindow != NULL) {
		DeleteObject(DebugFont);
		Release_Debug_Window_Style(DebugWindow);
		DestroyWindow(DebugWindow);
		DebugFont = NULL;
		DebugWindow = NULL;
	}
}

void __fastcall Debug_Window_Show_Or_Defer(void) // level-2 1.001: 0x19A760, adopted from gibbo101 (FUN_005BC370)
{
	if (DebugParentWindow == NULL) {
		DebugShowPending = true;
		return;
	}
	if (DebugEnabled) {
		if (DebugWindow == NULL) {
			Create_Debug_Window();
		}
		DebugVisible = true;
		ShowWindow(DebugWindow, SW_SHOWNORMAL);
		SetFocus(DebugParentWindow);
	}
}

void __fastcall Debug_Window_Show(void) // level-2 1.001: 0x19A7B0, adopted from gibbo101 (FUN_005BC3C0)
{
	if (DebugEnabled) {
		if (DebugWindow == NULL) {
			Create_Debug_Window();
		}
		DebugVisible = true;
		ShowWindow(DebugWindow, SW_SHOWNORMAL);
		SetFocus(DebugParentWindow);
	}
}

void __fastcall Debug_Window_Hide(void) // level-2 1.001: 0x19A7F0, adopted from gibbo101 (FUN_005BC400)
{
	DebugShowPending = false;
	if (DebugWindow != NULL) {
		DebugVisible = false;
		ShowWindow(DebugWindow, SW_HIDE);
	}
}

int __fastcall Debug_Window_Is_Shown(void) // level-2 1.001: 0x19A810, adopted from gibbo101 (FUN_005BC420)
{
	if (DebugVisible || DebugShowPending) {
		return 1;
	}
	return 0;
}

DebugPage * __fastcall Debug_Window_Current_Page(void) // level-2 1.001: 0x19A830, written from the disassembly; name INFERRED
{
	return CurrentDebugPage;
}

DebugPage * __fastcall Debug_Window_Get_Page(int index) // level-2 1.001: 0x19A840, written from the disassembly; name INFERRED
{
	return DebugPages[index];
}

void __fastcall Debug_Window_Select_Page(int index) // level-2 1.001: 0x19A850, adopted from gibbo101 (FUN_005BC460)
{
	DebugPage * page = DebugPages[index];
	CurrentDebugPage = page;
	page->Clear(); // level-2 1.001: inline
	CurrentDebugPage->Refresh(0, 0, 80, 25);
}

void __fastcall Debug_Window_Reset_Pages(void) // level-2 1.001: 0x19A8C0, adopted from gibbo101 (FUN_005BC4D0)
{
	for (int i = 0; i < 8; i++) {
		DebugPages[i]->Clear(); // level-2 1.001: inline
	}
}

void Create_Debug_Window(void) // level-2 1.001: 0x19A920, adopted from gibbo101 (FUN_005BC530)
{
	DebugWindow = CreateDialogParamA(DebugInstance, MAKEINTRESOURCE(248), DebugParentWindow, (DLGPROC)Debug_Window_Proc, 0);
	Set_Debug_Window_Style(DebugWindow);
	HDC dc = GetDC(DebugWindow);

	LOGFONT lf;
	lf.lfHeight = -MulDiv(8, GetDeviceCaps(dc, LOGPIXELSY), 72);
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 0;
	lf.lfItalic = 0;
	lf.lfUnderline = 0;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = 0;
	lf.lfOutPrecision = 0;
	lf.lfClipPrecision = 0;
	lf.lfQuality = 0;
	lf.lfPitchAndFamily = 0;
	strcpy(lf.lfFaceName, "Courier");
	DebugFont = CreateFontIndirect(&lf);
	HGDIOBJ old = SelectObject(dc, DebugFont);
	GetTextMetrics(dc, &DebugTextMetric);
	SelectObject(dc, old);
	DebugBackColor = GetSysColor(COLOR_BTNFACE);
	DebugTextColor = GetSysColor(COLOR_WINDOWTEXT);

	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = DebugTextMetric.tmMaxCharWidth * 79 + 20;
	rect.bottom = (DebugTextMetric.tmExternalLeading + DebugTextMetric.tmHeight) * 25 + 20; // level-2 1.001: operand order fixes the field load order (tmHeight first, as 0x59aa23)
	AdjustWindowRect(&rect, WS_CAPTION, FALSE);
	RECT parent;
	GetWindowRect(DebugParentWindow, &parent);
	MoveWindow(DebugWindow, parent.right + 5, 0, rect.right - rect.left, rect.bottom - rect.top, TRUE);
	ShowWindow(DebugWindow, SW_HIDE);
	SetFocus(DebugParentWindow);
	ReleaseDC(DebugWindow, dc);
}


BOOL CALLBACK Debug_Window_Proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) // level-2 1.001: 0x19AAD0, adopted from gibbo101 (FUN_005BC6E0)
{
	if (msg == WM_PAINT) {
		InvalidateRect(hwnd, NULL, TRUE);
		PAINTSTRUCT ps;
		BeginPaint(hwnd, &ps);
		DebugPage * page = CurrentDebugPage;
		if (page != NULL && DebugVisible) {
			if (CurrentDebugPage != page) {
				CurrentDebugPage = page;
				page->Reset();
			}
			page->Refresh(0, 0, 80, 25);
		}
		EndPaint(hwnd, &ps);
		return TRUE;
	}
	if (msg == WM_CHAR) {
		if (DebugAudioController == NULL) {
			AudioController * controller = &DebugAudioControllerObject;
			DebugAudioController = controller;
			controller->Init();
		}
		switch (wparam) {
		case '1':
		case '2':
		case '3':
		case '4':
			DebugEventChannel = wparam - '1';
			return FALSE;
		case 'Q':
		case 'q':
			if (DebugEventCursor > 16 || DebugEventCursor >= AudioEventTypeCount) {
				DebugEventCursor = 0;
			}
			Audio_Play_Test_Event(DebugEventCursor, 1, DebugEventChannel);
			DebugEventCursor++;
			return FALSE;
		case 'W':
		case 'w':
			if (DebugEventCursor > 16 || DebugEventCursor >= AudioEventTypeCount) {
				DebugEventCursor = 0;
			}
			Audio_Play_Test_Event(DebugEventCursor, 0, DebugEventChannel);
			DebugEventCursor++;
			return FALSE;
		case 'E':
		case 'e':
			if (DebugEventCursor > 16 || DebugEventCursor >= AudioEventTypeCount) {
				DebugEventCursor = 0;
			}
			Audio_Play_Test_Event(DebugEventCursor, 2, DebugEventChannel);
			DebugEventCursor++;
			return FALSE;
		case 'O':
		case 'o':
			if (DebugEventCursor > 16 || DebugEventCursor >= AudioEventTypeCount) {
				DebugEventCursor = 0;
			}
			Audio_Play_Test_Event(DebugEventCursor, -1, -1);
			DebugEventCursor++;
			return FALSE;
		case 'L':
		case 'l':
			if (AudioControllerGetEvent(DebugAudioController) != NULL) {
				DebugAudioController->End();
				return FALSE;
			}
			VocClass::PlayGlobal(Voc_Find_Index("TestEnvelopeFShift"), 1.0f, 0x2000, DebugAudioController);
			return FALSE;
		case 'T':
		case 't':
			VocClass::PlayGlobal(Voc_Find_Index("TestEffect"), 1.0f, 0x2000, NULL);
			return FALSE;
		case '[':
			if (DebugStreamCount < 5) {
				AudioStreamer * stream = AudioStreamerCreate(AudioGetDevice(), 5000);
				DebugStreams[DebugStreamCount] = stream;
				if (stream != NULL) {
					if (AudioStreamerPlayWAV(stream, "intro.wav", 1) != 0) {
						DebugStreamCount++;
						return FALSE;
					}
					AudioStreamerDestroy(DebugStreams[DebugStreamCount]);
				}
			}
			return FALSE;
		case ']':
			if (DebugStreamCount > 0) {
				AudioStreamer * last = DebugStreams[DebugStreamCount - 1];
				DebugStreamCount--;
				AudioStreamerStop(last);
				AudioStreamerDestroy(DebugStreams[DebugStreamCount]);
			}
			return FALSE;
		case 'N':
		case 'n':
			DebugToggle = (DebugToggle == 0);
			return FALSE;
		case 'S':
		case 's':
			Audio_Stop_All();
			return FALSE;
		case 'A':
		case 'a':
			CurrentDebugPage = DebugPages[5];
			CurrentDebugPage->Reset();
			CurrentDebugPage->Refresh(0, 0, 80, 25);
			return FALSE;
		case 'I':
		case 'i':
			CurrentDebugPage = DebugPages[7];
			CurrentDebugPage->Reset();
			CurrentDebugPage->Refresh(0, 0, 80, 25);
			return FALSE;
		case 'M':
		case 'm':
			CurrentDebugPage = DebugPages[6];
			CurrentDebugPage->Reset();
			CurrentDebugPage->Refresh(0, 0, 80, 25);
			return FALSE;
		case ',':
		case '<': {
			int next = CurrentDebugPage->Index + 1;
			if (next == 8) {
				next = 0;
			}
			CurrentDebugPage = DebugPages[next];
			CurrentDebugPage->Clear();
			CurrentDebugPage->Refresh(0, 0, 80, 25);
			return FALSE;
		}
		case '.':
		case '>': {
			int prev = CurrentDebugPage->Index - 1;
			if (prev < 0) {
				prev = 7;
			}
			CurrentDebugPage = DebugPages[prev];
			CurrentDebugPage->Clear();
			CurrentDebugPage->Refresh(0, 0, 80, 25);
			return FALSE;
		}
		default:
			return FALSE;
		}
	}
	if (msg == WM_COMMAND) {
		DebugShowPending = false;
		if (DebugWindow != NULL) {
			DebugVisible = false;
			ShowWindow(DebugWindow, SW_HIDE);
		}
		return TRUE;
	}
	return FALSE;
}


#pragma auto_inline(off) // level-2 1.001: the executable calls Reset out of line from the window procedure
void DebugPage::Reset(void) // level-2 1.001: 0x19B080, adopted from gibbo101 (DebugPage::Reset)
{
	Blank();
	Dirty = true;
	Refresh(0, 0, 80, 25);
}
#pragma auto_inline(on)


/// <summary>
/// Default constructor for the motion library.
/// This creates an empty library, ready to have an animation read into it.
/// </summary>
MotionLibrary::MotionLibrary() :
	LoadFailed(false),
	LayerCount(0),
	FrameCount(0),
	LayerMatrices(NULL)
{

}


/// <summary>
/// Constructor for the motion library that loads from a file.
/// This routine will read the animation held in the file specified.
/// </summary>
/// <remarks>A failure is recorded rather than reported, so check Load_Failed before
/// using the library.</remarks>
MotionLibrary::MotionLibrary(FileClass & file) :
	LoadFailed(false),
	LayerCount(0),
	FrameCount(0),
	LayerMatrices(NULL)
{
	if (!Read_File(file)) {
		LoadFailed = true;
	}
}


/// <summary>
/// Destructor for the motion library.
/// This will free the animation data that the library is holding.
/// </summary>
MotionLibrary::~MotionLibrary()
{
	Clear();
}


/// <summary>
/// Reads a voxel animation from the file specified.
/// This routine loads the per layer transformation matrices for every frame of the
/// animation. Anything this library was previously holding is discarded first, and the
/// file is closed before returning.
/// </summary>
/// <returns>bool; Was the animation read successfully?</returns>
BOOL MotionLibrary::Read_File(FileClass & file)
{
	Clear();

	bool result = file.Open(FileClass::READ) != 0;
	if (!result) {
		return(false);
	}

	VoxelAnimFileHeaderStruct header;

	file.Read(&header, sizeof(header));
	LayerCount = header.LayerCount;
	FrameCount = header.FrameCount;

	if (LayerMatrices != NULL) {	// RA2
		delete [] LayerMatrices;
	}
	LayerMatrices = new Matrix3D[FrameCount * LayerCount];	// RA2

	if (LayerMatrices == NULL) {
		LayerMatrices = NULL;
		file.Close();
		return(false);
	}

	file.Seek(MAX_VOXEL_NAME_LENGTH * LayerCount);

	for (unsigned frame = 0; frame < FrameCount; frame++) {
		for (unsigned layer = 0; layer < LayerCount; layer++) {
			float m[12];
			if (file.Read(&m, sizeof(m)) == sizeof(m)) {
				LayerMatrices[layer + frame * LayerCount] = Matrix3D(m);
			} else {
				file.Close();
				Clear();
				return(false);
			}
		}
	}

	file.Close();
	return(true);
}


/// <summary>
/// Scales the translation of every layer matrix.
/// Use this routine to bring an animation into the coordinate scale that the voxel
/// drawer expects. Only the translation part of each matrix is affected, so the layers
/// keep their orientation.
/// </summary>
void MotionLibrary::Scale(float scale)
{
	for (unsigned frame = 0; frame < FrameCount; frame++) {
		for (unsigned layer = 0; layer < LayerCount; layer++) {
			LayerMatrices[layer + frame * LayerCount][0].W = scale * LayerMatrices[layer + frame * LayerCount][0].W;
			LayerMatrices[layer + frame * LayerCount][1].W = scale * LayerMatrices[layer + frame * LayerCount][1].W;
			LayerMatrices[layer + frame * LayerCount][2].W = scale * LayerMatrices[layer + frame * LayerCount][2].W;
		}
	}
}


/// <summary>
/// Frees the layer transformation matrices.
/// This routine is used to release the animation data before another file is read into
/// this library, and by the destructor.
/// </summary>
void MotionLibrary::Clear()
{
	if (LayerMatrices != NULL) {
		delete [] LayerMatrices;
	}
	LayerMatrices = NULL;
}
