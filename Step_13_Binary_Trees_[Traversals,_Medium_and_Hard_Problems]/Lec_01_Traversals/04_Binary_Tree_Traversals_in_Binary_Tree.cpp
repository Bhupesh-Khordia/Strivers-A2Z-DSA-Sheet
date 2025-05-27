#include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/tree-traversal_981269?leftPanelTabValue=PROBLEM

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void ino(TreeNode* root, vector<int> &inorder) {
    if(root == NULL) return;

    ino(root -> left, inorder);
    inorder.push_back(root -> data);
    ino(root -> right, inorder);
}

void preo(TreeNode* root, vector<int> &preorder) {
    if(root == NULL) return;

    preorder.push_back(root -> data);
    preo(root -> left, preorder);
    preo(root -> right, preorder);
}

void posto(TreeNode* root, vector<int> &postorder) {
    if(root == NULL) return;

    posto(root -> left, postorder);
    posto(root -> right, postorder);
    postorder.push_back(root -> data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;

    vector<int> traversal;

    ino(root, traversal);

    ans.push_back(traversal);
    traversal.clear();

    preo(root, traversal);

    ans.push_back(traversal);
    traversal.clear();

    posto(root, traversal);

    ans.push_back(traversal);
    traversal.clear();

    return ans;
}