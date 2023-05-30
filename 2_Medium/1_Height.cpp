int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
// SC - O(N)
// TC - O(N)


// Using Queue/LevelOrderTraversal
int height(TreeNode* root){
    if(root == NULL) return 0;
    int height = 0;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int qsize = q.size();
        for (int i = 0; i < qsize; i++){
            TreeNode *curr = q.front();
            q.pop();

            if(!curr->left) q.push(curr->left);
            if(!curr->right) q.push(curr->right);
        }
        height++;
    }
    return height;
}
// SC - O(N)
// TC - O(N)


// Using Morris Traversal
// SC - constant
int findHeight(TreeNode* root)
{
    int height = 0;
    TreeNode* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            // If left subtree is NULL, move to right subtree
            current = current->right;
            height++; // Increment the height of the tree
        }
        else {
            // Find the inorder predecessor of current node
            TreeNode* pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            if (pre->right == NULL) {
                // Make current node the right child of its
                // inorder predecessor
                pre->right = current;
                current = current->left;
            }
            else {
                // If the right child of the inorder
                // predecessor already points to the current
                // node, then we have traversed the left
                // subtree and its inorder traversal is
                // complete.
                pre->right = NULL;
                current = current->right; // Move to the right subtree
            }
        }
    }
    return height;
}