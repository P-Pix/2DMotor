#include "../../../include/Window/Event.hpp"

Motor2D::Event::Event(void) {
    this->m_Event = SDL_Event();
    this->m_Window = nullptr;
}

Motor2D::Event::Event(const SDL_Event *event, SDL_Window* window) {
    this->setEvent(event);
    this->setWindow(window);
}

Motor2D::Event::~Event(void) {
}

bool Motor2D::Event::poll(void) {
    return SDL_PollEvent(&this->m_Event);
}