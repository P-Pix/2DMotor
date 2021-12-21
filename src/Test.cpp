#define _MAIN_CPP_

#include <iostream>

#include "main.cpp"

int main(int argc, char *argv[]) {
    std::cout << "Test" << std::endl;
    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    std::cout << "Test" << std::endl;
    return EXIT_SUCCESS;
}