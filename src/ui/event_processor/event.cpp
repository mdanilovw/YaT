#include "ui/event_processor/event.h"

Event::Event(EventType type): type{type}
{}

EventType Event::getType() const 
{
    return type;
}