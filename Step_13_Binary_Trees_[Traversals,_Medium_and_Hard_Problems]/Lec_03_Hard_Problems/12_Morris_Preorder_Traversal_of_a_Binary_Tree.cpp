#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

    // Function to find predecessor
    TreeNode* find (TreeNode* root) {
        TreeNode* pred = root -> left;
        while(pred -> right != NULL && pred -> right != root) {
            pred = pred -> right;
        }
        return pred;
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
        /*
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
        */

        // Morris Traversal
        TreeNode* curr = root;
        vector<int> ans;
        if(root == NULL) return ans;
        while(curr != NULL) {
            if(curr -> left == NULL) {
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
            else {
                TreeNode* pred = find(curr);
                if(pred -> right == NULL) {
                    pred -> right = curr;
                    ans.push_back(curr -> val);
                    curr = curr -> left;
                }
                else {
                    pred -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};