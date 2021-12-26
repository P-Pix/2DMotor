#pragma once

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SFML/Graphics.hpp>

#include "Pixel.hpp"
#include "../Struct/Tab2D.h"

namespace Motor2D {
    class ImageInterpretor {
    private:
        Tab2D<Motor2D::Pixel *> *m_Tab2DPixel = nullptr;

        SDL_Renderer *m_Renderer = nullptr;

        int m_WidthImage = 0;
        int m_HeightImage = 0;

        Uint32 getPixel(SDL_Surface *surface, int x, int y);

        void putPixelValue(SDL_Surface *surface, int x, int y);

        void putPixelValue(sf::Image *image, int x, int y);

        void deleteTab2D(void);

    protected:
        void readImage(const char *fileName);

    public:
        ImageInterpretor(SDL_Renderer *renderer);

        ImageInterpretor(SDL_Renderer *renderer, std::string fileName);

        ~ImageInterpretor(void);

        void setImage(std::string image);

        void setRender(SDL_Renderer *renderer);

        Tab2D<Motor2D::Pixel *> *getPixels(void) const;

        int getWidth(void) const;

        int getHeight(void) const;
    };
}