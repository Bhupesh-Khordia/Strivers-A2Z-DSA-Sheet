// https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int subarraysWithLTEKDistinct(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), ans = 0;
        unordered_map<int, int> cnt;

        while(r < n) {
            cnt[nums[r]]++;
            while(cnt.size() > k) {
                cnt[nums[l]]--;
                if(cnt[nums[l]] == 0) cnt.erase(nums[l]);
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithLTEKDistinct(nums, k) - subarraysWithLTEKDistinct(nums, k - 1);
    }
};