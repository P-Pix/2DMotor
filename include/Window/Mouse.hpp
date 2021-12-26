#pragma once

#include "Event.hpp"

#include <iostream>
#include <SDL2/SDL.h>

namespace Window {
    class Mouse : public Window::Event {
    private:
        Sint32 m_X = 0;
        Sint32 m_Y = 0;

    protected:
        void setX(int x);
        void setY(int y);

    public:
        Mouse(void);
        Mouse(const SDL_Event& event);
        ~Mouse(void);

        int getX(void) const;
        int getY(void) const;
        int getXRel(void) const;
        int getYRel(void) const;
        int getButton(void) const;
        int getWheel(void) const;
        int getWheelX(void) const;
        int getWheelY(void) const;

        bool isLeftButtonDown(void);
        bool isRightButtonDown(void);
        bool isMiddleButtonDown(void);
        bool isLeftButtonUp(void);
        bool isRightButtonUp(void);
        bool isMiddleButtonUp(void);
        bool isLeftButtonClicked(void);
        bool isRightButtonClicked(void);
        bool isMiddleButtonClicked(void);
    };
}