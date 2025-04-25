// https://www.interviewbit.com/problems/nearest-smaller-element/

// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1

// Solution to GFG Question

class Solution {
    public:
      vector<int> leftSmaller(vector<int> arr) {
          stack<int> st;
          int n = arr.size();
          vector<int> ans(n, -1);
          
          
          for(int i = 0; i < n; i++) {
              while(!st.empty() && st.top() >= arr[i]) {
                  st.pop();
              }
              if(!st.empty()) ans[i] = st.top();
              st.push(arr[i]);
          }
          return ans;
      }
  };