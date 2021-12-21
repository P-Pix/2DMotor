#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>

#include "Sprite.hpp"

class Window {
private:
    SDL_Window* m_Window = nullptr;

    bool init(void);
    void close(void);
    bool createWindow(const char* title, int x, int y, int w, int h);
    void destroyWindow(void);

public:
    Window(void);
    ~Window(void);

    bool isOpen(void) const;
    bool update(std::vector<Sprite> list);
    bool restart(void);
};