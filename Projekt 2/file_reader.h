#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <Windows.h>
#include <ctime>
using namespace std;

class FileReader {
public:
    vector<int> vert;
    vector<int> vert2;
    vector<int> weigh;
    int num_v;
    int num_e;
    int v_start;
    int v_end;
    int n;
    bool isFileReaded;
    string file_name;

    FileReader()
    {
        num_v = 0;
        num_e = 0;
    }

    ~FileReader();
    void getFileName();
    void readFile();

};