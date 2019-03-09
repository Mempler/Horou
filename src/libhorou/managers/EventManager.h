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

#ifndef HOROU_EVENTMANAGER_H
#define HOROU_EVENTMANAGER_H

#include <unordered_map>
#include <vector>

#define REGISTER_EVENT(EventId, EventFunction) g_EventManager.RegisterEvent(EventId, EventFunction)

#define EID_PACKET_MANAGER 0x88FF1145


struct EventArgs {

};

typedef bool (*EventFunc)(EventArgs* args);

class EventManager {
public:
    void CollectGarbage();

    void RegisterEvent(int Id, EventFunc func);
    void RunEvent(int Id, EventArgs* args);

private:
    std::unordered_map<int, std::vector<EventFunc>> events;
};

extern EventManager g_EventManager;

#endif //HOROU_EVENTMANAGER_H
