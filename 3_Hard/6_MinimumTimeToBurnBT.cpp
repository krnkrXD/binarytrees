#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



class Solution {
    Node* markParents(Node* root, unordered_map<Node*, Node*> &parent_track, int target) {
        queue<Node*> queue;
        queue.push(root);
        Node* res = NULL;
        while(!queue.empty()) { 
            Node* current = queue.front(); queue.pop();
            if(current->data == target) res = current; // store the target node.
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
        return res;
    }
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_track;
        Node* startnode = markParents(root, parent_track, target);
        
        queue<Node*> queue;
        unordered_map<Node*, int> visited;
        
        queue.push(startnode);
        visited[startnode] = 1;
        
        int time = 0;
        while(!queue.empty()){
            int size = queue.size();
            int burnt = 0;
            for(int i=0; i<size; i++) {
                Node* current = queue.front(); queue.pop();
                
                // if left of curr node isn't visited.
                if(current->left && !visited[current->left]) {
                    burnt = 1;
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                
                // if right of curr node isn't visited.
                if(current->right && !visited[current->right]) {
                    burnt = 1;
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                
                // if parent of currnode isn't visited.
                if(parent_track[current] && !visited[parent_track[current]]) {
                    burnt = 1;
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            if(burnt) time++;
        }
        return time;
    }
};