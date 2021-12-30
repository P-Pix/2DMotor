#include <iostream>

#include "../../../include/Window/Window.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Test Window" << std::endl;
    std::cout << "Size RAM : " << sizeof(Motor2D::Window) << std::endl;
    Motor2D::Window window;
    Motor2D::Sprite2D sprite(window.getRenderer(), "image/bloc.png");
    Structure::ChainedList<Motor2D::Sprite2D *> sprites(&sprite);
    std::cout << "Window created" << std::endl;
    window.update(&sprites);
    std::cout << "Window created" << std::endl;
    SDL_RenderPresent(window.getRenderer());
    std::cout << "Window created" << std::endl;
    SDL_Delay(5000);
    SDL_Quit();
    return EXIT_SUCCESS;
}