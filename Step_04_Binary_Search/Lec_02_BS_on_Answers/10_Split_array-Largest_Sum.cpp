// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
    private:
        bool isPossible(vector<int> &nums, int k, int mid) {
            int partition = 1;
            int tempSum = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(tempSum + nums[i] <= mid) {
                    tempSum += nums[i];
                } else {
                    partition++;
                    if(partition > k || nums[i] > mid) {
                        return false;
                    }
                    tempSum = nums[i];
                }
            }
            return true;
        }
    public:
        int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            if(k > n) return -1;
            int s = *max_element(nums.begin(), nums.end());
            int e = accumulate(nums.begin(), nums.end(), 0);
            int ans = -1;
            while(s <= e) {
                int mid = s + (e - s) / 2;
        
                if(isPossible(nums, k, mid)) {
                    ans = mid;
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            return ans;
        }
    };