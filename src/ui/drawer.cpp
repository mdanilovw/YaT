#include "ui/drawer.h"

Drawer::Drawer(SDL_Renderer& renderer): renderer{renderer}
{}

void Drawer::draw(IDrawable& image, const SDL_Rect& destArea) const
{
    SDL_RenderCopy(&renderer, &(image.getTexture()), NULL, &destArea);   
}

void Drawer::draw(IDrawable& image, const SDL_Rect& destArea,
                    double angle, SDL_Point& rotationPoint) const
{
    SDL_RenderCopyEx(&renderer, &(image.getTexture()), NULL, &destArea,
                        angle, &rotationPoint, SDL_FLIP_NONE);   
}