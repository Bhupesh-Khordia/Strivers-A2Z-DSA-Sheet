#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

class Solution {
  private:
    void insertAtBottom(stack<int> &st, int top) {
        if(st.empty()) {
            st.push(top);
            return;
        }
        
        int x = st.top(); st.pop();
        insertAtBottom(st, top);
        st.push(x);
    }
  public:
    void Reverse(stack<int> &St) {
        if(St.empty() || St.size() == 1) return ;
        
        int top = St.top();
        St.pop();
        Reverse(St);
        
        insertAtBottom(St, top);
    }
};