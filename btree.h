#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class bTree{
protected:
    struct node{
        friend class BST;
        string info;
        node* left = NULL;
        node* right = NULL;
        node(){};
        ~node();
        static int uniqueID;
        int nr;
        bool marked;
    };

    node* root;
public:
    node* hilfsPointer = NULL;
    bool isSame = true;

    bTree();
    virtual ~bTree();
    bool empty(node* b);
    node* left(node* b);
    node* right(node* b);
    string value(node* b);
    node* create();
    void printInOrder(node *b);
    node* NODE(node* b1, string, node* b2);
    node* getRoot(){return this->root;}
    void copy(bTree* cpy);
    void del(node* ptr);
    node* zuweisung(node* ptr, node* ptr2);
    node* deleteNode(node* ptr, string info);
    node* findMin(node* ptr);

    const bTree& operator=(const bTree& fromThis);

    void levelOrderPrint(node* ptr);
    void comapreTree(node* firstTree, node* secondTree);

    void main() {
        root = NODE(NODE(create(), "Peter", NODE(create(),
                                                 "Altenbernd", create())), "faehrt", NODE(create(), "nach",
                                                                                          NODE(create(), "Darmstadt", create())));
        cout << empty (right(root)) << endl;
        cout << value(left(root)) << endl;
    };
};


#endif // BTREE_H
