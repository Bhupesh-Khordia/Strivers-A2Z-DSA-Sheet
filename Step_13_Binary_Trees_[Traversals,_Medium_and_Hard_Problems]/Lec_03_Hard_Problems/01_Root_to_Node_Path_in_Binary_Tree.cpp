#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void solve(Node* root, vector<int> &output, vector<vector<int>> &ans) {
        if(root == NULL) {
            return;
        }
        output.push_back(root -> data);
        
        if(root -> left == NULL && root -> right == NULL) {
            ans.push_back(output);
        }
        
        solve(root -> left, output, ans);
        solve(root -> right, output, ans);
        output.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(root, output, ans);
        return ans;
    }
};