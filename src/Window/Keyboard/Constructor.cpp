#include "../../../include/Window/Keyboard.hpp"

Motor2D::Keyboard::Keyboard(void) {

}

Motor2D::Keyboard::Keyboard(SDL_Event* event, SDL_Window* window) {
    this->setWindow(window);
    this->setEvent(event);
}

Motor2D::Keyboard::~Keyboard(void) {

}