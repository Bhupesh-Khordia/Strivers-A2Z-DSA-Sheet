// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Use kadane's algorithm 2 times (1 from 0 to n - 1 and 1 from n - 1 to 0)

        /*
        int n = nums.size();
        int ans = INT_MIN;
        int product = 1;

        for(int i = 0; i < n - 1; i ++) {
            product = product * nums[i];
            ans = max(ans, product);
            if(product == 0) product = 1;
        }

        product = 1;
        for(int i = n - 1; i >= 0; i --) {
            product = product * nums[i];
            ans = max(ans, product);
            if(product == 0) product = 1;
        }

        return ans;
        */


        // The same can be done in single loop also

        int n = nums.size();
        int ans = INT_MIN;
        int productFromStart = 1, productFromEnd = 1;

        for(int i = 0; i < n; i++) {
            productFromStart *= nums[i];
            productFromEnd *= nums[n - i - 1];

            ans = max({ans, productFromStart, productFromEnd});

            if(productFromStart == 0) productFromStart = 1;
            if(productFromEnd == 0) productFromEnd = 1;
        }

        return ans;
    }
};
