#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "../Struct/ChainedList.h"
#include "../Sprite/Sprite2D.hpp"

class Window {
private:
    SDL_Window* m_Window = nullptr;
    SDL_Renderer* m_Renderer = nullptr;

    bool init(void);
    void close(void);

    bool drawRect(SDL_Rect *rect);

    bool createWindow(const char* title, int x, int y, int w, int h);
    bool createRenderer(void);

    void destroyWindow(void);
    void destroyRenderer(void);
    ChainedList<Sprite::Sprite2D *> *m_ListSprite = nullptr;

    void setListSprite(ChainedList<Sprite::Sprite2D *> *listSprite) {
        this->m_ListSprite = listSprite;
    }

public:
    Window(void);
    ~Window(void);

    bool isOpen(void) const;
    bool update(ChainedList<Sprite::Sprite2D *> *list);
    bool update(ChainedList<Sprite::Pixel *> *list);
    bool restart(void);

    SDL_Renderer* getRenderer(void) const {
        return this->m_Renderer;
    }

    SDL_Window* getWindow(void) const {
        return this->m_Window;
    }

    ChainedList<Sprite::Sprite2D *> *getListSprite(void) {
        return m_ListSprite;
    }
};