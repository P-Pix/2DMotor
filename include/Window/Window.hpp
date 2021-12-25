#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "../Struct/ChainedList.h"
#include "../Sprite/Sprite.hpp"

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
    ChainedList<Sprite *> *m_ListSprite = nullptr;

    void setListSprite(ChainedList<Sprite *> *listSprite) {
        this->m_ListSprite = listSprite;
    }

public:
    Window(void);
    ~Window(void);

    bool isOpen(void) const;
    bool update(ChainedList<Sprite *> *list);
    bool update(ChainedList<Pixel *> *list);
    bool restart(void);

    ChainedList<Sprite *> *getListSprite(void) {
        return m_ListSprite;
    }
};