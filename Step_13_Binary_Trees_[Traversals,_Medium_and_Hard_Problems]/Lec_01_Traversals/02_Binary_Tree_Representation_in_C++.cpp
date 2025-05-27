#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/binary-tree-representation/1

// User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution{
public:
    void create_tree(node* root0, vector<int> &v){
        deque<node*> que;
        que.push_back(root0);
        
        int i=0;
        while(!que.empty()) {
            node* cur = que.front();
            que.pop_front();
            
            if((2*i + 1) < 7) {
                cur->left = newNode(v[2*i + 1]);
                que.push_back(cur->left);
            }
            if((2*i + 2) < 7) {
                cur->right = newNode(v[2*i + 2]);
                que.push_back(cur->right);
            }
            i++;
        }
    }

};