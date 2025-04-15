// https://leetcode.com/problems/reverse-pairs/description/

class Solution {
private:
    long long merge(vector<int> &arr, long long l, long long mid, long long r) {
        long long reverse = 0;
        long long j = mid + 1;
        // Check for inversions first
        for(int i = l; i <= mid; i++) {
            while (j <= r && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            reverse += (j - (mid + 1));
        }
        vector<int> temp;
        long long left = l;
        long long right = mid + 1;
        
        while( left <= mid && right <= r ) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= r) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(long long i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
        
        return reverse;
    }
  
    long long mergeSort(vector<int> &arr, long long l, long long r) {
        if(l >= r) return 0;
        
        long long mid = l + ((r - l) / 2);
        long long left = mergeSort(arr, l, mid);
        long long right = mergeSort(arr, mid + 1, r);
        long long final = merge(arr, l, mid, r);
        
        return left + right + final;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
