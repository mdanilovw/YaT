#ifndef __IIMAGE_H__
#define __IIMAGE_H__

#include <string>

#include "ui/idrawable.h"

class Image : public IDrawable
{
    public:
    Image(const std::string& filePath, SDL_Renderer&);

    void draw(SDL_Rect& position);

    ~Image();

    private:
    SDL_Renderer& renderer;
    SDL_Texture* texture;
};

#endif