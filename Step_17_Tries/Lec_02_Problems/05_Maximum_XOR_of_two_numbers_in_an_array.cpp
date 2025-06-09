# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class Solution {
public:
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
        int query(int num) {
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

    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxXor = 0;
        
        for(auto i : nums) trie.insert(i);

        for(auto i : nums) {
            maxXor = max(maxXor, trie.query(i));
        }

        return maxXor;

        // In single Pass

        /*
        Trie trie;
        int maxXOR = 0;

        // Insert first number before querying (otherwise a^a = 0)
        trie.insert(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            int bestMatchXOR = trie.query(curr); // returns a^b
            maxXOR = max(maxXOR, bestMatchXOR);
            trie.insert(curr);
        }

        return maxXOR;
        */
    }
};
