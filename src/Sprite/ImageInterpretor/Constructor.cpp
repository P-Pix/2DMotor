#include "../../../include/Sprite/ImageInterpretor.hpp"

ImageInterpretor::ImageInterpretor(SDL_Renderer *renderer) {
    this->setRender(renderer);
}

ImageInterpretor::ImageInterpretor(SDL_Renderer *renderer, std::string fileName) {
    this->setRender(renderer);
    this->readImage(fileName.c_str());
}

ImageInterpretor::~ImageInterpretor(void) {
    deleteTab2D();
}

void ImageInterpretor::deleteTab2D(void) {
    Tab2D_Delete(this->m_Tab2DPixel);
}