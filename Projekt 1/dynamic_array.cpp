
#include <iostream>
#include "dynamic_array.h"

Dynamic_array::Dynamic_array()
{
    array = nullptr;
    size = 0;
}

Dynamic_array::~Dynamic_array()
{
    delete array;
}

void Dynamic_array::push_front(int value)
{

    int* new_array = new int[size + 1];
    new_array[0] = value;

    for(int i = 0; i < size; i++)
    {
        new_array[i+1] = array[i];
    }

    delete array;
    array = new_array;
    size++;

}

void Dynamic_array::push_back(int value)
{

    int* new_array = new int[size + 1];
    new_array[size] = value;


    for(int i = 0; i < size - 1; i++)
    {
        new_array[i] = array[i];
    }

    delete array;
    array = new_array;
    size++;

}

void Dynamic_array::push_position(int value, int position) //metoda dodająca nowy element do tablicy w dowolnym miejscu
{
    if(position < 0 )
    {
        std::cout<<" Nie ma pozycji ujemnej, element zostanie wstawiony na początek listy. "<<std::endl;
        push_front(value);
    }
    else {
        int *new_array = new int[size + 1];  //tworzymy nową tablicę o wielkości + 1
        new_array[position] = value;

        for (int i = 0; i < position; i++)  //przechodzimy przez tablice i przepisujemy do nowej wartości starej
        {
            new_array[i] = array[i];

        }

        for (int i = position + 1; i < size + 1; i++) //aby nie zastąpić naszego nowego elementu starym, i = position +1
        {
            new_array[i] = array[i - 1];          //z tego samego powodu co wyżej przepisujemy array[i-1]

        }

        delete array;
        array = new_array;
        size++;
    }
}

void Dynamic_array::pop_back() //metoda usuwająca ostatni element tablicy
{

    int* help = new int[size-1];

    for(int i = 0; i < size-1; i++) //przechodzimy i przepisujemy wartości starej tablicy do nowej
    {
        help[i] = array[i];
    }

    delete array;    //usuwamy starą tablicę zawierającą element, którego chcemy się pozbyć
    array = help;    //zastępujemy ja nową tablicą, bez tego elementu
    size--;
}

void Dynamic_array::pop_front() //metoda usuwająca pierwszy element tablicy
{

    int *help = new int[size - 1];

    //std::cout<<"f"<<std::endl;

    for (int i = 0; i < size - 1; i++)
    {
        help[i] = array[i + 1];

    }

    delete array;  //usuwamy starą tablicę zawierającą element, którego chcemy się pozbyć
    array = help;  //zastępujemy ja nową tablicą, bez tego elementu
    size--;

}

void Dynamic_array::pop(int position)
{
    if(position < 0)
    {
        std::cout << " Nie ma ujemnej pozycji. Zostanie usunięty element pierwszy" << std::endl;
        pop_front();
    }
    else if(position >= size)
    {
        pop_back();
    }
    else
    {
        int *help = new int[size - 1];

        for (int i = 0; i < position - 1; i++) //przepisujemy wartości starej tablicy do nowej do naszego elementu, który chcemy usunąć
        {
            help[i] = array[i];
        }
        for (int i = position; i < size - 1; i++) //tutaj pomijamy nasz element na pozycji position i przepisujemy pozostałe elementy do nowej tablicy
        {
            help[i] = array[i + 1];
        }

        delete array;  //usuwamy starą tablicę zawierającą element, którego chcemy się pozbyć
        array = help;  //zastępujemy ja nową tablicą, bez tego elementu
        size--;        //zmniejszamy rozmiar tablicy
    }
}

void Dynamic_array::show()
{
    for(int i = 0; i < size; i++)
    {
        std::cout<<array[i]<<" ";
    }
    std::cout << std::endl;
}

void Dynamic_array::swap(int x, int y)
{
   int* help = new int[1];

   help[0] = array[x];
   array[x] = array[y];
   array[y] = help[0];

   delete help;
}

int Dynamic_array::position(int value) //wyszukiwanie elementu w tablicy
{
    int pos = -1 ;

    for(int i = 0; i < size; i++)
    {
        if(array[i] == value)
        {
            pos = i;
            break;
        }
    }

    return pos;
}