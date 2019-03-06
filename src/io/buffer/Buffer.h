/*
Copyright (c) 2019 Robin A. P.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
*/

#ifndef HOROU_BUFFER_H
#define HOROU_BUFFER_H

#include <vector>
#include <cstdint>

class Buffer {
public:
    Buffer() = default;
    Buffer(char* buff, size_t len);
    Buffer(Buffer* buff);

    uint8_t ReadByte(bool seek = true);
    void WriteByte(uint8_t b);
    void Allocate(size_t size);

    void Append(char* buff, size_t len);
    void Append(Buffer* buff);

    const char* GetBytes();
    size_t Size();

    void DumpToLog();

protected:
    size_t mWritten = 0;
    size_t mReaded  = 0;

    std::vector<uint8_t> mData;
};

#endif //HOROU_BUFFER_H
