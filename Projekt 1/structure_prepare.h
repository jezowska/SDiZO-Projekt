#ifndef PROJEKT_1_STRUCTURE_PREPARE_H
#define PROJEKT_1_STRUCTURE_PREPARE_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <random>
#include <iomanip>
#include "dynamic_array.h"
#include "console.h"
#include "heap.h"
#include "file_prepare.h"

class Prepare {
public:
    long long int start;
    long long int passedTime;
    long long int frequency;
    bool isFileLoaded;
    int x;

    Prepare(){
        isFileLoaded = false;
        start = 0;
        passedTime = 0;
        QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    }

    void array_push_front();

    void array_push_back();

    void array_push_position();

    void array_push_without_message();

    void array_pop_without_message();

    void array_pop_front();

    void array_pop_back();

    void array_pop_position();

    void array_show();

    void array_serach();

    void list_push_front();

    void list_push_back();

    void list_push_position();

    static void list_pop_without_message();

    void list_push_without_message();

    void list_pop_front();

    void list_pop_back();

    void list_pop_position();

    void list_show();

    void list_message();

    void list_search();

    void heap_load();

    void heap_load_without_message();

    void heap_pop_without_message();

    void heap_pop();

    void heap_show();

    void heap_search();

    void readFileData();

    void createFileData();

    long long int read_QPC();

};


#endif // PROJEKT_1_STRUCTURE_PREPARE_H
