#include "../../../include/Window/Window.hpp"

Window::Window(void) {
    this->init();
    this->createWindow("Window", 0, 0, 800, 600);
    this->createRenderer();
}

Window::~Window(void) {
    this->destroyRenderer();
    this->destroyWindow();
}

bool Window::update(ChainedList<Sprite::Sprite2D *> *list) {
    while (list != nullptr) {
        ChainedList<Sprite::Pixel *> *listPixel = list->data->getListPixel();
        if (!this->update(listPixel)) {
            return false;
        }
        list = list->next;
    }
    return true;
}

bool Window::update(ChainedList<Sprite::Pixel *> *list) {
    while (list != nullptr) {
        if (!this->drawRect(list->data->getRect())) {
            return false;
        }
        list = list->next;
    }
    return true;
}

bool Window::drawRect(SDL_Rect *rect) {
    if (!SDL_RenderDrawRect(this->m_Renderer, rect)) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return false;
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

bool Window::createRenderer(void) {
    this->m_Renderer = SDL_CreateRenderer(this->m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->m_Renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void Window::destroyWindow(void) {
    SDL_DestroyWindow(this->m_Window);
}

void Window::destroyRenderer(void) {
    SDL_DestroyRenderer(this->m_Renderer);
}

bool Window::restart(void) {
    this->destroyRenderer();
    this->destroyWindow();
    this->createWindow("Window", 0, 0, 800, 600);
    this->createRenderer();
    return true;
}

void Window::close(void) {

}