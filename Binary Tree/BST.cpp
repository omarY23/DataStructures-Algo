
#include <bits/stdc++.h>
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

node *insertBST(node *root, int n)          // insert Function in BST
{

    if (root == NULL)
    {
        return new node(n);
    }

    if (n < root->data)
    {
        root->left = insertBST(root->left, n);
    }

    else if (n > root->data)
    {
        root->right = insertBST(root->right, n);
    }

    return root;
}


node *searchinBST(node *root, int key)              //Search function in BST
{

    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    if (key > root->data)
        return searchinBST(root->right, key);

    return searchinBST(root->left, key);
}


void inorder(node *root)
{

    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}


int main()
{

    node *root = NULL;

    root = insertBST(root, 5);

    insertBST(root, 4);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 6);
    insertBST(root, 2);

    node* n= searchinBST(root, 7);
    if(n !=NULL)
    cout<<"key is present in BST";

    else
    cout<<"key not found";

    return 0;
}

/* The BST will be of this kind:

                    5
                   / \
                  4   7
                 /   /
                3   6
               /
              2

*/
