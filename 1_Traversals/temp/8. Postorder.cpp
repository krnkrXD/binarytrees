#include<bits/stdc++.h>
using namespace std;

void postorder(){
    if(root == NULL) return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}