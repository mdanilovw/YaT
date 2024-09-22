#ifndef __IEVENT_PROCESSOR_H__
#define __IEVENT_PROCESSOR_H__

#include <SDL2/SDL.h>

#include "ui/event_processor/event_type.h"
#include "ui/event_processor/ievent_listener.h"

class IEventProcessor
{
    public:
    virtual void subscribe(EventType, std::shared_ptr<IEventListener>) = 0;
    virtual void unsubscribe(EventType, std::shared_ptr<IEventListener>) = 0;
    virtual void start() = 0;

    virtual ~IEventProcessor() = default;
};

#endif