#pragma once

#include <iostream>

namespace Structure {
    template<typename T>
    struct ShortcutList {
        int position;
        int floors;
        T data;
        ShortcutList<T> *next[];
    };

    template<typename T>
    ShortcutList<T> *ShortcutList_Create(T data, int position, int floors) {
        ShortcutList<T> *list = new ShortcutList<T>;
        list->data = data;
        list->position = position;
        list->floors = floors;
        for (int i = 0; i < floors; i++) {
            list->next[i] = nullptr;
        }
        return list;
    }

    template<typename T>
    void ShortcutList_Delete(ShortcutList<T> *list) {
        if (list == nullptr) {
            return;
        }
        ShortcutList_Delete(list->next[0]);
        delete list;
    }

    template<typename T>
    ShortcutList<T> *ShortcutList_Insert(ShortcutList<T> *list, int position, T data, int floors) {
        ShortcutList<T> *newList = ShortcutList_Create(data, position, floors);
        if (list == nullptr) {
            return newList;
        }
        ShortcutList<T> *current = list;
        while (current->next[0] != nullptr) {
            for (int i = 0; i < floors; i++) {
                if (current->position < position && current->next[i] != nullptr) {
                    if (current->next[i]->position >= position) {
                        newList->next[i] = current->next[i];
                    }
                    current->next[i] = newList;
                    if (i == 0) {
                        return list;
                    }
                }
            }
            current = current->next[0];
        }
        std::cout << "Error: position is out of range" << std::endl;
        return list;
    }
}
