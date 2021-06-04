#ifndef PROJEKT_1_FILE_PREPARE_H
#define PROJEKT_1_FILE_PREPARE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <random>
#include <iomanip>
#include <vector>
#include "dynamic_array.h"

#define TESTS   1000000

class FilePrepare
{
public:

    //Dynamic_array testData;
    std::vector<int> testData;
    bool fileRead;
    int n;
    int choice = 0;

    FilePrepare();
    void readData();
    void loadData();

};


#endif //PROJEKT_1_FILE_PREPARE_H
