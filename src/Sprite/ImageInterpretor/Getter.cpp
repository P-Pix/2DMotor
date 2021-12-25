#include "../../../include/Sprite/ImageInterpretor.hpp"

Tab2D<Sprite::Pixel *> *ImageInterpretor::getPixels() const {
    return this->m_pixels;
}