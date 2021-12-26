#pragma once

#include "Event.hpp"

namespace Motor2D {
    class Keyboard : public Motor2D::Event {
    private:
        SDL_KeyboardEvent m_Keyboard;

    public:
        Keyboard(void);
        Keyboard(SDL_Event* event, SDL_Window* window);
        ~Keyboard(void);
    };
}