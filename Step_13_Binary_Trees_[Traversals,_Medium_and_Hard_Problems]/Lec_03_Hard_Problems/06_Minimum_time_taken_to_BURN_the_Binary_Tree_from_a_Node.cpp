#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/burning-tree/1


/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    Node* createMapping(Node* root, int target, map <Node*, Node*> &nodeToParent) {
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        Node* res;
        
        while(!q.empty()) {
            Node* frontNode = q.front();
            q.pop();
            
            if(frontNode -> data == target) {
                res = frontNode;
            }
            
            if(frontNode -> left) {
                q.push(frontNode -> left);
                nodeToParent[frontNode-> left] = frontNode;
            }
            
            if(frontNode -> right) {
                q.push(frontNode -> right);
                nodeToParent[frontNode-> right] = frontNode;
            }
            
        }
        
        return res;
    }
    
    int burnTree(Node* targetNode, map <Node*, Node*> nodeToParent) {
        queue<Node*> q;
        q.push(targetNode);
        int ans = 0;
        map<Node*, bool> visited;
        visited[targetNode] = true;
        
        while(!q.empty()) {
            int size = q.size();
            bool sizeChange = false;
            
            for(int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();
                if(frontNode -> left && !visited[frontNode -> left]) {
                    visited[frontNode -> left] = true;
                    sizeChange = true;
                    q.push(frontNode -> left);
                }
                if(frontNode -> right && !visited[frontNode -> right]) {
                    visited[frontNode -> right] = true;
                    sizeChange = true;
                    q.push(frontNode -> right);
                }
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]) {
                    visited[nodeToParent[frontNode]] = true;
                    sizeChange = true;
                    q.push(nodeToParent[frontNode]);
                }
            }
            
            if(sizeChange) ans++;
        }
        
        return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
        map <Node*, Node*> nodeToParent;
        Node* targetNode = createMapping(root, target, nodeToParent);
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};