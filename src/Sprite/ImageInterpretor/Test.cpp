#include "../../../include/Sprite/ImageInterpretor.hpp"

int main(int argc, char **argv) {
    std::cout << "Size RAM : " << sizeof(Motor2D::ImageInterpretor) << std::endl;
    SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Motor2D::ImageInterpretor image(renderer, "image/bloc.png");
    Structure::Tab2D<Motor2D::Pixel *> *list = image.getPixels();
    for (int i = 0; i < list->getHeight(); i++) {
        for (int j = 0; j < list->getWidth(); j++) {
            list->get(i, j)->draw();
        }
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    SDL_Quit();
    return EXIT_SUCCESS;
}