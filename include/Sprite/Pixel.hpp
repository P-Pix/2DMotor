#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Rectangle.hpp"

namespace Motor2D {
class Pixel : public Motor2D::Rectangle {
    private:
        void init(SDL_Renderer *renderer, int x, int y, SDL_Color color);

    protected:

    public:
        Pixel(void);

        Pixel(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        Pixel(SDL_Renderer *renderer, int x, int y, SDL_Color color);

        ~Pixel(void);
    };
}