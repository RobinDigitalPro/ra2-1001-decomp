// C:\RA2\WDTSel.cpp (level-2 reconstruction of GAME.EXE 1.001)
// WorldDominationTour::Selection: the World Domination Tour territory selection screen. It is an
// MSEngine (animation engine) that shows the campaign map, replays the history of the campaign,
// lets the player pick a territory with a conflict and starts the chosen battle.
// Class names come from RTTI (.?AVSelection@WorldDominationTour@@ : MSEngine, Campaign, Conflict,
// Map, State, Territory, History, CampaignProperties, WDTTerritory, rc_ptr, VectorCursor,
// DynamicVectorClass, MSAnim, MSShapeAnim, MSFadeAnim, MSBitPrintAnim, MSFont, MSSfxEntry, INIClass,
// CCFileClass); all other names are provisional.
//
// TU boundary: this file starts with the 16-byte zeroing initializer 0x321f30 (its .bss 0xb0d3c8 lies
// inside this file's GAMECONST data 0xb0d3c0..0xb0d434, as in WorldDom.cpp), followed by the GAMECONST
// initializers 0x321f50..0x322110; its code runs from 0x322120 to 0x3250c7. The zeroing initializer
// 0x3250d0 (.bss 0xb0d440, just before the next file's GAMECONST data 0xb0d450..) starts the next file.

// Dynamic initializer 0x321f30: 16 bytes at 0xb0d3c8, written nowhere else (WDTProps.cpp currently
// also defines it; it belongs here).
struct WDTSelUnknownStruct {
    WDTSelUnknownStruct() : A(0), B(0), C(0), D(0) {}
    int A;
    int B;
    int C;
    int D;
};
static WDTSelUnknownStruct WDTSelUnknown;

#include "GAMECONST.H"

// ---- local declarations (to be moved to headers by the integrator) ----
#include <stddef.h>
#include "SURFACE.H"
#include "BLIT.H"

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x2eeb60 (also in ABSTYPE.H)

// Copy of VECTOR.H plus the constructors that VECTOR.H does not have yet (as in ToolTip.cpp).
template<class T> class VectorClass {
public:
    VectorClass(unsigned size = 0, T const * array = 0) :
        Vector(0), VectorMax(size), IsInitialized(true), IsAllocated(false)
    {
        if (size) {
            if (array) {
                Vector = (T *)array;
            } else {
                Vector = new T[size];
                IsAllocated = true;
            }
        }
    }
    virtual ~VectorClass() { VectorClass<T>::Clear(); }
    virtual bool operator == (VectorClass<T> const & vector) const;
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr);
    virtual int ID(T const & object);
    virtual T Fetch(int index) const { return Vector[index]; }

    T & operator[](unsigned index) { return Vector[index]; }
    T const & operator[](unsigned index) const { return Vector[index]; }
    int Length() const { return VectorMax; }

    T * Vector;
    int VectorMax;
    bool IsInitialized;
    bool IsAllocated;
};

template<class T> void VectorClass<T>::Clear(void)
{
    if (Vector && IsAllocated) {
        delete [] Vector;
        Vector = 0;
    }
    IsAllocated = false;
    VectorMax = 0;
}

template<class T> class DynamicVectorClass : public VectorClass<T> {
public:
    DynamicVectorClass(unsigned size = 0, T const * array = 0) : VectorClass<T>(size, array)
    {
        GrowthStep = 10;
        ActiveCount = 0;
    }
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr) { return VectorClass<T>::ID(ptr); }
    virtual int ID(T const & object);

    int Count() const { return ActiveCount; }
    int Add(T const & object);

    int ActiveCount;
    int GrowthStep;
};

template<class T> inline int DynamicVectorClass<T>::Add(T const & object)
{
    if (ActiveCount >= Length()) {
        if ((IsAllocated || !VectorMax) && GrowthStep > 0) {
            if (!Resize(Length() + GrowthStep)) {
                return false;
            }
        } else {
            return false;
        }
    }
    (*this)[ActiveCount++] = object;
    return true;
}

// Simple owned narrow string, one pointer (library code near 0x359250; name provisional).
class CharStringClass {
public:
    CharStringClass();                                          // 0x359250
    CharStringClass(char const * string);                       // 0x359260
    CharStringClass(CharStringClass const & string);            // 0x3592c0
    ~CharStringClass();                                         // 0x359320
    bool operator == (char const * string) const;               // 0x359340
    bool operator == (CharStringClass const & string) const;    // 0x3593b0
    bool operator != (char const * string) const;               // 0x359420
    CharStringClass & operator = (CharStringClass const & string);   // 0x359570
    CharStringClass operator + (char const * string) const;    // 0x3599d0
    char const * Peek_Buffer() const;                           // 0x35a030 (Buffer or NullString)
    char * Buffer;
};
CharStringClass Int_To_String(int value);                       // 0x35aec0 ("%d")
extern char NullString[];                                       // 0x8248a4 (.bss); name provisional

// Simple owned wide string, one pointer (library code near 0x35b2f0; name provisional).
class WideStringClass {
public:
    WideStringClass();                                          // 0x35b2f0
    WideStringClass(wchar_t const * string);                    // 0x35b300
    WideStringClass(WideStringClass const & string);            // 0x35b350
    ~WideStringClass();                                         // 0x35b390
    WideStringClass & operator = (WideStringClass const & string);   // 0x35b510
    WideStringClass & operator += (wchar_t const * string);     // 0x35b710
    WideStringClass & operator += (WideStringClass const & string);  // 0x35b790
    WideStringClass operator + (wchar_t const * string) const;  // 0x35b810
    WideStringClass operator + (WideStringClass const & string) const;   // 0x35b8e0
    unsigned Get_Length() const;                                // 0x35bde0
    wchar_t * Buffer;
};
WideStringClass Int_To_WideString(int value, int width);       // 0x35ca70 (zero-padded)
WideStringClass operator + (wchar_t const * string1, WideStringClass const & string2);   // 0x35ccc0
extern wchar_t NullWString[];                                   // 0x82208c (.bss), shared empty wide string

// Keyboard object (see Egos.CPP).
class WWKeyboardClass {
public:
    unsigned short Check();                 // 0x530530
    unsigned short Get();                   // 0x530580
    void Clear();                           // 0x530c50
};
extern WWKeyboardClass * Keyboard;          // 0x81a7a8

enum {
    KN_LMOUSE = 0x0001,
    KN_RLSE_BIT = 0x0800,
    KN_ESC = 0x001b
};

// Mouse object (0x821fa8); only the virtual slots used here are named.
class WWMouseClass {
public:
    virtual ~WWMouseClass();
    virtual void Virtual_01();
    virtual void Virtual_02();
    virtual void Hide_Mouse();              // +0x0c
    virtual void Show_Mouse();              // +0x10
    virtual void Virtual_05();
    virtual void Virtual_06();
    virtual void Virtual_07();
    virtual void Virtual_08();
    virtual void Virtual_09();
    virtual int Get_Mouse_State();          // +0x28 (negative while hidden)
    virtual int Get_Mouse_X();              // +0x2c
    virtual int Get_Mouse_Y();              // +0x30
};
extern WWMouseClass * WWMouse;              // 0x821fa8

extern Surface * AlternateSurface;          // 0x821c98
extern Surface * HiddenSurface;            // 0x821c94
extern Surface * VisibleSurface;             // 0x821c90 (name provisional)

// Music (see Egos.CPP, MPScore.cpp).
class ThemeClass {
public:
    void Queue_Song(int theme);             // 0x6dd0e0
    void Play_Song(int theme);              // 0x6dd170
    int From_Name(char const * name);       // 0x6dd7d0
    char Unknown00[0x10];
    bool Field10;                           // +0x10 (0xa1e0b8); meaning unknown
};
extern ThemeClass Theme;                    // 0xa1e0a8

// RTTI .?AVBitFont@@ (vtable 0x787788).
class BitFont {
public:
    virtual ~BitFont();
    unsigned short Set_Color(unsigned short color);   // 0x4312f0 (returns the old colour)
};
extern BitFont * TextFont;                  // 0x836d30 (provisional)

extern int WDTTextColor;                    // 0xa5af44 (RGB value; name provisional)
extern bool Flag_A28984;                    // 0xa28984 (see Restate.cpp)
bool Func_732A40();                         // 0x732a40 (see CampScor.cpp/WorldDom.cpp)

// Game setup globals written for the chosen battle (Session fields 0xa255c8 + n; names provisional).
extern int WDTScenarioID;                   // 0xa255d0
extern int WDTSetting_A25600;               // 0xa25600
extern int BuildLevel;                      // 0x7c3978
extern int WDTSetting_A255EC;               // 0xa255ec
extern bool WDTSetting_A2566D;              // 0xa2566d
extern bool WDTSetting_A2566C;              // 0xa2566c
extern bool WDTSetting_A255E8;              // 0xa255e8
extern bool WDTSetting_A2566F;              // 0xa2566f
extern bool WDTSetting_A25670;              // 0xa25670
extern bool WDTSetting_A255F0;              // 0xa255f0
extern bool WDTSetting_A255F1;              // 0xa255f1
extern bool WDTSetting_A255F2;              // 0xa255f2
extern bool WDTSetting_A255F4;              // 0xa255f4
extern bool WDTSetting_A255F3;              // 0xa255f3
extern int WDTSetting_A25604;               // 0xa25604
extern int WDTSetting_A25608;               // 0xa25608

// 16-bit pixel from RGB components with the shifts of BLIT.H (as in LdPrgMgr.cpp).
// level-2 1.001: STEERING split packed channels before font colour conversion (GetRValue/GetGValue/GetBValue
// shapes: byte results; green through the low 16 bits, so VC6 reads the colour once and takes green with mov bl,dh).
static inline unsigned char Red_Component(int color) { return (unsigned char)color; }
static inline unsigned char Green_Component(unsigned short color) { return (unsigned char)(color >> 8); }
static inline unsigned char Blue_Component(int color) { return (unsigned char)(color >> 16); }

inline int RGB_To_Pixel(int red, int green, int blue)
{
    return ((red >> BlitFormat.RedShiftLeft) << BlitFormat.RedShiftRight)
        | ((green >> BlitFormat.GreenShiftLeft) << BlitFormat.GreenShiftRight)
        | ((blue >> BlitFormat.BlueShiftLeft) << BlitFormat.BlueShiftRight);
}

// File class hierarchy, as in WDTTerr.cpp (signatures provisional).
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
    char RawFileData[0x1C];
};

class BufferIOFileClass : public RawFileClass {
public:
    virtual ~BufferIOFileClass();       // 0x42f250
private:
    char BufferIOData[0x34];
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}           // out-of-line copy 0x51a280
    virtual char const * Set_Name(char const * filename);   // 0x46fd50
};

// level-2 1.001: Buffer (ctor 0x438140, dtor 0x438290) comes from BUFFER.H through SURFACE.H.

class CCFileClass : public CDFileClass {
public:
    CCFileClass(char const * filename);                     // 0x468b70
    CCFileClass(CharStringClass const & filename);          // 0x468bb0
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual void Close();                                   // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// Doubly linked list and sorted index (as in Restate.cpp; the index constructor is inline here).
class GenericNode {
public:
    virtual ~GenericNode();
private:
    GenericNode * NextNode;
    GenericNode * PrevNode;
};

class GenericList {
public:
    GenericList();                      // 0x490c60
    virtual ~GenericList();
private:
    GenericNode FirstNode;
    GenericNode LastNode;
};

template<class T>
class List : public GenericList {
};

template<class INDEX, class DATA>
class IndexClass {
public:
    IndexClass() : IndexTable(0), IndexCount(0), IndexSize(0), IsSorted(false), Archive(0) {}
    ~IndexClass();
private:
    void * IndexTable;
    int IndexCount;
    int IndexSize;
    bool IsSorted;
    void const * Archive;
};

// RTTI .?AVINIClass@@ (vtable 0x78db34).
class INIClass {
public:
    struct INISection;

    INIClass() : Unknown34(0) {}
    virtual ~INIClass();                                                        // 0x50ad20
    int Load(FileClass & file, bool withdigest);                                // 0x50b030
    int Entry_Count(CharStringClass const & section) const;                     // 0x50c020
    CharStringClass Get_Entry(CharStringClass const & section, int index) const;   // 0x50c320
    int Get_Int(CharStringClass const & section, CharStringClass const & entry, int defvalue) const;   // 0x50ce20
    int Get_String(CharStringClass const & section, CharStringClass const & entry,
        CharStringClass const & defvalue, CharStringClass & result) const;    // 0x50df90
private:
    List<INISection *> SectionList;                 // +0x04
    IndexClass<int, INISection *> SectionIndex;     // +0x20
    int Unknown34;                                  // +0x34
};

// RTTI .?AVReferenceCounted@@, vtable 0x793cd4.
class ReferenceCounted {
public:
    ReferenceCounted() : ReferenceCount(0) {}
    virtual ~ReferenceCounted();                 // 0x230cb0 (deleting 0x230cf0)
    virtual bool Is_Kind(int kind) const;        // 0x230ce0
    virtual void Release();                      // 0x230cc0
    void Add_Ref() { ++ReferenceCount; }
    int ReferenceCount;
};

// RTTI .?AVrc_ptr_base@@, vtable 0x793ccc.
class rc_ptr_base {
public:
    rc_ptr_base();                               // 0x230a80
    rc_ptr_base(ReferenceCounted * pointer);     // 0x230a90
    rc_ptr_base(rc_ptr_base const & other);      // 0x230b00
    virtual ~rc_ptr_base();                      // 0x230ab0 (deleting 0x230b20)
    void Set(ReferenceCounted * pointer);        // 0x230ad0
protected:
    ReferenceCounted * Pointer;
};

// Provisional model of the accessors, chosen from this file's code: the const operator-> is a plain
// expression; the non-const one is a statement-level function that VC6 inlines with a temporary
// (unfolded "add eax,8 / mov eax,[eax+4]") and sometimes declines to inline (out-of-line copies
// 0x324e90/0x324ee0/0x324ef0). Get() gives the plain access where the original uses it.
template<class T>
class rc_ptr : public rc_ptr_base {
public:
    rc_ptr() {}
    rc_ptr(T * pointer) { Set(pointer); }
    rc_ptr(rc_ptr<T> const & other) { Set(other.Pointer); }
    virtual ~rc_ptr() {}
    rc_ptr<T> & operator = (rc_ptr<T> const & other) { Set(other.Pointer); return *this; }
    void Clear() { Set(NULL); }
    T * Get() const { return (T *)Pointer; }
    T * operator -> () const { return (T *)Pointer; }
    T * operator -> ();
    bool operator == (rc_ptr<T> const & other) const { return Pointer == other.Pointer; }
    bool operator != (rc_ptr<T> const & other) const { return Pointer != other.Pointer; }
};

template<class T>
T * rc_ptr<T>::operator -> ()
{
    if (Pointer != NULL) {
        return (T *)Pointer;
    }
    return NULL;
}

// RTTI .?AV?$VectorCursor@...@@ (4 slots: destructor, Is_Valid, operator++, operator--).
template<class T, class V>
class VectorCursor {
public:
    VectorCursor(V & vector, int index = 0) : Vector(&vector), Index(index) {}
    virtual ~VectorCursor() {}
    virtual bool Is_Valid() const { return (unsigned)Index < (unsigned)Vector->ActiveCount; }
    virtual VectorCursor<T, V> & operator ++ () { ++Index; return *this; }
    virtual VectorCursor<T, V> & operator -- () { --Index; return *this; }
    T & operator * () const { return Vector->Vector[Index]; }
    V * Vector;
    int Index;
};

// RTTI .?AVMSAnim@@, vtable 0x791d10 (9 slots).
class MSAnim {
public:
    virtual ~MSAnim();
    virtual void Set_Visible(bool visible);
    virtual void Virtual_02();
    virtual void Virtual_03();
    virtual void Virtual_04() = 0;
    virtual void Virtual_05() = 0;
    virtual void Virtual_06() = 0;
    virtual void Virtual_07();
    virtual void Virtual_08();
};

// Shape file name used by the shape animations (0x5ae0a0, size 0x10; class name unknown).
class MSShapeName : public CharStringClass {
public:
    MSShapeName(CharStringClass const & name);      // 0x5ae0a0
    int Unknown04[3];
};

// Palette loaded from a file (0x5a9140); only the virtual destructor is used.
class MSPalette {
public:
    virtual ~MSPalette();
};
MSPalette * Load_Palette(CharStringClass const & filename);    // 0x5a9140

// RTTI .?AVMSShapeAnim@@ : MSAnim (vtable 0x791d38), size 0x40.
class MSShapeAnim : public MSAnim {
public:
    MSShapeAnim(CharStringClass const & filename, int x, int y, MSPalette * palette, int a, int b, int c);   // 0x5a9280
    void Set_Frame(int frame);              // 0x5a9340
    void Set_Start_Frame(int frame);        // 0x5a93f0 (+0x2c)
    void Set_End_Frame(int frame);          // 0x5a9410 (+0x30)
    virtual void Virtual_04();
    virtual void Virtual_05();
    virtual void Virtual_06();
private:
    char ShapeData[0x3c];
};

// RTTI .?AVMSFadeAnim@@ : MSShapeAnim (vtable 0x791d60), size 0x48.
class MSFadeAnim : public MSShapeAnim {
public:
    MSFadeAnim(CharStringClass const & filename, int x, int y, MSPalette * palette, int a, int b,
        DynamicVectorClass<MSAnim *> * list);   // 0x5a9990
private:
    char FadeData[0x8];
};

// RTTI .?AVMSBitPrintAnim@@ : MSAnim (vtable 0x791e00), size 0x34.
class MSBitPrintAnim : public MSAnim {
public:
    MSBitPrintAnim(WideStringClass const & text, RectangleStruct const & rect, bool unknown);   // 0x5ab060
    void Set_Centered(bool centered);       // 0x5ab0f0 (+0x30)
    virtual void Virtual_04();
    virtual void Virtual_05();
    virtual void Virtual_06();
private:
    char PrintData[0x30];
};

// RTTI .?AVMSFont@@ (vtable 0x79208c), size 0x20.
class MSFont {
public:
    MSFont(char const * name);              // 0x5b0b20
    virtual ~MSFont();
private:
    char FontData[0x1c];
};

// Named sound effect (0x5ae190, size 0x10).
class MSSfxEntry {
public:
    MSSfxEntry(CharStringClass const & name, CharStringClass const & sound);   // 0x5ae190
    ~MSSfxEntry();                          // 0x5ae2a0
    void Play();                            // 0x5ae2b0 (empty)
    CharStringClass Name;
    int Unknown04[3];
};

// RTTI .?AVMSEngine@@, vtable 0x791ffc (3 slots), size 0x48.
class MSEngine {
public:
    MSEngine();                                      // 0x5af7c0
    virtual ~MSEngine();                             // 0x5af850 (deleting 0x5b0420)
    virtual void Virtual_01();
    virtual void Virtual_02();
    void Add_Anim(MSAnim * anim);                    // 0x5af940
    void Remove_Anim(MSAnim * anim);                 // 0x5afaa0
    void Remove_Anim_Later(MSAnim * anim, int delay);   // 0x5afb10
    void Add_Dirty(RectangleStruct const & rect);    // 0x5afcf0
    void Redraw(int frames);                         // 0x5b0130 (WDTTerr.cpp declares bool)
    void Process();                                  // 0x5b0250
    int Unknown04;
    VectorClass<void *> Unknown08;                   // +0x08
    DynamicVectorClass<MSAnim *> Anims;              // +0x18
    DynamicVectorClass<void *> Unknown30;            // +0x30
};

// RTTI .?AVWDTTerritory@@, vtable 0x79a168. Only the fields read here are named.
class WDTTerritory : public ReferenceCounted {
public:
    char Unknown08[6];               // +08
    unsigned char Value0E;           // +0E
    unsigned char Value0F;           // +0F
    unsigned short Value10;          // +10
    char Unknown12[0x38 - 0x12];     // +12
    unsigned Flag0:1;                // +38 (bit field of the territory flags)
    unsigned Flag1:1;
    unsigned Flag2:1;
    unsigned Flag3:1;
    unsigned Flag4:1;
    unsigned Flag5:1;
    unsigned Flag6:1;
    unsigned Flag7:1;
    unsigned Flag8:1;
    unsigned Flag9:1;
    unsigned Flag10:1;
};

namespace WorldDominationTour {

class Selection;

// RTTI .?AVCampaignProperties@WorldDominationTour@@ (see WDTProps.cpp).
class CampaignProperties : public ReferenceCounted {
public:
    int Is_Available() const;               // 0x321e60
    int Is_Enabled() const;                 // 0x321e70
    int Last_Stage() const;                 // 0x321e90
    char Unknown08[8];                       // +08 (rc_ptr<WDTState>)
    WideStringClass ShortDescription;       // +10
    WideStringClass LongDescription;        // +14
};

// RTTI .?AVState@WorldDominationTour@@, vtable 0x79a25c, size 0x14.
class State : public ReferenceCounted {
public:
    static rc_ptr<State> Create();          // 0x325350
    int Get_Owner(int territory) const;     // 0x325450
    int Get_Score(int side) const;          // 0x3254c0
};

// RTTI .?AVHistory@WorldDominationTour@@, vtable 0x79a024.
class History : public ReferenceCounted {
public:
    rc_ptr<State> Get_State(int stage);     // 0x31dac0
};

// RTTI .?AVConflict@WorldDominationTour@@, vtable 0x799f0c.
class Conflict : public ReferenceCounted {
public:
    int Territory_ID() const;               // 0x31bfb0
    WideStringClass Describe() const;       // 0x31c520
    rc_ptr<WDTTerritory> Territory;         // +08
};

// RTTI .?AVCampaign@WorldDominationTour@@, vtable 0x799e84. Only the members used here.
class Campaign : public ReferenceCounted {
public:
    int Get_Faction() const { return Side; }
    int Map_Variant(int theater);           // 0x31af30
    int Stage(int theater);                 // 0x31af60
    void Finish_Review(int theater);        // 0x31af70
    rc_ptr<CampaignProperties> Properties;  // +08
    rc_ptr<History> History;                // +10
    DynamicVectorClass<rc_ptr<Conflict> > Conflicts;   // +18
    int Unknown30;                          // +30
    int Stages[4];                          // +34
    int Side;                               // +44
};

// RTTI .?AVTerritory@WorldDominationTour@@ (see WDTTerr.cpp).
class Territory : public ReferenceCounted {
public:
    static rc_ptr<Territory> Find(DynamicVectorClass<rc_ptr<Territory> > & list, int id);   // 0x325d70
    void Set_State(int state, MSEngine & engine, int unused);   // 0x325b70
    void Show_Highlight(bool show, MSEngine & engine);          // 0x325ce0
    void Set_Pending(int value);            // 0x325d50
    int Take_Pending();                     // 0x325d60

    int ID;                          // +08
    WideStringClass Name;            // +0C
    Point2D Target;                  // +10
    Point2D Origin;                  // +18
    CharStringClass ShapeName;       // +20
    MSAnim * OverlayAnim;            // +24
    MSAnim * HighlightAnim;          // +28
    int Pending;                     // +2C (an MSShapeAnim set by Set_Pending)
};

// Voice-over player embedded in the selection screen (0x326080..; class name provisional,
// RTTI only has .?AVAnim@Voices@WorldDominationTour@@), size 0x3dc.
class Voices {
public:
    Voices(int side);                                                   // 0x326080
    ~Voices();                                                          // 0x326240
    void Load(INIClass & ini, CharStringClass const & section);         // 0x326360
    MSAnim * Create_Anim();                                             // 0x327610
    void Play(int category, int type, bool flag, bool queue, int delay);   // 0x3270d0
    void Play_Prompt(int type, int unknown, int delay);                 // 0x3272c0
    bool Is_Playing();                                                  // 0x327600
private:
    char VoiceData[0x3dc];
};

// RTTI .?AVMap@WorldDominationTour@@, vtable 0x79a07c, size 0xd4. Only the members used here.
class Map : public ReferenceCounted {
public:
    static rc_ptr<Map> Create(int enabled, int theater, int side);     // 0x31dea0
    void Load(INIClass & ini, MSEngine & engine, int variant);          // 0x31e0d0
    void Start(MSEngine & engine, Voices & voices);                     // 0x31f1e0
    int Territory_At(Point2D const & point);                            // 0x31f220
    void Press_Back(MSEngine & engine, bool pressed);                   // 0x31f290
    void Highlight_Back(MSEngine & engine, bool highlight);             // 0x31f2e0
    bool Is_Over_Back(Point2D const & point);                           // 0x31f330
    rc_ptr<Territory> Find_Territory(int id);

    char Unknown08[0x2c - 0x08];
    DynamicVectorClass<rc_ptr<Territory> > Territories;   // +2C
    Point2D Offset;                  // +44
    char Unknown4C[0x68 - 0x4c];
    bool BackHighlighted;            // +68
    char Unknown69[0x7c - 0x69];
    RectangleStruct TitleRect;       // +7C
    RectangleStruct TextRect;        // +8C
    RectangleStruct PlayRect;        // +9C
    RectangleStruct BackRect;        // +AC
};

inline rc_ptr<Territory> Map::Find_Territory(int id)
{
    return Territory::Find(Territories, id);
}

typedef VectorCursor<rc_ptr<Territory>, DynamicVectorClass<rc_ptr<Territory> > > TerritoryCursor;
typedef VectorCursor<rc_ptr<Conflict>, DynamicVectorClass<rc_ptr<Conflict> > > ConflictCursor;
typedef VectorCursor<MSSfxEntry *, DynamicVectorClass<MSSfxEntry *> > SoundCursor;
typedef VectorCursor<MSAnim *, DynamicVectorClass<MSAnim *> > AnimCursor;

// RTTI .?AVSelection@WorldDominationTour@@ : MSEngine, vtable 0x79a1fc, size 0x4b0.
class Selection : public MSEngine {
public:
    Selection(rc_ptr<Campaign> const & campaign, int theater);
    virtual ~Selection();

    void Load_Voice_Overs(INIClass & ini, CharStringClass const & section);
    void Load_Sounds(INIClass & ini, CharStringClass const & section);
    void Load_Layout(INIClass & ini, CharStringClass const & section);
    rc_ptr<Territory> Choose_Territory();
    void Handle_Click(Point2D const & mouse, bool & done);
    bool Select_At(Point2D const & mouse);
    void Update_Hover(Point2D const & mouse);
    void Show_State(rc_ptr<State> const & state, bool animate, bool fast);
    bool Select(rc_ptr<Territory> const & territory);
    void Clear_Pending();
    void Clear_Pending2();
    void Enter_Map();
    void Leave_Map();
    void Enter_Back();
    void Leave_Back();
    void Review_History(int theater);
    int Classify(int stage, bool & mega);
    bool Play_Stages(int from, int to);
    void Play_Summary(int theater);
    bool Play_Change(int from, int to);
    void Poll_Input();
    void Set_Title(WideStringClass const & text, int unused);
    void Set_Text(WideStringClass const & text);
    void Play_Sound(CharStringClass const & name);
    void Show_Description();
    void Start();
    void Stop();

    rc_ptr<Campaign> const Campaign;         // +48
    rc_ptr<Conflict> Conflict;               // +50
    Voices Voice;                            // +58
    int WinningThreshold;                    // +434
    int LosingThreshold;                     // +438
    int MegaWinningThreshold;                // +43C
    int MegaLosingThreshold;                 // +440
    bool Aborted;                            // +444
    Point2D LastMouse;                       // +448
    int LastStage;                           // +450
    int MouseState;                          // +454 (1 over the map, 2 over the back button)
    rc_ptr<Map> Map;                         // +458
    int HoverID;                             // +460
    rc_ptr<Territory> Selected;              // +464
    MSPalette * Palette;                     // +46C
    MSShapeName * ZoomingTarget;             // +470
    MSShapeName * Target;                    // +474
    int TargetDividingFrame;                 // +478
    MSBitPrintAnim * Title;                  // +47C
    MSBitPrintAnim * Text;                   // +480
    MSFont * Font;                           // +484
    rc_ptr<State> State;                     // +488
    CharStringClass ThemeName;               // +490
    DynamicVectorClass<MSSfxEntry *> Sounds; // +494
    int OldTextColor;                        // +4AC
};

}

void Func_724B40(rc_ptr<WorldDominationTour::Campaign> const & campaign, int theater);   // 0x324b40
bool Func_724B80(rc_ptr<WorldDominationTour::Campaign> const & campaign, int theater);   // 0x324b80
rc_ptr<WDTTerritory> Conflict_Territory(int id);   // 0x355830 (WorldDom.cpp)
namespace WorldDominationTour {
CharStringClass const & Side_Code(int side);       // 0x354740 (WorldDom.cpp)
}
// ---- end of local declarations ----

// Out-of-line template members that GAME.EXE keeps in this file (0x324e90..0x325080) because VC6
// declined to inline them at some call sites of the large functions below. The explicit
// instantiations emit the same COMDATs while those call sites are not yet reproduced.
template class rc_ptr<WorldDominationTour::CampaignProperties>;
template class rc_ptr<WorldDominationTour::Territory>;
template class rc_ptr<WorldDominationTour::Map>;
template class VectorCursor<rc_ptr<WorldDominationTour::Territory>, DynamicVectorClass<rc_ptr<WorldDominationTour::Territory> > >;
template class VectorCursor<MSSfxEntry *, DynamicVectorClass<MSSfxEntry *> >;
template class VectorClass<MSSfxEntry *>;

using namespace WorldDominationTour;

// level-2 1.001: STEERING share the source coordinate and filename lookup used by both buttons.
static inline WideStringClass Selection_Text(char const * label, int line)
{
    return WideStringClass(Fetch_String(label, NULL, "C:\\RA2\\WDTSel.cpp", line));
}

// 0x322120
#line 130 "C:\\RA2\\WDTSel.cpp"
Selection::Selection(rc_ptr<WorldDominationTour::Campaign> const & campaign, int theater) :
    Campaign(campaign),
    Voice(campaign->Get_Faction()),
    Aborted(false),
    LastMouse(-1, -1),
    LastStage(campaign->Properties->Last_Stage()),
    MouseState(-1),
    Map(Map::Create(campaign->Properties->Is_Enabled(), theater, campaign->Get_Faction())),
    HoverID(-1),
    Palette(NULL),
    ZoomingTarget(NULL),
    Target(NULL),
    TargetDividingFrame(32),
    Title(NULL),
    Text(NULL),
    Font(new MSFont(NULL)),
    State(State::Create()),
    ThemeName(NULL)
{
    int color = WDTTextColor;
    int pixel = RGB_To_Pixel(Red_Component(color), Green_Component(color), Blue_Component(color));
    OldTextColor = TextFont->Set_Color(pixel);
    Add_Anim(Voice.Create_Anim());

    CCFileClass file("WDTMAP.INI");
    INIClass ini;
    ini.Load(file, false);
    Load_Voice_Overs(ini, "VoiceOvers");
    Load_Sounds(ini, "SOUNDS");
    CharStringClass layout;
    ini.Get_String("LAYOUTS", Int_To_String(campaign->Properties->Is_Available()), NullString, layout);
    Load_Layout(ini, layout);
    Map->Load(ini, *this, campaign->Map_Variant(theater));

    WideStringClass play(Selection_Text("GUI:PlayWDT", 157));
    MSBitPrintAnim * anim = new MSBitPrintAnim(play, Map->PlayRect, true);
    anim->Set_Centered(true);
    Add_Anim(anim);

    WideStringClass back(Selection_Text("TXT_BACK", 164));
    anim = new MSBitPrintAnim(back, Map->BackRect, true);
    anim->Set_Centered(true);
    Add_Anim(anim);

    Start();
}



// 0x3227e0
void Selection::Load_Voice_Overs(INIClass & ini, CharStringClass const & section)
{
    Voice.Load(ini, section);
    WinningThreshold = ini.Get_Int(section, "WinningThreshold", WinningThreshold);
    MegaWinningThreshold = ini.Get_Int(section, "MegaWinningThreshold", MegaWinningThreshold);
    LosingThreshold = ini.Get_Int(section, "LosingThreshold", LosingThreshold);
    MegaLosingThreshold = ini.Get_Int(section, "MegaLosingThreshold", MegaLosingThreshold);
}

// 0x3228d0
void Selection::Load_Sounds(INIClass & ini, CharStringClass const & section)
{
    CharStringClass value;
    int count = ini.Entry_Count(section);
    for (int index = 0; index < count; index++) {
        CharStringClass entry = ini.Get_Entry(section, index);
        if (entry != NULL && ini.Get_String(section, entry, NULL, value) > 0) {
            if (entry == "Theme") {
                ThemeName = value;
                break;
            }
            MSSfxEntry * sound = new MSSfxEntry(entry, value);
            if (sound->Name == NULL) {
                delete sound;
            } else if (sound != NULL) {
                Sounds.Add(sound);
            }
        }
    }
}

// 0x322a60
void Selection::Load_Layout(INIClass & ini, CharStringClass const & section)
{
    CharStringClass value;
    CharStringClass prefix(Side_Code(Campaign->Side));
    if (ini.Get_String(section, prefix + "ZoomingTarget", NULL, value) > 0) {
        ZoomingTarget = new MSShapeName(value);
    }
    ini.Get_String(section, prefix + "TargetPalette", NULL, value);
    Palette = Load_Palette(value);
    ini.Get_String(section, prefix + "Target", NULL, value);
    Target = new MSShapeName(value);
    TargetDividingFrame = ini.Get_Int(section, prefix + "TargetDividingFrame", 32);
}

// 0x322c10
rc_ptr<Territory> Selection::Choose_Territory()
{
    Show_Description();
    bool done = false;
    bool canceled = false;
    Keyboard->Clear();
    do {
        Func_732A40();
        Process();
        Point2D mouse(WWMouse->Get_Mouse_X(), WWMouse->Get_Mouse_Y());
        if (Keyboard->Check()) {
            int key = Keyboard->Get();
            if (key == KN_LMOUSE) {
                Handle_Click(mouse, done);
            } else if (key == (KN_LMOUSE | KN_RLSE_BIT)) {
                Map->Press_Back(*this, false);
                if (Map->Is_Over_Back(mouse)) {
                    Play_Sound("Canceled");
                    canceled = true;
                }
            }
        } else if (mouse.X != LastMouse.X || mouse.Y != LastMouse.Y) {
            LastMouse = mouse;
            int state = Map->Is_Over_Back(mouse) ? 2 : 1;
            if (MouseState != state) {
                switch (MouseState) {
                    case 1:
                        Leave_Map();
                        break;
                    case 2:
                        Leave_Back();
                        break;
                }
            }
            switch (state) {
                case 1:
                    if (MouseState != 1) {
                        Enter_Map();
                    }
                    Update_Hover(mouse);
                    break;
                case 2:
                    if (MouseState != 2) {
                        Enter_Back();
                    }
                    break;
            }
            MouseState = state;
        }
        Redraw(1);
    } while (!canceled && !done);
    return done ? Selected : rc_ptr<Territory>();
}

// 0x322ff0
void Selection::Handle_Click(Point2D const & mouse, bool & done)
{
    done = false;
    switch (Map->Is_Over_Back(mouse) ? 2 : 1) {
        case 1:
            Map->Press_Back(*this, false);
            done = Select_At(mouse);
            if (done) {
                Play_Sound("ConflictSelected");
            }
            break;
        case 2:
            Map->Press_Back(*this, true);
            Enter_Back();
            break;
    }
}

// 0x323210
bool Selection::Select_At(Point2D const & mouse)
{
    Update_Hover(mouse);
    rc_ptr<Territory> territory = Map->Find_Territory(HoverID);
    return Select(territory);
}

// 0x3232e0
void Selection::Update_Hover(Point2D const & mouse)
{
    int id = Map.Get()->Territory_At(mouse);
    if (id != HoverID) {
        HoverID = id;
        Select(Map.Get()->Find_Territory(id));
    }
}

// 0x323340
// level-2 1.001: INFERRED stack holder for a target animation's art file.
// level-2 1.001: STEERING keep file destruction at the target-art scope boundary.
struct TargetArtFile {
    explicit TargetArtFile(CharStringClass const & name) : File(name) {}
    CCFileClass File;
};

// level-2 1.001: INFERRED the sound traversal constructs a cursor at the playback site.
struct TargetSoundRange {
    TargetSoundRange(DynamicVectorClass<MSSfxEntry *> & vector, int index);
    SoundCursor Cursor;
};
// level-2 1.001: STEERING retain the out-of-line constructor at the playback site.
#pragma auto_inline(off)
TargetSoundRange::TargetSoundRange(DynamicVectorClass<MSSfxEntry *> & vector, int index)
    : Cursor(vector, index) {}
#pragma auto_inline(on)

// level-2 1.001: INFERRED scoped holder for a territory traversal.
struct TargetTerritoryRange {
    TargetTerritoryRange(DynamicVectorClass<rc_ptr<Territory> > & vector, int index);
    TerritoryCursor Cursor;
};
// level-2 1.001: STEERING preserve the opening cursor constructor call.
#pragma auto_inline(off)
TargetTerritoryRange::TargetTerritoryRange(DynamicVectorClass<rc_ptr<Territory> > & vector, int index)
    : Cursor(vector, index) {}
#pragma auto_inline(on)

// level-2 1.001: INFERRED resolve an optional cached territory entry.
static inline Territory * Target_Territory(TerritoryCursor const & cursor, rc_ptr<Territory> const * entry)
{
    // level-2 1.001: STEERING carry both the indexed slot and its receiver into VC6's call sequence.
    return (entry ? *entry : *cursor).Get();
}

void Selection::Show_State(rc_ptr<WorldDominationTour::State> const & state, bool animate, bool fast)
{
    {
        // level-2 1.001: STEERING retain the opening map accessor call.
        WorldDominationTour::Map * (rc_ptr<WorldDominationTour::Map>::* get_map)() = &rc_ptr<WorldDominationTour::Map>::operator ->;
        TargetTerritoryRange range((Map.*get_map)()->Territories, 0);
        TerritoryCursor & territories = range.Cursor;
        for (TerritoryCursor & cursor = territories; cursor.Is_Valid(); ++cursor) {
            // level-2 1.001: STEERING retain the pending-territory accessor call.
            Territory * (rc_ptr<Territory>::* get_territory)() = &rc_ptr<Territory>::operator ->;
            MSAnim * anim = (MSAnim *)((*cursor).*get_territory)()->Take_Pending();
            if (anim != NULL) {
                Remove_Anim(anim);
            }
        }
    }
    DynamicVectorClass<MSAnim *> zooms;
    DynamicVectorClass<MSAnim *> targets;
    // level-2 1.001: STEERING retain the second cursor constructor call and its frame slot.
    TargetTerritoryRange region(Map.Get()->Territories, 0);
    TerritoryCursor & territories = region.Cursor;
    for (TerritoryCursor & cursor = territories; cursor.Is_Valid(); ++cursor) {
        rc_ptr<Territory> & current = *cursor;
        WorldDominationTour::State * previous = State.Get(); // level-2 1.001: STEERING capture the previous state before the territory ID.
        int id = current->ID;
        int oldowner = previous->Get_Owner(id);
        int owner = state->Get_Owner(id);
        if (owner != oldowner) {
            Poll_Input();
            Target_Territory(cursor, &*cursor)->Set_State(owner, *this, !Aborted || fast);
        }
        if (animate && owner == 1) {
            // level-2 1.001: STEERING capture the territory pointer before the map offset.
            Territory * location = Target_Territory(cursor, &*cursor);
            Point2D const & offset = Map.Get()->Offset;
            int x = location->Target.X + offset.X;
            int y = location->Target.Y + offset.Y;
            if (ZoomingTarget != NULL) {
                CCFileClass file(*ZoomingTarget);
                if (file.Is_Available()) {
                    MSAnim * anim = new MSFadeAnim(*ZoomingTarget, x, y, Palette, 3, 0x200, &Anims);
                    zooms.Add(anim);
                }
            }
            TargetArtFile file(*Target);
            if (file.File.Is_Available()) {
                MSShapeAnim * anim = new MSShapeAnim(*Target, x, y, Palette, 5, 1, 0x200);
                anim->Set_End_Frame(TargetDividingFrame - 1);
                anim->Set_Start_Frame(0);
                anim->Set_Frame(0);
                Target_Territory(cursor, &*cursor)->Set_Pending((int)anim); // level-2 1.001: STEERING resolve the pending slot through Target_Territory (folded element load, as at the other two sites).
                targets.Add(anim);
            }
        }
    }

    AnimCursor zoom_iterator(zooms); // level-2 1.001: STEERING keep the playback zoom cursor alive across both loop tests.
    AnimCursor & zoomcursor = zoom_iterator; // level-2 1.001: STEERING use the cursor reference for playback virtual dispatch.
    AnimCursor target_iterator(targets); // level-2 1.001: STEERING share the target cursor between entry and continuation.
    AnimCursor & target = target_iterator; // level-2 1.001: STEERING use reference dispatch for the continuation test.
    if (target.Is_Valid()) { // level-2 1.001: STEERING entry test through the cursor reference: VC6 folds the freshly stored vptr into call [vtable+4] (meastes 1.006 form, no member pointer).
        do {
            Poll_Input();
            if (zoomcursor.Is_Valid()) {
                if (Aborted) {
                    // level-2 1.001: STEERING retain the explicit cancellation null check.
                    MSAnim * anim = *zoomcursor;
                    if (anim != NULL) {
                        delete anim;
                    }
                } else {
                    {
                        // level-2 1.001: STEERING expand Play_Sound here to preserve its cursor constructor call.
                        CharStringClass name("TargetZoom");
                        if (name != NULL) {
                            TargetSoundRange sounds(Sounds, 0);
                            SoundCursor & scan = sounds.Cursor;
                            for (; scan.Is_Valid() && name == (*scan)->Name; ++scan) {}
                            if (scan.Is_Valid()) {
                                (*scan)->Play();
                            }
                        }
                    }
                    Add_Anim(*zoomcursor);
                    Remove_Anim_Later(*zoomcursor, 300000);
                }
                ++zoomcursor;
            }
            Add_Anim(*target);
            ++target;
        } while (target.Is_Valid()); // level-2 1.001: STEERING recheck the advanced cursor by reference.
    }
    State = state;
}

// 0x323940
bool Selection::Select(rc_ptr<Territory> const & territory)
{
    bool result = Conflict.Get() != NULL;
    if (territory == Selected) {
        return result;
    }
    if (Selected.Get() != NULL) {
        if (Conflict.Get() != NULL) {
            Conflict.Clear();
        }
        Selected->Show_Highlight(false, *this);
        MSShapeAnim * anim = (MSShapeAnim *)Selected->Pending;
        if (anim != NULL) {
            anim->Set_End_Frame(TargetDividingFrame - 1);
            anim->Set_Start_Frame(0);
            anim->Set_Frame(0);
        }
    }
    Selected = territory;
    if (Selected.Get() == NULL) {
        Show_Description();
        Voice.Play_Prompt(1, 0, 30);
        return result;
    }

    result = false;
    WideStringClass description;
    WideStringClass details;
    int owner = State->Get_Owner(Selected->ID);
    Voice.Play(3, (owner == 1 || owner == 0) ? 2 : (Campaign->Side != owner), false, false, 30);
    switch (owner) {
        case 2:
#line 685
            Set_Text(Fetch_String("WDT:AlliedHeldTooltip", NULL, __FILE__, __LINE__));
            break;
        case 3:
#line 689
            Set_Text(Fetch_String("WDT:SovietHeldTooltip", NULL, __FILE__, __LINE__));
            break;
        case 1:
#line 693
            Set_Text(Fetch_String("WDT:TerritorySelDispToolTip", NULL, __FILE__, __LINE__));
            break;
        default:
#line 697
            Set_Text(Fetch_String("WDT:TerritorySelectToolTip", NULL, __FILE__, __LINE__));
            break;
    }
    Selected->Show_Highlight(true, *this);
    if (Campaign->Properties->Last_Stage() == LastStage) {
        ConflictCursor conflicts(Campaign->Conflicts);
        ConflictCursor & cursor = conflicts;
        for (; cursor.Is_Valid() && (*cursor)->Territory_ID() != Selected->ID; ++cursor) {
        }
        if (cursor.Is_Valid()) {
            result = true;
            Conflict = *cursor;
            description = (*cursor)->Describe();
            details = description;
            MSShapeAnim * anim = (MSShapeAnim *)territory->Pending;
            if (anim != NULL) {
                anim->Set_End_Frame(-1);
                anim->Set_Start_Frame(TargetDividingFrame);
                anim->Set_Frame(TargetDividingFrame);
            }
        }
    }
#line 727
    WideStringClass title = Fetch_String("WDT:TerritoryPrefix", NULL, __FILE__, __LINE__) + Selected->Name + Fetch_String("WDT:TerritorySuffix", NULL, __FILE__, __LINE__);
    if (details.Get_Length() > 0) {
        title += description;
    }
    Set_Title(title, 0);
    return result;
}

// 0x323d40
void Selection::Clear_Pending()
{
    TerritoryCursor territories(Map.Get()->Territories);
    for (TerritoryCursor & cursor = territories; cursor.Is_Valid(); ++cursor) {
        MSAnim * anim = (MSAnim *)(*cursor)->Take_Pending();
        if (anim != NULL) {
            Remove_Anim(anim);
        }
    }
}

// 0x323dc0 (identical code)
void Selection::Clear_Pending2()
{
    TerritoryCursor territories(Map.Get()->Territories);
    for (TerritoryCursor & cursor = territories; cursor.Is_Valid(); ++cursor) {
        MSAnim * anim = (MSAnim *)(*cursor)->Take_Pending();
        if (anim != NULL) {
            Remove_Anim(anim);
        }
    }
}

// 0x323e40
void Selection::Enter_Map()
{
    Play_Sound("MapEnter");
}

// 0x323f00
void Selection::Leave_Map()
{
    Play_Sound("MapLeave");
    HoverID = -1;
    rc_ptr<Territory> none;
    Select(none);
}

// 0x323ff0
#line 889
void Selection::Enter_Back()
{
    if (!Map->BackHighlighted) {
        Map.Get()->Highlight_Back(*this, true);
        Play_Sound("MouseCancel");
        Set_Text(Fetch_String("WOL:WDTTerritoryBack", NULL, __FILE__, __LINE__));
    }
}

// 0x324100
#line 912
void Selection::Leave_Back()
{
    if (Map->BackHighlighted) {
        Map.Get()->Highlight_Back(*this, false);
        Set_Text(Fetch_String("WDT:TerritorySelectToolTip", NULL, __FILE__, __LINE__));
    }
}

// 0x324160
void Selection::Review_History(int theater)
{
    Set_Title(NULL, 0);
    int last = Campaign->Properties->Last_Stage();
    bool fast = true;
    int first = Campaign->Stage(theater);
    if (last - first > 8) {
        first = last - 8;
    }
    if (first != last) {
        fast = !Play_Change(first, last);
    } else {
        bool mega = false;
        int type = Classify(last, mega);
        Voice.Play(2, type, mega, true, 0);
    }
    Set_Title(NULL, 0);
    Poll_Input();
    Show_State(Campaign->History->Get_State(last), true, fast);
    Campaign->Finish_Review(theater);
}

// 0x3242a0
int Selection::Classify(int stage, bool & mega)
{
    rc_ptr<WorldDominationTour::State> state = Campaign->History->Get_State(stage);
    if (state.Get() != NULL) {
        int score = state->Get_Score(Campaign->Side);
        if (score <= LosingThreshold) {
            mega = score <= MegaLosingThreshold;
            return 1;
        }
        if (score >= WinningThreshold) {
            mega = score >= MegaWinningThreshold;
            return 0;
        }
    }
    mega = false;
    return 2;
}

// 0x324360
#line 990
bool Selection::Play_Stages(int from, int to)
{
    bool first = true;
    unsigned length = 0;
    for (int stage = from; stage <= to; stage++) {
        Poll_Input();
        if (Aborted) {
            break;
        }
#line 995
        WideStringClass text(Fetch_String("WDT:ReviewingHistory", NULL, __FILE__, __LINE__));
        text += L"\n";
        if (first) {
            length = text.Get_Length();
        }
#line 1003
        text += WideStringClass(Fetch_String("WDT:ReviewingHistoryDay", NULL, __FILE__, __LINE__)) + WideStringClass(L" ") + Int_To_WideString(stage + 1, 2);
        Set_Title(text, first ? 0 : length);
        Show_State(Campaign->History->Get_State(stage), false, first);
        first = false;
        Remove_Anim_Later(Title, 300000);
        int count = 5;
        while (!Aborted && count-- != 0) {
            Redraw(5);
            Poll_Input();
        }
        if (Aborted) {
            break;
        }
    }
    return first;
}

// 0x3245c0
void Selection::Play_Summary(int theater)
{
    Set_Title(NullWString, 0);
    int last = Campaign->Properties->Last_Stage();
    int first = Campaign->Stage(theater);
    if (last - first > 8) {
        first = last - 8;
    }
    rc_ptr<WorldDominationTour::State> state = Campaign->History->Get_State(first);
    if (state.Get() != NULL) {
        int score = state->Get_Score(Campaign->Side);
        if (score >= MegaWinningThreshold) {
            Voice.Play(0, 0, score >= 30, true, 0);
        } else if (score <= MegaLosingThreshold) {
            Voice.Play(0, 1, score <= 0, true, 0);
        } else {
            Voice.Play(0, 2, true, true, 0);
        }
        Play_Stages(first, last);
        while (Voice.Is_Playing() && !Aborted) {
            Redraw(5);
            Poll_Input();
        }
    }
}

// 0x324720
bool Selection::Play_Change(int from, int to)
{
    rc_ptr<WorldDominationTour::State> state1 = Campaign->History->Get_State(from);
    int score1 = state1->Get_Score(Campaign->Side);
    rc_ptr<WorldDominationTour::State> state2 = Campaign->History->Get_State(to);
    int score2 = state2->Get_Score(Campaign->Side);
    int change = score2 - score1;
    int type;
    bool mega;
    if (change < -1) {
        type = 1;
        mega = (change < -3 || score2 <= MegaLosingThreshold);
    } else if (change > 1) {
        type = 0;
        mega = (change > 3 || score2 >= MegaWinningThreshold);
    } else {
        type = 2;
        mega = false;
        mega = (Classify(to, mega) == 1 && mega);
    }
    Voice.Play(1, type, mega, true, 0);
    return !Play_Stages(from, to);
}

// 0x324840
void Selection::Poll_Input()
{
    Process();
    while (Keyboard->Check()) {
        if (Keyboard->Get() == KN_ESC) {
            Aborted = true;
        }
    }
}

// 0x324890
void Selection::Set_Title(WideStringClass const & text, int)
{
    if (Title != NULL) {
        Remove_Anim(Title);
        HiddenSurface->Copy_From(Map.Get()->TitleRect, *AlternateSurface, Map.Get()->TitleRect, false, true);
        Add_Dirty(Map.Get()->TitleRect);
        Title = NULL;
    }
    if (text.Get_Length() > 0) {
        WideStringClass string(text);
        Title = new MSBitPrintAnim(string, Map->TitleRect, true);
        Title->Set_Centered(true);
        Add_Anim(Title);
    }
}

// 0x324960
void Selection::Set_Text(WideStringClass const & text)
{
    RectangleStruct rect = Map->TextRect;
    if (Text != NULL) {
        Remove_Anim(Text);
        HiddenSurface->Copy_From(rect, *AlternateSurface, rect, false, true);
        Add_Dirty(rect);
        Text = NULL;
    }
    if (text.Get_Length() > 0) {
        WideStringClass string(text);
        Text = new MSBitPrintAnim(string, rect, false);
        Text->Set_Centered(true);
        Add_Anim(Text);
    }
}

// 0x324a50
void Selection::Play_Sound(CharStringClass const & name)
{
    if (name != NULL) {
        SoundCursor sounds(Sounds);
        SoundCursor & cursor = sounds;
        for (; cursor.Is_Valid() && name == (*cursor)->Name; ++cursor) {
        }
        if (cursor.Is_Valid()) {
            (*cursor)->Play();
        }
    }
}

// 0x324af0
#line 1227
void Selection::Show_Description()
{
    Set_Title(Campaign->Properties->LongDescription, 0);
    Set_Text(Fetch_String("WDT:TerritorySelectToolTip", NULL, __FILE__, __LINE__));
}

// 0x324b40
void Func_724B40(rc_ptr<WorldDominationTour::Campaign> const & campaign, int theater)
{
    Keyboard->Clear();
    Selection selection(campaign, theater);
    selection.Play_Summary(theater);
}

// 0x324b80
bool Func_724B80(rc_ptr<WorldDominationTour::Campaign> const & campaign, int theater)
{
    if (campaign.Get() == NULL) {
        return false;
    }
    Selection selection(campaign, theater);
    selection.Show_Description();
    selection.Review_History(theater);
    rc_ptr<Territory> territory = selection.Choose_Territory();
    bool result = territory.Get() != NULL;
    if (result) {
        WDTScenarioID = territory->ID;
        rc_ptr<WDTTerritory> conflict = Conflict_Territory(territory->ID);
        if (conflict.Get() != NULL) {
            WDTSetting_A25600 = conflict->Value0E;
            BuildLevel = conflict->Value0F;
            WDTSetting_A255EC = conflict->Value10;
            WDTSetting_A2566D = false;
            WDTSetting_A2566C = conflict->Flag2;
            WDTSetting_A255E8 = conflict->Flag4;
            WDTSetting_A2566F = false;
            WDTSetting_A25670 = conflict->Flag5;
            WDTSetting_A255F0 = true;
            WDTSetting_A255F1 = conflict->Flag8;
            WDTSetting_A255F2 = conflict->Flag10;
            WDTSetting_A255F4 = false;
            WDTSetting_A255F3 = conflict->Flag9;
            WDTSetting_A25604 = 0;
            WDTSetting_A25608 = 1;
        } else {
            result = false;
        }
    }
    return result;
}

// 0x324d20
void Selection::Start()
{
    Flag_A28984 = false;
    if (ThemeName != NULL) {
        Theme.Play_Song(Theme.From_Name(ThemeName.Peek_Buffer()));
        Theme.Field10 = true;
    }
    WWMouse->Hide_Mouse();
    AlternateSurface->Fill(0);
    HiddenSurface->Fill(0);
    VisibleSurface->Copy_From(*HiddenSurface, false, true);
    Keyboard->Clear();
    Map.Get()->Start(*this, Voice);
    while (WWMouse->Get_Mouse_State() < 0) {
        WWMouse->Show_Mouse();
    }
}

// 0x324df0
void Selection::Stop()
{
    WWMouse->Hide_Mouse();
    Theme.Queue_Song(-3);
    AlternateSurface->Fill(0);
    HiddenSurface->Fill(0);
    while (WWMouse->Get_Mouse_State() < 0) {
        WWMouse->Show_Mouse();
    }
}
