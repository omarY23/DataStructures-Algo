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

void printlevelOrder(node* root, int k){
    if(root==NULL){
        return;
    }
 
    queue<node*> q;
    int level= 0;
    q.push(root);
    q.push(NULL);
    int sum=0;
    while (!q.empty())
    {
        node* n=q.front();
        q.pop();

        if(n!=NULL){
            cout<<n->data<<" ";
            // if(level==k){                                       //For sum at Kth level in a Binary tree
            //     sum= sum+(n->data);
            // }
            if(n->left!=NULL)
            q.push(n->left);
            if(n->right!=NULL)
            q.push(n->right);
            

        }
        else if(!q.empty()){
            level++;                                            // Increasing the level after we get every NULL
            q.push(NULL);
        }
               
    }
    cout<<endl;
    cout<<sum<<endl;
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
    printlevelOrder(root,2);
    return 0;
}