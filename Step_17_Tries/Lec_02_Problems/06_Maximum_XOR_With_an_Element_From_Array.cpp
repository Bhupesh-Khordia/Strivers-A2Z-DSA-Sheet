# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/



// This code of Trie class is also used in - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class Trie {
public:
    struct Node {
        Node* left;  // bit 0
        Node* right; // bit 1
        Node() : left(nullptr), right(nullptr) {}
    };

    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* curr = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (!curr->left) curr->left = new Node();
                curr = curr->left;
            } else {
                if (!curr->right) curr->right = new Node();
                curr = curr->right;
            }
        }
    }
    // Returns the maximum possible XOR result of num ^ nums[i] for all i
    int findMax(int num) {
        Node* curr = root;
        int result = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (curr->right) {
                    result |= (1 << i); // 0 ^ 1 = 1
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->left) {
                    result |= (1 << i); // 1 ^ 0 = 1
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int,int>>> oQ; // offline queries {limit, {element, index}}
        int q = queries.size();
        for(int i = 0; i < q; i++) {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oQ.begin(), oQ.end()); // on basis of limit


        vector<int> ans(q, 0);
        int ind = 0; // to traverse in original nums
        int n = nums.size();
        Trie trie;
        for(int i = 0; i < q; i++) {
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;

            while(ind < n && nums[ind] <= ai) {
                trie.insert(nums[ind]);
                ind++;
            }

            if(ind == 0) ans[qInd] = -1;
            else ans[qInd] = trie.findMax(xi);
        }

        return ans;
    }
};