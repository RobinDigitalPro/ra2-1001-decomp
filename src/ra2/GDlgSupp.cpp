// C:\RA2\GDlgSupp.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Game dialog support: per-player country (side) and colour combo boxes of the multiplayer and
// skirmish set-up dialogs, their flag pictures, and the table of player colours that tracks which
// player slot owns which colour. Class names come from RTTI (HouseTypeClass, DynamicVectorClass);
// all other function, class and variable names are provisional.
#include "RECT.H"

// Zero rectangle with its own dynamic initializer (0x4d0890, .bss 0x84e3c0), directly before the
// GAMECONST.H block; the same form as Event.CPP's ZeroRect (there after GAMECONST.H). Name provisional.
static RectangleStruct const ZeroRect(0, 0, 0, 0);

#include "GAMECONST.H"
#include <windows.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60

// RTTI .?AVHouseTypeClass@@; only the fields used here.
class HouseTypeClass {
public:
    wchar_t const * Full_Name() const { return UIName; }

    char Unknown00[0x60];
    wchar_t const * UIName;                     // +0x60 (AbstractTypeClass::UIName)
    char Unknown64[0x1A5 - 0x64];
    bool IsMultiplay;                           // +0x1a5, country offered in multiplayer (provisional)
};
extern DynamicVectorClass<HouseTypeClass *> HouseTypes;    // 0xa1e038

// Image cache at 0xa5ded0; 0x682140 looks an image up by file name (hash table). Provisional.
class ImageCacheClass {
public:
    void * Find(char const * name, int unknown);    // 0x682140
};
extern ImageCacheClass ImageCache;              // 0xa5ded0

// Flag picture file names ("rani.pcx", "usai.pcx", ... "rusi.pcx"); defined in another TU (.data).
extern char const * FlagImageNames[10];         // 0x7e1f28

// Owner-draw control registry: attaches an image to a control window (0x5da440). Provisional.
void Set_Control_Image(HWND window, void * image);  // 0x5da440

// Session members (see NetDlg.CPP for the convention of separate globals).
extern int SessionColor;                        // 0xa256f4 (Session + 0x12c)
extern int SessionColorPref;                    // 0xa256f8 (Session + 0x130), -2 = random
extern int SessionSide;                         // 0xa256fc (Session + 0x134)
extern int SessionSidePref;                     // 0xa25700 (Session + 0x138), -2 = random

// ---- end of local declarations ----

#define MAX_SLOTS           8
#define MAX_COLORS          8
#define SIDE_RANDOM         -2
#define COLOR_RANDOM        -2

// Custom messages of the game's owner-drawn combo boxes (meanings provisional).
#define WM_CB_ADD_WIDE_STRING   (WM_USER + 0xC2)
#define WM_CB_SET_ITEM_COLOR    (WM_USER + 0x98)
#define WM_CB_SET_STYLE         (WM_USER + 0xDD)
#define WM_CB_SET_VISIBLE_ITEMS (WM_USER + 0xDE)

// Player colour table (12-byte entries at 0x84e408).
struct PlayerColorType {
    wchar_t const * Abbrev;                     // +0x0
    int RGB;                                    // +0x4
    int Owner;                                  // +0x8, owning player slot or -1
};
PlayerColorType PlayerColors[MAX_COLORS];       // 0x84e408

static int PlayerColorRGB[MAX_COLORS] = {       // 0x7d1178
    0x0DE2DD, 0x1919FF, 0xE2742A, 0x2ED13E, 0x19A0FF, 0xE6D732, 0xBD2895, 0xEB9AFF
};

int Player_Flag_ID(int slot)
{
    if (slot == 0) return 0x6DA;
    if (slot == 1) return 0x6DB;
    if (slot == 2) return 0x6DC;
    if (slot == 3) return 0x6DD;
    if (slot == 4) return 0x6DE;
    if (slot == 5) return 0x6DF;
    if (slot == 6) return 0x6E0;
    if (slot == 7) return 0x6E1;
    return -1;
}

int Player_Flag_Slot(int id)
{
    if (id == 0x6DA) return 0;
    if (id == 0x6DB) return 1;
    if (id == 0x6DC) return 2;
    if (id == 0x6DD) return 3;
    if (id == 0x6DE) return 4;
    if (id == 0x6DF) return 5;
    if (id == 0x6E0) return 6;
    if (id == 0x6E1) return 7;
    return -1;
}

void * Side_Flag_Image(int side)
{
    void * image = NULL;
    if (side == SIDE_RANDOM) {
        image = ImageCache.Find(FlagImageNames[0], 0);
    } else if (side == 0) {
        image = ImageCache.Find(FlagImageNames[1], 0);
    } else if (side == 1) {
        image = ImageCache.Find(FlagImageNames[2], 0);
    } else if (side == 2) {
        image = ImageCache.Find(FlagImageNames[3], 0);
    } else if (side == 3) {
        image = ImageCache.Find(FlagImageNames[4], 0);
    } else if (side == 4) {
        image = ImageCache.Find(FlagImageNames[5], 0);
    } else if (side == 5) {
        image = ImageCache.Find(FlagImageNames[6], 0);
    } else if (side == 6) {
        image = ImageCache.Find(FlagImageNames[7], 0);
    } else if (side == 7) {
        image = ImageCache.Find(FlagImageNames[8], 0);
    } else if (side == 8) {
        image = ImageCache.Find(FlagImageNames[9], 0);
    }
    return image;
}

int Player_Side_ID(int slot);
int Get_Side_Data(HWND dialog, int id, int index);

void Update_Player_Flag(HWND dialog, int slot)
{
    HWND flag = GetDlgItem(dialog, Player_Flag_ID(slot));
    int id = Player_Side_ID(slot);
    Set_Control_Image(flag, Side_Flag_Image(Get_Side_Data(dialog, id, -1)));
}

int Player_Side_ID(int slot)
{
    if (slot == 0) return 0x6A1;
    if (slot == 1) return 0x510;
    if (slot == 2) return 0x513;
    if (slot == 3) return 0x51E;
    if (slot == 4) return 0x514;
    if (slot == 5) return 0x51F;
    if (slot == 6) return 0x520;
    if (slot == 7) return 0x521;
    return -1;
}

int Player_Side_Slot(int id)
{
    if (id == 0x6A1) return 0;
    if (id == 0x510) return 1;
    if (id == 0x513) return 2;
    if (id == 0x51E) return 3;
    if (id == 0x514) return 4;
    if (id == 0x51F) return 5;
    if (id == 0x520) return 6;
    if (id == 0x521) return 7;
    return -1;
}

wchar_t const * Side_Name(int side)
{
    if (side == SIDE_RANDOM) {
#line 178 "C:\\RA2\\GDlgSupp.cpp"
        return Fetch_String("STT:PlayerSideRandom", NULL, __FILE__, __LINE__);
    } else if (side == 0) {
        return Fetch_String("STT:PlayerSideAmerica", NULL, __FILE__, __LINE__);
    } else if (side == 1) {
        return Fetch_String("STT:PlayerSideKorea", NULL, __FILE__, __LINE__);
    } else if (side == 2) {
        return Fetch_String("STT:PlayerSideFrance", NULL, __FILE__, __LINE__);
    } else if (side == 3) {
        return Fetch_String("STT:PlayerSideGermany", NULL, __FILE__, __LINE__);
    } else if (side == 4) {
        return Fetch_String("STT:PlayerSideBritain", NULL, __FILE__, __LINE__);
    } else if (side == 5) {
        return Fetch_String("STT:PlayerSideLibya", NULL, __FILE__, __LINE__);
    } else if (side == 6) {
        return Fetch_String("STT:PlayerSideIraq", NULL, __FILE__, __LINE__);
    } else if (side == 7) {
        return Fetch_String("STT:PlayerSideCuba", NULL, __FILE__, __LINE__);
    } else if (side == 8) {
        return Fetch_String("STT:PlayerSideRussia", NULL, __FILE__, __LINE__);
    }
    return 0;
}

void Fill_Side_List(HWND dialog, int id)
{
    HWND list = GetDlgItem(dialog, id);
    bool hidden = (ShowWindow(list, SW_HIDE) == 0);
    SendMessageA(list, CB_RESETCONTENT, 0, 0);
    SendMessageA(list, WM_CB_SET_VISIBLE_ITEMS, 0, 7);
#line 210 "C:\\RA2\\GDlgSupp.cpp"
    int index = SendMessageA(list, WM_CB_ADD_WIDE_STRING, 0, (LPARAM)Fetch_String("GUI:RandomEx", NULL, __FILE__, __LINE__));
    SendMessageA(list, CB_SETITEMDATA, index, SIDE_RANDOM);

    int count = HouseTypes.ActiveCount;
    for (int side = 0; side < count; side++) {
        HouseTypeClass * house = HouseTypes[side];
        if (house->IsMultiplay) {
            int item = SendMessageA(list, WM_CB_ADD_WIDE_STRING, 0, (LPARAM)house->Full_Name());
            SendMessageA(list, CB_SETITEMDATA, item, side);
        }
    }
    SendMessageA(list, CB_SETCURSEL, 0, 0);
    if (!hidden) {
        ShowWindow(list, SW_SHOW);
    }
}

void Fill_All_Side_Lists(HWND dialog)
{
    for (int slot = 0; slot < MAX_SLOTS; slot++) {
        Fill_Side_List(dialog, Player_Side_ID(slot));
    }
}

void Select_Side(HWND dialog, int id, int side);

void Select_Player_Side(HWND dialog, int slot)
{
    int side = SessionSide;
    if (SessionSidePref == SIDE_RANDOM) {
        side = SIDE_RANDOM;
    }
    Select_Side(dialog, Player_Side_ID(slot), side);
}

void Select_Side(HWND dialog, int id, int side)
{
    HWND list = GetDlgItem(dialog, id);
    bool hidden = (ShowWindow(list, SW_HIDE) == 0);
    int count = SendDlgItemMessageA(dialog, id, CB_GETCOUNT, 0, 0);
    for (int index = 0; index < count; index++) {
        if (SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0) == side) {
            SendDlgItemMessageA(dialog, id, CB_SETCURSEL, index, 0);
            break;
        }
    }
    if (!hidden) {
        ShowWindow(list, SW_SHOW);
    }
    Update_Player_Flag(dialog, Player_Side_Slot(id));
}

int Get_Side_Data(HWND dialog, int id, int index)
{
    if (index == -1) {
        index = SendDlgItemMessageA(dialog, id, CB_GETCURSEL, 0, 0);
    }
    return SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0);
}

int Player_Color_ID(int slot)
{
    if (slot == 0) return 0x6A2;
    if (slot == 1) return 0x522;
    if (slot == 2) return 0x523;
    if (slot == 3) return 0x524;
    if (slot == 4) return 0x525;
    if (slot == 5) return 0x526;
    if (slot == 6) return 0x527;
    if (slot == 7) return 0x528;
    return -1;
}

int Player_Color_Slot(int id)
{
    if (id == 0x6A2) return 0;
    if (id == 0x522) return 1;
    if (id == 0x523) return 2;
    if (id == 0x524) return 3;
    if (id == 0x525) return 4;
    if (id == 0x526) return 5;
    if (id == 0x527) return 6;
    if (id == 0x528) return 7;
    return -1;
}

wchar_t const * Color_Name(int color)
{
    if (color == COLOR_RANDOM) {
#line 337 "C:\\RA2\\GDlgSupp.cpp"
        return Fetch_String("STT:PlayerColorRandom", NULL, __FILE__, __LINE__);
    } else if (color == 0) {
        return Fetch_String("STT:PlayerColorGold", NULL, __FILE__, __LINE__);
    } else if (color == 1) {
        return Fetch_String("STT:PlayerColorRed", NULL, __FILE__, __LINE__);
    } else if (color == 2) {
        return Fetch_String("STT:PlayerColorBlue", NULL, __FILE__, __LINE__);
    } else if (color == 3) {
        return Fetch_String("STT:PlayerColorGreen", NULL, __FILE__, __LINE__);
    } else if (color == 4) {
        return Fetch_String("STT:PlayerColorOrange", NULL, __FILE__, __LINE__);
    } else if (color == 5) {
        return Fetch_String("STT:PlayerColorSkyBlue", NULL, __FILE__, __LINE__);
    } else if (color == 6) {
        return Fetch_String("STT:PlayerColorPurple", NULL, __FILE__, __LINE__);
    } else if (color == 7) {
        return Fetch_String("STT:PlayerColorPink", NULL, __FILE__, __LINE__);
    }
    return 0;
}

void Init_Player_Colors()
{
#line 361 "C:\\RA2\\GDlgSupp.cpp"
    PlayerColors[0].Abbrev = Fetch_String("GUI:GoldAbbrev", NULL, __FILE__, __LINE__);
    PlayerColors[1].Abbrev = Fetch_String("GUI:RedAbbrev", NULL, __FILE__, __LINE__);
    PlayerColors[2].Abbrev = Fetch_String("GUI:BlueAbbrev", NULL, __FILE__, __LINE__);
    PlayerColors[3].Abbrev = Fetch_String("GUI:GreenAbbrev", NULL, __FILE__, __LINE__);
    PlayerColors[4].Abbrev = Fetch_String("GUI:OrangeAbbrev", NULL, __FILE__, __LINE__);
    PlayerColors[5].Abbrev = Fetch_String("GUI:SkyBlueAbbrev", NULL, __FILE__, __LINE__);
    PlayerColors[6].Abbrev = Fetch_String("GUI:PurpleAbbrev", NULL, __FILE__, __LINE__);
    PlayerColors[7].Abbrev = Fetch_String("GUI:PinkAbbrev", NULL, __FILE__, __LINE__);
    for (int color = 0; color < MAX_COLORS; color++) {
        PlayerColors[color].RGB = PlayerColorRGB[color];
        PlayerColors[color].Owner = -1;
    }
}

int Combo_Color(int id)
{
    int slot = Player_Color_Slot(id);
    for (int color = 0; color < MAX_COLORS; color++) {
        if (PlayerColors[color].Owner == slot) {
            return color;
        }
    }
    return -1;
}

bool Is_Color_Taken(int color)
{
    return PlayerColors[color].Owner != -1;
}

void Fill_Color_List(HWND dialog, int id)
{
    int index;
    HWND list = GetDlgItem(dialog, id);
    bool hidden = (ShowWindow(list, SW_HIDE) == 0);
    SendMessageA(list, CB_RESETCONTENT, 0, 0);
    SendMessageA(list, WM_CB_SET_STYLE, 0, 1);
    SendMessageA(list, WM_CB_SET_VISIBLE_ITEMS, 0, 9);
#line 407 "C:\\RA2\\GDlgSupp.cpp"
    index = SendMessageA(list, WM_CB_ADD_WIDE_STRING, 0, (LPARAM)Fetch_String("GUI:RandomAsSymbols", NULL, __FILE__, __LINE__));
    SendMessageA(list, CB_SETITEMDATA, index, COLOR_RANDOM);
    SendMessageA(list, WM_CB_SET_ITEM_COLOR, index, -1);

    int slot = Player_Color_Slot(id);
    int selection = 0;
    for (int color = 0; color < MAX_COLORS; color++) {
        bool mine = (PlayerColors[color].Owner == slot);
        if (mine || PlayerColors[color].Owner == -1) {
            wchar_t const * name = PlayerColors[color].Abbrev; // level-2 1.001: STEERING named Abbrev local (same value, read once before the add); it lowers the walk pointer's weight so VC6 gives it EBX and index/slot EBP as in 1.001 (128 -> 0 bytes)
            index = SendMessageA(list, WM_CB_ADD_WIDE_STRING, 0, (LPARAM)name);
            SendMessageA(list, WM_CB_SET_ITEM_COLOR, index, PlayerColors[color].RGB);
            SendMessageA(list, CB_SETITEMDATA, index, color);
            if (mine) {
                selection = index;
            }
        }
    }
    SendMessageA(list, CB_SETCURSEL, selection, 0);
    if (!hidden) {
        ShowWindow(list, SW_SHOW);
    }
}

void Fill_All_Color_Lists(HWND dialog)
{
    for (int slot = 0; slot < MAX_SLOTS; slot++) {
        Fill_Color_List(dialog, Player_Color_ID(slot));
    }
}

void Select_Color(HWND dialog, int id, int color);

void Select_Player_Color(HWND dialog, int slot)
{
    int color = SessionColor;
    if (SessionColorPref == COLOR_RANDOM) {
        color = COLOR_RANDOM;
    }
    Select_Color(dialog, Player_Color_ID(slot), color);
}

void Select_Color(HWND dialog, int id, int color)
{
    HWND list = GetDlgItem(dialog, id);
    bool hidden = (ShowWindow(list, SW_HIDE) == 0);

    int old = Combo_Color(id);
    if (old != -1) {
        PlayerColors[old].Owner = -1;
    }

    int count = SendDlgItemMessageA(dialog, id, CB_GETCOUNT, 0, 0);
    for (int index = 0; index < count; index++) {
        int data = SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0);
        if (data == color) {
            SendDlgItemMessageA(dialog, id, CB_SETCURSEL, index, 0);
            if (data != COLOR_RANDOM) {
                PlayerColors[data].Owner = Player_Color_Slot(id);
            }
            break;
        }
    }
    if (!hidden) {
        ShowWindow(list, SW_SHOW);
    }
    Fill_All_Color_Lists(dialog);
}

int Get_Color_Data(HWND dialog, int id, int index);

void Color_Changed(HWND dialog, int id)
{
    int old = Combo_Color(id);
    if (old != -1) {
        PlayerColors[old].Owner = -1;
    }
    int color = Get_Color_Data(dialog, id, -1);
    int slot = Player_Color_Slot(id);
    if (color != COLOR_RANDOM) {
        PlayerColors[color].Owner = slot;
    }
    Fill_All_Color_Lists(dialog);
}

int Get_Color_Data(HWND dialog, int id, int index)
{
    if (index == -1) {
        index = SendDlgItemMessageA(dialog, id, CB_GETCURSEL, 0, 0);
    }
    return SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0);
}
