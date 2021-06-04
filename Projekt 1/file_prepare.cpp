#include "file_prepare.h"

FilePrepare::FilePrepare()
{
    fileRead = false;
}

void FilePrepare::loadData() {

    std::ofstream wynik;
    wynik.open("test.txt");

    int x = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000000);

    std::cout<< " Ile liczb ma zawierac plik?" << std::endl;
    std::cin>>x;
    wynik<<x<<std::endl;

    for(int i = 0; i < x; i++)
    {
        wynik<<dist(gen)<<std::endl;
    }

    wynik.close();

}
void FilePrepare::readData()
{
    std::ifstream input;
    input.open("test.txt");

    if(fileRead == false)
    {
        input>>n;
        int value = 0;

        for(int i = 0; i < n; i++)
        {
            input>>value;
            testData.push_back(value);
        }

        fileRead = true;
    }
    else
    {
        std::cout<<"Dane zostaly juz wczytane"<<std::endl;
    }

    input.close();
}





