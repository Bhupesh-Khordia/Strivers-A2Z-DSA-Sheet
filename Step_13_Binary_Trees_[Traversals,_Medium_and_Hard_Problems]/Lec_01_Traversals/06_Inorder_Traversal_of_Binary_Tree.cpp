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
class Solution {
private:
    void ino(TreeNode* root, vector<int> &inorder) {
        if(root == NULL) return;

        ino(root -> left, inorder);
        inorder.push_back(root -> val);
        ino(root -> right, inorder);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        ino(root, arr);
        return arr;
    }
};