#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

int widthOfBinaryTree(node * root) {
    if (!root) return 0;
    
    int maxWidth = 0;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int size = q.size();
        int curMin = q.front().second;
        int leftMost, rightMost;
        for (int i = 0; i < size; i++) {
            node *temp = q.front().first;
            int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
            q.pop();
            
            if (i == 0) leftMost = cur_id;      // first node of level
            if (i == size - 1) rightMost = cur_id; // last node of level
            
            if (temp -> left)
                q.push({temp->left, cur_id * 2 + 1});
            if (temp -> right)
                q.push({temp->right, cur_id * 2 + 2});
        }
        maxWidth = max(maxWidth, rightMost - leftMost + 1);
    }
    return maxWidth;
}