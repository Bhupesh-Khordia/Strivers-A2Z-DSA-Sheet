# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-complete-tree-nodes/description/

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

    void solve(TreeNode* root, int & ans) {
        if(root == NULL) return;

        if(root -> left) {
            ans++;
            solve(root-> left, ans);
        }

        if(root -> right) {
            ans++;
            solve(root-> right, ans);
        }
    }

    int leftHeight(TreeNode* root) {
        int height = 0;
        while(root) {
            root = root -> left;
            height++;
        }
        return height;
    }

    int rightHeight(TreeNode* root) {
        int height = 0;
        while(root) {
            root = root -> right;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        /*
        int ans = 0;
        if(root != NULL) ans++;
        solve (root, ans);
        return ans;
        */

        // Better Solution

        if(root == NULL) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1 << lh) - 1;
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};