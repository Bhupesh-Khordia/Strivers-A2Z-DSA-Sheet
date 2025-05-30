#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

int findCeil(Node* root, int input) {
    Node* temp = root;
    int ans = -1;
    while(temp) {
        if(temp -> data >= input) {
            ans = temp -> data;
            temp = temp -> left;
        } else {
            temp = temp -> right;
        }
    }
    return ans;
}