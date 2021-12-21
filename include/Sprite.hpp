#pragma once

#include <iostream>
#include <vector>
#include "Pixel.hpp"

class Sprite : public Pixel {
private:
    int m_Height;
    int m_Width;

    int m_PixelNumber = 0;

    Pixel m_pixels[10];

protected:
    void setX(int x);
    void setY(int y);
public:
    Sprite(int x, int y);
    ~Sprite();

    void move(int x, int y);
    void setSize(int multiply);
};