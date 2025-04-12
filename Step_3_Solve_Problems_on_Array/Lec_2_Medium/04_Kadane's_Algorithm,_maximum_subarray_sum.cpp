class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Brute Force
        /*
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                ans = max(ans, sum);
            }
        }
        return ans;
        */


        // Kadane's Algorithm

        int ans = INT_MIN;
        int sum = 0;
        for(auto i : nums) {
            sum += i;

            ans = max(ans, sum);

            if(sum < 0) sum = 0;

            
        }
        return ans;
    }
};
