using namespace std;
#include <bits/stdc++.h>

// https://www.interviewbit.com/problems/maximum-sum-combinations/

// https://www.geeksforgeeks.org/problems/maximum-sum-combination/0

/*

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        int n = A.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;
        pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
        st.insert({n - 1, n - 1});
        vector<int> ans;
        while(K--){
            auto curr = pq.top();
            ans.push_back(curr.first);
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            if(i - 1 >= 0 && st.find({i - 1, j}) == st.end()){
                pq.push({A[i - 1] + B[j], {i - 1, j}});
                st.insert({i - 1, j});
            }
            if(j - 1 >= 0 && st.find({i, j - 1}) == st.end()){
                pq.push({A[i] + B[j - 1], {i, j - 1}});
                st.insert({i, j - 1});
            }
        }
        return ans;
    }
};

*/


// https://www.naukri.com/code360/problems/k-max-sum-combinations_975322?leftPanelTabValue=PROBLEM

// /*

#include <bits/stdc++.h>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	priority_queue<pair<int, pair<int, int>>> pq;
	set<pair<int, int>> st;
	pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
	st.insert({n - 1, n - 1});
	vector<int> ans;
	while(k--){
		auto curr = pq.top();
		ans.push_back(curr.first);
		pq.pop();
		int i = curr.second.first;
		int j = curr.second.second;
		if(i - 1 >= 0 && st.find({i - 1, j}) == st.end()){
			pq.push({a[i - 1] + b[j], {i - 1, j}});
			st.insert({i - 1, j});
		}
		if(j - 1 >= 0 && st.find({i, j - 1}) == st.end()){
			pq.push({a[i] + b[j - 1], {i, j - 1}});
			st.insert({i, j - 1});
		}
	}
	return ans;
}


// */