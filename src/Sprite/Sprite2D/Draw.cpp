#include "../../../include/Sprite/Sprite2D.hpp"

void Sprite::Sprite2D::draw(void) {
    for (int i = 0; i < this->m_PixelTab->height; i++) {
        for (int j = 0; j < this->m_PixelTab->width; j++) {
            Sprite::Pixel *pixel = Tab2D_Get(this->m_PixelTab, i, j);
            if (pixel != nullptr) {
                pixel->draw();
            }
        }
    }
}