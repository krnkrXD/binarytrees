// method - 1
// using postorder
TreeNode* MirrorOfTree(TreeNode* node){
    if(node == NULL) return node;

    MirrorOfTree(node->left);
    MirrorOfTree(node->right);

    // swap the nodes
    swap(node->left, node->right);
    return node;
}

// TC- O(N) same as postorder