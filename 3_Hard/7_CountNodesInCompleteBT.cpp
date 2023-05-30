#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}


// Method1
// Count the nodes of BT while traversing.
// it can be preorder, postorder, or level
void inOrderTrav(node * curr, int& count) {
    if (curr == NULL)
        return;

    count++;
    inOrderTrav(curr -> left, count);
    inOrderTrav(curr -> right, count);
}



// Method 2
// Find the left most height and righ most height
// if LH == RH, that means all the element present.
// else, find the nodes in left subtree and right subtree.
int findHeightLeft(node* cur) {
    int hght = 0; 
    while(cur) {
        hght++; 
        cur = cur->left; 
    }
    return hght; 
}
int findHeightRight(node* cur) {
    int hght = 0; 
    while(cur) {
        hght++; 
        cur = cur->right; 
    }
    return hght; 
}

int countNodes(node* root) {
    if(root == NULL) return 0; 
    
    int lh = findHeightLeft(root); 
    int rh = findHeightRight(root); 
    
    if(lh == rh) return (1<<lh) - 1;  // pow(2,lh)
    
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    
    return 1 + leftNodes + rightNodes; 
}