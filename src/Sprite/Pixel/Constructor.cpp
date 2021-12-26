#include "../../../include/Sprite/Pixel.hpp"

Motor2D::Pixel::Pixel(void) {
    SDL_Color color = {0, 0, 0, 0};
    this->init(nullptr, 0, 0, color);
}

Motor2D::Pixel::Pixel(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color color = {r, g, b, a};
    this->init(renderer, x, y, color);
}

Motor2D::Pixel::Pixel(SDL_Renderer *renderer, int x, int y, SDL_Color color) {
    this->init(renderer, x, y, color);
}

Motor2D::Pixel::~Pixel() {

}

void Motor2D::Pixel::init(SDL_Renderer *renderer, int x, int y, SDL_Color color) {
    this->setRenderer(renderer);
    this->setRect(x, y, 1, 1);
    this->setColor(color);
}