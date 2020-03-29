#pragma once

#include "Node.h"
class Tree
{
public:
	Node *root;

	Tree();

	Node *CreateTreeNode(int value);

	Node *Insert(int key, Node* node);

	Node *Delete(Node *node, int value);

	void PostOrder(Node *node);

	void Inorder(Node *node);

	void PreOrder(Node *node);

	Node *minValue(Node *node);

	~Tree();
};

