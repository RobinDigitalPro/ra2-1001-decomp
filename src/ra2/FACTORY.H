// COM class factory template (RTTI .?AV?$TClassFactory@...; 74 instances in GAME.EXE).
// Member code reconstructed from TClassFactory<AITriggerTypeClass> (vtable 0x796f18). Names provisional.
#pragma once
#include <windows.h>
#include <objidl.h>

template<class T> class TClassFactory : public IClassFactory {
public:
    TClassFactory() : RefCount(0) {}

    virtual HRESULT __stdcall QueryInterface(REFIID riid, void ** ppv)
    {
        if (ppv == NULL) {
            return E_POINTER;
        }
        *ppv = NULL;
        if (riid == IID_IUnknown || riid == IID_IClassFactory) {
            *ppv = this;
        }
        if (*ppv == NULL) {
            return E_NOINTERFACE;
        }
        AddRef();
        return S_OK;
    }

    virtual ULONG __stdcall AddRef()
    {
        return InterlockedIncrement(&RefCount);
    }

    virtual ULONG __stdcall Release()
    {
        LONG count = InterlockedDecrement(&RefCount);
        if (count == 0) {
            delete this;
        }
        return count;
    }

    virtual HRESULT __stdcall CreateInstance(IUnknown * pUnkOuter, REFIID riid, void ** ppv)
    {
        if (ppv == NULL) {
            return E_INVALIDARG;
        }
        *ppv = NULL;
        if (pUnkOuter != NULL) {
            return CLASS_E_NOAGGREGATION;
        }
        T * obj = new T;
        if (obj == NULL) {
            return E_OUTOFMEMORY;
        }
        HRESULT hr = obj->QueryInterface(riid, ppv);
        if (FAILED(hr)) {
            delete obj;
        }
        return hr;
    }

    virtual HRESULT __stdcall LockServer(BOOL fLock)
    {
        if (fLock) {
            RefCount++;
        } else {
            RefCount--;
        }
        return S_OK;
    }

    LONG RefCount;
};
