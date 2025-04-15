// https://leetcode.com/problems/4sum/
// TC - O(N ^ 3), SC - O (1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Use 3 sum in a loop 

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());


        for(int j = 0; j < n; j++) {
            // Fix j and use 3 sum

            // Use code of 3 sum
            for(int i = j + 1; i < n; i++) {
                // Fix i and use two pointer (Two sum)

                int left = i + 1, right = n - 1;
                while(left < right) {
                    long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j]; // To avoid integer overflow when adding to get sum
                    long long sum = (long long)nums[left] + (long long)nums[right];

                    if(sum == newTarget) {
                        ans.push_back({nums[j], nums[i], nums[left], nums[right]});

                        // To avoid double counting
                        int tempIndex1 = left, tempIndex2 = right;
                        while(left < right && nums[left] == nums[tempIndex1]) left++;
                        while(left < right && nums[right] == nums[tempIndex2]) right--;
                    } else if (sum < newTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }

                // To avoid double counting
                while( i + 1 < n && nums[i] == nums[i + 1]) i++;

            }
            // To avoid double counting
            while( j + 1 < n && nums[j] == nums[j + 1]) j++;
        }
        return ans;
    }
};
