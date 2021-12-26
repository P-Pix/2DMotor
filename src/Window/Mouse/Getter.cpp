#include "../../../include/Window/Mouse.hpp"

int Window::Mouse::getX(void) const {
    return this->m_X;
}

int Window::Mouse::getY(void) const {
    return this->m_Y;
}

int Window::Mouse::getXRel(void) const {
    return this->m_XRel;
}

int Window::Mouse::getYRel(void) const {
    return this->m_YRel;
}

int