#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }

        if(root -> val < val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);

        return root;
    }
};