#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Pixel {
private:
    SDL_Rect* m_rect;
    SDL_Color m_color;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;

    Uint8 m_r;
    Uint8 m_g;
    Uint8 m_b;
    Uint8 m_a;

    void createRect(int x, int y, int w, int h);
    void createTexture(void);
    void linkColorAndTexture(void);
    void linkRectAndTexture(void);

protected:
    void setX(int x);
    void setY(int y);
    void setW(int w);
    void setH(int h);

    void setR(Uint8 r);
    void setG(Uint8 g);
    void setB(Uint8 b);
    void setA(Uint8 a);
    void setColor(SDL_Color color);
    void updateColor(void);

public:
    Pixel(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    ~Pixel(void);
    void render(void);
    int getX(void);
    int getY(void);
    int getW(void);
    int getH(void);
    SDL_Color getColor(void);
};