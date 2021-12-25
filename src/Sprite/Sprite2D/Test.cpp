#include "../../../include/Sprite/Sprite2D.hpp"

int main(int argc, char** argv) {
    SDL_Window* window = SDL_CreateWindow("Sprite2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    std::cout << "Sprite2D Test constructor" << std::endl;
    Sprite::Sprite2D test(renderer, "image/bloc.png");
    std::cout << "Sprite2D Test draw" << std::endl;
    test.draw();
    std::cout << "Sprite2D Test update" << std::endl;
    return EXIT_SUCCESS;
}