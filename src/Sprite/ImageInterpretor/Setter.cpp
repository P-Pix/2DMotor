#include "../../../include/Sprite/ImageInterpretor.hpp"

void ImageInterpretor::setImage(std::string image) {
    this->readImage(image.c_str());
}

void ImageInterpretor::setRender(SDL_Renderer *renderer) {
    this->m_Renderer = renderer;
}