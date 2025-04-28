// https://leetcode.com/problems/sliding-window-maximum/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq; // In decreasing order
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            while(!deq.empty() && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);

            if(i >= k && deq.front() == nums[i-k]) {
            deq.pop_front();
            } 

            if(i >= k - 1) ans.push_back(deq.front());
        }

        return ans;
    }
};