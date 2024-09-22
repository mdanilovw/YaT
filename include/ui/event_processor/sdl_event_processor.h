#ifndef __SDL_EVENT_PROCESSOR_H__
#define __SDL_EVENT_PROCESSOR_H__

#include <condition_variable>
#include <mutex>
#include <queue>

#include "ui/event_processor/ievent_mapper.h"
#include "ui/event_processor/ievent_notifier.h"
#include "ui/event_processor/ievent_processor.h"
#include "ui/event_processor/ievent_receiver.h"
#include "ui/event_processor/ievent.h"

class SdlEventProcessor: public IEventProcessor
{
    public:
    SdlEventProcessor(IEventReceiver&, IEventMapper&, IEventNotifier&);

    void subscribe(EventType, std::shared_ptr<IEventListener>) override;
    void unsubscribe(EventType, std::shared_ptr<IEventListener>) override;
    void start() override;

    private:
    IEventReceiver& sdlEventReceiver;
    IEventMapper& sdlEventMapper;
    IEventNotifier& eventNotifier;

    std::queue<std::shared_ptr<IEvent>> eventQueue;
    std::mutex eventQueueMutex;
    std::condition_variable cv;

    void putEventIntoQueue(SDL_EventType);
    std::shared_ptr<IEvent> removeEventFromQueue();
};

#endif