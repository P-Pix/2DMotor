#include "../../../include/Sprite/Drawable.hpp"

Sprite::Drawable::Drawable(void) {

}

Sprite::Drawable::Drawable(int x, int y, SDL_Color* color, SDL_Renderer* renderer) {
    this->setX(x);
    this->setY(y);
    this->setColor(color);
    this->setRenderer(renderer);
}

Sprite::Drawable::Drawable(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a, SDL_Renderer* renderer) {
    this->setX(x);
    this->setY(y);
    this->setColor(r, g, b, a);
    this->setRenderer(renderer);
}

Sprite::Drawable::~Drawable(void) {

}