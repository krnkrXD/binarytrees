#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

// change tree as node.val == node.left.val + node.right.val
void changeTree(node* root){
    if(root == NULL) return ;

    int childSum = 0;
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;

    if(childSum < root->data){
        if(root->left) root->left->data = childSum;
        if(root->right) root->right->data = childSum;
    }

    changeTree(root->left);
    changeTree(root->right);

    childSum = 0;
    if(root->left) childSum += root->left->data;
    if(root->right) childSum  += root->right->data;
    if(root->left || root->right) root->data = childSum;
    return;
}
// TC - O(N)