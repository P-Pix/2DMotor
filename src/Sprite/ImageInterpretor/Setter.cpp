#include "../../../include/Sprite/ImageInterpretor.hpp"

void Motor2D::ImageInterpretor::setImage(std::string image) {
    this->readImage(image.c_str());
}

void Motor2D::ImageInterpretor::setRender(SDL_Renderer *renderer) {
    this->m_Renderer = renderer;
}