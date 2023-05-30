void inorder(TreeNode* node){
    if(node == NULL) return ;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}