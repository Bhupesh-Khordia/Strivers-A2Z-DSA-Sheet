// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
    private:
        bool isPossible(vector<int>&piles, int h, int k) {
            long long hrs = 0;
            for(int i = 0; i < piles.size(); i++) {
                if(piles[i] <= k) {
                    hrs++;
                } else {
                    hrs += ceil((double)piles[i] / k);
                }
            }
            return hrs <= h;
        }
    public: 
        int minEatingSpeed(vector<int>& piles, int h) {
            int s = 1, e = *max_element(piles.begin(), piles.end());
            int ans = -1;
    
            while(s <= e) {
                int mid = s + (e - s)/2;
    
                if(isPossible(piles, h, mid)) {
                    ans = mid;
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
    
            return ans;
        }
    };