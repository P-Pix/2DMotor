#include "../../include/Window.hpp"

Window::Window(void) {
    this->init();
    this->createWindow("Window", 0, 0, 800, 600);
}

Window::~Window(void) {
    this->destroyWindow();
}

bool Window::update(std::vector <Sprite> list) {
    for (int i = 0; i < list.size(); i++) {
        // test for each sprite if it's correctly drawn
        if (!true) {
            return false;
        }
    }
    return true;
}

bool Window::init(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

bool Window::createWindow(const char *title, int x, int y, int w, int h) {
    this->m_Window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
    if (this->m_Window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void Window::destroyWindow(void) {
    SDL_DestroyWindow(this->m_Window);
}