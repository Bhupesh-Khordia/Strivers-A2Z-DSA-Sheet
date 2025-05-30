// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Another way is to sort and use two pointer like binary search
        
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(target - nums[i]) == map.end()) {
                map[nums[i]] = i;
            } else {
                return {i, map[target - nums[i]]};
            }
        }
        return {};
    }
};
