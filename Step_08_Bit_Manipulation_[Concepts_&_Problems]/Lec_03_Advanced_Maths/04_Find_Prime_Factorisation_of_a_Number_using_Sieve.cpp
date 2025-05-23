#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {
        vector<int> prime(N+1,0);
        vector<int> v;
        for(int i=0;i<prime.size();i++) prime[i] = i;
        for(int i=2;i*i<prime.size();i++){
            if(prime[i] == i) for(int j=i*i;j<prime.size();j+=i) prime[j] = i;
        }
        
        while(N>1){
            v.push_back(prime[N]);
            N = N/prime[N];
        }
        sort(v.begin(),v.end());
        return v;
        
    }
};