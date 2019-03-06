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

#ifndef HOROU_REQUEST_H
#define HOROU_REQUEST_H

#include <boost/asio.hpp>

#include <vector>
#include <unordered_map>

#include "Method.h"
#include "../../buffer/TextBuffer.h"

namespace http {
    class Request {
    public:
        explicit Request(boost::asio::ip::tcp::socket* sock);

        const Method& GetMethod() { return this->mMethod; };
        const std::string& GetPath() { return this->mPath; };
        const std::unordered_map<std::string, std::string>& GetHeaders() { return this->mHeaders; }
        const Buffer& GetBody() { return this->mBuffer; }
    private:
        Method mMethod = Method::GET;
        std::string mPath = "/";

        Buffer mBuffer;
        std::unordered_map<std::string, std::string> mHeaders;
    };
}


#endif //HOROU_REQUEST_H
