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


node* LCA(node* root, int n1, int n2){          //function to find least common ancestor

    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data== n2)
    return root;

    node* left= LCA(root->left, n1,n2);
    node* right= LCA(root->right, n1,n2);

    if(left!=NULL && right!=NULL)
    return root;

    if(left==NULL && right==NULL)
    return NULL;

    if(left!=NULL)
    return  LCA(root->left,n1,n2);

    return LCA(root->right,n1,n2);

}

int findDistance(node* root, int k, int dist){
    if(root== NULL)
    return -1;

    if(root->data== k)
    return dist;

    int left= findDistance(root->left, k, dist+1);

    if(left!=-1){
        return left;
    }
    
    return findDistance(root->right,k, dist+1);
}

int leastDistance(node* root, int n1,int n2){

    node* lca= LCA(root, n1,n2);
    int d1= findDistance(lca, n1,0);
    int d2= findDistance(lca, n2,0);

    return d1+d2;
}