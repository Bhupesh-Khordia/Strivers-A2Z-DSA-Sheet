#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/boundary-of-binary-tree/description/

// No money to buy premium :(



// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
    void traverseLeft (Node *root, vector<int> &ans) {
        // Base Case
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)) return;
    
        // Push Answer
        ans.push_back(root -> data);
    
        // Recursive Call
        if(root -> left) traverseLeft(root -> left, ans);
        else traverseLeft(root -> right, ans);
    }
    
    void traverseLeaf (Node *root, vector<int> &ans) {
        // Base Case
        if(root == NULL) return;
    
        // Push Answer
        if(root -> left == NULL && root -> right == NULL) {
            ans.push_back(root -> data);
            return;
        }
    
        // Recursive Call
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
    }
    
    void traverseRight (Node *root, vector<int> &ans) {
        // Base Case
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)) return;
    
        // Recursive Call
        if(root -> right) traverseRight(root -> right, ans);
        else traverseRight(root -> left, ans);
    
        // When returning, push answer, so that we get reversed order.
        ans.push_back(root -> data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root -> data);
    
        // Print Left Wala Part.
        traverseLeft(root -> left, ans);
        // Print Leaf Wala Part.
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
        // Print Right Wala Part.
        traverseRight(root -> right, ans);
    
        return ans;
    }
};




// https://www.naukri.com/code360/problems/boundary-traversal_790725

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void traverseLeft (TreeNode<int> *root, vector<int> &ans) {
    // Base Case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)) return;

    // Push Answer
    ans.push_back(root -> data);

    // Recursive Call
    if(root -> left) traverseLeft(root -> left, ans);
    else traverseLeft(root -> right, ans);
}

void traverseLeaf (TreeNode<int> *root, vector<int> &ans) {
    // Base Case
    if(root == NULL) return;

    // Push Answer
    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
        return;
    }

    // Recursive Call
    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
}

void traverseRight (TreeNode<int> *root, vector<int> &ans) {
    // Base Case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)) return;

    // Recursive Call
    if(root -> right) traverseRight(root -> right, ans);
    else traverseRight(root -> left, ans);

    // When returning, push answer, so that we get reversed order.
    ans.push_back(root -> data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    ans.push_back(root -> data);

    // Print Left Wala Part.
    traverseLeft(root -> left, ans);
    // Print Leaf Wala Part.
    // Dont print in one go, then in case of only one node in tree, it will be printed twice (again in traverseLeaf function).
    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
    // Print Right Wala Part.
    traverseRight(root -> right, ans);

    return ans;
}
