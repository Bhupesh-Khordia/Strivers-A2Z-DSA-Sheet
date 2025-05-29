#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode* solve(vector<int> in,vector<int> post, int n, int &index, int inorderStart, int inorderEnd, map<int, int> &mapper) {
        // Base Case
        if(index < 0 || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = post[index--];
        int position = mapper[element];
        TreeNode* root = new TreeNode(element);
        
        root -> right = solve(in, post, n, index, position + 1, inorderEnd, mapper);
        root -> left = solve(in, post, n, index, inorderStart, position - 1, mapper);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index = n - 1;  // To Trverse in Postorder Array.
        map<int, int> mapper;   // To Map Node to Index of Inorder Array
        for(int i = 0; i < n; i++) {
            mapper[inorder[i]] = i;
        }
        TreeNode* root = solve(inorder, postorder, n, index, 0, n-1, mapper);
        return root;
    }
};