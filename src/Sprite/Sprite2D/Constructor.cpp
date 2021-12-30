#include "../../../include/Sprite/Sprite2D.hpp"

Motor2D::Sprite2D::Sprite2D(SDL_Renderer *renderer, std::string fileName) {
    this->init(renderer, fileName);
}

Motor2D::Sprite2D::Sprite2D(SDL_Renderer *renderer, int x, int y, std::string fileName) {
    this->init(renderer, fileName);
    this->setX(x);
    this->setY(y);
}

Motor2D::Sprite2D::~Sprite2D(void) {
}

void Motor2D::Sprite2D::init(SDL_Renderer *renderer, std::string fileName) {
    ImageInterpretor image(renderer, fileName);
    this->setRenderer(renderer);
    this->setTab2D(image.getPixels());
    this->makeListPixel();
}

void Motor2D::Sprite2D::makeListPixel(void) {
    for (int i = 0; i < this->m_PixelTab.getHeight(); i ++) {
        for (int j = 0; j < this->m_PixelTab.getWidth(); j ++) {
            Pixel *pixel = this->m_PixelTab.get(i, j);
            if (pixel != nullptr) {
                this->m_ListPixel.add(pixel);
            }
        }
    }
}

Structure::Tab2D<Motor2D::Pixel *> *Motor2D::Sprite2D::getPixelTab(void) {
    return &this->m_PixelTab;
}

Structure::ChainedList<Motor2D::Pixel *> *Motor2D::Sprite2D::getListPixel(void) {
    return &this->m_ListPixel;
}