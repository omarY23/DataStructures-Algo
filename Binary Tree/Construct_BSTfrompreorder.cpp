#include <bits/stdc++.h>
using namespace std;

//best problem for recursion

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

node* constructBST(int preorder[], int* idx, int key, int min, int max, int n){

    if(*idx>=n){

        return NULL;
    }
    node* root = NULL;

    if(key> min && key<max){
    root = new node(key);
    *idx = *idx +1;
    
    if(*idx <n){
        root->left = constructBST(preorder, idx, preorder[*idx], min, key , n);
        // the max and min that we pass also gets updated like the key
        
    }
    if(*idx <n){
        root->right = constructBST(preorder, idx, preorder[*idx], key, max, n);

    }

    }
    return root;

}

void printlevelOrder(node* root){
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
    // cout<<sum<<endl;
}

int main(){

    int preorder[] = {7, 5, 4, 6, 8, 9};
    int n= sizeof(preorder);
    int idx= 0;

    node* root= constructBST(preorder, &idx, preorder[idx], INT_MIN, INT_MAX, n);
    printlevelOrder(root);

    return 0;
}