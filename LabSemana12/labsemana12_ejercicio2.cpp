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

void FindPath(vector<vector<int> >& graph, unordered_map<int, char> vertex, int u, int v)
{	
	if (u == v)
	{
		cout << vertex[u] << endl;
		return;
	}
	
	list<int> q;
	q.push_front(u);
	vector<int> path;
	vector<bool> visited(graph.size(), false);
	
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
				cout << vertex[val] << " ";
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
	vertex[9] = 'J';
	
	for (const auto& pair : vertex) 
	{
		const int& key = pair.first;
		char value = pair.second;
		cout << "Key: " << key << ", Value: " << value << endl;
	}
	cout << endl;
	
	vector<vector<int>> graph = 
	{
		{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
		{0, 0, 1, 1, 1, 0, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 1, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0}
	};
	
	V = 10;
	
	for (int i = 0; i < V; ++i) 
	{
		cout << "Vertice " << vertex[i] << ": ";
		for (int j = 0; j < V; ++j) 
		{
			if (graph[i][j])
			{
				cout << vertex[j] << " ";
			}
		}
		cout << endl;
	}
	
	FindPath(graph, vertex, 8, 3);
	
	return 0;
}

