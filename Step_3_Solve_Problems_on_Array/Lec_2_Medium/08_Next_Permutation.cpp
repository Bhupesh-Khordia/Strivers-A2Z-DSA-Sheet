// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // STL
        /*
        next_permutation(nums.begin(), nums.end());
        return ;
        */


        // /*
        
        int n = nums.size();
        int i = n - 2;
        while( i >= 0 && nums[i] >= nums[i + 1]) i--;

        if(i >= 0) {
            // Find element just greater than nums[i]
            // nums[i : ...] is decreasing, so first element greater than nums[i] would be just greater.

            int j = n - 1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[j], nums[i]);
        }

        sort(nums.begin() + i + 1, nums.end());


        // */
    }
};
