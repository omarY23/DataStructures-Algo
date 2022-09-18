#include<bits/stdc++.h>             //best conceptual problem for node pointers
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left= NULL;
        right= NULL;
    }
};

void zigzagTraversal(node* root, int n){                // My approach
    bool left_to_right = true;
    stack<node*> currLevel, nextLevel;
    int arr[n];

    currLevel.push(root);

    for(int i= 0; i<n; i++){

        if(left_to_right){
            if(currLevel.top()->left != NULL)
            nextLevel.push(currLevel.top()->left);
            if(currLevel.top()->right != NULL)
            nextLevel.push(currLevel.top()->right);
            arr[i] = currLevel.top()->data;
            currLevel.pop();
        }

        else{
            if(currLevel.top()->right != NULL)
            nextLevel.push(currLevel.top()->right);
            if(currLevel.top()->left != NULL)
            nextLevel.push(currLevel.top()->left);
            arr[i] = currLevel.top()->data;
            currLevel.pop();           
        }

        if(currLevel.empty()){

            swap(currLevel, nextLevel);

            if(left_to_right)
            left_to_right= false;
            
            else if (left_to_right!=true)
            left_to_right= true;
        }
      

    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){

    struct node* root=new node(1);

/*             1
              / \ 
             2   3
            / \   \
           4   5   6
              / \
             7   8
            
*/

// expexted output :  1 3 2 4 5 6 8 7

    root->left=new node(2);
    root->right= new node(3);
    
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->right = new node(6);

    root->left->right->left = new node(7);
    root->left->right->right = new node(8);


    zigzagTraversal(root, 8);
    return 0;
}


