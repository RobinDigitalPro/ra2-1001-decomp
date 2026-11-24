// BufferIOFileClass translation unit 0x42f100..0x42fd44 (level-2 reconstruction of GAME.EXE 1.001)
// file name inferred from class name; not proven by a C:\RA2 string
//
// Contents: a raw file with an optional memory buffer (whole-file cache or a sliding window).
// The class name comes from RTTI (.?AVBufferIOFileClass@@ vtable 0x78773c, 17 slots, bases
// RawFileClass and FileClass); all member names are provisional.
//
// TU span: 0x2f100 (constructor) .. 0x2fd44 (scalar deleting destructor). This file has no dynamic
// initializer; the zeroing initializer 0x2efa0 and the Benchmark members before 0x2f100 are in
// unnamed/TU_42EFA0.cpp, and the next initializer 0x2fd50 starts the Bink movie TU.
#include <errno.h>
#include <stdio.h>
#include <string.h>

// ---- local declarations (to be moved to headers by the integrator) ----

enum { READ = 1, WRITE = 2 };

// File class hierarchy (see Egos.CPP / SendFile.CPP); slot order from the RTTI vtables.
class FileClass {
public:
    virtual ~FileClass();
    virtual char const * File_Name() const = 0;
    virtual char const * Set_Name(char const * filename) = 0;
    virtual int Create() = 0;
    virtual int Delete() = 0;
    virtual bool Is_Available(int forced = false) = 0;
    virtual bool Is_Open() const = 0;
    virtual int Open(char const * filename, int rights = READ) = 0;
    virtual int Open(int rights = READ) = 0;
    virtual long Read(void * buffer, long size) = 0;
    virtual long Seek(long pos, int dir = SEEK_CUR) = 0;
    virtual long Size() = 0;
    virtual long Write(void const * buffer, long size) = 0;
    virtual void Close() = 0;
    virtual unsigned long Get_Date_Time() = 0;
    virtual bool Set_Date_Time(unsigned long datetime) = 0;
    virtual void Error(int error, int canretry = false, char const * filename = NULL) = 0;
};

// RawFileClass (RTTI vtable 0x793c84). The default constructor is inlined into
// BufferIOFileClass's constructors; member layout +0x04..+0x1c from those stores.
class RawFileClass : public FileClass {
public:
    RawFileClass() :
        Rights(READ),
        BiasStart(0),
        BiasLength(-1),
        Handle(-1),
        Filename(0),
        Date(0),
        Time(0),
        Allocated(false)
    {
    }
    virtual ~RawFileClass();                                    // 0x630060
    virtual char const * File_Name() const { return Filename; } // 0x401940
    virtual char const * Set_Name(char const * filename);      // 0x630110
    virtual int Create();
    virtual int Delete();
    virtual bool Is_Available(int forced = false);              // 0x630240
    virtual bool Is_Open() const { return Handle != -1; }       // 0x630a70
    virtual int Open(char const * filename, int rights = READ);
    virtual int Open(int rights = READ);                        // 0x6301a0
    virtual long Read(void * buffer, long size);                // 0x630330
    virtual long Seek(long pos, int dir = SEEK_CUR);            // 0x630550
    virtual long Size();                                        // 0x630720
    virtual long Write(void const * buffer, long size);         // 0x630420
    virtual void Close();                                       // 0x6302f0
    virtual unsigned long Get_Date_Time();
    virtual bool Set_Date_Time(unsigned long datetime);
    virtual void Error(int error, int canretry = false, char const * filename = NULL);

    int Rights;                 // +0x04
    long BiasStart;             // +0x08
    long BiasLength;            // +0x0c
    int Handle;                 // +0x10, -1 when closed
    char const * Filename;      // +0x14
    short Date;                 // +0x18
    short Time;                 // +0x1a
    bool Allocated;             // +0x1c
};

// ---- end of local declarations ----

class BufferIOFileClass : public RawFileClass {
public:
    enum { MINIMUM_BUFFER_SIZE = 1024 };

    BufferIOFileClass(char const * filename);
    BufferIOFileClass();
    virtual ~BufferIOFileClass();

    bool Cache(long size = 0, void * ptr = NULL);
    void Free();
    bool Commit();

    virtual char const * Set_Name(char const * filename);
    virtual bool Is_Available(int forced = false);
    virtual bool Is_Open() const;
    virtual int Open(char const * filename, int rights = READ);
    virtual int Open(int rights = READ);
    virtual long Read(void * buffer, long size);
    virtual long Seek(long pos, int dir = SEEK_CUR);
    virtual long Size();
    virtual long Write(void const * buffer, long size);
    virtual void Close();

    bool IsAllocated;           // +0x20
    bool IsOpen;                // +0x21
    bool IsDiskOpen;            // +0x22
    bool IsCached;              // +0x23
    bool IsChanged;             // +0x24
    bool UseBuffer;             // +0x25
    int BufferRights;           // +0x28
    void * Buffer;              // +0x2c
    long BufferSize;            // +0x30
    long BufferPos;             // +0x34
    long BufferFilePos;         // +0x38
    long BufferChangeBeg;       // +0x3c
    long BufferChangeEnd;       // +0x40
    long FileSize;              // +0x44
    long FilePos;               // +0x48
    long TrueFileStart;         // +0x4c
};

// 0x42f100
BufferIOFileClass::BufferIOFileClass(char const * filename) :
    IsAllocated(false),
    IsOpen(false),
    IsDiskOpen(false),
    IsCached(false),
    IsChanged(false),
    UseBuffer(false),
    BufferRights(0),
    Buffer(NULL),
    BufferSize(0),
    BufferPos(0),
    BufferFilePos(0),
    BufferChangeBeg(-1),
    BufferChangeEnd(-1),
    FileSize(0),
    FilePos(0),
    TrueFileStart(0)
{
    BufferIOFileClass::Set_Name(filename);
}

// 0x42f1f0
BufferIOFileClass::BufferIOFileClass() :
    IsAllocated(false),
    IsOpen(false),
    IsDiskOpen(false),
    IsCached(false),
    IsChanged(false),
    UseBuffer(false),
    BufferRights(0),
    Buffer(NULL),
    BufferSize(0),
    BufferPos(0),
    BufferFilePos(0),
    BufferChangeBeg(-1),
    BufferChangeEnd(-1),
    FileSize(0),
    FilePos(0),
    TrueFileStart(0)
{
}

// 0x42f250
BufferIOFileClass::~BufferIOFileClass()
{
    Free();
}

// 0x42f290: sets up the buffer (own allocation unless ptr is given) and fills it from the file.
bool BufferIOFileClass::Cache(long size, void * ptr)
{
    if (Buffer) {
        if (!size && !ptr) {
            return true;
        }
    } else {
        if (Is_Available()) {
            FileSize = Size();
        } else {
            FileSize = 0;
        }

        if (size) {
            if (size < MINIMUM_BUFFER_SIZE) {
                size = MINIMUM_BUFFER_SIZE;
                if (ptr) {
                    Error(EINVAL);
                }
            }
            BufferSize = size;
        } else {
            BufferSize = FileSize;
        }

        if ((size || !ptr) && BufferSize) {
            if (ptr) {
                Buffer = ptr;
            } else {
                Buffer = new char[BufferSize];
            }

            if (Buffer) {
                IsAllocated = true;
                IsDiskOpen = false;
                BufferPos = 0;
                BufferFilePos = 0;
                BufferChangeBeg = -1;
                BufferChangeEnd = -1;
                FilePos = 0;
                TrueFileStart = 0;

                if (FileSize) {
                    long readsize;
                    int opened = false;
                    long prevpos = 0;

                    readsize = FileSize;
                    if (FileSize > BufferSize) {
                        readsize = BufferSize;
                    }

                    if (Is_Open()) {
                        prevpos = Seek(0);
                        if (RawFileClass::Is_Open()) {
                            TrueFileStart = RawFileClass::Seek(0);
                        } else {
                            TrueFileStart = prevpos;
                        }
                        if (FileSize <= BufferSize) {
                            if (prevpos) {
                                Seek(0, SEEK_SET);
                            }
                            BufferPos = prevpos;
                            FilePos = prevpos;
                        } else {
                            BufferFilePos = prevpos;
                            FilePos = prevpos;
                        }
                    } else {
                        if (Open()) {
                            TrueFileStart = RawFileClass::Seek(0);
                            opened = true;
                        }
                    }

                    long actual = Read(Buffer, readsize);
                    if (actual != readsize) {
                        Error(EIO);
                    }

                    if (opened) {
                        Close();
                    } else {
                        Seek(prevpos, SEEK_SET);
                    }
                    IsCached = true;
                }
                UseBuffer = true;
                return true;
            }
            Error(ENOMEM);
        }
    }
    return false;
}

// 0x42f460
void BufferIOFileClass::Free()
{
    if (Buffer) {
        if (IsAllocated) {
            delete [] (char *)Buffer;
            IsAllocated = false;
        }
        Buffer = NULL;
    }
    BufferSize = 0;
    IsOpen = false;
    IsCached = false;
    IsChanged = false;
    UseBuffer = false;
}

// 0x42f4a0: writes the changed part of the buffer back to the file.
bool BufferIOFileClass::Commit()
{
    if (UseBuffer && IsChanged) {
        long size = BufferChangeEnd - BufferChangeBeg;
        if (IsDiskOpen) {
            RawFileClass::Seek(BufferFilePos + TrueFileStart + BufferChangeBeg, SEEK_SET);
            RawFileClass::Write(Buffer, size);
            RawFileClass::Seek(FilePos + TrueFileStart, SEEK_SET);
        } else {
            RawFileClass::Open(READ);
            RawFileClass::Seek(TrueFileStart + BufferFilePos + BufferChangeBeg, SEEK_SET);
            RawFileClass::Write(Buffer, size);
            RawFileClass::Close();
        }
        IsChanged = false;
        return true;
    }
    return false;
}

// 0x42f550
char const * BufferIOFileClass::Set_Name(char const * filename)
{
    if (File_Name() && UseBuffer) {
        if (strcmp(filename, File_Name()) == 0) {
            return File_Name();
        }
        Commit();
        IsCached = false;
    }
    RawFileClass::Set_Name(filename);
    return File_Name();
}

// 0x42f5e0
bool BufferIOFileClass::Is_Available(int)
{
    if (UseBuffer) {
        return true;
    }
    return RawFileClass::Is_Available();
}

// 0x42f600
bool BufferIOFileClass::Is_Open() const
{
    if (IsOpen && UseBuffer) {
        return true;
    }
    return RawFileClass::Is_Open();
}

// 0x42f620
int BufferIOFileClass::Open(char const * filename, int rights)
{
    Set_Name(filename);
    return BufferIOFileClass::Open(rights);
}

// 0x42f640
int BufferIOFileClass::Open(int rights)
{
    BufferIOFileClass::Close();

    if (UseBuffer) {
        BufferRights = rights;

        if (rights != READ || FileSize > BufferSize) {
            if (rights == WRITE) {
                RawFileClass::Open(rights);
                RawFileClass::Close();
                rights = READ | WRITE;
                TrueFileStart = 0;
            }
            if (TrueFileStart) {
                UseBuffer = false;
                Open(rights);
                UseBuffer = true;
            } else {
                RawFileClass::Open(rights);
            }
            IsDiskOpen = true;
            if (BufferRights == WRITE) {
                FileSize = 0;
            }
        } else {
            IsDiskOpen = false;
        }

        BufferPos = 0;
        BufferFilePos = 0;
        BufferChangeBeg = -1;
        BufferChangeEnd = -1;
        FilePos = 0;
        IsOpen = true;
    } else {
        RawFileClass::Open(rights);
    }
    return true;
}

// 0x42f730
long BufferIOFileClass::Write(void const * buffer, long size)
{
    int opened = false;

    if (!Is_Open()) {
        if (!Open(WRITE)) {
            return 0;
        }
        TrueFileStart = RawFileClass::Seek(0);
        opened = true;
    }

    if (UseBuffer) {
        long sizewritten = 0;

        if (BufferRights != READ) {
            while (size) {
                long sizetowrite = BufferSize - BufferPos;
                if (size < sizetowrite) {
                    sizetowrite = size;
                }

                if (sizetowrite != BufferSize) {
                    if (!IsCached) {
                        long readsize;
                        if (FileSize < BufferSize) {
                            readsize = FileSize;
                            BufferFilePos = 0;
                        } else {
                            readsize = BufferSize;
                            BufferFilePos = FilePos;
                        }

                        if (TrueFileStart) {
                            UseBuffer = false;
                            Seek(FilePos, SEEK_SET);
                            Read(Buffer, BufferSize);
                            Seek(FilePos, SEEK_SET);
                            UseBuffer = true;
                        } else {
                            RawFileClass::Seek(BufferFilePos, SEEK_SET);
                            RawFileClass::Read(Buffer, readsize);
                        }

                        BufferPos = 0;
                        BufferChangeBeg = -1;
                        BufferChangeEnd = -1;
                        IsCached = true;
                    }
                }

                memmove((char *)Buffer + BufferPos, (char *)buffer + sizewritten, sizetowrite);
                sizewritten += sizetowrite;
                size -= sizetowrite;

                IsChanged = true;
                if (BufferChangeBeg == -1) {
                    BufferChangeBeg = BufferPos;
                    BufferChangeEnd = BufferPos;
                } else {
                    if (BufferChangeBeg > BufferPos) {
                        BufferChangeBeg = BufferPos;
                    }
                }

                BufferPos += sizetowrite;
                if (BufferChangeEnd < BufferPos) {
                    BufferChangeEnd = BufferPos;
                }

                FilePos = BufferFilePos + BufferPos;
                if (FileSize < FilePos) {
                    FileSize = FilePos;
                }

                if (BufferPos == BufferSize) {
                    Commit();
                    BufferPos = 0;
                    BufferFilePos = FilePos;
                    BufferChangeBeg = -1;
                    BufferChangeEnd = -1;

                    if (size && FileSize > FilePos) {
                        if (TrueFileStart) {
                            UseBuffer = false;
                            Seek(FilePos, SEEK_SET);
                            Read(Buffer, BufferSize);
                            Seek(FilePos, SEEK_SET);
                            UseBuffer = true;
                        } else {
                            RawFileClass::Seek(FilePos, SEEK_SET);
                            RawFileClass::Read(Buffer, BufferSize);
                        }
                    } else {
                        IsCached = false;
                    }
                }
            }
        } else {
            Error(EACCES);
        }
        size = sizewritten;
    } else {
        size = RawFileClass::Write(buffer, size);
    }

    if (opened) {
        Close();
    }
    return size;
}

// 0x42f980
long BufferIOFileClass::Read(void * buffer, long size)
{
    int opened = false;

    if (!Is_Open()) {
        if (Open(READ)) {
            TrueFileStart = RawFileClass::Seek(0);
            opened = true;
        }
    }

    if (UseBuffer) {
        long sizeread = 0;

        if (BufferRights != WRITE) {
            while (size) {
                long sizetoread = (size >= BufferSize - BufferPos) ? BufferSize - BufferPos : size;

                if (!IsCached) {
                    long readsize;
                    if (FileSize < BufferSize) {
                        readsize = FileSize;
                        BufferFilePos = 0;
                    } else {
                        readsize = BufferSize;
                        BufferFilePos = FilePos;
                    }

                    if (TrueFileStart) {
                        UseBuffer = false;
                        Seek(FilePos, SEEK_SET);
                        Read(Buffer, BufferSize);
                        Seek(FilePos, SEEK_SET);
                        UseBuffer = true;
                    } else {
                        RawFileClass::Seek(BufferFilePos, SEEK_SET);
                        RawFileClass::Read(Buffer, readsize);
                    }

                    BufferPos = 0;
                    BufferChangeBeg = -1;
                    BufferChangeEnd = -1;
                    IsCached = true;
                }

                memmove((char *)buffer + sizeread, (char *)Buffer + BufferPos, sizetoread);
                sizeread += sizetoread;
                size -= sizetoread;
                BufferPos += sizetoread;
                FilePos = BufferFilePos + BufferPos;

                if (BufferPos == BufferSize) {
                    Commit();
                    BufferPos = 0;
                    BufferFilePos = FilePos;
                    BufferChangeBeg = -1;
                    BufferChangeEnd = -1;

                    if (size && FileSize > FilePos) {
                        if (TrueFileStart) {
                            UseBuffer = false;
                            Seek(FilePos, SEEK_SET);
                            Read(Buffer, BufferSize);
                            Seek(FilePos, SEEK_SET);
                            UseBuffer = true;
                        } else {
                            RawFileClass::Seek(FilePos, SEEK_SET);
                            RawFileClass::Read(Buffer, BufferSize);
                        }
                    } else {
                        IsCached = false;
                    }
                }
            }
        } else {
            Error(EACCES);
        }
        size = sizeread;
    } else {
        size = RawFileClass::Read(buffer, size);
    }

    if (opened) {
        Close();
    }
    return size;
}

// 0x42fb90
long BufferIOFileClass::Seek(long pos, int dir)
{
    if (UseBuffer) {
        bool adjusted = false;

        switch (dir) {
            case SEEK_END:
                FilePos = FileSize;
                break;

            case SEEK_SET:
                FilePos = 0;
                break;

            default:
                break;
        }

        if (TrueFileStart) {
            if (pos >= TrueFileStart) {
                pos -= TrueFileStart;
                adjusted = true;
            }
        }

        FilePos += pos;
        if (FilePos < 0) {
            FilePos = 0;
        }
        if (FilePos > FileSize) {
            FilePos = FileSize;
        }

        if (FileSize <= BufferSize) {
            BufferPos = FilePos;
        } else {
            if (FilePos >= BufferFilePos && FilePos < (BufferFilePos + BufferSize)) {
                BufferPos = FilePos - BufferFilePos;
            } else {
                Commit();
                if (TrueFileStart) {
                    UseBuffer = false;
                    Seek(FilePos, SEEK_SET);
                    UseBuffer = true;
                } else {
                    RawFileClass::Seek(FilePos, SEEK_SET);
                }
                IsCached = false;
            }
        }

        if (TrueFileStart && adjusted) {
            return FilePos + TrueFileStart;
        }
        return FilePos;
    }
    return RawFileClass::Seek(pos, dir);
}

// 0x42fc80
long BufferIOFileClass::Size()
{
    if (IsOpen && UseBuffer) {
        return FileSize;
    }
    return RawFileClass::Size();
}

// 0x42fca0
void BufferIOFileClass::Close()
{
    if (UseBuffer) {
        Commit();
        if (IsDiskOpen) {
            if (TrueFileStart) {
                UseBuffer = false;
                Close();
                UseBuffer = true;
            } else {
                RawFileClass::Close();
            }
            IsDiskOpen = false;
        }
        IsOpen = false;
    } else {
        RawFileClass::Close();
    }
}
