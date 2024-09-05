#ifndef __IIMAGE_H__
#define __IIMAGE_H__

#include <string>

#include "ui/idrawable.h"

class Image : public IDrawable
{
    public:
    Image(const std::string& filePath);

    void draw(SDL_Surface* destination, SDL_Rect& position);

    ~Image();

    private:
    SDL_Surface* imageSufrace;
};

#endif