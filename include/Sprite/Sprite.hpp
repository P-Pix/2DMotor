#pragma once

#include <iostream>

#include "../Struct/Tab2D.h"
#include "../Struct/ChainedList.h"
#include "ImageInterpretor.hpp"
#include "Pixel.hpp"

class Sprite : public Pixel {
private:
    int m_x = 0;
    int m_y = 0;

    Tab2D<Pixel *> *m_PixelTab = nullptr;
    void init(std::string fileName);

protected:
    void setX(int x);
    void setY(int y);
public:
    Sprite(std::string fileName);
    Sprite(int x, int y, std::string fileName);
    virtual ~Sprite();

    void move(int x, int y);
    ChainedList<Pixel *> *getListPixel(void);
    //void setSize(int multiply);
};