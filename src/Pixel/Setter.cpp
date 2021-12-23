#include "../../include/Sprite/Pixel.hpp"

void Pixel::setH(Uint8 h) {
    this->m_rect->h = h;
}

void Pixel::setW(Uint8 w) {
    this->m_rect->w = w;
}

void Pixel::setX(Sint16 x) {
    this->m_rect->x = x;
}

void Pixel::setY(Sint16 y) {
    this->m_rect->y = y;
}

void Pixel::setColor(SDL_Color color) {
    this->m_color = color;
}

void Pixel::setR(Uint8 r) {
    this->m_color.r = r;
}

void Pixel::setG(Uint8 g) {
    this->m_color.g = g;
}

void Pixel::setB(Uint8 b) {
    this->m_color.b = b;
}

void Pixel::setA(Uint8 a) {
    this->m_color.a = a;
}