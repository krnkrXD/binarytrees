// aka Breadth First Search
// method 1 - using recursion 
// method 2 - using queue

vector<vector<int>> levelorder(TreeNode* Node){
    vector<vector<int>> ans;
    if(Node == NULL){
        ans.push_back({Node->val});
        return ans;
    }

    int heightOfTree = findHeight(Node);

    for (int i = 1; i <= heightOfTree; i++){
        // apply dfs to traverse the tree, if the node belongs to height i add it.
        ans.push_back(nodeOfHeight_i(Node));
    }

    return ans;
}

// method 2 
vector<vector<int>> levelorder(TreeNode* Node){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(Node);

    while(!q.empty()){
        int qsize = q.size();
        vector<int> currlevelnodes;
        for (int i = 1; i <= qsize;i++){
            Node* currNode = q.front();
            q.pop();

            currlevelnodes.push(currNode->val);

            if(!currNode->left) q.push(currNode->left);
            if(!currNode->right) q.push(currNode->right);
        }
        ans.push_back(currlevelnodes);
    }
    return ans;
}