#ifndef __IUIOBJECT_H__
#define __IUIOBJECT_H__

#include "ui/idrawable.h"

class IUIObject
{
    public:
    virtual double& getAngle() = 0;
    virtual IDrawable& getIDrawable() = 0;
    virtual SDL_Rect& getRect() = 0;
    virtual SDL_Point& getRotationCenter() = 0;
    
    virtual ~IUIObject() = default;
};

#endif