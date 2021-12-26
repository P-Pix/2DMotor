#include "../../../include/Window/Mouse.hpp"

int main(int argc, char **argv) {
    std::cout << "Size RAM : " << sizeof(Motor2D::Mouse) << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Event event;
    Motor2D::Mouse mouse(&event, window);
    while (!mouse.isQuit()) {
        if (!mouse.poll()) {
            std::cout << "Poll" << std::endl;
        }
        std::cout << mouse.getX() << " " << mouse.getY() << std::endl;
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}