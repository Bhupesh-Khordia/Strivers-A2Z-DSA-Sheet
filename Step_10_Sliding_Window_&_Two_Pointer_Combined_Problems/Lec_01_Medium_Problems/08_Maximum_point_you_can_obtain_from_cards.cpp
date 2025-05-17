// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;
        int sum = 0;
        for(int i = 0; i < windowSize; i++) {
            sum += cardPoints[i];
        }

        int mini = sum;

        for(int i = windowSize; i < n; i++) {
            sum += cardPoints[i];
            sum -= cardPoints[i - windowSize];
            mini = min(mini, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - mini;
    }
};