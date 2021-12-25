#pragma once

#include <iostream>

template <typename T>
struct ChainedList {
    T data;
    ChainedList<T> *next;
};

template <typename T>
ChainedList<T> *ChainedList_Create(T data) {
    ChainedList<T> *list = new ChainedList<T>;
    list->data = data;
    list->next = nullptr;
    return list;
}

template <typename T>
void ChainedList_Delete(ChainedList<T> *list) {
    if (list == nullptr) {
        return;
    }
    ChainedList_Delete(list->next);
    delete list;
}

template <typename T>
ChainedList<T> *ChainedList_Set(ChainedList<T> *list, T data) {
    list->data = data;
    return list;
}