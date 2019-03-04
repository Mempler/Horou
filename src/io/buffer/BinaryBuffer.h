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

#ifndef HOROU_BINARYBUFFER_H
#define HOROU_BINARYBUFFER_H

#include <string>
#include <cstring>

#include "Buffer.h"

class BinaryBuffer : public Buffer {
public:
    template <typename T>
    void Write(T v) {
        this->Allocate(sizeof(T));
        std::memcpy(this->mData.data() + this->mWritten, &v, sizeof(T));
        this->mWritten += sizeof(T);
    }

    template <typename T>
    T Read() {
        T v;
        std::memcpy(&v, this->mData.data() + this->mWritten, sizeof(T));
        this->mReaded += sizeof(T);
    }

    void Write(std::string val, bool nullable = true);
private:
    void WriteULEB128(size_t val);
    size_t ReadULEB128();

};

#endif //HOROU_BINARYBUFFER_H
