#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <unordered_map>
#include <string>

using namespace std;

const int oo = numeric_limits<int>::max();

void Dijkstra(int u, int v, vector<vector<int>> graph)
{
	queue<int> q;
	int V = graph.size();
	vector<int> distance(V, oo);
	vector<bool> visited(V, false);
	
	distance[u] = 0;
	q.push(u);
	
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		visited[current] = true;
		
		if (current == v)
		{
			cout << "El costo para llegar de " << u " a " << v << " es " /*<< algo */<< endl; 
		}
		
		for (int i = 0; i < V; i++)
		{
			if(!mark[i] && (distance[current] + graph[current][i]) < dist[graph[current][i]])
			{
				dist[graph[current][i]] = distance[current] + graph[current][i];
				q.push ///ESTE ÚLTIMO IF NO LO LOGRO REPLICAR AÚN
			}
		}
	}
	
	queue<State> pq; // La cola de prioridad.
	vector<int> Dist(graph.V, oo); // La distancia hacia todos los vertices. Inicialmente para cada vertice su valor es infinito.
	vector<bool> mark(graph.V, false); // Este arreglo nos permitira determinar los nodos procesados.

	Dist[begin] = 0; // Valor inicial del vertice de partida.
	pq.push(State(begin, 0)); // Agregamos el primer elemento, que no es mas que el vertice de partida.
	while(!pq.empty()) // Mientras existan vertices por procesar.
	{
		State st = pq.top(); pq.pop(); // Se desencola el elemento minimo.
		mark[st.node] = true; // Se marca el nodo como visitado.
		if (st.node == end)
			return st.cost; // Retornamos el valor del camino, hemos llegado al vertice destino.

		int T = (int)graph.G[st.node].size();
		for(int i = 0; i < T; ++i) // Se recorren las adyacencias de "a".
		{
			// Si no ha sido procesado el vertice "vi" y la distancia hacia "vi" es menor a la distancia
			// en Dist entonces hemos encontrado un camino mas corto a "vi".
			if (!mark[graph.G[st.node][i].node] && ((Dist[st.node] + graph.G[st.node][i].cost) < Dist[graph.G[st.node][i].node]))
			{
				Dist[graph.G[st.node][i].node] = st.cost + graph.G[st.node][i].cost;
				pq.push(State(graph.G[st.node][i].node, st.cost + graph.G[st.node][i].cost));
			}
		}
	}
	return -1; // Si no se puede llegar al destino, retornar -1.
}

int main()
{
	int V = 0;
	unordered_map<int, char> vertex;
	
	vertex[0] = 'A';
	vertex[1] = 'B';
	vertex[2] = 'C';
	vertex[3] = 'D';
	vertex[4] = 'E';
	vertex[5] = 'F';
	vertex[6] = 'G';
	vertex[7] = 'H';
	vertex[8] = 'I';
	
	for (const auto& pair : vertex) 
	{
		const int& key = pair.first;
		char value = pair.second;
		cout << "Key: " << key << ", Value: " << value << endl;
	}
	cout << endl;
	
	vector<vector<int>> graph = 
	{
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0}
	};
	
	V = 9;
	
	for (int i = 0; i < V; ++i) 
	{
		cout << "Vertice " << vertex[i] << ": ";
		for (int j = 0; j < V; ++j) 
		{
			if (graph[i][j] != 0)
			{
				cout << vertex[j] << ", Peso: " << graph[i][j] << "; ";
			}
		}
		cout << endl;
	}
	
	Dijkstra(0, 7, graph);
	
	return 0;
}
