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
#include <boost/asio.hpp>

#include <io/network/http/Server.h>

#include "handlers/bancho/HTTPHandler.h"
#include "managers/PluginManager.h"


using namespace boost;

int main() {
    asio::io_service IO_Service;
    http::Server server(IO_Service, "0.0.0.0", 1341);


    PluginManager pl_mng("plugins");
    pl_mng.LoadAll(&server);

    server.RegisterHandler("/", HTTPHandler);

    pl_mng.ExecuteAll();

    server.Start();
    
    pl_mng.UnloadAll();
    return 0;
}
