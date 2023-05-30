#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left, * right;
};


void inOrderTrav(node * root) {
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    stack<pair<node*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        node *curr = st.top().first;
        int num = st.top().second;
        st.pop();
        if(num == 1){
            preorder.push_back(curr->data);
            st.push({root, num + 1});
            if(!curr->left) st.push({curr->left, 1});
        } 
        else if(num == 2){
            inorder.push_back(curr->data);
            st.push({root, num + 1});
            if(!curr->right) st.push({curr->right, 1});
        }
        else{
            postorder.push_back(curr->data);
        }
    }
    for(int x : preorder) cout<<x<<" ";
    cout << endl;
    for(int x : inorder) cout<<x<<" ";
    cout << endl;
    for(int x : postorder) cout<<x<<" ";
    cout << endl;
    return;
}