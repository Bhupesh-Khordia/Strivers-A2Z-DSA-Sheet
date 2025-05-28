#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/symmetric-tree/description/

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
    bool checkIdentical(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL && root2 != NULL) return false;
        if(root1 != NULL && root2 == NULL) return false;

        return checkIdentical(root1 -> left, root2 -> right) && checkIdentical(root1 -> right, root2 -> left) && root1 -> val == root2 -> val;
    }
public:
    bool isSymmetric(TreeNode* root) {
        // Recursive
        
        // return checkIdentical(root -> left, root -> right);


        // Iterative

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(root -> left);
        q2.push(root -> right);

        while(!q1.empty() && !q2.empty()) {
            TreeNode* top1 = q1.front(); q1.pop();
            TreeNode* top2 = q2.front(); q2.pop();

            if (!top1 && !top2) continue;
            if (!top1 || !top2) return false;
            if (top1->val != top2->val) return false;

            q1.push(top1 -> right);
            q1.push(top1 -> left);
            q2.push(top2 -> left);
            q2.push(top2 -> right);
        }

        return true;
    }
};