using namespace std;
#include <bits/stdc++.h>

// https://leetcode.com/problems/top-k-frequent-elements/description/

// O(nlogk)

/*
class Solution {
private:
    static bool cmp (pair<int, int>& a, pair<int, int> &b) {
        return a.second < b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(auto num : nums) {
            cnt[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> heap(&cmp);

        for (auto& entry : cnt) {
            heap.push({entry.first, entry.second});
        }

        vector<int> res;
        while (k-- > 0) {
            res.push_back(heap.top().first);
            heap.pop();
        }
        
        return res;  
    }
};
*/


// O(n)
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> counter;
            for (int n : nums) {
                counter[n]++;
            }
            
            vector<vector<int>> freq(nums.size() + 1);
            for (auto& entry : counter) {
                freq[entry.second].push_back(entry.first);
            }
            
            vector<int> res;
            for (int i = freq.size() - 1; i >= 0; i--) {
                for (int num : freq[i]) {
                    res.push_back(num);
                    if (res.size() == k) {
                        return res;
                    }
                }
            }
            
            return {};        
        }
    };