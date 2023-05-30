#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left, * right;
};


vector < int > inOrderTrav(node * curr) {
    vector < int > inOrder;
    stack < node * > s;
    while (true) {
        if (curr != NULL) {  // work as aux stack of recursion
            s.push(curr);
            curr = curr -> left;
        } 
        else {
            if (s.empty()) break; // if all elements traversed
            curr = s.top();
            s.pop();
            inOrder.push_back(curr -> data);
            curr = curr -> right;
        }
    }
    return inOrder;
}