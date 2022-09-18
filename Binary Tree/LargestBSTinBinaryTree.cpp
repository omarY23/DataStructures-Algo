#include <iostream> 
#include <climits>         
using namespace std;

struct node{
    int data;
     node* left;
     node* right;

    node(int val){
        data= val;
        left=right=NULL;
    }
    
};

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBinaryTree(node* root){                //function with return type INFO structure

if(root == NULL){
    return {0, INT_MIN, INT_MAX, 0, true};
}

if(root->left == NULL && root->right == NULL){
    return{1, root->data, root->data, 1, true};
}   

Info leftInfo = largestBSTinBinaryTree(root->left);
Info rightInfo = largestBSTinBinaryTree(root->right);

Info curr;
    curr.size = 1 + leftInfo.size + rightInfo.size;
    curr.max = max(rightInfo.max, max(leftInfo.max, root->data));
    curr.min = min(leftInfo.min, min(root->data, rightInfo.min));

if(leftInfo.isBST && rightInfo.isBST && (root->data > leftInfo.max && root->data < rightInfo.min)){

    curr.ans = curr.size;
    curr.isBST = true;

    return curr;

}

    curr.ans = max(leftInfo.ans,rightInfo.ans);
    curr.isBST = false;
    
    return curr;

}


int main(){
    /*
         5
        / \
       3   6
      / \
     2   4

    */
    node* root = new node(5);
    root->left= new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    cout <<"Largest BST in BT: "<< largestBSTinBinaryTree(root).ans << endl;
    return 0;
}

