#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Function to add an edge between vertices u and v
void addEdge(vector<vector<int> >& graph, int u, int v) 
{
	graph[u][v] = 1;
	graph[v][u] = 1;
}

// Function to print the adjacency matrix
void printGraph(const vector<vector<int> >& graph) 
{
	cout << "Adjacency Matrix:\n";
	for (const auto& row : graph) 
	{
		for (int val : row) 
		{
			cout << val << " ";
		}
		cout << '\n';
	}
}

bool IsConnected(vector<vector<int> >& graph, int u, int v)
{
	return graph[u][v];
}

void FindPath(vector<vector<int> >& graph, int u, int v)
{
	if (u == v)
	{
		cout << u << endl;
		return;
	}
	
	list<int> q;
	q.push_front(u);
	vector<int> path;
	vector<bool> visited(8, false);
	
	while (!q.empty())
	{
		int current = q.front();
		q.pop_front();
		path.push_back(current);
		visited[current] = true;
		
		if (path.back() == v)
		{
			for (int val : path)
			{
				cout << val << " ";
			}
			
			return;
		}
		
		for (int i = 0; i < graph.size(); i++) 
		{	
			if (graph[current][i] == 1 && !visited[i])
			{
				visited[i] = true;
				q.push_front(i);
			}
		}
	}
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
	
	// Print the adjacency matrix
	printGraph(graph);
	
	// Check if there is a direct connection between two vectors
	if (IsConnected(graph, 0, 5))
	{
		cout << "Hay conexion directa" << endl;
	}
	else
	{
		cout << "No hay conexion directa" << endl;
	}
	
	// Find a path from a vertex to another
	FindPath(graph, 0, 7);
	
	return 0;
}	
