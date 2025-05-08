// https://leetcode.com/problems/jump-game/description/

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxIndex = 0;
    
            for(int i = 0; i < nums.size(); i++) {
                maxIndex = max(maxIndex, nums[i] + i);
                if(i == nums.size() - 1) return true;
                if(nums[i] == 0) {
                    if(maxIndex > i) continue;
                    else return false;
                }
            }
            return true;
        }
    };