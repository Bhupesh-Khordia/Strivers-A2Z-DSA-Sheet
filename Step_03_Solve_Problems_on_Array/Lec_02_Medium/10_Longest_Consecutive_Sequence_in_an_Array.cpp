// https://leetcode.com/problems/longest-consecutive-sequence/

// IDK why TLE - O(N)
/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        int ans = 0;

        for(auto num : nums) {
            if(s.find(num - 1) == s.end()) {  // Start of sequence
                int len = 1;
                int next = num + 1;
                while(s.find(next) != s.end()) {
                    len++;
                    next++;
                }
                ans = max(ans, len);
            }
        } 
        return ans;
    }
};
*/


// IDK Why works - O(nlogn)

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int currentConsecutiveSequence = 1;
        int longestConsecutiveSequence = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    currentConsecutiveSequence++;
                }
                else{
                    longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                    currentConsecutiveSequence = 1;
                }
            }
        }
        return max(longestConsecutiveSequence, currentConsecutiveSequence);
    }
};
