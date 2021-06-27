#include "BST.h"

BST::BST()
{
    this->root = NULL;
    this->size = 0;
}

BST::~BST()
{
    rekursiveDestruct(root);
}

void BST::rekursiveDestruct(Node* root) 
{
    if (root != NULL)
    {

        if (root->left != NULL && root != NULL)
            rekursiveDestruct(root->left);
        if (root->right != NULL && root != NULL)
            rekursiveDestruct(root->right);
        delete root;
    }
}

void BST::pAdd(int id, StringCustom name, Node* temp)
{
    if (id < temp->id) //if id is smaller than the current node
    {
        if (temp->leftChild()) //if the node already has a left child
        {
            this->pAdd(id, name, temp->left); //searching for a free space recursively
        }
        else //if there is no leftChild, we can just make this student a leftChild
        {
            temp->left = new Node(id, name, temp);
        }
    }
    else // id is bigger than the current node
    {
        if (temp->rightChild())
        {
            this->pAdd(id, name, temp->right); 
        }
        else 
        {
            temp->right = new Node(id, name, temp);

        }
    }
}

Node* BST::pGet(int id, Node* temp)
{
    if (!temp)
    {
        return NULL;
    }
    else if (temp->id == id)
    {
        return temp;
    }
    else if (id < temp->id) // id is smaller than node, search left
    {
        return this->pGet(id, temp->left);
    }
    else// id is larger than the node, search right
    {
        return this->pGet(id, temp->right);
    }
}

Node* BST::minGet(Node* temp)
{
    Node* current = temp;
    while (current && current->left != NULL)
        current = current->left; //searching for the biggest id

    return current;
}

int BST::getSize()
{
    return this->size;
}

void BST::add(int id, StringCustom jmeno)
{
    if (this->root)
    {
        this->pAdd(id, jmeno, this->root);
    }
    else //BST is empty
    {
        this->root = new Node(id, jmeno);
    }
    this->size = this->size + 1;
}


StringCustom BST::get(int id)
{
    if (this->root)
    {
        Node* temp = this->pGet(id, this->root);
        if (temp)
        {
            return temp->name;
        }
        else
        {
            throw "Name not found.";
        }
    }
    else //BST is empty
    {
        throw "Name not found, there are no students enrolled.";
    }
}

bool BST::isId(int id)
{
    if (this->root)
    {
        Node* temp = this->pGet(id, this->root);
        if (temp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else //BST is empty
    {
        return false;
    }
}


void BST::deleteByNode(Node* temp)
{
    if (temp->isLeaf()) //node we're deleting is a leaf
    {
        if (temp->isLeftChild()) //node is a left leaf
        {
            temp->root->left = NULL;
        }
        else //node is a right leaf
        {
            temp->root->right = NULL;
        }
    }
    else if (temp->hasChildren()) //node has two childern
    {
        if (temp->root == NULL) //node doesnt have a parent
        {
            Node* heir = minGet(temp->right); //get the largest id on the right side and set it as the new root
            temp->id = heir->id;
            temp->name = heir->name;
            deleteByNode(heir);
        }
        else //node has a parent, is replaced by that parent
        {
        Node* heir = temp->heir();
        heir->tempTree();
        temp->id = heir->id;
        temp->name = heir->name;
        }
    }
    else
    {
        if (temp->leftChild()) //node has a left child only
        {
            if (temp->isLeftChild()) //node is a left child and has a left child
            {
                temp->left->root = temp->root; 
                temp->root->left = temp->left;
            }
            else if (temp->isRightChild()) //node is a right child
            {
                temp->left->root = temp->root;
                temp->root->right = temp->left;
            }
            else //node does not have a parent
            {
                //node is replaced with a left child
                temp->nodeSwitch(temp->left->id, 
                    temp->left->name,
                    temp->left->left,
                    temp->left->right);
            }
        }
        else //node has a right child only
        {
            if (temp->isLeftChild()) //node is a left child
            {
                temp->right->root = temp->root;
                temp->root->left = temp->right;
            }
            else if (temp->isRightChild()) //node is a right child
            {
                temp->right->root = temp->root;
                temp->root->right = temp->right;
            }
            else//node doesnt have a parent
            {
                //node is replaced by the right child
                temp->nodeSwitch(temp->right->id, 
                    temp->right->name,
                    temp->right->left,
                    temp->right->right);
            }
        }
    }
}

void BST::deleteById(int id)
{
    if (this->size > 1) //BST contains more than 1 student
    {
        Node* removeNode = this->pGet(id, this->root);
        if (removeNode)
        {
            this->deleteByNode(removeNode);
            this->size = this->size - 1;
        }
        else
        {
            throw "ID not found.";
        }
    }
    else if (this->size == 1 && this->root->id == id) //BST contains only one student
    {
        this->root = NULL; //left a right is NULL
        this->size = this->size - 1;
    }
    else
    {
        throw  "ID not found";
    }
}

