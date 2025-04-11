class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // This is moore Voting Algorithm
        int cnt = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                // Initialize Ans
                ans = nums[i];
                cnt++;
            } else {
                if(nums[i] == ans) cnt++;
                else cnt--;
            }
        }
        return ans;
    }
};
