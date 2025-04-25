// https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution {
    private:
        vector<int> nextSm(vector<int> &nums) {
            int n = nums.size();
            vector<int> ans(n, -1);
            stack<int> st;
            for(int i = n - 1; i >= 0; i--) {
                while(!st.empty() && nums[i] <= nums[st.top()]) {
                    st.pop();
                }
                if(!st.empty()) ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int> prevSm(vector<int> &nums) {
            int n = nums.size();
            vector<int> ans(n, -1);
            stack<int> st;
            for(int i = 0; i< n; i++) {
                while(!st.empty() && nums[i] < nums[st.top()]) {
                    st.pop();
                }
                if(!st.empty()) ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }
    public:
        int sumSubarrayMins(vector<int>& arr) {
            const int mod = 1e9 + 7;
            vector<int> nextSmaller = nextSm(arr);  // Next Smaller than or equal to
            vector<int> prevSmaller = prevSm(arr);  // Prev Smaller than (not equal to, to avoid double counting)
            int n = arr.size();
            long long ans = 0;
    
    
            for(int i = 0; i < n; i++) {
                int prev = prevSmaller[i];
                int next = nextSmaller[i];
                
                int left; // No Of elements possible to choose from left s.t. arr[i] is minimum
                if(prev == -1) {
                    left = i - 0;
                } else {
                    left = i - prev - 1;
                }
                int right;  // No Of elements possible to choose from right s.t. arr[i] is minimum
                if(next == -1) {
                    right = n - i - 1;
                } else {
                    right = next - i - 1;
                }
    
                // Left to right window will have min = arr[i]
    
                long long count = 1LL * (left + 1) * (right + 1) % mod;
                long long total = 1LL * arr[i] * count % mod;
                ans = (ans + total) % mod;
    
                // Choices of starting index of subarray = left + 1(i itself), ending index = right + 1
                // Total choices = (left + 1) * (right + 1) with minimum as arr[i];
            }
            return ans;
        }
    };