#include <iostream>

#include "ui/event_processor/sdl_event_receiver.h"

SdlEventReceiver::SdlEventReceiver(): sdlEventCheckingDelay{30}
{}

void SdlEventReceiver::start(std::function<void(SDL_EventType)> storeEvent)
{
    eventProducerThread = std::thread
    {
        [this, storeEvent](){receiveSdlEvents(storeEvent);}
    };
}

SdlEventReceiver::~SdlEventReceiver()
{
    std::cout << "SdlEventReceiver: joining event producer thread" << std::endl;
    eventProducerThread.join();
}

void SdlEventReceiver::receiveSdlEvents(std::function<void(SDL_EventType)> storeEvent)
{
    SDL_Event sdlEvent;
    bool runEventProcessing{true};
    
    while(runEventProcessing)
    {
        while(SDL_PollEvent(&sdlEvent))
        {   
            switch (sdlEvent.type)
            {
            case SDL_QUIT:
                std::cout << "SdlEventReceiver: received SDL_QUIT event" << std::endl;
                runEventProcessing = false; // special treatment of SDL_QUIT to prevent hang on exit
                storeEvent(SDL_QUIT);
                break;
            
            default:
                std::cout << "SdlEventReceiver: received unknown SDL event " << sdlEvent.type << std::endl;
                break;
            }
        }

        SDL_Delay(sdlEventCheckingDelay);
    }
}