// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            /*
            vector<int> numsDouble;
            for(int i = 1; i <= 2; i++) {
                for(int num : nums) {
                    numsDouble.push_back(num);
                }
            }
            int n = numsDouble.size();
            vector<int> ans(n, -1);
            stack<int> st;
            for(int i = n - 1; i >= 0; i--) {
                while(!st.empty() && numsDouble[i] >= st.top()) {
                    st.pop();
                }
                if(!st.empty()) ans[i] = st.top();
                st.push(numsDouble[i]);
            }
            ans.erase(ans.begin() + n/2, ans.end());
            return ans;
            */
            // Optimization
            int n = nums.size();
            vector<int> ans(n, -1);
            stack<int> st;
            for(int i = 2*n - 1; i >= 0; i--) {
                while(!st.empty() && nums[i % n] >= st.top()) {
                    st.pop();
                }
                if(!st.empty()) ans[i % n] = st.top();
                st.push(nums[i % n]);
            }
            return ans;
        }
    };