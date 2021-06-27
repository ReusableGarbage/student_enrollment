#include "Node.h"
#include <string>

Node::Node(int idCp, StringCustom jmenoCp, Node* rootCp, Node* leftCp, Node* rightCp)
{
	this->id = idCp;
	this->name = jmenoCp;
	this->left = leftCp;
	this->right = rightCp;
	this->root = rootCp;
}

Node* Node::leftChild()
{
	return this->left;
}

Node* Node::rightChild()
{
	return this->right;
}

bool Node::isLeftChild()
{
	return this->root && this->root->left == this;
}

bool Node::isRightChild()
{
	return this->root && this->root->right == this;
}

bool Node::isRoot()
{
	return !this->root;
}

bool Node::isLeaf()
{
	return !(this->left || this->right);
}

bool Node::hasChild()
{
	return this->left || this->right;
}

bool Node::hasChildren()
{
	return (this->left && this->right);
}

void Node::tempTree()
{

	if (this->isLeaf())
	{
		// if node is a leftmost child, NULL
		if (this->isLeftChild()) {
			this->root->left = NULL;
		}
		else {
			this->root->right = NULL;
		}
	}
	else if (this->hasChild()) // if node has at least one child
	{
		if (this->leftChild()) // if the child is left
		{
			if (this->isLeftChild()) //if the node itself is a left child as well
			{
				this->root->left = this->left;
			}
			else
			{
				this->root->right = this->right;
			}
			this->left->root = this->root;
		}
		else
		{
			if (this->isLeftChild())
			{
				this->root->left = this->right;
			}
			else
			{
				this->root->right = this->right;
			}
			this->right->root = this->root;
		}
	}

}

Node* Node::getMin() {
	Node* temp = this;
	while (temp->leftChild())
	{
		temp = temp->left;
	}
	return temp;
}

Node* Node::heir() {
	Node* temp = NULL;
	if (this->rightChild())
	{
		temp = this->root;
	}
	else
	{
		if (this->root)
		{
			if (this->isLeftChild())
			{
				temp = this->root;
			}
			else
			{
				this->root->right = NULL;
				temp = this->root->heir();
				this->root->right = this;
			}
		}
	}
	return temp;
}

void Node::nodeSwitch(int idCp, StringCustom nameCp, Node* leftCp, Node* rightCp)
{
	this->id = idCp;
	this->name = nameCp;
	this->left = leftCp;
	this->right = rightCp;

	if (this->leftChild())
	{
		this->left->root = this;
	}

	if (this->rightChild())
	{
		this->right->root = this;
	}

}