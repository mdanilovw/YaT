#include "ui/event_processor/sdl_event_processor.h"

SdlEventProcessor::SdlEventProcessor(IEventReceiver& sdlEventReceiver,
                                        IEventMapper& sdlEventMapper,
                                        IEventNotifier& eventNotifier):
                                        sdlEventReceiver{sdlEventReceiver},
                                        sdlEventMapper{sdlEventMapper},
                                        eventNotifier{eventNotifier}
{}

void SdlEventProcessor::subscribe(EventType type, std::shared_ptr<IEventListener> newListener)
{
    eventNotifier.subscribe(type, newListener);
}

void SdlEventProcessor::unsubscribe(EventType type, std::shared_ptr<IEventListener> listener)
{
    eventNotifier.unsubscribe(type, listener);
}

void SdlEventProcessor::start()
{
    sdlEventReceiver.start([this](SDL_EventType event){putEventIntoQueue(event);});
    eventNotifier.start([this](){return removeEventFromQueue();});
}

void SdlEventProcessor::putEventIntoQueue(SDL_EventType event)
{
    std::lock_guard<std::mutex> lg(eventQueueMutex);
    eventQueue.push(sdlEventMapper.mapEvent(event));
    cv.notify_one();
}

std::shared_ptr<IEvent> SdlEventProcessor::removeEventFromQueue()
{
    std::unique_lock<std::mutex> lock(eventQueueMutex);
    while(eventQueue.empty())
    {
        cv.wait(lock);
    }
    
    auto event = eventQueue.front();
    eventQueue.pop();
    lock.unlock();

    return event;
}