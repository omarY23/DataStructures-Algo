#include <bits/stdc++.h>
using namespace std;

struct node{
int data;
 struct node* left;
 struct node* right;

node(int val){
        data= val;
        left=right=NULL;
    }
    
};

bool isBalancedTree(node* root){

if(root== NULL)
return true;

if(isBalancedTree(root->left)== false)
return false;

if(isBalancedTree(root->right)== false)
return false;

int lh= height(root->left);
int rh= height(root->right);

if(abs(lh-rh) <=1){
    return true;
    }
}

int height(node* root){

if(root== NULL){
    return 0;
}

int lh= height(root->left);
int rh= height(root->right);
return max(lh, rh) + 1;
}



}