#ifndef __IDRAWABLE_H__
#define __IDRAWABLE_H__

#include <SDL2/SDL.h>

class IDrawable
{
    public:
    virtual void draw(SDL_Surface* destination, SDL_Rect& position) = 0;

    virtual ~IDrawable() = default;

    protected:
    IDrawable() = default;
};

#endif