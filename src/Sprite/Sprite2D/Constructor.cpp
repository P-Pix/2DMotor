#include "../../../include/Sprite/Sprite2D.hpp"

Sprite::Sprite2D::Sprite2D(SDL_Renderer *renderer, std::string fileName) {
    this->init(renderer, fileName);
}

Sprite::Sprite2D::Sprite2D(SDL_Renderer *renderer, int x, int y, std::string fileName) {
    this->init(renderer, fileName);
    this->setX(x);
    this->setY(y);
}

Sprite::Sprite2D::~Sprite2D(void) {
    this->deleteTab2D();
}

void Sprite::Sprite2D::init(SDL_Renderer *renderer, std::string fileName) {
    ImageInterpretor image(renderer, fileName);
    this->setRenderer(renderer);
    this->setTab2D(image.getPixels());
}

ChainedList<Sprite::Pixel *> *Sprite::Sprite2D::getListPixel(void) {
    ChainedList<Pixel *> *pointer = ChainedList_Create(Tab2D_Get(this->m_PixelTab, 0, 0));
    ChainedList<Pixel *> *list = pointer;
    for (int i = 0; i < this->m_PixelTab->height; i ++) {
        for (int j = 0; j < this->m_PixelTab->width; j ++) {
            Pixel *pixel = Tab2D_Get(this->m_PixelTab, i, j);
            if (pixel != nullptr) {
                pointer->next = ChainedList_Create(pixel);
                pointer = pointer->next;
            }
        }
    }
    return list;
}

Tab2D<Sprite::Pixel *> *Sprite::Sprite2D::getPixelTab(void) {
    return this->m_PixelTab;
}

void Sprite::Sprite2D::deleteTab2D(void) {
    Tab2D_Delete(this->m_PixelTab);
}