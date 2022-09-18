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

int countNodes(node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+ countNodes(root->right)+1;
}

int sumofNodes(node* root){
    if(root==NULL){
        return 0;
    }

    return sumofNodes(root->left)+ sumofNodes(root->right) + root->data;
}

int main(){
    struct node* root;
    root= new node(1);
    root->left=new node(2);
    root->right= new node(3);
    root->left->left=new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);
    cout<<sumofNodes(root)<<endl;
    cout<<countNodes(root)<<endl;
    return 0;
}