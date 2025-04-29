// https://leetcode.com/problems/find-the-celebrity/    (No money :( ))

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// https://www.naukri.com/code360/problems/the-celebrity-problem_982769


using namespace std;
#include <bits/stdc++.h>


// GFG


/*
// User function template for C++

class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        stack<int> st;
        int n = mat.size();
        for(int i = 0; i < n; i++) {
            st.push(i);
        }
        
        while(st.size() > 1) {
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
        
            if(mat[a][b] == 1) st.push(b);
            else st.push(a);
        }
        
        int celeb = st.top();
        
        for(int i = 0; i < n; i++) {
            if(mat[celeb][i] != 0) return -1;
        }
        
        for(int i = 0; i < n; i++) {
            if(celeb == i) continue;
            if(mat[i][celeb] != 1) return -1;
        }
        
        return celeb;
    }
};

*/


// Coding Ninjas



#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> st;
	for(int i = 0; i < n; i++) {
		st.push(i);
	}

	while(st.size() > 1) {
		int a = st.top();
		st.pop();
		
		int b = st.top();
		st.pop();

		if(knows(a,b) == 1) st.push(b);
		else st.push(a);
	}

	int celeb = st.top();

	for(int i = 0; i < n; i++) {
		if(knows(celeb, i) != 0) return -1;
	}

	for(int i = 0; i < n; i++) {
		if(celeb == i) continue;
		if(knows(i, celeb) != 1) return -1;
	}

	return celeb;
}