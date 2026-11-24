// C:\RA2\Multiplayer.cpp (level-2 reconstruction of GAME.EXE 1.001)
// MultiplayerGameMode: the base class of the multiplayer game modes (Battle, ManBattle, Siege,
// Unholy, FreeForAll, Cooperative and the derived Megawealth), its team list, its default
// behaviour (team lists, start positions, starting units and base) and the game-mode registry
// that is read from MPModes.ini.
// Class names come from RTTI (MultiplayerGameMode, MultiplayerGameMode::InitializerBase,
// MultiplayerGameMode::Initializer<T>, MultiplayerTeam, DynamicVectorClass, VectorClass, INIClass,
// CCINIClass, CCFileClass, GenericList, GenericNode, List); all other names are provisional.
//
// TU span: the 12 GAMECONST initializers 0x1b3550..0x1b3711 and the 16-byte zeroing header
// initializer 0x1b3720 (.bss 0xa595c8, header not reproduced, not claimed), then the code
// 0x1b3740..0x1b61b7 in source order followed by the compiler-generated deleting destructors,
// Initializer<T>::Create and vector template instances. The 16-byte zeroing initializer 0x1b61c0
// (.bss 0xa59658, 0x18 below the next file's GAMECONST constants at 0xa59670) and the GAMECONST
// block 0x1b61e0 belong to the next file (MultiplayerTeam, 0x1b63b0).
//
// Open (see W/analysis/level2/agents/Multiplayer.claims.json): Game_Mode_From_ID,
// Fill_Game_Mode_Combo/List, Read_Game_Modes and Create_Units differ only in how far VC6 inlined
// the static-initialisation (VectorClass constructor) or VectorClass::Clear; Create_Starting_Forces
// differs in register allocation of its first loop.
#include "GAMECONST.H"
#include <windows.h>
#include <stddef.h>
#include <string.h>
#include "ABSTRACT.H"

// ---- local declarations (to be moved to headers by the integrator) ----

// Copy of VECTOR.H plus the constructors that VECTOR.H does not have yet (as in WDTSel.cpp).
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

template<class T> bool VectorClass<T>::operator == (VectorClass<T> const & vector) const
{
    if (VectorMax == vector.VectorMax) {
        for (int index = 0; index < VectorMax; index++) {
            if (Vector[index] != vector.Vector[index]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template<class T> bool VectorClass<T>::Resize(int newsize, T const * array)
{
    if (newsize) {
        T * newptr;
        IsInitialized = false;
        if (!array) {
            newptr = new T[newsize];
        } else {
            newptr = (T *)array;
        }
        IsInitialized = true;
        if (!newptr) {
            return false;
        }
        if (Vector != NULL) {
            int copycount = (newsize < VectorMax) ? newsize : VectorMax;
            for (int index = 0; index < copycount; index++) {
                newptr[index] = Vector[index];
            }
            if (IsAllocated) {
                delete [] Vector;
                Vector = 0;
            }
        }
        Vector = newptr;
        VectorMax = newsize;
        IsAllocated = (Vector && !array);
    } else {
        Clear();
    }
    return true;
}

template<class T> void VectorClass<T>::Clear(void)
{
    if (Vector && IsAllocated) {
        delete [] Vector;
        Vector = 0;
    }
    IsAllocated = false;
    VectorMax = 0;
}

template<class T> int VectorClass<T>::ID(T const * ptr)
{
    if (!IsInitialized) {
        return 0;
    }
    return ((unsigned long)ptr - (unsigned long)Vector) / sizeof(T);
}

template<class T> int VectorClass<T>::ID(T const & object)
{
    if (!IsInitialized) {
        return 0;
    }
    for (int index = 0; index < VectorMax; index++) {
        if (Vector[index] == object) {
            return index;
        }
    }
    return -1;
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
    int Add_Head(T const & object);
    int Add_After(T const & object, int index);

    int ActiveCount;
    int GrowthStep;
};

template<class T> bool DynamicVectorClass<T>::Resize(int newsize, T const * array)
{
    if (VectorClass<T>::Resize(newsize, array)) {
        if (Length() < ActiveCount) {
            ActiveCount = Length();
        }
        return true;
    }
    return false;
}

template<class T> void DynamicVectorClass<T>::Clear(void)
{
    ActiveCount = 0;
    VectorClass<T>::Clear();
}

template<class T> int DynamicVectorClass<T>::ID(T const & object)
{
    for (int index = 0; index < ActiveCount; index++) {
        if ((*this)[index] == object) {
            return index;
        }
    }
    return -1;
}

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

template<class T> inline int DynamicVectorClass<T>::Add_Head(T const & object)
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
    if (ActiveCount) {
        memmove(&(*this)[1], &(*this)[0], ActiveCount * sizeof(T));
    }
    (*this)[0] = object;
    ActiveCount++;
    return true;
}

// Inserts the object behind position index (name provisional).
template<class T> inline int DynamicVectorClass<T>::Add_After(T const & object, int index)
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
    if (index < ActiveCount - 1) {
        memmove(&(*this)[index + 2], &(*this)[index + 1], (ActiveCount - (index + 1)) * sizeof(T));
    }
    (*this)[index + 1] = object;
    ActiveCount++;
    return true;
}

// Deletes every element and clears the vector (virtual Clear).
template<class T> inline void Delete_All(DynamicVectorClass<T> & vector)
{
    for (int index = 0; index < vector.ActiveCount; index++) {
        delete vector[index];
    }
    vector.Clear();
}

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)

// Simple owned narrow string, one pointer (library code near 0x759250; name provisional).
class CharStringClass {
public:
    CharStringClass();                                          // 0x759250
    CharStringClass(char const * string);                       // 0x759260
    CharStringClass(CharStringClass const & string);            // 0x7592c0
    ~CharStringClass();                                         // 0x759320
    operator char * ();                                         // 0x75a030
    operator char const * () const;                             // 0x75a070
    unsigned Get_Length() const;                                // 0x75a0e0
    int Get_Token(int start, char const * delimiters, CharStringClass & token) const;   // 0x75ab40 (name provisional)
    int As_Int() const;                                         // 0x75aeb0 (name provisional)
    void Trim_Left(CharStringClass const & characters);         // 0x759e00 (name provisional)
    void Trim_Right(CharStringClass const & characters);        // 0x759e60 (name provisional)
    char * Buffer;
};
extern char NullString[];                                       // 0x8248a4 (.bss), shared empty string

// Simple owned wide string, one pointer (library code near 0x75b2f0; name provisional).
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);                    // 0x75b300
    WideStringClass(WideStringClass const & string);            // 0x75b350
    ~WideStringClass();                                         // 0x75b390
    operator wchar_t * ();                                      // 0x75bd70
    unsigned Get_Length() const;                                // 0x75bde0
    wchar_t * Buffer;
};

// File class hierarchy (as in Restate.cpp).
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
    char RawFileData[0x1C];             // +0x04, layout not reconstructed
};

class BufferIOFileClass : public RawFileClass {
public:
    virtual ~BufferIOFileClass();       // 0x42f250
private:
    char BufferIOData[0x34];            // +0x20, layout not reconstructed
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}
    virtual char const * Set_Name(char const * filename);   // 0x46fd50
};

// Owned or borrowed memory block (0x438140 constructor, 0x438290 destructor).
class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);
    ~Buffer();
private:
    void * BufferPtr;
    long Size;
    bool IsAllocated;
};

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

// Doubly linked list (RTTI GenericNode 0x785afc, GenericList 0x785af4, List<INISection *> 0x785aec).
// Out-of-line copies: GenericNode() 0x40e160, Link 0x40e180, GenericList() 0x490c60,
// List<INISection *>() 0x490dd0.
class GenericNode {
public:
    GenericNode() : NextNode(0), PrevNode(0) {}
    virtual ~GenericNode() { Unlink(); }
    bool Is_Valid() const { return this != NULL && NextNode != NULL && PrevNode != NULL; }
    void Unlink()
    {
        if (Is_Valid()) {
            PrevNode->NextNode = NextNode;
            NextNode->PrevNode = PrevNode;
            PrevNode = 0;
            NextNode = 0;
        }
    }
    void Link(GenericNode * node)
    {
        node->Unlink();
        node->PrevNode = this;
        node->NextNode = NextNode;
        if (NextNode) {
            NextNode->PrevNode = node;
        }
        NextNode = node;
    }
protected:
    GenericNode * NextNode;
    GenericNode * PrevNode;
};

class GenericList {
public:
    GenericList() { FirstNode.Link(&LastNode); }
    virtual ~GenericList();
protected:
    GenericNode FirstNode;
    GenericNode LastNode;
};

template<class T>
class List : public GenericList {
};

// Sorted index (out-of-line constructor copy 0x490ea0).
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
    struct INIEntry;

    INIClass() : Unknown34(0) {}
    virtual ~INIClass();                                                        // 0x50ad20
    int Load(FileClass & file, bool withdigest);                                // 0x50b030
    INISection * Find_Section(char const * section) const;                      // 0x50be00
    int Entry_Count(CharStringClass const & section) const;                     // 0x50c020
    CharStringClass Get_Entry(CharStringClass const & section, int index) const;   // 0x50c320
    int Get_Int(char const * section, char const * entry, int defvalue) const;  // 0x50cc40
    int Get_String(CharStringClass const & section, CharStringClass const & entry,
        CharStringClass const & defvalue, CharStringClass & result) const;    // 0x50df90
    INIEntry * Find_Entry(char const * section, char const * entry) const;    // 0x50c0f0
    bool Is_Present(char const * section, char const * entry = NULL) const
    {
        if (entry == NULL) return Find_Section(section) != NULL;
        return Find_Entry(section, entry) != NULL;
    }
protected:
    List<INISection *> SectionList;                 // +0x04
    IndexClass<int, INISection *> SectionIndex;     // +0x20
    int Unknown34;                                  // +0x34
};

// RTTI .?AVCCINIClass@@ (vtable 0x785ae4), size 0x50.
class CCINIClass : public INIClass {
public:
    CCINIClass() : IsDigestPresent(false) {}
    int Load(FileClass & file, bool withdigest, bool merge);                    // 0x4692d0
private:
    bool IsDigestPresent;               // +0x38
    unsigned char Digest[20];           // +0x39
};

// Multiplayer scenario description (Session scenario list entries).
class MultiMission {
public:
    bool Is_Random_Map() const;                                     // 0x668370 (name provisional)
    bool Is_Game_Mode_Allowed(CharStringClass const & key) const;   // 0x668390 (name provisional)
};

// Entry of the session player list (0x71 bytes; see ModemGst.cpp, MPCoop.cpp).
#pragma pack(push, 1)
struct NodeNameType {
    wchar_t Name[20];                           // +0x00
    char Unknown28[0x59 - 0x28];
    int Team;                                   // +0x59
    int ID;                                     // +0x5d
    char Unknown61[0x71 - 0x61];
};
#pragma pack(pop)

// Session object at 0xa255c8 (class name provisional; layout as in Skirmish.cpp). Offsets are binary
// evidence, field names provisional.
enum GameEnum {
    GAME_INTERNET = 4,
    GAME_SKIRMISH = 5
};

struct GameOptionsType {
    int GameMode;                               // +0x00 0xa255e0
    int Scenario;                               // +0x04 0xa255e4
    bool Bases;                                 // +0x08 0xa255e8
    int Credits;                                // +0x0c 0xa255ec
    char Unknown10[0x20 - 0x10];
    int UnitCount;                              // +0x20 0xa25600
};

class SessionClass {
public:
    int Random_Country();                       // 0x668bb0 (name provisional)

    int Type;                                   // +0x000 0xa255c8
    char Unknown004[0x18 - 0x04];
    GameOptionsType Options;                    // +0x018 0xa255e0
    char Unknown03C[0x2C0 - 0x3C];
    int MaxPlayers;                             // +0x2c0 0xa25888 (name provisional)
    char Unknown2C4[0x640 - 0x2C4];
    DynamicVectorClass<MultiMission *> Scenarios;   // +0x640 0xa25c08
    char Unknown658[0x27E0 - 0x658];
    DynamicVectorClass<NodeNameType *> Players; // +0x27e0 0xa27da8
};
extern SessionClass Session;                    // 0xa255c8

// Random number generator inside the scenario.
// level-2 1.001: Random2Class (operator() 0x62FE40, the scenario generator), not RandomClass (0x62FCC0); shown by the P9 link check.
class Random2Class {
public:
    int operator()(int minval, int maxval);     // 0x62fe40
};

// Only the fields used here; layout not reconstructed.
class ScenarioClass {
public:
    unsigned long Flags;                        // +0x000 (bit 10 cleared by Prepare_Scenario)
    char Unknown004[0x218 - 0x004];
    Random2Class RandomNumber;                   // +0x218
};
extern ScenarioClass * Scen;                    // 0xa255c0

bool Is_Tournament_Server();                    // 0x730e40 (meaning provisional)
void Reset_Combo_Box(HWND combo);               // 0x5f8490 (meaning provisional)

// RTTI .?AVMultiplayerTeam@@, vtable 0x7922e4 (3 slots), size 0xc (as in MPObserver.cpp).
class MultiplayerTeam {
public:
    MultiplayerTeam(WideStringClass const & name, int id);   // 0x5b63b0
    virtual ~MultiplayerTeam();                              // 0x5b63e0 (slot 0: 0x1b64b0)
    virtual bool Is_Valid_Index(int index);                  // slot 1: 0x5b63f0
    virtual bool Can_Join(int index);                        // slot 2: 0x5b6410

    WideStringClass Name;   // +0x04
    int ID;                 // +0x08
};

// RTTI .?AVMultiplayerObserverTeam@@ : MultiplayerTeam (MPObserver.cpp).
class MultiplayerObserverTeam : public MultiplayerTeam {
public:
    MultiplayerObserverTeam();                  // 0x5a73a0
};

MultiplayerTeam * Create_Battle_Team(int index);    // 0x59f310 (name provisional)

// Cell coordinates (RTTI .?AV?$VectorClass@VCell@@@@, vtable 0x7875e0; as in MPCoop.cpp).
class Cell {
public:
    Cell() {}
    Cell(short x, short y) : X(x), Y(y) {}
    bool operator == (Cell const & cell) const { return X == cell.X && Y == cell.Y; }
    bool operator != (Cell const & cell) const { return X != cell.X || Y != cell.Y; }
    Cell operator - (Cell const & cell) const { return Cell((short)(X - cell.X), (short)(Y - cell.Y)); }
    short X;
    short Y;
};
DynamicVectorClass<Cell> Get_Start_Cells(bool flag);    // 0x656fd0 (as in MPCoop.cpp)

inline double Distance(double x, double y)
{
    return Fast_Sqrt(x * x + y * y);
}

// Object hierarchy (as in Event.CPP); only the slots and fields used here are named.
class ObjectClass : public AbstractClass {
public:
    virtual void Slot_024(); virtual void Slot_025(); virtual void Slot_026(); virtual void Slot_027();
    virtual void Slot_028(); virtual void Slot_029(); virtual void Slot_030(); virtual void Slot_031();
    virtual void Slot_032(); virtual void Slot_033(); virtual void Slot_034(); virtual void Slot_035();
    virtual void Slot_036(); virtual void Slot_037(); virtual void Slot_038(); virtual void Slot_039();
    virtual void Slot_040(); virtual void Slot_041(); virtual void Slot_042(); virtual void Slot_043();
    virtual void Slot_044(); virtual void Slot_045(); virtual void Slot_046(); virtual void Slot_047();
    virtual void Slot_048(); virtual void Slot_049(); virtual void Slot_050(); virtual void Slot_051();
    virtual void Slot_052();
    virtual bool Unlimbo(CoordStruct const & coord, int dir);      // slot 53 (+0xd4)
    virtual void Slot_054(); virtual void Slot_055(); virtual void Slot_056(); virtual void Slot_057();
    virtual void Slot_058(); virtual void Slot_059(); virtual void Slot_060(); virtual void Slot_061();
    virtual void Slot_062(); virtual void Slot_063(); virtual void Slot_064(); virtual void Slot_065();
    virtual void Slot_066(); virtual void Slot_067(); virtual void Slot_068(); virtual void Slot_069();
    virtual void Slot_070(); virtual void Slot_071(); virtual void Slot_072(); virtual void Slot_073();
    virtual void Slot_074(); virtual void Slot_075(); virtual void Slot_076(); virtual void Slot_077();
    virtual void Slot_078(); virtual void Slot_079(); virtual void Slot_080(); virtual void Slot_081();
    virtual void Slot_082(); virtual void Slot_083(); virtual void Slot_084(); virtual void Slot_085();
    virtual void Slot_086(); virtual void Slot_087(); virtual void Slot_088(); virtual void Slot_089();
    virtual void Slot_090(); virtual void Slot_091(); virtual void Slot_092(); virtual void Slot_093();
    virtual void Slot_094(); virtual void Slot_095(); virtual void Slot_096(); virtual void Slot_097();
    virtual void Slot_098(); virtual void Slot_099(); virtual void Slot_100(); virtual void Slot_101();
    virtual void Slot_102(); virtual void Slot_103(); virtual void Slot_104(); virtual void Slot_105();
    virtual void Slot_106(); virtual void Slot_107(); virtual void Slot_108(); virtual void Slot_109();
    virtual void Slot_110(); virtual void Slot_111(); virtual void Slot_112(); virtual void Slot_113();
    virtual void Slot_114(); virtual void Slot_115();
};

// Veterancy of a techno object (TechnoClass +0x118); names provisional.
class VeterancyClass {
public:
    void Set_Elite(bool flag);                // 0x708110 (name provisional)
};

class TechnoClass : public ObjectClass {
public:
    virtual void Slot_116(); virtual void Slot_117();
    virtual void Queue_Mission(int mission);    // slot 118 (+0x1d8), name provisional

    char Unknown24[0x118 - 0x24];
    VeterancyClass Veterancy;                   // +0x118
};

class FootClass : public TechnoClass {
};

class UnitTypeClass;
class HouseClass;

// RTTI .?AVUnitClass@@, 0x7d0 bytes.
class UnitClass : public FootClass {
public:
    UnitClass(UnitTypeClass * type, HouseClass * house);   // 0x6ef0a0
    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    char Unknown11C[0x7D0 - sizeof(FootClass)];
};

// Places an object on or next to a cell (0x657b30, __fastcall). Name provisional.
int Place_Near(TechnoClass * object, CellStruct const & cell, int flag);

inline CellStruct Coord_Cell(CoordStruct const & coord)
{
    return CellStruct((short)(coord.X / 256), (short)(coord.Y / 256));
}

// RTTI .?AVTechnoTypeClass@@, primary vtable 48 slots (as in Dropship.cpp).
class TechnoTypeClass {
public:
    virtual void Slot_000(); virtual void Slot_001(); virtual void Slot_002(); virtual void Slot_003();
    virtual void Slot_004(); virtual void Slot_005(); virtual void Slot_006(); virtual void Slot_007();
    virtual void Slot_008(); virtual void Slot_009(); virtual void Slot_010(); virtual void Slot_011();
    virtual void Slot_012(); virtual void Slot_013(); virtual void Slot_014(); virtual void Slot_015();
    virtual void Slot_016(); virtual void Slot_017(); virtual void Slot_018(); virtual void Slot_019();
    virtual void Slot_020(); virtual void Slot_021(); virtual void Slot_022(); virtual void Slot_023();
    virtual void Slot_024(); virtual void Slot_025(); virtual void Slot_026(); virtual void Slot_027();
    virtual void Slot_028(); virtual void Slot_029(); virtual void Slot_030(); virtual void Slot_031();
    virtual void Slot_032(); virtual void Slot_033(); virtual void Slot_034();
    virtual ObjectClass * Create_One_Of(HouseClass * house);   // slot 35 (+0x8c)
    virtual void Slot_036(); virtual void Slot_037(); virtual void Slot_038(); virtual void Slot_039();
    virtual void Slot_040(); virtual void Slot_041(); virtual void Slot_042();
    virtual int Cost_Of() const;                // slot 43 (+0xac)

    char Unknown004[0x55C - 0x004];
    int TechLevel;                              // +0x55c
    char Unknown560[0x5E8 - 0x560];
    unsigned int Ownable;                       // +0x5e8, bit per country
    char Unknown5EC[0x5F1 - 0x5EC];
    bool AllowedToStartInMultiplayer;           // +0x5f1
};
class UnitTypeClass : public TechnoTypeClass {
};
class InfantryTypeClass : public TechnoTypeClass {
};
extern DynamicVectorClass<UnitTypeClass *> UnitTypes;          // 0xa1e078
extern DynamicVectorClass<InfantryTypeClass *> InfantryTypes;  // 0xa27fa0
extern int TechLevel;                           // 0x7c3978 (as in ModemHst.cpp)

class RulesClass {
public:
    char Unknown0000[0x9D0];
    DynamicVectorClass<UnitTypeClass *> BaseUnit;   // +0x9d0 (name provisional)
};
extern RulesClass * Rule;                       // 0x821b88

// RTTI .?AVHouseTypeClass@@; only the fields used here.
class HouseTypeClass {
public:
    char Unknown00[0x24];
    char ID[0x3C];                              // +0x24 (AbstractTypeClass::ID)
    char Unknown60[0xB4 - 0x60];
    int CountryIndex;                           // +0xb4, bit index in TechnoTypeClass::Ownable (provisional)
    char UnknownB8[0x1A6 - 0xB8];
    bool IsMultiplayPassive;                    // +0x1a6
};

// RTTI .?AVHouseClass@@; only the fields used here.
class HouseClass {
public:
    void Give_Money(int amount);                // 0x4e4ae0 (name provisional)
    UnitTypeClass * Pick_Unit(DynamicVectorClass<UnitTypeClass *> const & list) const;   // 0x4eebf0 (name provisional)
    bool Func_4F47F0() const;                   // 0x4f47f0 (meaning unknown, see Event.CPP)

    char Unknown0000[0x34];
    HouseTypeClass * Class;                     // +0x34
    char Unknown0038[0x11C - 0x38];
    int TechLevel;                              // +0x11c (name provisional)
    char Unknown0120[0x53BC - 0x120];
    CoordStruct StartCoord;                     // +0x53bc (as in MPCoop.cpp)
    char Unknown53C8[0x54A0 - 0x53C8];
    VectorClass<int> List54A0;                  // +0x54a0 (element types unknown)
    VectorClass<int> List54B0;                  // +0x54b0
    VectorClass<int> List54C0;                  // +0x54c0
    VectorClass<int> List54D0;                  // +0x54d0
    char Unknown54E0[0x15EE0 - 0x54E0];
    char IniName[0x36];                         // +0x15ee0 (name and length provisional)
};
extern DynamicVectorClass<HouseClass *> Houses; // 0xa1a5c8

enum {
    MISSION_5 = 5,                              // given to the units of human players (name unknown)
    MISSION_11 = 11                             // given to the units of computer players (name unknown)
};

// RTTI .?AVMultiplayerGameMode@@, vtable 0x792188 (44 slots), size 0x40. Slot names are provisional
// but derived from the base bodies in this file; slots 1-3, 8, 9, 17-19, 22, 25 and 30-39 have
// their bodies (inline in the header) in another file.
class MultiplayerGameMode {
public:
    // RTTI .?AVInitializerBase@MultiplayerGameMode@@, vtable 0x79227c.
    class InitializerBase {
    public:
        InitializerBase();
        virtual ~InitializerBase();
        virtual MultiplayerGameMode * Create(WideStringClass const & name, WideStringClass const & description,
            CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id) const = 0;
    };

    // RTTI .?AV?$Initializer@VT@@@MultiplayerGameMode@@.
    template<class T> class Initializer : public InitializerBase {
    public:
        virtual MultiplayerGameMode * Create(WideStringClass const & name, WideStringClass const & description,
            CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id) const
        {
            return new T(name, description, ini_file, key, random_maps, id);
        }
    };

    MultiplayerGameMode(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x5b37e0
    virtual ~MultiplayerGameMode();                                 // 0x5b3930
    virtual bool Virtual_01();                                      // 0x59f150 (false)
    virtual bool Virtual_02();                                      // 0x59f160 (false)
    virtual bool Virtual_03(int);                                   // 0x59f170 (true)
    virtual bool Assign_Teams();
    virtual bool Can_Start(WideStringClass & reason);
    virtual bool Virtual_06();
    virtual bool Is_Valid_House(int house);
    virtual void Activate();                                        // 0x59f180
    virtual void Request_Refresh();                                 // 0x59f190 (name from MPCoop.cpp)
    virtual int Virtual_10();
    virtual bool Allows_Random_Maps();
    virtual bool Is_Skirmish_Allowed();
    virtual int Default_Scenario();
    virtual void Fill_Combo(HWND combo, DynamicVectorClass<int> const & items, int selected);
    virtual void Fill_List_Box(HWND list, DynamicVectorClass<int> const & items, int selected);
    virtual void Fill_Team_List(HWND combo, int player);
    virtual bool Virtual_17(int, DynamicVectorClass<int>);          // 0x59f1c0 (signature as in MPCoop.cpp)
    virtual bool Virtual_18(int, DynamicVectorClass<int>, int, int);    // 0x59f1a0 (signature as in MPCoop.cpp)
    virtual bool Virtual_19(int, int, int);                         // 0x59f1e0 (true)
    virtual bool Virtual_20();
    virtual bool Virtual_21();
    virtual bool Virtual_22();                                      // 0x59f1f0 (true)
    virtual int Random_Country();
    virtual int Random_AI_Country();
    virtual void Virtual_25(int, int);                              // 0x59f200
    virtual bool Prepare_Scenario();
    virtual bool Assign_Start_Positions(bool flag);
    virtual bool Virtual_28();
    virtual bool Reveal_Map();
    virtual void Virtual_30();
    virtual void Virtual_31();
    virtual int Virtual_32();
    virtual void Virtual_33();
    virtual void Virtual_34(int);
    virtual void Virtual_35(int);
    virtual bool Virtual_36();
    virtual void Virtual_37();
    virtual void Virtual_38();
    virtual void Virtual_39();
    virtual void Create_Teams(DynamicVectorClass<MultiplayerTeam *> & teams);
    virtual Cell Pick_Start_Cell(int house, DynamicVectorClass<Cell> & cells, bool * used);
    virtual bool Create_Base(HouseClass * house, int & cost);
    virtual bool Create_Units(HouseClass * house, int & budget);

    static DynamicVectorClass<MultiplayerGameMode *> & Game_Modes();
    static MultiplayerGameMode * Default_Game_Mode();
    static int Game_Mode_Count();
    static MultiplayerGameMode * Game_Mode_From_ID(int id);
    static void Fill_Game_Mode_Combo(HWND combo, int selected);
    static void Fill_Game_Mode_List(HWND list, int selected);
    static void Read_Game_Modes(CharStringClass const & section, InitializerBase const & initializer);
    static void Init_Game_Modes();
    static void Free_Game_Modes();

    bool Is_Scenario_Allowed(MultiMission * scenario);
    MultiplayerTeam * Find_Team(int id);
    void Clear_Teams();
    CCINIClass * Get_INI();
    bool Create_Starting_Forces();
    int Player_Team(int id);

    bool Flag04;                                    // +0x04
    DynamicVectorClass<MultiplayerTeam *> Teams;    // +0x08
    WideStringClass Name;                           // +0x20
    WideStringClass Description;                    // +0x24
    int ID;                                         // +0x28
    CharStringClass INIFile;                        // +0x2c
    CharStringClass Key;                            // +0x30
    bool RandomMaps;                                // +0x34
    CCINIClass * INI;                               // +0x38
    int Value3C;                                    // +0x3c, "WonlineTournamentAllowed"
};

// Game modes created by the registry (constructors in their own files).
class MultiplayerBattle : public MultiplayerGameMode {
public:
    MultiplayerBattle(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x59f0f0
};
class MultiplayerManBattle : public MultiplayerGameMode {
public:
    MultiplayerManBattle(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x5a40a0
};
class MultiplayerSiege : public MultiplayerGameMode {
public:
    MultiplayerSiege(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x5a8180
};
class UnholyAlliance : public MultiplayerGameMode {
public:
    UnholyAlliance(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x5a8f10
};
class FreeForAll : public MultiplayerGameMode {
public:
    FreeForAll(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x5a3c60
};
class MPCooperative : public MultiplayerGameMode {
public:
    MPCooperative(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x59f720
    char Unknown40[0x268 - 0x40];
};

// ---- end of local declarations ----

#define CB_ADD_WIDE_STRING      (WM_USER + 0xCD)

static char const * const MPDialogSettings = "MultiplayerDialogSettings";   // 0x792140

inline DynamicVectorClass<MultiplayerGameMode *> & MultiplayerGameMode::Game_Modes()
{
    static DynamicVectorClass<MultiplayerGameMode *> modes;
    return modes;
}

MultiplayerGameMode::MultiplayerGameMode(WideStringClass const & name, WideStringClass const & description,
    CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id) :
    Name(name),
    Description(description),
    ID(id),
    INIFile(ini_file),
    Key(key),
    RandomMaps(random_maps),
    INI(NULL)
{
    Flag04 = false;
    Value3C = 1;
    Get_INI();
    if (INI && INI->Is_Present(MPDialogSettings)) {
        Value3C = INI->Get_Int(MPDialogSettings, "WonlineTournamentAllowed", Value3C);
    }
}

MultiplayerGameMode::~MultiplayerGameMode()
{
    Clear_Teams();
    delete INI;
}

int MultiplayerGameMode::Virtual_10()
{
    return -2;
}

MultiplayerGameMode * MultiplayerGameMode::Default_Game_Mode()
{
    if (Game_Modes().Count() == 0) {
        return NULL;
    }
    return Game_Modes()[0];
}

int MultiplayerGameMode::Game_Mode_Count()
{
    return Game_Modes().Count();
}

MultiplayerGameMode * MultiplayerGameMode::Game_Mode_From_ID(int id)
{
    for (int index = 0; index < Game_Mode_Count(); index++) {
        MultiplayerGameMode * mode = Game_Modes()[index];
        if (mode->ID == id) {
            return mode;
        }
    }
    return NULL;
}

void MultiplayerGameMode::Fill_Game_Mode_Combo(HWND combo, int selected)
{
    Reset_Combo_Box(combo);
    bool skirmish = (Session.Type == GAME_SKIRMISH);
    for (int index = 0; index < Game_Mode_Count(); index++) {
        MultiplayerGameMode * mode = Game_Modes()[index];
        if (!skirmish || mode->Is_Skirmish_Allowed()) {
            int item = SendMessageA(combo, CB_ADDSTRING, 0, (LPARAM)(wchar_t *)mode->Name);
            if (mode->ID == selected) {
                SendMessageA(combo, CB_SETCURSEL, item, 0);
            }
            SendMessageA(combo, CB_SETITEMDATA, item, (LPARAM)mode);
        }
    }
}

void MultiplayerGameMode::Fill_Game_Mode_List(HWND list, int selected)
{
    SendMessageA(list, LB_RESETCONTENT, 0, 0);
    bool skirmish = (Session.Type == GAME_SKIRMISH);
    for (int index = 0; index < Game_Modes().ActiveCount; index++) {
        MultiplayerGameMode * mode = Game_Modes()[index];
        if (mode->Value3C == 0 && Session.Type == GAME_INTERNET && Is_Tournament_Server()) {
            continue;
        }
        if (!skirmish || mode->Is_Skirmish_Allowed()) {
            int item = SendMessageA(list, CB_ADD_WIDE_STRING, 0, (LPARAM)(wchar_t *)mode->Name);
            if (mode->ID == selected) {
                SendMessageA(list, LB_SETCURSEL, item, 0);
            }
            SendMessageA(list, LB_SETITEMDATA, item, (LPARAM)mode);
        }
    }
}

bool MultiplayerGameMode::Assign_Teams()
{
    for (int index = 0; index < Session.Players.ActiveCount; index++) {
        Session.Players[index]->Team = index;
    }
    return true;
}

bool MultiplayerGameMode::Can_Start(WideStringClass &)
{
    return true;
}

bool MultiplayerGameMode::Virtual_20()
{
    return true;
}

bool MultiplayerGameMode::Virtual_21()
{
    return true;
}

bool MultiplayerGameMode::Virtual_06()
{
    return true;
}

bool MultiplayerGameMode::Allows_Random_Maps()
{
    return RandomMaps;
}

bool MultiplayerGameMode::Is_Skirmish_Allowed()
{
    return false;
}

int MultiplayerGameMode::Default_Scenario()
{
    int count = Session.Scenarios.ActiveCount;
    for (int index = 0; index < count; index++) {
        if (Is_Scenario_Allowed(Session.Scenarios[index])) {
            return index;
        }
    }
    return -1;
}

bool MultiplayerGameMode::Is_Scenario_Allowed(MultiMission * scenario)
{
    if (scenario->Is_Random_Map()) {
        return Allows_Random_Maps();
    }
    return scenario->Is_Game_Mode_Allowed(Key);
}

int MultiplayerGameMode::Random_Country()
{
    return Session.Random_Country();
}

int MultiplayerGameMode::Random_AI_Country()
{
    return Random_Country();
}

void MultiplayerGameMode::Fill_Combo(HWND combo, DynamicVectorClass<int> const & items, int selected)
{
    Reset_Combo_Box(combo);
    for (int index = 0; index < items.ActiveCount; index++) {
        int value = items[index];
        int item = SendMessageA(combo, CB_ADDSTRING, 0, value);
        if (value == selected) {
            SendMessageA(combo, CB_SETCURSEL, item, 0);
        }
        SendMessageA(combo, CB_SETITEMDATA, item, value);
    }
}

void MultiplayerGameMode::Fill_List_Box(HWND list, DynamicVectorClass<int> const & items, int selected)
{
    SendMessageA(list, LB_RESETCONTENT, 0, 0);
    for (int index = 0; index < items.ActiveCount; index++) {
        int value = items[index];
        int item = SendMessageA(list, CB_ADD_WIDE_STRING, 0, value);
        if (value == selected) {
            SendMessageA(list, LB_SETCURSEL, item, 0);
        }
        SendMessageA(list, LB_SETITEMDATA, item, value);
    }
}

void MultiplayerGameMode::Fill_Team_List(HWND combo, int player)
{
    Reset_Combo_Box(combo);
    Clear_Teams();
    Create_Teams(Teams);
    if (player >= 0 && player < Session.Players.ActiveCount) {
        int team = Session.Players[player]->Team;
        for (int index = 0; index < Teams.ActiveCount; index++) {
            MultiplayerTeam * t = Teams[index];
            int item = SendMessageA(combo, CB_ADDSTRING, 0, (LPARAM)(wchar_t *)t->Name);
            if (t->ID == team) {
                SendMessageA(combo, CB_SETCURSEL, item, 0);
            }
            SendMessageA(combo, CB_SETITEMDATA, item, (LPARAM)t);
        }
    }
}

MultiplayerTeam * MultiplayerGameMode::Find_Team(int id)
{
    if (Teams.ActiveCount < 3) {
        Clear_Teams();
        Create_Teams(Teams);
    }
    for (int index = 0; index < Teams.ActiveCount; index++) {
        MultiplayerTeam * team = Teams[index];
        if (team && team->ID == id) {
            return team;
        }
    }
    return NULL;
}

void MultiplayerGameMode::Create_Teams(DynamicVectorClass<MultiplayerTeam *> & teams)
{
    teams.Add(new MultiplayerObserverTeam);
    for (int index = 1; index <= Session.MaxPlayers; index++) {
        teams.Add(Create_Battle_Team(index));
    }
}

void MultiplayerGameMode::Clear_Teams()
{
    for (int index = 0; index < Teams.Count(); index++) {
        delete Teams[index];
    }
    Teams.Clear();
}

bool MultiplayerGameMode::Prepare_Scenario()
{
    Scen->Flags &= ~0x400;
    return true;
}

bool MultiplayerGameMode::Is_Valid_House(int)
{
    return true;
}

CCINIClass * MultiplayerGameMode::Get_INI()
{
    if (INI == NULL) {
        INI = new CCINIClass;
        CCFileClass file(INIFile);
        if (file.Is_Available()) {
            INI->Load(file, false, false);
        }
    }
    return INI;
}

Cell MultiplayerGameMode::Pick_Start_Cell(int, DynamicVectorClass<Cell> & cells, bool * used)
{
    int index;
    for (index = 0; index < cells.Count(); index++) {
        if (used[index]) {
            break;
        }
    }
    if (index == cells.Count()) {
        int pick = Scen->RandomNumber(0, cells.Count() - 1);
        used[pick] = true;
        return cells[pick];
    }
    int best = -1;
    int bestindex = -1;
    for (int cell = 0; cell < cells.Count(); cell++) {
        if (!used[cell]) {
            int total = 0;
            for (int other = 0; other < cells.Count(); other++) {
                if (used[other]) {
                    Cell diff = cells[cell] - cells[other];
                    total += (short)Distance(diff.Y, diff.X);
                }
            }
            if (total > best) {
                best = total;
                bestindex = cell;
            }
        }
    }
    used[bestindex] = true;
    return cells[bestindex];
}

bool MultiplayerGameMode::Assign_Start_Positions(bool flag)
{
    DynamicVectorClass<Cell> cells = Get_Start_Cells(flag);
    bool used[16];
    memset(used, 0, sizeof(used));
    for (int index = 0; index < Houses.Count(); index++) {
        HouseClass * house = Houses[index];
        if (!house->Class->IsMultiplayPassive) {
            Debug_Printf("Assigning Starting Points for house %d (%s)\n", index, house->Class->ID);
            Cell cell = Pick_Start_Cell(index, cells, used);
            house->StartCoord = CoordStruct(cell.X * 256 + 128, cell.Y * 256 + 128, 0);
        }
    }
    return true;
}

bool MultiplayerGameMode::Create_Starting_Forces()
{
    int budget = 0;
    if (Session.Options.UnitCount > 0) {
        unsigned int owners = 0;
        for (int index = 0; index < Houses.Count(); index++) {
            if (!Houses[index]->Class->IsMultiplayPassive) {
                owners |= 1 << Houses[index]->Class->CountryIndex;
            }
        }
        int total = 0;
        int count = 0;
        for (int unit = 0; unit < UnitTypes.Count(); unit++) {
            UnitTypeClass * type = UnitTypes[unit];
            if (type->AllowedToStartInMultiplayer && (owners & type->Ownable) && type->TechLevel <= TechLevel) {
                bool found = false;
                for (int base = 0; base < Rule->BaseUnit.Count(); base++) {
                    if (Rule->BaseUnit[base] == type) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    count++;
                    total += type->Cost_Of();
                }
            }
        }
        for (int infantry = 0; infantry < InfantryTypes.Count(); infantry++) {
            InfantryTypeClass * type = InfantryTypes[infantry];
            if (type->AllowedToStartInMultiplayer && (owners & type->Ownable) && type->TechLevel <= TechLevel) {
                count++;
                total += type->Cost_Of();
            }
        }
        if (count == 0) {
            count = 1;
        }
        budget = ((count / 2 + total) / count) * Session.Options.UnitCount;
    }

    for (int index = 0; index < Houses.Count(); index++) {
        HouseClass * house = Houses[index];
        if (!house->Class->IsMultiplayPassive) {
            int money = budget;
            if (!Create_Base(house, money)) {
                return false;
            }
            if (!Create_Units(house, money)) {
                return false;
            }
            if (money > 0) {
                house->Give_Money(money);
            }
            house->List54A0.Clear();
            house->List54D0.Clear();
            house->List54C0.Clear();
            house->List54B0.Clear();
        }
    }
    Debug_Printf("Finished unit generation. Random number is %d\n", Scen->RandomNumber(0, 0xFFFF));
    return true;
}

bool MultiplayerGameMode::Create_Base(HouseClass * house, int &)
{
    if (!Session.Options.Bases) {
        return true;
    }
    UnitTypeClass * type = house->Pick_Unit(Rule->BaseUnit);
    if (type) {
        UnitClass * unit = new UnitClass(type, house);
        if (unit) {
            if (unit->Unlimbo(house->StartCoord, 0)) {
                return true;
            }
            if (Place_Near(unit, Coord_Cell(house->StartCoord), 1)) {
                return true;
            }
            delete unit;
        }
    }
    return false;
}

// level-2 1.001: INFERRED helper for excluding base unit types.
static inline bool Is_Base_Unit(UnitTypeClass * type)
{
    for (int base = 0; base < Rule->BaseUnit.Count(); ++base) {
        if (Rule->BaseUnit[base] == type) {
            return true;
        }
    }
    return false;
}

// level-2 1.001: INFERRED helper for successful unit deployment.
static inline void On_Starting_Unit_Placed(TechnoClass * techno, TechnoTypeClass * type, HouseClass * house, int & budget)
{
    Debug_Printf("House %s deployed object %s\n", house->Class->ID, house->IniName);
    budget -= type->Cost_Of();
    if (Scen->Flags & 0x200) {
        techno->Veterancy.Set_Elite(true);
    }
    if (house->Func_4F47F0()) {
        techno->Queue_Mission(MISSION_5);
    } else {
        techno->Queue_Mission(MISSION_11);
    }
}

bool MultiplayerGameMode::Create_Units(HouseClass * house, int & budget)
{
    if (budget > 0) {
        int start = budget;
        DynamicVectorClass<UnitTypeClass *> units;
        DynamicVectorClass<InfantryTypeClass *> infantry;
        unsigned int owner = 1 << house->Class->CountryIndex;

        for (int unit = 0; unit < UnitTypes.Count(); unit++) {
            UnitTypeClass * type = UnitTypes[unit];
            if (type->AllowedToStartInMultiplayer && (type->Ownable & owner) && type->TechLevel <= house->TechLevel) {
                if (!Is_Base_Unit(type)) {
                    units.Add(type);
                }
            }
        }
        for (int inf = 0; inf < InfantryTypes.Count(); inf++) {
            InfantryTypeClass * type = InfantryTypes[inf];
            if (type->AllowedToStartInMultiplayer && (type->Ownable & owner) && type->TechLevel <= house->TechLevel) {
                infantry.Add(type);
            }
        }

        if (units.Count() == 0 && infantry.Count() == 0) {
            return false;
        }

        int tries = 20;
        while (budget > 0 && tries > 0) {
            TechnoTypeClass * type;
            if (budget > start / 3 && units.Count() != 0) {
                type = units[Scen->RandomNumber(0, units.Count() - 1)];
            } else {
                type = infantry[Scen->RandomNumber(0, infantry.Count() - 1)];
            }
            ObjectClass * object = type->Create_One_Of(house);
            TechnoClass * techno = dynamic_cast<TechnoClass *>(object);
            if (!Place_Near(techno, Coord_Cell(house->StartCoord), 4)) {
                delete techno;
                tries--;
            } else {
                On_Starting_Unit_Placed(techno, type, house, budget);
            }
        }
    }
    return true;
}

bool MultiplayerGameMode::Virtual_28()
{
    return true;
}

int MultiplayerGameMode::Player_Team(int id)
{
    for (int index = 0; index < Session.Players.Count(); index++) {
        if (Session.Players[index]->ID == id) {
            return Session.Players[index]->Team;
        }
    }
    return -1;
}

bool MultiplayerGameMode::Reveal_Map()
{
    return true;
}

MultiplayerGameMode::InitializerBase::InitializerBase()
{
}

#line 650 "C:\\RA2\\Multiplayer.cpp"
void MultiplayerGameMode::Read_Game_Modes(CharStringClass const & section, InitializerBase const & initializer)
{
    CCFileClass file("MPModes.ini");
    if (file.Is_Available()) {
        INIClass ini;
        if (ini.Load(file, false) > 0) {
            int count = ini.Entry_Count(section);
            for (int index = 0; index < count; index++) {
                CharStringClass entry = ini.Get_Entry(section, index);
                int id = entry.As_Int();
                CharStringClass line;
                if (ini.Get_String(section, entry, NullString, line) > 0) {
                    CharStringClass token;
                    int pos = line.Get_Token(0, ",", token);
                    if (token.Get_Length()) {
                        token.Trim_Left(" ");
                        token.Trim_Right(" ");
#line 677
                        WideStringClass name(Fetch_String(token, NULL, __FILE__, __LINE__));
                        CharStringClass token2;
                        pos = line.Get_Token(pos, ",", token2);
                        if (token2.Get_Length()) {
                            token2.Trim_Left(" ");
                            token2.Trim_Right(" ");
#line 688
                            WideStringClass description(Fetch_String(token2, NULL, __FILE__, __LINE__));
                            CharStringClass ini_file;
                            pos = line.Get_Token(pos, ",", ini_file);
                            if (ini_file.Get_Length()) {
                                ini_file.Trim_Left(" ");
                                ini_file.Trim_Right(" ");
                                CharStringClass key;
                                pos = line.Get_Token(pos, ",", key);
                                key.Trim_Left(" ");
                                key.Trim_Right(" ");
                                CharStringClass random;
                                line.Get_Token(pos, ",", random);
                                random.Trim_Left(" ");
                                random.Trim_Right(" ");
                                bool random_maps = true;
                                if (random.Get_Length() > 0) {
                                    random_maps = (stricmp(random, "false") != 0);
                                }
                                if (name.Get_Length() > 0 && ini_file.Get_Length() > 0 && key.Get_Length() > 0) {
                                    MultiplayerGameMode * mode = initializer.Create(name, description, ini_file, key, random_maps, id);
                                    int pos2 = 0;
                                    while (pos2 < Game_Modes().Count()) {
                                        if (Game_Modes()[pos2]->ID > mode->ID) {
                                            break;
                                        }
                                        pos2++;
                                    }
                                    if (pos2 == 0) {
                                        Game_Modes().Add_Head(mode);
                                    } else {
                                        Game_Modes().Add_After(mode, pos2 - 1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

MultiplayerGameMode::InitializerBase::~InitializerBase()
{
}

void MultiplayerGameMode::Init_Game_Modes()
{
    Free_Game_Modes();
    Initializer<MultiplayerBattle> battle;
    Read_Game_Modes("Battle", battle);
    Initializer<MultiplayerManBattle> manbattle;
    Read_Game_Modes("ManBattle", manbattle);
    Initializer<MultiplayerSiege> siege;
    Read_Game_Modes("Siege", siege);
    Initializer<UnholyAlliance> unholy;
    Read_Game_Modes("Unholy", unholy);
    Initializer<FreeForAll> freeforall;
    Read_Game_Modes("FreeForAll", freeforall);
    Initializer<MPCooperative> cooperative;
    Read_Game_Modes("Cooperative", cooperative);
}

void MultiplayerGameMode::Free_Game_Modes()
{
    for (int index = 0; index < Game_Modes().ActiveCount; index++) {
        delete Game_Modes()[index];
    }
}
