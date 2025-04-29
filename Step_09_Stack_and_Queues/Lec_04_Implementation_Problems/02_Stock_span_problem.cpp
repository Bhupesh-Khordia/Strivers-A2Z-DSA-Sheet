// https://leetcode.com/problems/online-stock-span/

using namespace std;
#include <bits/stdc++.h>

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// O(1) amortized TC
class StockSpanner {
private:
    stack<pair<int, int>> st;
public:
    StockSpanner() {
    
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push(make_pair(price, span));
        return span;
    }
};



/*
// O(n) - TC
class StockSpanner {
private:
    vector<int> prices;
public:
    StockSpanner() {
    
    }
    
    int next(int price) {
        prices.push_back(price);
        int ans = 0;

        for(int i = prices.size() - 1; i >= 0; i--) {
            if(prices[i] <= price) ans++;
            else break;
        }

        return ans;
    }
};
*/
    
    