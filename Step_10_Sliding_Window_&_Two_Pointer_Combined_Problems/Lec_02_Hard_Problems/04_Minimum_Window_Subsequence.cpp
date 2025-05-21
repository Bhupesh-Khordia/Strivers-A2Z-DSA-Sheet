// https://leetcode.com/problems/minimum-window-subsequence/description/

// No money to buy leetcode subscription.

// https://www.naukri.com/code360/problems/minimum-window-subsequence_2181133?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

string minWindow(string S, string T)
{
	// 3 Pointer solution

	int l = 0, r = 0; // To traverse S
	int k = 0; // To traverse T

	int n = S.length();
	int m = T.length();

	int minLen = INT_MAX;
	string ans = "";

	while(r < n) {
		if(S[r] == T[k]) k++;

		if(k == m) {
			l = r;
			k--;
			while(k >= 0) {
				if(S[l] == T[k]) k--;
				l--;
			}

			l++;

			if(minLen > r - l + 1) {
				minLen = r - l + 1;
				ans = S.substr(l, minLen);
			}

			k = 0, r = l;
		}

		r++;
	}

	return ans;
}