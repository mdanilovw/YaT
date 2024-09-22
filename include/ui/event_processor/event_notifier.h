#ifndef __EVENT_NOTIFIER_H__
#define __EVENT_NOTIFIER_H__

#include <list>
#include <map>
#include <mutex>
#include <thread>

#include "ui/event_processor/ievent_notifier.h"

class EventNotifier: public IEventNotifier
{
    public:
    void start(std::function<std::shared_ptr<IEvent>()> accessEvent) override;
    void subscribe(EventType, std::shared_ptr<IEventListener>) override;
    void unsubscribe(EventType, std::shared_ptr<IEventListener>) override;
    ~EventNotifier();

    private:
    std::map<EventType, std::list<std::shared_ptr<IEventListener>>> listeners;
    std::mutex listenersMutex;
    
    std::thread eventConsumerThread;
    void consumeEvent(std::function<std::shared_ptr<IEvent>()> accessEvent);
    void notifyEvent(std::shared_ptr<IEvent>);
};

#endif