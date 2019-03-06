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

#ifndef HOROU_SERVER_H
#define HOROU_SERVER_H

#include <boost/asio.hpp>
#include <boost/unordered_map.hpp>

#include "Request.h"
#include "Response.h"

namespace http {
    typedef void (*http_requesthandler)(Request&, Response&);

    class Server {
    public:
        explicit Server(boost::asio::io_service& service, std::string hostname, uint16_t port);

        void Start();
        void RegisterHandler(std::string path, http_requesthandler);

    private:
        boost::asio::io_service& mService;
        boost::asio::ip::tcp::endpoint mEndPoint;

        boost::unordered_map<std::string, http_requesthandler> mHandlers;

        static void HandleClient(boost::unordered_map<std::string, http_requesthandler>* handlers, boost::asio::ip::tcp::socket sock);
    };
}

#endif //HOROU_SERVER_H
