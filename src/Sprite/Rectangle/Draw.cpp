#include "../../../include/Sprite/Rectangle.hpp"

void Sprite::Rectangle::draw(void) {
    SDL_SetRenderDrawColor(this->getRenderer(), this->getR(), this->getG(), this->getB(),
                           this->getA());
    SDL_RenderFillRect(this->getRenderer(), &this->m_Rect);
}