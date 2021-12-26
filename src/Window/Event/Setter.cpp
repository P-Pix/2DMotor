#include "../../../include/Window/Event.hpp"

void Motor2D::Event::setEvent(const SDL_Event *event) {
    this->m_Event = *event;
}

void Motor2D::Event::setWindow(SDL_Window *window) {
    this->m_Window = window;
}