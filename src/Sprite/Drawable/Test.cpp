#include <iostream>

#include "../../../include/Sprite/Drawable.hpp"

int main(int argc, char *argv[]) {
    std::cout << sizeof(Sprite::Drawable) << std::endl;
    SDL_Renderer *renderer = SDL_CreateRenderer(nullptr, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Color color = {255, 255, 255, 255};
    Sprite::Drawable drawable(0, 0, &color, renderer);
    std::cout << drawable.getX() << " " << drawable.getY() << std::endl;
    return EXIT_SUCCESS;
}