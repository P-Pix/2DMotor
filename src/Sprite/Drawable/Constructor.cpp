#include "../../../include/Sprite/Drawable.hpp"

Motor2D::Drawable::Drawable(void) {

}

Motor2D::Drawable::Drawable(SDL_Renderer *renderer, int x, int y, SDL_Color color) {
    this->init(renderer, x, y, color);
}

Motor2D::Drawable::Drawable(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color color = {r, g, b, a};
    this->init(renderer, x, y, color);
}

void Motor2D::Drawable::init(SDL_Renderer *renderer, int x, int y, SDL_Color color) {
    this->setX(x);
    this->setY(y);
    this->setColor(color);
    this->setRenderer(renderer);
}

Motor2D::Drawable::~Drawable(void) {
}