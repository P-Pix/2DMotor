#include "../../../include/Sprite/Pixel.hpp"

Sprite::Pixel::Pixel(void) {
    SDL_Color color = {0, 0, 0, 0};
    this->init(nullptr, 0, 0, &color);
}

Sprite::Pixel::Pixel(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color color = {r, g, b, a};
    this->init(renderer, x, y, &color);
}

Sprite::Pixel::Pixel(SDL_Renderer *renderer, int x, int y, SDL_Color *color) {
    this->init(renderer, x, y, color);
}

Sprite::Pixel::~Pixel() {
}

void Sprite::Pixel::init(SDL_Renderer *renderer, int x, int y, SDL_Color *color) {
    this->setRenderer(renderer);
    this->setRect(x, y, 1, 1);
    this->setColor(color);
}