// https://leetcode.com/problems/kth-missing-positive-number/description/

class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int n = arr.size();
            
            int s = 0, e = n - 1;
            while(s <= e) {
                int mid = s + (e - s) / 2;
                int missingNo = arr[mid] - mid - 1;
    
                if(missingNo < k) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            // preceding neighbor of the kth missing number is vec[high]
            // the number of missing numbers = vec[high] - (high+1).
            // more_missing_numbers = k - (vec[high] - (high+1)).
            // kth missing number = vec[high] + k - (vec[high] - (high+1))
            return k + e + 1;
        }
    };