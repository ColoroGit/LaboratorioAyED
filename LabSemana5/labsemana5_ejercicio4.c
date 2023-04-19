#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node 
{
	int data;
	struct node *next;
};

struct node* CreateNode(int data)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

void Enqueue(struct node **head, struct node *newNode) 
{
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		struct node *current = *head;
		
		while (current->next != NULL)
		{
			current = current->next;
		}
		
		current->next = newNode;
	}
}

struct node* Dequeue(struct node **head)
{
	if (*head != NULL)
	{
		struct node *n = *head;
		*head = n->next;
		return n;
	}
	else
	{
		printf("\nNo hay nodos para sacar de la cola");
	}
}

void Peek(struct node *head)
{
	printf("\nInfo del nodo en el inicio del stack: %d", head->data);
}

void PrintNodes(struct node *head)
{
	struct node *current = head;
	int i = 1;
	
	while (current != NULL)
	{
		printf("\nNodo %d: %d", i, current->data);
		i++;
		current = current->next;
	}
}

void SearchNode(struct node *head, int data)
{
	struct node *current = head;
	bool found = false;
	
	while (current != NULL && !found)
	{
		if(current->data == data)
		{
			found = true;
		}
		else
		{
			current = current->next;
		}
	}
	
	if (found)
	{
		printf("\nNodo: %d", current->data);
	}
	else
	{
		printf("\nNo hay ningun nodo con esa informacion");
	}
}

int GetSize(struct node *head)
{
	int i = 0;
	
	struct node *current = head;
	
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	
	return i;
}

void FreeNodes(struct node *head)
{
	struct node *current = head;
	
	while (current != NULL)
	{
		struct node *aux = current->next;
		free(current);
		current = aux;
	}
}

int main()
{
	struct node *head = NULL;
	struct node *newNode;
	
	int data;
	
	Enqueue(&head, CreateNode(2));
	Enqueue(&head, CreateNode(3));
	Enqueue(&head, CreateNode(4));
	
	PrintNodes(head);
	
	printf("\nHay %d nodos en la lista", GetSize(head));
	
	printf("\nIngrese la data del nodo que quiere buscar: ");
	scanf("%d", &data);
	
	SearchNode(head, data);
	
	struct node *actual = Dequeue(&head);
	
	printf("\nInfo nodo popeado: %d", actual->data);
	
	PrintNodes(head);
	
	Peek(head);
	
	FreeNodes(head);
	
	return 0;
}
