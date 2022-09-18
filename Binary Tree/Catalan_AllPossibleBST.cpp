// #include <bits/stdc++.h>
// using namespace std;
// struct node{
//     int data;
//     struct node* left;
//     struct node* right;

//     node(int val){
//         data= val;
//         left=right=NULL;
//     }
    
// };

// vector<node*> constructTrees(int start, int end){
    
//     vector<node*> trees;
//     if(start>end){
        
//     }

//     for(int i=start; i<=end; i++){
//         vector<node*> leftSubtrees = constructTrees(start, i-1);
//         vector<node*> rightSubtrees = constructTrees(i+1, end);

//         for(int j=0; j<leftSubtrees.size(); j++){
//             node* left = leftSubtrees[j];
//             for (int k = 0; k < rightSubtrees.size(); k++)
//             {
//                 node* right= rightSubtrees[k];
//                 node* n= new node(i);

//                 n->left = left;
//                 n->right = right;
//                 trees.push_back(n);
//             }
            
//         }

//     }
//     return trees;
// }


// int main(){

//     return 0;
// }