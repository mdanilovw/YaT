#ifndef __EVENT_H__
#define __EVENT_H__

#include "ui/event_processor/ievent.h"
#include "ui/event_processor/event_type.h"

class Event: public IEvent
{
    public:
    Event(EventType);

    EventType getType() const override;

    private:
    EventType type;
};

#endif