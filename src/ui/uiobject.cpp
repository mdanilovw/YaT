#include "ui/uiobject.h"

UIOjbect::UIOjbect(std::unique_ptr<IDrawable>&& drawable, SDL_Rect&& rect,
                    SDL_Point&& rotationCenter, double angle):
    drawable{std::move(drawable)},
    rect{std::move(rect)},
    rotationCenter{std::move(rotationCenter)},
    angle{angle}
    {}

double& UIOjbect::getAngle()
{
    return angle;
}

IDrawable& UIOjbect::getIDrawable()
{
    return *drawable;
}

SDL_Rect& UIOjbect::getRect()
{
    return rect;
}

SDL_Point& UIOjbect::getRotationCenter()
{
    return rotationCenter;
}