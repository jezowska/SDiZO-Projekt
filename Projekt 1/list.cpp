/*
 * W tym pliku definujemy funkcje naszej listy dwukierunkowej
 */

#include <iostream>
#include "list.h"

Lista::Lista() //konstruktor klasy Lista
{
    head = NULL;  //nie znamy jeszcze pierwszego elementu naszej listy, więc ustawiamy go na NULL
    tail = NULL; //tak jak w przypadku pierwszego elementu naszej listy, ostatniego też nie znamy więc ustawiamy go na NULL
}

Lista::~Lista() //dekonstruktor klasy Lista
{
    delete head; //nie potrzebujemy już więcej naszej list, więc usuwamy wskaźniki i zwalniamy pamięć
    delete tail;
}

void Lista::pushFront(int value) //funkcja, która ma za zadanie dodać element na początek listy
{

    Element *newHead = new Element;

    if (head == NULL)        //sprawdzamy czy nasza lista jest pusta
    {                       //  jeśli jest pusta to nasz element staje się pierwszy elementem listy
        head = newHead;
        tail = newHead;
        head->data = value;
        head->previous = NULL;
        head->next = NULL;
    } else                    //w innym wypadku musimy wstawić naszą nową wartość na początek
    {
        newHead->data = value;
        newHead->next = head;
        newHead->previous = NULL;           //jako że nowy element ma być na początku to nie posiada poprzednika, więc poprzednika ustawiamy na null
        head->previous = newHead;           //poprzednika naszej starej głowy ustawiamy na nasz nowy element
        head = newHead;                     //ustawiamy naszą głowę, pierwszy element na nowy element
        if (newHead->next !=
            NULL)           //jeśli nasza lista ma więcej niż jeden element to na poprzedni element naszego następnego elementu ustawiamy nasz nowy element
            newHead->next->previous = newHead;
        else                                //jeśli natomiast nie ma więcej elementów w liście to ogonem staje się nasz nowy element
            tail = newHead;
    }
    size++;
    //std::cout << value << std::endl;
}

void Lista::pushBack(int value)  //funkcja, która ma za zadanie dodać element na koniec listy
{
    Element *newTail = new Element;

    if (head == NULL)            // sprawdzamy czy nasza lista jest pusta
    {                           //jeśli jest pusta to ustawiamy nasz element jako początek i koniec listy jednocześnie
        head = newTail;
        head->data = value;
        head->previous = NULL;
        head->next = NULL;
        tail = head;
    } else                        //jeśli nasza lista nie jest pusta to ustawiamy nasz element na koniec listy
    {
        newTail->data = value;
        tail->next = newTail;        //ustawiamy nasz nowy ostatni element na następny element naszego starego ostatniego elementu
        newTail->previous = tail;    //poprzednim elementem naszego nowego ogona staje się nasz stary ogon
        newTail->next = NULL;
        tail = newTail;              //ustawiamy nasz ogon na nasz nowy ogon
    }
    size++;
}

void
Lista::pushPosition(int value, int position)      //funkcja, która ma za zadanie dodać element na dowolne miesjce listy
{

    if (head == NULL)                        // sprawdzamy czy nasza lista jest pusta
    {                                       //jeśli jest pusta to ustawiamy nasz element jako początek i koniec listy jednocześnie
        Element *newHead = new Element;
        head = newHead;
        head->data = value;
        head->previous = NULL;
        head->next = NULL;
        tail = head;
    } else                                    //jeśli nasza lista nie jest pusta to musimy dotrzeć do elementu na danej pozycji
    {
        Element *current = new Element;
        current = head;

        for (int i = 0; i < position - 1; i++) //idziemy do elementu na poprzedniej pozycji
        {
            if (current->next ==
                NULL)       //jeśli dostarliśmy do końca listy to wychodzimy z pętli i nasz element zostaje umieszczony na końcu listy
            {
                break;
            }

            current = current->next;
        }

        if (current->next ==
            NULL) //jeśli nie ma następnego elementu to znaczy, że musimy wstawić naszą wartość na koniec
        {
            pushBack(value);
        } else                      //w innym wypadku wstawiamy nasz element na daną pozycję
        {
            Element *middle = new Element;
            middle->data = value;
            middle->next = current->next;   //musimy ustawić następny element naszego nowego elementu na następny element poprzedniego elementu na danej pozycji
            current->next->previous = middle; //poprzedni element następnego elementu ustawiamy na na
            middle->previous = current;     //to samo robimy z poprzednim elementem
            current->next = middle;         //ustawiamy nasz nowy element jako następny element naszego poprzedniego elementu

        }
    }
    size++;
}

void Lista::popFront() {
    if (head == NULL) //sprawdzamy czy pierwszy element istnieje, jeśli nie to nie ma czego usuwać
        return;

    Element *p = new Element;
    p = head;


    if (p->next == NULL) {
        delete p;
        return;
    }

    head = head->next;
    head->previous = NULL;
    size--;
    delete p; //zwalnianie miejsca w pamięci

}

void Lista::popBack() {
    if (head == NULL) //sprawdzamy czy pierwszy element istnieje, jeśli nie to nie ma czego usuwać
        return;

    Element *p = new Element;
    p = tail;

    if (tail->previous == NULL) {
        delete tail;
    } else {

        tail = tail->previous; //ustawiamy nasz ogon na poprzedni element
        tail->next = NULL;      //ustawiamy element następny na NULL, ponieważ nie ma już kolejnego elementu

        delete p; //zwalnianie miejsca w pamięci
    }
    size--;
}

void Lista::popPosition(int position) {

    if (head == NULL) { //sprawdzamy czy pierwszy element istnieje, jeśli nie to nie ma czego usuwać
        return;
    }
    if(position >= size)
    {
        popBack();
    }
    else if(position == 0 )
    {
        popFront();
    }

    Element *current = new Element;
    current = head;

    if(position == 1 )
    {
        current->next->previous = head;
        head->next = current->next;
    }
    else {

        for (int i = 0; i < position; i++) //idziemy do elementu na poprzedniej pozycji
        {
            if (current->next == NULL)       //jeśli dostarliśmy do końca listy to wychodzimy z pętli i nasz element zostaje umieszczony na końcu listy
            {
                delete current; //zwalnianie miejsce w pamięci
                return;
            }
            current = current->next;
        }

        if (current->next == NULL)       //jeśli dostarliśmy do końca listy to wychodzimy z pętli i nasz element zostaje umieszczony na końcu listy
        {
            delete current; //zwalnianie miejsce w pamięci
            return;
        }

        current->previous->next = current->next; //ustawiamy następny element elementu poprzedniego na nasz akturalny następny
        current->next->previous = current->previous; //ustawiamy poprzedni elemnt kolejnego elementu na aktualny poprzedni element

        size--;

        delete current; //zwalniamy miejsce w pamięci
    }
}

void Lista::showFront() //wyswietlanie tablicy od przodu
{
    Element *current = new Element;
    current = head;

    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;

    delete current; //zwalnianie miejsce w pamięci
}

void Lista::showBack() //wyswietlanie tablicy od tylu
{
    Element *current = new Element;
    current = tail;

    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->previous;
    }

    std::cout << std::endl;

    delete current; //zwalnianie miejsce w pamięci
}

int Lista::listSize() {

    int x;

    if (head == NULL)
        return 0;

    else {
        Element *help = new Element;
        help = head;

        x = 0;

        while (help->next != NULL) {
            x++;
            help = help->next;
        }
        x++;

        return x;
    }
}


int Lista::showPosition(int pos) {
    Element *element = new Element;
    element = head;

    for (int i = 0; i < pos - 1; i++) {
        element = element->next;
    }

    return element->data;
}

int Lista::position(int value) {
    Element *element = new Element;
    element = head;
    int pos = -1;
    int help = 0;

    while (element->next != NULL) {
        help++;
        if(element->data == value)
        {
            pos = help;
            break;
        }
        element = element->next;
    }

    return pos ;
}

