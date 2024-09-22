#include <iostream>
#include <memory>
#include <thread>

#include <SDL2/SDL_image.h>

#include "ui/image.h"
#include "ui/drawer.h"
#include "ui/uiobject.h"
#include "ui/event_processor/sdl_event_processor.h"
#include "ui/event_processor/sdl_event_receiver.h"
#include "ui/event_processor/sdl_event_mapper.h"
#include "ui/event_processor/event_notifier.h"
#include "ui/event_processor/quit_event_listener.h"

void runGame(SDL_Renderer* renderer) 
{
    Drawer drawer{*renderer};
    
    auto fieldImage = std::make_unique<Image>("res/Field.png", *renderer);
    auto berryImage = std::make_unique<Image>("res/BlueBerry.png", *renderer);

    UIOjbect field{std::move(fieldImage), {0, 0, 540, 804}, {}, 0};
    UIOjbect berry{std::move(berryImage), {50, 50, 100, 100}, {}, 0};

    SdlEventReceiver eventReceiver;
    SdlEventMapper eventMapper;
    EventNotifier eventNotifier;
    SdlEventProcessor eventProcessor{eventReceiver, eventMapper, eventNotifier};
    
    auto quitListener = std::make_shared<QuitEventListener>();
    eventProcessor.subscribe(EventType::QUIT_APP, quitListener);

    eventProcessor.start();

    drawer.draw(field);
    drawer.draw(berry);
    
    SDL_RenderPresent(renderer);

    quitListener->waitQuit();
}

int main(int argc, char** argv) 
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("YaT", 30, 30, 540, 804, SDL_WINDOW_SHOWN);
    
    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == nullptr)
    {
        std::string errorMessage{"Unable to create a renderer\n"};
        throw errorMessage;
    }

    try
    {
        runGame(renderer);
    } catch(const std::string& errorMessage)
    {
        std::cerr << errorMessage;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    IMG_Quit();

    return 0;
}
