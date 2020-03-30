#include "pch.h"
#include <iostream>
#include "Tree.h"
#include "Node.h"

Tree CreateTree() {
	/*
		Creates a tree and adds values to it
	*/
	Tree tree = Tree();
	tree.root = tree.CreateTreeNode(5);
	tree.Insert(3, tree.root);
	tree.Insert(2, tree.root);
	tree.Insert(4, tree.root);
	tree.Insert(7, tree.root);
	tree.Insert(6, tree.root);
	tree.Insert(8, tree.root);

	return tree;
}

void TestDurchgehen(Tree tree) {
	tree.PreOrder(tree.root);
	std::cout << '\n';
	tree.InOrder(tree.root);
	std::cout << '\n';
	tree.PostOrder(tree.root);
	std::cout << '\n';
}

void TestDelete(Tree tree) {
	tree.Delete(tree.root, 3);
	tree.Delete(tree.root, 8);
	std::cout <<"Nodes Count: " << tree.Nodes(tree.root) << '\n';

}

int main()
{
    std::cout << "Lab3!\n"; 

	/*Tree tree_root;
	tree_root.root = tree_root.Insert(50, tree_root.root);*/

	Tree tree;

	tree = CreateTree(); //testing constructor and add

	std::cout << "Nodes Count: " << tree.Nodes(tree.root) << '\n'; //testing count

	TestDurchgehen(tree); //testing inorder, preorder, postorder

	TestDelete(tree); //Testing delete
	
	tree.PreOrder(tree.root); //Check if delete works
	std::cout << '\n';

	std::cout <<"Edges: "<< tree.Edges(tree.root) << '\n'; //testing edges

	std::cout <<"Height: " << tree.Height(tree.root) << '\n'; //testing height

}
