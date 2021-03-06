#include <utility>

#include <utility>

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

#ifndef HOROU_PACKETMANAGERARGS_H
#define HOROU_PACKETMANAGERARGS_H

#include <managers/EventManager.h>
#include <io/packets/PacketId.h>
#include <io/buffer/BinaryBuffer.h>
#include <objects/Presence.h>

struct PacketManagerArgs : public EventArgs {
    PacketManagerArgs(const Presence &Presence, const Packets::PacketId& PacketId, BinaryBuffer Data)
            : Presence(Presence), Data(std::move(Data)), PacketId(PacketId) {}

    Packets::PacketId PacketId;
    BinaryBuffer Data;
    Presence Presence;
};

#endif //HOROU_PACKETMANAGERARGS_H
