#include <iostream>
#include "dynamic_array.h"
#include "heap.h"

Heap::Heap() //konstruktor - ustawiamy wielkość naszego kopca na 0
{
    size = 0;
    push(INT_MAX); //na miejsce 0 wstawiamy największą wartość
}

Heap::~Heap() {} //destruktor

void Heap::push(int number) //dodawanie nowej liczby do kopca
{
    size++; //zwiększamy wielkość naszego kopca o 1 przy każdorazowym dodaniu nowego elementu
    kopiec.push_back(number); //korzystając z wcześniej stworzonej tablicy dynamicznej dodajemy nowy element

    int position = size - 1;

    while (position > 1) //while porządkujący nasz kopiec
    {
        if (kopiec.array[position / 2] < kopiec.array[position])  //jeśli dziecko, jest większe od rodzica, wtedy zamieniay je miejscami
        {
            kopiec.swap(position / 2, position);
            position = position / 2;
        } else break;
    }
}

void Heap::rmv() {

    if (size == 0) {
        return;

    } else if (size == 1) {
        kopiec.pop_back();

    } else {
        kopiec.swap(1, size);

        int position = 1;

        while (position * 2 < size) {
            int child = position * 2;

            if (child != size - 1) {
                if (child < child + 1) {
                    child++;
                }
            }
            if (child > position) {
                kopiec.swap(child, position);
                position = child;
            } else {
                break;
            }
        }
        size = size - 1;
    }
}

void Heap::show() //Wyświetlanie kopca
{
    int n = 1;

    for (int i = 1; i < size; i++) {

        if ((n & (n - 1)) == 0) //aby czytelniej wypisać kopiec sprawdzamy czy wyświetlilismy ilosc elementow, ktore sa potegami dwojki, jesli sa to dodajemy nowa linie, ktora ma byc kolejnym poziomem
        {
            std::cout << std::endl;
        }

        std::cout << kopiec.array[i] << " ";
        n++;

    }
    std::cout << std::endl;
}

bool Heap::search(int value)
{
    bool val = false;

    for(int i = 0; i < kopiec.size; i++)
    {
        if(kopiec.array[i] == value)
        {
            val = true;
            break;
        }
    }

    return val;

}

