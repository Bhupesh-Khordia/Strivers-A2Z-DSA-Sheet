// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

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
        int findMin(vector<int>& nums) {
            return nums[pivot(nums)];
        }
    };