#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/children-sum-parent/1

/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    pair<bool, int> isSum (Node* root) {
        // First - is Sum
        // Second - Sum
        if(root == NULL) return {true, 0};
        
        if(root -> left == NULL && root -> right == NULL) return {true, root -> data};
        
        auto left = isSum(root -> left);
        auto right = isSum(root -> right);
        
        return {left.first && right.first && (root -> data == left.second + right.second), root -> data};
    }
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        return isSum(root).first;
    }
};