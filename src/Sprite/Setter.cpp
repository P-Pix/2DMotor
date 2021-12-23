#include "../../include/Sprite/Sprite.hpp"

void Sprite::setX(int x) {
    for (int i = 0; i < this->m_PixelTab->height; i++) {
        for (int j = 0; j < this->m_PixelTab->width; j++) {
            this->m_PixelTab->tab[i][j]->getRect()->x += x;
        }
    }
    this->m_x = x;
}

void Sprite::setY(int y) {
    for (int i = 0; i < this->m_PixelTab->height; i++) {
        for (int j = 0; j < this->m_PixelTab->width; j++) {
            this->m_PixelTab->tab[i][j]->getRect()->y += y;
        }
    }
    this->m_y = y;
}

void Sprite::move(int x, int y) {
    this->setX(x - this->m_x);
    this->setY(y - this->m_y);
}