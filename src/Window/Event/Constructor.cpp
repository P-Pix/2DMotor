#include "../../../include/Window/Event.hpp"

Window::Event::Event(void) {
    this->m_Event = SDL_Event();
}

Window::Event::Event(const SDL_Event& event) {
    this->m_Event = event;
}

Window::Event::~Event(void) {
}

void Window::Event::poll(void) {
    SDL_PollEvent(&this->m_Event);
}