#ifndef __UIOBJECT_H__
#define __UIOBJECT_H__

#include <memory>

#include "ui/iuiobject.h"

class UIOjbect : public IUIObject
{
    public:
    UIOjbect(std::unique_ptr<IDrawable>&& drawable, SDL_Rect&& rect,
            SDL_Point&& rotationCenter, double angle);
    
    double& getAngle() override;
    IDrawable& getIDrawable() override;
    SDL_Rect& getRect() override;
    SDL_Point& getRotationCenter() override;

    private:
    std::unique_ptr<IDrawable> drawable;
    SDL_Rect rect;
    SDL_Point rotationCenter;
    double angle;
};

#endif