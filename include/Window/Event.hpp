#pragma once

#include <iostream>
#include <SDL2/SDL.h>

namespace Window {
    class Event {
    private:
        SDL_Event m_Event;

    protected:
        void setEvent(const SDL_Event& event);

    public:
        Event(void);
        Event(const SDL_Event& event);
        ~Event(void);
        void poll(void);
        SDL_Event* getEvent(void);
    };
}