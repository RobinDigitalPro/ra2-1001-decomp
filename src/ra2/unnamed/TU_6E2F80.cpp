// unidentified translation unit (GAMECONST.H initializers at 0x2e2f80) (level-2 reconstruction of GAME.EXE 1.001)
// Contents: TriggerTypeClass (RTTI .?AVTriggerTypeClass@@, primary vtable 0x798934, base
// AbstractTypeClass, Size_Of 0xb4, Kind_Of 0x27) and two string-trim helpers. Member and helper
// names are provisional.
#include "../GAMECONST.H"
#include "../RECT.H"
static RectangleStruct const ZeroRectB(0, 0, 0, 0);

#include "../ABSTYPE.H"
#include "../VECTOR.H"
#include "../CRC.H"
#include <new.h>
#include <string.h>
#include <wchar.h>

// ---- local declarations (to be moved to headers by the integrator) ----

class SwizzleManagerClass {
public:
    HRESULT __stdcall Swizzle(void ** pointer);             // 0x695170
    HRESULT __stdcall Here_I_Am(LONG id, void * pointer);   // 0x6951f0
};
extern SwizzleManagerClass SwizzleManager;                  // 0xaa5370

void Detach_This_From_All(AbstractClass * object, bool all);    // 0x6e1e50 (name provisional)

// Trigger event / action list nodes (AbstractClass based; only the fields used here).
class TEventClass : public AbstractClass {
public:
    int Unknown24;                          // +0x24
    TEventClass * Next;                     // +0x28
    int Event;                              // +0x2c
    int Unknown30;                          // +0x30
    int Data;                               // +0x34
};
class TActionClass : public AbstractClass {
public:
    int Unknown24;                          // +0x24
    TActionClass * Next;                    // +0x28
    int Action;                             // +0x2c
};

class HouseTypeClass : public AbstractTypeClass {
};

int Event_Flags(int event);                 // 0x6dbcf0 (name provisional)
int Action_Flags(int action);               // 0x6a8440 (name provisional)

// {C02D1591-0A2A-11D2-ACA7-006008055BB5} (GAME.EXE 0x78cd60)
class __declspec(uuid("C02D1591-0A2A-11D2-ACA7-006008055BB5")) TriggerTypeClass : public AbstractTypeClass {
public:
    TriggerTypeClass(char const * ini_name);
    TriggerTypeClass(NoInitClass const & x) : AbstractTypeClass(x) {}
    virtual ~TriggerTypeClass();

    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);

    virtual void Pointer_Expired(AbstractClass * object, bool removed);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    virtual void Compute_CRC(CRCEngine & crc) const;
    virtual int Array_Index() const;
    virtual bool Read_INI(CCINIClass & ini);
    virtual bool Write_INI(CCINIClass & ini) const;

    bool Has_Event_1A() const;
    bool Has_Event_19() const;
    bool Has_Event_18() const;
    bool Has_Action_0F() const;
    bool Has_Event_1B_1C(int data) const;
    bool Has_Event_24_25(int data) const;
    int Flags() const;

    static TriggerTypeClass * From_Name(char const * name);
    static TriggerTypeClass * Find_Or_Make(char const * name);
    static int Persistence_From_Name(char const * name);
    static char const * Name_From_Persistence(int persistence);

    int ArrayIndex;                         // +0x98
    bool Flag9C;                            // +0x9c
    bool Flag9D;                            // +0x9d
    bool Flag9E;                            // +0x9e
    bool Flag9F;                            // +0x9f
    bool FlagA0;                            // +0xa0
    HouseTypeClass * House;                 // +0xa4
    TriggerTypeClass * Next;                // +0xa8 (attached trigger type)
    TEventClass * Events;                   // +0xac
    TActionClass * Actions;                 // +0xb0
};

extern DynamicVectorClass<TriggerTypeClass *> TriggerTypes;         // 0x84e538
extern DynamicVectorClass<AbstractClass *> AbstractList87A0;        // 0xaa87a0, meaning unknown
extern DynamicVectorClass<AbstractClass *> AbstractList87B8;        // 0xaa87b8, meaning unknown

// ---- end of local declarations ----

static char const * const PersistenceNames[3] = { "Volatile", "Semi-persistant", "Persistent" };

TriggerTypeClass::TriggerTypeClass(char const * ini_name) :
    AbstractTypeClass(ini_name),
    ArrayIndex(-1),
    Flag9C(true),
    Flag9D(true),
    Flag9E(true),
    Flag9F(true),
    FlagA0(false),
    House(NULL),
    Next(NULL),
    Events(NULL),
    Actions(NULL)
{
    AbstractList87A0.Add(this);
    AbstractList87B8.Add(this);
    ArrayIndex = TriggerTypes.Count();
    TriggerTypes.Add(this);
}

TriggerTypeClass::~TriggerTypeClass()
{
    Detach_This_From_All(this, true);
    TriggerTypes.Delete(this);
    TActionClass * action = Actions;
    while (action != NULL) {
        TActionClass * next = action->Next;
        delete action;
        action = next;
    }
    TEventClass * event = Events;
    while (event != NULL) {
        TEventClass * next = event->Next;
        delete event;
        event = next;
    }
    AbstractList87B8.Delete(this);
    AbstractList87A0.Delete(this);
}

bool TriggerTypeClass::Has_Event_1A() const
{
    bool found = false;
    for (TEventClass * event = Events; event != NULL; event = event->Next) {
        if (event->Event == 0x1a) {
            found = true;
            break;
        }
    }
    return found;
}

bool TriggerTypeClass::Has_Event_19() const
{
    bool found = false;
    for (TEventClass * event = Events; event != NULL; event = event->Next) {
        if (event->Event == 0x19) {
            found = true;
            break;
        }
    }
    return found;
}

bool TriggerTypeClass::Has_Event_18() const
{
    bool found = false;
    for (TEventClass * event = Events; event != NULL; event = event->Next) {
        if (event->Event == 0x18) {
            found = true;
            break;
        }
    }
    return found;
}

bool TriggerTypeClass::Has_Action_0F() const
{
    bool found = false;
    for (TActionClass * action = Actions; action != NULL; action = action->Next) {
        if (action->Action == 0x0f) {
            found = true;
            break;
        }
    }
    return found;
}

bool TriggerTypeClass::Has_Event_1B_1C(int data) const
{
    bool found = false;
    for (TEventClass * event = Events; event != NULL; event = event->Next) {
        if ((event->Event == 0x1b || event->Event == 0x1c) && event->Data == data) {
            found = true;
            break;
        }
    }
    return found;
}

bool TriggerTypeClass::Has_Event_24_25(int data) const
{
    bool found = false;
    for (TEventClass * event = Events; event != NULL; event = event->Next) {
        if ((event->Event == 0x24 || event->Event == 0x25) && event->Data == data) {
            found = true;
            break;
        }
    }
    return found;
}

void TriggerTypeClass::Pointer_Expired(AbstractClass * object, bool removed)
{
    if (Next != NULL && Next == object) {
        Next = Next->Next;
    }
    TActionClass * action;
    for (action = Actions; action != NULL; action = action->Next) {
        action->Pointer_Expired(object, true);
    }
    if (Actions == object) {
        Actions = Actions->Next;
    }
    TEventClass * event;
    for (event = Events; event != NULL; event = event->Next) {
        event->Pointer_Expired(object, true);
    }
    if (Events == object) {
        Events = Events->Next;
    }
}

TriggerTypeClass * TriggerTypeClass::From_Name(char const * name)
{
    if (name != NULL) {
        for (int index = 0; index < TriggerTypes.Count(); index++) {
            if (!stricmp(TriggerTypes[index]->ID, name) || !stricmp(TriggerTypes[index]->Name, name)) {
                return TriggerTypes[index];
            }
        }
    }
    return NULL;
}

int TriggerTypeClass::Persistence_From_Name(char const * name)
{
    for (int index = 0; index < 3; index++) {
        if (!stricmp(name, PersistenceNames[index])) {
            return index;
        }
    }
    return 0;
}

char const * TriggerTypeClass::Name_From_Persistence(int persistence)
{
    return PersistenceNames[persistence];
}

int TriggerTypeClass::Flags() const
{
    int flags = 0;
    TEventClass * event;
    for (event = Events; event != NULL; event = event->Next) {
        flags |= Event_Flags(event->Event);
    }
    TActionClass * action;
    for (action = Actions; action != NULL; action = action->Next) {
        flags |= Action_Flags(action->Action);
    }
    if (Next != NULL) {
        return Next->Flags() | flags;
    }
    return flags;
}

TriggerTypeClass * TriggerTypeClass::Find_Or_Make(char const * name)
{
    if (!stricmp("<none>", name) || !stricmp("none", name)) {
        return NULL;
    }
    for (int index = 0; index < TriggerTypes.Count(); index++) {
        if (!stricmp(TriggerTypes[index]->ID, name)) {
            return TriggerTypes[index];
        }
    }
    return new TriggerTypeClass(name);
}

void TriggerTypeClass::Compute_CRC(CRCEngine & crc) const
{
    AbstractTypeClass::Compute_CRC(crc);
    crc(House->Fetch_ID());
    if (Next != NULL) {
        crc(Next->Fetch_ID());
    }
    if (Events != NULL) {
        crc(Events->Fetch_ID());
    }
    if (Actions != NULL) {
        crc(Actions->Fetch_ID());
    }
}

HRESULT __stdcall TriggerTypeClass::GetClassID(CLSID * pClassID)
{
    if (pClassID == NULL) {
        return E_POINTER;
    }
    *pClassID = __uuidof(TriggerTypeClass);
    return S_OK;
}

HRESULT __stdcall TriggerTypeClass::Load(IStream * pStm)
{
    HRESULT hr = AbstractTypeClass::Load(pStm);
    if (FAILED(hr)) {
        return hr;
    }
    new (this) TriggerTypeClass(NoInitClass());
    SwizzleManager.Swizzle((void **)&Next);
    SwizzleManager.Swizzle((void **)&Events);
    SwizzleManager.Swizzle((void **)&Actions);
    SwizzleManager.Swizzle((void **)&House);
    return S_OK;
}

HRESULT __stdcall TriggerTypeClass::Save(IStream * pStm, BOOL fClearDirty)
{
    HRESULT hr = AbstractTypeClass::Save(pStm, fClearDirty);
    if (SUCCEEDED(hr)) {
        hr = S_OK;
    }
    return hr;
}

int TriggerTypeClass::Kind_Of() const
{
    return 0x27;
}

int TriggerTypeClass::Size_Of() const
{
    return sizeof(TriggerTypeClass);
}

int TriggerTypeClass::Array_Index() const
{
    return ArrayIndex;
}

// 0x2e41d0: remove leading and trailing control/space characters in place (name provisional).
char * strtrim(char * buffer)
{
    if (buffer != NULL) {
        char * source = buffer;
        while (*source != '\0' && (unsigned char)*source <= ' ') {
            source++;
        }
        if (source != buffer) {
            strcpy(buffer, source);
        }
        for (int index = strlen(buffer) - 1; index >= 0; index--) {
            if (*source != '\0' && (unsigned char)buffer[index] <= ' ') {
                buffer[index] = '\0';
            } else {
                break;
            }
        }
    }
    return buffer;
}

// 0x2e4240: wide version of strtrim (name provisional).
wchar_t * wcstrim(wchar_t * buffer)
{
    if (buffer != NULL) {
        wchar_t * source = buffer;
        while (*source != L'\0' && *source <= L' ') {
            source++;
        }
        if (source != buffer) {
            wcscpy(buffer, source);
        }
        for (int index = wcslen(buffer) - 1; index >= 0; index--) {
            if (*source != L'\0' && buffer[index] <= L' ') {
                buffer[index] = L'\0';
            } else {
                break;
            }
        }
    }
    return buffer;
}
