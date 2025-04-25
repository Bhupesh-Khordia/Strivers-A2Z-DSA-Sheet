// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

class Solution {
    public:
      string postToInfix(string exp) {
          stack <string> st;
          int i = 0, n = exp.length();
          while (i < n) {
              if(
                  (exp[i] >= 'a' && exp[i] <= 'z') || 
                  (exp[i] >= 'A' && exp[i] <= 'Z') ||
                  (exp[i] >= '0' && exp[i] <= '9')
              ) {
                  st.push(string(1, exp[i]));
              } else {
                  string second = st.top(); st.pop();
                  string first = st.top(); st.pop();
                  st.push("(" + first + exp[i] + second + ")");
              }
              i++;
          }
          return st.top();
      }
  };