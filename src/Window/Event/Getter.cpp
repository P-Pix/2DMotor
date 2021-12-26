#include "../../../include/Window/Event.hpp"

SDL_Event *Motor2D::Event::getEvent(void) {
    return &this->m_Event;
}

bool Motor2D::Event::isQuit(void) {
    return this->m_Type == SDL_QUIT;
}

Uint32 Motor2D::Event::getType(void) {
    return this->m_Type;
}