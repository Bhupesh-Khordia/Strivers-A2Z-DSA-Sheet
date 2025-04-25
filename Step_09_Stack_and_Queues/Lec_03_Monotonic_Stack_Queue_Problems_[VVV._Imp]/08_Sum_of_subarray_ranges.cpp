// https://leetcode.com/problems/sum-of-subarray-ranges/description/

// Refer 907. Sum of Subarray Minimums for detail explanation (Striver Sheet Q6 Lec 3 Step 9 Stacks)

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
        vector<int> nextGreater(vector<int> &nums) {
            int n = nums.size();
            vector<int> ans(n, -1);
            stack<int> st;
            for(int i = n - 1; i >= 0; i--) {
                while(!st.empty() && nums[i] >= nums[st.top()]) {
                    st.pop();
                }
                if(!st.empty()) ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }
        
        vector<int> prevGreater(vector<int> &nums) {
            int n = nums.size();
            vector<int> ans(n, -1);
            stack<int> st;
            for(int i = 0; i < n; i++) {
                while(!st.empty() && nums[i] > nums[st.top()]) {
                    st.pop();
                }
                if(!st.empty()) ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }
        long long sumOfMins(vector<int>& arr) {
            vector<int> nextSmaller = nextSm(arr);
            vector<int> prevSmaller = prevSm(arr);
            int n = arr.size();
            long long ans = 0;
    
            for(int i = 0; i < n; i++) {
                int prev = prevSmaller[i];
                int next = nextSmaller[i];
                int left = (prev == -1) ? i : i - prev - 1;
                int right = (next == -1) ? n - i - 1 : next - i - 1;
                long long count = 1LL * (left + 1) * (right + 1);
                long long total = 1LL * arr[i] * count;
                ans = (ans + total);
            }
            return ans;
        }
    
        long long sumOfMaxs(vector<int>& arr) {
            vector<int> nextGreater_ = nextGreater(arr);
            vector<int> prevGreater_ = prevGreater(arr);
            int n = arr.size();
            long long ans = 0;
    
            for(int i = 0; i < n; i++) {
                int prev = prevGreater_[i];
                int next = nextGreater_[i];
                int left = (prev == -1) ? i : i - prev - 1;
                int right = (next == -1) ? n - i - 1 : next - i - 1;
                long long count = 1LL * (left + 1) * (right + 1);
                long long total = 1LL * arr[i] * count;
                ans = (ans + total);
            }
            return ans;
        }
    public:
        long long subArrayRanges(vector<int>& nums) {
            // subArraySum Max - subArraySum Min = subArraySum Range
            // Refer 907. Sum of Subarray Minimums for detail explanation (Striver Sheet Q6 Lec 3 Step 9 Stacks)
    
            long long maxSum = sumOfMaxs(nums);
            long long minSum = sumOfMins(nums);
            return (maxSum - minSum);
        }
    };