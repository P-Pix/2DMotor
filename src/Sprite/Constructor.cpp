#include "../../include/Sprite.hpp"

Sprite::Sprite(std::string fileName) {
    ImageInterpretor imageInterpretor(fileName);
    this->m_PixelTab = imageInterpretor.getPixels();
}

Sprite::Sprite(int x, int y, std::string fileName) {
    ImageInterpretor imageInterpretor(fileName);
    this->m_PixelTab = imageInterpretor.getPixels();
    this->setX(x);
    this->setY(y);
}

Sprite::~Sprite() {
}