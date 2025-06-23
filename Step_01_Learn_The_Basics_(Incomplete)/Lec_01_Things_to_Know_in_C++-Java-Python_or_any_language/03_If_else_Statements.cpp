# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/java-if-else-decision-making0924/1

//User function Template for C++

class Solution {
  public:
    string compareNM(int n, int m){
        
        
        if (n <  m){
            return("lesser");
        }
        else if (n> m){
            return("greater");
        
        
        
        }
        else {
            return("equal");
        }
    }
};