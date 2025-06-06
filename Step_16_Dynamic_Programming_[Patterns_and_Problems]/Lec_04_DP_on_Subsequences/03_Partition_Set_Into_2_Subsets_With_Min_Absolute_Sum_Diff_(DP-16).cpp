# include <bits/stdc++.h>
using namespace std;

// Leetcode question uses different approach which is hard (Meet in middle) . What striver wanted to teach can be applied in GFG/Coding Ninjas Question below -

// --------------------------------------------------------------------------------------------------------------------------------
// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
// --------------------------------------------------------------------------------------------------------------------------------

// Bad and wrong approach (negative indices are possible)
/*
class Solution {
private:
    // DP not possible in this method.
    int solve(vector<int> &nums, int index, long long sum1, int cnt1, long long totalSum) {
        if(index >= nums.size()) return cnt1 == nums.size() >> 1 ? abs(totalSum - sum1 - sum1) : INT_MAX;
        if(cnt1 > nums.size() >> 1) return INT_MAX;
        if(cnt1 == nums.size() >> 1) return abs(totalSum - sum1 - sum1);

        // Include in arr1
        int option1 = solve(nums, index + 1, sum1 + nums[index], cnt1 + 1, totalSum);
        
        // Include in arr2
        int option2 = solve(nums, index + 1, sum1, cnt1, totalSum);

        return min(option1, option2);
    }

    
public:
    int minimumDifference(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<vector<int>>> dp (nums.size() + 1, )
        return solve(nums, 0, 0, 0, sum);
    }
};
*/




// Meet in the middle solution
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(),0);
        
        int N = n/2;
        // Divide array into two subparts of equal size - left and right
        vector<vector<int>> left(N+1), right(N+1); // Value on Index 0 in left means possible sums of size 0 from left subpart of array
        
		//storing all possible sum in left and right part
        for(int mask = 0; mask<(1<<N); ++mask){
            int sz = 0, l = 0, r = 0;
            for(int i=0; i<N; ++i){
                if(mask&(1<<i)){
                    sz++;
                    l += nums[i];
                    r += nums[i+N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for(int sz=0; sz<=N; ++sz){
            sort(right[sz].begin(), right[sz].end());
        }

        // All n elements in first subset from left part or right part
        res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));

		//iterating over left part
        for(int sz=1; sz<N; ++sz){  // sz is number of elements in first subset from left array
            for(auto &a : left[sz]){
                int b = (sum - 2*a)/2; // ideal value of b (ideally a + b = (sum / 2))
                int rsz = N-sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part
                // in array of 4,5,9,10  lower bound of 6 will return 9, but actually 5 is closer, so also check for previous element to itr
                
                if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr))));
                if(itr!= v.begin()){
                    auto it = itr; --it;
                    res = min(res, abs(sum-2*(a+(*it))));
                }                
            }
        }
        return res;
        
    }
};





// --------------------------------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// --------------------------------------------------------------------------------------------------------------------------------

class Solution {
  private:
    // This function is copied and modified from 416. Partition Equal Subset Sum (DP-15 in striver's sheet)
    vector<bool> solveSO(vector<int> &nums, int n, int totalSum) {
        // vector<vector<int>> dp (n + 1, vector<int> ((totalSum / 2) + 1, 0));
        vector<bool> curr (totalSum/2 + 1, 0);
        vector<bool> next (totalSum/2 + 1, 0);

        // Base Case
        curr[0] = 1;
        next[0] = 1;

        for(int index = n - 1; index >= 0; index--) {
            for(int target = 0; target <= totalSum / 2; target++) {
                // Include 
                bool include = 0;
                if(target - nums[index] >= 0)
                    include = next[target - nums[index]];

                // Exclude
                bool exclude = next[target - 0];

                curr[target] = include || exclude ; // Logical OR
            }
            next = curr;
        }

        return curr;
    }
  public:
    int minDifference(vector<int>& arr) {
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        vector<bool> check = solveSO(arr, arr.size(), sum);
        // check[x] = if it is possible to split array into subset of sum x

        int ans = INT_MAX;
        for(int i = 0; i <= sum/2; i++) {
            // After sum/2 partitions start to repeat
            if(check[i]) {
                // Possible to get sum1 = i;
                long long sum1 = i;
                long long sum2 = sum - i;
                
                ans = min(ans, (int)abs(sum1 - sum2));
            }
        }
        
        return ans;
    }
};




// --------------------------------------------------------------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTabValue=PROBLEM
// --------------------------------------------------------------------------------------------------------------------------------


// This function is copied and modified from 416. Partition Equal Subset Sum (DP-15 in striver's sheet)
vector<bool> solveSO(vector<int> &nums, int n, int totalSum) {
	// vector<vector<int>> dp (n + 1, vector<int> ((totalSum / 2) + 1, 0));
	vector<bool> curr (totalSum/2 + 1, 0);
	vector<bool> next (totalSum/2 + 1, 0);

	// Base Case
	curr[0] = 1;
	next[0] = 1;

	for(int index = n - 1; index >= 0; index--) {
		for(int target = 0; target <= totalSum / 2; target++) {
			// Include 
			bool include = 0;
			if(target - nums[index] >= 0)
				include = next[target - nums[index]];

			// Exclude
			bool exclude = next[target - 0];

			curr[target] = include || exclude ; // Logical OR
		}
		next = curr;
	}

	return curr;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	long long sum = accumulate(arr.begin(), arr.end(), 0);
	vector<bool> check = solveSO(arr, n, sum);
	// check[x] = if it is possible to split array into subset of sum x

	int ans = INT_MAX;
	for(int i = 0; i <= sum/2; i++) {
		// After sum/2 partitions start to repeat
		if(check[i]) {
			// Possible to get sum1 = i;
			long long sum1 = i;
			long long sum2 = sum - i;
			
			ans = min(ans, (int)abs(sum1 - sum2));
		}
	}
	
	return ans;
}
