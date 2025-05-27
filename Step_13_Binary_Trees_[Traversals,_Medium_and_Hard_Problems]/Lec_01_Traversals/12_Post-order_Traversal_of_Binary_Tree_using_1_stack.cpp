#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    void posto(TreeNode* root, vector<int> &postorder) {
        if(root == NULL) return;

        posto(root -> left, postorder);
        posto(root -> right, postorder);
        postorder.push_back(root -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // Recursive
        /*
        vector<int> arr;
        posto(root, arr);
        return arr;
        */

        // Iterative using 2 stacks
        /*
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()) {
            TreeNode* top = st1.top();
            st1.pop();
            st2.push(top);
            if(top -> left) st1.push(top -> left);
            if(top -> right) st1.push(top -> right);
        }

        while(!st2.empty()) {
            ans.push_back(st2.top() -> val);
            st2.pop();
        }

        return ans;
        */

        // Iterative using single stack
        TreeNode* curr = root;
        stack<TreeNode*> st;
        vector<int> ans;
        while(curr != NULL || !st.empty()) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr -> left;
            } else {
                TreeNode* temp = st.top() -> right;
                if (temp != NULL) curr = temp;
                else {
                    TreeNode* temp = st.top();
                    st.pop();
                    ans.push_back(temp -> val);

                    while(!st.empty() && temp == st.top() -> right) {
                        temp = st.top(); st.pop();
                        ans.push_back(temp -> val);
                    }
                }
            }
        }
        return ans;
    }
};