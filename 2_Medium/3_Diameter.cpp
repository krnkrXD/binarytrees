#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left, * right;
};
// maximum of 3 values:
// left height + right height + 1
// maximum diameter of right subtree
// maximum diameter of left subtree).


// method - 1
// find height of left and right subtree seperately
// then call the diameter function
int diameter(node* node){
    if(node == NULL) return 1;
    int lHeight = height(node->left);
    int rHeight = height(node->right);

    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);
    return max(lHeight + rHeight + 1, max(ldiameter, rdiameter));
}
// TC - O(N^2)
// SC - O(N)


// method - 2
// can we optimize the calling of height and diameter?
// Yes, we can use post order traversal.
// where we can just call on left and right then compute on currnode
// and pass the diameter globally

int height(node* node, int& diameter){
    if(node == NULL) return 0;
    int lHeight = height(node->left, diameter);
    int rHeight = height(node->right, diameter);
    diameter = max(lHeight + rHeight + 1, diameter);
    return max(lHeight, rHeight) + 1;
}

int diameter (node* node){
    int diameter = 0;
    height(node, diameter);
    return diameter;
}
// TC - O(N)  ->  POSTORDER