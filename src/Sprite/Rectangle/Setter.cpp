#include "../../../include/Sprite/Rectangle.hpp"

void Sprite::Rectangle::setRect(SDL_Rect rect) {
    this->m_Rect = rect;
}

void Sprite::Rectangle::setWidth(int width) {
    this->m_width = width;
}

void Sprite::Rectangle::setHeight(int height) {
    this->m_height = height;
}

void Sprite::Rectangle::setRect(int x, int y, int w, int h) {
    this->m_Rect.x = x;
    this->m_Rect.y = y;
    this->m_Rect.w = w;
    this->m_Rect.h = h;

    this->setX(x);
    this->setY(y);
    this->setWidth(w);
    this->setHeight(h);
}