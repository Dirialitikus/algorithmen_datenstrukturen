#include "bst.h"
#include "btree.h"
#include <string>
#include <algorithm>

BST::BST()
{
    root2 = NULL;

}


bTree::node *BST::insertInClass(std::string insertInfo, bTree::node* ptr)
{

    std::string data;
    std::string dataPtr;




    if(ptr != NULL){
        dataPtr = ptr->info;

        // convert string to upper case
        std::for_each(dataPtr.begin(), dataPtr.end(), [](char & c) {
            c = ::toupper(c);
        });


        data = insertInfo;

        // convert string to upper case
        std::for_each(data.begin(), data.end(), [](char & c) {
            c = ::toupper(c);
        });
    }

    if(ptr == NULL){
        ptr = new node();
        ptr->left = NULL;
        ptr->right = NULL;
        ptr->info = insertInfo;
    }


    else if(data <= dataPtr)
        ptr->left = insertInClass(insertInfo, ptr->left);
    else
        ptr->right = insertInClass(insertInfo, ptr->right);


    return ptr;

}

void BST::printAlphabeticly(bTree::node *ptr)
{

    if(ptr == NULL)
        return;

    printAlphabeticly(ptr->left);
    std::cout << ptr->info << " : ";
    printAlphabeticly(ptr->right);

}

bTree::node* BST::insert(std::string insert){

    root2 = insertInClass(insert, root2);


    return root2;

}
