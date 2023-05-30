
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> zigzagLevelOrder(Node * root) {
    vector < vector < int >> result;
    if (root == NULL) {
        return result;
    }

    queue < Node * > nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector < int > row(size);
        for (int i = 0; i < size; i++) {
        Node * node = nodesQueue.front();
        nodesQueue.pop();

        // find position to fill node's value
        int index = (leftToRight) ? i : (size - 1 - i);

        row[index] = node -> data;
        if (node -> left) {
            nodesQueue.push(node -> left);
        }
        if (node -> right) {
            nodesQueue.push(node -> right);
        }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}