#ifndef __IEVENT_NOTIFIER_H__
#define __IEVENT_NOTIFIER_H__

#include <functional>
#include <memory>

#include "ui/event_processor/ievent.h"
#include "ui/event_processor/ievent_listener.h"

class IEventNotifier
{
    public:
    virtual void start(std::function<std::shared_ptr<IEvent>()> accessEvent) = 0;
    virtual void subscribe(EventType, std::shared_ptr<IEventListener>) = 0;
    virtual void unsubscribe(EventType, std::shared_ptr<IEventListener>) = 0;
    virtual ~IEventNotifier() = default;
};

#endif