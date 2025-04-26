// https://leetcode.com/problems/asteroid-collision/description/

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> st;
            
            for (int ast : asteroids) {
                bool destroyed = false;
                while (!st.empty() && ast < 0 && st.top() > 0) {
                    if (st.top() < -ast) {
                        st.pop();  // smaller positive destroyed
                    } else if (st.top() == -ast) {
                        st.pop();  // both destroyed
                        destroyed = true;
                        break;
                    } else {
                        destroyed = true;
                        break;
                    }
                }
                if (!destroyed) {
                    st.push(ast);
                }
            }
            
            vector<int> ans(st.size());
            for (int i = st.size() - 1; i >= 0; i--) {
                ans[i] = st.top();
                st.pop();
            }
            
            return ans;
        }
    };
    