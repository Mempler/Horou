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

#ifndef HOROU_LOGINRESPONSE_H
#define HOROU_LOGINRESPONSE_H

#include "../Packet.h"

namespace Packets {
    enum LoginResponses : int32_t {
        Failed = -1,
        Outdated = -2,
        Banned = -3,
        MultiAcc = -4,
        Exception = -5,
        SupporterOnly = -6,
        PasswordReset = -7,
        TwoFactorAuth = -8
    };

    class LoginResponse : public Packet {

    public:
        LoginResponse(LoginResponses response);
        LoginResponse(int32_t response);
        LoginResponse(uint32_t response);

    };
}

#endif //HOROU_LOGINRESPONSE_H
