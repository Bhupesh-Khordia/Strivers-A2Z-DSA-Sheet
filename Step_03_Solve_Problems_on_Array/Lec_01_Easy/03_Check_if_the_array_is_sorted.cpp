// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution {
public:
    bool sorted(vector<int>& arr){
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i+1] < arr[i]) {
                return false;
            }
        }
        return true;
    }
    bool check(vector<int>& nums) {
        vector<int> temp(nums);
        for(int x = 0; x < nums.size(); x++) {
            for(int i = 0; i < nums.size(); i++){
                temp[(i + x) % (nums.size())] = nums[i];
            }
            if(sorted(temp)){
                return true;
            }
        }
        return false;
    }
};
