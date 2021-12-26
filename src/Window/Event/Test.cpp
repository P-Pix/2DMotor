#include "../../../include/Window/Event.hpp"

int main(int argc, char** argv) {
    std::cout << "Size RAM : " << sizeof(Motor2D::Event) << std::endl;
    Motor2D::Event event;
    event.poll();
    return EXIT_SUCCESS;
}