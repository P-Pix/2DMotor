#include "../../../include/Sprite/Sprite2D.hpp"

void Sprite::Sprite2D::setX(int x) {
    for (int i = 0; i < this->m_PixelTab->height; i++) {
        for (int j = 0; j < this->m_PixelTab->width; j++) {
            this->m_PixelTab->tab[i][j]->getRect()->x += x;
        }
    }
    this->m_XSprite = x;
}

void Sprite::Sprite2D::setY(int y) {
    for (int i = 0; i < this->m_PixelTab->height; i++) {
        for (int j = 0; j < this->m_PixelTab->width; j++) {
            this->m_PixelTab->tab[i][j]->getRect()->y += y;
        }
    }
    this->m_YSprite = y;
}

void Sprite::Sprite2D::move(int x, int y) {
    this->setX(x + this->m_XSprite);
    this->setY(y + this->m_YSprite);
}

void Sprite::Sprite2D::setTab2D(Tab2D<Sprite::Pixel *> *tab2D) {
    this->m_PixelTab = tab2D;
}