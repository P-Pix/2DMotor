#include "../../../include/Window/Mouse.hpp"

Motor2D::Mouse::Mouse(void) {
}

Motor2D::Mouse::Mouse(const SDL_Event *src, SDL_Window *window) {
    this->setEvent(src);
    this->setWindow(window);
    SDL_GetMouseState(&this->m_X, &this->m_Y);
}

Motor2D::Mouse::~Mouse(void) {
}