#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool validateBSTUtil(TreeNode *node, long long min, long long max) {
        if (node == NULL) return true;

        if (node->val <= min || node->val >= max) return false;

        return validateBSTUtil(node->left, min, node->val) &&
            validateBSTUtil(node->right, node->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validateBSTUtil(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};