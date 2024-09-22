#ifndef __SDL_EVENT_RECEIVER_H__
#define __SDL_EVENT_RECEIVER_H__

#include <thread>

#include "ui/event_processor/ievent_listener.h"
#include "ui/event_processor/ievent_receiver.h"

class SdlEventReceiver: public IEventReceiver
{
    public:
    SdlEventReceiver();
    void start(std::function<void(SDL_EventType)> storeEvent) override;
    ~SdlEventReceiver();

    private:
    std::thread eventProducerThread;
    const int sdlEventCheckingDelay;

    void receiveSdlEvents(std::function<void(SDL_EventType)> storeEvent);
};

#endif