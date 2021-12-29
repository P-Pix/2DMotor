#pragma once

#include "Event.hpp"

namespace Motor2D {
    class OtherEvent : public Event {
    private:
        bool m_Quit = false;
    protected:
    public:
        OtherEvent(void);

        ~OtherEvent(void);

        event(void);

        bool isOpen(void);
    };
}