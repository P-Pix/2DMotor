#include "../../../include/Sprite/Sprite.hpp"

Sprite::Sprite(std::string fileName) {
    this->init(fileName);
}

Sprite::Sprite(int x, int y, std::string fileName) {
    this->init(fileName);
    this->setX(x);
    this->setY(y);
}

Sprite::~Sprite() {
}

void Sprite::init(std::string fileName) {
    ImageInterpretor image(fileName);
    this->m_PixelTab = image.getPixels();
}

ChainedList<Pixel *> *Sprite::getListPixel(void) {
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