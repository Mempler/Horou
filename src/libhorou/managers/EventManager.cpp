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

#include "EventManager.h"

EventManager g_EventManager;

void EventManager::CollectGarbage() {
    for (auto x : this->events) {
        std::vector<EventFunc> new_events;
        for (auto z : x.second) {
            if (z != nullptr)
                new_events.push_back(z);
        }
        x.second = new_events;
    }
}

void EventManager::RegisterEvent(int Id, EventFunc func) {
    this->events[Id].push_back(func);
}

void EventManager::RunEvent(int Id, EventArgs* args) {
    for (auto ev : this->events[Id])
        if (ev(args)) break;
}
