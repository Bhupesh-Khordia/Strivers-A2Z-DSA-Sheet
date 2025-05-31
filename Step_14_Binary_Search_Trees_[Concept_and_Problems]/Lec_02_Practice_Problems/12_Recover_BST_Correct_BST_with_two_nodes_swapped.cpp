#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/recover-binary-search-tree/description/

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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root -> left);

        if(prev != NULL && root -> val < prev -> val) {
            if(first && middle) {
                last = root;
            } else {
                first = prev;
                middle = root;
            }
        }

        prev = root;
        inorder(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        first = middle = last = NULL;

        inorder(root);

        if(first && last) swap(first -> val, last -> val);
        else if(first && middle) swap(first -> val, middle -> val);
    }
};