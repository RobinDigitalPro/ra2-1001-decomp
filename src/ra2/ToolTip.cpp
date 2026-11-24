// C:\RA2\ToolTip.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Tool tip manager: a list of screen regions with text labels, shown after a mouse-move delay.
// Class names come from RTTI (.?AVToolTipManager@@ vtable 0x7987dc, .?AVCCToolTip@@ derives from it,
// .?AV?$DynamicVectorClass@PBVToolTip@@@@); all method, member and variable names are provisional.
//
// TU boundary note: the code of this file starts at 0x2e0580 (a 16-byte RectangleStruct static
// initializer, .bss 0xaa86f0) and ends at 0x2e1654. 0x2e03c0..0x2e0574 is ToggleClass (TOGGLE.CPP),
// and the GAMECONST initializers 0x2e0030..0x2e01e0 with 0x2e0200..0x2e03b0 form the TU before it.
// (integrator 2026-11-18: those initializers now live in unnamed/TU_6E0030.cpp)
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "RECT.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0

// Copy of VECTOR.H plus the constructors (and Count) that VECTOR.H does not have yet. The
// constructors are inlined into ToolTipManager::ToolTipManager (0x2e05a0); member code unchanged.
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
    int Delete(T const & object);
    int Delete(int index);

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

template<class T> inline int DynamicVectorClass<T>::Delete(T const & object)
{
    int index = ID(object);
    if (index != -1) {
        return Delete(index);
    }
    return false;
}

template<class T> inline int DynamicVectorClass<T>::Delete(int index)
{
    if (index < ActiveCount) {
        ActiveCount--;
        for (int i = index; i < ActiveCount; i++) {
            (*this)[i] = (*this)[i+1];
        }
        return true;
    }
    return false;
}

// Binary search over a sorted array (instance 0x2e1610, __fastcall under -Gr).
template<class T> T * Binary_Search(T * A, int n, T const & key)
{
    int stride = n;
    while (stride > 0) {
        int pivot = stride / 2;
        T * pivot_point = &A[pivot];
        if (key < *pivot_point) {
            stride = pivot;
        } else {
            if (*pivot_point == key) {
                return pivot_point;
            }
            A = pivot_point + 1;
            stride -= pivot + 1;
        }
    }
    return 0;
}

// Sorted ID -> data index (IndexClass<unsigned int, ToolTip const *> instance: Is_Archive_Same 0x2e1540,
// Search_For_Node 0x2e1560, search_compfunc 0x2e15e0, NodeElement ctor 0x2e1530). The key is
// unsigned (Binary_Search compares with jbe/jae) while search_compfunc compares ints (setge).
// Which calls VC6 inlines depends on its per-caller inline budget, so extra inline levels in
// callers (Hide in Remove) matter.
template<class T, class U> class IndexClass {
public:
    IndexClass() : IndexTable(0), IndexCount(0), IndexSize(0), IsSorted(false), Archive(0) {}
    ~IndexClass() { Clear(); }

    bool Add_Index(T const & id, U const & data);
    bool Remove_Index(T const & id);
    bool Is_Present(T const & id) const;
    int Count() const { return IndexCount; }
    U const & Fetch_Index(T const & id) const;
    void Clear();

private:
    struct NodeElement {
        NodeElement() {}
        bool operator == (NodeElement const & elem) const { return ID == elem.ID; }
        bool operator < (NodeElement const & elem) const { return ID < elem.ID; }
        T ID;
        U Data;
    };

    bool Increase_Table_Size(int amount);
    bool Is_Archive_Same(T const & id) const;
    void Invalidate_Archive() const { ((IndexClass<T, U> *)this)->Archive = 0; }
    void Set_Archive(NodeElement const * node) const { ((IndexClass<T, U> *)this)->Archive = node; }
    NodeElement const * Search_For_Node(T const & id) const;
    static int __cdecl search_compfunc(void const * ptr, void const * ptr2);

    NodeElement * IndexTable;
    int IndexCount;
    int IndexSize;
    bool IsSorted;
    NodeElement const * Archive;
};

template<class T, class U> void IndexClass<T, U>::Clear()
{
    delete [] IndexTable;
    IndexTable = 0;
    IndexCount = 0;
    IndexSize = 0;
    IsSorted = false;
    Invalidate_Archive();
}

template<class T, class U> bool IndexClass<T, U>::Increase_Table_Size(int amount)
{
    if (amount < 0) return false;

    NodeElement * table = new NodeElement[IndexSize + amount];
    if (table != NULL) {
        for (int index = 0; index < IndexCount; index++) {
            table[index] = IndexTable[index];
        }
        delete [] IndexTable;
        IndexTable = table;
        IndexSize += amount;
        Invalidate_Archive();
        return true;
    }
    return false;
}

template<class T, class U> bool IndexClass<T, U>::Add_Index(T const & id, U const & data)
{
    if (IndexCount + 1 > IndexSize) {
        if (!Increase_Table_Size(IndexSize == 0 ? 10 : IndexSize)) {
            return false;
        }
    }
    IndexTable[IndexCount].ID = id;
    IndexTable[IndexCount].Data = data;
    ++IndexCount;
    IsSorted = false;
    return true;
}

template<class T, class U> bool IndexClass<T, U>::Remove_Index(T const & id)
{
    int found_index = -1;
    if (IndexCount != 0) {
        if (!IsSorted) {
            qsort(&IndexTable[0], IndexCount, sizeof(IndexTable[0]), search_compfunc);
            Invalidate_Archive();
            IsSorted = true;
        }
        NodeElement elem;
        elem.ID = id;
        NodeElement * nodeptr = Binary_Search(IndexTable, IndexCount, elem);
        if (nodeptr != NULL) {
            found_index = nodeptr - IndexTable;
        }
    }
    if (found_index != -1) {
        for (int index = found_index + 1; index < IndexCount; index++) {
            IndexTable[index - 1] = IndexTable[index];
        }
        IndexCount--;
        NodeElement fake;
        fake.ID = T();
        fake.Data = U();
        IndexTable[IndexCount] = fake;
        Invalidate_Archive();
        return true;
    }
    return false;
}

template<class T, class U> bool IndexClass<T, U>::Is_Present(T const & id) const
{
    if (IndexCount == 0) {
        return false;
    }
    if (Is_Archive_Same(id)) {
        return true;
    }
    NodeElement const * nodeptr = Search_For_Node(id);
    if (nodeptr != NULL) {
        Set_Archive(nodeptr);
        return true;
    }
    return false;
}

template<class T, class U> U const & IndexClass<T, U>::Fetch_Index(T const & id) const
{
    static U _x;
    if (Is_Present(id)) {
        return Archive->Data;
    }
    return _x;
}

template<class T, class U> bool IndexClass<T, U>::Is_Archive_Same(T const & id) const
{
    if (Archive != 0 && Archive->ID == id) {
        return true;
    }
    return false;
}

template<class T, class U>
typename IndexClass<T, U>::NodeElement const * IndexClass<T, U>::Search_For_Node(T const & id) const
{
    if (IndexCount == 0) {
        return 0;
    }
    if (!IsSorted) {
        qsort(&IndexTable[0], IndexCount, sizeof(IndexTable[0]), search_compfunc);
        Invalidate_Archive();
        ((IndexClass<T, U> *)this)->IsSorted = true;
    }
    NodeElement elem;
    elem.ID = id;
    return Binary_Search(IndexTable, IndexCount, elem);
}

template<class T, class U> int __cdecl IndexClass<T, U>::search_compfunc(void const * ptr1, void const * ptr2)
{
    if (*(int const *)ptr1 == *(int const *)ptr2) {
        return 0;
    }
    if (*(int const *)ptr1 < *(int const *)ptr2) {
        return -1;
    }
    return 1;
}

// One registered tool tip region, 0x1c bytes (operator new(0x1c) in ToolTipManager::Add).
// RTTI names it a class (PBVToolTip). The memberwise copy in Add needs a user-written copy
// constructor (an implicit one gives rep movsd); the null checks before operator delete need a
// destructor. Both are provisional reconstructions of that evidence.
class ToolTip {
public:
    ToolTip(ToolTip const & that) : ID(that.ID), Region(that.Region), Text(that.Text), Flag(that.Flag) {}
    ~ToolTip() {}
    unsigned ID;                    // +0x00 key in the index
    RectangleStruct Region;         // +0x04 screen region
    char const * Text;              // +0x14 string-table label; NULL: ask Get_Text(ID)
    bool Flag;                      // +0x18 unused here
};

// The tip currently displayed: position and text (+0x18 of ToolTipManager, 0x210 bytes).
struct ToolTipText {
    RectangleStruct Region;         // +0x00
    wchar_t Text[256];              // +0x10
};

extern bool InstantToolTips;        // 0xa292fc: nonzero shows a tip at once on mouse move

enum { TOOLTIP_TIMER = 0x54544950 };    // 'TTIP' timer ID

class ToolTipManager {
public:
    ToolTipManager(HWND window);
    virtual ~ToolTipManager();
    virtual bool Set_Position(ToolTipText & info);      // slot 1, 0x2e1040
    virtual void Erase(ToolTipText & info);             // slot 2, 0x2e1050
    virtual void Draw(bool update);                     // slot 3, 0x2e1120
    virtual void Draw_Tip(ToolTipText & info);          // slot 4, 0x2e1150
    virtual wchar_t const * Get_Text(int id);           // slot 5, 0x2e1170

    void Set_Active(bool on);
    void Message(MSG const * msg);
    void Set_Delay(int delay);
    void Save_Delay();
    void Restore_Delay();
    int Get_Duration() const;
    void Set_Duration(int duration);
    int Count() const;
    bool Add(ToolTip const & tip);
    void Remove(unsigned id);
    bool Get(unsigned id, ToolTip * tip);
    ToolTip const * Find(POINT const & point);
    bool Update();
    void Hide();
    bool Is_Showing() const;

    // Inline helper (provisional): Update clears through the reference in one path and through
    // this in the other, which plain member stores do not reproduce.
    void Clear_Info(ToolTipText & info)
    {
        info.Region.X = 0;
        info.Region.Y = 0;
        info.Region.Width = 0;
        info.Region.Height = 0;
        Current = NULL;
    }

protected:
    ToolTip const * Current;                            // +0x004
    HWND Window;                                        // +0x008
    bool IsActive;                                      // +0x00c
    POINT CursorPos;                                    // +0x010
    ToolTipText Info;                                   // +0x018
    int Delay;                                          // +0x228 ms before showing
    int SavedDelay;                                     // +0x22c
    int Duration;                                       // +0x230 ms a tip stays visible
    DynamicVectorClass<ToolTip const *> ToolTips;       // +0x234
    IndexClass<unsigned int, ToolTip const *> Index;    // +0x24c
};

// ---- end of local declarations ----

ToolTipManager::ToolTipManager(HWND window) :
    Current(NULL),
    Window(window),
    IsActive(false),
    Delay(1000),
    Duration(10000)
{
    ToolTips.Clear();
    Index.Clear();
}

ToolTipManager::~ToolTipManager()
{
    KillTimer(Window, TOOLTIP_TIMER);
    Hide();
    Index.Clear();
    for (int index = 0; index < ToolTips.Count(); index++) {
        delete (ToolTip *)ToolTips[index];
    }
    ToolTips.Clear();
}

void ToolTipManager::Set_Active(bool on)
{
    if (IsActive != on) {
        IsActive = on;
        if (!on) {
            KillTimer(Window, TOOLTIP_TIMER);
            Hide();
        }
        Debug_Printf("Tooltips are %s.\n", (IsActive == true) ? "on" : "off");
    }
}

void ToolTipManager::Message(MSG const * msg)
{
    if (IsActive == true) {
        switch (msg->message) {
            case WM_LBUTTONDOWN:
            case WM_LBUTTONUP:
            case WM_RBUTTONDOWN:
            case WM_RBUTTONUP:
            case WM_MBUTTONDOWN:
            case WM_MBUTTONUP:
                KillTimer(Window, TOOLTIP_TIMER);
                Hide();
                break;

            case WM_MOUSEMOVE:
                if (Delay != 0 && !InstantToolTips) {
                    KillTimer(Window, TOOLTIP_TIMER);
                    SetTimer(Window, TOOLTIP_TIMER, Delay, NULL);
                    Hide();
                } else {
                    GetCursorPos(&CursorPos);
                    ScreenToClient(Window, &CursorPos);
                    Current = Find(CursorPos);
                    if (Update()) {
                        SetTimer(Window, TOOLTIP_TIMER, Duration, NULL);
                    }
                }
                break;

            case WM_TIMER:
                if (msg->wParam == TOOLTIP_TIMER) {
                    KillTimer(Window, TOOLTIP_TIMER);
                    if (Current != NULL) {
                        Erase(Info);
                    } else {
                        GetCursorPos(&CursorPos);
                        ScreenToClient(Window, &CursorPos);
                        Current = Find(CursorPos);
                        if (Update()) {
                            SetTimer(Window, TOOLTIP_TIMER, Duration, NULL);
                        }
                    }
                }
                break;
        }
    }
}

void ToolTipManager::Set_Delay(int delay)
{
    Delay = delay;
}

void ToolTipManager::Save_Delay()
{
    SavedDelay = Delay;
}

void ToolTipManager::Restore_Delay()
{
    Delay = SavedDelay;
}

int ToolTipManager::Get_Duration() const
{
    return Duration;
}

void ToolTipManager::Set_Duration(int duration)
{
    Duration = duration;
}

int ToolTipManager::Count() const
{
    return ToolTips.Count();
}

bool ToolTipManager::Add(ToolTip const & tip)
{
    unsigned id = tip.ID;
    if (Index.Is_Present(id)) {
        return false;
    }
    ToolTip * newtip = new ToolTip(tip);
    if (newtip == NULL) {
        return false;
    }
    if (!ToolTips.Add(newtip)) {
        delete newtip;
        return false;
    }
    Index.Add_Index(newtip->ID, newtip);
    return true;
}

void ToolTipManager::Remove(unsigned id)
{
    if (Index.Is_Present(id)) {
        ToolTip const * tip = Index.Fetch_Index(id);
        if (Current == tip) {
            Hide();
        }
        Index.Remove_Index(tip->ID);
        ToolTips.Delete(tip);
        delete (ToolTip *)tip;
    }
}

bool ToolTipManager::Get(unsigned id, ToolTip * tip)
{
    if (!Index.Is_Present(id)) {
        return false;
    }
    if (tip != NULL) {
        *tip = *Index.Fetch_Index(id);
    }
    return true;
}

ToolTip const * ToolTipManager::Find(POINT const & point)
{
    for (int index = 0; index < ToolTips.Count(); index++) {
        RectangleStruct const & rect = ToolTips[index]->Region;
        if (point.x >= rect.X && point.x <= rect.X + rect.Width &&
            point.y >= rect.Y && point.y <= rect.Y + rect.Height) {
            return ToolTips[index];
        }
    }
    return NULL;
}

bool ToolTipManager::Set_Position(ToolTipText &)
{
    return true;
}

void ToolTipManager::Erase(ToolTipText &)
{
    Info.Region.X = 0;
    Info.Region.Y = 0;
    Info.Region.Width = 0;
    Info.Region.Height = 0;
    Current = NULL;
}

bool ToolTipManager::Update()
{
    if (Current != NULL) {
        wchar_t const * text;
        if (Current->Text == NULL) {
            text = Get_Text(Current->ID);
        } else {
#line 563 "C:\\RA2\\ToolTip.cpp"
            text = Fetch_String(Current->Text, NULL, __FILE__, __LINE__);
        }
        if (text != NULL && wcslen(text) > 0) {
            wcsncpy(Info.Text, text, 256);
            Info.Region.X = CursorPos.x;
            Info.Region.Y = CursorPos.y;
            if (!Set_Position(Info)) {
                Clear_Info(Info);
            }
        } else {
            Clear_Info(Info);
        }
    }
    return Current != NULL;
}

void ToolTipManager::Draw(bool update)
{
    if (update == true) {
        Update();
    }
    if (Current != NULL) {
        Draw_Tip(Info);
    }
}

void ToolTipManager::Draw_Tip(ToolTipText & info)
{
    Debug_Printf("ToolTip: %s\n", info.Text);
}

wchar_t const * ToolTipManager::Get_Text(int)
{
    return NULL;
}

void ToolTipManager::Hide()
{
    if (Current != NULL) {
        Erase(Info);
    }
}

bool ToolTipManager::Is_Showing() const
{
    return Current != NULL;
}
