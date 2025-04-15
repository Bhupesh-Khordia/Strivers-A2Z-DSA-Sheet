// https://leetcode.com/problems/merge-sorted-array/


// Extra Space Solution

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> ans;
//         int i = 0;
//         int j = 0;

//         while( i < nums1.size() && j < nums2.size()) {
//             if(nums1[i] < nums2[j]) {
//                 ans.push_back(nums1[i]);
//                 i++;
//             }
//             else {
//                 ans.push_back(nums2[j]);
//                 j++;
//             }
//         }

//         while(i < nums1.size()) {
//             ans.push_back(nums1[i]);
//             i++;
//         }

//         while (j < nums2.size()) {
//             ans.push_back(nums2[j]);
//             j++;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // No Extra space but O((m + n) log (m + n))
        /*
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
        */

        // No Extra Space and Linear Time

        // We start traversing from end so that no overriding problem

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1; // Final Index

        while(j >= 0) {
            if(i >= 0 && nums2[j] < nums1[i]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
