#include "../../../include/Sprite/Drawable.hpp"

void Sprite::Drawable::setColor(SDL_Color *color) {
    this->m_Color = color;
}

void Sprite::Drawable::setRenderer(SDL_Renderer* renderer) {
    this->m_Renderer = renderer;
}

void Sprite::Drawable::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->m_Color->r = r;
    this->m_Color->g = g;
    this->m_Color->b = b;
    this->m_Color->a = a;
}

void Sprite::Drawable::setX(int x) {
    this->m_x = x;
}

void Sprite::Drawable::setY(int y) {
    this->m_y = y;
}