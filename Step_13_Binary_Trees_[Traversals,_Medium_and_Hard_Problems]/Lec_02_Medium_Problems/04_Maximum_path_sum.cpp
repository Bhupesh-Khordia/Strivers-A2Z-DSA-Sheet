#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int findMaxPath(TreeNode* root, int &maxSum) {
        if (root == NULL) return 0;

        // Recursively get the maximum path sum for left and right subtrees
        int leftSum = max(0, findMaxPath(root->left, maxSum));
        int rightSum = max(0, findMaxPath(root->right, maxSum));

        // Calculate the maximum path sum where root is the highest node
        int currentMax = root->val + leftSum + rightSum;

        // Update the global maximum path sum
        maxSum = max(maxSum, currentMax);

        // Return the maximum sum of a path that includes the current node
        return root->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMaxPath(root, maxSum);
        return maxSum;
    }
};