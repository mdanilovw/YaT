#ifndef __IDRAWER_H__
#define __IDRAWER_H__

#include <SDL2/SDL.h>

#include "ui/idrawable.h"

class IDrawer
{
    public:
    virtual void draw(IDrawable&, const SDL_Rect& destArea) const = 0;
    virtual void draw(IDrawable&, const SDL_Rect& destArea,
                        double angle, SDL_Point& rotationPoint) const = 0;
    virtual ~IDrawer() = default;

    protected:
    IDrawer() = default;
};

#endif