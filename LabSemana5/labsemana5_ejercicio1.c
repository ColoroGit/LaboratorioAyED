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

void AddNode(struct node **head, struct node *newNode)
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
	
	AddNode(&head, CreateNode(2));
	AddNode(&head, CreateNode(3));
	AddNode(&head, CreateNode(4));
	
	PrintNodes(head);
	
	FreeNodes(head);
	
	return 0;
}
