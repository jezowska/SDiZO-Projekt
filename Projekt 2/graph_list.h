#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> Pii;
typedef vector<Pii> Vii;

class GraphList {
public:
    vector<Vii> graph; //lista sasiedztwa zrobiona na wektorze wektora pary, aby moc przechowywac na jednej pozycji wierzcholek docelowy oraz wage krawedzi
    int n;
    int* d; //distance
    int* p; //previous
    int* pp;
    int cost; //koszt - przy MST
    int* key; // waga krawedzi przy MST
    bool* inQ;

    GraphList(int size);
    ~GraphList();

    void add(int v, int u, int e);

    void print();

    void dijkstra(int start);
    void print_dijkstra(int start);

    void prim(int start);
    void print_prim();
};