#include <iostream>

#include "../../include/Window/Window.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Test Window" << std::endl;
    Window window;
    Sprite sprite("image/bloc.png");
    ChainedList<Sprite *> *sprites = ChainedList_Create(&sprite);
    window.update(sprites);
    SDL_Delay(1000);
    return EXIT_SUCCESS;
}