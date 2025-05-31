#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    void inorderTraversal (TreeNode* root, vector<int> &inorder) {
        if(root == NULL) {
            return;
        }

        inorderTraversal(root -> left, inorder);
        inorder.push_back(root -> val);
        inorderTraversal(root -> right, inorder);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int i =0, j = inorder.size() -1;
        while(i < j) {
            int sum = inorder[i] + inorder[j];
            if(sum == k) return true;
            if(sum > k) j--;
            else i++;
        }
        return false;
    }
};