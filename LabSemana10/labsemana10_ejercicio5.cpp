#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int d)
{
	Node* newNode = new Node;
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, Node* newNode)
{
	if (root == NULL)
	{
		root = newNode;
		return root;
	}
	
	if (newNode->data <= root->data)
	{
		root->left = Insert(root->left, newNode);
	}
	else
	{
		root->right = Insert(root->right, newNode);
	}
}

void InOrderPrint(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	
	InOrderPrint(root->left);
	
	cout << root->data << " ";
	
	InOrderPrint(root->right);
}

int main()
{
	Node* root = NULL;
	int array[] = {21, 18, 6, 9, 10, 7, 19, 15, 12, 5};
	
	for (int i = 0; i < 10; i++)
	{
		root = Insert(root, CreateNode(array[i]));
	}
	
	InOrderPrint(root);
	
	return 0;
}
