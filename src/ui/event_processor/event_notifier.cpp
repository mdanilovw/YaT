#include <iostream>

#include "ui/event_processor/event_notifier.h"

void EventNotifier::start(std::function<std::shared_ptr<IEvent>()> accessEvent)
{
   eventConsumerThread = std::thread 
   {
    [this, accessEvent](){consumeEvent(accessEvent);}
   };
}

void EventNotifier::consumeEvent(std::function<std::shared_ptr<IEvent>()> accessEvent)
{
    bool runNotifications = true;
    
    while(runNotifications)
    {
        auto event = accessEvent();

        std::cout << "EventNotifier: consumed event " << static_cast<int>(event->getType()) << std::endl;

        if(event->getType() == EventType::QUIT_APP)
        {
            runNotifications = false;
        }

        notifyEvent(event);
    }
}

void EventNotifier::subscribe(EventType type, std::shared_ptr<IEventListener> newListener)
{
    std::lock_guard<std::mutex> lg(listenersMutex);

    auto kv = listeners.find(type);
    if(kv != listeners.end())
    {
        auto& eventListeners = kv->second;
        auto sameEventListenerIt = std::find(eventListeners.begin(), eventListeners.end(), newListener);
        if(sameEventListenerIt == eventListeners.end())
        {
            eventListeners.push_back(newListener);
            std::cout << "EventNotifier: new listener subscribed for event [" 
                        << static_cast<int>(type) << "]" << std::endl;
        } else
        {
            std::string errorMessage = 
                "EventNotifier: double subscription of the same listener for event " 
                + std::to_string(static_cast<int>(type));
            throw errorMessage;
        }
    } else 
    {
        listeners[type] = {newListener};
        std::cout << "EventNotifier: new listener subscribed for event [" 
                        << static_cast<int>(type) << "]" << std::endl;
    }
}

void EventNotifier::unsubscribe(EventType type, std::shared_ptr<IEventListener> listener)
{
    std::lock_guard<std::mutex> lg(listenersMutex);

    auto kv = listeners.find(type);
    if(kv != listeners.end())
    {
        auto& eventListeners = kv->second;
        eventListeners.remove(listener);
        std::cout << "EventNotifier: listener unsubscribed from event ["
                    << static_cast<int>(type) << "]" << std::endl;
    }
}

void EventNotifier::notifyEvent(std::shared_ptr<IEvent> event)
{
    std::cout << "EventNotifier: notifying listeners of event ["
                << std::to_string(static_cast<int>(event->getType())) << "]" << std::endl;

    std::list<std::shared_ptr<IEventListener>> eventListeners;
    {
        std::lock_guard<std::mutex> lg(listenersMutex);
        
        auto kv = listeners.find(event->getType());
        if(kv != listeners.end())
        {
            eventListeners = kv->second;
        }
    }

    for(auto listener: eventListeners)
    {
        listener->onEvent(event);
    }
}

EventNotifier::~EventNotifier()
{
    std::cout << "EventNotifier: joining event consumer thread" << std::endl;
    eventConsumerThread.join();
}