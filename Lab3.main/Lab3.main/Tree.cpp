#include "pch.h"
#include "Tree.h"
#include <stdio.h>


Tree::Tree()
{
	root = nullptr;
}

Node *Tree::minValue(Node *node) {
	struct Node* current = node;
	while (current != NULL && current->left != NULL) {
		current = current->left;
	}
	return current;
}

Node *Tree::CreateTreeNode(int value) {
	/*
		Creaing a new Node
		and return it!=> functie e de tip Node*
	*/
	Node *temp = new Node();
	temp->left = nullptr;
	temp->right = nullptr;
	temp->info = value;

	return temp;
}

Node *Tree::Insert(int value, Node *root) {

	if (root == nullptr) {
		return this->CreateTreeNode(value);
	}

	if (value <= root->info) {
		root->left = Insert(value, root->left);
	}
	else if (value > root->info) {
		root->right = Insert(value, root->right);
	}

}

Node *Tree::Delete(Node *root, int key) {

	
	if (root == nullptr) {
		return root;
	}

	//pana se ajunge in capete
	if (key < root->info) {
		root->left = Delete(root->left, key);
	}
	else if (key > root->info) {
		root->right = Delete(root->right, key);
	}
	else {
		//cand se gaseste key-ul
		if (root->left == nullptr) {
			Node *temp = root->right;
			delete root; //free
			return temp;

		}
		else if (root->right == nullptr) {
			Node *temp = root->left;
			delete root;
			return temp;
		}

		//Daca Nodul respectiv are ambii fii trebuie sa se
		//stie care detine valoarea mai mica
		Node *temp = this->minValue(root->right);
		root->info = temp->info;
		root->right = Delete(root->right, temp->info);

	}

	return root;
}

void PostOrder(Node *node)
{
	if (node == NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	std::cout << node->value << " ";
}

void InOrder(Node *node)
{
	if (node == NULL)
		return;
	InOrder(node->left);
	std::cout << node->value << " ";
	InOrder(node->right);
}

void PreOrder(Node *node)
{
	if (node == NULL)
		return;
	std::cout << node->value << " ";
	PreOrder(node->left);
	PreOrder(node->right);
}

Tree::~Tree()
{
}
