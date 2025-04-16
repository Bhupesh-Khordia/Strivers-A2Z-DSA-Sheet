// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int s = 0, e = nums.size() - 1;
    
            while(s <= e) {
                int mid = s + (e - s) / 2;
    
                if(nums[mid] == target) return true;
    
                if(nums[mid] == nums[s] && nums[mid] == nums[e]) {
                    s++;
                    e--;
                }
    
                else if(nums[mid] >= nums[s]) {  // Left Half Sorted
                    if(target >= nums[s] && target < nums[mid]) {
                        e = mid - 1;
                    } else {
                        s = mid + 1;
                    }
                }
    
                // Right Half Sorted
                else { // numd[mid] <= nums[right]
                    if(target <= nums[e] && target > nums[mid]) {
                        s = mid + 1;
                    } else {
                        e = mid - 1;
                    }
                }
            }
            return false;
        }
    };