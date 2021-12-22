#include "../../include/Pixel.hpp"

int Pixel::getX(void) {
    return this->m_rect->x;
}

int Pixel::getY(void) {
    return this->m_rect->y;
}

int Pixel::getW(void) {
    return this->m_rect->w;
}

int Pixel::getH(void) {
    return this->m_rect->h;
}

SDL_Rect *Pixel::getRect(void) {
    return this->m_rect;
}

SDL_Color Pixel::getColor(void) {
    return this->m_color;
}