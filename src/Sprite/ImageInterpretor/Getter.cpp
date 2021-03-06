#include "../../../include/Sprite/ImageInterpretor.hpp"

Structure::Tab2D<Motor2D::Pixel *> *Motor2D::ImageInterpretor::getPixels() {
    return &this->m_Tab2DPixel;
}

int Motor2D::ImageInterpretor::getWidth() const {
    return this->m_WidthImage;
}

int Motor2D::ImageInterpretor::getHeight() const {
    return this->m_HeightImage;
}