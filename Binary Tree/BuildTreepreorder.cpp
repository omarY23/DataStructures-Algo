#include <iostream>          
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


/*

Static variables in a Function: When a variable is declared as static,
space for it gets allocated for the lifetime of the program. 
Even if the function is called multiple times, space for the static variable is allocated
only once and the value of variable in the previous call gets carried through the next function call. 
 
*/

int search(int inorder[], int start, int end, int val){
    for(int i=start; i<=end; i++){
        if(inorder[i]==val)
        return i;
    }
    return -1;
}

node* buildTree(int preorder[], int inorder[], int start, int end){  //Returns pointer to every node constructed

if(start>end){                          //base case
    return NULL;
}

static int idx=0;
int val= preorder[idx];
idx++;

node* curr= new node(val);
if(start==end){
    return curr;
}
int pos= search(inorder, start, end, val);

curr->left= buildTree(preorder, inorder, start, pos-1);
curr->right= buildTree(preorder, inorder, pos+1, end);

return curr;
}                               

void inorderPrint(node* root){          //printing the built tree by inorder traversal
    if(root==NULL){
    return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}


int main(){
    int preorder[]= {1, 2, 4, 3, 5};
    int inorder[]= {4, 2, 1, 5, 3};

    node* root=buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}