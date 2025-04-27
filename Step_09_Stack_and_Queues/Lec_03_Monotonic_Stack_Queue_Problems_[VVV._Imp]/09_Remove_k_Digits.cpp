// https://leetcode.com/problems/remove-k-digits/description/

class Solution {
    public:
        string removeKdigits(string num, int k) {
            if(k == num.length()) return "0";
    
            string ans = "";
    
            stack <char> st;
    
            for(int i = 0; i < num.length(); i++) {
                while(k && !st.empty() && st.top() > num[i]) {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
                if(st.size() == 1 && num[i] == '0') // Preceding zero
                    st.pop();
            }
    
            while(k && !st.empty())
            {
                --k;
                st.pop();
            }
            
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
    
            reverse(ans.begin(), ans.end());
    
            if(ans.length() == 0) return "0";
            return ans;
        }
    };