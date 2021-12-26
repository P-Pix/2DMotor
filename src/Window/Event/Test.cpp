#include "../../../include/Window/Event.hpp"

int main(int argc, char** argv) {
    Window::Event event;
    event.poll();
    return EXIT_SUCCESS;
}