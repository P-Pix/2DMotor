#include "../../include/Sprite/Pixel.hpp"

Sint16 Pixel::getX(void) {
    return this->m_rect->x;
}

Sint16 Pixel::getY(void) {
    return this->m_rect->y;
}

Uint8 Pixel::getW(void) {
    return this->m_rect->w;
}

Uint8 Pixel::getH(void) {
    return this->m_rect->h;
}

Uint8 Pixel::getR(void) {
    return this->m_color.r;
}

Uint8 Pixel::getG(void) {
    return this->m_color.g;
}

Uint8 Pixel::getB(void) {
    return this->m_color.b;
}

Uint8 Pixel::getA(void) {
    return this->m_color.a;
}

SDL_Rect *Pixel::getRect(void) {
    return this->m_rect;
}

SDL_Color Pixel::getColor(void) {
    return this->m_color;
}