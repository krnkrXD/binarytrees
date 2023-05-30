#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    
    int inRoot = inMap[root->val];   // index of root in Inorder
    int numsLeft = inRoot - inStart; // numbers on left

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // Build a hashmap to record the relation of value -> index for inorder, 
    // so that we can find the position of root in constant time.
    map<int, int> inMap; 
    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    return 
    buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}
