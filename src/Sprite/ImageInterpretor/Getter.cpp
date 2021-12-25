#include "../../../include/Sprite/ImageInterpretor.hpp"

Tab2D<Sprite::Pixel *> *ImageInterpretor::getPixels() const {
    return this->m_Tab2DPixel;
}

int ImageInterpretor::getWidth() const {
    return this->m_WidthImage;
}

int ImageInterpretor::getHeight() const {
    return this->m_HeightImage;
}