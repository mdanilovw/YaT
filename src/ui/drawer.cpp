#include "ui/drawer.h"

Drawer::Drawer(SDL_Renderer& renderer): renderer{renderer}
{}

void Drawer::draw(IDrawable& image, const SDL_Rect& destArea) const
{
    SDL_RenderCopy(&renderer, &(image.getTexture()), NULL, &destArea);
}