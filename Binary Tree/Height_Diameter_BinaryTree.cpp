#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

   
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

int calHeight(node* root){

    if(root == NULL)
    return 0;

    int lHeight= calHeight(root->left);
    int rHeight= calHeight(root->right);

    return max(lHeight, rHeight)+1;
}


int calDiameter(node* root){

    if(root==NULL)
    return 0;

    int lHeight =calHeight(root->left);
    int rHeight =calHeight(root->right);
    int currDia = lHeight + rHeight +1;

    int lDia = calDiameter(root->left);
    int rDia = calDiameter(root->right);

    return max((lDia,rDia), currDia);

}



int main(){

node* root = new node(1);
root->left=new node(2);
root->right = new node(3);

root->left->left = new node(4);
root->left->right= new node(5);

int a= calHeight(root);
int b= calDiameter(root);
    cout<<a<<" "<<b<<endl;
return 0;

}

