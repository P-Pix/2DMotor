#include "../../../include/Sprite/Drawable.hpp"

void Motor2D::Drawable::setColor(SDL_Color color) {
    this->m_Color = color;
}

void Motor2D::Drawable::setRenderer(SDL_Renderer* renderer) {
    this->m_Renderer = renderer;
}

void Motor2D::Drawable::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->setR(r);
    this->setG(g);
    this->setB(b);
    this->setA(a);
}

void Motor2D::Drawable::setX(int x) {
    this->m_Vector2D.setX(x);
}

void Motor2D::Drawable::setY(int y) {
    this->m_Vector2D.setY(y);
}

void Motor2D::Drawable::setA(Uint8 a) {
    this->m_Color.a = a;
}

void Motor2D::Drawable::setR(Uint8 r) {
    this->m_Color.r = r;
}

void Motor2D::Drawable::setG(Uint8 g) {
    this->m_Color.g = g;
}

void Motor2D::Drawable::setB(Uint8 b) {
    this->m_Color.b = b;
}