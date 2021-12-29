#include "../../../include/Sprite/Rectangle.hpp"

bool Motor2D::Rectangle::draw(void) {
    if (SDL_SetRenderDrawColor(this->getRenderer(), this->getR(), this->getG(), this->getB(),
                               this->getA())) {
        return false;
    }
    if (SDL_RenderFillRect(this->getRenderer(), &this->m_Rect)) {
        return false;
    }
    return true;
}