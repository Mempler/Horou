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

#ifndef HOROU_PLUGIN_H
#define HOROU_PLUGIN_H

#define __PUBLIC extern "C"

#define MAKE_PLUGIN(class_name) __PUBLIC class class_name : public Plugin

#define EXPORT_PLUGIN(class_name) class_name g_Plugin;  \
                                  __PUBLIC Plugin* get_plugin() { return &g_Plugin; }

#include "io/network/http/Server.h"

__PUBLIC class Plugin {
public:
    virtual void PluginInit(http::Server* server)  { } // First PluginInit will be called
    virtual void PluginEntry() { } // After PluginInit, PluginEntry will be called.
private:
protected:
};


#endif //HOROU_PLUGIN_H
