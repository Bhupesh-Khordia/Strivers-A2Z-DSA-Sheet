// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Brute Force
        /*
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if(sum == k) ans++;
            }
        }
        return ans;
        */
        
        
        // /*
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            int remaining = sum - k;
            if(map.find(remaining) != map.end()) {
                ans += map[remaining];
            }
            map[sum]++;
        }
        return ans;
        // */
    }
};
