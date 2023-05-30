#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};


// method - check r1.left == r2 left and vice versa.
bool isIdentical(node * node1, node * node2) {
    if (node1 == NULL && node2 == NULL) return true;
    if (node1 == NULL || node2 == NULL) return false;

    return ((node1 -> data == node2 -> data) && 
    isIdentical(node1 -> left, node2 -> left) && 
    isIdentical(node1 -> right, node2 -> right));
}