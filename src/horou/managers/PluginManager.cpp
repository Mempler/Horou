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

#include "PluginManager.h"

#include <dlfcn.h>
#include <sys/stat.h>
#include <dirent.h>
#include <cstring>

PluginManager::PluginManager(std::string plugin_path) {
    mkdir(plugin_path.c_str(), 0777);
    this->plugin_path = std::move(plugin_path);
}

Plugin* PluginManager::Load(std::string name) {
    if (this->plugins[name].second != nullptr)
        throw std::runtime_error("NativePlugin " + name + " has already Loaded!");
    void* shared_object = dlopen((this->plugin_path + "/" + name).c_str(), RTLD_LAZY);

    Plugin* p = ((Plugin* (*)()) dlsym(shared_object, "get_plugin"))();
    if (p == nullptr)
        throw std::logic_error("P IS NULL! This will cause an ServerCrash!");

    return (this->plugins[name] = std::make_pair(p, shared_object)).first;
}

void PluginManager::Unload(std::string name) {
    if (this->plugins[name].second != nullptr)
        dlclose(this->plugins[name].second);
}

void PluginManager::LoadAll(http::Server* server) {
    auto dir = opendir(this->plugin_path.c_str());
    if(dir == nullptr)
        throw std::runtime_error("Could not open Directory " + plugin_path);

    dirent* entity = nullptr;

    do {
        if (entity == nullptr) continue;
        if (std::string(entity->d_name) == ".") continue;
        if (std::string(entity->d_name) == "..") continue;

        Plugin* p = this->Load(entity->d_name);
        p->PluginInit(server);
    } while ((entity = readdir(dir)) != nullptr);

    closedir(dir);
}

void PluginManager::UnloadAll() {
    for(const auto& x : this->plugins)
        this->Unload(x.first);
}

void PluginManager::ExecuteAll() {
    for(const auto& x : this->plugins)
        x.second.first->PluginEntry();
}
