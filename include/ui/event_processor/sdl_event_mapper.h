#ifndef __EVENT_MAPPER_H__
#define __EVENT_MAPPER_H__

#include <map>

#include "ui/event_processor/ievent_mapper.h"

class SdlEventMapper: public IEventMapper
{
    public:
    SdlEventMapper();
    std::shared_ptr<IEvent> mapEvent(SDL_EventType) override;

    private:
    std::map<SDL_EventType, EventType> eventMap;
};

#endif