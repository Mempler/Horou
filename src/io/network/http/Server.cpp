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

#include "Server.h"

#include <thread>
#include <iostream>

#include "Request.h"
#include "Response.h"

using namespace boost;

namespace http {
    Server::Server(asio::io_service& service,
                   std::string hostname,
                   uint16_t port) : mService(service) {

        asio::ip::tcp::resolver resolver(this->mService);
        asio::ip::tcp::resolver::query query(hostname, std::to_string(port));
        asio::ip::tcp::resolver::iterator iter = resolver.resolve(query);

        this->mEndPoint = iter->endpoint();
    }

    void Server::Start() {
        asio::ip::tcp::acceptor a(this->mService, this->mEndPoint);
        for (;;)
        {
            asio::ip::tcp::socket sock(this->mService);
            a.accept(sock);
            Server::HandleClient(&this->mHandlers, std::move(sock));
        }
    }

    void Server::RegisterHandler(std::string path, http_requesthandler h) { this->mHandlers[path] = h; }

    void Server::HandleClient(boost::unordered_map<std::string, http_requesthandler>* handlers, boost::asio::ip::tcp::socket sock) {
        Request req(&sock);
        Response res(&sock);

        boost::unordered_map<std::string, http_requesthandler>::iterator it = handlers->find(req.GetPath());
        if(it != handlers->end())
            it->second(req, res);
    }
}