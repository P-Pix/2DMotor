#include "../../../include/Sprite/ImageInterpretor.hpp"

int main(int argc, char **argv) {
    SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    ImageInterpretor image(renderer, "image/bloc.png");
    Tab2D<Sprite::Pixel *> *list = image.getPixels();
    for (int i = 0; i < list->height; i++) {
        for (int j = 0; j < list->width; j++) {
            Tab2D_Get(list, i, j)->draw();
        }
    }
    SDL_RenderPresent(renderer);
    Tab2D_Delete(list);
    SDL_Delay(5000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return EXIT_SUCCESS;
}