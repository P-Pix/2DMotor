#include "../../../include/Window/Mouse.hpp"

int Motor2D::Mouse::getX(void) const {
    return this->m_X;
}

int Motor2D::Mouse::getY(void) const {
    return this->m_Y;
}

bool Motor2D::Mouse::leftButton(void) {
    // return if left button mousse is pressed
    return this->getEvent()->type == SDL_MOUSEBUTTONDOWN && this->getEvent()->button.button == SDL_BUTTON_LEFT;
}

bool Motor2D::Mouse::rightButton(void) {
    return true;
}