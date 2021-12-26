#include "../../../include/Sprite/ImageInterpretor.hpp"

Motor2D::ImageInterpretor::ImageInterpretor(SDL_Renderer *renderer) {
    this->setRender(renderer);
}

Motor2D::ImageInterpretor::ImageInterpretor(SDL_Renderer *renderer, std::string fileName) {
    this->setRender(renderer);
    this->readImage(fileName.c_str());
}

Motor2D::ImageInterpretor::~ImageInterpretor(void) {
}

void Motor2D::ImageInterpretor::deleteTab2D(void) {
    Tab2D_Delete(this->m_Tab2DPixel);
}