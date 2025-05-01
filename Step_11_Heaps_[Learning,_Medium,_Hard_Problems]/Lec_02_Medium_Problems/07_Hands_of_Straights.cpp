
// https://leetcode.com/problems/hand-of-straights/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
    public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
            priority_queue<int> pq (hand.begin(), hand.end());
            int cnt = 0;
            int prev = -1;
            vector<int> temp;
            
            while(!pq.empty()) {
                int top = pq.top(); pq.pop();
                if(cnt != 0 && top == prev) { // if cnt = 0 then starting of new group
                    temp.push_back(top);
                } else if(prev == -1 || top == prev - 1 || cnt == 0) {
                    cnt++;
                    if(cnt == groupSize) {
                        cnt = 0;
                        for(auto i : temp) {
                            pq.push(i);
                        }
                        temp.clear();
                    }
                    prev = top;
                } else {
                    return false;
                }
                
            }
    
            if(cnt == 0)
            return true;
            return false;
        }
    };


// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/


/*
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k) return false;

        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] == 0) continue;
            mp[nums[i]]--;
            
            for (int j = 1; j < k; j++) {
                if (mp[nums[i] + j] == 0) return false;
                else mp[nums[i] + j]--;
            }
        }
        return true;
    }
};
*/