#pragma once

#include <SDL2/SDL.h>
#include "Drawable.hpp"

namespace Sprite {
    class Rectangle : public Sprite::Drawable {
    private:
        int m_width = 0;
        int m_height = 0;

        SDL_Rect m_Rect;

    protected:
        void init(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color *color);

    public:
        Rectangle(void);

        Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h, SDL_Color *color);

        ~Rectangle(void);

        void draw(void);

        int getWidth(void);

        int getHeight(void);

        SDL_Rect getRect(void);

        void setRect(SDL_Rect rect);

        void setWidth(int width);

        void setHeight(int height);

        void setRect(int x, int y, int w, int h);
    };
}