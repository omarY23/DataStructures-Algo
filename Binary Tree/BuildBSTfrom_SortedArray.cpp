#include <iostream>
using namespace std;

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

node* buildfromSortedArray(int arr[], int n, int start, int end){

    if(start>end){
        return NULL;
    }

    int mid= (start + end)/2;
    node* root= NULL;
  
        root =new node(arr[mid]);
       
        root->left = buildfromSortedArray(arr, n, start, mid-1);
                
        root->right = buildfromSortedArray(arr, n, mid, end);
         
 return root;  
   
}