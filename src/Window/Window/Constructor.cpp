#include "../../../include/Window/Window.hpp"

Motor2D::Window::Window(void) {
    this->init("Window");
}

Motor2D::Window::Window(const char *Name) {
    this->init(Name);
}

Motor2D::Window::~Window(void) {
    this->destroyRenderer();
    this->destroyWindow();
}

void Motor2D::Window::init(const char *Name) {
    this->initSDL();
    this->createWindow(Name, 0, 0, 800, 600);
    this->createRenderer();
    this->m_Keyboard.setWindow(this->m_Window);
    this->m_Keyboard.setEvent(&this->m_Event);
    this->m_Mouse.setWindow(this->m_Window);
    this->m_Mouse.setEvent(&this->m_Event);
    this->m_OtherEvent.setWindow(this->m_Window);
    this->m_OtherEvent.setEvent(&this->m_Event);
}

bool Motor2D::Window::update(Structure::ChainedList<Motor2D::Sprite2D *> *list) {
    if (list == nullptr) {
        return true;
    }
    Structure::ChainedList<Motor2D::Pixel *> *listPixel = list->getData()->getListPixel();
    if (listPixel == nullptr) {
        return true;
    }
    if (!this->update(listPixel)) {
        return false;
    }
    return this->update(list->getNext());
}

bool Motor2D::Window::update(Structure::ChainedList<Motor2D::Pixel *> *list) {
    if (list == nullptr) {
        return true;
    }
    if (list->getData() == nullptr) {
        return true;
    }
    if (!list->getData()->draw()) {
        return false;
    }
    return this->update(list->getNext());
}

bool Motor2D::Window::initSDL(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

bool Motor2D::Window::createWindow(const char *title, int x, int y, int w, int h) {
    this->m_Window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
    if (this->m_Window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

bool Motor2D::Window::createRenderer(void) {
    this->m_Renderer = SDL_CreateRenderer(this->m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->m_Renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void Motor2D::Window::destroyWindow(void) {
    SDL_DestroyWindow(this->m_Window);
}

void Motor2D::Window::destroyRenderer(void) {
    SDL_DestroyRenderer(this->m_Renderer);
}

bool Motor2D::Window::restart(void) {
    this->destroyRenderer();
    this->destroyWindow();
    this->createWindow("Window", 0, 0, 800, 600);
    this->createRenderer();
    return true;
}