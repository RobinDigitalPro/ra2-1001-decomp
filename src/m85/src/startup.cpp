/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 *
 * Contains material derived from Electronic Arts source code.
 * Modified by OpenTS contributors, 2026.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 ******************************************************************************/

/* $Header: /counterstrike/STARTUP.CPP 6     3/15/97 7:18p Steve_tall $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : STARTUP.CPP                                                  *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : October 3, 1994                                              *
 *                                                                                             *
 *                  Last Update : September 30, 1996 [JLB]                                     *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   Prog_End -- Cleans up library systems in prep for game exit.                              *
 *   main -- Initial startup routine (preps library systems).                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// level-2 1.001: INFERRED helper for the INI section used by WinMain.
static inline char const * Intro_Section(void) // level-2 1.001: STEERING keep the configuration-file reload after depth-buffer allocation.
{
	return("Intro");
}

#define INCLUDE_COM
#include "always.h"
#include "geoconst1.h" // level-2 1.001: per-module geometry constants

#include "_alpha.h"
#include "_command.h"
#include "_convert.h"
#include "_font.h"
#include "_keyboar.h"
#include "_mixfile.h"
#include "_rect.h"
#include "_rules.h"
#include "_surface.h"
#include "_tactica.h"
#include "_winfix.h"
#include "_zbuffer.h"
#include "aircraft.h"
#include "airctype.h"
#include "aitrig.h"
#include "alphashp.h"
#include "anim.h"
#include "animtype.h"
#include "app.h"
#include "assert.h"
#include "blight.h"
#include "brain.h"
#include "building.h"
#include "builtype.h"
#include "bullet.h"
#include "bullettype.h"
#include "campaign.h"
#include "cd.h"
#include "cdcntrl.h"
#include "cell.h"
#include "classfactory.h"
#include "command.h"
#include "conquer.h"
#include "cstream.h"
#include "data.h"
#include "dbgprint.h"
#include "dllver.h"
#include "drive.h"
#include "droppod.h"
#include "dsaudio.h"
#include "dsurface.h"
#include "empulse.h"
#include "except.h"
#include "factory.h"
#include "fly.h"
#include "fog.h"
#include "goptions.h"
#include "house.h"
#include "houstype.h"
#include "hover.h"
#include "iblowfish.h"
#include "infantry.h"
#include "infatype.h"
#include "init.h"
#include "ionblast.h"
#include "ipxmgr.h"
#include "isotype.h"
#include "jumpjet.h"
#include "language\language.h"
#include "levitate.h"
#include "light.h"
#include "lightcon.h"
#include "mech.h"
#include "mixfile.h"
#include "movie.h"
#include "msgloop.h"
#include "netdlg.h" // for Shutdown_Network.
#include "overlay.h"
#include "overtype.h"
#include "ovrlight.h"
#include "particle.h"
#include "partsys.h"
#include "playcd.h"
#include "psystype.h"
#include "ptype.h"
#include "rules.h"
#include "scenario.h"
#include "scheme.h"
#include "script.h"
#include "session.h"
#include "shapeset.h"
#include "side.h"
#include "sidebar.h"
#include "smudge.h"
#include "smudtype.h"
#include "sun.h"
#include "super.h"
#include "suprtype.h"
#include "surface.h"
#include "tactical.h"
#include "taction.h"
#include "tag.h"
#include "tagtype.h"
#include "taskforc.h"
#include "team.h"
#include "teamtype.h"
#include "teleport.h"
#include "terrain.h"
#include "terrtype.h"
#include "tevent.h"
#include "theme.h"
#include "tiberium.h"
#include "trigger.h"
#include "trigtype.h"
#include "trim.h"
#include "tube.h"
#include "tunnel.h"
#include "unit.h"
#include "unittype.h"
#include "vanim.h"
#include "vanimtype.h"
#include "vector.h"
#include "walk.h"
#include "warhead.h"
#include "wave.h"
#include "waypoint.h"
#include "weapon.h"
#include "win.h"
#include "winstub.h"
#include "wwfont.h"
#include "wwmouse.h"
#include "zbuffer.h"
#include "bittext.h" // RA2: BitText
#include "temporal.h" // level-2 1.001: classes RegisterClasses registers in 1.001
#include "spawnmgr.h" // level-2 1.001: as above
#include "capmgr.h" // level-2 1.001: as above
#include "parasite.h" // level-2 1.001: as above
#include "bomb.h" // level-2 1.001: as above
#include "radsite.h" // level-2 1.001: as above
#include "rocket.h" // level-2 1.001: as above
#include "ship.h" // level-2 1.001: as above
#include "stringtable.h" // level-2 1.001: StringTable::Unload in Prog_End
#include "revent.h" // level-2 1.001: RadarEventClass::Clear in Prog_End
#include "planning.h" // level-2 1.001: Planning_Reset_Wrapper in Prog_End
#include "vox.h" // level-2 1.001: Speech_Free_All in Prog_End
#include "ramfile.h" // level-2 1.001: Init_Keys
#include "_pk.h" // level-2 1.001: Keys, FastKey

#include <conio.h>
#include <io.h>
#include <cfloat>
#include "geoconst2.h" // level-2 1.001: this module holds its own copy (per-TU constant addresses)



extern "C" {
	void __cdecl set_control_word(void);
};

bool VideoBackBufferAllowed = true;

// ---- local declarations (to be moved to headers by the integrator) ----
extern "C" const CLSID CLSID_BombClass; // level-2 1.001: declared locally in bomb.cpp
extern "C" const CLSID CLSID_ShipLocomotion; // level-2 1.001: declared locally in ship.cpp/building.cpp
extern ShapeSet * EndGameGraphicsShape; // level-2 1.001: 0xA292B4
extern ConvertClass * EndGameGraphicsConvert; // level-2 1.001: 0xA292B8
extern void * EndGameGraphicsPalette; // level-2 1.001: 0xA292B0, provisional name
extern CCINIClass UIINI; // level-2 1.001: 0x821BA0
extern CCINIClass INI_821A20; // level-2 1.001: 0x821A20, provisional name
extern MFCD * GenericMix; // level-2 1.001: 0x81F808
extern MFCD * IsoGenericMix; // level-2 1.001: 0x81F810
extern MFCD * NeutralMix; // level-2 1.001: 0x81F830
extern MFCD * Mix_81F818; // level-2 1.001: provisional name
extern MFCD * Mix_81F83C; // level-2 1.001: provisional name
extern MFCD * Mix_81F7FC; // level-2 1.001: provisional name
extern DynamicVectorClass<MFCD *> MixList_81F7C0; // level-2 1.001: provisional name
void Free_Scheme_Library(void); // level-2 1.001: 0x5FBB80, deletes TheSchemeLibrary; provisional name
void Func_59A6F0(void); // level-2 1.001: 0x59A6F0, provisional name
void Func_5E2F00(void); // level-2 1.001: 0x5E2F00, empty in 1.001; provisional name
void Free_All_Art(void); // level-2 1.001: 0x6E6E00
void Clear_Cycle_List(void); // level-2 1.001: 0x6EA7D0
void Load_Progress_Shutdown(void); // level-2 1.001: 0x533BD0
void Free_Mouse_Shapes(void); // level-2 1.001: 0x59CCE0
void Shutdown_Network_5B76A0(void); // level-2 1.001: 0x5B76A0 (netdlg2.cpp claims it as ?Shutdown_Network@@YIXXZ too; name clash)
void Audio_File_Shutdown(void); // level-2 1.001: 0x521E70
void Audio_Shutdown(void); // level-2 1.001: 0x406C80
void Kill_Mouse_Thread(void); // level-2 1.001: 0x75D2E0
namespace CopyProtection { void ShutDown(void); bool IsLauncherRunning(void); bool NotifyLauncher(void); } // level-2 1.001: 0x4918E0, 0x4916D0, 0x491710
int __fastcall Message_Box_Wide(HWND window, wchar_t const * text, wchar_t const * caption, unsigned int type); // level-2 1.001: 0x6EECE0 (strtable.cpp)
void Start_Mouse_Thread(void); // level-2 1.001: 0x75D120 (wwmouse.cpp)
HRESULT Init_Direct3D(void); // level-2 1.001: 0x4B1050 (dsurface.cpp)
int Get_Performance_Profile(void); // level-2 1.001: 0x519DF0 (init.cpp)
int Audio_File_Init(int count, int size); // level-2 1.001: 0x521AA0 (audfile.cpp)
int Audio_File_Create_Stream(char const * name); // level-2 1.001: 0x522190 (audfile.cpp)
int Audio_File_Open_Stream(char const * name); // level-2 1.001: 0x5221F0 (audfile.cpp)
void Free_Game_Modes(void); // level-2 1.001: 0x5B55D0 (multiplayer.cpp; src/ra2 names it MultiplayerGameMode::Free_Game_Modes)
void Func_59A570(HINSTANCE instance, HWND window, bool windowed); // level-2 1.001: 0x59A570, creates the eight buffers Func_59A6F0 frees; provisional name
extern int RecordPlayRequest; // level-2 1.001: 0xA292A4, 1 with -record, 2 with -play
extern int SidebarWidth; // level-2 1.001: 0x798C14
extern bool Debug_IngameModeChange;

// level-2 1.001: the WOLAPI registry options (HKLM\SOFTWARE\Westwood\WOLAPI, value "Options"), as in src/ra2/WOLPersonaInformation.cpp
class WOLAPIOptions {
public:
	WOLAPIOptions() : Flags(0), IsLoaded(false) { Load(); }
	bool Load(void);							// 0x4FE700
	bool Is_Option_1_Clear(void) const;			// 0x4FE7B0, true when bit 0 is clear (meaning unknown)
	bool Is_Option_2_Clear(void) const;			// 0x4FE7C0, true when bit 1 is clear (meaning unknown)
	bool Is_Option_4_Clear(void) const;			// 0x4FE7D0, true when bit 2 is clear (meaning unknown)
private:
	unsigned long Flags;
	bool IsLoaded;
};

extern	HINSTANCE LanguageResources;
extern void * MouseShapes; // RA2: 0xABD488, MOUSE.SHP as Init_Game loaded it
extern bool MouseShapesAllocated; // RA2: 0xABD48C, set when MouseShapes was allocated

#define APP_GUID "29e3bb2a-2f36-11d3-a72c-0090272fa661"
#define AUTOPLAY_GUID "01AF9993-3492-11d3-8F6F-0060089C05B1" // level-2 1.001: the 1.001 autoplay mutex


#ifndef NO_BLOWFISH_DLL
const struct RegStruct {
	const GUID *clsid;
	const char *name;
} RegisterTheseDLLs[] = {
	{ &CLSID_BlowfishObject, "blowfish.dll" }
};
#endif

HANDLE AppMutex;
HANDLE AutoPlayMutex;

DWORD dwRegisterTiberianSun;
DWORD dwRegisterMap = -1;
DWORD pTiberianSun;

DynamicVectorClass<DWORD> RegisteredClasses;

//WinTimerClass * WinTimer;

/// MSDN sample code

/// <summary>
/// Sets the default value of a registry key.
/// This is the low level routine that the server registration code uses to create a key
/// beneath HKEY_CLASSES_ROOT and give it a string value.
/// </summary>
/// <param name="pszKey">The key to create, relative to HKEY_CLASSES_ROOT.</param>
/// <param name="pszSubkey">The subkey to create beneath the key, or NULL for none.</param>
/// <param name="pszValue">The string to store as the key's default value, or NULL to
/// leave the value alone.</param>
/// <returns>bool; Was the key created and its value stored?</returns>
bool SetRegKeyValue(const LPCSTR pszKey, const LPCSTR pszSubkey, const LPCSTR pszValue)
{
	bool bOk = FALSE;
	LONG ec;
	HKEY hKey;
	TCHAR szKey[260];

	lstrcpy(szKey, pszKey);

	if (NULL != pszSubkey)
	{
		lstrcat(szKey, TEXT("\\"));
		lstrcat(szKey, pszSubkey);
	}

	ec = RegCreateKeyEx(HKEY_CLASSES_ROOT, szKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

	if (ERROR_SUCCESS == ec)
	{
		if (NULL != pszValue)
		{
			ec = RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE *)pszValue, (lstrlen(pszValue) + 1) * sizeof(TCHAR));
		}
		if (ERROR_SUCCESS == ec)
			bOk = TRUE;
		RegCloseKey(hKey);
	}

	return(bOk);
}


/// MSDN sample code

/// <summary>
/// Registers the game as a COM server.
/// This routine writes the ProgID, the version independent ProgID and the CLSID keys
/// that let OLE find the game by name, and loads the type library so that the interfaces
/// the game exposes are known to the system.
/// </summary>
/// <returns>Returns with the result code; this routine always reports success.</returns>
HRESULT RegisterServer(void)
{
	HRESULT hr = NOERROR;
	TCHAR szID[39 + 1];
	TCHAR szCLSID[48];
	TCHAR szLibID[39 + 1];
	WCHAR temp[39 + 1];
	TCHAR szModulePath[MAX_PATH];

	GetModuleFileName(ProgramInstance, szModulePath, sizeof(szModulePath) / sizeof(TCHAR));
	StringFromGUID2(CLSID_TiberianSun, temp, (sizeof(temp) / sizeof(WCHAR)) - 1);
	WideCharToMultiByte(0, 0, temp, -1, szID, (sizeof(temp) / sizeof(WCHAR)) - 1, 0, 0);
	StringFromGUID2(LIBID_TiberianSun, temp, (sizeof(temp) / sizeof(WCHAR)) - 1);
	WideCharToMultiByte(0, 0, temp, -1, szLibID, (sizeof(temp) / sizeof(WCHAR)) - 1, 0, 0);

	/// Create some base key strings.
	lstrcpy(szCLSID, TEXT("CLSID\\"));
	lstrcat(szCLSID, szID);

	/*
	 * Create ProgID keys.
	 */
	SetRegKeyValue(TEXT(GAME_PROGID), NULL, GAME_VERNAME);
	SetRegKeyValue(TEXT(GAME_PROGID), TEXT("CLSID"), szID);

	/*
	 * Create VersionIndependentProgID keys.
	 */
	SetRegKeyValue(TEXT(GAME_VPROGID), NULL, GAME_VERNAME);
	SetRegKeyValue(TEXT(GAME_VPROGID), TEXT("CurVer"), TEXT(GAME_PROGID));
	SetRegKeyValue(TEXT(GAME_VPROGID), TEXT("CLSID"), szID);

	/*
	 * Create entries under CLSID.
	 */
	SetRegKeyValue(szCLSID, NULL, GAME_VERNAME);
	SetRegKeyValue(szCLSID, TEXT("ProgID"), TEXT(GAME_PROGID));
	SetRegKeyValue(szCLSID, TEXT("VersionIndependentProgID"), TEXT(GAME_VPROGID));
	SetRegKeyValue(szCLSID, TEXT("NotInsertable"), NULL);
	SetRegKeyValue(szCLSID, TEXT("InprocServer32"), szModulePath);
	SetRegKeyValue(szCLSID, TEXT("Typelib"), szLibID);

	ITypeLib * pITypeLib = NULL;
	LoadTypeLib(L"RA2.TLB", &pITypeLib); // RA2: RegisterServer at 0x68DC70 matches only so
	if (pITypeLib != NULL) {
		pITypeLib->Release();
	}

	return(hr);
}


/// MSDN sample code

/// <summary>
/// Removes the game's registration from the system.
/// This routine undoes the work of RegisterServer, deleting the ProgID, the version
/// independent ProgID and the CLSID keys that the game claims for itself.
/// </summary>
/// <returns>Returns with the result code; this routine always reports success.</returns>
HRESULT UnregisterServer(void)
{
	HRESULT hr = NOERROR;
	TCHAR szCLSID[39 + 1 + 32];
	TCHAR szID[39 + 1];
	TCHAR szTemp[300];
	WCHAR temp[39 + 1];

	/// Create some base key strings.
	StringFromGUID2(CLSID_TiberianSun, temp, (sizeof(temp) / sizeof(WCHAR)) - 1);
	WideCharToMultiByte(0, WC_SEPCHARS, temp, -1, szID, (sizeof(temp) / sizeof(WCHAR)) - 1, 0, 0);
	lstrcpy(szCLSID, TEXT("CLSID\\"));
	lstrcat(szCLSID, szID);

	RegDeleteKey(HKEY_CLASSES_ROOT, TEXT(GAME_CURVER));
	RegDeleteKey(HKEY_CLASSES_ROOT, TEXT(GAME_VCLSID));
	RegDeleteKey(HKEY_CLASSES_ROOT, TEXT(GAME_VPROGID));

	RegDeleteKey(HKEY_CLASSES_ROOT, TEXT(GAME_CLSID));
	RegDeleteKey(HKEY_CLASSES_ROOT, TEXT(GAME_PROGID));

	wsprintf(szTemp, TEXT("%s\\%s"), szCLSID, TEXT("ProgID"));
	RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

	wsprintf(szTemp, TEXT("%s\\%s"), szCLSID, TEXT("VersionIndependentProgID"));
	RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

	wsprintf(szTemp, TEXT("%s\\%s"), szCLSID, TEXT("NotInsertable"));
	RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

	wsprintf(szTemp, TEXT("%s\\%s"), szCLSID, TEXT("InprocServer32"));
	RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

	wsprintf(szTemp, TEXT("%s\\%s"), szCLSID, TEXT("Typelib"));
	RegDeleteKey(HKEY_CLASSES_ROOT, szTemp);

	RegDeleteKey(HKEY_CLASSES_ROOT, szCLSID);

	return(hr);
}





/// <summary>
/// Destroys the drawing surfaces and drops the video mode.
/// This routine is used on the way out of the game so that the display is handed back to
/// Windows in a sane state, rather than left sitting in the game's own video mode.
/// </summary>
/// <remarks>It is safe to call this routine more than once; only the first call does any
/// work, since several shutdown paths lead here.</remarks>
void Reset_Surfaces(void)
{
	static bool surfaces_reset = false;
	if (UseDirect3D) { // RA2: RA2's form
		Release_Direct3D(); // RA2: as above
	}
	if (!surfaces_reset) {
		if (HiddenSurface != 0) { // RA2: as above
			delete HiddenSurface;
			HiddenSurface = 0; // RA2: as above
		}
		if (AlternateSurface != 0) { // RA2: as above
			delete AlternateSurface;
			AlternateSurface = 0; // RA2: as above
		}
		if (TileSurface != 0) { // RA2: as above
			delete TileSurface;
			TileSurface = 0; // RA2: as above
		}
		if (SidebarSurface != 0) { // RA2: as above
			delete SidebarSurface;
			SidebarSurface = 0; // RA2: as above
		}
		if (CompositeSurface != 0) { // RA2: as above
			delete CompositeSurface;
			CompositeSurface = 0; // RA2: as above
		}
		if (VisibleSurface != 0) { // RA2: as above
			delete VisibleSurface;
			VisibleSurface = 0; // RA2: as above
		}
		Reset_Video_Mode();
		surfaces_reset = true;
	}
}



/// <summary>
/// Handles any exception that escapes the game.
/// This routine is installed as the top level exception filter for the process, so that
/// a crash is reported by the game's own exception handler rather than by Windows.
/// </summary>
/// <returns>Returns with the disposition that the exception handler decided upon.</returns>
LONG Top_Level_Exception_Filter(EXCEPTION_POINTERS *e_info)
{
	return(Exception_Handler(e_info->ExceptionRecord->ExceptionCode, e_info));
}













/// <summary>
/// Registers the game's COM classes with OLE.
/// This routine is called during startup, before anything that lives in the object
/// database can be created. It first ensures the support DLLs are present, asking any
/// that OLE cannot yet instantiate to register themselves, and then publishes a class
/// factory for every persistent game class so that objects can be created by CLSID. The
/// player is told by way of a message box if a support DLL could not be prepared.
/// </summary>
/// <returns>bool; Did the preparation fail? Note the sense -- true means trouble.</returns>
/***********************************************************************************************
 * Init_Keys -- Initialize the cryptographic keys.                                             *
 *                                                                                             *
 *    level-2 1.001: WinMain expands this after RegisterClasses; it reads the public key from  *
 *    the embedded key text into FastKey.                                                      *
 *=============================================================================================*/
static void Init_Keys(void)
{
	DebugString("Init_Keys - declarations\n");
	RAMFileClass file((void*)Keys, strlen(Keys));
	INIClass ini;

	DebugString("Init_Keys - Load\n");
	ini.Load(file, false);

	DebugString("Init_Keys - Init fast key\n");
	FastKey = ini.Get_PKey(true);
}


static bool RegisterClasses(void)
{

	bool failed = false;
#ifndef NO_BLOWFISH_DLL
	for (int i = 0; i < ARRAY_SIZE(RegisterTheseDLLs); i++) {
		IUnknownPtr ptr;
		HRESULT result = ptr.CreateInstance(*RegisterTheseDLLs[i].clsid, NULL, CLSCTX_ALL);
		failed = FAILED(result);
		if (failed) {
			failed = false;
			HINSTANCE hModule = LoadLibrary(RegisterTheseDLLs[i].name);
			if (hModule != NULL) {
				FARPROC fprocDllReg = (FARPROC)GetProcAddress(hModule, "DllRegisterServer");
				if (!fprocDllReg || (fprocDllReg(), FAILED(ptr.CreateInstance(*RegisterTheseDLLs[i].clsid, NULL, CLSCTX_ALL)))) {
					failed = true;
				}
				FreeLibrary(hModule);
			} else {
				failed = true;
			}
		}
		if (failed) {
			break;
		}
		ptr.Release();
	}
#endif

	RegisterServer();

	DWORD dwRegister;
	IClassFactory *factory; // level-2 1.001: INFERRED name (was t); names decide WinMain's SEH frame slots, and this one gives the 1.001 slot before failed

	/// Handy macros to easily register the class factories.

	/// Register a class-object with OLE.
	#define REGISTER_CLASS(_class, _clsid) \
		{ \
			factory = new TClassFactory<_class>; \
			CoRegisterClassObject(_clsid, factory, CLSCTX_INPROC_SERVER, REGCLS_MULTIPLEUSE, &dwRegister); \
			RegisteredClasses.Add(dwRegister); \
		} \

	/// Register a class-object with OLE (precreated factory).
	#define REGISTER_FACT_CLASS(_class, _fact, _clsid) \
		{ \
			factory = _fact; \
			CoRegisterClassObject(_clsid, factory, CLSCTX_INPROC_SERVER, REGCLS_MULTIPLEUSE, &dwRegister); \
			RegisteredClasses.Add(dwRegister); \
		}

	REGISTER_FACT_CLASS(TiberianSunClassFactory, &TibSunFactory, CLSID_TiberianSun);

	REGISTER_CLASS(CStreamClass, CLSID_CompressStream);
	REGISTER_CLASS(WaveClass, CLSID_WaveClass);
	REGISTER_CLASS(TerrainTypeClass, CLSID_TerrainTypeClass);
	REGISTER_CLASS(TerrainClass, CLSID_TerrainClass);
	REGISTER_CLASS(SuperWeaponTypeClass, CLSID_SuperWeaponTypeClass);
	REGISTER_CLASS(SuperClass, CLSID_SuperWeaponClass);
	REGISTER_CLASS(Tactical, CLSID_TacticalMapClass);
	REGISTER_CLASS(CellClass, CLSID_CellClass);
	REGISTER_CLASS(EMPulseClass, CLSID_EMPulseClass);
	REGISTER_CLASS(LightSourceClass, CLSID_LightSource);
	REGISTER_CLASS(SideClass, CLSID_SideClass);
	REGISTER_CLASS(TiberiumClass, CLSID_TiberiumClass);
	REGISTER_CLASS(TubeClass, CLSID_TubeClass);
	REGISTER_CLASS(CampaignClass, CLSID_CampaignClass);
	REGISTER_CLASS(BuildingLightClass, CLSID_BuildingLightClass);
	REGISTER_CLASS(WaypointPathClass, CLSID_WaypointPath);
	REGISTER_CLASS(TemporalClass, CLSID_TemporalClass); // level-2 1.001: factories 0x6883D0..0x688B50 follow WaypointPath
	REGISTER_CLASS(SpawnManagerClass, CLSID_SpawnManagerClass); // level-2 1.001: as above
	REGISTER_CLASS(CaptureManagerClass, CLSID_CaptureManagerClass); // level-2 1.001: as above
	REGISTER_CLASS(ParasiteClass, CLSID_ParasiteClass); // level-2 1.001: as above
	REGISTER_CLASS(BombClass, CLSID_BombClass); // level-2 1.001: as above
	REGISTER_CLASS(RadSiteClass, CLSID_RadSiteClass); // level-2 1.001: as above
	REGISTER_CLASS(TEventClass, CLSID_EventClass);
	REGISTER_CLASS(VoxelAnimTypeClass, CLSID_VoxelAnimTypeClass);
	REGISTER_CLASS(VoxelAnimClass, CLSID_VoxelAnimClass);
	REGISTER_CLASS(TActionClass, CLSID_ActionClass);
	REGISTER_CLASS(TriggerClass, CLSID_TriggerClass);
	REGISTER_CLASS(TriggerTypeClass, CLSID_TriggerTypeClass);
	REGISTER_CLASS(ScriptClass, CLSID_ScriptClass);
	REGISTER_CLASS(ScriptTypeClass, CLSID_ScriptTypeClass);
	REGISTER_CLASS(TagClass, CLSID_TagClass);
	REGISTER_CLASS(TagTypeClass, CLSID_TagTypeClass);
	REGISTER_CLASS(TeamClass, CLSID_TeamClass);
	REGISTER_CLASS(TeamTypeClass, CLSID_TeamTypeClass);
	REGISTER_CLASS(TaskForceClass, CLSID_TaskForceClass);
	REGISTER_CLASS(UnitTypeClass, CLSID_UnitTypeClass);
	REGISTER_CLASS(BuildingTypeClass, CLSID_BuildingTypeClass);
	REGISTER_CLASS(AircraftTypeClass, CLSID_AircraftTypeClass);
	REGISTER_CLASS(InfantryTypeClass, CLSID_InfantryTypeClass);
	REGISTER_CLASS(BulletTypeClass, CLSID_BulletTypeClass);
	REGISTER_CLASS(IsometricTileTypeClass, CLSID_IsometricTileTypeClass);
	REGISTER_CLASS(OverlayTypeClass, CLSID_OverlayTypeClass);
	REGISTER_CLASS(SmudgeTypeClass, CLSID_SmudgeTypeClass);
	REGISTER_CLASS(UnitClass, CLSID_UnitClass);
	REGISTER_CLASS(BuildingClass, CLSID_BuildingClass);
	REGISTER_CLASS(AircraftClass, CLSID_AircraftClass);
	REGISTER_CLASS(InfantryClass, CLSID_InfantryClass);
	REGISTER_CLASS(AnimClass, CLSID_AnimClass);
	REGISTER_CLASS(AnimTypeClass, CLSID_AnimTypeClass);
	REGISTER_CLASS(HouseTypeClass, CLSID_HouseTypeClass);
	REGISTER_CLASS(HouseClass, CLSID_HouseClass);
	REGISTER_CLASS(DriveLocomotionClass, CLSID_DriveLocomotion);
	REGISTER_CLASS(JumpjetLocomotionClass, CLSID_JumpjetLocomotion);
	REGISTER_CLASS(HoverLocomotionClass, CLSID_HoverLocomotion);
	REGISTER_CLASS(RocketLocomotionClass, CLSID_RocketLocomotion); // level-2 1.001: factory 0x68BCD0
	REGISTER_CLASS(TunnelLocomotionClass, CLSID_TunnelLocomotion);
	REGISTER_CLASS(WalkLocomotionClass, CLSID_WalkLocomotion);
	REGISTER_CLASS(DropPodLocomotionClass, CLSID_BallisticLocomotion);
	REGISTER_CLASS(FlyLocomotionClass, CLSID_FlyerLocomotion);
	REGISTER_CLASS(TeleportLocomotionClass, CLSID_TeleportLocomotion);
	REGISTER_CLASS(MechLocomotionClass, CLSID_MechLocomotion);
	REGISTER_CLASS(ShipLocomotionClass, CLSID_ShipLocomotion); // level-2 1.001: factory 0x68C750; 1.001 registers no LevitateLocomotionClass
	REGISTER_CLASS(BulletClass, CLSID_BulletClass);
	REGISTER_CLASS(FactoryClass, CLSID_FactoryClass);
	REGISTER_CLASS(WarheadTypeClass, CLSID_WarheadTypeClass);
	REGISTER_CLASS(WeaponTypeClass, CLSID_WeaponTypeClass);
	REGISTER_CLASS(ParticleClass, CLSID_ParticleClass);
	REGISTER_CLASS(ParticleTypeClass, CLSID_ParticleTypeClass);
	REGISTER_CLASS(ParticleSystemClass, CLSID_ParticleSystemClass);
	REGISTER_CLASS(ParticleSystemTypeClass, CLSID_ParticleSystemTypeClass);
	REGISTER_CLASS(AITriggerTypeClass, CLSID_AITriggerTypeClass);
	REGISTER_CLASS(NeuronClass, CLSID_NeuronClass);
	REGISTER_CLASS(FoggedObjectClass, CLSID_FoggedObjectClass);
	REGISTER_CLASS(AlphaShapeClass, CLSID_AlphaShapeClass);

	RegisterActiveObject((IUnknown *)&ApplicationInstance, CLSID_TiberianSun, ACTIVEOBJECT_WEAK, &dwRegisterTiberianSun);

	if (failed) {
		Message_Box_Wide(NULL, StringTable::LoadString("TXT_PREPARECOM_FAILED", NULL, "C:\\RA2\\Startup.CPP", 1518), StringTable::LoadString("TXT_SHORT_TITLE", NULL, "C:\\RA2\\Startup.CPP", 1518), MB_ICONEXCLAMATION); // level-2 1.001: wide text, line 1518
	}

	return(failed);

}




static void Read_Setup_Options(RawFileClass * config_file);

/***********************************************************************************************
 * main -- Initial startup routine (preps library systems).                                    *
 *                                                                                             *
 *    This is the routine that is first called when the program starts up. It basically        *
 *    handles the command line parsing and setting up library systems.                         *
 *                                                                                             *
 * INPUT:   argc  -- Number of command line arguments.                                         *
 *                                                                                             *
 *          argv  -- Pointer to array of command line argument strings.                        *
 *                                                                                             *
 * OUTPUT:  Returns with execution failure code (if any).                                      *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   03/20/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
int CALLBACK WinMain ( HINSTANCE instance , HINSTANCE , char * command_line , int command_show )
{
	int		argc;       //Command line argument count
	char *	argv[20];   //Pointers to command line arguments
	char	path_to_exe[132];
	wchar_t	buffer[512]; // level-2 1.001: the message texts are wide (string table)

#ifdef STEVES_NEW_CATCHER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
#endif

	ProgramInstance = instance;

	MainThread = (HANDLE)GetCurrentThreadId();

	/*
	** level-2 1.001: the 1.001 size report has 56 entries (lines 1560..1615). The sizes are
	** the 1.001 class sizes, which the 1.006 headers do not reproduce, so they are given as
	** values; the class in each comment is the 1.006 list entry at the same position.
	*/
#line 1560
	DebugString("%d-%d\n", __LINE__, 0x98);		// CrateData
	DebugString("%d-%d\n", __LINE__, 0x4C);		// CrateShares
	DebugString("%d-%d\n", __LINE__, 0x4C);		// CrateAnims
	DebugString("%d-%d\n", __LINE__, 0x13);		// level-2 1.001: an entry the 1.006 list lacks (unidentified)
	DebugString("%d-%d\n", __LINE__, 0xE18);	// Tactical
	DebugString("%d-%d\n", __LINE__, 0x5C0);	// AircraftClass
	DebugString("%d-%d\n", __LINE__, 0xBA8);	// AircraftTypeClass
	DebugString("%d-%d\n", __LINE__, 0x110);	// AITriggerTypeClass
	DebugString("%d-%d\n", __LINE__, 0x1A8);	// AnimClass
	DebugString("%d-%d\n", __LINE__, 0x330);	// AnimTypeClass
	DebugString("%d-%d\n", __LINE__, 0x78);		// BaseClass
	DebugString("%d-%d\n", __LINE__, 0x5E0);	// BuildingClass
	DebugString("%d-%d\n", __LINE__, 0x1418);	// BuildingTypeClass
	DebugString("%d-%d\n", __LINE__, 0x148);	// BulletClass
	DebugString("%d-%d\n", __LINE__, 0x2C8);	// BulletTypeClass
	DebugString("%d-%d\n", __LINE__, 0x148);	// CellClass
	DebugString("%d-%d\n", __LINE__, 0x70);		// FactoryClass
	DebugString("%d-%d\n", __LINE__, 0x15F90);	// HouseClass
	DebugString("%d-%d\n", __LINE__, 0x1B0);	// HouseTypeClass
	DebugString("%d-%d\n", __LINE__, 0x5D8);	// InfantryClass
	DebugString("%d-%d\n", __LINE__, 0xC18);	// InfantryTypeClass
	DebugString("%d-%d\n", __LINE__, 0x18);		// LayerClass
	DebugString("%d-%d\n", __LINE__, 0x4F3C);	// MouseClass
	DebugString("%d-%d\n", __LINE__, 0xE18);	// MapEditTactical
	DebugString("%d-%d\n", __LINE__, 0x9C);		// OverlayClass
	DebugString("%d-%d\n", __LINE__, 0x288);	// OverlayTypeClass
	DebugString("%d-%d\n", __LINE__, 0x9C);		// SmudgeClass
	DebugString("%d-%d\n", __LINE__, 0x274);	// SmudgeTypeClass
	DebugString("%d-%d\n", __LINE__, 0xD4);		// TaskForceClass
	DebugString("%d-%d\n", __LINE__, 0x9C);		// TeamClass
	DebugString("%d-%d\n", __LINE__, 0xF0);		// TeamTypeClass
	DebugString("%d-%d\n", __LINE__, 0xC8);		// TerrainClass
	DebugString("%d-%d\n", __LINE__, 0x28C);	// TerrainTypeClass
	DebugString("%d-%d\n", __LINE__, 0x44);		// TriggerClass
	DebugString("%d-%d\n", __LINE__, 0xB4);		// TriggerTypeClass
	DebugString("%d-%d\n", __LINE__, 0xA4);		// TagTypeClass
	DebugString("%d-%d\n", __LINE__, 0x38);		// TagClass
	DebugString("%d-%d\n", __LINE__, 0x7D0);	// UnitClass
	DebugString("%d-%d\n", __LINE__, 0xC10);	// UnitTypeClass
	DebugString("%d-%d\n", __LINE__, 0x2460);	// ScenarioClass
	DebugString("%d-%d\n", __LINE__, 0xEC);		// SuperWeaponTypeClass
	DebugString("%d-%d\n", __LINE__, 0x68);		// SuperClass
	DebugString("%d-%d\n", __LINE__, 0x1B0);	// Ground
	DebugString("%d-%d\n", __LINE__, 0x14C0);	// RulesClass
	DebugString("%d-%d\n", __LINE__, 0x3C0);	// MissionControl
	DebugString("%d-%d\n", __LINE__, 1);
	DebugString("%d-%d\n", __LINE__, 0x418);	// TechnoClass
	DebugString("%d-%d\n", __LINE__, 0xD8);		// RadioClass
	DebugString("%d-%d\n", __LINE__, 0xBC);		// MissionClass
	DebugString("%d-%d\n", __LINE__, 8);
	DebugString("%d-%d\n", __LINE__, 0x18);		// StageClass
	DebugString("%d-%d\n", __LINE__, 8);
	DebugString("%d-%d\n", __LINE__, 8);
	DebugString("%d-%d\n", __LINE__, 0x10);		// StorageClass
	DebugString("%d-%d\n", __LINE__, 0x20);		// DelayTimerClass
	DebugString("%d-%d\n", __LINE__, 0x18);		// FacingClass

	/*
	** level-2 1.001: the game only runs when it was started by the launcher.
	*/
	if (!CopyProtection::IsLauncherRunning()) {
		DebugString("Launcher not running....Bail!\n");
		return(EXIT_SUCCESS);
	}

	/*
	 * Create a mutex with a unique name to TibSun in order to determine if
	 * our app is already running.
	 *
	 * WARNING: DO NOT use this number for any other application except TibSun
	 */
	AppMutex = ::CreateMutex (NULL, FALSE, APP_GUID);

	//
	// Is there already an instance of this app somewhere?
	//
	if (::GetLastError () == ERROR_ALREADY_EXISTS) {
		//
		// Find the previous instance
		//
		HWND main_wnd = ::FindWindow (APP_GUID, NULL);
		if (main_wnd != NULL) {
			::SetForegroundWindow (main_wnd);
			::ShowWindow (main_wnd, SW_RESTORE);
		}
		if (AppMutex != NULL) {
			CloseHandle(AppMutex);
			AppMutex = NULL;
		}
		DebugString("TibSun is already running...Bail!\n");
		return(EXIT_SUCCESS);
	} else {

		DebugString("Create AppMutex okay.\n");

		//
		// Obtain the mutex unique to the Renegade AutoPlay application.
		//
		// WARNING: DO NOT use this number for any other application except Renegade AutoPlay
		//
		do
		{
			//
			// Attempt to open the mutex
			//
			AutoPlayMutex = ::OpenMutex (MUTEX_ALL_ACCESS, FALSE, AUTOPLAY_GUID);
			if (AutoPlayMutex != NULL) {
				DebugString( "Waiting for Autoplay to quit!\n");
				if (::WaitForSingleObject (AutoPlayMutex, 30000) == WAIT_FAILED) {
					DebugString ("Failed waiting for AutoPlayMutex\n");
					::CloseHandle (AutoPlayMutex);
					AutoPlayMutex = NULL;
				}
			}

			/*
			 * Create a mutex with a name unique to the TibSun AutoPlay application.
			 * This prevents the autoplay from running since it cannot get the mutex.
			 * TibSun needs both of these mutexs before it is allowed to run.
			 */
			if (AutoPlayMutex == NULL) {
				AutoPlayMutex = CreateMutex (NULL, FALSE, AUTOPLAY_GUID);
				if (GetLastError () == ERROR_ALREADY_EXISTS) {
					CloseHandle (AutoPlayMutex);
					AutoPlayMutex = NULL;
					Sleep (2500);
				} else {
					DebugString("Create AutoPlayMutex.\n");
				}
			}
		} while (AutoPlayMutex == NULL);

		DebugString ("Got AutoPlayMutex okay.\n");
	}

	_controlfp(_RC_CHOP, MCW_RC);
	set_control_word();

	/*
	**	Get the full path to the .EXE
	*/
	GetModuleFileName (instance, &path_to_exe[0], sizeof(path_to_exe));

	/*
	**	First argument is supposed to be a pointer to the .EXE that is running
	**
	*/
	argc=1;                     //Set argument count to 1
	argv[0]=&path_to_exe[0];    //Set 1st command line argument to point to full path

	/*
	**	Get pointers to command line arguments just like if we were in DOS
	**
	*/
	char *token = strtok(command_line, " ");
	while (argc < ARRAY_SIZE(argv) && token != NULL) {
		argv[argc++] = strtrim(token);
		token = strtok(NULL, " ");
	}

	/*
	**	Change directory to the where the executable is located. Handle the
	**	case where there is no path attached to argv[0].
	*/
	char drive[_MAX_DRIVE];
	char path[_MAX_PATH];
	char dir[_MAX_DIR];
	_splitpath(argv[0], drive, dir, NULL, NULL);
	_makepath(path, drive, dir, NULL, NULL);
	SetCurrentDirectory(path);

	int retval = EXIT_FAILURE; // level-2 1.001: local names decide SEH frame slots; retval and fileptr give the 1.001 slots (were error_code, cfile)

	if (Parse_Command_Line(argc, argv)) {

		RawFileClass *fileptr = new RawFileClass(CONFIG_FILE_NAME);

		/*
		** Set the options as requested by the setup program
		*/
		Read_Setup_Options(fileptr); // level-2 1.001: INFERRED single-caller helper (RA1 STARTUP.CPP form), expanded inline here

		Keyboard = new KeyboardClass();

		/*
		**	If there is not enough disk space free, don't allow the product to run.
		*/
		if (Disk_Space_Available() < INIT_FREE_DISK_SPACE) {
			swprintf(buffer, StringTable::LoadString("TXT_CRITICALLY_LOW", NULL, "C:\\RA2\\Startup.CPP", 1830), (INIT_FREE_DISK_SPACE) / (1024 * 1024)); // level-2 1.001: wide text, line 1830
			int reply = Message_Box_Wide(NULL, buffer, StringTable::LoadString("TXT_SHORT_TITLE", NULL, "C:\\RA2\\Startup.CPP", 1831), MB_ICONQUESTION|MB_YESNO); // level-2 1.001: as above, line 1831
			if (reply == IDNO) {
				OleUninitialize();
				return(EXIT_FAILURE);
			}
		}

		OleInitialize(NULL); // level-2 1.001: COM is prepared after the configuration is read

		if (RegisterClasses()) {
			exit(EXIT_FAILURE);
		}

		DebugString("Init Encryption Keys.\n"); // level-2 1.001: the keys are prepared here
		Init_Keys();

		/*
		** level-2 1.001: LANGUAGE.MIX is opened from the local disk before the string table is read.
		*/
		DiskID cd = CD::Get_Required_Disk();
		CD::Set_Required_Disk(DISK_LOCAL);
		Mix_81F7FC = new MFCD("LANGUAGE.MIX", &FastKey);
		CD::Set_Required_Disk(cd);

		atexit(Prog_End);

		Start_Mouse_Thread(); // level-2 1.001: as above

		if (!StringTable::LoadFile("ra2.str")) { // level-2 1.001: as above
			MessageBox(NULL, "Unable to initialize 'ra2.csf', please reinstall Red Alert.\nKeine Initialisierung von 'ra2.csf' m\xf6glich. Bitte installieren Sie Red Alert erneut.\nInitialisation de 'ra2.csf' impossible. Veuillez r\xe9installer Red Alert.", "Red Alert 2", MB_ICONERROR);
			return(EXIT_SUCCESS);
		}

		if (!Init_Language_Resources(true)) {
			return(EXIT_SUCCESS);
		}

		if (!GetSystemMetrics(SM_MOUSEPRESENT) || !GetSystemMetrics(SM_CMOUSEBUTTONS)) {
			Message_Box_Wide(NULL, StringTable::LoadString("TXT_MOUSE_REQUIRED", NULL, "C:\\RA2\\Startup.CPP", 1894), StringTable::LoadString("TXT_SHORT_TITLE", NULL, "C:\\RA2\\Startup.CPP", 1894), MB_ICONERROR); // level-2 1.001: line 1894
			exit(EXIT_FAILURE);
		}

		if (GetDllVersion("comctl32.dll") < PACKVERSION(4, 70)) {
			swprintf(buffer, StringTable::LoadString("TXT_DLL_INVALID", NULL, "C:\\RA2\\Startup.CPP", 1904), "comctl32.dll", 4, 70, "comctl32.dll"); // level-2 1.001: line 1904
			Message_Box_Wide(NULL, buffer, StringTable::LoadString("TXT_SHORT_TITLE", NULL, "C:\\RA2\\Startup.CPP", 1905), MB_ICONERROR); // level-2 1.001: line 1905
			exit(EXIT_FAILURE);
		}

		RegisterActiveObject((IUnknown *)&Map, CLSID_TiberianSun, ACTIVEOBJECT_WEAK, &dwRegisterMap);

		if (Options.ScreenWidth == -1 || Options.ScreenHeight == -1) {
			Options.ScreenWidth = 640;

			if (WinVersion.Is_WinNTx() || GetVideoMemory() > 0x200000) {
				Options.ScreenHeight = 480;
			} else {
				Options.ScreenHeight = 400;
			}
		}

		BOOL video_success = FALSE;

		if (Debug_IngameModeChange) {
			Create_Main_Window(instance, command_show, 640, 400);
			Prep_Direct_Draw(); // level-2 1.001: the audio is not started here
			if (WindowedMode) {
				VisibleRect = Rect(0,0,640,400);
				VideoModeWidth = VisibleRect.Width;
				VideoModeHeight = VisibleRect.Height;
				VideoModeBitsPerPixel = HicolorFlag ? 16 : 8;
			} else {
				/*
				** Set 640x400 video mode. If its not available then try for 640x480
				*/
				VisibleRect = Rect(0,0,640,400);
				video_success = Set_Video_Mode(MainWindow, 640, 400, HicolorFlag ? 16 : 8);
				if (!video_success) {
					video_success = Set_Video_Mode(MainWindow, 640, 480, HicolorFlag ? 16 : 8);
					VisibleRect = Rect(0,0,640,480);
					if (!video_success) {
						Destroy_Direct_Draw();
						Message_Box_Wide(MainWindow, StringTable::LoadString("TXT_VIDEO_ERROR", NULL, "C:\\RA2\\Startup.CPP", 2048), StringTable::LoadString("TXT_SHORT_TITLE", NULL, "C:\\RA2\\Startup.CPP", 2049), MB_ICONWARNING); // level-2 1.001: lines 2048/2049
						exit(EXIT_FAILURE);
					}
				}
			}
		} else {
			Create_Main_Window(instance, command_show, Options.ScreenWidth, Options.ScreenHeight);
			Prep_Direct_Draw();
			if (WindowedMode) {
				VisibleRect = Rect(0,0,Options.ScreenWidth,Options.ScreenHeight);
				VideoModeWidth = Options.ScreenWidth;
				VideoModeHeight = Options.ScreenHeight;
				VideoModeBitsPerPixel = HicolorFlag ? 16 : 8;
			} else {
				/*
				 * Set desired video mode. If its not available then try for 640x480
				 */
				video_success = Set_Video_Mode(MainWindow, Options.ScreenWidth, Options.ScreenHeight, HicolorFlag ? 16 : 8);
				VisibleRect = Rect(0,0,Options.ScreenWidth,Options.ScreenHeight);
				if (!video_success) {
					if (Options.ScreenWidth != 640 || Options.ScreenHeight != 480) {
						Options.ScreenWidth = 640;
						Options.ScreenHeight = 480;
						video_success = Set_Video_Mode(MainWindow, Options.ScreenWidth, Options.ScreenHeight, HicolorFlag ? 16 : 8);
						VisibleRect = Rect(0,0,Options.ScreenWidth,Options.ScreenHeight);
					}
					if (!video_success) {
						Destroy_Direct_Draw();
						Message_Box_Wide(MainWindow, StringTable::LoadString("TXT_VIDEO_ERROR", NULL, "C:\\RA2\\Startup.CPP", 2087), StringTable::LoadString("TXT_SHORT_TITLE", NULL, "C:\\RA2\\Startup.CPP", 2088), MB_ICONWARNING); // level-2 1.001: lines 2087/2088
						exit(EXIT_FAILURE);
					}
				}
			}
		}

		/*
		** level-2 1.001: -record and -play open the session recording here.
		*/
		if (RecordPlayRequest && Audio_File_Init(1000, 0x19000)) {
			if (RecordPlayRequest == 1) {
				Audio_File_Create_Stream("session.ipb");
			} else if (RecordPlayRequest == 2) {
				Audio_File_Open_Stream("session.ipb");
			}
		}

		VisibleSurface = DSurface::Create_Primary();

		int visible_bpp = VisibleSurface->Bytes_Per_Pixel();
		HicolorFlag = visible_bpp == 2;
		if (!HicolorFlag) {
			Message_Box_Wide(MainWindow, StringTable::LoadString("TXT_INVALIDMODE", NULL, "C:\\RA2\\Startup.CPP", 2117), StringTable::LoadString("TXT_SHORT_TITLE", NULL, "C:\\RA2\\Startup.CPP", 2117), MB_ICONEXCLAMATION); // level-2 1.001: line 2117
			Emergency_Exit();
		}

		if (!CopyProtection::NotifyLauncher()) { // level-2 1.001: as above
			DebugString("Failed to notify launcher\n");
			exit(EXIT_FAILURE);
		}

		do {
			Windows_Message_Handler();
		}
		while (!GameInFocus);

		SurfacesRestored = false;

		if (!WindowedMode) {
			VisibleSurface->Fill(0);
		}

		Func_59A570(ProgramInstance, MainWindow, WindowedMode); // level-2 1.001: as above
		Planning_Reset(); // level-2 1.001: as above

		/*
		** level-2 1.001: INFERRED form. The composite, tile and sidebar rectangles are temporaries
		** of this call (the sidebar width is a variable). In 1.001's SEH frame they sit among the
		** temporaries, below every named local, in the order sidebar, tile, composite; named Rect
		** locals sort by name among the named locals instead. gibbo101's YR 1.001 WinMain notes
		** report the same form ("Rect temporaries straight into Allocate_Surfaces").
		*/
		Allocate_Surfaces(VisibleRect, Rect(0,0,VisibleRect.Width-SidebarWidth, VisibleRect.Height), Rect(0,0,VisibleRect.Width-SidebarWidth, VisibleRect.Height), Rect(0,0,SidebarWidth,VisibleRect.Height), false);
		if (UseDirect3D) { // level-2 1.001: as above
			Init_Direct3D();
		}
		LogicalSurface = HiddenSurface;
		Update_Visible_Surface(true, HiddenSurface);

		/*
		** level-2 1.001: INFERRED named alias for the new depth buffer. It is the one 4-byte named
		** local of this block that 1.001's frame has beyond ours, and calling Set_Scroll through a
		** local drops the inline expansion's `this` slot at the bottom of the frame, which 1.001
		** also lacks (frame 0xe0c). The code is identical to `DepthBuffer->Set_Scroll(...)`.
		** gibbo101's YR 1.001 WinMain needed a zbuf alias local here as well.
		*/
		ZBuffer * zbufptr = DepthBuffer = new ZBuffer(Rect(TacticalRect.X, TacticalRect.Y, 480, 480 - TacticalRect.Y));
		zbufptr->Set_Scroll(ZBUFFER_MAX);

		AlphaBuffer = new ABuffer(Rect(TacticalRect.X, TacticalRect.Y, 480, 480 - TacticalRect.Y));

		MouseCursor = new WWMouseClass(VisibleSurface, MainWindow);
		MouseCursor->Hide_Mouse(); // level-2 1.001: the mouse is hidden here, not captured

		CDFileClass::Set_CD_Drive (CDList.Get_First_CD_Drive());

		/*
		**	Check for forced intro movie run disabling. If the conquer
		**	configuration file says "no", then don't run the intro.
		*/
		DiskID diskid = CD::Get_Current_Disk(60); // RA2: a 60 timeout; level-2 1.001: INFERRED name (was disk), see wolopt
		Get_Performance_Profile(); // level-2 1.001: as above
		if (!Special.IsFromInstall && diskid > DISK_ANY) { // level-2 1.001: one Play key for every disk
			Special.IsFromInstall = ConfigINI.Get_Bool(Intro_Section(), "Play", true); // level-2 1.001: STEERING use the shared intro section.
		}

		/*
		** level-2 1.001: the WOLAPI registry options set IsEscapeMovies. INFERRED names: in this SEH
		** function local names decide the frame order (OPEN_PATTERNS, local names). 1.001 has wolopt
		** at -0x720 above video_success at -0x724, and fileptr at -0x70c directly below visible_bpp;
		** the names wolopt, diskid and zbufptr give that layout (disk/wolapi did not).
		*/
		WOLAPIOptions wolopt;
		if (!wolopt.Is_Option_1_Clear() && !wolopt.Is_Option_4_Clear() && !wolopt.Is_Option_2_Clear()) {
			Special.IsEscapeMovies = true;
		}

		/*
		**	Regardless of whether we should run it or not, here we're
		**	gonna change it to say "no" in the future.
		*/
		if (Special.IsFromInstall == true) {
			if (diskid > DISK_ANY) {
				Special.IsFromInstall = ConfigINI.Put_Bool(Intro_Section(), "Play", false); // level-2 1.001: STEERING use the shared intro section.
			}
			fileptr->Close();
			fileptr->Open(FileClass::READ);
			ConfigINI.Save(*fileptr, false);
		}

		fileptr->Close();
		delete fileptr;

		if (NoExceptionHandler) {

			Main_Game(argc, argv);

		} else {

#if defined(_MSC_VER) && (_MSC_VER <= 1200)
			/*
			**	The __try/__except construct is part of the WIN32 interface. This is not the same
			**	as C++ exception handling. There is no additional code overhead required
			**	with this interface and the compilers exception handling options should be disabled
			**	to prevent the compiler generating additional stack unwinding code.
			*/
			__try {
#else
			SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER) &Top_Level_Exception_Filter);
#endif

				DebugString("Main_Game\n");

				Main_Game(argc, argv);

#if defined(_MSC_VER) && (_MSC_VER <= 1200)
			} __except(Exception_Handler(GetExceptionCode(), GetExceptionInformation())) {};
#else
			/*
			**	Set the exception filter to use on shutdown.
			*/
			SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER) &Top_Level_Exception_Filter);
#endif

#if defined(_MSC_VER) && (_MSC_VER <= 1200)
			SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER) &Top_Level_Exception_Filter);
#endif

		}

		MouseCursor->Hide_Mouse(); // level-2 1.001: hidden again after the game

		HiddenSurface->Fill(0);
		Update_Visible_Surface(true, HiddenSurface);

		/*
		**	Flag that this is a clean shutdown (not killed with Ctrl-Alt-Del)
		*/
		ReadyToQuit = 1;

		Theme.Free_Themes(); // level-2 1.001: the themes and the audio are released here
		Audio_Shutdown();

		/*
		**	Post a message to our message handler to tell it to clean up.
		*/
		PostMessage(MainWindow, WM_DESTROY, 0, 0);

		/*
		**	Wait until the message handler has dealt with the message
		*/
		do
		{
			Windows_Message_Handler();
		}while (ReadyToQuit == 1);

		retval = EXIT_SUCCESS;
	}

	/*
	** level-2 1.001: the subsystems are shut down here as well as in Prog_End.
	*/
	Free_Game_Modes();
	RadarEventClass::Clear();
	Map.DisposeOfArt();
	Free_Scheme_Library();
	Func_59A6F0();
	ObjectTypeClass::Free_One_Time();
	Func_5E2F00();
	Planning_Reset_Wrapper();
	Free_All_Art();
	Clear_Cycle_List();
	Load_Progress_Shutdown();
	Free_Mouse_Shapes();
	Shutdown_Network_5B76A0();

	if (dwRegisterMap != -1) {
		RevokeActiveObject(dwRegisterMap, NULL);
		dwRegisterMap = -1;
	}

	CoDisconnectObject((LPUNKNOWN)&ApplicationInstance, 0);
	OleUninitialize();

	return(retval);
}

/***********************************************************************************************
 * Read_Setup_Options -- Read stuff in from the INI file that we need to know sooner           *
 *                                                                                             *
 *    level-2 1.001: INFERRED helper. WinMain is its only caller and VC6 expands it inline.    *
 *    Its form follows RA1's STARTUP.CPP Read_Setup_Options; the evidence is WinMain's SEH     *
 *    frame (netptr/netbuf/socket/found/p, node, net, x, i and the IPXAddressClass temporary   *
 *    sit with RegisterClasses' expanded locals, as an inline expansion's do) and its inline   *
 *    budget (with the socket and DestNet code in this helper, WinMain calls the CStreamClass  *
 *    factory ctor and the INIClass ctor out of line, as 1.001 does).                          *
 *                                                                                             *
 * INPUT:    Ptr to config file class                                                          *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 *=============================================================================================*/
static void Read_Setup_Options(RawFileClass * config_file)
{
	ConfigINI.Load(*config_file, false);
	VideoBackBufferAllowed = ConfigINI.Get_Bool("Video", "VideoBackBuffer", true);
	Debug_IngameModeChange = ConfigINI.Get_Bool("Video", "AllowModeToggle", false);
	Options.ScreenWidth = ConfigINI.Get_Int("Video", "ScreenWidth", Options.ScreenWidth);
	Options.ScreenHeight = ConfigINI.Get_Int("Video", "ScreenHeight", Options.ScreenHeight);

	/*
	** See if an alternative socket number has been specified
	*/
	int socket = ConfigINI.Get_Int("Network", "Socket", 0);
	if (socket > 0) {
		socket += 0x4000;
		if (socket >= 0x4000 && socket < 0x8000) {
			Ipx.Set_Socket(socket);
		}
	}

	/*
	** See if a destination network has been specified
	*/
	char netbuf[INIClass::MAX_LINE_LENGTH];
	memset(netbuf, 0, sizeof(netbuf));
	char * netptr = netbuf; // level-2 1.001: INFERRED (RA1 form); its frame slot sits above netbuf
	bool found = ConfigINI.Get_String("Network", "DestNet", 0, netbuf, sizeof(netbuf)) ? true : false; // level-2 1.001: INFERRED name (RA1)
	if (found && netptr != NULL && strlen(netbuf)) {
		NetNumType net;
		NetNodeType node;

		/*
		** Scan the string, pulling off each address piece
		*/
		int i = 0;
		char * p = strtok(netbuf, "."); // level-2 1.001: the whole string is scanned
		int x; // level-2 1.001: INFERRED, declared at this level as in RA1 (gives the 1.001 x and i slots)
		while (p != NULL) {
			sscanf(p, "%x", &x);			// convert from hex string to int
			if (i < 4) {
				net[i] = (char)x;			// fill NetNum
			} else {
				node[i-4] = (char)x;		// fill NetNode
			}
			i++;
			p = strtok(NULL, ".");
		}

		/*
		** If all the address components were successfully read, fill in the
		** BridgeNet with a broadcast address to the network across the bridge.
		*/
		if (i >= 4) {
			Session.IsBridge = 1;
			memset(node, 0xff, 6);
			Session.BridgeNet = IPXAddressClass(net, node);
		}
	}
}



/***********************************************************************************************
 * Prog_End -- Cleans up library systems in prep for game exit.                                *
 *                                                                                             *
 *    This routine should be called before the game terminates. It handles cleaning up         *
 *    library systems so that a graceful return to the host operating system is achieved.      *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   03/20/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
void __cdecl Prog_End(void)
{
	int i;

	GameActive = false;

	if (EndGameGraphicsShape != NULL) { // level-2 1.001: the end-game graphics are freed first
		delete EndGameGraphicsShape;
		EndGameGraphicsShape = NULL;
	}
	if (EndGameGraphicsConvert != NULL) { // level-2 1.001: as above
		delete EndGameGraphicsConvert;
		EndGameGraphicsConvert = NULL;
	}
	if (EndGameGraphicsPalette != NULL) { // level-2 1.001: as above
		delete EndGameGraphicsPalette;
		EndGameGraphicsPalette = NULL;
	}

	Session.Free_Scenario_Descriptions();

	while (ColorSchemes.Count()) {
		delete ColorSchemes[0];
	}
	ColorSchemes.Clear();

	// level-2 1.001: no TutorialText release here

	Delete_All_Objects();

	while (Movies.Count()) {
		free((void *)Movies[0]);
		Movies.Delete_Index(0);
	}
	Movies.Clear();

	for (i = 0; i < AllCommands.Count(); i++) {
		delete AllCommands[i];
	}
	AllCommands.Clear();

	// level-2 1.001: Theme.Free_Themes moved to the end

	if (RuleINI != NULL) {
		delete RuleINI;
		RuleINI = NULL;
	}
	AIINI.Clear();
	ArtINI.Clear();
	UIINI.Clear(); // level-2 1.001: the INI set of 1.001
	INI_821A20.Clear(); // level-2 1.001: as above
	ConfigINI.Clear();
	ConfigINI.Clear();

	SpotLightClass::Clear_All();
	IonBlastClass::Clear_All();

	if (MouseCursor) {
		delete MouseCursor;
		MouseCursor = NULL;
	}

	Map.Free_Cells();
	Map.Clear_Radar();

	Reset_Surfaces(); // level-2 1.001: 1.001 resets the surfaces here

	if (DepthBuffer != NULL) {
		delete DepthBuffer;
		DepthBuffer = NULL;
	}
	if (AlphaBuffer != NULL) {
		delete AlphaBuffer;
		AlphaBuffer = NULL;
	}

	if (BitText::Instance != NULL) { // level-2 1.001: one text printer instead of the font pointers
		delete BitText::Instance;
		BitText::Instance = NULL;
	}

	if (TerrainDrawer != NULL) {
		delete TerrainDrawer;
		TerrainDrawer = NULL;
	}
	if (AnimDrawer != NULL) {
		delete AnimDrawer;
		AnimDrawer = NULL;
	}
	if (NormalDrawer != NULL) {
		delete NormalDrawer;
		NormalDrawer = NULL;
	}
	if (VoxelDrawer != NULL) {
		delete VoxelDrawer;
		VoxelDrawer = NULL;
	}
	if (MouseDrawer != NULL) {
		delete MouseDrawer;
		MouseDrawer = NULL;
	}
	if (SidebarDrawer != NULL) {
		delete SidebarDrawer;
		SidebarDrawer = NULL;
	}
	if (CameoDrawer != NULL) {
		delete CameoDrawer;
		CameoDrawer = NULL;
	}
	if (EightBitDrawer != NULL) {
		delete EightBitDrawer;
		EightBitDrawer = NULL;
	}
	if (EightBitSurface != NULL) {
		delete EightBitSurface;
		EightBitSurface = NULL;
	}

	if (CloakingSurface != NULL) {
		delete (Surface *)CloakingSurface;
		CloakingSurface = NULL;
	}

	if (BuildingTypeClass::BuildingZShape != NULL) {
		delete (void *)BuildingTypeClass::BuildingZShape;
		BuildingTypeClass::BuildingZShape = NULL;
	}

	Map.Shutdown();

	for (i = 0; i < TileDrawers.Count(); i++) {
		delete TileDrawers[i];
	}
	TileDrawers.Clear();

	if (TheaterData) {
		delete TheaterData;
		TheaterData = NULL;
	}
	if (TheaterDat) {
		delete TheaterDat;
		TheaterDat = NULL;
	}
	if (GenericMix) { // level-2 1.001: as above
		delete GenericMix;
		GenericMix = NULL;
	}
	if (IsometricTheaterData) {
		delete IsometricTheaterData;
		IsometricTheaterData = NULL;
	}
	if (IsoGenericMix) { // level-2 1.001: as above
		delete IsoGenericMix;
		IsoGenericMix = NULL;
	}

	if (IsometricTileTypeClass::CellShadowShapes != NULL) {
		delete IsometricTileTypeClass::CellShadowShapes;
		IsometricTileTypeClass::CellShadowShapes = NULL;
	}

	if (SlopeZShapes[0] != NULL) {
		delete (ShapeSet *)SlopeZShapes[0];
		SlopeZShapes[0] = NULL;
	}
	if (SlopeZShapes[1] != NULL) {
		delete (ShapeSet *)SlopeZShapes[1];
		SlopeZShapes[1] = NULL;
	}
	if (SlopeZShapes[2] != NULL) {
		delete (ShapeSet *)SlopeZShapes[2];
		SlopeZShapes[2] = NULL;
	}
	if (SlopeZShapes[3] != NULL) {
		delete (ShapeSet *)SlopeZShapes[3];
		SlopeZShapes[3] = NULL;
	}

	if (PreviewSurface != NULL) {
		delete PreviewSurface;
		PreviewSurface = NULL;
	}

	// level-2 1.001: the mix file set of 1.001
	if (MoviesMix != NULL) {
		delete MoviesMix;
		MoviesMix = NULL;
	}
	if (Mix_81F818 != NULL) {
		delete Mix_81F818;
		Mix_81F818 = NULL;
	}
	if (MainMix != NULL) {
		delete MainMix;
		MainMix = NULL;
	}
	if (ConquerMix != NULL) {
		delete ConquerMix;
		ConquerMix = NULL;
	}
	if (CameoMix != NULL) {
		delete CameoMix;
		CameoMix = NULL;
	}

	while (ExpandMix.Count() > 0) {
		delete ExpandMix[0];
		ExpandMix.Delete_Index(0);
	}
	if (CacheMix != NULL) {
		delete CacheMix;
		CacheMix = NULL;
	}
	if (LocalMix != NULL) {
		delete LocalMix;
		LocalMix = NULL;
	}
	if (NeutralMix != NULL) {
		delete NeutralMix;
		NeutralMix = NULL;
	}
	if (SideCDMix != NULL) {
		delete SideCDMix;
		SideCDMix = NULL;
	}
	if (Mix_81F83C != NULL) {
		delete Mix_81F83C;
		Mix_81F83C = NULL;
	}
	while (MixList_81F7C0.Count() > 0) {
		delete MixList_81F7C0[0];
		MixList_81F7C0.Delete_Index(0);
	}
	if (MapsMix != NULL) {
		delete MapsMix;
		MapsMix = NULL;
	}
	if (MultiMix != NULL) {
		delete MultiMix;
		MultiMix = NULL;
	}
	if (SideCMix != NULL) {
		delete SideCMix;
		SideCMix = NULL;
	}
	if (SideNCMix != NULL) {
		delete SideNCMix;
		SideNCMix = NULL;
	}
	if (GameMix != NULL) {
		delete GameMix;
		GameMix = NULL;
	}
	if (Mix_81F7FC != NULL) {
		delete Mix_81F7FC;
		Mix_81F7FC = NULL;
	}

	if (TacticalMap != NULL) {
		delete TacticalMap;
		TacticalMap = NULL;
	}

	// level-2 1.001: the further subsystem shutdowns of 1.001
	RadarEventClass::Clear();
	Map.DisposeOfArt();
	Free_Scheme_Library();
	Func_59A6F0();
	ObjectTypeClass::Free_One_Time();
	Func_5E2F00();
	Planning_Reset_Wrapper();
	Free_All_Art();
	Clear_Cycle_List();
	Load_Progress_Shutdown();
	Free_Mouse_Shapes();
	Shutdown_Network_5B76A0();
	Free_Vocs();
	Speech_Free_All();

	CDFileClass::Clear_Search_Drives();

	if (Keyboard != NULL) {
		delete Keyboard;
		Keyboard = NULL;
	}

	Shutdown_Network();

	if (UnkBuffer != NULL) {
		delete UnkBuffer;
		UnkBuffer = NULL;
	}

	if (Rule != NULL) {
		delete Rule;
		Rule = NULL;
	}

	if (Scen != NULL) {
		delete Scen;
		Scen = NULL;
	}

	for (i = 0; i < RegisteredClasses.Count(); i++) {
		CoRevokeClassObject((DWORD)RegisteredClasses[i]);
	}
	RegisteredClasses.Clear();

	RevokeActiveObject(dwRegisterTiberianSun, NULL);

	if (LanguageResources) {
		FreeLibrary(LanguageResources);
	}

	if (AutoPlayMutex != NULL) {
		CloseHandle(AutoPlayMutex);
		AutoPlayMutex = NULL;
	}
	if (AppMutex != NULL) {
		CloseHandle(AppMutex);
		AppMutex = NULL;
	}

	Audio_File_Shutdown(); // level-2 1.001: the remaining shutdowns of 1.001
	Theme.Free_Themes(); // level-2 1.001: as above
	Audio_Shutdown(); // level-2 1.001: as above
	StringTable::Unload(); // level-2 1.001: as above
	CopyProtection::ShutDown(); // level-2 1.001: as above
	Kill_Mouse_Thread(); // level-2 1.001: as above

#ifdef STEVES_NEW_CATCHER
	_CrtDumpMemoryLeaks();
#endif
}


/// <summary>
/// Ends the process with the exit code given.
/// </summary>
void Exit_Process(int code) // RA2: not in TibSun, at 0x691310
{
	exit(code);
}


/***********************************************************************************************
 * Emergency_Exit -- Function to call when we want to exit unexpectedly.                       *
 *                   Use this function instead of exit(n) so everything is properly cleaned up.*
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Code to return to the OS                                                          *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    3/13/97 1:32AM ST : Created                                                              *
 *=============================================================================================*/
void Emergency_Exit(void)
{
	// RA2: no Audio.End()
	ReadyToQuit = 1;

	/*
	**	Post a message to our message handler to tell it to clean up.
	*/
	PostMessage(MainWindow, WM_DESTROY, 0, 0);

	while (MainWindow) {
		Windows_Message_Handler();
		if (ReadyToQuit != 1) {
			break;
		}
	}

	if (dwRegisterMap != -1) {
		RevokeActiveObject(dwRegisterMap, NULL);
		dwRegisterMap = -1;
	}

	CoDisconnectObject((LPUNKNOWN)&ApplicationInstance, 0);

	OleUninitialize();

	if (MouseCursor) {
		MouseCursor->Release_Mouse();
		delete MouseCursor;
	}
	MouseCursor = NULL;

	if (MouseShapesAllocated) { // RA2: frees the mouse shapes Init_Game loaded (MOUSE.SHP)
		delete MouseShapes; // RA2: as above
		MouseShapesAllocated = false; // RA2: as above
	} // RA2: as above

	PostQuitMessage(EXIT_SUCCESS);

	Shutdown_Network();

	Prog_End();
}

