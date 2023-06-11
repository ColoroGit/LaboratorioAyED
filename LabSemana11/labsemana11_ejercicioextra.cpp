#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Node
{
	public:
		
	char letter;
	vector<Node*> adj;
	
	Node(char l)
	{
		letter = l;
	}
};

void AddEdge(vector<Node*> adjList, int u, int v)
{
	adjList[u]->adj.push_back(adjList[v]);
	adjList[v]->adj.push_back(adjList[u]);
}

void PrintGraph(vector<Node*> adjList)
{
	for (Node* vertex : adjList)
	{
		for (Node* v : vertex->adj)
		{
			cout << v->letter << " ";
		}
		
		cout << endl;
	}
}

bool IsConnected(vector<Node*> adjList, int u, int v)
{
	for (Node* vertex : (adjList[u])->adj)
	{
		if (vertex->letter == 'A' + v)
		{
			return true;
		}
	}
	
	return false;
}

void FindPath(vector<Node*> adjList, int u, int v)
{
	if (u == v)
	{
		cout << adjList[u]->letter << endl;
		return;
	}
	
	list<Node*> q;
	q.push_back(adjList[u]);
	vector<char> path;
	
	while (!q.empty())
	{
		Node* current = q.front();
		q.pop_front();
		path.push_back(current->letter);
		
		if (path.back() == 'A' + v)
		{
			for (char val : path)
			{
				cout << val << " ";
			}
			
			return;
		}
		
		for (Node* vertex : current->adj)
		{
			bool visited = false;
			
			for (char l : path)
			{
				if (vertex->letter == l)
				{
					visited = true;
				}
			}
			
			if (!visited)
			{
				q.push_front(vertex);
			}
		}
	}
}

int main()
{
	vector<Node*> adjList;
	
	adjList.push_back(new Node('A'));
	adjList.push_back(new Node('B'));
	adjList.push_back(new Node('C'));
	adjList.push_back(new Node('D'));
	adjList.push_back(new Node('E'));
	adjList.push_back(new Node('F'));
	adjList.push_back(new Node('G'));
	adjList.push_back(new Node('H'));
	
	AddEdge(adjList, 0, 1);
	AddEdge(adjList, 0, 2);
	AddEdge(adjList, 1, 3);
	AddEdge(adjList, 1, 4);
	AddEdge(adjList, 1, 5);
	AddEdge(adjList, 2, 3);
	AddEdge(adjList, 2, 5);
	AddEdge(adjList, 2, 6);
	AddEdge(adjList, 3, 4);
	AddEdge(adjList, 4, 5);
	AddEdge(adjList, 4, 7);
	AddEdge(adjList, 5, 6);
	AddEdge(adjList, 5, 7);
	AddEdge(adjList, 6, 7);
	
	PrintGraph(adjList);
	
	if (IsConnected(adjList, 0, 7))
	{
		cout << "Existe coneccion" << endl;
	}
	else
	{
		cout << "No existe coneccion" << endl;
	}
	
	FindPath(adjList, 0, 5);
	
	return 0;
}
