// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

class MyStack {
    private:
      StackNode *top;
  
    public:
      void push(int x) {
          StackNode *temp = new StackNode(x);
          temp -> next = top;
          top = temp;
      }
  
      int pop() {
          if(top == NULL) return -1;
          
          int ans = top -> data;
          top = top -> next;
          return ans;
      }
  
      MyStack() { top = NULL; }
  };