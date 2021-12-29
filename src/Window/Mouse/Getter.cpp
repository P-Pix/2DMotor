#include "../../../include/Window/Mouse.hpp"

int Motor2D::Mouse::getX(void) const {
    return this->m_X;
}

int Motor2D::Mouse::getY(void) const {
    return this->m_Y;
}

bool Motor2D::Mouse::getLeftButton() const {
    return this->m_LeftButton;
}

bool Motor2D::Mouse::getRightButton(void) const {
    return this->m_RightButton;
}

bool Motor2D::Mouse::getMiddleButton(void) const {
    return this->m_MiddleButton;
}