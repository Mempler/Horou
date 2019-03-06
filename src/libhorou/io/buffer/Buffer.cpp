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

#include "Buffer.h"

#include <iostream>

Buffer::Buffer(char* buff, size_t len) { this->Append(buff, len); }

Buffer::Buffer(Buffer* buff) { this->Append(buff); }

uint8_t Buffer::ReadByte(bool seek) {
    uint8_t byte = this->mData[this->mReaded];

    if (seek)
        this->mReaded++;

    return byte;
}

void Buffer::WriteByte(uint8_t b) {
    this->Allocate(1);
    this->mData[this->mWritten++] = b;
}

void Buffer::Allocate(size_t size) { this->mData.resize(this->mWritten + size); }

void Buffer::Append(char* buff, size_t len) {
    for (size_t i = 0; i < len; ++i)
        this->WriteByte((uint8_t) buff[i]);
}

void Buffer::Append(Buffer* buff) {
    for (uint8_t b : buff->mData)
        this->WriteByte(b);
}

const char* Buffer::GetBytes() { return (const char*) this->mData.data(); }

size_t Buffer::Size() { return this->mData.size(); }

void Buffer::DumpToLog() {
    std::cout << "Size: " << std::to_string(this->Size()) << std::endl;
    std::cout << "Buffer: [ ";

    const char* b = this->GetBytes();
    size_t bs = this->Size();

    for (int i = 0; i < bs -1; ++i)
        std::cout << std::to_string(b[i]) << ", ";

    std::cout << (int32_t) b[bs] << " ]" << std::endl << std::flush;
}

