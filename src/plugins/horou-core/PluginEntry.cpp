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

#include <Plugin.h>

#include <iostream>

MAKE_PLUGIN(horou_core) {
public:
    void PluginInit(http::Server* server) override {
        std::cout << "Call" << std::endl;
    }

    void PluginEntry() override {
        std::cout << "Call" << std::endl;
    }
private:
protected:
};

EXPORT_PLUGIN(horou_core);
