#pragma once

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Struct/Tab2D.hpp"

class ImageInterpretor {
private:
    Tab2D<int> *m_r;
    Tab2D<int> *m_g;
    Tab2D<int> *m_b;
    Tab2D<int> *m_a;

    Uint32 getPixel(SDL_Surface *surface, int x, int y);
    void putPixelValue(SDL_Surface *surface, int x, int y);
    void resetTab2D(int width, int height);

protected:
    void readImage(std::string image);
    void setImage(std::string image);
public:
    ImageInterpretor(void);
    ImageInterpretor(std::string fileName);
    ~ImageInterpretor(void);
    Tab2D<int> *getR(void) const;
    Tab2D<int> *getG(void) const;
    Tab2D<int> *getB(void) const;
};