#pragma once

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <SFML/Graphics.hpp>

#include "Pixel.hpp"
#include "../Struct/Tab2D.hpp"

class ImageInterpretor {
private:
    Tab2D<Uint8> *m_r = nullptr;
    Tab2D<Uint8> *m_g = nullptr;
    Tab2D<Uint8> *m_b = nullptr;
    Tab2D<Uint8> *m_a = nullptr;

    int m_width = 0;
    int m_height = 0;

    Uint32 getPixel(SDL_Surface *surface, int x, int y);
    void putPixelValue(SDL_Surface *surface, int x, int y);
    void putPixelValue(sf::Image image, int x, int y);
    void resetTab2D(int width, int height);
    void createListPixel(void);
    void deleteTab2D(void);

protected:
    Tab2D<Pixel *> *m_pixels = nullptr;

    void readImage(const char *fileName);
    void setImage(std::string image);
public:
    ImageInterpretor(void);
    ImageInterpretor(std::string fileName);
    ~ImageInterpretor(void);

    Tab2D<Uint8> *getR(void) const;
    Tab2D<Uint8> *getG(void) const;
    Tab2D<Uint8> *getB(void) const;
    Tab2D<Uint8> *getA(void) const;

    Tab2D<Pixel *> *getPixels(void) const;
};