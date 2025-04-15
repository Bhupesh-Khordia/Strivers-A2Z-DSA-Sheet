// GFG - https://www.geeksforgeeks.org/problems/maximum-sub-array5443/1

/*
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // Kadane's extended Version
        int n = arr.size();

        long long maxSum = -1;
        long long currSum = 0;
        int start = 0;
        int ansStart = -1, ansEnd = -1;

        for(int i = 0; i < n; i++) {
            if(arr[i] >= 0) {
                currSum += arr[i];

                if(currSum > maxSum) {
                    maxSum = currSum;
                    ansStart = start;
                    ansEnd = i;
                } else if(currSum == maxSum) {
                    int currLen = i - start + 1;
                    int bestLen = ansEnd - ansStart + 1;
                    if(currLen > bestLen) {
                        // Prefer longer subarray if sums are equal
                        ansStart = start;
                        ansEnd = i;
                    }
                }
            } else {
                // Reset on negative number
                currSum = 0;
                start = i + 1;
            }
        }

        vector<int> ans;
        if(ansStart != -1) {
            for(int i = ansStart; i <= ansEnd; i++) {
                ans.push_back(arr[i]);
            }
        } else {
            return {-1};
        }

        return ans;
    }
};
*/




// Naukri (Coding Ninjas) -  https://www.naukri.com/code360/problems/maximum-subarray_893296?leftPanelTabValue=SUBMISSION


// /*
#include <bits/stdc++.h> 
vector<int> maximumsumSubarray(vector<int> &arr , int n)
{
    // Kadane's Algorithm

    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    
    for(int i = 0; i < arr.size(); i++) {
        
        sum += arr[i];

        if(sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        } else if (sum == maxi) {
            int currLen = i - start + 1;
            int bestLen = ansEnd - ansStart + 1;
            if(currLen > bestLen) {
                ansStart = start;
                ansEnd = i;
            }
        }

        if(sum < 0){
            sum = 0;
            start = i + 1;
        } 
    }
    vector<int> ans;
    for(int i = ansStart; i <= ansEnd; i++) {
        ans.push_back(arr[i]);
    }
    return ans;
}
// */
