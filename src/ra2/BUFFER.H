#pragma once
// Memory buffer owned by BSurface (+0x14; 12 bytes). Out-of-line methods: ctor 0x438140, dtor 0x438290.
// level-2 1.001: named Buffer as in buff.cpp (dtor 0x438290). BufferClass is the other class at 0x438360 (P9 link check).
class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);
    ~Buffer();
    void * Get_Buffer() const { return BufferPtr; }

    void * BufferPtr;
    long Size;
    bool IsAllocated;
};
