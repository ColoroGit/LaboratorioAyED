#include <iostream>
#include <string>
#include <vector>
#include <queue>

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

void BFS(Node* root)
{
	queue<Node*> queue;
	queue.push(root);
	
	if (root == NULL)
	{
		return;
	}
	
	while (!queue.empty())
	{
		Node* current = queue.front();
		queue.pop();
		
		cout << current->data << " ";
		
		if (current->left != NULL)
		{
			queue.push(current->left);
		}
		
		if (current->right != NULL)
		{
			queue.push(current->right);
		}
	}
}

int main()
{
	Node* root = NULL;
	int array[] = {21, 18, 6, 9, 10, 7, 19, 15, 12, 5};
	
	for (int i = 0; i < 10; i++)
	{
		root = Insert(root, CreateNode(array[i]));
	}
	
	BFS(root);
		
	return 0;
}
