#include "../../../include/Sprite/Drawable.hpp"

int Motor2D::Drawable::getX(void) {
    return this->m_x;
}

int Motor2D::Drawable::getY(void) {
    return this->m_y;
}

SDL_Color *Motor2D::Drawable::getColor(void) {
    return &this->m_Color;
}

SDL_Renderer *Motor2D::Drawable::getRenderer(void) {
    return this->m_Renderer;
}

Uint8 Motor2D::Drawable::getA(void) {
    return this->m_Color.a;
}

Uint8 Motor2D::Drawable::getR(void) {
    return this->m_Color.r;
}

Uint8 Motor2D::Drawable::getG(void) {
    return this->m_Color.g;
}

Uint8 Motor2D::Drawable::getB(void) {
    return this->m_Color.b;
}