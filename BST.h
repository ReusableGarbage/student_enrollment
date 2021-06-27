//class implementing BINARY SEARCH TREE
//!!! to see the implementation of node, refer to Node.h !!!
//
//This tree is made specificaly to track students enrolling to a class (class = tree, student = node)
//every node is a student
//every node contains a student id
//every node contains a name of a student


#pragma once
#ifndef BSThead
#define BSThead

#include "Node.h"


class BST {
private:

	Node* root;
	int size;

	// private method called in add(int id, StringCustom jmeno);
	void pAdd(int id, StringCustom name, Node* temp);
	// private method called in  StringCustom get(int id);
	Node* pGet(int id, Node* temp);
	//finds a student with the lowest id
	Node* minGet(Node* temp);
	
	//rekursice destructor
	void rekursiveDestruct(Node* root);

public:
	BST();
	~BST();
	//returns number of students
	int getSize();
	//adds a student. id= student id, name=student name
	void add(int id, StringCustom name);
	//returns students name according to the id
	StringCustom get(int id);
	//check if a student id exists in the tree
	bool isId(int id);
	//deletion of a node, called in deleteById
	void deleteByNode(Node* temp);
	//deletion of a student 
	void deleteById(int id);

};

#endif