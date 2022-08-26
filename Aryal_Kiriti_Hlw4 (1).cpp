#include <iostream>
#include <iomanip>
#include <stack>
#include <math.h>
using namespace std;

struct Node
{
	int info;
	Node* left, * right;
};
void BFTraversal(Node* t);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);
Node* deleteNode(Node* root, int el);
Node* insertNode(Node* t1, int el)
{
	Node* temp = new Node();
	temp->info = el;
	if (t1 == NULL)
	{
		t1 = temp;
	}
	else if (t1->info > el)
	{
		t1->right = insertNode(t1->right, el);
	}
	else if (t1->info < el)
	{
		t1->left = insertNode(t1->left, el);
	}
	return t1;
}

bool isInTree(Node* temp, int el)
{
	if (temp == NULL)
		return false;
	if (temp->info == el)
		return true;
	else if (isInTree(temp->left, el) || isInTree(temp->right, el))
		return true;
	else if (temp->info != el)
		return false;
	return false;
}
bool search(Node* node, int data) {

	if (node == NULL) {
		return false;
	}
	if (node->info == data)
		return true;
	else if (isInTree(node->left, data) || isInTree(node->right, data))
		return true;
	else if (node->info != data)
		return false;
	return false;

}
void dispMenu(Node* root) {
	cout << setw(25) << "MENU" << endl << endl;
	cout << "Create (0), Search (1), Breadth-First Traversal (2)" << endl;
	cout << "Depth-First Traversal: preorder (3), inorder (4), postorder (5), deleteNode(6)" << endl;
	cout << "Exit Program(7)" << endl << endl;
	cout << setw(28) << "Choose?" << endl;
	int menuInput;
	int userInput;
	cin >> menuInput;
	switch (menuInput)
	{
	case 0:
		cout << "Enter the node key(press -99 when done): " << endl;
		cin >> userInput;
		cin;
		while (userInput != -99)
		{
			cin;
			insertNode(root, userInput);
			cin >> userInput;
		}
		dispMenu(root);
		break;
	case 1:
		cout << "Enter the number to search: " << endl;
		cin >> userInput;
		if (isInTree(root, userInput))
			cout << "Number belongs to the tree." << endl;
		else
			cout << "There is no such value." << endl;
		dispMenu(root);
		break;
	case 2:
		cout << "Breadth-First Traversal: ";
		BFTraversal(root);
		cout << endl;
		dispMenu(root);
		cin >> userInput;
		break;
	case 3:
		cout << "Depth-First Traversal: preorder: ";
		preorder(root);
		cout << endl;
		dispMenu(root);
		break;
	case 4:
		cout << "Depth-First Traversal: inorder: ";
		inorder(root);
		cout << endl;
		dispMenu(root);
		break;
	case 5:
		cout << "Depth-First Traversal: postorder: ";
		postorder(root);
		cout << endl;
		dispMenu(root);
		break;
	case 6:
		cout << "Delete a node: ";
		cin >> userInput;
		deleteNode(root, userInput);
		dispMenu(root);
		break;
	case 7:
		break;
	default:
		cout << "\nIncorrect selection. Try again!" << endl << endl;
		dispMenu(root);
	}
}
void BFTraversal(Node* t)
{
	if (t == NULL)
		return;

	stack <Node*> st;
	st.push(t);
	while (!st.empty())
	{
		Node* temp = new Node();
		temp = st.top();
		cout << temp->info << " ";
		st.pop();

		if (t->left != NULL)
			BFTraversal(t->left);
		if (t->right != NULL)
			BFTraversal(t->right);
	}
	cout << endl;

}
void preorder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->info << " ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->info << " ";
}
void inorder(Node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->info << " ";
	inorder(root->right);
}
Node* FindMin(Node* root)
{
	while (root->left != NULL) 
		root = root->left;
	return root;
}

Node* deleteNode(Node* root, int el)
{

	if (root == NULL) {
		return root;
	}

	if (el < root->info)
		root->left = deleteNode(root->left, el);
	else if (el > root->info)
		root->right = deleteNode(root->right, el);
	else {
		if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else if (root->right == NULL && root->left == NULL) {
			delete root;
			root = NULL;
		}
		else {
			Node* temp = FindMin(root->right);;
			root->info = temp->info;
			root->right = deleteNode(root->right, temp->info);
		}
	}
	return root;
}



int main()
{
	Node* root = new Node();
	dispMenu(root);
	return 0;
}