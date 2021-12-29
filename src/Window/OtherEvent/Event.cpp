#include "../../../include/Window/OtherEvent.hpp"

Motor2D::OtherEvent::event(void) {
    if (this->getEvent()->type == SDL_QUIT) {
        this->m_Quit = true;
    }
}