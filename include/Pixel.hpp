#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Pixel {
private:
    SDL_Rect* m_rect = nullptr;
    SDL_Color m_color = {0, 0, 0, 0};
    SDL_Renderer* m_renderer = nullptr;
    SDL_Texture* m_texture = nullptr;

    Uint8 m_r = 0;
    Uint8 m_g = 0;
    Uint8 m_b = 0;
    Uint8 m_a = 0;

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
    Pixel(void);
    Pixel(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    ~Pixel(void);
    void render(void);
    int getX(void);
    int getY(void);
    int getW(void);
    int getH(void);
    SDL_Rect* getRect(void);
    SDL_Color getColor(void);
};