#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int data;
	Node* next;
} Node;

class LinkedList
{
	Node* head;
	
	public:
	
	LinkedList()
	{
		head = NULL;
	}
	
	void Insert(Node* n)
	{
		if (head == NULL)
		{
			head = n;
		}
		else
		{
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = n;
		}
	}
	
	Node* Search(int d)
	{
		Node* n = head;
		
		while (n != NULL && n->data != d)
		{
			n = n->next;
		}
		
		return n;
	}
	
	Node* Remove(int d)
	{
		Node* n = head;
		
		while (n->next->data != d && n != NULL)
		{
			n = n->next;
		}
		
		if (n != NULL)
		{
			Node* aux = n->next;
			n->next = aux->next;
			return aux;
		}
		
		return NULL;
	}
	
	void Print()
	{
		Node* current = head;
		
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
};

Node* CreateNode(int d)
{
	Node* newNode = new Node;
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

int main()
{
	LinkedList list;
	
	list.Insert(CreateNode(6));
	list.Insert(CreateNode(8));
	list.Insert(CreateNode(12));
	list.Insert(CreateNode(2));
	
	list.Print();
	
	if (list.Search(8) != NULL)
	{
		cout << "El nodo que esta buscando se encuentra en la lista" << endl;
	}
	else
	{
		cout << "El nodo que esta buscando no se encuentra en la lista" << endl;
	}
	
	list.Remove(8);
	
	if (list.Search(8) != NULL)
	{
		cout << "El nodo que esta buscando se encuentra en la lista" << endl;
	}
	else
	{
		cout << "El nodo que esta buscando no se encuentra en la lista" << endl;
	}
	
	list.Print();
	
	return 0;
}
