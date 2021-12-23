#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "../Struct/ChainedList.hpp"
#include "../Sprite/Sprite.hpp"

class Window {
private:
    SDL_Window* m_Window = nullptr;
    SDL_Renderer* m_Renderer = nullptr;

    ChainedList<Sprite *> *m_ListSprite;

    bool init(void);
    void close(void);

    bool drawRect(SDL_Rect *rect);

    bool createWindow(const char* title, int x, int y, int w, int h);
    bool createRenderer(void);

    void destroyWindow(void);
    void destroyRenderer(void);

public:
    Window(void);
    ~Window(void);

    bool isOpen(void) const;
    bool update(ChainedList<Sprite *> *list);
    bool restart(void);
};