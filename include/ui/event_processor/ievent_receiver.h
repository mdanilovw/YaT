#ifndef __IEVENT_RECEIVER_H__
#define __IEVENT_RECEIVER_H__

#include <SDL2/SDL.h>

#include <functional>

class IEventReceiver
{
    public:
    virtual void start(std::function<void(SDL_EventType)> storeEvent) = 0;
    virtual ~IEventReceiver() = default;
};

#endif