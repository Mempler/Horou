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

#include "TextBuffer.h"

#include "../../utils/StringUtils.h"

std::string TextBuffer::ReadLine() {
    std::string str;
    uint8_t byte;

    while(true)
        if ((byte = this->ReadByte()) != '\n')
            str += byte;
        else
            break;

    if (Utils::EndsWith(str, "\r"))
        str.pop_back();

    return str;
}

void TextBuffer::WriteLine(std::string str) {
    for (char c : str)
        this->WriteByte((uint8_t) c);
    this->WriteByte((uint8_t) '\n');
}

std::string TextBuffer::ReadToEnd() {
    std::string str;

    while(true)
        if (this->mReaded != this->mWritten + 1)
            str += this->ReadByte();
        else
            break;

    return str;
}
