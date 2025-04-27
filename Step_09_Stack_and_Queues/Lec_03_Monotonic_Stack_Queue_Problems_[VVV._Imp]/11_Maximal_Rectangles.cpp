// https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
    private:
        vector<int> nextSmallerElement(vector<int> &arr, int n)
        {
            vector<int> ans (n , 0);
    
            stack<int> st;
            st.push(-1);
    
            for(int i = arr.size() - 1; i >= 0; i--) {
                while(st.top() != -1 && arr[st.top()] >= arr[i]) st.pop();
                ans[i] = st.top();
                st.push(i);
            }
    
            return ans;
        }
    
        vector<int> prevSmallerElement(vector<int> & arr, int n) 
        {
            vector<int> ans (n , 0);
    
            stack<int> st;
            st.push(-1);
    
            for(int i = 0; i < arr.size(); i++) {
                while(st.top() != -1 && arr[st.top()] >= arr[i]) st.pop();
                ans[i] = st.top();
                st.push(i);
            }
    
            return ans;
        }
    
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> nextSmaller = nextSmallerElement(heights, n);
            vector<int> prevSmaller = prevSmallerElement(heights, n);
    
            int area = INT_MIN;
    
            for(int i = 0; i < n; i++) {
                int length = heights[i];
                if(nextSmaller[i] == -1) nextSmaller[i] = n;
                int breadth = nextSmaller[i] - prevSmaller[i] - 1;
    
                area = max(area, length*breadth);
            }
    
            return area;
        }
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int ans = INT_MIN;
            int m = matrix[0].size(), n = matrix.size();
            vector<int> arr (m, 0);
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(matrix[i][j] == '0') {
                        arr[j] = 0;
                    }
                    else {
                        arr[j] ++ ;
                    }
                }
                
                int area = largestRectangleArea(arr);
                
                ans = max (area, ans);
            }
            return ans;
        }
    };