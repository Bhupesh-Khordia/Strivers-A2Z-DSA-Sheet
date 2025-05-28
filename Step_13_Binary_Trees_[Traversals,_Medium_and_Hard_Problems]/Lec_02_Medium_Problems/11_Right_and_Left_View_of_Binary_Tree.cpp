#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    void solve(TreeNode* root, vector<int> &ans, int level) {
        // Base Case
        if(root == NULL) return;
        
        // When we enter a new level, store element's data.
        if(level == ans.size()) {
            ans.push_back(root -> val);
        }
        
        // Recursive Calls
        solve(root -> right, ans, level + 1);
        solve(root -> left, ans, level + 1);
        // For left view, swap the recursive calls. First for root -> left then for right.
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // Can be done iteratively using level order traversal
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};