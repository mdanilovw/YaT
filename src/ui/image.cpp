#include <SDL2/SDL_image.h>

#include "ui/image.h"


Image::Image(const std::string& filePath)
{
    imageSufrace = IMG_Load(filePath.c_str());
}

Image::~Image()
{
    if(imageSufrace != nullptr)
    {
        SDL_FreeSurface(imageSufrace);
    }
}

void Image::draw(SDL_Surface* destination, SDL_Rect& position)
{
    if(imageSufrace != nullptr)
    {
        SDL_BlitSurface(imageSufrace, nullptr, destination, &position);
    }
}