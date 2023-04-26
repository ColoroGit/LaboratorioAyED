#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

void Enqueue(Node **head, Node *newNode)
{
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node *current = *head;
		
		while (current->next != NULL)
		{
			current = current->next;
		}
		
		current->next = newNode;
	}
}

void InsertValue(Node **head, int cant, int count)
{
	if (count == cant)
	{
		return;
	}
	
	Node *newNode = new Node;
	
	cout << "Ingrese un numero: ";
	cin >> newNode->data;
	newNode->next = NULL;
	
	Enqueue(head, newNode);
	count++;
	InsertValue(head, cant, count);
}

float GetAvg(Node *node, int cant, int count, float avg)
{
	if (count == cant)
	{
		return avg/cant;
	}
	
	avg += node->data;
	node = node->next;
	count++;
	avg = GetAvg(node, cant, count, avg);
}

int GetSum(Node *node, int cant, int count, int sum)
{
	if (count == cant)
	{
		return sum;
	}
	
	sum += node->data;
	node = node->next;
	count++;
	sum = GetSum(node, cant, count, sum);
}

int GetMult(Node *node, int cant, int count, int mult)
{
	if (count == cant)
	{
		return mult;
	}
	
	mult *= node->data;
	node = node->next;
	count++;
	mult = GetMult(node, cant, count, mult);
}

int main()
{
	Node *head = NULL;
	int cant = 0;
	
	cout << "A continuacion obtendremos el promedio, la suma y la multiplicacion de los valores que usted ingrese" << endl << "Cuantos numeros va a ingresar?: ";
	cin >> cant;
	
	InsertValue(&head, cant, 0);
	
	float avg = 0;
	int sum = 0;
	int mult = 1;
	
	cout << "Promedio: " << GetAvg(head, cant, 0, avg) << endl;
	cout << "Suma: " << GetSum(head, cant, 0, sum) << endl;
	cout << "Multiplicacion: " << GetMult(head, cant, 0, mult) << endl;
	
	return 0;
}
