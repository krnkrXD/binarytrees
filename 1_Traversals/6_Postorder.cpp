#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

// using 2 stacks
vector < int > postordertrav(node * curr) {
    vector < int > postorder;
    stack<node *> s1;
    stack<node *> s2;
    s1.push(curr);
    while(!s1.empty()){
        node *currnode = s1.top();
        s1.pop();

        s2.push(currnode);
    
        if(!currnode->left) s1.push(currnode->left);
        if(!currnode->right) s1.push(currnode->right);
    }

    while(!s2.empty()){
        postorder.push_back(s2.top()->data);
        s2.pop();
    }
    return postorder;
}