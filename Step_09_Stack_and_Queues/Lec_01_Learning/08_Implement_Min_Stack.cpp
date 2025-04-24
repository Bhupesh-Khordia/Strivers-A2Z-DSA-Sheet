// https://leetcode.com/problems/min-stack/description/

class MinStack {
    public:
        stack<int> st;
        stack<int> minStack;
        int mini = INT_MAX;
    
        MinStack() {}
        
        void push(int val) {
            st.push(val);
            mini = min(mini, val);
            minStack.push(mini);
        }
        
        void pop() {
            if(st.empty()) return;
    
            minStack.pop();
            if(!minStack.empty()) mini = minStack.top();
            else mini = INT_MAX;
            st.pop();
        }
        
        int top() {
            if(st.empty()) return -1;
            return st.top();
        }
        
        int getMin() {
            if(minStack.empty()) return -1;
            return minStack.top();
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */