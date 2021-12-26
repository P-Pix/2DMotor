#pragma once

#include <iostream>

template <typename T>
struct Tab2D {
    size_t width;
    size_t height;
    T **tab;
};

template <typename T>
Tab2D<T> *Tab2D_Create(size_t width, size_t height) {
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
void Tab2D_InitPointer(Tab2D<T> *tab) {
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
void Tab2D_InitValue(Tab2D<T> *tab) {
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
void Tab2D_InitChar(Tab2D<T> *tab) {
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
void Tab2D_Delete(Tab2D<T> *tab) {
    if (tab == nullptr) {
        return;
    }
    for (size_t i = 0; i < tab->height; i++) {
        delete[] tab->tab[i];
    }
    delete[] tab->tab;
    delete tab;
    return;
}

template <typename T>
void Tab2D_Print(Tab2D<T> *tab) {
    if (tab == nullptr) {
        return;
    }
    for (size_t i = 0; i < tab->height; i++) {
        for (size_t j = 0; j < tab->width; j++) {
            std::cout << tab->tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void Tab2D_Set(Tab2D<T> *tab, size_t x, size_t y, T value) {
    if (tab == nullptr) {
        return;
    }
    tab->tab[y][x] = value;
}

template <typename T>
T Tab2D_Get(Tab2D<T> *tab, size_t x, size_t y) {
    if (tab == nullptr) {
        return 0;
    }
    if (x >= tab->width || y >= tab->height) {
        return 0;
    }
    return tab->tab[y][x];
}

template <typename T>
T Tab2D_GetPointer(Tab2D<T> *tab, size_t x, size_t y) {
    if (tab == nullptr) {
        return nullptr;
    }
    if (x >= tab->width || y >= tab->height) {
        return nullptr;
    }
    return tab->tab[y][x];
}