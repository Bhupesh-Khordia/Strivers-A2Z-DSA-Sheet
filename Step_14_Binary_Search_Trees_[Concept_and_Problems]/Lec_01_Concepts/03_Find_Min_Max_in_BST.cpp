#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
        if(!root) return -1;
        
        while(root -> left) root = root -> left;
        return root -> data;
    }
};