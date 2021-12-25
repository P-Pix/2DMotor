#pragma once

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SFML/Graphics.hpp>

#include "Pixel.hpp"
#include "../Struct/Tab2D.h"

class ImageInterpretor {
private:
    Tab2D<Sprite::Pixel *> *m_pixels = nullptr;

    SDL_Renderer *m_Renderer = nullptr;

    int m_width = 0;
    int m_height = 0;

    Uint32 getPixel(SDL_Surface *surface, int x, int y);
    void putPixelValue(SDL_Surface *surface, int x, int y);
    void putPixelValue(sf::Image *image, int x, int y);
    void deleteTab2D(void);

protected:
    void readImage(const char *fileName);

public:
    ImageInterpretor(SDL_Renderer *renderer);
    ImageInterpretor(SDL_Renderer *renderer ,std::string fileName);
    ~ImageInterpretor(void);

    void setImage(std::string image);
    void setRender(SDL_Renderer *renderer);

    Tab2D<Sprite::Pixel *> *getPixels(void) const;
};