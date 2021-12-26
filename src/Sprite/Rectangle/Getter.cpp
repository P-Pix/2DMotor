#include "../../../include/Sprite/Rectangle.hpp"

int Motor2D::Rectangle::getWidth(void) {
    return this->m_width;
}

int Motor2D::Rectangle::getHeight(void) {
    return this->m_height;
}

SDL_Rect *Motor2D::Rectangle::getRect(void) {
    return &this->m_Rect;
}