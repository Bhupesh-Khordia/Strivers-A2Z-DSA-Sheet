// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
    private:
        int isPossible(vector<int> &weights, int days, int mid) {
            int totalDays = 1;
            int capRemaining = mid;
            for(int i = 0; i < weights.size(); i++) {
                if(weights[i] <= capRemaining) {
                    capRemaining -= weights[i];
                } else {
                    totalDays++;
                    capRemaining = mid - weights[i];
                }
            }
            return totalDays <= days;
        }
    
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int s = *max_element(weights.begin(), weights.end());
            int e = accumulate(weights.begin(), weights.end(), 0); // Sum of array
            int ans = -1;
            while(s <= e) {
                int mid = s + (e - s) / 2;
                if(isPossible(weights, days, mid)) {
                    ans = mid;
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            return ans;
        }
    };