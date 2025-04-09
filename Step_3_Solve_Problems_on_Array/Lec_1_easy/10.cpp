class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Solution 1
        /*
        vector<bool> check(nums.size() + 1, false);

        for(auto i : nums) {
            check[i] = true;
        }
        for(int i = 1; i < check.size(); i++) {
            if(!check[i]) return i;
        }

        return 0;
        */

        // Solution 2
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }

        int n = nums.size();
        return (n * (n + 1) / 2) - sum;
    }
};
