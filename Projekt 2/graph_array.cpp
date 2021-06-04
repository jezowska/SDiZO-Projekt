#include "graph_array.h"

using namespace std;

GraphArray::GraphArray(int v, int e) 
{
    n = v;
    size = e;
    cost = 0;

    //tworzenie tablic ze wskaznikow zadeklarowanych w pliku naglowkowym
    d = new int[n];
    p = new int[n];
    key = new int[n];
    pp = new int[n];
    graph = new int* [n];
    inQ = new bool[n];

    for (int i = 0; i < n; i++) 
    {
        //tworzymy tablicê dwuwymiarow¹
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) 
        {
            //tworzymy tablicê dwuwymiarow¹
            graph[i][j] = 0;
        }
        inQ[i] = true;
    }
}

void GraphArray::add(int v, int u, int e) 
{
    if (e <= 0) 
    {
        cout << "Waga powinna byc dodatnia" << endl;
        return;
    }

    graph[v][u] = e;
    graph[u][v] = -e;  //dodanie ujemnej krawedzi, aby rozpoznac graf skierowany, ale takze przy mst moc zrobic abs i aby graf byl czytany jako nieskierowany
}

void GraphArray::print() 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << graph[i][j] << "  ";
            if (graph[i][j] < 10) cout << " ";
        }
        cout << endl;
    }
}

void GraphArray::print2() 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {

            cout << abs(graph[i][j]) << "  ";
            if (graph[i][j] < 10) cout << " ";
        }
        cout << endl;
    }
}

void GraphArray::dijkstra(int start) 
{
    priority_queue<Pii, Vii, greater<Pii>> Q; //do kolejki dodajemy co ma byc kolejce, na jakiej konstrukcji budowana jest kolejka i typ sortowania

    for (int i = 0; i < n; i++) //uzupelniamy tablice d i p odpowiednio najwiekszym intem i najmniejszym - zeby zapobiec zlemu dzialaniu algorytmu
    {
        d[i] = INT_MAX;
        p[i] = NULL;
    }
    d[start] = 0;
    p[start] = start;
    Q.push(make_pair(d[start], start)); //wrzucamy na kolejke nasz wierzcholek startowy i jego droge do samego siebie (0) 

    while (!Q.empty()) 
    {
        int u = Q.top().second; // pobieramy z gory kolejki wierzcholek o najmniejszym d 
        Q.pop();//usuwamy pare z kolejki

        for (int i = 0; i < n; i++) 
        {
            // szukamy polaczenia z innym wierzcholkiem, a nastepnie 
            //pobieramy numer i wage krawedzi miedzy naszym pobranym z kolejki wierzcholkiem i 

            int w = graph[u][i];
            int distance = w + d[u];

            if (w > 0 && d[i] > distance)  //sprawdzamy czy nasza krawedz istnieje 
                //i czy droga do poprzedniego wiercholka i waga krawedzi miedzy poprzednim, a aktualnym jest mniejsza niz dotychczasowa droga do danego wierzcholka
            {
                d[i] = distance; //zmieniamy dotychczasowa droge
                p[i] = u; // poprzedni wierzcholek ustawiamy na aktualny

                Q.push(make_pair(d[i], i));  // wrzucamy nasza nowa pare do kolejki
            }
        }
    }

    print_dijkstra(start);
}

void GraphArray::print_dijkstra(int start) 
{
    vector<int> path;
    cout << "End  Dist  Path" << endl;

    for (int i = 0; i < n; i++) 
    {
        int x = i;
        if (d[i] != INT_MAX) //sprawdzamy czy zaszly zmiany w naszej drodze i czy istnieje polaczenie do danego wierzcholka z wierzcholka startowego
        {
            cout << i << "  | " << d[i] << "  | ";
            
                x = p[x];
                path.push_back(x);

                while (x != start) 
                {
                    //chodzimy po tablicy p i szukamy poprzednikow, aby ustalic sciezke z wierzcholka startowego
                    
                    if (p[x] != INT_MIN)
                    {
                        x = p[x];
                        path.push_back(x);
                    }
                }

                while (!path.empty()) 
                {
                    cout << path.back() << " ";
                    if (path.back() < 10) cout << " ";
                    path.pop_back();

                }

                cout << i << endl;
            }
    }
    cout << endl;
}


void GraphArray::prim(int start) 
{
    priority_queue<Pii, Vii, greater<Pii>> Q; //do kolejki dodajemy co ma byc kolejce, na jakiej konstrukcji budowana jest kolejka i typ sortowania
    cost = 0;
    for (int i = 0; i < n; i++) 
    {
        key[i] = INT_MAX;
        p[i] = NULL;
        inQ[i] = true;
    }

    key[start] = 0;
    p[start] = 0;
    Q.push(make_pair(key[start], start)); //wrzucamy wierzcholek do kolejki

    while (!Q.empty()) 
    {
        int u = Q.top().second; //pobieramy wierzcholek z kolejki
        inQ[u] = false; //zaznaczamy, ze dany wierzcholek zostal odwiedzony
        Q.pop();

        for (int i = 0; i < n; i++) 
        {
            // szukamy polaczenia z innym wierzcholkiem, a nastepnie 
            //pobieramy numer i wage krawedzi miedzy naszym pobranym z kolejki wierzcholkiem i wierzcholkiem i 
\
            int w = abs(graph[u][i]);
            if (w > 0) 
            {
                if (inQ[i] == true && w < key[i]) 
                {
                    //jesli wierzcholek jest w kolejce i nasza waga jest mniejsza niz dotychczasowo ustalona roboczo waga 
                    //to zmieniamy wage i poprzedni wierzcholek
                    key[i] = w;
                    p[i] = u;
                    
                    Q.push(make_pair(key[i], i)); //wrzucamy nasz wierzcholek do kolejki
			
                }
            }
        }
    }
    print_prim();

}

void GraphArray::print_prim() 
{
    cout << "V  U  Cost" << endl;
    for (int i = 1; i < n; i++)
    {
        if (key[i] != INT_MAX)
        {
            cout << p[i] << "  " << i << "  " << key[i] << endl;
            cost += key[i];
        }
    }
    cout << "MST = " << cost << endl;
}

GraphArray::~GraphArray() {
    delete d;
    delete p;
    delete pp;
    delete key;
    delete graph;
}