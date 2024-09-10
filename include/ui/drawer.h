#ifndef __DRAWER_H__
#define __DRAWER_H__

#include "ui/idrawer.h"

class Drawer : public IDrawer
{
    public:
    Drawer(SDL_Renderer&);
    void draw(IDrawable&, const SDL_Rect& destArea) const override;

    private:
    SDL_Renderer& renderer;
};

#endif