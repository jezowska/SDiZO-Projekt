#include "file_reader.h"

using namespace std;

void FileReader::getFileName() {
    cout << "Wpisz nazwe pliku txt (nie wpisuj rozszerzenia)" << endl;
    cin >> file_name;
}

void FileReader::readFile() {

    getFileName();
    ifstream we;
    file_name.append(".txt");
    we.open(file_name);
    int x;
    we >> num_v;
    we >> num_e;
    we >> v_start;
    we >> v_end;

    while (we) {
        we >> x;
        vert.push_back(x);
        we >> x;
        vert2.push_back(x);
        we >> x;
        weigh.push_back(x);
        n++;
    }
}


FileReader::~FileReader() {
    vert.clear();
    vert2.clear();
    weigh.clear();
}
