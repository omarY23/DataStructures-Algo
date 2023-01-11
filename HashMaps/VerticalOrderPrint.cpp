/*----------------Print the vertical ordr of a binary tree using hahmaps------------------*/

#include<iostream>
#include<map>
#include<vector>

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

// No return type but modifies our map into the required map with key value pair
// By default, a Map in C++ is sorted in increasing order based on its key.
void verticalOrderPrint(node* root, int hdis, map<int, vector<int>> &m){     

    if(root == NULL)
        return;
    
    m[hdis].push_back(root->data);
    verticalOrderPrint(root->left, hdis-1, m);
    verticalOrderPrint(root->right, hdis+1, m);
    
}


int main(){

    node* root;
    root = new node(10);
    root->left = new node(3);
    root->right = new node(13);
    root->left->left = new node(1);
    root->left->right = new node(8);
    root->right->left = new node(11);
    root->right->right = new node(24);

    int hdis=0;
    map<int, vector<int>> m;

    verticalOrderPrint(root, hdis, m);

    map<int, vector<int>> ::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->second.size()); i++)
        {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}