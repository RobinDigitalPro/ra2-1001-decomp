// AbstractClass: root of the game object hierarchy (RTTI .?AVAbstractClass@@).
// The vtable order (24 primary slots) is taken from GAME.EXE 0x785dd8; names are provisional.
#pragma once
#include "COM.H"
#include "NOINIT.H"
#include "GAMECONST.H"

class CRCEngine;
class HouseClass;
class TechnoClass;

class AbstractClass : public IPersistStream, public IRTTITypeInfo, public INoticeSink, public INoticeSource {
public:
    // IUnknown
    virtual HRESULT __stdcall QueryInterface(REFIID riid, void ** ppv);
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();

    // IPersist / IPersistStream
    virtual HRESULT __stdcall GetClassID(CLSID * pClassID) = 0;
    virtual HRESULT __stdcall IsDirty();
    virtual HRESULT __stdcall Load(IStream * pStm) = 0;
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty) = 0;
    virtual HRESULT __stdcall GetSizeMax(ULARGE_INTEGER * pcbSize);

    // IRTTITypeInfo
    virtual int __stdcall What_Am_I() const;
    virtual int __stdcall Fetch_ID() const;
    virtual void __stdcall Create_ID();

    // INoticeSink / INoticeSource
    virtual bool __stdcall INoticeSink_Unknown(DWORD value);
    virtual void __stdcall INoticeSource_Unknown();

    AbstractClass();
    AbstractClass(NoInitClass const & x);
    virtual ~AbstractClass();

    virtual void Init();
    virtual void Pointer_Expired(AbstractClass * object, bool removed);
    virtual int Kind_Of() const = 0;
    virtual int Size_Of() const = 0;
    virtual void Compute_CRC(CRCEngine & crc) const;
    virtual int Owner_House_Index() const;
    virtual HouseClass * Owner_House() const;
    virtual int Array_Index() const;
    virtual bool Is_Dead() const;
    virtual CoordStruct Center_Coord() const;
    virtual CoordStruct Destination_Coord(TechnoClass * docker) const;
    virtual bool Is_On_Floor() const;
    virtual bool Is_In_Air() const;
    virtual CoordStruct Target_Coord() const;
    virtual void AI();

    int UniqueID;                 // +0x10
    unsigned char Flag1:1;        // +0x14
    unsigned char Flag2:1;
    unsigned char Flag3:1;
    int Unknown18;                // +0x18
    int RefCount;                 // +0x1c
    bool Dirty;                   // +0x20
};
