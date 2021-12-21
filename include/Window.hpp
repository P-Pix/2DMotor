#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>

#include "Sprite.hpp"

class Window {
public:
    Window(void);
    ~Window(void);

    bool update(std::vector<Sprite> list);
};