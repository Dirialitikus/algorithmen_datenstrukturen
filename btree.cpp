#include "btree.h"
#include <queue>


bTree::bTree()
{
    root = NULL;
}



bool bTree::empty(bTree::node *b)
{
    bool isFilled = true;

    if(b->left != NULL || b->right != NULL)
        isFilled = true;

    return isFilled;
}

bTree::node *bTree::left(bTree::node *b)
{
    return b->left;
}

bTree::node *bTree::right(bTree::node *b)
{
    return b->right;
}

string bTree::value(bTree::node *b)
{
    return b->info;
}

bTree::node *bTree::create()
{

    bTree::node* ptr = NULL;
    return ptr;
}

void bTree::printInOrder(bTree::node *b) //inorder print of a btree
{
    if(b == NULL)
        return;
    printInOrder(b->left);
    std::cout << b->nr << ": " << b->info << "\n";
    printInOrder(b->right);
}

bTree::node *bTree::NODE(bTree::node *b1, string inf, bTree::node *b2)
{

    bTree::node* ptr = new bTree::node();
    ptr->left = b1;
    ptr->right = b2;
    ptr->info = inf;
    ptr->nr = bTree::node::uniqueID;

    bTree::node::uniqueID++;

    return ptr;

}

void bTree::copy(bTree *cpy)
{

    this->root = cpy->root;

}

void bTree::del(bTree::node *ptr)
{

    if(ptr ==NULL)
        return;

    if(ptr->left !=NULL)
        del(ptr->left);
    if(ptr->right !=NULL)
        del(ptr->right);

    delete ptr;

}

bTree::node *bTree::zuweisung(bTree::node *copyFrom, bTree::node* toThis)
{
    if(copyFrom == NULL)
        return NULL;

    else{
        toThis = new node();
        toThis->left = NULL;
        toThis->right = NULL;

        toThis->info = copyFrom->info;

        toThis->left = zuweisung(copyFrom->left, toThis->left);
        toThis->right = zuweisung(copyFrom->right, toThis->right);

    }

    return toThis;


}

bTree::node *bTree::deleteNode(bTree::node *ptr, string info)
{
    if(ptr == NULL)
        return ptr;

    if(info != ptr->info){
        ptr->left = deleteNode(ptr->left, info);
        ptr->right = deleteNode(ptr->right, info);
    }
    else{
        if(ptr->left == NULL && ptr->right == NULL){
            delete ptr;
            ptr = NULL;
        }
        else if(ptr->left == NULL){
            bTree::node* tmp = ptr;
            ptr = ptr->right;
            delete tmp;

        }
        else if(ptr->right == NULL){
            bTree::node* tmp = ptr;
            ptr = ptr->left;
            delete tmp;
        }
        else {
            bTree::node* tmp = findMin(ptr->right);
            ptr->info = tmp->info;
            ptr->right = deleteNode(ptr->right, tmp->info);
        }


    }

    return ptr;

}

bTree::node *bTree::findMin(bTree::node *ptr)
{
    while(ptr->left != NULL){
        ptr = ptr->left;
    }

    return ptr;
}

const bTree &bTree::operator=(const bTree &fromThis)
{

    bTree* tmpTree = new bTree();
    // bTree zwei = eins;
    tmpTree->root = zuweisung(fromThis.root, tmpTree->root);

    this->copy(tmpTree);

    return *this;
}

void bTree::levelOrderPrint(bTree::node *ptr)
{
    if(ptr == NULL)
        return;

    queue<node*> levelOrderQueue;

    levelOrderQueue.push(ptr);

    bTree::node* front = NULL;

    while(!levelOrderQueue.empty()){

        front = levelOrderQueue.front();
        std::cout << front->info << " ";

        if(front->left != NULL)
            levelOrderQueue.push(front->left);

        if(front->right != NULL)
            levelOrderQueue.push(front->right);

        levelOrderQueue.pop();
    }
}


void bTree::comapreTree(bTree::node *firstTree, bTree::node *secondTree)
{

    if(this->isSame == true){
        if(firstTree == NULL && secondTree == NULL){
            return;
        }
        else if (firstTree == NULL || secondTree == NULL){
            isSame = false;
            return;
        }

        else if(firstTree->info != secondTree->info){
            this->isSame = false;
        }

        else{
            this->hilfsPointer = secondTree->right;
            comapreTree(firstTree->right,hilfsPointer);
            this->hilfsPointer = secondTree->left;
            comapreTree(firstTree->left, hilfsPointer);
        }
    }
}


bTree::~bTree()
{
    bTree::del(root);
}

int bTree::node::uniqueID = 0;


bTree::node::~node(){

}
