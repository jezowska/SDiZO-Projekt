#include "console.h"

void Message::show() {

    Prepare prepare;

    while (!prepare.isFileLoaded) //sprawdzanie czy został załadowany plik i oczekiwanie na jego załadowanie
    {
        fileMessage();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                prepare.readFileData();
                break;
            }
            case 2: {
                prepare.createFileData();
                prepare.readFileData();
                break;
            }
            default: {
                return;
            }
        }
    }

    mainMessage(); // Wyswietlanie menu glownego
    std::cin >> choice;

    switch (choice)  // Wybor akcji z menu
    {
        case 1: //Wybor nr 1 - wybranie struktury do testow
        {
            structuresMessage();
            std::cin >> choice;

            switch (choice) //Wybor struktury
            {

                case 1: //Wybor tablicy dynamicznej
                {
                    arrayMessage();

                    std::cin >> choice;

                    //tablica dodawanie na koniec pozycje
                    if (choice == 1) {
                        prepare.array_push_back();
                    }

                    //tablica dodawanie na poczatek pozycje
                    if (choice == 2) {
                        prepare.array_push_front();
                    }

                    //tablica dodawanie na poszczegolna pozycje
                    if (choice == 3) {
                        prepare.array_push_position();
                    }

                    //tablica usuwanie od końca
                    if (choice == 4) {
                        prepare.array_pop_back();
                    }

                    //tablica usuwanie od poczatku
                    if (choice == 5) {
                        prepare.array_pop_front();
                    }

                    //tablica usuwanie z danej pozycji
                    if (choice == 6) {
                        prepare.array_pop_position();
                    }

                    //wyswietlania elementow tablicy
                    if (choice == 7) {
                        prepare.array_show();
                    }
                    if (choice == 8) {
                        prepare.array_serach();
                    }

                    break;

                }

                case 2:  //Wybor listy dwukierunkowej
                {
                    listMessage();
                    std::cin >> choice;

                    switch (choice) //Menu listy dwukierunkowej
                    {
                        case 1: //Dodawanie elementow na koniec listy
                        {
                            prepare.list_push_back();
                            break;
                        }

                        case 2: //Dodawanie elementow na poczatek listy
                        {
                            prepare.list_push_front();
                            break;
                        }

                        case 3: //Dodawanie elementow na dana pozycje listy
                        {
                            prepare.list_push_position();
                            break;
                        }

                        case 4: //Usuwanie elementow z konca listy
                        {
                            prepare.list_pop_back();
                            break;
                        }
                        case 5: //Usuwanie elementow z poczatku listy
                        {
                            prepare.list_pop_front();
                            break;
                        }
                        case 6: //Usuwanie elementow z danej pozycji listy
                        {
                            prepare.list_pop_position();
                            break;
                        }
                        case 7: //Wyswietlanie listy
                        {
                            prepare.list_show();
                        }
                        case 8: //szukanie elementów w liście
                        {
                            prepare.list_search();
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case 3:  //Wybor kopca binarnego
                {
                    heapMessage();
                    std::cin >> choice;
                    switch (choice) {
                        case 1: //Ładowanie kopca
                        {

                            prepare.heap_load();
                            break;
                        }
                        case 2: //Usuwanie kopca
                        {

                            prepare.heap_pop();
                            break;
                        }
                        case 3: //Wyświetlanie kopca
                        {
                            prepare.heap_show();
                        }
                        case 4: //Wyszukiwanie czy element jest w kopcu
                        {
                            prepare.heap_search();
                        }
                        default: //Wyjście z menu kopca
                        {
                            break;
                        }
                    }
                    break;
                }
                default: {
                    break;
                }
            }
            break;
        }
        default: {
            return;
        }
    }
}


void Message::fileMessage() //Menu dotyczace wczytywania/tworzenia pliku
{
    std::cout
            << "1 - Wczytanie pliku txt z danymi do testu (plik powinien miec nazwe test.txt, a pierwsza liczba byc liczba wskazujaca na ilosc pozostalych liczb w pliku)"
            << std::endl;
    std::cout << "2 - Stworzenie pliku z danymi do testu" << std::endl;
    std::cout << "Wybierz inna liczbe, aby wyjsc" << std::endl;
}

void Message::mainMessage() //Menu dotyczace wyboru strukry do testu lub wyjścia
{
    std::cout << "1 - Wybor struktury i test" << std::endl;
    std::cout << "Wybierz inna liczbe, aby wyjsc" << std::endl;
}

void Message::structuresMessage() //Menu wyboru struktur
{
    std::cout << "1 - Tablica dynamiczna" << std::endl;
    std::cout << "2 - Lista dwukierunkowa" << std::endl;
    std::cout << "3 - Kopiec" << std::endl;
    std::cout << "Aby wyjsc wybierz inna liczbe" << std::endl;
}

void Message::arrayMessage() //Menu tablicy dynamicznej
{
    std::cout << "1 - Dodanie liczby do tablicy od tylu" << std::endl;
    std::cout << "2 - Dodanie liczby do tablicy od przodu" << std::endl;
    std::cout << "3 - W dowolne miejsce (w tym wypadku domyslnie ustawiane jest na n miejse)"
              << std::endl;
    std::cout << "4 - Usuniecie ostatniego elementu" << std::endl;
    std::cout << "5 - Usuniecie pierwszego elementu" << std::endl;
    std::cout << "6 - Usuniecie dowolnego elementu" << std::endl;
    std::cout << "7 - Wyswietlenie tablicy" << std::endl;
    std::cout << "8 - Wyszukiwanie elementu" << std::endl;
    std::cout << "Aby powrocic do menu glownego wpisz jakakolwiek inna liczbe " << std::endl;
}

void Message::listMessage() //Menu listy dwukierunkowej
{
    std::cout << "1 - Dodanie liczby do listy od tylu" << std::endl;
    std::cout << "2 - Dodanie liczby do listy od przodu" << std::endl;
    std::cout << "3 - Dodanie liczby w dowolne miejsce (w tym wypadku domyslnie ustawiane jest na n miejse)"
              << std::endl;
    std::cout << "4 - Usuniecie ostatniego elementu" << std::endl;
    std::cout << "5 - Usuniecie pierwszego elementu" << std::endl;
    std::cout << "6 - Usuniecie dowolnego elementu (w tym wypadku domyslnie ustawiane jest na n miejsce)" << std::endl;
    std::cout << "7 - Wyswietlenie listy" << std::endl;
    std::cout << "8 - Wyszukiwanie elementu" << std::endl;
    std::cout << "Aby powrocic do menu glownego wpisz jakakolwiek inna liczbe " << std::endl;
}

void Message::heapMessage() //Menu kopca
{
    std::cout << "1 - Budowanie kopca" << std::endl;
    std::cout << "2 - Usuwanie pierwszego elementu kopca" << std::endl;
    std::cout << "3 - Wyswietlanie kopca" << std::endl;
    std::cout << "4 - Sprawdzanie czy element znajduje się w kopcu" << std::endl;
    std::cout << "Aby powrocic do menu glownego wpisz jakakolwiek inna liczbe" << std::endl;
}
