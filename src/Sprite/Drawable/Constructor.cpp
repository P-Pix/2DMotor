#include "../../../include/Sprite/Drawable.hpp"

Sprite::Drawable::Drawable(void) {

}

Sprite::Drawable::Drawable(SDL_Renderer *renderer, int x, int y, SDL_Color* color) {
    this->init(renderer, x, y, color);
}

Sprite::Drawable::Drawable(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color color = {r, g, b, a};
    this->init(renderer, x, y, &color);
}

void Sprite::Drawable::init(SDL_Renderer *renderer, int x, int y, SDL_Color *color) {
    this->setX(x);
    this->setY(y);
    this->setColor(color);
    this->setRenderer(renderer);
}

Sprite::Drawable::~Drawable(void) {
}