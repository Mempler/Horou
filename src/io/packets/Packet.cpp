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

#include <iostream>
#include "Packet.h"


void Packets::Packet::WriteBytes(Buffer* buff) {
    auto b = (BinaryBuffer*) buff;

    b->Write(this->mId);
    b->Write((uint8_t) 0x00);
    b->Write((int32_t) this->GetBuffer()->Size());
    b->Append(this->GetBuffer());
}

void Packets::Packet::DumpToLog() {
    std::cout << "PacketId: " << std::hex << (int32_t) this->GetPacketId() << std::endl;

    std::cout << "Size: " << std::to_string(this->mBuffer.Size()) << std::endl;
    std::cout << "PacketData: [ ";

    const char* b = this->mBuffer.GetBytes();
    size_t bs = this->mBuffer.Size();

    for (int i = 0; i < bs -1; ++i)
        std::cout << std::to_string(b[i]) << ", ";

    std::cout << (int32_t) b[bs] << " ]" << std::endl << std::flush;
}
