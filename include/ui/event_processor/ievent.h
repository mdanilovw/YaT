#ifndef __IEVENT_H__
#define __IEVENT_H__

#include "ui/event_processor/event_type.h"

class IEvent
{
    public:
    virtual EventType getType() const = 0;
    
    virtual ~IEvent() = default;
};

#endif