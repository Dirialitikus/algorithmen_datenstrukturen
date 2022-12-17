#ifndef BST_H
#define BST_H
#include "btree.h"


class BST : public bTree
{
private:
    node* root2;

public:
    BST();
    ~BST(){del(root2);}
    node* insert(std::string insert);
    node* insertInClass(std::string insert, node* ptr);
    bTree::node* getRoot2(){return this->root2;}
    void printAlphabeticly(node* ptr);

};

#endif // BST_H
