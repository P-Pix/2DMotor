#pragma once

#include <iostream>

#include "../Struct/Tab2D.h"
#include "../Struct/ChainedList.h"
#include "ImageInterpretor.hpp"
#include "Pixel.hpp"

namespace Sprite {
class Sprite2D : public Sprite::Pixel {
    private:
        int m_XSprite = 0;
        int m_YSprite = 0;

        Tab2D<Sprite::Pixel *> *m_PixelTab = nullptr;

        void init(SDL_Renderer *renderer, std::string fileName);

    protected:
        void setX(int x);

        void setY(int y);

    public:
        Sprite2D(SDL_Renderer *renderer, std::string fileName);

        Sprite2D(SDL_Renderer *renderer, int x, int y, std::string fileName);

        virtual ~Sprite2D(void);

        void move(int x, int y);

        void draw(void);

        ChainedList<Sprite::Pixel *> *getListPixel(void);

        Tab2D<Sprite::Pixel *> *getPixelTab(void);

        static bool collide(Sprite::Sprite2D *s1, Sprite::Sprite2D *s2);

        static bool collide(Sprite::Pixel *p1, Sprite::Pixel *p2);

        // if it's possible i need the exacly outline of the sprite
        /*
         * |---------|      |---------|
         * |xxxvvvvxx|      |xxxvvvvxx|
         * |xvvvvvvxx|      |xvvxxxvxx|
         * |vvvvvvxxx|  ->  |vvvxxvxxx|     loop gain
         * |xxxvvxxxx|      |xxxvvxxxx|
         * |---------|      |---------|
         */

        static ChainedList<Sprite::Pixel *> *outline(Sprite::Sprite2D *s);
    };
}