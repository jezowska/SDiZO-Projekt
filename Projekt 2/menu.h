#pragma once
#include <iostream>
#include "graph_array.h"
#include "graph_list.h"
#include "file_reader.h"
using namespace std;

class Menu {
public:
    int choice;
    FileReader fileReader;

    Menu() {
        choice = 0;
    }

    void mainMessage();
    void DijkstraListMessage();
    void PrimListMessage();
    void show();
    void fileMessage();

};