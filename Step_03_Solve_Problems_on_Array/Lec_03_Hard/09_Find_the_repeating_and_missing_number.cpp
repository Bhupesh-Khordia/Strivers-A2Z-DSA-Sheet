// https://leetcode.com/problems/find-missing-and-repeated-values/

// /*
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // Another method is to use Bit Manipulation(XOR)
        int n = grid.size() * grid.size();
        long long sum = (long long)n * (n + 1) / 2;
        long long sumOfSq = (long long)n * (n + 1) * ((2 * n) + 1) / 6;
        
        long long sumOfArr = 0;
        long long sumSqArr = 0;
        for(auto i : grid) {
            for(auto j : i){
                sumOfArr += (long long)j;
                sumSqArr += (long long)j * (long long)j;
            }
        }
        
        long long temp1 = sumOfArr - sum;
        long long temp2 = sumSqArr - sumOfSq;
        temp2 = temp2 / temp1;
        
        // X - Y = temp1;
        // X + Y = temp2;
        
        // X = (temp1 + temp2) / 2;
        // Y = (temp2 - temp1) / 2;
        
        return {(int)(temp1 + temp2) / 2, (int)(temp2 - temp1) / 2};
    }
};
// */



// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

/*
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long sum = n * (n + 1) / 2;
        long long sumOfSq = n * (n + 1) * ((2 * n) + 1) / 6;
        
        long long sumOfArr = 0;
        long long sumSqArr = 0;
        for(auto i : arr) {
            sumOfArr += (long long)i;
            sumSqArr += (long long)i * i;
        }
        
        long long temp1 = sumOfArr - sum;
        long long temp2 = sumSqArr - sumOfSq;
        temp2 = temp2 / temp1;
        
        // X - Y = temp1;
        // X + Y = temp2;
        
        // X = (temp1 + temp2) / 2;
        // Y = (temp2 - temp1) / 2;
        
        return {(temp1 + temp2) / 2, (temp2 - temp1) / 2};
        
    }
};
*/



// https://www.naukri.com/code360/problems/missing-and-repeating-numbers_873366?leftPanelTabValue=PROBLEM


/*
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long sum = n * (n + 1) / 2;
	long long sumOfSq = n * (n + 1) * ((2 * n) + 1) / 6;
	
	long long sumOfArr = 0;
	long long sumSqArr = 0;
	for(auto i : arr) {
		sumOfArr += (long long)i;
		sumSqArr += (long long)i * (long long)i;
	}
	
	long long temp1 = sumOfArr - sum;
	long long temp2 = sumSqArr - sumOfSq;
	temp2 = temp2 / temp1;
	
	// X - Y = temp1;
	// X + Y = temp2;
	
	// X = (temp1 + temp2) / 2;
	// Y = (temp2 - temp1) / 2;
	
	return {(temp2 - temp1) / 2, (temp1 + temp2) / 2};
}
*/
