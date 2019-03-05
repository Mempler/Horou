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

#ifndef HOROU_PACKET_H
#define HOROU_PACKET_H

#include "../buffer/Buffer.h"

#include "PacketId.h"
#include "../buffer/BinaryBuffer.h"
#include "../buffer/TextBuffer.h"

namespace Packets {
    class Packet {
    public:
        PacketId GetPacketId() { return this->mId; }
        void WriteBytes(Buffer* buff);

        void DumpToLog();
    protected:
        BinaryBuffer* GetBinaryBuffer() { return (BinaryBuffer*) &this->mBuffer; }
        TextBuffer*   GetTextBuffer()   { return (TextBuffer*)   &this->mBuffer; }
        Buffer*       GetBuffer()       { return &this->mBuffer; }

        void SetPacketId(PacketId id) { this->mId = id; }
    private:
        PacketId mId;
        Buffer mBuffer;
    };
}

#endif //HOROU_PACKET_H
