#include "../../../include/Sprite/Rectangle.hpp"

void Motor2D::Rectangle::draw(void) {
    if (SDL_SetRenderDrawColor(this->getRenderer(), this->getR(), this->getG(), this->getB(),
                               this->getA())) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    if (SDL_RenderFillRect(this->getRenderer(), &this->m_Rect)) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
}