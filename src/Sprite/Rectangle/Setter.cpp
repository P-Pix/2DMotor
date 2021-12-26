#include "../../../include/Sprite/Rectangle.hpp"

void Motor2D::Rectangle::setRect(SDL_Rect rect) {
    this->m_Rect = rect;
}

void Motor2D::Rectangle::setWidth(int width) {
    this->m_width = width;
    this->m_Rect.w = width;
}

void Motor2D::Rectangle::setHeight(int height) {
    this->m_height = height;
    this->m_Rect.h = height;
}

void Motor2D::Rectangle::setPosiX(int x) {
    this->setX(x);
    this->m_Rect.x = x;
}

void Motor2D::Rectangle::setPosiY(int y) {
    this->setY(y);
    this->m_Rect.y = y;
}

void Motor2D::Rectangle::setRect(int x, int y, int w, int h) {
    this->setPosiX(x);
    this->setPosiY(y);
    this->setWidth(w);
    this->setHeight(h);
}