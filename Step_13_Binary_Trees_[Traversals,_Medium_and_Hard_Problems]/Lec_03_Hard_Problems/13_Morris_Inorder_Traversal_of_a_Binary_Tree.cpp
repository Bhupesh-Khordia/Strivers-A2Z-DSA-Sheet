#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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



 // MORRIS TRAVERSAL

class Solution {
private:
    // Function to find predecessor
    TreeNode* find (TreeNode* root) {
        TreeNode* pred = root -> left;
        while(pred -> right != NULL && pred -> right != root) {
            pred = pred -> right;
        }
        return pred;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    curr = curr -> left;
                }
                else {
                    pred -> right = NULL;
                    ans.push_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};