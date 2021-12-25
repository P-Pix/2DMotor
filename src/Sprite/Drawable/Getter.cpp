#include "../../../include/Sprite/Drawable.hpp"

int Sprite::Drawable::getX(void) {
    return this->m_x;
}

int Sprite::Drawable::getY(void) {
    return this->m_y;
}

SDL_Color *Sprite::Drawable::getColor(void) {
    return &this->m_Color;
}

SDL_Renderer *Sprite::Drawable::getRenderer(void) {
    return this->m_Renderer;
}

Uint8 Sprite::Drawable::getA(void) {
    return this->m_Color.a;
}

Uint8 Sprite::Drawable::getR(void) {
    return this->m_Color.r;
}

Uint8 Sprite::Drawable::getG(void) {
    return this->m_Color.g;
}

Uint8 Sprite::Drawable::getB(void) {
    return this->m_Color.b;
}