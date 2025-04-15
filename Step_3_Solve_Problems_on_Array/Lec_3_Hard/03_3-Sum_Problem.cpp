// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Use two sum in a loop

        int n = nums.size();
        vector<vector<int>> ans;
        int target = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            // Fix i and use two pointer (Two sum)

            if(i > 0 && nums[i] == nums[i - 1]) continue;  // To avoid double counting

            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];

                if(sum == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;

                    // To avoid double counting
                    while(nums[left] == nums[left - 1] && left < right) left++;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};
