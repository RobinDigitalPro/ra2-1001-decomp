// C:\RA2\AbsType.cpp (level-2 reconstruction of GAME.EXE 1.001)
#include <stdio.h>
#include <string.h>
#include "ABSTYPE.H"
#include "CCINI.H"
#include "CRC.H"

AbstractTypeClass::AbstractTypeClass(char const * ini_name) : AbstractClass()
{
    char buffer[16];
    if (ini_name == NULL) {
        sprintf(buffer, "%08X", this);
        ID = buffer;
    } else {
        ID = ini_name;
    }
    Name = (char const *)ID;
    UIName = EmptyUIName;
    AbstractTypes.Add(this);
}

#line 123 "C:\\RA2\\AbsType.cpp"
AbstractTypeClass::AbstractTypeClass(NoInitClass const & x) : AbstractClass(x), ID(x), UINameLabel(x), Name(x)
{
    if (UINameLabel[0]) {
        // Original __LINE__ is 127.
        UIName = Fetch_String(UINameLabel, NULL, __FILE__, __LINE__);
    } else {
        UIName = EmptyUIName;
    }
}

AbstractTypeClass::~AbstractTypeClass()
{
    AbstractTypes.Delete(this);
}

int AbstractTypeClass::operator == (char const * name) const
{
    return stricmp(name, ID) == 0;
}

bool AbstractTypeClass::Read_INI(CCINIClass & ini)
{
    char buffer[1024];
    if (ini.Is_Present(ID)) {
        ini.Get_String(ID, "Name", Name, buffer, sizeof(Name));
        Name = buffer;
        ini.Get_String(ID, "UIName", UINameLabel, buffer, sizeof(UINameLabel));
        UINameLabel = buffer;
        if (UINameLabel[0]) {
#line 205
            UIName = Fetch_String(UINameLabel, NULL, __FILE__, __LINE__);
        } else {
            UIName = EmptyUIName;
        }
        return true;
    }
    return false;
}

bool AbstractTypeClass::Write_INI(CCINIClass & ini) const
{
    ini.Clear(ID, NULL);
    ini.Put_String(ID, "Name", Name);
    if (UINameLabel[0]) {
        ini.Put_String(ID, "UIName", UINameLabel);
    }
    return true;
}

void AbstractTypeClass::Compute_CRC(CRCEngine & crc) const
{
    AbstractClass::Compute_CRC(crc);
    crc(ID);
    crc(Name);
    crc(UINameLabel);
}

void AbstractTypeClass::Load_Theater_Art(int theater)
{
}
