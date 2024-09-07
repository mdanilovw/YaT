#include <iostream>

#include <SDL2/SDL_image.h>

#include "ui/image.h"

void runGame() 
{
    SDL_Window* window = SDL_CreateWindow("YaT", 30, 30, 540, 804, SDL_WINDOW_SHOWN);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    
    Image fieldImage{"res/Field.png"};
    Image berryImage{"res/BlueBerry.png"};
    
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

        SDL_Rect postition;
        postition.x = 0;
        postition.y = 0;
        fieldImage.draw(surface, postition);
        berryImage.draw(surface, postition);

        SDL_UpdateWindowSurface(window);
    }
    

    SDL_DestroyWindow(window);
}

int main(int argc, char** argv) 
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    runGame();
  
    SDL_Quit();
    IMG_Quit();

    return 0;
}
