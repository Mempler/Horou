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

#include "Response.h"
#include "../../buffer/TextBuffer.h"

namespace http {
    std::string GetStatusString(int number) {
        switch (number) {
            case 100: return "Continue";
            case 101: return "Switching Protocols";
            case 200: return "OK";
            case 201: return "Created";
            case 202: return "Accepted";
            case 203: return "Non-Authoritative Information";
            case 204: return "No Content";
            case 205: return "Reset Content";
            case 206: return "Partial Content";
            case 300: return "Multiple Choices";
            case 301: return "Moved Permanently";
            case 302: return "Found";
            case 303: return "See Other";
            case 304: return "Not Modified";
            case 305: return "Use Proxy";
            case 307: return "Temporary Redirect";
            case 400: return "Bad Request";
            case 401: return "Unauthorized";
            case 402: return "Payment Required";
            case 403: return "Forbidden";
            case 404: return "Not Found";
            case 405: return "Method Not Allowed";
            case 406: return "Not Acceptable";
            case 407: return "Proxy Authentication Required";
            case 408: return "Request Time-out";
            case 409: return "Conflict";
            case 410: return "Gone";
            case 411: return "Length Required";
            case 412: return "Precondition Failed";
            case 413: return "Request Entity Too Large";
            case 414: return "Request-URI Too Large";
            case 415: return "Unsupported Media Type";
            case 416: return "Requested range not satisfiable";
            case 417: return "Expectation Failed";
            case 500: return "Internal Server Error";
            case 501: return "Not Implemented";
            case 502: return "Bad Gateway";
            case 503: return "Service Unavailable";
            case 504: return "Gateway Time-out";
            case 505: return "HTTP Version not supported";
            default: return "OK";
        }
    }

    Response::Response(boost::asio::ip::tcp::socket* sock) {
        this->mSocket       = sock;
        this->mStatusNumber = 200;
        this->mStatusText   = GetStatusString(200);
        this->SetContentType("text/html");
    }

    void Response::SetStatus(int number) { this->mStatusNumber = number; this->mStatusText = GetStatusString(number); }

    void Response::SetStatus(int number, std::string status) { this->mStatusNumber = number; this->mStatusText = std::move(status); }

    void Response::SetHeader(std::string key, std::string value) { this->mHeaders[std::move(key)] = std::move(value); }

    void Response::SetContentType(std::string type) { this->mContentType = std::move(type); }

    void Response::Write(Buffer* buff) { this->mBuffer.Append(buff); }

    void Response::Close() {
        TextBuffer buff;
        buff.WriteLine("HTTP/1.0 " + std::to_string(this->mStatusNumber) + " " + this->mStatusText);
        auto it = this->mHeaders.begin();

        buff.WriteLine("Cache-Control: no-cache");

        buff.WriteLine("Server: Horou");

        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];

        time (&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
        std::string str(buffer);

        buff.WriteLine("Date: " + str);
        buff.WriteLine("Connection: close");

        while(it != this->mHeaders.end())
        {
            buff.WriteLine(it->first + ": " + it->second);
            it++;
        }

        buff.WriteLine("Content-Type: " + this->mContentType);
        buff.WriteLine("Content-Length: " + std::to_string(this->mBuffer.Size() - 1));

        buff.WriteLine("");

        buff.Append(&this->mBuffer);
        const char* data = buff.GetBytes();
        size_t len = buff.Size();

        this->mSocket->write_some(boost::asio::buffer(data, len));
        this->mSocket->close();
    }
}
