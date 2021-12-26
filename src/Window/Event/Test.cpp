#include "../../../include/Window/Event.hpp"

int main(int argc, char** argv) {
    Motor2D::Event event;
    event.poll();
    return EXIT_SUCCESS;
}