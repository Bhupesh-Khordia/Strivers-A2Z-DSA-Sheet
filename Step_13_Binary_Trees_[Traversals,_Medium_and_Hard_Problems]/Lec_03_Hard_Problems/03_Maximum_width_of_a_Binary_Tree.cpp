#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int max_width = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int level_size = q.size();
            int start_index = q.front().second;
            int end_index = q.back().second;
            max_width = max(max_width, end_index - start_index + 1);
            
            for (int i = 0; i < level_size; ++i) {
                auto node_index_pair = q.front();
                TreeNode* node = node_index_pair.first;
                int node_index = node_index_pair.second - start_index;  // To prevent overflow
                q.pop();
                
                if (node->left != nullptr) {
                    q.push({node->left, 2LL * node_index + 1});
                }
                
                if (node->right != nullptr) {
                    q.push({node->right, 2LL * node_index + 2});
                }
            }
        }
        
        return max_width;
    }
};

// Brute Force - MLE
/*
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        int width = 1;
        q.push(root);


        while(!q.empty()) {
            int first = -1, last = -1;
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();

                if(top != NULL) {
                    if(first == -1) first = i;
                    last = i;
                }

                if(top != NULL) {
                    q.push(top->left);
                    q.push(top->right);
                } else {
                    // still push NULLs to preserve position
                    q.push(NULL);
                    q.push(NULL);
                }
            }

            // If there were no non-null nodes, skip further processing
            if(first == -1) break;

            width = max(width, last - first + 1);
        }

        return width;
    }
};
*/