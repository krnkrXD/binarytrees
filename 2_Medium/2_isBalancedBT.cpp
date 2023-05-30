#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

// Method - 1
// find the height of every node
// and checks abs(h(r) - h(l)) < 1.
// TC - O(N*N)    
//      N - for everynode, N - TC of find height

// Method - 2
// Use post order
// first go to left then right, then solve on curr node.
// if left isnot balance, curr isnot balanced too
// if right isnot balance, curr isnot balanced too
// -1 indicates, subtree isn't balances
bool isBalanced(node* root) {
    return dfsHeight (root) != -1;
}

int dfsHeight (node* root) {
    if (root == NULL) return 0;
    
    int leftHeight = dfsHeight (root -> left);
    if (leftHeight == -1) return -1;
    
    int rightHeight = dfsHeight (root -> right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1)  return -1;
    return max (leftHeight, rightHeight) + 1;
}
