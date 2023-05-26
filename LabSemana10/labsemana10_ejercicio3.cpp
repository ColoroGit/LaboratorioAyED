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
	
	root = CreateNode(1);
	root->left = CreateNode(2);
	root->right = CreateNode(3);
	root->left->left = CreateNode(4);
	root->left->right = CreateNode(5);
	root->right->left = CreateNode(6);
	root->right->right = CreateNode(7);
	
	InOrderPrint(root);
	
	return 0;
}
