#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "OtherEvent.hpp"
#include "../Sprite/Sprite2D.hpp"

namespace Motor2D {
    class Window {
    private:
        SDL_Window *m_Window = nullptr;
        SDL_Renderer *m_Renderer = nullptr;
        SDL_Event m_Event;

        Motor2D::Keyboard m_Keyboard;
        Motor2D::Mouse m_Mouse;
        Motor2D::OtherEvent m_OtherEvent;

        void init(const char *Name);

        bool initSDL(void);

        bool createWindow(const char *title, int x, int y, int w, int h);

        bool createRenderer(void);

        void destroyWindow(void);

        void destroyRenderer(void);

        Structure::ChainedList<Motor2D::Sprite2D *> m_ListSprite;

        void setListSprite(Structure::ChainedList<Motor2D::Sprite2D *> *listSprite) {
            this->m_ListSprite = *listSprite;
        }

    public:

        Window(void);

        Window(const char *Name);

        ~Window(void);

        bool update(Structure::ChainedList<Motor2D::Sprite2D *> *list);

        bool update(Structure::ChainedList<Motor2D::Pixel *> *list);

        bool restart(void);

        bool isOpen(void);

        SDL_Renderer *getRenderer(void) const {
            return this->m_Renderer;
        }

        SDL_Window *getWindow(void) const {
            return this->m_Window;
        }

        Structure::ChainedList<Motor2D::Sprite2D *> *getListSprite(void) {
            return &m_ListSprite;
        }
    };
}