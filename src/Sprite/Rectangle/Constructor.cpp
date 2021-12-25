#include "../../../include/Sprite/Rectangle.hpp"

Sprite::Rectangle::Rectangle(void) {

}

Sprite::Rectangle::Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color color = {r, g, b, a};
    this->init(renderer, x, y, w, h, &color);
}

Sprite::Rectangle::Rectangle(SDL_Renderer *renderer, int x, int y, int w, int h, SDL_Color* color) {
    this->init(renderer, x, y, w, h, color);
}

Sprite::Rectangle::~Rectangle(void) {

}

void Sprite::Rectangle::init(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color* color) {
    this->setRect(x, y, width, height);
    this->setColor(color);
    this->setRenderer(renderer);
}
