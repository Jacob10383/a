// bst.cpp
// CS24 Final Exam
// Implements class bst
// JT Siebold 06/06

#include "bst.h"

#include <iostream>
using std::cout;

bst::bst(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        insert(v.at(i));
    }
}

bst::~bst()
{
   //clear(root);
}

void bst::clear(bstNode *n)
{
    if(n)
    {
        clear(n->right);
        clear(n->left);
        delete n;
    }
}

bool bst::insert(int value) {

    if (root == nullptr){
        root = new bstNode(value);
        return true;
    }else{
        return insert(value, root);
    }

    return false; 

}


// recursive helper for insert (assumes n is never 0)

bool bst::insert(int value, bstNode *n) {

    if(value < n->info){
        if(n->left == nullptr){
            n->left = new bstNode(value);
            n->left->parent = n;
            return true;
        } else {
            return insert(value, n->left);
        }
    } else if (value > n->info) {
        if (n->right == nullptr){
            n->right = new bstNode(value);
            n->right->parent = n;
            return true;
        } else {
            return insert(value, n->right);
        }
    } else {
        return false;
    }

}



void bst::deleteSubtree(int key)
 {
     if(getNodeFor(key,root))
 delete(getNodeFor(key, root));
}




int bst::countLeaves(bstNode *n) const
{
    if(!n)
        return 0;
    if((n->right == nullptr) && (n->left == nullptr))
        return 1;        
    else
        return countLeaves(n->right) + countLeaves(n->left);
}

int bst::countParentsWithTwoChildren(bstNode *n) const
{
    if(!n)
        return 0;
    if((n->right) && (n->left))
        return 1;        
    else
        return countLeaves(n->right) + countLeaves(n->left);
}

int bst::height(bstNode *n) const
{
    int tall;
    if (!root)
        return -1;
    if(!n)
        return 0;
    else
    {
        int left = height(n->left);
        int right = height(n->right);
        if (left > right)
            tall = left;
        else
            tall = right;
       return tall + 1;
    }
}
void bst::outputPreOrder(bstNode *n, vector<int> &output) const
{
    if (!n)
    {
        return;
    }
    output.push_back(n->info);
    outputInOrder(n->left, output);
    outputInOrder(n->right, output);
}

void bst::outputInOrder(bstNode *n, vector<int> &output) const
{
    if (!n)
    {
        return;
    }
    outputInOrder(n->left, output);
    output.push_back(n->info);
    outputInOrder(n->right, output);
}

typename bst::bstNode* bst::getNodeFor(int value, bstNode* n) const{
    while (n != nullptr) {
        if (value == n->info) {
            return n; 
        }
        else if (value < n->info) {
            return getNodeFor(value, n->left);
        } else {
            return getNodeFor(value, n->right);
        }
    }
    return nullptr; // Node doesn't exist in tree
}
