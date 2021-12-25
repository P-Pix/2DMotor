#include "../../../include/Sprite/Rectangle.hpp"

int Sprite::Rectangle::getWidth(void) {
    return this->m_width;
}

int Sprite::Rectangle::getHeight(void) {
    return this->m_height;
}

SDL_Rect Sprite::Rectangle::getRect(void) {
    return this->m_Rect;
}