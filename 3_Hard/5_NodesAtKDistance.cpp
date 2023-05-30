#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Alternate Solution : 

Get Path from the Root node and add into a list
For each ith element from Path just iterate and print (K-i)th distance nodes.
*/



class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
        
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track); 
        
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        int curr_level = 0;
        
        queue.push(target);
        visited[target] = true;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                
                // if left of curr node isn't visited.
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                
                // if right of curr node isn't visited.
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                
                // if parent of currnode isn't visited.
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            curr_level++;
        }

        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result; 
    }
};