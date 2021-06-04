#ifndef SDIZO_PROJEKT1_HEAP_H
#define SDIZO_PROJEKT1_HEAP_H

#include <iostream>
#include "dynamic_array.h"

class Heap{
public:

    int size;
    Dynamic_array kopiec;

    Heap();
    ~Heap();

    void push(int number);

    void rmv();

    void show();

    bool search(int value);

};
#endif //SDIZO_PROJEKT1_HEAP_H