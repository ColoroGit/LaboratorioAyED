#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int data;
	Node* left;
	Node* right;
} Node;

Node* CreateNode(int d)
{
	Node* newNode = new Node;
	newNode->data = d;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

class BinaryTree
{
	Node* root;
	
	public:
		
	BinaryTree()
	{
		root = NULL;
	}
	
	Node* GetRoot()
	{
		return root;
	}
	
	void SetRoot(Node* n)
	{
		root = n;
	}
	
	Node* Insert(Node* root, Node* n)
	{
		if (root == NULL)
		{
			root = n;
			return root;
		}
		
		if (n->data <= root->data)
		{
			root->left = Insert(root->left, n); 
		}
		else
		{
			root->right = Insert(root->right, n);
		}
	}
	
	Node* Search(Node* root, int d)
	{
		if (root == NULL || root->data == d)
		{
			return root;
		}
		
		if (d <= root->data)
		{
			Search(root->left, d);
		}
		else
		{
			Search(root->right, d);
		}
	}
	
	void Print(Node* root)
	{
		if (root == NULL) 
		{
			return;
		}
		
		Print(root->left);
		cout << root->data << " ";
		Print(root->right);
	}
};

int main()
{
	BinaryTree tree;
	
	tree.SetRoot(tree.Insert(tree.GetRoot(), CreateNode(5)));
	tree.SetRoot(tree.Insert(tree.GetRoot(), CreateNode(8)));
	tree.SetRoot(tree.Insert(tree.GetRoot(), CreateNode(7)));
	tree.SetRoot(tree.Insert(tree.GetRoot(), CreateNode(15)));
	tree.SetRoot(tree.Insert(tree.GetRoot(), CreateNode(1)));
	
	tree.Print(tree.GetRoot());
	cout << endl;
	
	if (tree.Search(tree.GetRoot(), 3) != NULL)
	{
		cout << "El nodo que esta buscando se encuentra en la lista" << endl;
	}
	else
	{
		cout << "El nodo que esta buscando no se encuentra en la lista" << endl;
	}
	
	return 0;
}
