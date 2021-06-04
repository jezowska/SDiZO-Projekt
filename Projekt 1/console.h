#ifndef PROJEKT_1_CONSOLE_H
#define PROJEKT_1_CONSOLE_H

#include <iostream>
#include <windows.h>
#include <random>
#include <iomanip>
#include <ctime>
#include "dynamic_array.h"
#include "list.h"
#include "heap.h"
#include "file_prepare.h"
#include "structure_prepare.h"


class Message{
public:
    int choice;


    Message(){
        choice = 0;
    }

    void show();
    void mainMessage();
    void structuresMessage();
    void arrayMessage();
    void listMessage();
    void heapMessage();
    void fileMessage();
};

#endif //PROJEKT_1_CONSOLE_H
