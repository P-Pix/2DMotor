#include "../../../include/Sprite/ImageInterpretor.hpp"

int main(int argc, char **argv) {
    SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    ImageInterpretor image(renderer, "image/bloc.png");
    // no problem with rgba value
    Tab2D<Sprite::Pixel *> *list = image.getPixels();
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < list->height; i++) {
        for (int j = 0; j < list->width; j++) {
            Tab2D_Get(list, i, j)->draw();
            std::cout << (int) Tab2D_Get(list, i, j)->getR() << " " << (int) Tab2D_Get(list, i, j)->getG() << " "
                      << (int) Tab2D_Get(list, i, j)->getB() << " " << (int) Tab2D_Get(list, i, j)->getA() << std::endl;
        }
        std::cout << std::endl;
    }
    SDL_RenderPresent(renderer);
    for (int i = 0; i < list->height; i++) {
        for (int j = 0; j < list->width; j++) {
            Tab2D_Get(list, i, j)->~Pixel();
        }
    }
    Tab2D_Delete(list);
    SDL_Delay(5000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return EXIT_SUCCESS;
}