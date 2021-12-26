#include "../../../include/Sprite/Sprite2D.hpp"

bool Motor2D::Sprite2D::collide(Motor2D::Sprite2D *s1, Motor2D::Sprite2D *s2) {
    ChainedList<Motor2D::Pixel *> *pixels1 = Motor2D::Sprite2D::outline(s1);
    ChainedList<Motor2D::Pixel *> *pixels2 = Motor2D::Sprite2D::outline(s2);
    while (pixels1 != nullptr) {
        ChainedList<Motor2D::Pixel *> *pixels2_copy = pixels2;
        while (pixels2_copy != nullptr) {
            if (Motor2D::Sprite2D::collide(pixels1->data, pixels2->data)) {
                return true;
            }
            pixels2_copy = pixels2_copy->next;
        }
        pixels1 = pixels1->next;
    }
    return false;
}

bool Motor2D::Sprite2D::collide(Motor2D::Pixel *p1, Motor2D::Pixel *p2) {
    return (p1->getX() == p2->getX() && p1->getY() == p2->getY());
}

ChainedList<Motor2D::Pixel *> *Motor2D::Sprite2D::outline(Motor2D::Sprite2D *s) {
    Tab2D<Motor2D::Pixel *> *tab = s->getPixelTab();
    ChainedList<Motor2D::Pixel *> *outline = nullptr;
    for (int i = 0; i < tab->height; i++) {
        for (int j = 0; j < tab->width; j++) {
            Motor2D::Pixel *p = Tab2D_Get(tab, i, j);
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