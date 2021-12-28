#include "../../../include/Sprite/Sprite2D.hpp"

void Motor2D::Sprite2D::setX(int x) {
    for (int i = 0; i < this->m_PixelTab.getHeight(); i++) {
        for (int j = 0; j < this->m_PixelTab.getWidth(); j++) {
            this->m_PixelTab.get(i, j)->getRect()->x += x;
        }
    }
    this->m_XSprite = x;
}

void Motor2D::Sprite2D::setY(int y) {
    for (int i = 0; i < this->m_PixelTab.getHeight(); i++) {
        for (int j = 0; j < this->m_PixelTab.getWidth(); j++) {
            this->m_PixelTab.get(i, j)->getRect()->y += y;
        }
    }
    this->m_YSprite = y;
}

void Motor2D::Sprite2D::move(int x, int y) {
    this->setX(x + this->m_XSprite);
    this->setY(y + this->m_YSprite);
}

void Motor2D::Sprite2D::setTab2D(Structure::Tab2D<Motor2D::Pixel *> *tab2D) {
    this->m_PixelTab = *tab2D;
}