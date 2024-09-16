#include <iostream>
#include <memory>

#include <SDL2/SDL_image.h>

#include "ui/image.h"
#include "ui/drawer.h"
#include "ui/uiobject.h"

void runGame() 
{
    SDL_Window* window = SDL_CreateWindow("YaT", 30, 30, 540, 804, SDL_WINDOW_SHOWN);
    
    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == nullptr)
    {
        std::string errorMessage{"Unable to create a renderer\n"};
        throw errorMessage;
    }

    Drawer drawer{*renderer};
    
    auto fieldImage = std::make_unique<Image>("res/Field.png", *renderer);
    auto berryImage = std::make_unique<Image>("res/BlueBerry.png", *renderer);

    UIOjbect field{std::move(fieldImage), {0, 0, 540, 804}, {}, 0};
    UIOjbect berry{std::move(berryImage), {50, 50, 100, 100}, {}, 0};
    
    bool run{true};
    while (run)
    {
        SDL_Event sdlEvent;
        while(SDL_PollEvent(&sdlEvent))
        {
            switch (sdlEvent.type)
            {
            case SDL_QUIT:
                run = false;
                break;
            
            default:
                break;
            }
        }

        drawer.draw(field);

        berry.getRotationCenter().x = berry.getRect().w/2;
        berry.getRotationCenter().y = berry.getRect().h/2;
        berry.getRotationCenter().x += berry.getRect().x;
        berry.getRotationCenter().y += berry.getRect().y;
        
        drawer.draw(berry);
        
        SDL_RenderPresent(renderer);

        berry.getRect().w++;
        berry.getRect().h++;
        berry.getAngle()++;
        
        SDL_Delay(10);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int main(int argc, char** argv) 
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    try
    {
        runGame();
    } catch(const std::string& errorMessage)
    {
        std::cerr << errorMessage;
    }
    
    SDL_Quit();
    IMG_Quit();

    return 0;
}
