#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    TreeNode *getBST(vector<int>& preorder,int maxi,int &index){
        if(index==preorder.size()|| preorder[index]>maxi ){
            return NULL;
        }
        
        TreeNode *root=new TreeNode(preorder[index++]);
        
        root->left=getBST(preorder,root->val,index);
        
        root->right=getBST(preorder,maxi,index);
        
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
      int index=0;
      return getBST(preorder,INT_MAX,index);
        
    }
};