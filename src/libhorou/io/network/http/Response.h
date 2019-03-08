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

#ifndef HOROU_RESPONSE_H
#define HOROU_RESPONSE_H

#include <boost/asio.hpp>

#include <unordered_map>
#include "../../buffer/Buffer.h"

namespace http {
    class Response {
    public:
        explicit Response(boost::asio::ip::tcp::socket* sock);

        void SetStatus(int number);
        void SetStatus(int number, std::string status);
        void SetHeader(std::string key, std::string value);
        void SetContentType(std::string type);

        void Write(Buffer* buff);
        void Close();

        Buffer* GetBuffer() { return &this->mBuffer; }
    private:
        int mStatusNumber;
        std::string mStatusText;
        std::string mContentType;

        Buffer mBuffer;

        boost::asio::ip::tcp::socket* mSocket;

        std::unordered_map<std::string, std::string> mHeaders;
    };
}

#endif //HOROU_RESPONSE_H
