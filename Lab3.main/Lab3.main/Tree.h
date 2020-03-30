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

	Node *minValue(Node *node);

	void PostOrder(Node *node);

	void InOrder(Node *node);

	void PreOrder(Node *node);

	int Nodes(Node *node);

	int Edges(Node *node);

	int Height(Node *node);

	~Tree();
};

