#ifndef PROJEKT_1_LIST_H
#define PROJEKT_1_LIST_H

#include <iostream>
#include <vector>
#include "file_prepare.h"


struct Element{       //struktura, która tworzy elementy posiadające wskaźnik na element następny i poprzedni - tak jak to się dzieje w liście
    int data;        //zmienna odpowiadająca za przechowywanie wartości danego elementu
    Element* next;
    Element* previous;

    Element()
    {
        next = NULL;
        previous = NULL;
    }
};

class Lista
{
public:

    Element* head = new Element; //tworzymy element, który będzie początkiem naszej listy
    Element* tail = new Element;//tworzymy element, który będzie końcem naszej listy
    int size;


    Lista(); //Konstruktor

    ~Lista(); //Dekonstruktor

    void pushFront(int value); //funkcja odpowiadająca za dodanie elementu na przód listy

    void pushBack(int value); //funkcja odpowiadająca za dodanie elementu na tył listy

    void pushPosition(int value, int position); //funkcja odpowiadająca za dodanie elementu na dowolną pozycję listy

    void popFront(); //funkcja odpowiadająca za usunięcie elementów z przodu listy

    void popBack(); //funkcja odpowiadająca za usunięcie elementów z tyłu listy

    void popPosition(int position); //funkcja odpowiadająca za usunięcie elementów z tyłu listy

    void showFront(); //funkcja odpowiadająca za wyświetlenie elementów od początku listy

    void showBack(); //funkcja odpowiadająca za wyświetlenie elementów od końca listy

    int showPosition(int pos);

    int position(int value);

    int listSize();

    void swap(int pos1, int pos2);
};

#endif //PROJEKT_1_LIST_H
