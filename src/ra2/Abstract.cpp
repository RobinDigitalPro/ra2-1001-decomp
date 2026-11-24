// C:\RA2\Abstract.cpp (level-2 reconstruction of GAME.EXE 1.001)
#include "OSVER.H"
#include "RECT.H"

OSVersionClass OSVersion;
static RectangleStruct const ZeroRectA(0, 0, 0, 0);

#include "ABSTRACT.H"

static RectangleStruct const ZeroRectB(0, 0, 0, 0);
#include "CRC.H"
#include "SCENARIO.H"
#include "SWIZZLE.H"

int __stdcall AbstractClass::What_Am_I() const
{
    return Kind_Of();
}

int __stdcall AbstractClass::Fetch_ID() const
{
    return UniqueID;
}

void __stdcall AbstractClass::Create_ID()
{
    UniqueID = (Scen == NULL) ? 0 : Scen->Get_Unique_ID();
}

AbstractClass::AbstractClass() :
    UniqueID(-1),
    Unknown18(0),
    RefCount(0),
    Dirty(false)
{
    Flag1 = false;
    Flag2 = false;
    Flag3 = false;
}

AbstractClass::AbstractClass(NoInitClass const &)
{
}

AbstractClass::~AbstractClass()
{
}

HRESULT __stdcall AbstractClass::QueryInterface(REFIID riid, void ** ppv)
{
    if (ppv == NULL) {
        return E_POINTER;
    }
    *ppv = NULL;
    if (riid == IID_IUnknown) {
        *ppv = static_cast<IPersistStream *>(this);
    }
    if (riid == IID_IPersistStream) {
        *ppv = static_cast<IPersistStream *>(this);
    }
    if (riid == IID_IPersist) {
        *ppv = static_cast<IPersistStream *>(this);
    }
    if (riid == __uuidof(IRTTITypeInfo)) {
        *ppv = static_cast<IRTTITypeInfo *>(this);
    }
    if (*ppv == NULL) {
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

ULONG __stdcall AbstractClass::AddRef()
{
    return 1;
}

ULONG __stdcall AbstractClass::Release()
{
    return 1;
}

void AbstractClass::Compute_CRC(CRCEngine & crc) const
{
    crc(UniqueID);
    crc((bool)Dirty);
}

HRESULT __stdcall AbstractClass::Save(IStream * pStm, BOOL fClearDirty)
{
    if (!pStm) return E_POINTER;
    AbstractClass * ptr = this;
    HRESULT hr = pStm->Write(&ptr, sizeof(ptr), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(this, Size_Of(), NULL);
    if (SUCCEEDED(hr) && fClearDirty) Dirty = false;
    return hr;
}

HRESULT __stdcall AbstractClass::Load(IStream * pStm)
{
    if (pStm == NULL) {
        return E_POINTER;
    }
    LONG id;
    HRESULT hr = pStm->Read(&id, sizeof(id), NULL);
    if (SUCCEEDED(hr)) {
        SwizzleManager.Here_I_Am(id, this);
        int refcount = RefCount;
        hr = pStm->Read(this, Size_Of(), NULL);
        RefCount = refcount;
    }
    return hr;
}

HRESULT __stdcall AbstractClass::GetSizeMax(ULARGE_INTEGER * pcbSize)
{
    if (pcbSize == NULL) {
        return E_POINTER;
    }
    pcbSize->QuadPart = (DWORD)(Size_Of() + 4);
    return S_OK;
}

bool AbstractClass::Is_Dead() const
{
    return true;
}

HRESULT __stdcall AbstractClass::IsDirty()
{
    return Dirty ? S_OK : S_FALSE;
}

void AbstractClass::Init()
{
}

void AbstractClass::Pointer_Expired(AbstractClass * object, bool removed)
{
}

int AbstractClass::Owner_House_Index() const
{
    return -1;
}

HouseClass * AbstractClass::Owner_House() const
{
    return NULL;
}

int AbstractClass::Array_Index() const
{
    return 0;
}

CoordStruct AbstractClass::Center_Coord() const
{
    return EmptyCoord;
}

CoordStruct AbstractClass::Destination_Coord(TechnoClass * docker) const
{
    return Center_Coord();
}

bool AbstractClass::Is_On_Floor() const
{
    return false;
}

bool AbstractClass::Is_In_Air() const
{
    return false;
}

CoordStruct AbstractClass::Target_Coord() const
{
    return Center_Coord();
}

void AbstractClass::AI()
{
}

bool __stdcall AbstractClass::INoticeSink_Unknown(DWORD value)
{
    return false;
}

void __stdcall AbstractClass::INoticeSource_Unknown()
{
}
