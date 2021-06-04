#include "structure_prepare.h"

Message message;
FilePrepare newFile;
Dynamic_array dynamic_array;
Lista list;
Heap heap;

void Prepare::array_push_back()  //testowanie ile zajmie wczytanie n elementow na koniec tablicy
{
    start = read_QPC(); //rozpoczynamy liczenie czasu

    for (int i = 0; i < newFile.n; i++) //newFile.n to ilośc elementow do przetestowania na tablicy
    {
        dynamic_array.push_back(newFile.testData[i]);
    }

    passedTime = read_QPC() - start; //kończymy liczenie czasu


    std::cout << "W przypadku dodawania od tylu " << newFile.n
              << " elementow, utworzenie tablicy dynamicznej zajmuje " << std::setprecision(5)
              << (1000.0 * passedTime) / frequency << " ms" << std::endl;

    array_pop_without_message();
}

void Prepare::array_push_front() //testowanie ile zajmie wczytanie n elementow na początek tablicy
{
    start = read_QPC(); //rozpoczynamy liczenie czasu

    for (int i = 0; i < newFile.n; i++) //newFile.n to ilośc elementow do przetestowania na tablicy
    {
        dynamic_array.push_front(newFile.testData[i]);
    }

    passedTime = read_QPC() - start;

    std::cout << "W przypadku dodawania od przodu " << newFile.n
              << " elementow, utworzenie tablicy dynamicznej zajmuje " << std::setprecision(5)
              << (1000.0 * passedTime) / frequency << " ms" << std::endl;

    array_pop_without_message();

}

void Prepare::array_push_position() //testowanie ile zajmie wczytanie n elementow do środka tablicy
{
    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        dynamic_array.push_position(newFile.testData[i], dynamic_array.size/2);
    }

    passedTime = read_QPC() - start;

    std::cout << "W przypadku dodawania " << newFile.n
              << " elementow, utworzenie tablicy dynamicznej zajmuje " << std::setprecision(5)
              << (1000.0 * passedTime) / frequency << " ms" << std::endl;

    array_pop_without_message();

}

void Prepare::array_pop_front() //testowanie ile zajmie usuniecie n elementow z początku tablicy
{
    array_push_without_message(); //dodajemy elementy do tablicy, aby moc zmierzyc czas ich usuwania

    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) //newFile.n to ilośc elementow do przetestowania na tablicy
    {
        dynamic_array.pop_front();
    }

    passedTime = read_QPC() - start;
    std::cout << "Usuwanie " << newFile.n
              << " elementow poprzez usuwanie pierwszego elementu wynosi"
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;
}

void Prepare::array_pop_back() //testowanie ile zajmie usuniecie n elementow z końca tablicy
{
    array_push_without_message(); //dodajemy elementy do tablicy, aby moc zmierzyc czas ich usuwania

    start = read_QPC();
    for (int i = 0; i < dynamic_array.size; i++) {
        dynamic_array.pop_back();
    }

    passedTime = read_QPC() - start;
    std::cout << "Usuwanie " << newFile.n
              << " elementow poprzez usuwanie ostatniego elementu wynosi "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;
}

void Prepare::array_pop_position() //testowanie ile zajmie usuniecie n elementow ze środka tablicy
{
    array_push_without_message();

    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        dynamic_array.pop(newFile.n);
    }

    passedTime = read_QPC() - start;
    std::cout << "Usuwanie " << newFile.n
              << " elementow poprzez usuwanie dowolnego elementu wynosi "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;

}

void Prepare::array_push_without_message() //Dodawanie elementow do tablicy bez liczenia czasu
{

    for (int i = 0; i <  newFile.n ; i++) {
        dynamic_array.push_back(newFile.testData[i]);
    }

}

void Prepare::array_pop_without_message() //Usuwanie elementow do tablicy bez liczenia czasu
{
    for (int i = 0; i < newFile.n; i++) {
        dynamic_array.pop_back();
    }
}

void Prepare::array_show() //Wyświetlanie tablicy
{
    array_push_without_message();

    start = read_QPC();

    dynamic_array.show();

    passedTime = start - read_QPC();

   // array_pop_without_message();

}

void Prepare::array_serach() //Szukanie elementu w tablicy
{
    array_push_without_message();

    int value;
    int pos;
    std::cout << "Podaj element, ktory ma zostac wyszukany." << std::endl;
    std::cin>>value;

    start = read_QPC();
    pos = dynamic_array.position(value);
    passedTime = read_QPC() - start;

    if( pos < 0 )
    {
        std::cout << "Danego elementu nie ma strukturze. Jej przeszukanie zajelo: " << passedTime << " ms" << std::endl;
    }
    else
    {
        std::cout << "Szykany element znajduje sie na " << pos << "pozycji. Jego znalezienie zajelo " << passedTime <<" ms."<<std::endl;
    }
}

void Prepare::list_push_front() //Dodawanie elementow do listy na jej początek
{
    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        list.pushFront(newFile.testData[i]);
    }

    passedTime = read_QPC() - start;

    std::cout << "W przypadku dodawania " << newFile.n
              << " elementow od przodu, utworzenie listy dwukierunkowej zajmuje "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;

    //list_pop_without_message();
}

void Prepare::list_push_back() //Dodawanie elementow do listy na jej koniec
{
    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        list.pushBack(newFile.testData[i]);
    }

    passedTime = read_QPC() - start;
    std::cout << "W przypadku dodawania " << newFile.n
              << " elementow od tylu, utworzenie listy dwukierunkowej zajmuje "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;

   // list_pop_without_message();
}

void Prepare::list_push_position() //Dodawanie elementow do listy na jej środek
{
    start = read_QPC();
    int pos = (newFile.n*0,5) + 1;
    for (int i = 0; i < newFile.n; i++) {
        list.pushPosition(newFile.testData[i], pos);
    }

    passedTime = read_QPC() - start;
    std::cout << "W przypadku dodawania " << newFile.n
              << " elementow poprzez dodanie na wybrane miejsce, utworzenie listy dwukierunkowej zajmuje "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;

    //list_pop_without_message();
}

void Prepare::list_push_without_message() //Dodawanie elementow do listy bez liczenia czasu
{
    for (int i = 0; i < newFile.n; i++) {
        list.pushBack(newFile.testData[i]);
    }
}

void Prepare::list_pop_without_message()  //Usuwanie elementow z listy bez liczenia czasu
{
    for (int i = 0; i < newFile.n; i++) {
        list.popBack();
    }
}

void Prepare::list_pop_front() // Usuwanie elementow z listy z początku
{
    list_push_without_message();

    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        list.popFront();
    }

    passedTime = read_QPC() - start;

    std::cout << "Usuwanie " << newFile.n
              << " elementow poprzez usuwanie pierwszego elementu zajelo  "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;
}

void Prepare::list_pop_back() // Usuwanie elementow z listy z końca
{

    list_push_without_message();

    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        list.popBack();
    }

    passedTime = read_QPC() - start;
    std::cout << "Usuwanie " << newFile.n
              << " elementow poprzez usuwanie ostatniego elementu zajelo  "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;
}

void Prepare::list_pop_position() // Usuwanie elementow z listy z polowy listy
{
    list_push_without_message();
    int pos = (newFile.n*0,5) + 1;

    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        list.popPosition(pos );
    }

    passedTime = read_QPC() - start;

    std::cout << "Usuwanie " << newFile.n
              << " elementow poprzez usuwanie dowolnego elementu zajelo  "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;
}

void Prepare::list_show() //Wyświetlanie listy
{
    list_push_without_message();

    list_message();
    std::cin>>x;

    switch(x) //wybieranie czy lista ma zostac wyswietlona od przodu czy od tylu
    {
        case 1:
        {
            list.showFront();
            break;
        }
        case 2:
        {
            list.showBack();
            break;
        }
        default:
        {
            break;
        }
    }

    list_pop_without_message();
}

void Prepare::list_message() {
    std::cout<<" 1 - Wyswietlanie listy od przodu" << std::endl;
    std::cout<<" 2 - Wyswietlanie listy od tylu" << std::endl;
    std::cout<<" Wybierz jakakolwiek liczbe, aby powrocic" << std::endl;
}

void Prepare::list_search()
{
    list_push_without_message();

    int value;
    int pos;
    std::cout << "Podaj element, ktory ma zostac znalezieni." << std::endl;
    std::cin>>value;

    start = read_QPC();
    pos = list.position(value);
    passedTime = read_QPC() - start;

    if( pos < 0 )
    {
        std::cout << "Danego elementu nie ma strukturze. Jej przeszukanie zajelo: " << passedTime << " ms" << std::endl;
    }
    else
    {
        std::cout << "Szukany element znajduje sie na " << pos << "pozycji. Jego znalezienie zajelo " << passedTime <<" ms."<<std::endl;
    }

}

void Prepare::heap_load() //ladowanie kopca
{
    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        heap.push(newFile.testData[i]);
    }

    passedTime = read_QPC() - start;
    std::cout << "W przypadku dodawania " << newFile.n
              << " elementow, utworzenie kopca zajmuje "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;

    heap_pop_without_message();
}

void Prepare::heap_load_without_message() //ladowania kopca bez liczenia czasu
{

    for (int i = 0; i < newFile.n; i++) {
        heap.push(newFile.testData[i]);
    }
}

void Prepare::heap_pop_without_message() //Usuwanie kopca bez liczenia czasu
{

    for (int i = 0; i < newFile.n; i++) {
        heap.rmv();
    }
}

void Prepare::heap_pop() //Usuwanie kopca
{

    heap_load_without_message();

    start = read_QPC();

    for (int i = 0; i < newFile.n; i++) {
        heap.rmv();
    }

    passedTime = read_QPC() - start;
    std::cout << "W przypadku usuwania " << newFile.n << " elementow, usuniecie kopca zajmuje "
              << std::setprecision(5) << (1000.0 * passedTime) / frequency << " ms"
              << std::endl;
}

void Prepare::heap_show() //Wyświetlanie kopca
{
    heap_load_without_message();

    heap.show();

    heap_pop_without_message();
}

void Prepare::heap_search()
{
    heap_load_without_message();
    int value;
    bool pos;

    std::cout << "Podaj element, ktory ma zostac wyszukany." << std::endl;
    std::cin>>value;

    start = read_QPC();
    pos = heap.search(value);
    passedTime = read_QPC() - start;

    if( pos == true)
    {
        std::cout << "Szukany element znajduje sie na w kopcu. Jego znalezienie zajelo " << passedTime <<" ms."<<std::endl;
    }
    else
    {
        std::cout << "Danego elementu nie ma strukturze. Jej przeszukanie zajelo: " << passedTime << " ms" << std::endl;
    }
}

void Prepare::readFileData() //Czytanie danych z pliku
{
    newFile.readData();
    isFileLoaded = true;
}

void Prepare::createFileData() //Tworzenie i ladowanie danych do pliku
{
    newFile.loadData();
    isFileLoaded = true;
}

long long int Prepare::read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int) count.QuadPart);
}


