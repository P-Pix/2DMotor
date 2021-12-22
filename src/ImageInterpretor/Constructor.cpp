#include "../../include/ImageInterpretor.hpp"

ImageInterpretor::ImageInterpretor(void) {
}

ImageInterpretor::ImageInterpretor(std::string fileName) {
    this->readImage(fileName.c_str());
}

ImageInterpretor::~ImageInterpretor(void) {
}

void ImageInterpretor::deleteTab2D(void) {
    Tab2D_Delete(this->m_r);
    Tab2D_Delete(this->m_g);
    Tab2D_Delete(this->m_b);
    Tab2D_Delete(this->m_a);
}

void ImageInterpretor::setImage(std::string image) {
    this->readImage(image.c_str());
}

Tab2D<Uint8> *ImageInterpretor::getR(void) const {
    return this->m_r;
}

Tab2D<Uint8> *ImageInterpretor::getG(void) const {
    return this->m_g;
}

Tab2D<Uint8> *ImageInterpretor::getB(void) const {
    return this->m_b;
}

Tab2D<Uint8> *ImageInterpretor::getA(void) const {
    return this->m_a;
}

Tab2D<Pixel *> *ImageInterpretor::getPixels() const {
    return this->m_pixels;
}

Uint32 ImageInterpretor::getPixel(SDL_Surface *surface, int x, int y) {
    Uint32 *pixels = (Uint32 *) surface->pixels;
    return pixels[(y * surface->w) + x];
}

void ImageInterpretor::putPixelValue(SDL_Surface *surface, int x, int y) {
    Uint32 pixel = this->getPixel(surface, x, y);
    Uint8 r, g, b, a;
    SDL_GetRGBA(pixel, surface->format, &r, &g, &b, &a);
    Tab2D_Set(this->m_r, x, y, (Uint8) r);
    Tab2D_Set(this->m_g, x, y, (Uint8) g);
    Tab2D_Set(this->m_b, x, y, (Uint8) b);
    Tab2D_Set(this->m_a, x, y, (Uint8) a);
}

void ImageInterpretor::putPixelValue(sf::Image image, int x, int y) {
    sf::Color pixel = image.getPixel(x, y);
    Tab2D_Set(this->m_r, x, y, (Uint8) pixel.r);
    Tab2D_Set(this->m_g, x, y, (Uint8) pixel.g);
    Tab2D_Set(this->m_b, x, y, (Uint8) pixel.b);
    Tab2D_Set(this->m_a, x, y, (Uint8) pixel.a);
}

void ImageInterpretor::resetTab2D(int width, int height) {
    this->m_r = Tab2D_Create<Uint8>(width, height);
    Tab2D_InitValue(this->m_r);
    this->m_g = Tab2D_Create<Uint8>(width, height);
    Tab2D_InitValue(this->m_g);
    this->m_b = Tab2D_Create<Uint8>(width, height);
    Tab2D_InitValue(this->m_b);
    this->m_a = Tab2D_Create<Uint8>(width, height);
    Tab2D_InitValue(this->m_a);
}

void ImageInterpretor::readImage(const char *fileName) {
    sf::Image image;
    image.loadFromFile(fileName);
    this->m_width = image.getSize().x;
    this->m_height = image.getSize().y;
    this->resetTab2D(image.getSize().x, image.getSize().y);
    for (int y = 0; y < image.getSize().y; y++) {
        for (int x = 0; x < image.getSize().x; x++) {
            this->putPixelValue(image, x, y);
        }
    }
    this->createListPixel();
}

void ImageInterpretor::createListPixel(void) {
    this->m_pixels = Tab2D_Create<Pixel *>(this->m_width, this->m_height);
    Tab2D_InitPointer(this->m_pixels);
    for (int y = 0; y < this->m_height; y++) {
        for (int x = 0; x < this->m_width; x++) {
            std::cout << "---------- " << y << " - " << x << " ----------" << std::endl;
            if (Tab2D_Get(this->m_a, x, y) != 0) {
                std::cout << "make pixel" << std::endl;
                Pixel pixel(x, y, 1, 1,
                             Tab2D_Get(this->m_r, x, y),
                             Tab2D_Get(this->m_g, x, y),
                             Tab2D_Get(this->m_b, x, y),
                             Tab2D_Get(this->m_a, x, y));
                std::cout << "pixel created" << std::endl;
                Tab2D_Set(this->m_pixels, x, y, &pixel);
                std::cout << "pixel added" << std::endl;
            }
        }
    }
    this->deleteTab2D();
}