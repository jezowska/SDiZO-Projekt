#include "graph_list.h"

GraphList::GraphList(int size) {
	n = size;
	cost = 0;
	//tworzenie tablic ze wskaznikow zadeklarowanych w pliku naglowkowym
	d = new int[n]; 
	p = new int[n];
	key = new int[n];
	pp = new int[n];
	graph.resize(n);
	inQ = new bool[n];
}

GraphList::~GraphList()
{
	delete d;
	delete p;
	delete pp;
	delete key;
	delete inQ;
	graph.clear();
}
void GraphList::add(int v, int u, int e) 
{

	if (e <= 0) 
	{
		cout << "Waga powinna byc dodatnia" << endl;
		return;
	}
	graph[v].push_back(make_pair(u, e)); 
	graph[u].push_back(make_pair(v, -e)); //dodanie ujemnej krawedzi, aby rozpoznac graf skierowany, ale takze przy mst moc zrobic abs i aby graf nie byl skierowany
}



void GraphList::print() // wypisywanie graf
{
	for (int i = 0; i < graph.size(); i++) 
	{
		for (auto g : graph[i]) 
		{
			if (g.second > 0) 
			{
				cout << i << " " << g.first << " " << g.second << endl;
			}
		}
	}
	cout << endl;
}



void GraphList::dijkstra(int start) 
{

	priority_queue<Pii, Vii, greater<Pii>> Q; //do kolejki Q dodajemy co ma byc kolejce (Pii - para), na jakiej konstrukcji budowana jest kolejka (Vii) i typ sortowania

	for (int i = 0; i < graph.size(); i++) //uzupelniamy tablice d i p odpowiednio najwiekszym intem i najmniejszym - zeby zapobiec zlemu dzialaniu algorytmu
	{
		d[i] = INT_MAX;
		p[i] = INT_MIN;
	}
	
	d[start] = 0; 
	p[start] = start;
	Q.push(make_pair(d[start], start)); //wrzucamy na kolejke nasz wierzcholek startowy i jego droge do samego siebie (0) 


	while (!Q.empty()) {
		int u = Q.top().second; // pobieramy z gory kolejki wierzcholek o najmniejszym d 
		Q.pop(); //usuwamy pare z kolejki

		for (int i = 0; i < graph[u].size(); i++) {
			
			// szukamy polaczenia z innym wierzcholkiem, a nastepnie 
			//pobieramy numer i wage krawedzi miedzy naszym pobranym z kolejki wierzcholkiem i 
			int v = graph[u][i].first; 
			int w = graph[u][i].second;

			if (w > 0 && d[v] > d[u] + w) //sprawdzamy czy nasza krawedz istnieje i czy droga do poprzedniego wiercholka i waga krawedzi miedzy poprzednim, a aktualnym jest mniejsza niz dotychczasowa droga do danego wierzcholka
			{
				
					d[v] = d[u] + w; //zmieniamy dotychczasowa droge
					p[v] = u; // poprzedni wierzcholek ustawiamy na aktualny
					Q.push(make_pair(d[v], v)); // wrzucamy nasza nowa pare do kolejki
				
			}
		}
	}

	print_dijkstra(start);
}

void GraphList::print_dijkstra(int start)
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
			int licznik = 0;

			while (x != start)
			{
				//chodzimy po tablicy p i szukamy poprzednikow, aby ustalic sciezke z wierzcholka startowego
				x = p[x]; 
				path.push_back(x);
			}

			while (!path.empty())
			{
				//wypisujemy nasza sciezke
				cout << path.back() << " ";
				if (path.back() < 10) cout << " ";
				path.pop_back();
			}

			cout << i << endl;
		}
		cout << endl;
	}
}

void GraphList::prim(int start) {
	priority_queue<Pii, Vii, greater<Pii>> Q; //do kolejki dodajemy co ma byc kolejce, na jakiej konstrukcji budowana jest kolejka i typ sortowania    
	cost = 0; //koszt drzewa ustawiamy na 0

	for (int i = 0; i < graph.size(); i++) //ustawiamy key na int max oraz pomocnicza tablice na true
	{
		key[i] = INT_MAX;
		inQ[i] = true;
	}

	key[start] = 0;
	p[start] = 0;

	for (int i = 0; i < graph.size(); i++)
	{
		//wrzucamy wierzcholki do kolejki
		Q.push(make_pair(key[i], i));
	}

	while (!Q.empty()) 
	{
		int u = Q.top().second; //pobieramy wierzcholek z kolejki
		inQ[u] = false; //zaznaczamy, ze dany wierzcholek zostal odwiedzony
		Q.pop();

		for (int i = 0; i < graph[u].size(); i++)
		{
			// szukamy polaczenia z innym wierzcholkiem, a nastepnie 
			//pobieramy numer i wage krawedzi miedzy naszym pobranym z kolejki wierzcholkiem i wierzcholkiem i 
			int v = graph[u][i].first;
			int w = abs(graph[u][i].second);

			if (inQ[v] == true && w < key[v]) 
			{
				//jesli wierzcholek jest w kolejce i nasza waga jest mniejsza niz dotychczasowo ustalona roboczo waga 
				//to zmieniamy wage i poprzedni wierzcholek
				key[v] = w;
				p[v] = u;

				Q.push(make_pair(key[v], v)); //wrzucamy nasz wierzcholek do kolejki
			}
		}
	}
	cout << "V  U  Cost" << endl;

	for (int i = 0; i < graph.size(); i++) 
	{
		if (key[i] != INT_MAX)
		{
			cout << p[i] << " " << i << " " << key[i] << endl;
			cost += key[i];
		}
		
	}
	cout << "MST = " << cost << endl;
}



