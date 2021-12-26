#include "../../../include/Window/Mouse.hpp"

Window::Mouse::Mouse(void) {
}

Window::Mouse::Mouse(const SDL_Event &src) {
    this->setEvent(src);
}

Window::Mouse::~Mouse(void) {
}