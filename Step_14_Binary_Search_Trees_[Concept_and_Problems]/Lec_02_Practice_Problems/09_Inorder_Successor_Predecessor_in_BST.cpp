#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/inorder-successor-in-bst/description/

// No money :(

// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* temp = root;
        Node* succ = NULL;
        Node* pred = NULL;
        
        while(temp) {
            if(temp -> data <= key) {
                temp = temp -> right;
            } else {
                succ = temp;
                temp = temp -> left;
            }
        }
        
        temp = root;
        while(temp) {
            if(temp -> data >= key) {
                temp = temp -> left;
            } else {
                pred = temp;
                temp = temp -> right;
            }
        }
        
        return {pred, succ};
    }
};