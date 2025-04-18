// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // Watch video for better explanation
            int n1 = nums1.size();
            int n2 = nums2.size();
            int lenOfLeftPart = (n1 + n2 + 1) / 2;
    
            if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
            int s = 0, e = n1;
            // Searching for number of elements from nums1 in left partition
    
            while(s <= e) {
                int mid = s + (e - s) / 2;
    
                int index1 = mid;
                int index2 = lenOfLeftPart - mid;
    
                int l1 = INT_MIN;  // max element from nums1 in left part
                int l2 = INT_MIN;
                int r1 = INT_MAX; // Min element from nums1 in right part
                int r2 = INT_MAX;
    
                if (index1 < n1)
                    r1 = nums1[index1];
                if (index2 < n2)
                    r2 = nums2[index2];
                if (index1 - 1 >= 0)
                    l1 = nums1[index1 - 1];
                if (index2 - 1 >= 0)
                    l2 = nums2[index2 - 1];
                
                if(max(l1, l2) <= min(r1, r2)) {
                    // Valid Solution
                    if((n1 + n2) % 2 == 1) {
                        return max(l1, l2);
                    } else {
                        return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                    }
                } else if (l1 > r2) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            return 0;
        }
    };