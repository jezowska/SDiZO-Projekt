#include "menu.h"

void Menu::mainMessage()
{
    cout << "1. Wczytanie danych z pliku" << endl;
    cout << "2. Algorytm Dijkstry - macierz sasiedztwa" << endl;
    cout << "3. Algorytm Dijkstry - lista sasiedztwa" << endl;
    cout << "4. Algorytm Prima - macierz sasiedztwa" << endl;
    cout << "5. Algorytm Prima - lista sasiedztwa" << endl;
    cout << "6. Wyswietlanie grafu - macierz sasiedztwa" << endl;
    cout << "7. Wyswietlanie grafu skierowanego - macierz sasiedztwa" << endl;
    cout << "8. Wyswietlanie grafu  - lista sasiedztwa" << endl;
    cout << "9. Koniec" << endl;
    cout << "Wybor: ";
    cin >> choice;
}

void Menu::fileMessage()
{
    fileReader.readFile();
}

void Menu::show()
{
    fileMessage();
    GraphArray graphArray(fileReader.num_v, fileReader.num_e);
    GraphList graphList(fileReader.num_v);

    while (true)
    {
        mainMessage();

        switch (choice)
        {
            case 1:
            {
                system("cls");

                for (int i = 0; i < fileReader.num_e; i++)
                {
                    graphList.add(fileReader.vert[i], fileReader.vert2[i], fileReader.weigh[i]);
                    graphArray.add(fileReader.vert[i], fileReader.vert2[i], fileReader.weigh[i]);
                }

                break;
            }

            case 2:
            {
                system("cls");

                graphArray.dijkstra(fileReader.v_start);
                break;
            }
            case 3:
            {
                system("cls");

                graphList.dijkstra(fileReader.v_start);
                break;
            }
            case 4:
            {
                system("cls");

                graphArray.prim(fileReader.v_start);
                break;
            }
            case 5:
            {
                system("cls");

                graphList.prim(fileReader.v_start);
                break;
            }
            case 6:
            {
                system("cls");

                graphArray.print2();
                break;
            }
            case 7:
            {
                system("cls");

                graphArray.print();
                break;
            }
            case 8:
            {
                system("cls");

                graphList.print();
                break;
            }
            case 9:
            {
                system("cls");

                return;
                break;
            }
            default:
            {
                system("cls");

                return;
                break;
            }
        }
    }
}

