#include <SDL2/SDL_image.h>

#include "ui/image.h"


Image::Image(const std::string& filePath, SDL_Renderer& renderer): renderer{renderer}
{
    SDL_Surface* sufrace{nullptr};
    sufrace = IMG_Load(filePath.c_str());

    if(sufrace == nullptr)
    {
        std::string errorMessage = "Unable to create a surface for image " + filePath + "\n";
        throw errorMessage;
    }

    texture = nullptr;
    texture = SDL_CreateTextureFromSurface(&renderer, sufrace);

    SDL_FreeSurface(sufrace);

    if(texture == nullptr)
    {
        std::string errorMessage = "Unable to create a texture for image " + filePath + "\n";
        throw errorMessage;
    }
}

void Image::draw(SDL_Rect& position)
{
    SDL_RenderCopy(&renderer, texture, NULL, &position);
}

SDL_Texture& Image::getTexture() {
    return *texture;
}

Image::~Image()
{
    SDL_DestroyTexture(texture);
}