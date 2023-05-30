#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Method - 1
// return node, if you get the one of the node.
// if l and r both are node, then return root.
// if l is node and r is NULL, return l.
// if r is node and l is NULL, return r.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return node itself, when it is p or q or NULL
        if(!root or root==p or root==q) return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l != NULL && r != NULL) return root; // l and r have some value, then root is lca.
        if(l != NULL) return l;     // if l isn't null but r is,  return
        else return r;     // if r isn't null but l is, return
    }
};