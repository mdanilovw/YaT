#include "ui/drawer.h"

Drawer::Drawer(SDL_Renderer& renderer): renderer{renderer}
{}

void Drawer::draw(IUIObject& uiObject)
{
    SDL_RenderCopyEx(&renderer, &(uiObject.getIDrawable().getTexture()), 
                    NULL, &uiObject.getRect(), uiObject.getAngle(),
                    &uiObject.getRotationCenter(), SDL_FLIP_NONE);   
}