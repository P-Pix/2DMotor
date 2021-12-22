#pragma once

#include <iostream>

#include "Struct/Tab2D.hpp"
#include "Pixel.hpp"

class Sprite : public Pixel {
private:
    Tab2D<Pixel> *m_pixels;

protected:
    void setX(int x);
    void setY(int y);
public:
    Sprite(int x, int y);
    ~Sprite();

    void move(int x, int y);
    void setSize(int multiply);
};