#include <iostream>

template <typename T>
struct Tab2D {
    size_t width;
    size_t height;
    T **tab;
};

template <typename T>
Tab2D<T> *createTab2D(size_t width, size_t height) {
    Tab2D<T> *tab = new Tab2D<T>;
    tab->width = width;
    tab->height = height;
    tab->tab = new T*[height];
    for (size_t i = 0; i < height; i++) {
        tab->tab[i] = new T[width];
    }
    return tab;
}

template <typename T>
void initPointer(Tab2D<T> *tab) {
    if (tab == nullptr) {
        tab = new Tab2D<T>;
    }
    for (size_t i = 0; i < tab->height; i++) {
        for (size_t j = 0; j < tab->width; j++) {
            tab->tab[i][j] = nullptr;
        }
    }
}

template <typename T>
void initValue(Tab2D<T> *tab) {
    if (tab == nullptr) {
        tab = new Tab2D<T>;
    }
    for (size_t i = 0; i < tab->height; i++) {
        for (size_t j = 0; j < tab->width; j++) {
            tab->tab[i][j] = 0;
        }
    }
}

template <typename T>
void initChar(Tab2D<T> *tab) {
    if (tab == nullptr) {
        tab = new Tab2D<T>;
    }
    for (size_t i = 0; i < tab->height; i++) {
        for (size_t j = 0; j < tab->width; j++) {
            tab->tab[i][j] = '\0';
        }
    }
}

template <typename T>
void deleteTab2D(Tab2D<T> *tab) {
    for (size_t i = 0; i < tab->height; i++) {
        delete[] tab->tab[i];
    }
    delete[] tab->tab;
    delete tab;
}

template <typename T>
void printTab2D(Tab2D<T> *tab) {
    for (size_t i = 0; i < tab->height; i++) {
        for (size_t j = 0; j < tab->width; j++) {
            std::cout << tab->tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void setTab2D(Tab2D<T> *tab, size_t x, size_t y, T value) {
    tab->tab[y][x] = value;
}