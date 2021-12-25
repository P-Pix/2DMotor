#include "../../../include/Sprite/Rectangle.hpp"

void Sprite::Rectangle::setRect(SDL_Rect rect) {
    this->m_Rect = rect;
}

void Sprite::Rectangle::setWidth(int width) {
    this->m_width = width;
    this->m_Rect.w = width;
}

void Sprite::Rectangle::setHeight(int height) {
    this->m_height = height;
    this->m_Rect.h = height;
}

void Sprite::Rectangle::setPosiX(int x) {
    this->setX(x);
    this->m_Rect.x = x;
}

void Sprite::Rectangle::setPosiY(int y) {
    this->setY(y);
    this->m_Rect.y = y;
}

void Sprite::Rectangle::setRect(int x, int y, int w, int h) {
    this->setPosiX(x);
    this->setPosiY(y);
    this->setWidth(w);
    this->setHeight(h);
}