#pragma once

#include <iostream>

#include "../Struct/Tab2D.hpp"
#include "../Struct/ChainedList.hpp"
#include "ImageInterpretor.hpp"
#include "Pixel.hpp"

namespace Motor2D {
class Sprite2D : public Motor2D::Pixel {
    private:
        int m_XSprite = 0;
        int m_YSprite = 0;

        Structure::Tab2D<Motor2D::Pixel *> m_PixelTab;

        void init(SDL_Renderer *renderer, std::string fileName);

        void deleteTab2D(void);

    protected:
        void setX(int x);

        void setY(int y);

        void setTab2D(Structure::Tab2D<Motor2D::Pixel *> *tab2D);

    public:
        Sprite2D(SDL_Renderer *renderer, std::string fileName);

        Sprite2D(SDL_Renderer *renderer, int x, int y, std::string fileName);

        virtual ~Sprite2D(void);

        void move(int x, int y);

        void draw(void) override;

        Structure::ChainedList<Motor2D::Pixel *> *getListPixel(void);

        Structure::Tab2D<Motor2D::Pixel *> *getPixelTab(void);

        static bool collide(Motor2D::Sprite2D *s1, Motor2D::Sprite2D *s2);

        static bool collide(Motor2D::Pixel *p1, Motor2D::Pixel *p2);

        // if it's possible i need the exacly outline of the sprite
        /*
         * |---------|      |---------|
         * |xxxvvvvxx|      |xxxvvvvxx|
         * |xvvvvvvxx|      |xvvxxxvxx|
         * |vvvvvvxxx|  ->  |vvvxxvxxx|     loop gain
         * |xxxvvxxxx|      |xxxvvxxxx|
         * |---------|      |---------|
         */

        static Structure::ChainedList<Motor2D::Pixel *> *outline(Motor2D::Sprite2D *s);
    };
}