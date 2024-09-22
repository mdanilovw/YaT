#ifndef __IEVENT_LISTENER__H__
#define __IEVENT_LISTENER__H__

#include <memory>

#include "ui/event_processor/ievent.h"

class IEventListener 
{
    public:
    virtual void onEvent(const std::shared_ptr<IEvent>) = 0;

    virtual ~IEventListener() = default;
};

#endif