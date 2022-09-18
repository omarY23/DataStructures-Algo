#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isValid(node* root, node* min=NULL, node* max=NULL){

    if(root==NULL)
    return true;  //because an empty root means it follows BST

    if(min!=NULL && root->data<=min->data)
    return false;

    if(max!=NULL && root->data>=max->data)
    return false;

    bool leftChildValidity = isValid(root->left, min, root);
    bool rightChildValidity = isValid(root->right, root, max);

    return (leftChildValidity && rightChildValidity);


}