#ifndef SDIZO_PROJEKT1_DYNAMICARRAY_H
#define SDIZO_PROJEKT1_DYNAMICARRAY_H
#include <iostream>

class Dynamic_array {
public:
    int *array;
    int size;

    Dynamic_array();

    ~Dynamic_array();

    void push_front(int value);

    void push_back(int value);

    void push_position(int value, int position);

    void pop_back();

    void pop_front();

    void pop(int position);

    void swap(int x, int y);

    int position(int value);

    void show();


};
#endif //SDIZO_PROJEKT1_DYNAMICARRAY_H

