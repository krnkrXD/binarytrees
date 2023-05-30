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

bool isleaf(TreeNode* root){
    if(!root->left && !root->right) return true;
    return false;
}

// Boundary Nodes
// 1. left boundary
// 2. leaf Nodes
// 3. right boundary

void addleftboundary(TreeNode* root, vector<int>& res){
    TreeNode *curr = root->left;
    while(curr != NULL){
        if(!isleaf(curr)) res.push_back(curr->val);
        // leave if it is leaf. goto left if left not there then right.
        if(curr->left) curr = curr->left;
        else curr = curr -> right;
    }
}

void addrightboundary(TreeNode* root, vector<int>& res){
    vector<int> temp; //cz we have to store in revers
    TreeNode *curr = root->right;
    while(curr != NULL){
        if(!isleaf(curr)) res.push_back(curr->val);
        // go to right if right not there then left.
        if(curr->right) curr = curr->right;
        else curr = curr -> left;
    }
    for (int i = temp.size() - 1; i >= 0; i--){
        res.push_back(temp[i]);
    }
}

void addleaves(TreeNode* root, vector<int>& res){
    if(isleaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left) addleaves(root->left, res);
    if(root->right) addleaves(root->right, res);
}

vector<int> boundary(TreeNode* root){
    vector<int> ans;
    if(!root) return ans; // root==NULL

    if(!isleaf(root)) ans.push_back(root->val);  // root isnot leaf
    
    addleftboundary(root, ans);
    addleaves(root, ans);
    addrightboundary(root, ans);
    
    return ans;
}