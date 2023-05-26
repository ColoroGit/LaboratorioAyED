#include <iostream>
#include <vector>

using namespace std;

// Function to add an edge between vertices u and v
void addEdge(vector<vector<int> >& graph, int u, int v) 
{
	graph[u][v] = 1;
	graph[v][u] = 1;
}

int main() 
{
	int V = 8; // Number of vertices
	
	// Create an empty adjacency matrix
	vector<vector<int> > graph(V, vector<int>(V, 0));
	
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 5);
	addEdge(graph, 2, 3);
	addEdge(graph, 2, 5);
	addEdge(graph, 2, 6);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 4, 7);
	addEdge(graph, 5, 6);
	addEdge(graph, 5, 7);
	addEdge(graph, 6, 7);
	
	return 0;
}

