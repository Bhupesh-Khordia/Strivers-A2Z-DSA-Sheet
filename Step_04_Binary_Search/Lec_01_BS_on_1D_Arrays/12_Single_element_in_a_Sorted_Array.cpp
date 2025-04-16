// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            // [1,1,2,2,3,3,4,5,5,8,8]
            //(even,odd) till single then (odd,even)  
    
    
            int n = nums.size();
            int s = 0, e = n - 1;
            while(s <= e) {
                int mid = s + (e - s) / 2;
                // Base case
                if ((mid == 0 || nums[mid] != nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] != nums[mid + 1]))
                    return nums[mid];
    
                if(mid & 1) {
                    if(mid > 0 && nums[mid] == nums[mid - 1]) {
                        s = mid + 1;
                    } else {
                        e = mid - 1;
                    }
                } else {
                    if(mid < n && nums[mid] == nums[mid + 1]) {
                        s = mid + 1;
                    } else {
                        e = mid - 1;
                    }
                }
            }
            return -1;
        }
    };