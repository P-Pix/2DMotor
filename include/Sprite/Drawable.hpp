#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "../Struct/ChainedList.h"

namespace Sprite {
    class Drawable {
    private:
        int m_x = 0;
        int m_y = 0;

        SDL_Color *m_Color = nullptr;
        SDL_Renderer *m_Renderer = nullptr;

        void init(SDL_Renderer *renderer, int x, int y, SDL_Color *color);

    protected:

    public:
        Drawable(void);

        Drawable(SDL_Renderer *renderer, int x, int y, SDL_Color *color);

        Drawable(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        ~Drawable(void);

        //virtual void draw(SDL_Renderer *renderer) = 0;

        int getX(void);

        int getY(void);

        SDL_Color *getColor(void);

        Uint8 getR(void);

        Uint8 getG(void);

        Uint8 getB(void);

        Uint8 getA(void);

        SDL_Renderer *getRenderer(void);

        void setColor(SDL_Color *color);

        void setRenderer(SDL_Renderer *renderer);

        void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        void setA(Uint8 a);

        void setR(Uint8 r);

        void setG(Uint8 g);

        void setB(Uint8 b);

        void setX(int x);

        void setY(int y);
    };
}