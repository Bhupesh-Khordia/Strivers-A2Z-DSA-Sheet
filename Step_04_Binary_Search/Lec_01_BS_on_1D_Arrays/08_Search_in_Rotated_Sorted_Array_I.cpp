// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
    private:
        int pivot(vector<int> &arr) {
            int start = 0;
            int end = arr.size() - 1;
    
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (arr[mid] > arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
            return start;
        }
    
    public:
        int search(vector<int>& nums, int target) {
            // Find Pivot index
            int pivotIndex = pivot(nums);
            int s, e;
    
            // Find where does target lies
            if (target >= nums[pivotIndex] && target <= nums[nums.size() - 1]) {
                s = pivotIndex;
                e = nums.size() - 1;
            } else {
                s = 0;
                e = pivotIndex - 1;
            }
    
            while (s <= e) {
                int mid = s + (e - s) / 2;
    
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) s = mid + 1;
                else e = mid - 1;
            }
    
            return -1;
        }
    };
    