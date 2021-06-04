#pragma once
#include "graph_array.h"
#include "graph_list.h"
#include "file_reader.h"
#include "menu.h"
#include <random>
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

long long int read_QPC() 
{ 
    LARGE_INTEGER count;   
    QueryPerformanceCounter(&count); 
    return((long long int)count.QuadPart); 
}

int main() 
{
    Menu menu;

    menu.show();

    return 0;
}
