// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

class Solution {
    public:
      string postToPre(string post_exp) {
          stack <string> st;
          int i = 0, n = post_exp.length();
          while (i < n) {
              if(
                  (post_exp[i] >= 'a' && post_exp[i] <= 'z') || 
                  (post_exp[i] >= 'A' && post_exp[i] <= 'Z') ||
                  (post_exp[i] >= '0' && post_exp[i] <= '9')
              ) {
                  st.push(string(1, post_exp[i]));
              } else {
                  string second = st.top(); st.pop();
                  string first = st.top(); st.pop();
                  st.push(post_exp[i] + first + second);
              }
              i++;
          }
          return st.top();
      }
  };