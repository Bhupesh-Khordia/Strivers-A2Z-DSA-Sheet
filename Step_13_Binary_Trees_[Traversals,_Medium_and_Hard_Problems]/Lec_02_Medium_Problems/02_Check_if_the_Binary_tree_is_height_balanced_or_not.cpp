#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/balanced-binary-tree/description/

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
    pair<int, bool> help (TreeNode* root) {
        if(root == NULL) {
            pair<int, bool> p = make_pair (0, true);
            // First - Height.
            // Second - If Balanced
            return p;
        }
        
        pair<int, bool> ans;
        pair<int, bool> left = help(root -> left);
        pair<int, bool> right = help(root -> right);
        ans.first = max(left.first, right.first) + 1;
        ans.second = (abs(left.first - right.first) <= 1);
        if(left.second == false || right.second == false) ans.second = false;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return help(root).second;
    }
};