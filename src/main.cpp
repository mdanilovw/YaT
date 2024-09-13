#include <iostream>

#include <SDL2/SDL_image.h>

#include "ui/image.h"
#include "ui/drawer.h"

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
    
    Image fieldImage{"res/Field.png", *renderer};
    Image berryImage{"res/BlueBerry.png", *renderer};

    SDL_Rect fieldPostition;
    fieldPostition.x = 0;
    fieldPostition.y = 0;
    fieldPostition.h = 804;
    fieldPostition.w = 540;

    SDL_Rect berryPostition;
    berryPostition.x = 50;
    berryPostition.y = 50;
    berryPostition.h = 100;
    berryPostition.w = 100;
    double berryAngle{0};
    
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

        drawer.draw(fieldImage, fieldPostition);

        SDL_Point berryRotationPoint;
        berryRotationPoint.x = berryPostition.w/2;
        berryRotationPoint.y = berryPostition.h/2;
        berryRotationPoint.x += berryPostition.x;
        berryRotationPoint.y += berryPostition.y;
        
        drawer.draw(berryImage, berryPostition, berryAngle, berryRotationPoint);
        
        SDL_RenderPresent(renderer);
        berryAngle++;
        berryPostition.w++;
        berryPostition.h++;

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
