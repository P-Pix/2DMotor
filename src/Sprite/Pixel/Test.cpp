#include "../../../include/Sprite/Pixel.hpp"

int main(int argc, char** argv) {
    std::cout << sizeof(Sprite::Pixel) << std::endl;
    SDL_Window *window = SDL_CreateWindow("Sprite Rectangle Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Color color = {127, 0, 127, 255};
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Sprite::Pixel pixel(renderer, 0, 0, &color);
    pixel.draw();
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    return EXIT_SUCCESS;
}