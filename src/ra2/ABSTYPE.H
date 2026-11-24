// AbstractTypeClass: base of all type classes (RTTI .?AVAbstractTypeClass@@).
#pragma once
#include "ABSTRACT.H"
#include "VECTOR.H"
#include "FIXSTR.H"

class CCINIClass;
class CRCEngine;

class AbstractTypeClass : public AbstractClass {
public:
    AbstractTypeClass(char const * ini_name);
    AbstractTypeClass(NoInitClass const & x);
    virtual ~AbstractTypeClass();

    int operator == (char const * name) const;

    virtual void Compute_CRC(CRCEngine & crc) const;
    virtual void Load_Theater_Art(int theater);
    virtual bool Read_INI(CCINIClass & ini);
    virtual bool Write_INI(CCINIClass & ini) const;

    FixedString<0x18> ID;            // +0x24
    FixedString<0x1f> UINameLabel;   // +0x3d
    wchar_t const * UIName;          // +0x60
    FixedString<0x30> Name;          // +0x64
};

extern DynamicVectorClass<AbstractTypeClass *> AbstractTypes;

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);
extern wchar_t EmptyUIName[];
