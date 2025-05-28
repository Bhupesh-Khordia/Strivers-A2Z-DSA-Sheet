#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<pair<Node *, int>> q;
        map <int, int> mapper;
    
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            Node * frontNode = q.front().first;
            int hd = q.front().second;
    
            q.pop();
    
            // if(mapper.find(hd) == mapper.end()) 
            mapper[hd] = frontNode -> data;
    
            if(frontNode -> left) q.push(make_pair(frontNode -> left, hd - 1));
            if(frontNode -> right) q.push(make_pair(frontNode -> right, hd + 1));
        }
    
        for(auto i : mapper) {
            ans.push_back(i.second);
        }
        return ans;
    }
};