#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Pixel {
private:
    SDL_Rect* m_rect = nullptr;
    SDL_Color m_color = {0, 0, 0, 0};
    SDL_Renderer* m_renderer = nullptr;
    SDL_Texture* m_texture = nullptr;

    void createRect(int x, int y, int w, int h);
    void createTexture(void);
    void linkColorAndTexture(void);
    void linkRectAndTexture(void);

protected:
    void setX(Sint16 x);
    void setY(Sint16 y);
    void setW(Uint8 w);
    void setH(Uint8 h);

    void setR(Uint8 r);
    void setG(Uint8 g);
    void setB(Uint8 b);
    void setA(Uint8 a);
    void setColor(SDL_Color color);

public:
    Pixel(void);
    Pixel(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    ~Pixel(void);
    void render(void);

    Sint16 getX(void);
    Sint16 getY(void);
    Uint8 getW(void);
    Uint8 getH(void);
    SDL_Rect* getRect(void);

    Uint8 getR(void);
    Uint8 getG(void);
    Uint8 getB(void);
    Uint8 getA(void);
    SDL_Color getColor(void);
};