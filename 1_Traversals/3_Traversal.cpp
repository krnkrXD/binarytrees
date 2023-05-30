#include<bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

void preorder(node * root, vector < int > & preOrder){
    if(root == NULL) return ;

    preOrder.push_back(root->data);
    preorder(root->left, preOrder);
    preorder(root->right, preOrder);
}

void postorder(node * root, vector < int > & postOrder){
    if(root == NULL) return ;

    postorder(root->left, postOrder);
    postorder(root->right, postOrder);
    postOrder.push_back(root->data);
}

// LevelOrderTraversal aka Breadth First Search
// method 1 - using recursion 
vector<vector<int>> levelorder(node* Node){
    vector<vector<int>> ans;
    if(Node == NULL){
        ans.push_back({Node->data});
        return ans;
    }

    // int heightOfTree = findHeight(Node);

    for (int i = 1; i <= heightOfTree; i++){
        // apply dfs to traverse the tree, if the node belongs to height i add it.
        // ans.push_back(nodesAtHeight_i(Node));
    }

    return ans;
}

// method 2 Using queue
vector<vector<int>> levelorder(node* Node){
    vector<vector<int>> ans;
    queue<node*> q;
    q.push(Node);

    while(!q.empty()){
        int qsize = q.size();
        vector<int> currlevelnodes;
        for (int i = 1; i <= qsize;i++){
            node* currNode = q.front();
            q.pop();

            currlevelnodes.push_back(currNode->data);

            if(!currNode->left) q.push(currNode->left);
            if(!currNode->right) q.push(currNode->right);
        }
        ans.push_back(currlevelnodes);
    }
    return ans;
}