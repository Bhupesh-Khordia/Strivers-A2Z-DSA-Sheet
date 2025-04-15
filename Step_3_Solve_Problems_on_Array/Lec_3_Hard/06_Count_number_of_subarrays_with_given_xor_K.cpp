// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


/*
// Same pattern as Leetcode 560
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        map<long, long> map;
        long xori = 0;
        long ans = 0;
        
        for(long i = 0; i < arr.size(); i++) {
            xori = xori ^ arr[i];
            
            if(xori == k) ans++;
            
            long remaining = xori ^ k; // For longest subarray sum we used minus. But inverse of XOR is XOR itself.
            
            if(map.find(remaining) != map.end()) {
                ans += map[remaining];
            }
            map[xori]++;
        }
        return ans;
    }
};
*/



// https://www.naukri.com/code360/problems/count-subarrays-with-given-xor_1115652?leftPanelTabValue=SUBMISSION


// /*
// Same pattern as Leetcode 560

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    map<long, long> map;
    long xori = 0;
    long ans = 0;
    
    for(long i = 0; i < arr.size(); i++) {
        xori = xori ^ arr[i];
        
        if(xori == x) ans++;
        
        long remaining = xori ^ x; // For longest subarray sum we used minus. But inverse of XOR is XOR itself.
        
        if(map.find(remaining) != map.end()) {
            ans += map[remaining];
        }
        map[xori]++;
    }
    return ans;
}
// */
