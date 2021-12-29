#include "../../../include/Window/Window.hpp"

bool Motor2D::Window::isOpen() {
    return !this->m_OtherEvent.getQuit();
}