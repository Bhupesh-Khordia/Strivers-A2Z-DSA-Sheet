// https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        if(nums.size() == 1) return nums[0] == 1;
        if(nums[0] == 1){
            cnt = 1;
            ans = max(ans, cnt);
        }
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == 1) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
