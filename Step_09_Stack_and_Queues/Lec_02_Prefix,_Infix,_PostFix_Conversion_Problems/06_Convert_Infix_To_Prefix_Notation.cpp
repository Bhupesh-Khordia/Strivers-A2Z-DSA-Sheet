/*

https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1  (No Spearate question found)
https://www.geeksforgeeks.org/convert-infix-prefix-notation/ (GFG Article)

Steps - 
1. Reverse the infix (handle brackets)
2. Convert to Postfix (in a controlled manner (refer video))   (https://www.youtube.com/watch?v=4pIc9UBHJtk)
3. Reverse the generated postfix.

*/


// Code for  (https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1)

class Solution {
    private:
      int priority(char c) {
          if(c == '^') return 3;
          else if(c == '*' || c == '/') return 2;
          else if(c == '+' || c == '-') return 1;
          return 0;
      }
    public:
      string infixToPostfix(string& s) {
          string ans = "";
          stack <char> st;
          
          for(int i = 0; i < s.length(); i++) {
              if((s[i] >= 'a' && s[i] <= 'z')
                  || (s[i] >= 'A' && s[i] <= 'Z')
                  || (s[i] >= '0' && s[i] <= '9')) {
                  ans += s[i];
              } else if (s[i] == '(') {
                  st.push(s[i]);
              } else if (s[i] == ')') {
                  while(!st.empty() && st.top() != '(') {
                      ans += st.top();
                      st.pop();
                  }
                  if (!st.empty()) st.pop();
              } else {
                  // Operator
                  while (!st.empty() && priority(st.top()) >= priority(s[i])) {
                      ans += st.top();
                      st.pop();
                  }
                  st.push(s[i]);
              }
          }
          
          while(!st.empty()) {
              ans += st.top();
              st.pop();
          }
          
          return ans;
      }
  };