#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preo(TreeNode* root, vector<int> &preorder) {
        if(root == NULL) return;

        preorder.push_back(root -> val);
        preo(root -> left, preorder);
        preo(root -> right, preorder);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // Recursive
        /*
        vector<int> arr;
        preo(root, arr);
        return arr;
        */

        // Iterative
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* top = st.top();
            st.pop();
            ans.push_back(top -> val);
            if(top -> right) st.push(top -> right);
            if(top -> left) st.push(top -> left);
        }
        return ans;
    }
};