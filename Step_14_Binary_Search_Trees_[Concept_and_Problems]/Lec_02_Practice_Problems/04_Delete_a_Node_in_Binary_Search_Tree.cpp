#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    int minVal(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }

        TreeNode* temp = root;
        while(temp->left) {
            temp = temp->left;
        }

        return temp->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return root;
        }

        if(root->val == key) {
            
            // 0 Child
            if(root->left==NULL && root->right==NULL) {
                delete root;
                return NULL;
            }

            // 1 Child
            // Left Child
            if(root->left!=NULL && root->right==NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Right Child
            if(root->left==NULL && root->right!=NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 2 Child
            if(root->left!=NULL && root->right!=NULL) {
                int mini = minVal(root->right);
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }

        } else if(key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            root->left = deleteNode(root->left, key);
            return root;
        }
        return root;
    }
};