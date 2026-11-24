// Vector templates. Member code reconstructed from GAME.EXE instances (e.g. VectorClass<AbstractTypeClass*>
// vtable 0x78da84 and DynamicVectorClass<AbstractTypeClass*> vtable 0x78da64). Seven virtual slots:
// destructor, operator==, Resize, Clear, ID(T const &), ID(T const *), Fetch. Method names provisional.
#pragma once
#include <stddef.h>

template<class T> class VectorClass {
public:
    VectorClass(unsigned size = 0, T const * array = 0);
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

// Constructor: out of line in GAME.EXE (e.g. VectorClass<char *>::VectorClass 0x4911c0, from coopcamp.cpp).
template<class T> VectorClass<T>::VectorClass(unsigned size, T const * array) :
    Vector(0),
    VectorMax(size),
    IsInitialized(true),
    IsAllocated(false)
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
