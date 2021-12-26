#pragma once

#include "Event.hpp"

#include <iostream>
#include <SDL2/SDL.h>

namespace Motor2D {
    class Mouse : public Motor2D::Event {
    private:
        SDL_MouseMotionEvent m_Motion;
        SDL_MouseButtonEvent m_Button;
        SDL_MouseWheelEvent m_Wheel;

        int m_X;
        int m_Y;

    protected:

    public:
        Mouse(void);
        Mouse(const SDL_Event *event, SDL_Window* window);
        ~Mouse(void);

        int getX(void) const;
        int getY(void) const;
        int getXRel(void) const;
        int getYRel(void) const;
        int getButton(void) const;
        int getWheel(void) const;
        int getWheelX(void) const;
        int getWheelY(void) const;

        /// @return true if the button is pressed
        bool leftButton(void);

        /// @return true if the button is pressed
        bool rightButton(void);
    };
}