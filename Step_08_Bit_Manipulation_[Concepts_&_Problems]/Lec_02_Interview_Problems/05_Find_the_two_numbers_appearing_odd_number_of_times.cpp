#include <bits/stdc++.h>
using namespace std;

// 136. Single Number - https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR of 2 same numbers is 0
        int x = 0;
        for(auto i : nums) {
            x = x ^ i;
        }
        return x;
    }
};


// 137. Single Number II - https://leetcode.com/problems/single-number-ii/description/
// https://www.youtube.com/watch?v=5Bb2nqA40JY

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Solution 1 : count first bit of every number and then check if it is multiple of 3
        // T.C. = O(N * 32)

        /*
        int ans = 0;
        for(int bitIndex = 0; bitIndex <= 31; bitIndex++) {
            int cnt = 0;
            for(int i = 0;  i < nums.size(); i++) {
                cnt += (nums[i] >> bitIndex) & 1;
            }
            if(cnt % 3 == 1)  {
                ans = ans | (1 << bitIndex);
            }
        }
        return ans;
        */


        // Solution 2 : sort array and iterate from 1 index and increment with 3
        // T.C. = O(N * log N) 

        /*
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i+=3) {
            if(nums[i] != nums[i - 1]) return nums[i - 1];
        }
        return nums[nums.size() - 1];
        */

        // Solution 3 : Magical
        // T.C = O(N)

        int ones = 0;
        int twos = 0;

        for (const int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};


// 260. Single Number III - https://leetcode.com/problems/single-number-iii/description/
// https://www.youtube.com/watch?v=UA5JnV1J2sI

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xori = 0;
        for(int num : nums) xori ^= num;

        /*
        let xori = 110100
        then rightmost = 000100
        */

        int rightmost = (xori & (xori - 1)) ^ xori;

        int bucket1 = 0, bucket2 = 0;
        // Classify based on rightmost bit set or unset

        for(int num : nums) {
            if((num & rightmost) != 0) bucket1 = bucket1 ^ num;
            else bucket2 = bucket2 ^ num;
        }

        return {bucket1, bucket2};
    }
};

// https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

class Solution {
  public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long int xori = 0;
        for(long long int i = 0; i < N; i++) {
            xori = xori ^ Arr[i];
        }

        /*
        let xori = 110100
        then rightmost = 000100
        */

        long long int rightmost = xori & -xori;

        long long int bucket1 = 0, bucket2 = 0;
        // Classify based on rightmost bit set or unset

        for(long long int i = 0; i < N; i++) {
            if((Arr[i] & rightmost) != 0) bucket1 = bucket1 ^ Arr[i];
            else bucket2 = bucket2 ^ Arr[i];
        }
        
        vector<long long int> ans = {bucket1, bucket2};
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};