#include "../../include/Pixel.hpp"

void Pixel::setH(int h) {
    this->m_rect->h = h;
}

void Pixel::setW(int w) {
    this->m_rect->w = w;
}

void Pixel::setX(int x) {
    this->m_rect->x = x;
}

void Pixel::setY(int y) {
    this->m_rect->y = y;
}

void Pixel::setColor(SDL_Color color) {
    this->m_color = color;
}

void Pixel::setR(Uint8 r) {
    this->m_color.r = r;
    this->updateColor();
}

void Pixel::setG(Uint8 g) {
    this->m_color.g = g;
    this->updateColor();
}

void Pixel::setB(Uint8 b) {
    this->m_color.b = b;
    this->updateColor();
}

void Pixel::setA(Uint8 a) {
    this->m_color.a = a;
    this->updateColor();
}

void Pixel::updateColor(void) {
    this->m_color.r = this->m_r;
    this->m_color.g = this->m_g;
    this->m_color.b = this->m_b;
    this->m_color.a = this->m_a;

}