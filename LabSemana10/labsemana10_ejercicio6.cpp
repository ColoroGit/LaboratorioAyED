#include <iostream>
#include <string>
#include <vector>
#include <stack>

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

void DFS(Node* root)
{
	stack<Node*> stack;
	stack.push(root);
	
	if (root == NULL)
	{
        return;
    }
	
	while (!stack.empty())
	{
		Node* current = stack.top();
		stack.pop();
		
		cout << current->data << " ";
		
		if (current->right != NULL)
		{
			stack.push(current->right);
		}
		
		if (current->left != NULL)
		{
			stack.push(current->left);
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
	
	DFS(root);
		
	return 0;
}
