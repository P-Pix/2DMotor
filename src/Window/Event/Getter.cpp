#include "../../../include/Window/Event.hpp"

SDL_Event *Motor2D::Event::getEvent(void) {
    return &this->m_Event;
}