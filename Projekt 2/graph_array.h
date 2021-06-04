#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> Pii;
typedef vector<Pii> Vii;

class GraphArray{
public:
    int n;
    int v_start;
    int v_end;
    int* d;
    int* p;
    int* pp;
    int cost;
    int* key;
    int** graph;
    int size;
    bool* inQ;
    int n_done;

    GraphArray(int v, int e);
    ~GraphArray();
    void add(int v1, int v2, int e);

    void print();
    void print2();

    void dijkstra(int start);
    void print_dijkstra(int start);

    void prim(int start);
    void print_prim();

    void bellman_ford(int start);
    void bellford_print(int start);


};