#include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/tree-traversal_981269

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/


vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Iterative in single traversal

    vector<vector<int>> ans;

    if(!root) return ans;

    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    // 1 - Preorder
    // 2 - Inorder
    // 3 - Postorder
    while(!st.empty()) {
        pair<TreeNode*, int> top = st.top(); st.pop();
        TreeNode* topNode = top.first;
        int num = top.second;

        switch (num) {
            case 1:
                preorder.push_back(topNode -> data);
                st.push({topNode, num + 1});

                if(topNode -> left) st.push({topNode -> left, 1});
                break;
            case 2:
                inorder.push_back(topNode -> data);
                st.push({topNode, num + 1});

                if(topNode -> right) st.push({topNode -> right, 1});
                break;
            case 3:
                postorder.push_back(topNode -> data);
                break;
        }

    }

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}


// https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/1


/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        vector<int> ans;
        if(!node) return ans;
        stack<Node*> st1;
        st1.push(node);

        while(!st1.empty()) {
            Node* top = st1.top();
            st1.pop();
            ans.push_back(top -> data);
            if(top -> left) st1.push(top -> left);
            if(top -> right) st1.push(top -> right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};