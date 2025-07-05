# include <bits/stdc++.h>
using namespace std;

// Leetcode problem is different (uses Stack based approach) from what striver wanted to teach. That can be found here: 
// (Leetcode's solution is below it -)



// --------------------------------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
// --------------------------------------------------------------------------------------------------------------------------------


class Solution {
  private:
    int solve(int i, int j, bool isTrue, string &s, vector<vector<vector<int>>> &dp) {
        if(i > j) return 0;

        if(i == j) {
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ways = 0;

        for(int ind = i + 1; ind < j; ind += 2) {
            char op = s[ind];

            // Evaluate all 4 possibilities
            int lt = solve(i, ind - 1, true, s, dp);
            int lf = solve(i, ind - 1, false, s, dp);
            int rt = solve(ind + 1, j, true, s, dp);
            int rf = solve(ind + 1, j, false, s, dp);

            if(op == '&') {
                if(isTrue) ways = (ways + lt * rt);
                else ways = (ways + lt * rf + lf * rt + lf * rf);
            }
            else if(op == '|') {
                if(isTrue) ways = (ways + lt * rt + lt * rf + lf * rt);
                else ways = (ways + lf * rf);
            }
            else if(op == '^') {
                if(isTrue) ways = (ways + lt * rf + lf * rt);
                else ways = (ways + lt * rt + lf * rf);
            }
        }

        return dp[i][j][isTrue] = ways;
    }
  public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n - 1, true, s, dp);
    }
};


// --------------------------------------------------------------------------------------------------------------------------------
// https://leetcode.com/problems/parsing-a-boolean-expression/description/
// --------------------------------------------------------------------------------------------------------------------------------


// Question of stack (not DP)


// Using Single Stack Solution

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char currChar : expression) {
            if(currChar == ',' || currChar == '(')
                continue;  
            if(currChar == 't' || currChar == 'f' || currChar == '!' || currChar == '&' || currChar == '|') 
                st.push(currChar);         
            else if(currChar == ')') {
                bool hasTrue = false, hasFalse = false;
                while(st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topValue = st.top();
                    st.pop();
                    if(topValue == 't') 
                        hasTrue = true;
                    if(topValue == 'f') 
                        hasFalse = true;
                }
                char op = st.top();
                st.pop();
                if(op == '!') 
                    st.push(hasTrue ? 'f' : 't');
                else if(op == '&') 
                    st.push(hasFalse ? 'f' : 't');
                else 
                    st.push(hasTrue ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};


// Using 2 Stacks Solution

/*
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operators;
        stack<char> operands;

        int n = expression.size();
        for(int i = 0; i < n; i++) {
            if(expression[i] == '&' || expression[i] == '|' || expression[i] == '!') {
                operators.push(expression[i]);
            } else if (expression[i] == ',') {
                continue;
            } else if (expression[i] != ')') {
                operands.push(expression[i]);
            } else {
                char op = operators.top(); operators.pop();

                if(op == '!') {
                    char top = operands.top(); operands.pop();
                    operands.pop(); // '('

                    if(top == 't')
                        operands.push('f');
                    else 
                        operands.push('t');
                }

                else if(op == '&') {
                    bool result = true;

                    while(true) {
                        char top = operands.top(); operands.pop();

                        if(top == '(') break;

                        result &= (top == 't');
                    }

                    if(result)
                        operands.push('t');
                    else 
                        operands.push('f');
                }

                else {
                    bool result = false;

                    while(true) {
                        char top = operands.top(); operands.pop();

                        if(top == '(') break;

                        result |= (top == 't');
                    }

                    if(result)
                        operands.push('t');
                    else 
                        operands.push('f');
                }
            }
        }

        return operands.top() == 't';
    }
};
*/