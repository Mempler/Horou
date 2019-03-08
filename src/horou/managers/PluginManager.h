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

#ifndef HOROU_PLUGINMANAGER_H
#define HOROU_PLUGINMANAGER_H

#include <string>
#include <unordered_map>
#include <Plugin.h>
#include <io/network/http/Server.h>

class PluginManager {
public:
    explicit PluginManager(std::string plugin_path);

    Plugin* Load(std::string name);
    void Unload(std::string name);

    void ExecuteAll();
    void LoadAll(http::Server* server);
    void UnloadAll();
private:
    std::unordered_map<std::string, std::pair<Plugin*, void*>> plugins;
    std::string plugin_path;
};

#endif //HOROU_PLUGINMANAGER_H
