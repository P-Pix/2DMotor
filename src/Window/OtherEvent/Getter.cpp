#include "../../../include/Window/OtherEvent.hpp"

bool Motor2D::OtherEvent::isOpen(void) {
    return !this->m_Quit;
}