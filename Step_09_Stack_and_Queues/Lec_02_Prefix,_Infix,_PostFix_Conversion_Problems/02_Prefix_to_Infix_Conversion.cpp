// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

class Solution {
    public:
      string preToInfix(string pre_exp) {
          stack <string> st;
          int n = pre_exp.length();
          int i = n - 1; 
          while (i >= 0) {
              if(
                  (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || 
                  (pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') ||
                  (pre_exp[i] >= '0' && pre_exp[i] <= '9')
              ) {
                  st.push(string(1, pre_exp[i]));
              } else {
                  string first = st.top(); st.pop();
                  string second = st.top(); st.pop();
                  st.push("(" + first + pre_exp[i] + second + ")");
              }
              i--;
          }
          return st.top();
      }
  };