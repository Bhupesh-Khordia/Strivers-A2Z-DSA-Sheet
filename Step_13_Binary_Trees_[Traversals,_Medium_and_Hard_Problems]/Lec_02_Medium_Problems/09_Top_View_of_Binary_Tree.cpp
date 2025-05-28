#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<pair<Node *, int>> q;
        map <int, int> mapper;
    
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            Node * frontNode = q.front().first;
            int hd = q.front().second;
    
            q.pop();
    
            if(mapper.find(hd) == mapper.end()) mapper[hd] = frontNode -> data;
    
            if(frontNode -> left) q.push(make_pair(frontNode -> left, hd - 1));
            if(frontNode -> right) q.push(make_pair(frontNode -> right, hd + 1));
        }
    
        for(auto i : mapper) {
            ans.push_back(i.second);
        }
        return ans;
    }

};
