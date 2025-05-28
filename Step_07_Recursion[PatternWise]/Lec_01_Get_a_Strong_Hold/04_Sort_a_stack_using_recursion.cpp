#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/sort-a-stack/1

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insertSorted(stack<int>& s, int x) {
    if (s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }
    
    int temp = s.top();
    s.pop();
    insertSorted(s, x);
    s.push(temp);
}

void SortedStack::sort() {
    if (s.empty()) return;

    int temp = s.top();
    s.pop();
    sort();  // Recursive sort on remaining stack
    insertSorted(s, temp);
}