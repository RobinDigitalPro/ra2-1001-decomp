// UnholyAlliance game mode TU (file name unknown; level-2 reconstruction of GAME.EXE 1.001); placeholder name TU_5A8D20.
// UnholyAlliance: the "Unholy Alliance" multiplayer game mode (each house gets the first two Rule->BaseUnit units).
// Evidence: RTTI .?AVUnholyAlliance@@ (vtable 0x791c5c) names the class; the constructor 0x5a8f10 is
// the one MultiplayerGameMode::Initializer<UnholyAlliance> calls. All other names are provisional.
// TU span: the 12 GAMECONST initializers 0x1a8d20..0x1a8ed0, the 16-byte zeroing initializer
// 0x1a8ef0 (.bss 0xa593a8), then the code 0x1a8f10..0x1a9111 in source order followed by the
// deleting destructor (same layout as MPSiege.cpp, TU_5A7F90.cpp).
// The local declarations are copied from TU_5A7F90.cpp (MPSiege.cpp).
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
    WideStringClass & operator = (wchar_t const * string);      // 0x75b4b0
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
class RandomClass {
public:
    int operator()(int minval, int maxval);     // 0x62fe40
};

// Only the fields used here; layout not reconstructed.
class ScenarioClass {
public:
    unsigned long Flags;                        // +0x000 (bit 10 cleared by Prepare_Scenario)
    char Unknown004[0x218 - 0x004];
    RandomClass RandomNumber;                   // +0x218
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

// RTTI .?AVMultiplayerSiegeDefenderTeam@@ / .?AVMultiplayerSiegeAttackerTeam@@ (MPSiegeTeam.cpp).
class MultiplayerSiegeDefenderTeam : public MultiplayerTeam {
public:
    MultiplayerSiegeDefenderTeam();             // 0x5a89a0
};
class MultiplayerSiegeAttackerTeam : public MultiplayerTeam {
public:
    MultiplayerSiegeAttackerTeam();             // 0x5a8a40
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
class BuildingTypeClass;
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

// RTTI .?AVBuildingClass@@, 0x5e0 bytes (operator new size here).
class BuildingClass : public TechnoClass {
public:
    BuildingClass(BuildingTypeClass const * type, HouseClass * house);   // 0x438b60
    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    char Unknown11C[0x5E0 - sizeof(TechnoClass)];
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
    char Unknown0000[0x7C8];
    DynamicVectorClass<BuildingTypeClass const *> SiegeBase;   // +0x7c8 (the defender's base building list; name provisional)
    char Unknown07E0[0x9D0 - 0x7E0];
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
    BuildingTypeClass const * Get_First_Ownable(DynamicVectorClass<BuildingTypeClass const *> const & list) const;   // 0x4eeb00 (as in m85 house.cpp)
    void Give_Money(int amount);                // 0x4e4ae0 (name provisional)
    UnitTypeClass * Pick_Unit(DynamicVectorClass<UnitTypeClass *> const & list) const;   // 0x4eebf0 (name provisional)
    bool Func_4F47F0() const;                   // 0x4f47f0 (meaning unknown, see Event.CPP)

    char Unknown0000[0x30];
    int ID;                                     // +0x30 (compared with the player node ID; name provisional)
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
// RTTI .?AVUnholyAlliance@@ : MultiplayerGameMode, vtable 0x791c5c (slots 0, 4, 5, 6 and 42
// overridden: 0x5a90f0, 0x5a8f60, 0x5a8f70, 0x5a8fa0, 0x5a8fb0).
class UnholyAlliance : public MultiplayerGameMode {
public:
    UnholyAlliance(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x5a8f10
    virtual ~UnholyAlliance();
    virtual bool Assign_Teams();
    virtual bool Can_Start(WideStringClass & reason);
    virtual bool Virtual_06();
    virtual bool Create_Base(HouseClass * house, int & cost);
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

#include "RECT.H"
static RectangleStruct const ZeroRectC(0, 0, 0, 0);

UnholyAlliance::UnholyAlliance(WideStringClass const & name, WideStringClass const & description,
    CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id) :
    MultiplayerGameMode(name, description, ini_file, key, random_maps, id)
{
}

UnholyAlliance::~UnholyAlliance()
{
}

// Every player builds a base.
bool UnholyAlliance::Assign_Teams()
{
    Session.Options.Bases = true;
    return true;
}

bool UnholyAlliance::Can_Start(WideStringClass & reason)
{
    return(Session.Options.Bases && MultiplayerGameMode::Can_Start(reason));
}

bool UnholyAlliance::Virtual_06()
{
    Session.Options.Bases = true;
    return true;
}

// Each house gets the first two base units of the rules: the first is unlimboed three cells
// south-east of the start position, the second (or a failed first) is placed near the start cell.
bool UnholyAlliance::Create_Base(HouseClass * house, int &)
{
    bool failed = false;
    for (int index = 0; index < 2; index++) {
        UnitTypeClass * type = Rule->BaseUnit[index];
        if (!type) {
            failed = true;
            continue;
        }
        UnitClass * unit = new UnitClass(type, house);
        if (!unit) {
            failed = true;
            continue;
        }
        CellStruct cell = Coord_Cell(house->StartCoord);
        CellStruct offset((short)(cell.X + 3), (short)(cell.Y + 3));
        if (index == 0) {
            if (unit->Unlimbo(CoordStruct(offset.X * 256 + 128, offset.Y * 256 + 128, 0), 0)) {
                continue;
            }
        }
        CellStruct spot = Coord_Cell(house->StartCoord);
        if (!Place_Near(unit, spot, 3)) {
            failed = true;
            delete unit;
        }
    }
    return !failed;
}
