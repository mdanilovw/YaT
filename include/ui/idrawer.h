#ifndef __IDRAWER_H__
#define __IDRAWER_H__

#include <SDL2/SDL.h>

#include "ui/iuiobject.h"

class IDrawer
{
    public:
    virtual void draw(IUIObject&) = 0;

    virtual ~IDrawer() = default;

    protected:
    IDrawer() = default;
};

#endif