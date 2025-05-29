#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode* solve(vector<int> in,vector<int> pre, int n, int &index, int inorderStart, int inorderEnd, map<int, int> &mapper) {
        // Base Case
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = pre[index++];
        int position = mapper[element];
        TreeNode* root = new TreeNode(element);
        
        root -> left = solve(in, pre, n, index, inorderStart, position - 1, mapper);
        root -> right = solve(in, pre, n, index, position + 1, inorderEnd, mapper);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;  // To Trverse in Preorder Array.
        int n = preorder.size();
        map<int, int> mapper;   // To Map Node to Index of Inorder Array
        for(int i = 0; i < n; i++) {
            mapper[inorder[i]] = i;
        }
        TreeNode* root = solve(inorder, preorder, n, index, 0, n-1, mapper);
        return root;
    }
};