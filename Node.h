//this class implements a node in the BINARY SEARCH TREE
//key node value is the student ID
//node also contains a student name
//this class is private and should only be used in the class implementing the whole BST

#pragma once
#ifndef NODE
#define NODE
#include "StringCustom.h"

class Node {
private:
	//student ID
	int id;
	//student name
	StringCustom name;

	//pointer to the left child
	Node* left;
	//pointer to the right child
	Node* right;
	//pointer to the parent
	Node* root;

	//constructor
	Node(int idCp, StringCustom nameCp, Node* rootCp = NULL, Node* leftCp = NULL, Node* rightCp = NULL);


	//returns a pointer to the left child
	// NULL if left child does not exist
	Node* leftChild();
	//returns a pointer to the right child
	// NULL if right child does not exist
	Node* rightChild();

	// if TRUE node is a left child of their parent
	bool isLeftChild();
	// if TRUE node is a right child of their parent
	bool isRightChild();
	// if TRUE node is a root and does not have a parent
	bool isRoot();
	// if TRUE node does not have children
	bool isLeaf();
	// if TRUE node has at least one child
	bool hasChild();
	// if TRUE node has 2 children
	bool hasChildren();
	//takes a node and makes it into a root of its own temp tree
	void tempTree();
	// finds the leftmost node
	Node* getMin();
	// finds an heir for a node to be deleted
	Node* heir();
	// replaces data of a node with data from a different node
	void nodeSwitch(int idCp, StringCustom nameCp, Node* leftCp = NULL, Node* rightCp = NULL);

	friend class BST;
};

#endif