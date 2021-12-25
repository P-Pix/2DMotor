#pragma once

#include <SDL2/SDL.h>
#include "Drawable.hpp"

class Circle : public Sprite::Drawable {
private:
    SDL_Point m_Center;
    int m_Radius = 0;

protected:
    void draw(SDL_Renderer* renderer) override;
    void setCenter(SDL_Point center) {
        this->m_Center = center;
    }
    void setRadius(int radius) {
        this->m_Radius = radius;
    }
    void setCercle(SDL_Point center, int radius) {
        this->setCenter(center);
        this->setRadius(radius);
    }
    void setCercle(int x, int y, int radius) {
        this->setCercle({x, y}, radius);
    }
public:
    Circle(SDL_Renderer* renderer, int x, int y, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        this->setCercle(x, y, radius);
        this->setColor({r, g, b, a});
        this->setRenderer(renderer);
    }
    ~Circle() {

    }
    void draw() {
        this->draw(this->getRenderer());
    }
};