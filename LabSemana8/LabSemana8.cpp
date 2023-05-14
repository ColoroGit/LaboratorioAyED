#include <iostream>
#include <string>

using namespace std;

struct Node 
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data) 
{
	Node* newNode = new Node;
	newNode->data = data;
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

void PrintTree(Node* root) 
{
	if (root == NULL) 
	{
		return;
	}
	
	PrintTree(root->left);
	cout << root->data << " ";
	PrintTree(root->right);
}

Node* SearchTree(Node* root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	
	if (root->data == data)
	{
		return root;
	}
	
	if (data <= root->data)
	{
		SearchTree(root->left, data);
	}
	else
	{
		SearchTree(root->right, data);
	}
}

Node* SearchTreesMin(Node* root)
{
	if (root->left == NULL)
	{
		return root;
	}
	
	SearchTreesMin(root->left);
}

Node* SearchTreesMax(Node* root)
{
	if (root->right == NULL)
	{
		return root;
	}
	
	SearchTreesMax(root->right);
}

Node* Cut(Node* root, int data)
{
    // base case
    if (root == NULL)
    {
    	return root;
	}
 
    if (data < root->data)
    {
    	root->left = Cut(root->left, data);
	}
    else if (data > root->data)
    {
    	root->right = Cut(root->right, data);
	}
    else 
	{
        // node has no child
        if (root->left == NULL && root->right == NULL)
        {
        	return NULL;
		}
		
        // node with only one child or no child
        else if (root->left == NULL) 
		{
            Node* aux = root->right;
            //free(root);
            return aux;
        }
        else if (root->right == NULL) 
		{
            Node* aux = root->left;
            //free(root);
            return aux;
        }
 
        // node with two children: Get the inorder successor (smallest in the right subtree)
        Node* aux = SearchTreesMin(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = aux->data;
 
        // Delete the inorder successor
        root->right = Cut(root->right, aux->data);
    }
    
    return root;
}

int main()
{
	Node* root = NULL;
	
	root = Insert(root, CreateNode(8));
	root = Insert(root, CreateNode(5));
	root = Insert(root, CreateNode(1));
	root = Insert(root, CreateNode(7));
	root = Insert(root, CreateNode(10));
	root = Insert(root, CreateNode(6));
	
	PrintTree(root);
	
	int search = 2;
	
	cout << "Buscando el valor " << search << "... ";
	
	if (SearchTree(root, search) != NULL)
	{
		cout << "Encontrado" << endl;
	}
	else
	{
		cout << "No se encuentra" << endl;
	}
	
	cout << "Buscando el valor minimo... ";
	cout << SearchTreesMin(root)->data << endl;
	
	cout << "Buscando el valor maximo... ";
	cout << SearchTreesMax(root)->data << endl;
	
	int cut = 5;
	
	cout << "Eliminando el valor " << cut << "... ";
	
	root = Cut(root, cut);
	
	PrintTree(root);
	
	return 0;
}
