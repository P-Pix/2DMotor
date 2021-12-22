#include <iostream>

template <typename T>
struct ChainedList {
    T data;
    ChainedList<T> *next;
};

template <typename T>
ChainedList<T> *createChainedList(T data) {
    ChainedList<T> *list = new ChainedList<T>;
    list->data = data;
    list->next = nullptr;
    return list;
}

template <typename T>
void deleteChainedList(ChainedList<T> *list) {
    if (list == nullptr) {
        return;
    }
    deleteChainedList(list->next);
    delete list;
}