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

void printSubtreeNodes(node* root, int k){          //for the case when we find nodes in the subtree of target node
    if(root== NULL || k<0)
    return;

    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    printSubtreeNodes(root->left, k-1);
    printSubtreeNodes(root->right, k-1);

}

int printKnode(node* root, node* target, int k){

    if(root==NULL)
    return -1;

    if(root ==target){
        printSubtreeNodes(root,k);
        return 0;
    }

    int dl= printKnode(root->left, target, k);
    if(dl!=-1){
        if(dl+1 == k)
        cout<<root->data;

        else
        printSubtreeNodes(root->right, k-dl-2);

        return 1+dl;
    }

   int dr= printKnode(root->right, target, k);
    if(dr!=-1){
        if(dr+1 == k)
        cout<<root->data;

        else
        printSubtreeNodes(root->left, k-dr-2);

        return 1+dr;
    }
    return -1;
}

int main(){

      struct node* root=new node(1);

    root->left=new node(2);
    root->right= new node(3);
    /*

             1
           /   \ 
          2     3
         / \   / \
        4   5 6   7
    */

   root->left->left=new node(4);
   root->left->right= new node(5);    
   root->right->left= new node(6);    
   root->right->right= new node(7);     

   int a=printKnode(root, root->left, 1); 

    return 0;
}