#include "../../../include/Sprite/Sprite2D.hpp"

void Sprite::Sprite2D::draw(void) {
    if (this->m_PixelTab == nullptr) {
        return;
    }
    for (unsigned int y = 0; y < this->m_PixelTab->height; y++) {
        for (unsigned int x = 0; x < this->m_PixelTab->width; x++) {
            Sprite::Pixel *pixel = Tab2D_GetPointer(this->m_PixelTab, x, y);
            if (pixel != nullptr) {
                pixel->draw();
            }
        }
    }
}