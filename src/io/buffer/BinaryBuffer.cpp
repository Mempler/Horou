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

#include "BinaryBuffer.h"

void BinaryBuffer::WriteULEB128(size_t val) {
    size_t t = 0;
    do {
        uint8_t byte;
        byte = (uint8_t) (val & 0x7F);
        val >>= 0x07;
        if (val != 0)
            byte |= 0x80;

        this->WriteByte(byte);
        t++;
    } while(val > 0);
}

size_t BinaryBuffer::ReadULEB128() {
    size_t total = 0;
    size_t shift = 0;

    while(true) {
        uint8_t byte = ReadByte();

        total |= (byte & 0x7F) << shift;

        if ((byte & 0x80) == 0)
            break;

        shift += 7;
    }

    return total;
}

void BinaryBuffer::Write(std::string val, bool nullable) {
    if (val.empty() && nullable)
        this->WriteByte(0);
    else {
        this->WriteByte(0x0b);
        this->WriteULEB128(val.size());
        for (char i : val)
            this->WriteByte((uint8_t) i);
    }
}


