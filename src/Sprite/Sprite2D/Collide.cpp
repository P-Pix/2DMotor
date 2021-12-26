#include "../../../include/Sprite/Sprite2D.hpp"

bool Sprite::Sprite2D::collide(Sprite::Sprite2D *s1, Sprite::Sprite2D *s2) {
    ChainedList<Sprite::Pixel *> *pixels1 = Sprite::Sprite2D::outline(s1);
    ChainedList<Sprite::Pixel *> *pixels2 = Sprite::Sprite2D::outline(s2);
    while (pixels1 != nullptr) {
        ChainedList<Sprite::Pixel *> *pixels2_copy = pixels2;
        while (pixels2_copy != nullptr) {
            if (Sprite::Sprite2D::collide(pixels1->data, pixels2->data)) {
                return true;
            }
            pixels2_copy = pixels2_copy->next;
        }
        pixels1 = pixels1->next;
    }
    return false;
}

bool Sprite::Sprite2D::collide(Sprite::Pixel *p1, Sprite::Pixel *p2) {
    return (p1->getX() == p2->getX() && p1->getY() == p2->getY());
}

ChainedList<Sprite::Pixel *> *Sprite::Sprite2D::outline(Sprite::Sprite2D *s) {
    Tab2D<Sprite::Pixel *> *tab = s->getPixelTab();
    ChainedList<Sprite::Pixel *> *outline = nullptr;
    for (int i = 0; i < tab->height; i++) {
        for (int j = 0; j < tab->width; j++) {
            Sprite::Pixel *p = Tab2D_Get(tab, i, j);
            if (p != nullptr) {
                if (i == 0 || i == tab->height - 1 || j == 0 || j == tab->width - 1 ||
                    (Tab2D_Get(tab, i - 1, j) == nullptr || Tab2D_Get(tab, i + 1, j) == nullptr ||
                     Tab2D_Get(tab, i, j - 1) == nullptr || Tab2D_Get(tab, i, j + 1) == nullptr)) {
                    outline = ChainedList_Add(outline, p);
                }
            }
        }
    }
    return outline;
}