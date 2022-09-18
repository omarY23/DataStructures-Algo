#include <bits/stdc++.h>
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

int maxPathUtil(node *root, int &ans)
{ // &ans so that we can edit it

    if (root == NULL)
    {
        return 0;
    }

    int left = maxPathUtil(root->left, ans);
    int right = maxPathUtil(root->right, ans);

    int nodemax = max(max(root->data, root->data + left + right),
                      max(root->data + left, root->data + right));

    ans = max(ans, nodemax);

    int singlepathsum = max(root->data, max(root->data + left, root->data + right));
    /* singlepath sum does not include a root + left + right because we also need to
       consider the ancestors
    */

    return singlepathsum;
}

int maxPathSum(node *root)
{

    int ans = INT_MIN;
    maxPathUtil(root, ans); // although return type is int, but we are interesed in
                            // the modified value of ans

    return ans;
}

int main()
{

    struct node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    /*

             1
           /   \
          2     3
         / \    /\
        4   5  6   7
           / \     \
          8   9     10
    */

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(10);

    int ans = maxPathSum(root);
    cout << ans << endl;

    return 0;
}