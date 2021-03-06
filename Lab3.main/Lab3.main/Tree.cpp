#include "pch.h"
#include "Tree.h"
#include <stdio.h>
#include <queue>
#include <iostream>


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

Node *Tree::Insert(int value, Node *node) {

	if (node == NULL) {
		return CreateTreeNode(value);
	}

	if (value <= node->info) {
		node->left = Insert(value, node->left);
	}
	else if (value >= node->info) {
		node->right = Insert(value, node->right);
	}
	return node;
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

void Tree::PostOrder(Node *node)
{
	if (node == NULL)
		return;
	PostOrder(node->left);
	PostOrder(node->right);
	std::cout << node->info << " ";
}

void Tree::InOrder(Node *node)
{
	if (node == NULL)
		return;
	InOrder(node->left);
	std::cout << node->info << " ";
	InOrder(node->right);
}

void Tree::PreOrder(Node *node)
{
	if (node == NULL)
		return;
	std::cout << node->info << " ";
	PreOrder(node->left);
	PreOrder(node->right);
}

int Tree::Nodes(Node *node)
{//contorizeaza nr de noduri
	int count = 1;
	if (node == nullptr)
		return 0;
	else
	{
		count += Nodes(node->left);
		count += Nodes(node->right);
	}
	return count;
}

int Tree::Edges(Node *node)
{//returneaza nr de margini
	return Nodes(node) - 1;
}

int max(int a, int b)
{
	if (a < b)
		return b;
	return a;
}

int Tree::Height(Node *node)
{//returneaza inaltimea lui Tree
	if (node == NULL)
		return -1;
	return max(Height(node->left), Height(node->right)) + 1;
}

Tree::~Tree()
{
}
