#include "../../include/ImageInterpretor.hpp"

ImageInterpretor::ImageInterpretor(void) {
}

ImageInterpretor::ImageInterpretor(std::string fileName) {
    this->readImage(fileName);
}

ImageInterpretor::~ImageInterpretor(void) {
    deleteTab2D(this->m_r);
    deleteTab2D(this->m_g);
    deleteTab2D(this->m_b);
    deleteTab2D(this->m_a);
}

void ImageInterpretor::setImage(std::string image) {
    this->readImage(image);
}

Tab2D<int> *ImageInterpretor::getR(void) const {
    return this->m_r;
}

Tab2D<int> *ImageInterpretor::getG(void) const {
    return this->m_g;
}

Tab2D<int> *ImageInterpretor::getB(void) const {
    return this->m_b;
}

Uint32 ImageInterpretor::getPixel(SDL_Surface *surface, int x, int y) {
    Uint32 *pixels = (Uint32 *)surface->pixels;
    return pixels[(y * surface->w) + x];
}

void ImageInterpretor::putPixelValue(SDL_Surface *surface, int x, int y) {
    Uint32 pixel = this->getPixel(surface, x, y);
    Uint8 r, g, b, a;
    SDL_GetRGBA(pixel, surface->format, &r, &g, &b, &a);
    setTab2D(this->m_r, x, y, (int)r);
    setTab2D(this->m_g, x, y, (int)g);
    setTab2D(this->m_b, x, y, (int)b);
    setTab2D(this->m_a, x, y, (int)a);
}

void ImageInterpretor::resetTab2D(int width, int height) {
    this->m_r = createTab2D<int>(width, height);
    initValue(this->m_r);
    this->m_g = createTab2D<int>(width, height);
    initValue(this->m_g);
    this->m_b = createTab2D<int>(width, height);
    initValue(this->m_b);
    this->m_a = createTab2D<int>(width, height);
    initValue(this->m_a);
}

void ImageInterpretor::readImage(std::string image) {
    std::cout << "Reading image " << image << std::endl;
    const char *fileName = image.c_str();
    std::cout << fileName << std::endl;
    SDL_Surface *surface = IMG_Load(fileName);
    if (!surface) {
        std::cerr << "Unable to load image " << image << ": " << IMG_GetError() << std::endl;
        return;
    }
    std::cout << "No error" << std::endl;
    int width = surface->w;
    int height = surface->h;
    this->resetTab2D(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            this->putPixelValue(surface, j, i);
        }
    }
    std::cout << "width: " << width << std::endl;
    std::cout << "height: " << height << std::endl;
    printTab2D(this->m_r);
    printTab2D(this->m_g);
    printTab2D(this->m_b);
}