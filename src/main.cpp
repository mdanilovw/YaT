#include <iostream>

#include <SDL2/SDL_image.h>

#include "ui/image.h"

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
    
    Image fieldImage{"res/Field.png", *renderer};
    Image berryImage{"res/BlueBerry.png", *renderer};
    
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

        SDL_Rect fieldPostition;
        fieldPostition.x = 0;
        fieldPostition.y = 0;
        fieldPostition.h = 804;
        fieldPostition.w = 540;
        fieldImage.draw(fieldPostition);

        SDL_Rect berryPostition;
        berryPostition.x = 50;
        berryPostition.y = 50;
        berryPostition.h = 100;
        berryPostition.w = 100;
        berryImage.draw(berryPostition);

        SDL_RenderPresent(renderer);
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
