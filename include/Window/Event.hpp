#pragma once

#include <iostream>
#include <SDL2/SDL.h>

namespace Motor2D {
    class Event {
    private:
        SDL_Event m_Event;
        SDL_Window* m_Window;

        Uint32 m_Type;

    protected:
        void setEvent(const SDL_Event *event);
        void setWindow(SDL_Window* window);

    public:
        Event(void);
        Event(const SDL_Event *event, SDL_Window* window);
        ~Event(void);
        bool poll(void);
        bool isQuit(void);
        Uint32 getType(void);
        SDL_Event* getEvent(void);
    };
}