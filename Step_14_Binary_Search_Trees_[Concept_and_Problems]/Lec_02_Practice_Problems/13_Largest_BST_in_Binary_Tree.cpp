#include <bits/stdc++.h>
using namespace std;
// --------------------------------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/problems/largest-bst/1
// --------------------------------------------------------------------------------------------------------------------------------

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class info {
  public :
        int size;
        int maxi;
        int mini;
        bool isBST;
};

class Solution {
  private:
    info solve(Node * root, int &ans) {
        if(root == NULL) return {0, INT_MIN, INT_MAX, true};
    
        info left = solve(root -> left, ans);
        info right = solve(root -> right, ans);
    
        info current;
        current.size = left.size + right.size + 1;
        current.maxi = max(root -> data, right.maxi);
        current.mini = min(root -> data, left.mini);
        current.isBST = (left.isBST && right.isBST && root -> data < right.mini && root -> data > left.maxi);
    
        if(current.isBST) ans = max(ans, current.size);
        return current;
    }
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

// --------------------------------------------------------------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/largest-bst-subtree_893103
// --------------------------------------------------------------------------------------------------------------------------------

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

class info {
  public :
        int size;
        int maxi;
        int mini;
        bool isBST;
};

info solve(TreeNode * root, int &ans) {
    if(root == NULL) return {0, INT_MIN, INT_MAX, true};

    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);

    info current;
    current.size = left.size + right.size + 1;
    current.maxi = max(root -> data, right.maxi);
    current.mini = min(root -> data, left.mini);
    current.isBST = (left.isBST && right.isBST && root -> data < right.mini && root -> data > left.maxi);

    if(current.isBST) ans = max(ans, current.size);
    return current;
}

int largestBST(TreeNode * root){
    int ans = 0;
    solve(root, ans);
    return ans;
}