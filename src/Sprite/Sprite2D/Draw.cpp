#include "../../../include/Sprite/Sprite2D.hpp"

bool Motor2D::Sprite2D::draw(void) {
    for (unsigned int y = 0; y < this->m_PixelTab.getHeight(); y++) {
        for (unsigned int x = 0; x < this->m_PixelTab.getWidth(); x++) {
            Motor2D::Pixel *pixel = this->m_PixelTab.get(x, y);
            if (pixel != nullptr) {
                if (!pixel->draw()) {
                    return false;
                }
            }
        }
    }
    return true;
}