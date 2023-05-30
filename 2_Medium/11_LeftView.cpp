#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Method:1 Recursive Level Order Traversal.
// Root Right Left     —-> for Right view
// Root Left Right     —–> for Left view
void solve(TreeNode* root, int level, vector<int>& res){
    if(root == NULL) return;
    if(level == res.size()) res.push_back(root->val);
    solve(root->left, level + 1, res);
    solve(root->right, level + 1, res);
}

vector<int> leftview(TreeNode* root){
    vector<int> res;
    solve(root, 0, res);    // (root, currlevel, res)
    return res;
}