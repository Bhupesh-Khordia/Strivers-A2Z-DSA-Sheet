#include <bits/stdc++.h>
using namespace std;

//  https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL) s += "#,";
            else {
                s += to_string(top -> val) + ',';
            }

            if(top != NULL) {
                q.push(top -> left);
                q.push(top -> right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") {
                node -> left = NULL;
            } else {
                node -> left = new TreeNode(stoi(str));
                q.push(node -> left);
            }

            getline(s, str, ',');
            if(str == "#") {
                node -> right = NULL;
            } else {
                node -> right = new TreeNode(stoi(str));
                q.push(node -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


// Does not handle duplicate elements.
/*
class Codec {
private:
    void inorder(TreeNode* root, vector<int> & traversal) {
        if(root == NULL) return;

        inorder(root -> left, traversal);
        traversal.push_back(root -> val);
        inorder(root -> right, traversal);
    }

    void preorder(TreeNode* root, vector<int> & traversal) {
        if(root == NULL) return;

        traversal.push_back(root -> val);
        preorder(root -> left, traversal);
        preorder(root -> right, traversal);
    }

    TreeNode* makeTree(vector<int> in,vector<int> pre, int n, int &index, int inorderStart, int inorderEnd, unordered_map<int, int> &mapper) {
        // Base Case
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = pre[index++];
        int position = mapper[element];
        TreeNode* root = new TreeNode(element);
        
        root -> left = makeTree(in, pre, n, index, inorderStart, position - 1, mapper);
        root -> right = makeTree(in, pre, n, index, position + 1, inorderEnd, mapper);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root) return s;
        vector<int> traversal;

        inorder(root, traversal);
        for (int i = 0; i < traversal.size(); ++i) {
            s += to_string(traversal[i]);
            s += ',';
        }
        s += '|'; // delimiter between inorder and preorder

        traversal.clear();

        preorder(root, traversal);
        for (int i = 0; i < traversal.size(); ++i) {
            s += to_string(traversal[i]);
            s += ',';
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        vector<int> inorder;
        vector<int> preorder;

        int prevIndex = 0;
        bool inorderInsert = true;

        for(int i = 0; i < data.length(); i++) {
            if(inorderInsert) {
                if(data[i] == ',') {
                    inorder.push_back(stoi(data.substr(prevIndex, i - prevIndex)));
                    prevIndex = i + 1;
                } else if (data [i] == '|') {
                    inorderInsert = false;
                    prevIndex = i + 1;
                }
            } else {
                if(data[i] == ',') {
                    preorder.push_back(stoi(data.substr(prevIndex, i - prevIndex)));
                    prevIndex = i + 1;
                }
            }
        }

        int index = 0;  // To Trverse in Preorder Array.
        int n = preorder.size();
        unordered_map<int, int> mapper;   // To Map Node to Index of Inorder Array
        for(int i = 0; i < n; i++) {
            mapper[inorder[i]] = i;
        }
        TreeNode* root = makeTree(inorder, preorder, n, index, 0, n-1, mapper);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

*/