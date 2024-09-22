#ifndef __IEVENT_MAPPER_H__
#define __IEVENT_MAPPER_H__

#include <memory>

#include <SDL2/SDL.h>

#include "ui/event_processor/ievent.h"

class IEventMapper
{
    public:
    virtual std::shared_ptr<IEvent> mapEvent(SDL_EventType) = 0;

    virtual ~IEventMapper() = default;
};

#endif