#include "../../include/Sprite/Pixel.hpp"

int main(int argc, char** argv) {
    Pixel pixel(0, 0, 1, 1, 127, 0, 127, 255);
    std::cout << (int)pixel.getR() << " " << (int)pixel.getG() << " " << (int)pixel.getB() << " " << (int)pixel.getA() << std::endl;
    std::cout << (int)pixel.getX() << " " << (int)pixel.getY() << " " << (int)pixel.getW() << " " << (int)pixel.getH() << std::endl;
    return EXIT_SUCCESS;
}