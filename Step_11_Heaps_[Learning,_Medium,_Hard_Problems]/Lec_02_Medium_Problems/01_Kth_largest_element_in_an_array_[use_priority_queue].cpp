// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
    
        for(int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
    
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // Heap has k largest elements of array.
    
        return pq.top();
    }
};