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
        vector<int> arr;
        posto(root, arr);
        return arr;
    }
};