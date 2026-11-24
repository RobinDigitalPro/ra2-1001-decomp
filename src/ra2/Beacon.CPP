// C:\RA2\Beacon.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Multiplayer map beacons: a player marks a map position with a beacon (up to three per house,
// eight houses), may attach a short text, and the placement, text and removal are sent to the
// other players as global packets (commands 32, 34 and 33). BeaconManager (0x836c18) owns them.
// No RTTI exists for these classes (only BeaconPlacementCommandClass elsewhere); the class names
// BeaconClass / BeaconManagerClass and all method, member and variable names are provisional.
//
// TU span 0x42d770..0x42ef95: 0x2d770 is the 16-byte zeroing header initializer (.bss 0x836be8,
// between this TU's GAMECONST constants; header not reproduced, not claimed), 0x2d790..0x2d951 the
// GAMECONST block, 0x2d960 the initializer of BeaconManager with its atexit destructor 0x2d990,
// then the BeaconClass and BeaconManagerClass methods in source order up to 0x2ef95. The 16-byte
// zeroing initializer 0x2efa0 (.bss 0x836ce0) starts the next TU.
//
// BeaconManagerClass::Place / Delete / Set_Text use the nested mischa85 form (stored bool,
// `if (Count) { ... }`, return inside the slot loop); this gives the 1.001 block layout (w45).
#include "GAMECONST.H"
#include <windows.h>
#include <mmsystem.h>
#include <string.h>
#include <wchar.h>
#include "VECTOR.H"
#include "SURFACE.H"
#include "BLIT.H"


// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
void Speak(char const * name, int arg2 = -1, int arg3 = -1);  // 0x70a700 (see Super.CPP)
int Play_Sound(int voc, float volume, int pan, int flags);   // 0x708970 (names provisional, as in Options.CPP)
char * To_Narrow(wchar_t const * string);       // 0x6eedc0
wchar_t * To_Wide(char const * string);         // 0x6eee20
extern char NullString[];                       // 0x8248a4 (.bss), shared empty string
extern int Frame;                               // 0xa2896c, game frame counter

inline CoordStruct operator - (CoordStruct left, CoordStruct right)
{
    return CoordStruct(left.X - right.X, left.Y - right.Y, left.Z - right.Z);
}
inline int Coord_Length(CoordStruct coord)
{
    double y = coord.Y;
    double z = coord.Z;
    double x = coord.X;
    return (int)Fast_Sqrt(y * y + (x * x + z * z));
}
inline bool operator == (CoordStruct const & left, CoordStruct const & right)
{
    return left.X == right.X && left.Y == right.Y && left.Z == right.Z;
}
inline bool operator != (CoordStruct const & left, CoordStruct const & right)
{
    return !(left == right);
}

// File classes (copied from Options.CPP).
class FileClass {
public:
    virtual ~FileClass();
    virtual char const * File_Name() const = 0;
    virtual char const * Set_Name(char const * filename) = 0;
    virtual int Create() = 0;
    virtual int Delete() = 0;
    virtual bool Is_Available(int forced = false) = 0;
    virtual bool Is_Open() const = 0;
    virtual int Open(char const * filename, int rights = 1) = 0;
    virtual int Open(int rights = 1) = 0;
    virtual long Read(void * buffer, long size) = 0;
    virtual long Seek(long pos, int dir = 1) = 0;
    virtual long Size() = 0;
    virtual long Write(void const * buffer, long size) = 0;
    virtual void Close() = 0;
    virtual unsigned long Get_Date_Time() = 0;
    virtual bool Set_Date_Time(unsigned long datetime) = 0;
    virtual void Error(int error, int canretry = false, char const * filename = NULL) = 0;
};

class RawFileClass : public FileClass {
public:
    RawFileClass(char const * filename);    // 0x6300e0
    virtual ~RawFileClass();                // 0x630060
    virtual char const * File_Name() const;
    virtual char const * Set_Name(char const * filename);
    virtual int Create();
    virtual int Delete();
    virtual bool Is_Available(int forced = false);
    virtual bool Is_Open() const;
    virtual int Open(char const * filename, int rights = 1);
    virtual int Open(int rights = 1);
    virtual long Read(void * buffer, long size);
    virtual long Seek(long pos, int dir = 1);
    virtual long Size();
    virtual long Write(void const * buffer, long size);
    virtual void Close();
    virtual unsigned long Get_Date_Time();
    virtual bool Set_Date_Time(unsigned long datetime);
    virtual void Error(int error, int canretry = false, char const * filename = NULL);
private:
    char RawFileData[0x1C];             // +0x04, layout not reconstructed
};

void * Load_Alloc_Data(FileClass & file);       // 0x495010: Is_Available, Size, new, Read (name provisional)
void * MFCD_Retrieve(char const * filename);    // 0x5924c0: data of a file inside a loaded mix file (name provisional)

// Shape file header (only the fields read here).
struct ShapeFileStruct {
    short Type;                                 // +0
    short Width;                                // +2
    short Height;                               // +4
    short Count;                                // +6, number of frames
};

// Shape drawing (0x49ebd0); see Power.CPP.
class ConvertClass;
void CC_Draw_Shape(Surface * surface, ConvertClass * convert, void const * shape, int frame,
    Point2D const * point, RectangleStruct const * window, int flags, int arg8, int arg9, int arg10,
    int arg11, int arg12, int arg13, Point2D offset);

// Colours (see LdPrgMgr.cpp).
struct RGBClass {
    RGBClass() {}
    RGBClass(unsigned char red, unsigned char green, unsigned char blue) : Red(red), Green(green), Blue(blue) {}
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};
class HSVClass {
public:
    RGBClass To_RGB() const;                // 0x4fe550
    unsigned char Hue;
    unsigned char Saturation;
    unsigned char Value;
};
inline unsigned RGB_To_Pixel(int red, int green, int blue)
{
    return ((red >> BlitFormat.RedShiftLeft) << BlitFormat.RedShiftRight)
        | ((green >> BlitFormat.GreenShiftLeft) << BlitFormat.GreenShiftRight)
        | ((blue >> BlitFormat.BlueShiftLeft) << BlitFormat.BlueShiftRight);
}
inline unsigned RGB_To_Pixel(RGBClass rgb)
{
    return RGB_To_Pixel(rgb.Red, rgb.Green, rgb.Blue);
}

// RTTI .?AVColorScheme@@; only the fields used here.
class ColorScheme {
public:
    char Unknown0[0x308];
    HSVClass BaseColor;                     // +0x308
    char Unknown30B[0x30C - 0x30B];
    ConvertClass * Convert;                 // +0x30c, shape drawer in this colour
};
extern DynamicVectorClass<ColorScheme *> ColorSchemes;   // 0xa9ea00

// RTTI .?AVHouseClass@@; only the fields used here.
class HouseClass {
public:
    bool Is_Ally(int house) const;              // 0x4e4ba0 (house index)
    bool Is_Ally(HouseClass const * house) const;   // 0x4e4be0
    char Unknown00[0x30];
    int ArrayIndex;                             // +0x30
    char Unknown34[0x15F40 - 0x34];
    int ColorSchemeIndex;                       // +0x15f40
};
extern DynamicVectorClass<HouseClass *> Houses; // 0xa1a5c8
extern HouseClass * PlayerPtr;                  // 0xa1e0e4

// RTTI .?AVRulesClass@@; only the field used here.
class RulesClass {
public:
    char Unknown00[0x1C4];
    int BeaconSound;                            // +0x1c4, played when the player places a beacon (provisional)
};
extern RulesClass * Rule;                       // 0x821b88

enum GameEnum { GAME_NORMAL = 0, GAME_MODEM = 1, GAME_NULL_MODEM = 2, GAME_IPX = 3,
    GAME_INTERNET = 4, GAME_SKIRMISH = 5 };     // see Conquer.CPP
class SessionClass {
public:
    int Type;                                   // +0x0000
};
extern SessionClass Session;                    // 0xa255c8

class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
    char Unknown00[0x19];
    bool IsEditing;                             // +0x19, a message is being typed (provisional)
};
extern MessageListClass SessionMessages;        // 0xa25fa0  (Session + 0x9d8)

// IPX addresses and the global packet (see Conquer.CPP).
class IPXAddressClass {
public:
    char Address[10];
};
struct NodeNameType {
    wchar_t Name[20];                           // +0x00 (assumed)
    IPXAddressClass Address;                    // +0x28
};
extern DynamicVectorClass<NodeNameType *> SessionPlayers;  // 0xa27da8 (Session + 0x27e0)

#pragma pack(push, 1)
struct GlobalPacketType {
    int Command;                                // +0x00
    char Name[0x2F - 0x04];                     // +0x04 narrow player name (size assumed)
    union {
        struct {
            int X;                              // +0x2f
            int Y;                              // +0x33
            int Z;                              // +0x37
            char B;                             // +0x3b
            char A;                             // +0x3c
        } Location;
        struct {
            char B;                             // +0x2f
            char A;                             // +0x30
            wchar_t Text[0x80];                 // +0x31
        } Raw;
    };
    unsigned char Unknown[0x1C7 - 0x131];
};
#pragma pack(pop)
enum { NET_BEACON_PLACE = 32, NET_BEACON_DELETE = 33, NET_BEACON_TEXT = 34 };   // provisional names

class IPXManagerClass {
public:
    int Send_Global_Message(void * buf, int buflen, int ack_req, IPXAddressClass * address);   // 0x524560
};
extern IPXManagerClass Ipx;                     // 0xa285c8

// Smallest rectangle containing both (an invalid rectangle, W or H <= 0, is ignored).
inline bool Is_Valid(RectangleStruct const & rect)
{
    return rect.Width > 0 && rect.Height > 0;
}
inline RectangleStruct Union(RectangleStruct const & rect1, RectangleStruct const & rect2)
{
    if (Is_Valid(rect1)) {
        if (Is_Valid(rect2)) {
            RectangleStruct result = rect1;
            if (result.X > rect2.X) {
                result.Width += result.X - rect2.X;
                result.X = rect2.X;
            }
            if (result.Y > rect2.Y) {
                result.Height += result.Y - rect2.Y;
                result.Y = rect2.Y;
            }
            if (result.X + result.Width < rect2.X + rect2.Width) {
                result.Width = rect2.X - result.X + rect2.Width + 1;
            }
            if (result.Y + result.Height < rect2.Y + rect2.Height) {
                result.Height = rect2.Y - result.Y + rect2.Height + 1;
            }
            return result;
        }
        return rect1;
    }
    return rect2;
}

inline CellStruct Coord_Cell(CoordStruct coord)
{
    return CellStruct(coord.X / 256, coord.Y / 256);
}

// Radar event (0x632b40, __fastcall; type 1 = beacon). Name provisional.
void Radar_Event(int type, CellStruct cell);

// Map (0x81a820); only the radar parts used here (offsets relative to Map).
class MouseClass {
public:
    Point2D Coord_To_Radar(CoordStruct const & coord, bool flag);  // 0x629220 (provisional)
    void Radar_Pixel(Point2D const & pixel);    // 0x629ca0, marks a radar pixel for redraw (provisional)
    char Unknown0000[0x1208];
    RectangleStruct RadarDirty;                 // +0x1208 (0x81ba28)
    Surface * RadarSurface;                     // +0x1218 (0x81ba38)
    char Unknown121C[0x1498 - 0x121C];
    RectangleStruct RadarRect;                  // +0x1498 (0x81bcb8)
};
extern MouseClass Map;                          // 0x81a820

// Tactical view (object pointer 0x821cac).
class TacticalClass {
public:
    bool Coord_To_Pixel(CoordStruct const & coord, Point2D & pixel);   // 0x698010 (provisional)
};
extern TacticalClass * TacticalMap;             // 0x821cac

void Unselect_All();                            // 0x482960 (Conquer.CPP Clear_Object_List_482960)

// Bitmap font (RTTI .?AVBitFont@@, see LdPrgMgr.cpp).
class BitFont {
public:
    virtual ~BitFont();
    int Get_Text_Size(wchar_t const * text, int * width, int * height, int max_width);  // 0x431370
    bool Set_Wrap(bool wrap);                   // 0x431310 (+0x41, provisional)
    void Set_Clip(RECT const * rect);           // 0x431320 (+0x30..0x3c)
    unsigned short Set_Color(unsigned short color);   // 0x4312f0 (+0x24)
};
extern BitFont * TextFont;                      // 0x836d30
class TextPrinterClass {
public:
    int Print(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int width,
        int height, int arg8, int arg9, int arg10);   // 0x432350 (provisional)
};
extern TextPrinterClass * TextPrinter;          // 0x836d18 (provisional)

class BeaconClass {
public:
    BeaconClass();
    void Draw(Surface * surface, RectangleStruct window);
    void Func_42DD50(int, int, int, int, int, int, int);
    void Set(CoordStruct coord, int owner);
    void Set_Selected(bool selected);
    void Func_42DDD0();
    void Deactivate();
    void Set_Text(wchar_t const * text);
    void Draw_Radar(Surface * surface, RectangleStruct window, bool forced);
    bool Is_Visible() const;

    CoordStruct Coord;                          // +0x00
    unsigned char IsActive:1;                   // +0x0c bit 0
    unsigned char IsSelected:1;                 // +0x0c bit 1
    wchar_t Text[128];                          // +0x0e
    int Owner;                                  // +0x110, house index
};

class BeaconManagerClass {
public:
    BeaconManagerClass();
    ~BeaconManagerClass();
    void Clear();
    void Init();
    void Draw(Surface * surface, RectangleStruct window);
    void Place(int owner, CoordStruct coord, int slot);
    bool Has_Free_Slot(int owner);
    Point2D Func_42E6E0();
    bool Select_Near(CoordStruct coord);
    void Unselect_All();
    BeaconClass * Find_Near(CoordStruct coord);
    BeaconClass * Find_Selected(int owner);
    void Delete(int owner, int slot);
    void Set_Text(wchar_t const * text, int owner, int slot, bool send);
    void Draw_Radar(Surface * surface, RectangleStruct window);
    bool Is_Blinking();

    BeaconClass * Beacons[8][3];                // +0x00
    int Count;                                  // +0x60
    int BeaconWidth;                            // +0x64
    int BeaconHeight;                           // +0x68
    int BeaconFrames;                           // +0x6c
    int RadarWidth;                             // +0x70
    int RadarHeight;                            // +0x74
    int RadarFrames;                            // +0x78
    int BlinkRate;                              // +0x7c
};

// ---- end of local declarations ----

BeaconManagerClass BeaconManager;
static ShapeFileStruct * BeaconShape;           // 0x836cd4
static ShapeFileStruct * RadarBeaconShape;      // 0x836cd8

BeaconClass::BeaconClass() :
    Coord(EmptyCoord)
{
    IsActive = false;
    IsSelected = false;
    memset(Text, 0, sizeof(Text));
}

void BeaconClass::Draw(Surface * surface, RectangleStruct window)
{
    ColorScheme * scheme = ColorSchemes[Houses[Owner]->ColorSchemeIndex];
    Point2D pixel;
    if (TacticalMap->Coord_To_Pixel(Coord, pixel)) {
        int half = BeaconManager.BeaconFrames / 2;
        CC_Draw_Shape(surface, scheme->Convert, BeaconShape, Frame % half + (IsSelected ? half : 0),
            &pixel, &window, 0x600, 0, 0, 0, 1000, 0, 0, Point2D(0, 0));
        if (wcslen(Text) != 0) {
            wchar_t text[128];
            memcpy(text, Text, sizeof(text));
            if (IsSelected && SessionMessages.IsEditing) {
                if (timeGetTime() % 500 < 250) {
                    wchar_t * cursor = wcsrchr(text, '_');
                    if (cursor != NULL && wcslen(cursor) == 1) {
                        *cursor = ' ';
                    }
                }
            }
            if (!IsSelected || !SessionMessages.IsEditing) {
                wchar_t * cursor;
                if ((cursor = wcsrchr(text, '_')) != NULL && wcslen(cursor) == 1 ||
                    (cursor = wcsrchr(text, ' ')) != NULL && wcslen(cursor) == 1) {
                    *cursor = 0;
                }
            }
            BitFont * font = TextFont;
            int width = 0;
            int height = 0;
            font->Get_Text_Size(text, &width, &height, 200);
            RectangleStruct box(pixel.X - width / 2 - 4, pixel.Y + 32, width + 8, height + 8);
            RGBClass rgb = scheme->BaseColor.To_RGB();
            RectangleStruct clip = Intersect(box, window);
            unsigned color = RGB_To_Pixel(rgb);
            surface->Fill_Rect(clip, 0);
            surface->Draw_Rect(clip, color);
            font->Set_Wrap(true);
            RECT rect;
            rect.left = window.X;
            rect.top = window.Y;
            rect.right = window.X + window.Width - 1;
            rect.bottom = window.Y + window.Height - 1;
            font->Set_Clip(&rect);
            font->Set_Color(color);
            TextPrinter->Print(font, surface, text, box.X + 4, box.Y + 4, 200, box.Height, 0, 0, 0);
        }
    }
}

void BeaconClass::Func_42DD50(int, int, int, int, int, int, int)
{
}

void BeaconClass::Set(CoordStruct coord, int owner)
{
    if (coord != EmptyCoord) {
        Coord = coord;
    }
    if (owner < 8) {
        Owner = owner;
        IsActive = true;
    }
}

void BeaconClass::Set_Selected(bool selected)
{
    IsSelected = selected;
}

void BeaconClass::Func_42DDD0()
{
}

void BeaconClass::Deactivate()
{
    IsActive = false;
}

void BeaconClass::Set_Text(wchar_t const * text)
{
    memset(Text, 0, sizeof(Text));
    if (text != NULL) {
        wcsncpy(Text, text, 127);
    }
}

void BeaconClass::Draw_Radar(Surface * surface, RectangleStruct window, bool forced)
{
    int frame = Frame % BeaconManager.BlinkRate;
    if (frame < BeaconManager.RadarFrames + 1 || forced) {
        Point2D pixel = Map.Coord_To_Radar(Coord, true);
        if (frame < BeaconManager.RadarFrames && !forced) {
            CC_Draw_Shape(surface, ColorSchemes[Houses[Owner]->ColorSchemeIndex]->Convert, RadarBeaconShape, frame,
                &pixel, &window, 0x600, 0, 0, 0, 1000, 0, 0, Point2D(0, 0));
        }
        int width = BeaconManager.RadarWidth;
        int height = BeaconManager.RadarHeight;
        RectangleStruct area(pixel.X - width / 2, pixel.Y - height / 2, width, height);
        Map.RadarDirty = Intersect(Union(Map.RadarDirty, RectangleStruct(Map.RadarRect.X + area.X, Map.RadarRect.Y + area.Y, width, height)), Map.RadarRect, NULL, NULL);
        for (int yy = area.Y; yy < area.Y + area.Height; yy++) {
            for (int xx = area.X; xx < area.X + area.Width; xx++) {
                Map.Radar_Pixel(Point2D(xx, yy));
            }
        }
    }
}

bool BeaconClass::Is_Visible() const
{
    if (IsActive && PlayerPtr->Is_Ally(Owner) && Houses[Owner]->Is_Ally(PlayerPtr)) {
        return true;
    }
    return false;
}

BeaconManagerClass::BeaconManagerClass()
{
    memset(Beacons, 0, sizeof(Beacons));
    Count = 0;
    BlinkRate = 0;
}

BeaconManagerClass::~BeaconManagerClass()
{
    Clear();
}

void BeaconManagerClass::Clear()
{
    if (Count) {
        for (int house = 0; house < 8; house++) {
            for (int index = 0; index < 3; index++) {
                if (Beacons[house][index] != NULL) {
                    delete Beacons[house][index];
                    Beacons[house][index] = NULL;
                }
            }
        }
        Count = 0;
    }
}

void BeaconManagerClass::Init()
{
    RawFileClass file("PBEACON.SHP");
    BeaconShape = (ShapeFileStruct *)Load_Alloc_Data(file);
    if (BeaconShape == NULL) {
        BeaconShape = (ShapeFileStruct *)MFCD_Retrieve("PBEACON.SHP");
    }
    if (BeaconShape != NULL) {
        BeaconWidth = BeaconShape->Width;
        BeaconHeight = BeaconShape->Height;
        BeaconFrames = BeaconShape->Count;
    } else {
        Debug_Printf("Failed to load BeaconArt");
    }

    RawFileClass radarfile("RDRBEACN.SHP");
    RadarBeaconShape = (ShapeFileStruct *)Load_Alloc_Data(radarfile);
    if (RadarBeaconShape == NULL) {
        RadarBeaconShape = (ShapeFileStruct *)MFCD_Retrieve("RDRBEACN.SHP");
    }
    if (RadarBeaconShape != NULL) {
        RadarWidth = RadarBeaconShape->Width;
        RadarHeight = RadarBeaconShape->Height;
        RadarFrames = RadarBeaconShape->Count;
        BlinkRate = RadarFrames * 4;
    } else {
        Debug_Printf("Failed to load RadarBeaconArt");
    }
}

void BeaconManagerClass::Draw(Surface * surface, RectangleStruct window)
{
    if (Count) {
        for (int house = 0; house < 8; house++) {
            for (int index = 0; index < 3; index++) {
                BeaconClass * beacon = Beacons[house][index];
                if (beacon != NULL && beacon->Is_Visible()) {
                    beacon->Draw(surface, window);
                }
            }
        }
    }
}

void BeaconManagerClass::Place(int owner, CoordStruct coord, int slot)
{
    if (!Has_Free_Slot(owner) && slot == -1) {
        return;
    }
    bool full = false;
    BeaconClass * beacon = new BeaconClass();
    if (slot == -1) {
        full = true;
        int index;
        for (index = 0; index < 3; index++) {
            if (Beacons[owner][index] == NULL) {
                full = false;
                break;
            }
        }
        if (!full) {
            slot = index;
            Beacons[owner][slot] = beacon;
        }
    } else {
        if (Beacons[owner][slot] != NULL) {
            delete Beacons[owner][slot];
            Count--;
        }
        Beacons[owner][slot] = beacon;
    }
    if (full) {
        delete beacon;
        return;
    }
    beacon->Set(coord, owner);
    Count++;

    if (Session.Type != GAME_NORMAL && Session.Type != GAME_SKIRMISH) {
        if (owner == PlayerPtr->ArrayIndex) {
#line 810 "C:\\RA2\\Beacon.CPP"
            SessionMessages.Add_Message(NULL, 0, Fetch_String("TXT_BEACON_HELP1", NULL, __FILE__, __LINE__), PlayerPtr->ColorSchemeIndex, 0x4046, 225, false);
            SessionMessages.Add_Message(NULL, 0, Fetch_String("TXT_BEACON_HELP2", NULL, __FILE__, __LINE__), PlayerPtr->ColorSchemeIndex, 0x4046, 225, false);
            Speak("EVA_BeaconPlaced");
            Play_Sound(Rule->BeaconSound, 1.0f, 0x2000, 0);
            GlobalPacketType packet;
            packet.Command = NET_BEACON_PLACE;
            strcpy(packet.Name, To_Narrow(SessionPlayers[0]->Name));
            packet.Location.X = coord.X;
            packet.Location.Y = coord.Y;
            packet.Location.Z = coord.Z;
            packet.Location.B = slot;
            packet.Location.A = owner;
            for (int index = 1; index < SessionPlayers.ActiveCount; index++) {
                Debug_Printf("Sending beacon placement to %s\n", SessionPlayers[index]->Name);
                Ipx.Send_Global_Message(&packet, 0x3d, 1, &SessionPlayers[index]->Address);
            }
        } else if (beacon->Is_Visible()) {
            Radar_Event(1, Coord_Cell(coord));
            Speak("EVA_BeaconDetected");
        }
    }
}

bool BeaconManagerClass::Has_Free_Slot(int owner)
{
    for (int index = 0; index < 3; index++) {
        if (Beacons[owner][index] == NULL) {
            return true;
        }
    }
    return false;
}

Point2D BeaconManagerClass::Func_42E6E0()
{
    return Point2D(0, 0);
}

bool BeaconManagerClass::Select_Near(CoordStruct coord)
{
    BeaconClass * beacon = Find_Near(coord);
    if (beacon != NULL) {
        ::Unselect_All();
        beacon->IsSelected = true;
        return true;
    }
    return false;
}

void BeaconManagerClass::Unselect_All()
{
    if (Count) {
        for (int house = 0; house < 8; house++) {
            for (int index = 0; index < 3; index++) {
                if (Beacons[house][index] != NULL) {
                    Beacons[house][index]->IsSelected = false;
                }
            }
        }
    }
}

BeaconClass * BeaconManagerClass::Find_Near(CoordStruct coord)
{
    if (Count) {
        for (int house = 0; house < 8; house++) {
            for (int index = 0; index < 3; index++) {
                if (Beacons[house][index] != NULL) {
                    if (Coord_Length(coord - Beacons[house][index]->Coord) < 128) {
                        return Beacons[house][index];
                    }
                }
            }
        }
    }
    return NULL;
}

BeaconClass * BeaconManagerClass::Find_Selected(int owner)
{
    if (Count) {
        for (int house = 0; house < 8; house++) {
            for (int index = 0; index < 3; index++) {
                BeaconClass * beacon = Beacons[house][index];
                if (beacon != NULL && beacon->IsSelected) {
                    if (owner == -1) {
                        return beacon;
                    }
                    if (owner == beacon->Owner) {
                        return beacon;
                    }
                }
            }
        }
    }
    return NULL;
}

void BeaconManagerClass::Delete(int owner, int slot)
{
    if (Count) {
        bool local;
        BeaconClass * beacon;
        local = owner == -1 && slot == -1;
        if (local) {
            beacon = Find_Selected(-1);
        } else {
            beacon = Beacons[owner][slot];
        }
        if (beacon != NULL) {
            int house = beacon->Owner;
            if (house != PlayerPtr->ArrayIndex && local) {
                beacon->IsActive = false;
                beacon->IsSelected = false;
                return;
            }
            if (beacon->Is_Visible()) {
                beacon->Draw_Radar(Map.RadarSurface, Map.RadarSurface->Get_Rect(), true);
            }
            delete beacon;
            for (int index = 0; index < 3; index++) {
                if (beacon == Beacons[house][index]) {
                    Beacons[house][index] = NULL;
                    Count--;
                    if (Session.Type != GAME_NORMAL && Session.Type != GAME_SKIRMISH && house == PlayerPtr->ArrayIndex && local) {
                        GlobalPacketType packet;
                        packet.Command = NET_BEACON_DELETE;
                        strcpy(packet.Name, To_Narrow(SessionPlayers[0]->Name));
                        packet.Location.A = house;
                        packet.Location.B = index;
                        for (int player = 1; player < SessionPlayers.ActiveCount; player++) {
                            Debug_Printf("Sending beacon delete to %s\n", SessionPlayers[player]->Name);
                            Ipx.Send_Global_Message(&packet, 0x3d, 1, &SessionPlayers[player]->Address);
                        }
                    }
                    return;
                }
            }
        }
    }
}

void BeaconManagerClass::Set_Text(wchar_t const * text, int owner, int slot, bool send)
{
    bool local;
    BeaconClass * beacon;
    local = owner == -1 && slot == -1;
    if (local) {
        beacon = Find_Selected(-1);
    } else {
        beacon = Beacons[owner][slot];
    }
    if (beacon != NULL) {
        beacon->Set_Text(text);
        if (Session.Type != GAME_NORMAL && Session.Type != GAME_SKIRMISH) {
            if (local && beacon->Owner == PlayerPtr->ArrayIndex && send) {
                GlobalPacketType packet;
                packet.Command = NET_BEACON_TEXT;
                strcpy(packet.Name, To_Narrow(SessionPlayers[0]->Name));
                if (text != NULL) {
                    wcsncpy(packet.Raw.Text, text, 128);
                } else {
                    wcscpy(packet.Raw.Text, To_Wide(NullString));
                }
                packet.Raw.A = PlayerPtr->ArrayIndex;
                packet.Raw.B = -1;
                for (int index = 0; index < 3; index++) {
                    if (Beacons[packet.Raw.A][index] == beacon) {
                        packet.Raw.B = index;
                    }
                }
                if (packet.Raw.B != -1) {
                    for (int player = 1; player < SessionPlayers.ActiveCount; player++) {
                        Debug_Printf("Sending beacon text to %s\n", SessionPlayers[player]->Name);
                        Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &SessionPlayers[player]->Address);
                    }
                }
            } else if (beacon->Owner != PlayerPtr->ArrayIndex && beacon->Is_Visible()) {
                CoordStruct coord = beacon->Coord;
                Radar_Event(1, Coord_Cell(coord));
            }
        }
    }
}

void BeaconManagerClass::Draw_Radar(Surface * surface, RectangleStruct window)
{
    if (Count && Frame % BlinkRate < BeaconManager.RadarFrames + 1) {
        for (int house = 0; house < 8; house++) {
            for (int index = 0; index < 3; index++) {
                BeaconClass * beacon = Beacons[house][index];
                if (beacon != NULL && beacon->Is_Visible()) {
                    beacon->Draw_Radar(surface, window, false);
                }
            }
        }
    }
}

bool BeaconManagerClass::Is_Blinking()
{
    if (Count) {
        bool found = false;
        for (int house = 0; house < 8; house++) {
            for (int index = 0; index < 3; index++) {
                BeaconClass * beacon = Beacons[house][index];
                if (beacon != NULL && beacon->Is_Visible()) {
                    found = true;
                    break;
                }
            }
        }
        if (found && Frame % BlinkRate < BeaconManager.RadarFrames + 1) {
            return true;
        }
    }
    return false;
}
