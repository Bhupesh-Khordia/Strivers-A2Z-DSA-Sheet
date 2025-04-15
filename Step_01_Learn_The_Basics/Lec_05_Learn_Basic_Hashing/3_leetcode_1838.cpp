class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0;
        long long ans = 0;
        long long right = 0;
        long long totalSumOfWindow = 0;
        // Sliding Window
        while(right < nums.size()) {
            totalSumOfWindow += nums[right];
            while((nums[right] * (right - left + 1)) > (totalSumOfWindow + k)) {   
                // Invalid Window (if all elements in window equal to last element, doing that would exceed available number of operations. So answer cannot be this window's length. Shorten the window.)
                totalSumOfWindow -= nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
            // This window can be an answer, try increasing size of window.
            right++;
        }
        return ans;
    }
};
