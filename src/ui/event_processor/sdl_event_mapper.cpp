#include "ui/event_processor/sdl_event_mapper.h"
#include "ui/event_processor/event.h"

SdlEventMapper::SdlEventMapper()
{
    eventMap[SDL_QUIT] = EventType::QUIT_APP;
}

std::shared_ptr<IEvent> SdlEventMapper::mapEvent(SDL_EventType sdlEventType)
{
    EventType eventType{EventType::UNKNOWN};
    auto eventEntry = eventMap.find(sdlEventType);
    
    if(eventEntry != eventMap.end())
    {
        eventType = eventEntry->second;
    }

    // TODO: add event meta when available and needed
    return std::make_shared<Event>(eventType);
}