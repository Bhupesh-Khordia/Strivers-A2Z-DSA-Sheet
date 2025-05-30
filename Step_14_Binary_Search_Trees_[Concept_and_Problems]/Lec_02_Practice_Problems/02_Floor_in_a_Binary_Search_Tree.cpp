#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/floor-in-bst/1

class Solution {

  public:
    int floor(Node* root, int x) {
        Node* temp = root;
        int ans = -1;
        while(temp) {
            if(temp -> data <= x) {
                ans = temp -> data;
                temp = temp -> right;
            } else {
                temp = temp -> left;
            }
        }
        
        return ans;
    }
};