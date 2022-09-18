#include<iostream>
#include<vector>
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

bool getPath(node* root, int key, vector<int> &path){ // this fuction will return
                                                      // boolean but will also
    if(root==NULL){                                   // give us the path by filling it in vector<int> path
        return false;
    }         

    path.push_back(root->data);
    if(root->data == key){
        return true;
    }

    if(getPath(root->left, key, path)==true || getPath(root->right, key, path)==true ){
        return true;
    }             

    path.pop_back();

    return false;                          


}

int LCA(node* root, int n1, int n2){

    vector<int> path1, path2;

    if(getPath(root, n1, path1)!= true || getPath(root, n2, path2)!= true )
    return -1;

    int path_change;
    
    for(path_change=0; path_change<=path1.size() && path_change<=path1.size(); path_change++){

        if(path1[path_change]!=path2[path_change])
        break;
    }

    return path1[path_change-1];

}

int main(){

    struct node* root=new node(1);

    root->left=new node(2);
    root->right= new node(3);
    
    /*

             1
           /   \ 
         (2)     3
         / \   
        7   4  
           / \
          5   6       clearly for 6 & 7, 2 is the LCA
    */

   root->left->left=new node(7);
   root->left->right= new node(4);    
   root->left->right->left= new node(5);    
   root->left->right->right= new node(6);      

   int lca= LCA(root, 6, 7);   
   cout<<lca;

   return 0; 
}