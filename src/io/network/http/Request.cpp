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

#include "Request.h"

#include <iostream>

#include "../../../utils/StringUtils.h"

namespace http {
    Request::Request(boost::asio::ip::tcp::socket* sock) {
        TextBuffer buff;
        char data[4096*16];

        bool IsHeader = false;

        boost::system::error_code error;
        size_t length = sock->read_some(boost::asio::buffer(data), error);

        if (error == boost::asio::error::eof)
            return;
        else if (error)
            throw boost::system::system_error(error);

        buff.Append(data, length);

        std::string RequestLine = buff.ReadLine();

        auto x = Utils::Split(RequestLine, " ", true);

        if (x[0] == "GET")
            this->mMethod = Method::GET;
        else if(x[0] == "POST")
            this->mMethod = Method::POST;
        else if(x[0] == "PUT")
            this->mMethod = Method::PUT;
        else if(x[0] == "DELETE")
            this->mMethod = Method::DELETE;
        this->mPath = x[1];

        std::string HTTPVersion = x[2];

        for(;;) {
            std::string line = buff.ReadLine();
            if (line.empty()) break;

            auto SplittedHeader = Utils::Split(line, ":", true);

            this->mHeaders[std::move(SplittedHeader[0])] = SplittedHeader[1];
        }

        if (this->mMethod == Method::GET)
            return;

        std::string s = buff.ReadToEnd();
        this->mBuffer.Append((char*) s.c_str(), s.size());
    }
}
