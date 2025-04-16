// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int startIndex = -1, endIndex = -1;
            int s = 0, e = nums.size() - 1;
    
            while(s <= e) {
                int mid = s + ((e - s) / 2);
    
                if(nums[mid] == target ) {
                    startIndex = mid;
                    e = mid - 1;
                } else if(nums[mid] < target ) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            s = 0, e = nums.size() - 1;
            while(s <= e) {
                int mid = s + (e - s) / 2;
    
                if(nums[mid] == target ) {
                    endIndex = mid;
                    s = mid + 1;
                } else if(nums[mid] < target ) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
    
            return {startIndex, endIndex};
        }
    };