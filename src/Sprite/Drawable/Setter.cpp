#include "../../../include/Sprite/Drawable.hpp"

void Sprite::Drawable::setColor(SDL_Color *color) {
    this->m_Color = color;
    std::cout << (int)this->m_Color->r << " " << (int)this->m_Color->g << " " << (int)this->m_Color->b << " " << (int)this->m_Color->a << std::endl;
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

void Sprite::Drawable::setA(Uint8 a) {
    this->m_Color->a = a;
}

void Sprite::Drawable::setR(Uint8 r) {
    this->m_Color->r = r;
}

void Sprite::Drawable::setG(Uint8 g) {
    this->m_Color->g = g;
}

void Sprite::Drawable::setB(Uint8 b) {
    this->m_Color->b = b;
}