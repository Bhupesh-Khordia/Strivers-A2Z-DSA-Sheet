// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

using namespace std;
#include <bits/stdc++.h>

// User function template for C++

class Solution {
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
    
        for(int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
    
        for(int i = k; i < arr.size(); i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    
        return pq.top();
    }
};