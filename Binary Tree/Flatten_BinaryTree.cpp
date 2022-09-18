#include <iostream>          
#include <queue>
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

void flatten(node* root){

if(root==NULL || (root->left==NULL && root->right==NULL))
return;

if(root->left!=NULL){
    
    node* temp= root->right;
    root->right= root->left;
    root->left=NULL;

    node* t= root->right;
    while (t->right!=NULL)
    {
        t=t->right;
    }
    t->right=temp;
}
flatten(root->right);
    
}

void printTree(node* root){
    if(root==NULL)
    return;

    node* temp=root;

    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->right;        
    }
    cout<<"NULL"<<endl;
}

int main(){
     struct node* root=new node(1);

    root->left=new node(2);
    root->right= new node(3);
    /*

            1
           / \  
          2   3
         / \    
        4   5
    */

   root->left->left=new node(4);
   root->left->right= new node(5);  
   flatten(root);
   printTree(root);    
   return 0; 
}